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
#include <QCalendarWidget>
#include <QHeaderView>
#include <QTextCharFormat>
#include <QFont>
#include <QInputDialog>

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
    connect(ui->btnExportCSVMachines, &QPushButton::clicked, this, &AtelierWidget::onBtnExportCSVMachinesClicked);
    connect(ui->calendarAtelier, &QCalendarWidget::selectionChanged, this, &AtelierWidget::onCalendrierDateChanged);
    connect(ui->calendarAtelier, &QCalendarWidget::currentPageChanged, this, &AtelierWidget::onCalendrierPageChanged);

    // Planification tab
    connect(ui->btnPlanAjouter,       &QPushButton::clicked, this, &AtelierWidget::onPlanAjouter);
    connect(ui->btnPlanSupprimer,     &QPushButton::clicked, this, &AtelierWidget::onPlanSupprimer);
    connect(ui->btnPlanModifierStatut,&QPushButton::clicked, this, &AtelierWidget::onPlanModifierStatut);
    connect(ui->comboPlanFiltreStatut,  QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AtelierWidget::onPlanFiltreChanged);
    connect(ui->comboPlanFiltreEmploye, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &AtelierWidget::onPlanFiltreChanged);

    planRemplirCombos();
    planChargerTaches();
}

void AtelierWidget::initialiserTableau()
{
    // Tableau principal : colonnes fixes adaptées
    ui->tableMachines->setColumnWidth(0, 80);
    ui->tableMachines->setColumnWidth(1, 140);
    ui->tableMachines->setColumnWidth(2, 120);
    ui->tableMachines->setColumnWidth(3, 120);
    ui->tableMachines->setColumnWidth(4, 160);
    ui->tableMachines->setColumnWidth(5, 120);
    ui->tableMachines->setColumnWidth(6, 100);
    ui->tableMachines->horizontalHeader()->setStretchLastSection(true);
    // Tableaux statistiques : colonnes qui s'étirent pour remplir l'espace
    ui->tableMachinesCritiques->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableMachinesCritiques->verticalHeader()->setVisible(false);
    ui->tableMachinesCritiques->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableMachinesSollicitees->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableMachinesSollicitees->verticalHeader()->setVisible(false);
    ui->tableMachinesSollicitees->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Tableaux calendrier
    ui->tableCalMachines->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableCalMachines->verticalHeader()->setVisible(false);
    ui->tableCalMachines->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableCalCommandes->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableCalCommandes->verticalHeader()->setVisible(false);
    ui->tableCalCommandes->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // Highlight initial du calendrier
    highlighterDatesCommandes();
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
        QString ref = dialog.getReference().trimmed();
        if (ref.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "La référence ne peut pas être vide.");
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
        QString ref = dialog.getReference().trimmed();
        if (ref.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "La référence ne peut pas être vide.");
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

void AtelierWidget::onCalendrierDateChanged()
{
    const QDate date = ui->calendarAtelier->selectedDate();
    ui->lblDateSelectionnee->setText("📅 " + date.toString("dddd dd MMMM yyyy"));

    // --- Machines dont la maintenance était ce jour ---
    ui->tableCalMachines->setRowCount(0);
    QSqlQuery qMac;
    qMac.prepare(
        "SELECT m.TYPE, m.ETAT, m.HEURES_UTILISATION, NVL(e.NOM, '—') AS NOM_EMP "
        "FROM ATELIER.MACHINE m "
        "LEFT JOIN ATELIER.EMPLOYE e ON m.ID_EMPLOYE = e.ID_EMPLOYE "
        "WHERE TRUNC(m.DATE_DERNIERE_MAINTNANCE) = TO_DATE(:d, 'YYYY-MM-DD')"
    );
    qMac.bindValue(":d", date.toString("yyyy-MM-dd"));
    if (qMac.exec()) {
        int row = 0;
        while (qMac.next()) {
            ui->tableCalMachines->insertRow(row);
            ui->tableCalMachines->setItem(row, 0, new QTableWidgetItem(qMac.value("TYPE").toString()));
            ui->tableCalMachines->setItem(row, 1, new QTableWidgetItem(qMac.value("ETAT").toString()));
            ui->tableCalMachines->setItem(row, 2, new QTableWidgetItem(qMac.value("HEURES_UTILISATION").toString() + "h"));
            ui->tableCalMachines->setItem(row, 3, new QTableWidgetItem(qMac.value("NOM_EMP").toString()));
            row++;
        }
    }

    // --- Commandes passées ce jour (DATE_COMMANDE) ---
    ui->tableCalCommandes->setRowCount(0);
    QSqlQuery qCmd;
    qCmd.prepare(
        "SELECT c.ID_COMMANDE, c.DETAILS_COMMANDE, c.DIMENSIONS, c.PRIX, c.ETAT "
        "FROM ATELIER.COMMANDE c "
        "WHERE TRUNC(c.DATE_COMMANDE) = TO_DATE(:d, 'YYYY-MM-DD') "
        "ORDER BY c.ID_COMMANDE"
    );
    qCmd.bindValue(":d", date.toString("yyyy-MM-dd"));
    if (qCmd.exec()) {
        int row = 0;
        while (qCmd.next()) {
            ui->tableCalCommandes->insertRow(row);
            ui->tableCalCommandes->setItem(row, 0, new QTableWidgetItem(qCmd.value("ID_COMMANDE").toString()));
            ui->tableCalCommandes->setItem(row, 1, new QTableWidgetItem(qCmd.value("DETAILS_COMMANDE").toString()));
            ui->tableCalCommandes->setItem(row, 2, new QTableWidgetItem(qCmd.value("PRIX").toString() + " €"));
            ui->tableCalCommandes->setItem(row, 3, new QTableWidgetItem(qCmd.value("ETAT").toString()));
            ui->tableCalCommandes->setItem(row, 4, new QTableWidgetItem(qCmd.value("DIMENSIONS").toString()));
            row++;
        }
    }

    // Mettre à jour le titre du groupe avec le nombre de commandes
    int nbCmd = ui->tableCalCommandes->rowCount();
    ui->groupCalCommandes->setTitle(
        nbCmd > 0
        ? QString(" 📦 Commandes ce jour (%1)").arg(nbCmd)
        : " 📦 Commandes ce jour (aucune)"
    );
}

void AtelierWidget::onCalendrierPageChanged(int year, int month)
{
    Q_UNUSED(year)
    Q_UNUSED(month)
    highlighterDatesCommandes();
}

void AtelierWidget::highlighterDatesCommandes()
{
    // Récupère toutes les dates avec au moins une commande ce mois
    QTextCharFormat formatCommande;
    formatCommande.setBackground(QColor("#D4E8C2"));       // vert clair
    formatCommande.setForeground(QColor("#2E5E00"));
    formatCommande.setFontWeight(QFont::Bold);

    // Reset d'abord le format du mois affiché
    const QDate premier(ui->calendarAtelier->yearShown(),
                        ui->calendarAtelier->monthShown(), 1);
    const QDate dernier = premier.addMonths(1).addDays(-1);

    QTextCharFormat formatNormal;
    for (QDate d = premier; d <= dernier; d = d.addDays(1))
        ui->calendarAtelier->setDateTextFormat(d, formatNormal);

    // Requête : dates distinctes avec commandes
    QSqlQuery query;
    query.prepare(
        "SELECT DISTINCT TRUNC(DATE_COMMANDE) AS JOUR "
        "FROM ATELIER.COMMANDE "
        "WHERE DATE_COMMANDE >= TO_DATE(:debut, 'YYYY-MM-DD') "
        "  AND DATE_COMMANDE <  TO_DATE(:fin,   'YYYY-MM-DD')"
    );
    query.bindValue(":debut", premier.toString("yyyy-MM-dd"));
    query.bindValue(":fin",   dernier.addDays(1).toString("yyyy-MM-dd"));

    if (query.exec()) {
        while (query.next()) {
            QDate jour = query.value("JOUR").toDate();
            if (jour.isValid())
                ui->calendarAtelier->setDateTextFormat(jour, formatCommande);
        }
    }
}

// ─── Planification ───────────────────────────────────────────────────────────

void AtelierWidget::planRemplirCombos()
{
    // Employés
    auto remplirEmp = [&](QComboBox *cb, bool avecTous) {
        cb->clear();
        if (avecTous) cb->addItem("-- Tous --", QVariant());
        QSqlQuery q("SELECT ID_EMPLOYE, NOM FROM ATELIER.EMPLOYE ORDER BY NOM");
        while (q.next())
            cb->addItem(q.value("NOM").toString(), q.value("ID_EMPLOYE"));
    };
    remplirEmp(ui->comboPlanEmploye,       false);
    remplirEmp(ui->comboPlanFiltreEmploye, true);

    // Commandes
    ui->comboPlanCommande->clear();
    QSqlQuery qCmd("SELECT ID_COMMANDE, DETAILS_COMMANDE FROM ATELIER.COMMANDE ORDER BY ID_COMMANDE DESC");
    while (qCmd.next())
        ui->comboPlanCommande->addItem(
            "#" + qCmd.value("ID_COMMANDE").toString() + " — " + qCmd.value("DETAILS_COMMANDE").toString(),
            qCmd.value("ID_COMMANDE"));

    // Machines
    ui->comboPlanMachine->clear();
    ui->comboPlanMachine->addItem("-- Aucune --", QVariant());
    QSqlQuery qMac("SELECT ID_MACHINE, REFERENCE, TYPE FROM ATELIER.MACHINE ORDER BY TYPE");
    while (qMac.next())
        ui->comboPlanMachine->addItem(
            qMac.value("REFERENCE").toString() + " (" + qMac.value("TYPE").toString() + ")",
            qMac.value("ID_MACHINE"));
}

void AtelierWidget::planChargerTaches()
{
    QString sql =
        "SELECT p.ID_TACHE, p.PRIORITE, e.NOM, c.DETAILS_COMMANDE, "
        "       NVL(TO_CHAR(m.ID_MACHINE),'—'), p.DATE_DEBUT, p.DATE_FIN, p.STATUT, NVL(p.NOTES,'') "
        "FROM ATELIER.PLANIFICATION p "
        "JOIN ATELIER.COMMANDE c ON p.ID_COMMANDE = c.ID_COMMANDE "
        "JOIN ATELIER.EMPLOYE  e ON p.ID_EMPLOYE  = e.ID_EMPLOYE "
        "LEFT JOIN ATELIER.MACHINE m ON p.ID_MACHINE = m.ID_MACHINE "
        "WHERE 1=1 ";

    QString filtreStatut = ui->comboPlanFiltreStatut->currentText();
    if (filtreStatut != "-- Tous --")
        sql += "AND p.STATUT = '" + filtreStatut + "' ";

    QVariant filtreEmp = ui->comboPlanFiltreEmploye->currentData();
    if (filtreEmp.isValid())
        sql += "AND p.ID_EMPLOYE = " + filtreEmp.toString() + " ";

    sql += "ORDER BY p.DATE_DEBUT, p.PRIORITE";

    QSqlQuery q;
    q.prepare(sql);
    q.exec();

    ui->tablePlanTaches->setRowCount(0);
    int row = 0;
    while (q.next()) {
        ui->tablePlanTaches->insertRow(row);
        ui->tablePlanTaches->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));

        int prio = q.value(1).toInt();
        QString prioStr = prio == 1 ? "🔴 Haute" : (prio == 3 ? "🟢 Basse" : "🟡 Normale");
        ui->tablePlanTaches->setItem(row, 1, new QTableWidgetItem(prioStr));
        ui->tablePlanTaches->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
        ui->tablePlanTaches->setItem(row, 3, new QTableWidgetItem(q.value(3).toString()));
        ui->tablePlanTaches->setItem(row, 4, new QTableWidgetItem(q.value(4).toString()));
        ui->tablePlanTaches->setItem(row, 5, new QTableWidgetItem(q.value(5).toDate().toString("dd/MM/yyyy")));
        ui->tablePlanTaches->setItem(row, 6, new QTableWidgetItem(q.value(6).toDate().toString("dd/MM/yyyy")));

        QString statut = q.value(7).toString();
        auto *itemStatut = new QTableWidgetItem(statut);
        if (statut == "En cours")   itemStatut->setBackground(QColor("#C8E6C9"));
        else if (statut == "En attente") itemStatut->setBackground(QColor("#FFF9C4"));
        else if (statut == "En retard")  itemStatut->setBackground(QColor("#FFCDD2"));
        else if (statut == "Terminee")   itemStatut->setBackground(QColor("#E0E0E0"));
        ui->tablePlanTaches->setItem(row, 7, itemStatut);
        ui->tablePlanTaches->setItem(row, 8, new QTableWidgetItem(q.value(8).toString()));
        row++;
    }
}

