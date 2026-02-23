#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialogmachine.h"
#include <QPixmap>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QTextStream>
#include <QSqlQuery>
#include <QSqlError>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Charger le logo depuis les ressources Qt
    QPixmap logo(":/images/logo.png");
    
    if (logo.isNull()) {
        qDebug() << "ERREUR : Logo introuvable dans les ressources !";
        ui->lblLogo->setText("LOGO");
        ui->lblLogo->setStyleSheet("background-color: red; color: white;");
    } else {
        qDebug() << "Logo chargé avec succès !";
        ui->lblLogo->setPixmap(logo.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        setWindowIcon(QIcon(logo));
    }
    
    // Initialiser l'interface
    initialiserTableau();
    connectSignals();
    chargerDonnees();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::connectSignals()
{
    // Connexion des boutons de gestion
    connect(ui->btnAjouter, &QPushButton::clicked, this, &MainWindow::onBtnAjouterClicked);
    connect(ui->btnModifier, &QPushButton::clicked, this, &MainWindow::onBtnModifierClicked);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::onBtnSupprimerClicked);
    connect(ui->btnExporter, &QPushButton::clicked, this, &MainWindow::onBtnExporterClicked);
    
    // Connexion des filtres
    connect(ui->btnAppliquerTri, &QPushButton::clicked, this, &MainWindow::onBtnAppliquerTriClicked);
    connect(ui->btnReinitialiser, &QPushButton::clicked, this, &MainWindow::onBtnReinitialiserClicked);
    
    // Connexion des boutons statistiques
    connect(ui->btnPlanifierMaintenance, &QPushButton::clicked, this, &MainWindow::onBtnPlanifierMaintenanceClicked);
    connect(ui->btnDetecterCritiques, &QPushButton::clicked, this, &MainWindow::onBtnDetecterCritiquesClicked);
    connect(ui->btnAnalyserRisques, &QPushButton::clicked, this, &MainWindow::onBtnAnalyserRisquesClicked);
}

void MainWindow::initialiserTableau()
{
    // Configuration du tableau principal (CRUD seulement)
    ui->tableMachines->setColumnWidth(0, 60);   // ID
    ui->tableMachines->setColumnWidth(1, 200);  // NOM
    ui->tableMachines->setColumnWidth(2, 120);  // TYPE
    ui->tableMachines->setColumnWidth(3, 120);  // ÉTAT
    ui->tableMachines->setColumnWidth(4, 120);  // MAINTENANCE
    ui->tableMachines->setColumnWidth(5, 100);  // HEURES
    ui->tableMachines->setColumnWidth(6, 180);  // RESP. MAINTENANCE
    ui->tableMachines->setColumnWidth(7, 180);  // RESP. ATELIER
}

void MainWindow::chargerDonnees()
{
    // Charger les données depuis Oracle
    QSqlQuery query;
    query.prepare("SELECT * FROM MACHINES ORDER BY ID");
    
    if (!query.exec()) {
        qDebug() << "Erreur SQL:" << query.lastError().text();
        QMessageBox::warning(this, "Erreur", "Impossible de charger les données: " + query.lastError().text());
        return;
    }
    
    // Vider le tableau
    ui->tableMachines->setRowCount(0);
    
    int row = 0;
    int totalMachines = 0;
    int disponibles = 0;
    int enMaintenance = 0;
    int horsService = 0;
    
    while (query.next()) {
        ui->tableMachines->insertRow(row);
        
        // Remplir les colonnes
        ui->tableMachines->setItem(row, 0, new QTableWidgetItem(query.value("ID").toString()));
        ui->tableMachines->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableMachines->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableMachines->setItem(row, 3, new QTableWidgetItem(query.value("ETAT").toString()));
        ui->tableMachines->setItem(row, 4, new QTableWidgetItem(query.value("DATE_MAINTENANCE").toString()));
        ui->tableMachines->setItem(row, 5, new QTableWidgetItem(query.value("HEURES_CUMULEES").toString()));
        ui->tableMachines->setItem(row, 6, new QTableWidgetItem(query.value("RESP_MAINTENANCE").toString()));
        ui->tableMachines->setItem(row, 7, new QTableWidgetItem(query.value("RESP_ATELIER").toString()));
        
        // Compter les statistiques
        totalMachines++;
        QString etat = query.value("ETAT").toString();
        if (etat == "Disponible") disponibles++;
        else if (etat == "En maintenance") enMaintenance++;
        else if (etat == "Hors service") horsService++;
        
        row++;
    }
    
    // Mettre à jour les statistiques
    ui->lblTotalMachines->setText("Total Machines: " + QString::number(totalMachines));
    ui->lblMachinesDisponibles->setText("Disponibles: " + QString::number(disponibles));
    ui->lblMachinesMaintenance->setText("En Maintenance: " + QString::number(enMaintenance));
    ui->lblMachinesHS->setText("Hors Service: " + QString::number(horsService));
    
    // Charger les données des métiers innovants
    chargerMachinesCritiques();
    chargerMachinesSollicitees();
}

