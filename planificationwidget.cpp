#include "planificationwidget.h"
#include "ui_PlanificationWidget.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QMessageBox>
#include <QTableWidgetItem>
#include <QHeaderView>
#include <QInputDialog>
#include <QColor>
#include <QDate>

PlanificationWidget::PlanificationWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::PlanificationWidget)
{
    ui->setupUi(this);

    ui->tableListeTaches->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    ui->tableListeTaches->verticalHeader()->setVisible(false);

    ui->dateDebut->setDate(QDate::currentDate());
    ui->dateFin->setDate(QDate::currentDate().addDays(1));

    remplirCombos();
    chargerListeTaches();

    connect(ui->btnAjouter,        &QPushButton::clicked, this, &PlanificationWidget::onAjouter);
    connect(ui->btnSupprimer,      &QPushButton::clicked, this, &PlanificationWidget::onSupprimer);
    connect(ui->btnModifierStatut, &QPushButton::clicked, this, &PlanificationWidget::onModifierStatut);
    connect(ui->comboFiltreStatut, QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PlanificationWidget::onFiltreChanged);
    connect(ui->comboFiltreEmploye,QOverload<int>::of(&QComboBox::currentIndexChanged), this, &PlanificationWidget::onFiltreChanged);
    connect(ui->tableListeTaches,  &QTableWidget::cellClicked, this, &PlanificationWidget::onTableClicked);
}

PlanificationWidget::~PlanificationWidget()
{
    delete ui;
}

void PlanificationWidget::remplirCombos()
{
    // Employés
    auto remplirEmp = [&](QComboBox *cb, bool avecTous) {
        cb->clear();
        if (avecTous) cb->addItem("-- Tous --", QVariant());
        QSqlQuery q("SELECT ID_EMPLOYE, NOM FROM ATELIER.EMPLOYE ORDER BY NOM");
        while (q.next())
            cb->addItem(q.value("NOM").toString(), q.value("ID_EMPLOYE"));
    };
    remplirEmp(ui->comboEmploye,       false);
    remplirEmp(ui->comboFiltreEmploye, true);

    // Commandes
    ui->comboCommande->clear();
    QSqlQuery qCmd("SELECT ID_COMMANDE, DETAILS_COMMANDE FROM ATELIER.COMMANDE ORDER BY ID_COMMANDE DESC");
    while (qCmd.next())
        ui->comboCommande->addItem(
            "#" + qCmd.value("ID_COMMANDE").toString() + " — " + qCmd.value("DETAILS_COMMANDE").toString(),
            qCmd.value("ID_COMMANDE"));

    // Machines
    ui->comboMachine->clear();
    ui->comboMachine->addItem("-- Aucune --", QVariant());
    QSqlQuery qMac("SELECT ID_MACHINE, REFERENCE, TYPE FROM ATELIER.MACHINE ORDER BY TYPE");
    while (qMac.next())
        ui->comboMachine->addItem(
            qMac.value("REFERENCE").toString() + " (" + qMac.value("TYPE").toString() + ")",
            qMac.value("ID_MACHINE"));
}

void PlanificationWidget::chargerListeTaches()
{
    QString sql =
        "SELECT p.ID_TACHE, p.PRIORITE, e.NOM, c.DETAILS_COMMANDE, "
        "       NVL(TO_CHAR(m.ID_MACHINE),'—'), p.DATE_DEBUT, p.DATE_FIN, p.STATUT, NVL(p.NOTES,'') "
        "FROM ATELIER.PLANIFICATION p "
        "JOIN ATELIER.COMMANDE c ON p.ID_COMMANDE = c.ID_COMMANDE "
        "JOIN ATELIER.EMPLOYE  e ON p.ID_EMPLOYE  = e.ID_EMPLOYE "
        "LEFT JOIN ATELIER.MACHINE m ON p.ID_MACHINE = m.ID_MACHINE "
        "WHERE 1=1 ";

    QString filtreStatut = ui->comboFiltreStatut->currentText();
    if (filtreStatut != "-- Tous --")
        sql += "AND p.STATUT = '" + filtreStatut + "' ";

    QVariant filtreEmp = ui->comboFiltreEmploye->currentData();
    if (filtreEmp.isValid())
        sql += "AND p.ID_EMPLOYE = " + filtreEmp.toString() + " ";

    sql += "ORDER BY p.DATE_DEBUT, p.PRIORITE";

    QSqlQuery q;
    q.prepare(sql);
    q.exec();

    ui->tableListeTaches->setRowCount(0);
    int row = 0;
    while (q.next()) {
        ui->tableListeTaches->insertRow(row);
        ui->tableListeTaches->setItem(row, 0, new QTableWidgetItem(q.value(0).toString()));
        ui->tableListeTaches->setItem(row, 1, new QTableWidgetItem(iconePriorite(q.value(1).toInt())));
        ui->tableListeTaches->setItem(row, 2, new QTableWidgetItem(q.value(2).toString()));
        ui->tableListeTaches->setItem(row, 3, new QTableWidgetItem(q.value(3).toString()));
        ui->tableListeTaches->setItem(row, 4, new QTableWidgetItem(q.value(4).toString()));
        ui->tableListeTaches->setItem(row, 5, new QTableWidgetItem(q.value(5).toDate().toString("dd/MM/yyyy")));
        ui->tableListeTaches->setItem(row, 6, new QTableWidgetItem(q.value(6).toDate().toString("dd/MM/yyyy")));

        QString statut = q.value(7).toString();
        auto *itemStatut = new QTableWidgetItem(statut);
        itemStatut->setBackground(QColor(couleurStatut(statut)));
        ui->tableListeTaches->setItem(row, 7, itemStatut);
        ui->tableListeTaches->setItem(row, 8, new QTableWidgetItem(q.value(8).toString()));
        row++;
    }
}