void AtelierWidget::onPlanAjouter()
{
    if (ui->comboPlanEmploye->currentIndex() < 0 || ui->comboPlanCommande->currentIndex() < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé et une commande.");
        return;
    }
    if (ui->planDateFin->date() < ui->planDateDebut->date()) {
        QMessageBox::warning(this, "Erreur", "La date de fin doit être après la date de début.");
        return;
    }

    QSqlQuery q;
    q.prepare(
        "INSERT INTO ATELIER.PLANIFICATION "
        "(ID_COMMANDE, ID_EMPLOYE, ID_MACHINE, DATE_DEBUT, DATE_FIN, STATUT, PRIORITE, NOTES) "
        "VALUES (:cmd, :emp, :mac, :debut, :fin, 'En attente', :prio, :notes)"
    );
    q.bindValue(":cmd",   ui->comboPlanCommande->currentData().toInt());
    q.bindValue(":emp",   ui->comboPlanEmploye->currentData().toInt());
    QVariant mac = ui->comboPlanMachine->currentData();
    q.bindValue(":mac",   mac.isValid() ? mac : QVariant(QVariant::Int));
    q.bindValue(":debut", ui->planDateDebut->date());
    q.bindValue(":fin",   ui->planDateFin->date());
    q.bindValue(":prio",  ui->comboPlanPriorite->currentIndex() + 1);
    q.bindValue(":notes", ui->planNotes->toPlainText().trimmed());

    if (!q.exec()) {
        QMessageBox::warning(this, "Erreur SQL", q.lastError().text());
        return;
    }
    QMessageBox::information(this, "Succès", "Tâche assignée !");
    ui->planNotes->clear();
    ui->planDateDebut->setDate(QDate::currentDate());
    ui->planDateFin->setDate(QDate::currentDate().addDays(1));
    planChargerTaches();
}