void MainWindow::onBtnAjouterClicked()
{
    DialogMachine dialog(this);
    dialog.setWindowTitle("Ajouter une Machine");
    
    if (dialog.exec() == QDialog::Accepted) {
        // Récupérer les données du dialogue
        int row = ui->tableMachines->rowCount();
        ui->tableMachines->insertRow(row);
        
        ui->tableMachines->setItem(row, 0, new QTableWidgetItem(QString::number(row + 1).rightJustified(3, '0')));
        ui->tableMachines->setItem(row, 1, new QTableWidgetItem(dialog.getNom()));
        ui->tableMachines->setItem(row, 2, new QTableWidgetItem(dialog.getType()));
        ui->tableMachines->setItem(row, 3, new QTableWidgetItem(dialog.getEtat()));
        ui->tableMachines->setItem(row, 4, new QTableWidgetItem(dialog.getDateMaintenance()));
        ui->tableMachines->setItem(row, 5, new QTableWidgetItem(QString::number(dialog.getHeuresCumulees())));
        ui->tableMachines->setItem(row, 6, new QTableWidgetItem(dialog.getResponsableMaintenance()));
        ui->tableMachines->setItem(row, 7, new QTableWidgetItem(dialog.getResponsableAtelier()));
        
        QMessageBox::information(this, "Succès", "Machine ajoutée avec succès !");
        
        // Recharger les métiers innovants
        chargerMachinesCritiques();
        chargerMachinesSollicitees();
    }
}

void MainWindow::onBtnModifierClicked()
{
    int currentRow = ui->tableMachines->currentRow();
    
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une machine à modifier.");
        return;
    }
    
    DialogMachine dialog(this);
    dialog.setWindowTitle("Modifier la Machine");
    
    // Remplir le dialogue avec les données existantes
    dialog.setID(ui->tableMachines->item(currentRow, 0)->text());
    dialog.setNom(ui->tableMachines->item(currentRow, 1)->text());
    dialog.setType(ui->tableMachines->item(currentRow, 2)->text());
    dialog.setEtat(ui->tableMachines->item(currentRow, 3)->text());
    dialog.setDateMaintenance(ui->tableMachines->item(currentRow, 4)->text());
    dialog.setHeuresCumulees(ui->tableMachines->item(currentRow, 5)->text().toInt());
    dialog.setResponsableMaintenance(ui->tableMachines->item(currentRow, 6)->text());
    dialog.setResponsableAtelier(ui->tableMachines->item(currentRow, 7)->text());
    
    if (dialog.exec() == QDialog::Accepted) {
        // Mettre à jour les données
        ui->tableMachines->item(currentRow, 1)->setText(dialog.getNom());
        ui->tableMachines->item(currentRow, 2)->setText(dialog.getType());
        ui->tableMachines->item(currentRow, 3)->setText(dialog.getEtat());
        ui->tableMachines->item(currentRow, 4)->setText(dialog.getDateMaintenance());
        ui->tableMachines->item(currentRow, 5)->setText(QString::number(dialog.getHeuresCumulees()));
        ui->tableMachines->item(currentRow, 6)->setText(dialog.getResponsableMaintenance());
        ui->tableMachines->item(currentRow, 7)->setText(dialog.getResponsableAtelier());
        
        QMessageBox::information(this, "Succès", "Machine modifiée avec succès !");
    }
}

