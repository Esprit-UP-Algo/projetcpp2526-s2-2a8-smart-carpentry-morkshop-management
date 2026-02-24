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
        ui->tableMachines->setItem(row, 4, new QTableWidgetItem(query.value("DATE_DERNIERE_MAINTENANCE").toString()));
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
        int row = ui->tableMachines->rowCount();
        ui->tableMachines->insertRow(row);

        ui->tableMachines->setItem(row, 0, new QTableWidgetItem(dialog.getID()));
        ui->tableMachines->setItem(row, 1, new QTableWidgetItem(dialog.getReference()));
        ui->tableMachines->setItem(row, 2, new QTableWidgetItem(dialog.getType()));
        ui->tableMachines->setItem(row, 3, new QTableWidgetItem(dialog.getEtat()));
        ui->tableMachines->setItem(row, 4, new QTableWidgetItem(dialog.getDateMaintenance()));
        ui->tableMachines->setItem(row, 5, new QTableWidgetItem(QString::number(dialog.getHeuresCumulees())));
        ui->tableMachines->setItem(row, 6, new QTableWidgetItem(QString::number(dialog.getQuantite())));
        ui->tableMachines->setItem(row, 7, new QTableWidgetItem(""));

        QMessageBox::information(this, "Succès", "Machine ajoutée avec succès !");
        chargerMachinesCritiques();
        chargerMachinesSollicitees();
    }
}

void AtelierWidget::onBtnModifierClicked()
{
    int currentRow = ui->tableMachines->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une machine à modifier.");
        return;
    }

    DialogMachine dialog(this);
    dialog.setWindowTitle("Modifier la Machine");

    dialog.setID(ui->tableMachines->item(currentRow, 0)->text());
    dialog.setReference(ui->tableMachines->item(currentRow, 1)->text());
    dialog.setType(ui->tableMachines->item(currentRow, 2)->text());
    dialog.setEtat(ui->tableMachines->item(currentRow, 3)->text());
    dialog.setDateMaintenance(ui->tableMachines->item(currentRow, 4)->text());
    dialog.setHeuresCumulees(ui->tableMachines->item(currentRow, 5)->text().toInt());
    dialog.setQuantite(ui->tableMachines->item(currentRow, 6)->text().toInt());

    if (dialog.exec() == QDialog::Accepted) {
        ui->tableMachines->item(currentRow, 0)->setText(dialog.getID());
        ui->tableMachines->item(currentRow, 1)->setText(dialog.getReference());
        ui->tableMachines->item(currentRow, 2)->setText(dialog.getType());
        ui->tableMachines->item(currentRow, 3)->setText(dialog.getEtat());
        ui->tableMachines->item(currentRow, 4)->setText(dialog.getDateMaintenance());
        ui->tableMachines->item(currentRow, 5)->setText(QString::number(dialog.getHeuresCumulees()));
        ui->tableMachines->item(currentRow, 6)->setText(QString::number(dialog.getQuantite()));
        ui->tableMachines->item(currentRow, 7)->setText("");

        QMessageBox::information(this, "Succès", "Machine modifiée avec succès !");
    }
}

void AtelierWidget::onBtnSupprimerClicked()
{
    int currentRow = ui->tableMachines->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une machine à supprimer.");
        return;
    }

    if (QMessageBox::question(this, "Confirmation",
                              "Êtes-vous sûr de vouloir supprimer cette machine ?",
                              QMessageBox::Yes | QMessageBox::No) == QMessageBox::Yes) {
        ui->tableMachines->removeRow(currentRow);
        QMessageBox::information(this, "Succès", "Machine supprimée avec succès !");
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

void AtelierWidget::onBtnPlanifierMaintenanceClicked()
{
    QMessageBox::information(this, "Planification Automatique",
                             "• Scie Circulaire A : Maintenance urgente\n"
                             "• Ponceuse D : Maintenance dans 50h\n"
                             "• Tour à bois E : Réparation immédiate");
}

void AtelierWidget::onBtnDetecterCritiquesClicked()
{
    QMessageBox::warning(this, "Machines Critiques",
                         "⚠️ 3 machines critiques détectées.");
}

void AtelierWidget::onBtnAnalyserRisquesClicked()
{
    QMessageBox::information(this, "Analyse des Risques",
                             "🔴 RISQUE ÉLEVÉ : 3 machines\n🟠 RISQUE MOYEN : 1 machine\n🟢 RISQUE FAIBLE : 1 machine");
}

void AtelierWidget::chargerMachinesCritiques()
{
    ui->tableMachinesCritiques->setRowCount(3);

    ui->tableMachinesCritiques->setItem(0, 0, new QTableWidgetItem("🔴 URGENT"));
    ui->tableMachinesCritiques->setItem(0, 1, new QTableWidgetItem("Scie Circulaire A"));
    ui->tableMachinesCritiques->setItem(0, 2, new QTableWidgetItem("Surcharge continue"));
    ui->tableMachinesCritiques->setItem(0, 3, new QTableWidgetItem("🔴 ÉLEVÉ"));
    ui->tableMachinesCritiques->setItem(0, 4, new QTableWidgetItem("Maintenance immédiate"));

    ui->tableMachinesCritiques->setItem(1, 0, new QTableWidgetItem("🔴 URGENT"));
    ui->tableMachinesCritiques->setItem(1, 1, new QTableWidgetItem("Ponceuse D"));
    ui->tableMachinesCritiques->setItem(1, 2, new QTableWidgetItem("Heures excessives"));
    ui->tableMachinesCritiques->setItem(1, 3, new QTableWidgetItem("🔴 ÉLEVÉ"));
    ui->tableMachinesCritiques->setItem(1, 4, new QTableWidgetItem("Planifier maintenance"));

    ui->tableMachinesCritiques->setItem(2, 0, new QTableWidgetItem("🔴 CRITIQUE"));
    ui->tableMachinesCritiques->setItem(2, 1, new QTableWidgetItem("Tour à bois E"));
    ui->tableMachinesCritiques->setItem(2, 2, new QTableWidgetItem("Hors service"));
    ui->tableMachinesCritiques->setItem(2, 3, new QTableWidgetItem("❌ PANNE"));
    ui->tableMachinesCritiques->setItem(2, 4, new QTableWidgetItem("Réparation urgente"));
}

void AtelierWidget::chargerMachinesSollicitees()
{
    ui->tableMachinesSollicitees->setRowCount(5);

    ui->tableMachinesSollicitees->setItem(0, 0, new QTableWidgetItem("1"));
    ui->tableMachinesSollicitees->setItem(0, 1, new QTableWidgetItem("Tour à bois E"));
    ui->tableMachinesSollicitees->setItem(0, 2, new QTableWidgetItem("650h"));
    ui->tableMachinesSollicitees->setItem(0, 3, new QTableWidgetItem("3 pannes"));
    ui->tableMachinesSollicitees->setItem(0, 4, new QTableWidgetItem("Immédiate"));

    ui->tableMachinesSollicitees->setItem(1, 0, new QTableWidgetItem("2"));
    ui->tableMachinesSollicitees->setItem(1, 1, new QTableWidgetItem("Scie Circulaire A"));
    ui->tableMachinesSollicitees->setItem(1, 2, new QTableWidgetItem("520h"));
    ui->tableMachinesSollicitees->setItem(1, 3, new QTableWidgetItem("1 panne"));
    ui->tableMachinesSollicitees->setItem(1, 4, new QTableWidgetItem("Dans 20h"));
}