void PlanificationWidget::onAjouter()
{
    if (ui->comboEmploye->currentIndex() < 0 || ui->comboCommande->currentIndex() < 0) {
        QMessageBox::warning(this, "Erreur", "Veuillez sélectionner un employé et une commande.");
        return;
    }
    if (ui->dateFin->date() < ui->dateDebut->date()) {
        QMessageBox::warning(this, "Erreur", "La date de fin doit être après la date de début.");
        return;
    }

    int idEmploye  = ui->comboEmploye->currentData().toInt();
    int idCommande = ui->comboCommande->currentData().toInt();
    QVariant idMachine = ui->comboMachine->currentData();
    int priorite = ui->comboPriorite->currentIndex() + 1;

    QSqlQuery q;
    q.prepare(
        "INSERT INTO ATELIER.PLANIFICATION "
        "(ID_COMMANDE, ID_EMPLOYE, ID_MACHINE, DATE_DEBUT, DATE_FIN, STATUT, PRIORITE, NOTES) "
        "VALUES (:cmd, :emp, :mac, :debut, :fin, 'En attente', :prio, :notes)"
    );
    q.bindValue(":cmd",   idCommande);
    q.bindValue(":emp",   idEmploye);
    q.bindValue(":mac",   idMachine.isValid() ? idMachine : QVariant(QVariant::Int));
    q.bindValue(":debut", ui->dateDebut->date());
    q.bindValue(":fin",   ui->dateFin->date());
    q.bindValue(":prio",  priorite);
    q.bindValue(":notes", ui->txtNotes->toPlainText().trimmed());

    if (!q.exec()) {
        QMessageBox::warning(this, "Erreur SQL", q.lastError().text());
        return;
    }

    QMessageBox::information(this, "Succès", "Tâche assignée avec succès !");
    clearFormulaire();
    chargerListeTaches();
}

void PlanificationWidget::onSupprimer()
{
    int row = ui->tableListeTaches->currentRow();
    if (row < 0) { QMessageBox::warning(this, "Attention", "Sélectionnez une tâche."); return; }

    int id = ui->tableListeTaches->item(row, 0)->text().toInt();
    if (QMessageBox::question(this, "Confirmation", "Supprimer cette tâche ?",
        QMessageBox::Yes | QMessageBox::No) != QMessageBox::Yes) return;

    QSqlQuery q;
    q.prepare("DELETE FROM ATELIER.PLANIFICATION WHERE ID_TACHE = :id");
    q.bindValue(":id", id);
    if (!q.exec()) { QMessageBox::warning(this, "Erreur SQL", q.lastError().text()); return; }
    chargerListeTaches();
}

void PlanificationWidget::onModifierStatut()
{
    int row = ui->tableListeTaches->currentRow();
    if (row < 0) { QMessageBox::warning(this, "Attention", "Sélectionnez une tâche."); return; }

    int id = ui->tableListeTaches->item(row, 0)->text().toInt();

    // Statuts compatibles avec la contrainte SQL: En attente, En cours, Terminee, En retard
    QStringList statuts = {"En attente", "En cours", "Terminee", "En retard"};
    bool ok;
    QString choix = QInputDialog::getItem(this, "Changer le statut", "Nouveau statut :", statuts, 0, false, &ok);
    if (!ok) return;

    QSqlQuery q;
    q.prepare("UPDATE ATELIER.PLANIFICATION SET STATUT=:s WHERE ID_TACHE=:id");
    q.bindValue(":s",  choix);
    q.bindValue(":id", id);
    if (!q.exec()) { QMessageBox::warning(this, "Erreur SQL", q.lastError().text()); return; }
    chargerListeTaches();
}

void PlanificationWidget::onFiltreChanged() { chargerListeTaches(); }

void PlanificationWidget::onTableClicked(int row, int) { Q_UNUSED(row) }

void PlanificationWidget::clearFormulaire()
{
    ui->txtNotes->clear();
    ui->dateDebut->setDate(QDate::currentDate());
    ui->dateFin->setDate(QDate::currentDate().addDays(1));
    ui->comboPriorite->setCurrentIndex(1);
}

QString PlanificationWidget::couleurStatut(const QString &statut) const
{
    if (statut == "En cours")   return "#C8E6C9";
    if (statut == "En attente") return "#FFF9C4";
    if (statut == "En retard")  return "#FFCDD2";
    if (statut == "Terminee")   return "#E0E0E0";
    return "#FFFFFF";
}

QString PlanificationWidget::iconePriorite(int priorite) const
{
    if (priorite == 1) return "🔴 Haute";
    if (priorite == 3) return "🟢 Basse";
    return "🟡 Normale";
}