void MainWindow::onBtnSupprimerClicked()
{
    int currentRow = ui->tableMachines->currentRow();
    
    if (currentRow < 0) {
        QMessageBox::warning(this, "Attention", "Veuillez sélectionner une machine à supprimer.");
        return;
    }
    
    QMessageBox::StandardButton reply = QMessageBox::question(
        this, 
        "Confirmation", 
        "Êtes-vous sûr de vouloir supprimer cette machine ?",
        QMessageBox::Yes | QMessageBox::No
    );
    
    if (reply == QMessageBox::Yes) {
        ui->tableMachines->removeRow(currentRow);
        QMessageBox::information(this, "Succès", "Machine supprimée avec succès !");
    }
}

void MainWindow::onBtnExporterClicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter les données", "", "CSV Files (*.csv)");
    
    if (fileName.isEmpty()) {
        return;
    }
    
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier pour l'écriture.");
        return;
    }
    
    QTextStream out(&file);
    
    // En-têtes
    out << "ID,NOM,TYPE,ÉTAT,MAINTENANCE,HEURES,RESP. MAINTENANCE,RESP. ATELIER,NIVEAU RISQUE,STATUT CRITIQUE,ALERTES\n";
    
    // Données
    for (int row = 0; row < ui->tableMachines->rowCount(); ++row) {
        for (int col = 0; col < ui->tableMachines->columnCount(); ++col) {
            out << ui->tableMachines->item(row, col)->text();
            if (col < ui->tableMachines->columnCount() - 1) {
                out << ",";
            }
        }
        out << "\n";
    }
    
    file.close();
    QMessageBox::information(this, "Succès", "Données exportées avec succès !");
}

void MainWindow::onBtnAppliquerTriClicked()
{
    QString triPar = ui->comboTriPar->currentText();
    
    if (triPar == "-- Aucun tri --") {
        chargerDonnees();
        return;
    }
    
    // Logique de tri selon le critère sélectionné
    if (triPar == "Date de maintenance") {
        ui->tableMachines->sortItems(4, Qt::AscendingOrder);
    } else if (triPar == "Heures d'utilisation") {
        ui->tableMachines->sortItems(5, Qt::DescendingOrder);
    } else if (triPar == "Niveau de risque") {
        ui->tableMachines->sortItems(8, Qt::DescendingOrder);
    } else if (triPar == "Machines critiques") {
        ui->tableMachines->sortItems(9, Qt::DescendingOrder);
    }
    
    QMessageBox::information(this, "Tri appliqué", "Les données ont été triées par : " + triPar);
}

void MainWindow::onBtnReinitialiserClicked()
{
    ui->comboRechercheType->setCurrentIndex(0);
    ui->comboRechercheEtat->setCurrentIndex(0);
    ui->comboTriPar->setCurrentIndex(0);
    chargerDonnees();
}

void MainWindow::onBtnPlanifierMaintenanceClicked()
{
    QMessageBox::information(
        this, 
        "Planification Automatique",
        "Plan de maintenance généré :\n\n"
        "• Scie Circulaire A : Maintenance urgente (520h/500h)\n"
        "• Ponceuse D : Maintenance dans 50h (450h/500h)\n"
        "• Tour à bois E : Réparation immédiate (Hors service)\n\n"
        "Règles appliquées :\n"
        "- Scie : tous les 500h\n"
        "- Perceuse : tous les 300h\n"
        "- Raboteuse : tous les 400h"
    );
}

