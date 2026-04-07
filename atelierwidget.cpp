#include "atelierwidget.h"
#include "ui_AtelierWidget.h"
#include "dialogmachine.h"
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>

AtelierWidget::AtelierWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AtelierWidget)
{
    ui->setupUi(this);

    QPixmap logo(":/images/logo.png");
    if (logo.isNull()) {
        qDebug() << "ERREUR : Logo introuvable !";
        ui->lblLogo->setText("LOGO");
        ui->lblLogo->setStyleSheet("background-color: red; color: white;");
    } else {
        ui->lblLogo->setPixmap(logo.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
    }

    initialiserTableau();
    connectSignals();
    chargerDonnees();
}

AtelierWidget::~AtelierWidget()
{
    delete ui;
}

void AtelierWidget::connectSignals()
{
    connect(ui->btnAjouter, &QPushButton::clicked, this, &AtelierWidget::onBtnAjouterClicked);
    connect(ui->btnModifier, &QPushButton::clicked, this, &AtelierWidget::onBtnModifierClicked);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &AtelierWidget::onBtnSupprimerClicked);
    connect(ui->btnExporter, &QPushButton::clicked, this, &AtelierWidget::onBtnExporterClicked);

    connect(ui->btnAppliquerTri, &QPushButton::clicked, this, &AtelierWidget::onBtnAppliquerTriClicked);
    connect(ui->btnReinitialiser, &QPushButton::clicked, this, &AtelierWidget::onBtnReinitialiserClicked);

    connect(ui->btnPlanifierMaintenance, &QPushButton::clicked, this, &AtelierWidget::onBtnPlanifierMaintenanceClicked);
    connect(ui->btnDetecterCritiques, &QPushButton::clicked, this, &AtelierWidget::onBtnDetecterCritiquesClicked);
    connect(ui->btnAnalyserRisques, &QPushButton::clicked, this, &AtelierWidget::onBtnAnalyserRisquesClicked);
}

void AtelierWidget::initialiserTableau()
{
    ui->tableMachines->setColumnWidth(0, 80);   // ID_MACHINE
    ui->tableMachines->setColumnWidth(1, 140);  // REFERENCE
    ui->tableMachines->setColumnWidth(2, 120);  // TYPE
    ui->tableMachines->setColumnWidth(3, 120);  // ETAT
    ui->tableMachines->setColumnWidth(4, 160);  // DATE_DERNIERE_MAINTENANCE
    ui->tableMachines->setColumnWidth(5, 120);  // HEURES_UTILISATION
    ui->tableMachines->setColumnWidth(6, 100);  // QUANTITE
    ui->tableMachines->setColumnWidth(7, 140);  // colonne libre
}

void AtelierWidget::chargerDonnees()
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ATELIER.MACHINE ORDER BY ID_MACHINE");

    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", "Impossible de charger les données: " + query.lastError().text());
        return;
    }

    ui->tableMachines->setRowCount(0);

    int row = 0;
    int totalMachines = 0;
    int disponibles = 0;
    int enMaintenance = 0;
    int horsService = 0;

    while (query.next()) {
        ui->tableMachines->insertRow(row);

        ui->tableMachines->setItem(row, 0, new QTableWidgetItem(query.value("ID_MACHINE").toString()));
        ui->tableMachines->setItem(row, 1, new QTableWidgetItem(query.value("REFERENCE").toString()));
        ui->tableMachines->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableMachines->setItem(row, 3, new QTableWidgetItem(query.value("ETAT").toString()));
        ui->tableMachines->setItem(row, 4, new QTableWidgetItem(query.value("DATE_DERNIERE_MAINTNANCE").toString()));
        ui->tableMachines->setItem(row, 5, new QTableWidgetItem(query.value("HEURES_UTILISATION").toString()));
        ui->tableMachines->setItem(row, 6, new QTableWidgetItem(query.value("QUANTITE").toString()));
        ui->tableMachines->setItem(row, 7, new QTableWidgetItem(""));

        totalMachines++;
        QString etat = query.value("ETAT").toString();
        if (etat == "Disponible") disponibles++;
        else if (etat == "En maintenance") enMaintenance++;
        else if (etat == "Hors service") horsService++;

        row++;
    }

    ui->lblTotalMachines->setText("Total Machines: " + QString::number(totalMachines));
    ui->lblMachinesDisponibles->setText("Disponibles: " + QString::number(disponibles));
    ui->lblMachinesMaintenance->setText("En Maintenance: " + QString::number(enMaintenance));
    ui->lblMachinesHS->setText("Hors Service: " + QString::number(horsService));

    chargerMachinesCritiques();
    chargerMachinesSollicitees();
}