void AtelierWidget::onPlanSupprimer()
{
    int row = ui->tablePlanTaches->currentRow();
    if (row < 0) { QMessageBox::warning(this, "Attention", "Sélectionnez une tâche."); return; }
    int id = ui->tablePlanTaches->item(row, 0)->text().toInt();
    if (QMessageBox::question(this, "Confirmation", "Supprimer cette tâche ?",
        QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) return;
    QSqlQuery q;
    q.prepare("DELETE FROM ATELIER.PLANIFICATION WHERE ID_TACHE = :id");
    q.bindValue(":id", id);
    if (!q.exec()) { QMessageBox::warning(this, "Erreur SQL", q.lastError().text()); return; }
    planChargerTaches();
}

void AtelierWidget::onPlanModifierStatut()
{
    int row = ui->tablePlanTaches->currentRow();
    if (row < 0) { QMessageBox::warning(this, "Attention", "Sélectionnez une tâche."); return; }
    int id = ui->tablePlanTaches->item(row, 0)->text().toInt();
    QStringList statuts = {"En attente", "En cours", "Terminee", "En retard"};
    bool ok;
    QString choix = QInputDialog::getItem(this, "Changer le statut", "Nouveau statut :", statuts, 0, false, &ok);
    if (!ok) return;
    QSqlQuery q;
    q.prepare("UPDATE ATELIER.PLANIFICATION SET STATUT=:s WHERE ID_TACHE=:id");
    q.bindValue(":s", choix);
    q.bindValue(":id", id);
    if (!q.exec()) { QMessageBox::warning(this, "Erreur SQL", q.lastError().text()); return; }
    planChargerTaches();
}

void AtelierWidget::onPlanFiltreChanged() { planChargerTaches(); }

void AtelierWidget::onBtnExportCSVMachinesClicked()
{
    QString fileName = QFileDialog::getSaveFileName(
        this, "Exporter les machines en CSV", "", "CSV Files (*.csv)");
    if (fileName.isEmpty()) return;

    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier.");
        return;
    }

    QTextStream out(&file);
    // En-tête
    out << "ID_MACHINE,REFERENCE,TYPE,ETAT,DATE_MAINTENANCE,HEURES_UTILISATION,QUANTITE,NIVEAU_RISQUE,ACTION_REQUISE\n";

    QSqlQuery query;
    query.prepare("SELECT ID_MACHINE, REFERENCE, TYPE, ETAT, DATE_DERNIERE_MAINTNANCE, HEURES_UTILISATION, QUANTITE FROM ATELIER.MACHINE ORDER BY ID_MACHINE");
    if (!query.exec()) {
        QMessageBox::warning(this, "Erreur SQL", query.lastError().text());
        return;
    }

    int total = 0, critiques = 0;
    while (query.next()) {
        QString etat   = query.value("ETAT").toString();
        double heures  = query.value("HEURES_UTILISATION").toDouble();
        QDate date     = query.value("DATE_DERNIERE_MAINTNANCE").toDate();
        QString risque = calculerNiveauRisque(etat, heures, date);

        QString action;
        if (risque == "ÉLEVÉ")  { action = "Maintenance immédiate"; critiques++; }
        else if (risque == "MOYEN") action = "Planifier maintenance";
        else action = "RAS";

        out << query.value("ID_MACHINE").toString() << ","
            << query.value("REFERENCE").toString() << ","
            << query.value("TYPE").toString() << ","
            << etat << ","
            << date.toString("yyyy-MM-dd") << ","
            << QString::number(heures) << ","
            << query.value("QUANTITE").toString() << ","
            << risque << ","
            << action << "\n";
        total++;
    }

    file.close();

    QMessageBox::information(this, "Export réussi",
        QString("✅ %1 machines exportées.\n⚠️ %2 machine(s) critique(s) détectée(s).\n\nFichier : %3")
        .arg(total).arg(critiques).arg(fileName));
}