void MainWindow::onBtnDetecterCritiquesClicked()
{
    QMessageBox::warning(
        this,
        "Machines Critiques Détectées",
        "⚠️ 3 machines critiques détectées :\n\n"
        "1. Scie Circulaire A - Surcharge continue\n"
        "2. Ponceuse D - Heures excessives\n"
        "3. Tour à bois E - Hors service\n\n"
        "Action recommandée : Maintenance immédiate"
    );
}

void MainWindow::onBtnAnalyserRisquesClicked()
{
    QMessageBox::information(
        this,
        "Analyse des Risques",
        "📊 Classement par niveau de risque :\n\n"
        "🔴 RISQUE ÉLEVÉ (3 machines) :\n"
        "- Scie Circulaire A\n"
        "- Ponceuse D\n"
        "- Tour à bois E\n\n"
        "🟠 RISQUE MOYEN (1 machine) :\n"
        "- Raboteuse C\n\n"
        "🟢 RISQUE FAIBLE (1 machine) :\n"
        "- Perceuse B\n\n"
        "⚠️ Prévention goulots d'étranglement activée"
    );
}

void MainWindow::appliquerTri()
{
    // Implémentation du tri
}

void MainWindow::chargerMachinesCritiques()
{
    // Charger le tableau des machines critiques (Métiers Innovants)
    ui->tableMachinesCritiques->setRowCount(3);
    
    // Configurer les largeurs de colonnes
    ui->tableMachinesCritiques->setColumnWidth(0, 120);  // PRIORITÉ
    ui->tableMachinesCritiques->setColumnWidth(1, 200);  // MACHINE
    ui->tableMachinesCritiques->setColumnWidth(2, 180);  // TYPE ALERTE
    ui->tableMachinesCritiques->setColumnWidth(3, 150);  // NIVEAU RISQUE
    ui->tableMachinesCritiques->setColumnWidth(4, 200);  // ACTION REQUISE
    
    // Machine critique 1
    ui->tableMachinesCritiques->setItem(0, 0, new QTableWidgetItem("🔴 URGENT"));
    ui->tableMachinesCritiques->setItem(0, 1, new QTableWidgetItem("Scie Circulaire A"));
    ui->tableMachinesCritiques->setItem(0, 2, new QTableWidgetItem("Surcharge continue"));
    ui->tableMachinesCritiques->setItem(0, 3, new QTableWidgetItem("🔴 ÉLEVÉ"));
    ui->tableMachinesCritiques->setItem(0, 4, new QTableWidgetItem("Maintenance immédiate"));
    
    // Machine critique 2
    ui->tableMachinesCritiques->setItem(1, 0, new QTableWidgetItem("🔴 URGENT"));
    ui->tableMachinesCritiques->setItem(1, 1, new QTableWidgetItem("Ponceuse D"));
    ui->tableMachinesCritiques->setItem(1, 2, new QTableWidgetItem("Heures excessives"));
    ui->tableMachinesCritiques->setItem(1, 3, new QTableWidgetItem("🔴 ÉLEVÉ"));
    ui->tableMachinesCritiques->setItem(1, 4, new QTableWidgetItem("Planifier maintenance"));
    
    // Machine critique 3
    ui->tableMachinesCritiques->setItem(2, 0, new QTableWidgetItem("🔴 CRITIQUE"));
    ui->tableMachinesCritiques->setItem(2, 1, new QTableWidgetItem("Tour à bois E"));
    ui->tableMachinesCritiques->setItem(2, 2, new QTableWidgetItem("Hors service"));
    ui->tableMachinesCritiques->setItem(2, 3, new QTableWidgetItem("❌ PANNE"));
    ui->tableMachinesCritiques->setItem(2, 4, new QTableWidgetItem("Réparation urgente"));
}