void AtelierWidget::onBtnAjouterClicked()
{
    DialogMachine dialog(this);
    dialog.setWindowTitle("Ajouter une Machine");

    if (dialog.exec() == QDialog::Accepted) {
        bool refOk;
        int ref = dialog.getReference().toInt(&refOk);
        if (!refOk || ref <= 0) {
            QMessageBox::warning(this, "Erreur", "La référence doit être un nombre entier positif.");
            return;
        }

        QSqlQuery query;
        query.prepare(
            "INSERT INTO ATELIER.MACHINE "
            "(REFERENCE, TYPE, ETAT, DATE_DERNIERE_MAINTNANCE, HEURES_UTILISATION, QUANTITE, ID_EMPLOYE) "
            "VALUES (:ref, :type, :etat, :date, :heures, :qte, :idEmp)"
        );
        query.bindValue(":ref", ref);
        query.bindValue(":type", dialog.getType());
        query.bindValue(":etat", dialog.getEtat());
        query.bindValue(":date", QDate::fromString(dialog.getDateMaintenance(), "dd/MM/yyyy"));
        query.bindValue(":heures", dialog.getHeuresCumulees());
        query.bindValue(":qte", dialog.getQuantite());
        query.bindValue(":idEmp", dialog.getIdEmploye());

        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur SQL", query.lastError().text());
            return;
        }

        QMessageBox::information(this, "Succès", "Machine ajoutée avec succès !");
        chargerDonnees();
    }
}

void AtelierWidget::onBtnModifierClicked()
{
    int currentRow = ui->tableMachines->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une machine à modifier.");
        return;
    }

    const QString idMachine = ui->tableMachines->item(currentRow, 0)->text();

    DialogMachine dialog(this);
    dialog.setWindowTitle("Modifier la Machine");
    dialog.setID(idMachine);
    dialog.setReference(ui->tableMachines->item(currentRow, 1)->text());
    dialog.setType(ui->tableMachines->item(currentRow, 2)->text());
    dialog.setEtat(ui->tableMachines->item(currentRow, 3)->text());
    dialog.setDateMaintenance(ui->tableMachines->item(currentRow, 4)->text());
    dialog.setHeuresCumulees(ui->tableMachines->item(currentRow, 5)->text().toInt());
    dialog.setQuantite(ui->tableMachines->item(currentRow, 6)->text().toInt());

    if (dialog.exec() == QDialog::Accepted) {
        bool refOk;
        int ref = dialog.getReference().toInt(&refOk);
        if (!refOk || ref <= 0) {
            QMessageBox::warning(this, "Erreur", "La référence doit être un nombre entier positif.");
            return;
        }

        QSqlQuery query;
        query.prepare(
            "UPDATE ATELIER.MACHINE SET "
            "REFERENCE=:ref, TYPE=:type, ETAT=:etat, "
            "DATE_DERNIERE_MAINTNANCE=:date, HEURES_UTILISATION=:heures, "
            "QUANTITE=:qte, ID_EMPLOYE=:idEmp "
            "WHERE ID_MACHINE=:id"
        );
        query.bindValue(":id", idMachine.toInt());
        query.bindValue(":ref", ref);
        query.bindValue(":type", dialog.getType());
        query.bindValue(":etat", dialog.getEtat());
        query.bindValue(":date", QDate::fromString(dialog.getDateMaintenance(), "dd/MM/yyyy"));
        query.bindValue(":heures", dialog.getHeuresCumulees());
        query.bindValue(":qte", dialog.getQuantite());
        query.bindValue(":idEmp", dialog.getIdEmploye());

        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur SQL", query.lastError().text());
            return;
        }

        QMessageBox::information(this, "Succès", "Machine modifiée avec succès !");
        chargerDonnees();
    }
}

void AtelierWidget::onBtnSupprimerClicked()
{
    int currentRow = ui->tableMachines->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une machine à supprimer.");
        return;
    }

    const QString idMachine = ui->tableMachines->item(currentRow, 0)->text();

    if (QMessageBox::question(this, "Confirmation",
                              "Êtes-vous sûr de vouloir supprimer cette machine ?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        QSqlQuery query;
        query.prepare("DELETE FROM ATELIER.MACHINE WHERE ID_MACHINE = :id");
        query.bindValue(":id", idMachine.toInt());

        if (!query.exec()) {
            QMessageBox::warning(this, "Erreur SQL", query.lastError().text());
            return;
        }

        QMessageBox::information(this, "Succès", "Machine supprimée avec succès !");
        chargerDonnees();
    }
}