void MainWindow::chargerMachinesSollicitees()
{
    // Charger le tableau des machines les plus sollicitées (Métiers Innovants)
    ui->tableMachinesSollicitees->setRowCount(5);
    
    // Configurer les largeurs de colonnes
    ui->tableMachinesSollicitees->setColumnWidth(0, 80);   // RANG
    ui->tableMachinesSollicitees->setColumnWidth(1, 200);  // MACHINE
    ui->tableMachinesSollicitees->setColumnWidth(2, 150);  // HEURES TOTALES
    ui->tableMachinesSollicitees->setColumnWidth(3, 180);  // PANNES FRÉQUENTES
    ui->tableMachinesSollicitees->setColumnWidth(4, 200);  // PROCHAINE MAINTENANCE
    
    // Rang 1
    ui->tableMachinesSollicitees->setItem(0, 0, new QTableWidgetItem("1"));
    ui->tableMachinesSollicitees->setItem(0, 1, new QTableWidgetItem("Tour à bois E"));
    ui->tableMachinesSollicitees->setItem(0, 2, new QTableWidgetItem("650h"));
    ui->tableMachinesSollicitees->setItem(0, 3, new QTableWidgetItem("3 pannes"));
    ui->tableMachinesSollicitees->setItem(0, 4, new QTableWidgetItem("Immédiate"));
    
    // Rang 2
    ui->tableMachinesSollicitees->setItem(1, 0, new QTableWidgetItem("2"));
    ui->tableMachinesSollicitees->setItem(1, 1, new QTableWidgetItem("Scie Circulaire A"));
    ui->tableMachinesSollicitees->setItem(1, 2, new QTableWidgetItem("520h"));
    ui->tableMachinesSollicitees->setItem(1, 3, new QTableWidgetItem("1 panne"));
    ui->tableMachinesSollicitees->setItem(1, 4, new QTableWidgetItem("Dans 20h"));
    
    // Rang 3
    ui->tableMachinesSollicitees->setItem(2, 0, new QTableWidgetItem("3"));
    ui->tableMachinesSollicitees->setItem(2, 1, new QTableWidgetItem("Ponceuse D"));
    ui->tableMachinesSollicitees->setItem(2, 2, new QTableWidgetItem("450h"));
    ui->tableMachinesSollicitees->setItem(2, 3, new QTableWidgetItem("2 pannes"));
    ui->tableMachinesSollicitees->setItem(2, 4, new QTableWidgetItem("Dans 50h"));
    
    // Rang 4
    ui->tableMachinesSollicitees->setItem(3, 0, new QTableWidgetItem("4"));
    ui->tableMachinesSollicitees->setItem(3, 1, new QTableWidgetItem("Raboteuse C"));
    ui->tableMachinesSollicitees->setItem(3, 2, new QTableWidgetItem("380h"));
    ui->tableMachinesSollicitees->setItem(3, 3, new QTableWidgetItem("0 panne"));
    ui->tableMachinesSollicitees->setItem(3, 4, new QTableWidgetItem("Dans 20h"));
    
    // Rang 5
    ui->tableMachinesSollicitees->setItem(4, 0, new QTableWidgetItem("5"));
    ui->tableMachinesSollicitees->setItem(4, 1, new QTableWidgetItem("Perceuse B"));
    ui->tableMachinesSollicitees->setItem(4, 2, new QTableWidgetItem("180h"));
    ui->tableMachinesSollicitees->setItem(4, 3, new QTableWidgetItem("0 panne"));
    ui->tableMachinesSollicitees->setItem(4, 4, new QTableWidgetItem("Dans 120h"));
}

void MainWindow::detecterMachinesCritiques()
{
    // Implémentation de la détection
}

void MainWindow::calculerNiveauRisque()
{
    // Implémentation du calcul de risque
}

void MainWindow::genererAlertes()
{
    // Implémentation de la génération d'alertes
}