void AtelierWidget::onBtnExporterClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter les données", "", "CSV Files (*.csv)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream out(&file);
    out << "ID_MACHINE,REFERENCE,TYPE,ETAT,DATE_DERNIERE_MAINTENANCE,HEURES_UTILISATION,QUANTITE\n";

    for (int row = 0; row < ui->tableMachines->rowCount(); ++row) {
        for (int col = 0; col < 7; ++col) {
            out << ui->tableMachines->item(row, col)->text();
            if (col < 6) out << ",";
        }
        out << "\n";
    }

    file.close();
    QMessageBox::information(this, "Succès", "Données exportées avec succès !");
}

void AtelierWidget::onBtnAppliquerTriClicked()
{
    QString triPar = ui->comboTriPar->currentText();
    if (triPar == "-- Aucun tri --") {
        chargerDonnees();
        return;
    }

    if (triPar == "Date de maintenance") {
        ui->tableMachines->sortItems(4, Qt::AscendingOrder);
    } else if (triPar == "Heures d'utilisation") {
        ui->tableMachines->sortItems(5, Qt::DescendingOrder);
    }

    QMessageBox::information(this, "Tri appliqué", "Tri par : " + triPar);
}

void AtelierWidget::onBtnReinitialiserClicked()
{
    ui->comboRechercheType->setCurrentIndex(0);
    ui->comboRechercheEtat->setCurrentIndex(0);
    ui->comboTriPar->setCurrentIndex(0);
    chargerDonnees();
}

// Calcule le niveau de risque d'une machine selon ses données
static QString calculerNiveauRisque(const QString &etat, double heures, const QDate &dateMaintenance)
{
    if (etat == "Hors service") return "ÉLEVÉ";
    if (heures > 500) return "ÉLEVÉ";
    int joursDepuisMaintenance = dateMaintenance.isValid()
        ? dateMaintenance.daysTo(QDate::currentDate()) : 9999;
    if (heures > 300 || joursDepuisMaintenance > 90) return "MOYEN";
    return "FAIBLE";
}

void AtelierWidget::onBtnPlanifierMaintenanceClicked()
{
    QSqlQuery query;
    query.prepare(
        "SELECT TYPE, ETAT, HEURES_UTILISATION, DATE_DERNIERE_MAINTNANCE "
        "FROM ATELIER.MACHINE "
        "WHERE ETAT != 'Hors service' "
        "ORDER BY HEURES_UTILISATION DESC"
    );
    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", query.lastError().text());
        return;
    }

    QString plan = "Plan de maintenance automatique :\n\n";
    bool found = false;
    while (query.next()) {
        double heures = query.value("HEURES_UTILISATION").toDouble();
        QString type = query.value("TYPE").toString();
        QString etat = query.value("ETAT").toString();
        QDate date = query.value("DATE_DERNIERE_MAINTNANCE").toDate();
        QString risque = calculerNiveauRisque(etat, heures, date);

        if (risque == "ÉLEVÉ") {
            plan += "🔴 " + type + " (" + QString::number(heures) + "h) : Maintenance urgente\n";
            found = true;
        } else if (risque == "MOYEN") {
            plan += "🟠 " + type + " (" + QString::number(heures) + "h) : Planifier maintenance\n";
            found = true;
        }
    }
    if (!found) plan += "✅ Aucune machine ne nécessite de maintenance urgente.";
    QMessageBox::information(this, "Planification Automatique", plan);
}

void AtelierWidget::onBtnDetecterCritiquesClicked()
{
    chargerMachinesCritiques();
    QSqlQuery query;
    query.prepare(
        "SELECT COUNT(*) FROM ATELIER.MACHINE "
        "WHERE ETAT = 'Hors service' OR HEURES_UTILISATION > 500"
    );
    query.exec();
    int count = 0;
    if (query.next()) count = query.value(0).toInt();
    QMessageBox::warning(this, "Machines Critiques",
        QString("⚠️ %1 machine(s) critique(s) détectée(s).\nTableau mis à jour.").arg(count));
}

void AtelierWidget::onBtnAnalyserRisquesClicked()
{
    QSqlQuery query;
    query.prepare("SELECT ETAT, HEURES_UTILISATION, DATE_DERNIERE_MAINTNANCE FROM ATELIER.MACHINE");
    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur", query.lastError().text());
        return;
    }

    int eleve = 0, moyen = 0, faible = 0;
    while (query.next()) {
        QString risque = calculerNiveauRisque(
            query.value("ETAT").toString(),
            query.value("HEURES_UTILISATION").toDouble(),
            query.value("DATE_DERNIERE_MAINTNANCE").toDate()
        );
        if (risque == "ÉLEVÉ") eleve++;
        else if (risque == "MOYEN") moyen++;
        else faible++;
    }

    QMessageBox::information(this, "Analyse des Risques",
        QString("🔴 RISQUE ÉLEVÉ  : %1 machine(s)\n"
                "🟠 RISQUE MOYEN  : %2 machine(s)\n"
                "🟢 RISQUE FAIBLE : %3 machine(s)").arg(eleve).arg(moyen).arg(faible));
}

void AtelierWidget::chargerMachinesCritiques()
{
    ui->tableMachinesCritiques->setRowCount(0);

    QSqlQuery query;
    query.prepare(
        "SELECT TYPE, ETAT, HEURES_UTILISATION, DATE_DERNIERE_MAINTNANCE "
        "FROM ATELIER.MACHINE "
        "WHERE ETAT = 'Hors service' OR HEURES_UTILISATION > 300 "
        "ORDER BY HEURES_UTILISATION DESC"
    );
    if (!query.exec()) return;

    int row = 0;
    while (query.next()) {
        QString etat   = query.value("ETAT").toString();
        double heures  = query.value("HEURES_UTILISATION").toDouble();
        QString type   = query.value("TYPE").toString();
        QDate date     = query.value("DATE_DERNIERE_MAINTNANCE").toDate();
        QString risque = calculerNiveauRisque(etat, heures, date);

        QString priorite, typeAlerte, action, risqueLabel;
        if (risque == "ÉLEVÉ") {
            priorite   = "🔴 URGENT";
            typeAlerte = etat == "Hors service" ? "Hors service" : "Heures excessives";
            risqueLabel = "🔴 ÉLEVÉ";
            action     = etat == "Hors service" ? "Réparation urgente" : "Maintenance immédiate";
        } else {
            priorite   = "🟠 ATTENTION";
            typeAlerte = "Surveillance requise";
            risqueLabel = "🟠 MOYEN";
            action     = "Planifier maintenance";
        }

        ui->tableMachinesCritiques->insertRow(row);
        ui->tableMachinesCritiques->setItem(row, 0, new QTableWidgetItem(priorite));
        ui->tableMachinesCritiques->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableMachinesCritiques->setItem(row, 2, new QTableWidgetItem(typeAlerte));
        ui->tableMachinesCritiques->setItem(row, 3, new QTableWidgetItem(risqueLabel));
        ui->tableMachinesCritiques->setItem(row, 4, new QTableWidgetItem(action));
        row++;
    }
}

void AtelierWidget::chargerMachinesSollicitees()
{
    ui->tableMachinesSollicitees->setRowCount(0);

    QSqlQuery query;
    query.prepare(
        "SELECT TYPE, ETAT, HEURES_UTILISATION, DATE_DERNIERE_MAINTNANCE "
        "FROM ATELIER.MACHINE "
        "ORDER BY HEURES_UTILISATION DESC"
    );
    if (!query.exec()) return;

    int rang = 1;
    while (query.next() && rang <= 5) {
        QString type  = query.value("TYPE").toString();
        double heures = query.value("HEURES_UTILISATION").toDouble();
        QString etat  = query.value("ETAT").toString();
        QDate date    = query.value("DATE_DERNIERE_MAINTNANCE").toDate();

        // Prochaine maintenance estimée selon le type
        int seuilMaintenance = 500;
        if (type == "Perceuse") seuilMaintenance = 300;
        else if (type == "Raboteuse") seuilMaintenance = 400;
        double heuresRestantes = seuilMaintenance - heures;
        QString prochaine = heuresRestantes <= 0
            ? "Immédiate"
            : QString("Dans %1h").arg((int)heuresRestantes);

        int row = ui->tableMachinesSollicitees->rowCount();
        ui->tableMachinesSollicitees->insertRow(row);
        ui->tableMachinesSollicitees->setItem(row, 0, new QTableWidgetItem(QString::number(rang)));
        ui->tableMachinesSollicitees->setItem(row, 1, new QTableWidgetItem(type));
        ui->tableMachinesSollicitees->setItem(row, 2, new QTableWidgetItem(QString::number(heures) + "h"));
        ui->tableMachinesSollicitees->setItem(row, 3, new QTableWidgetItem(etat));
        ui->tableMachinesSollicitees->setItem(row, 4, new QTableWidgetItem(prochaine));
        rang++;
    }
}
