#include "clientswidget.h"
#include "ui_ClientsWidget.h"
#include "client.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QTableWidgetItem>

ClientsWidget::ClientsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientsWidget)
{
    ui->setupUi(this);

    ui->tableWidgetClients->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->btnAjouter, &QPushButton::clicked, this, &ClientsWidget::onAjouter);
    connect(ui->btnModifier, &QPushButton::clicked, this, &ClientsWidget::onModifier);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &ClientsWidget::onSupprimer);
    connect(ui->btnVider, &QPushButton::clicked, this, &ClientsWidget::onVider);
    connect(ui->btnRechercher, &QPushButton::clicked, this, &ClientsWidget::onRechercher);
    connect(ui->btnAfficherTout, &QPushButton::clicked, this, &ClientsWidget::onAfficherTout);
    connect(ui->btnAfficher, &QPushButton::clicked, this, &ClientsWidget::onAfficherTout);
    connect(ui->btnTrier, &QPushButton::clicked, this, &ClientsWidget::onTrier);
    connect(ui->tableWidgetClients, &QTableWidget::cellClicked, this, &ClientsWidget::onTableClicked);
    connect(ui->btnExportPDF, &QPushButton::clicked, this, &ClientsWidget::onExportPDF);
    connect(ui->btnActualiserStats, &QPushButton::clicked, this, &ClientsWidget::onActualiserStats);

    chargerTable();
}

ClientsWidget::~ClientsWidget()
{
    delete ui;
}

void ClientsWidget::chargerTable(const QString &orderBy)
{
    QSqlQuery query = Client::getAll(orderBy);
    chargerTable(query);
}

void ClientsWidget::chargerTable(const QSqlQuery &query)
{
    ui->tableWidgetClients->setRowCount(0);
    ui->tableWidgetClients->setColumnCount(10);
    ui->tableWidgetClients->setHorizontalHeaderLabels({
        "ID Client", "Nom", "Prénom", "Téléphone", "Email",
        "Adresse", "Société", "Matricule Fiscale", "N° CIN", "Site Web/FB"
    });
    int row = 0;
    QSqlQuery q = query;
    while (q.next()) {
        ui->tableWidgetClients->insertRow(row);
        ui->tableWidgetClients->setItem(row, 0, new QTableWidgetItem(q.value("ID_CLIENT").toString()));
        ui->tableWidgetClients->setItem(row, 1, new QTableWidgetItem(q.value("NOM").toString()));
        ui->tableWidgetClients->setItem(row, 2, new QTableWidgetItem(q.value("PRENOM").toString()));
        ui->tableWidgetClients->setItem(row, 3, new QTableWidgetItem(q.value("TELEPHONE").toString()));
        ui->tableWidgetClients->setItem(row, 4, new QTableWidgetItem(q.value("EMAIL").toString()));
        ui->tableWidgetClients->setItem(row, 5, new QTableWidgetItem(q.value("ADDRESSE").toString()));
        ui->tableWidgetClients->setItem(row, 6, new QTableWidgetItem(q.value("SOCIETE").toString()));
        ui->tableWidgetClients->setItem(row, 7, new QTableWidgetItem(q.value("MATRICULE_FISCALE").toString()));
        ui->tableWidgetClients->setItem(row, 8, new QTableWidgetItem(q.value("N_CIN").toString()));
        ui->tableWidgetClients->setItem(row, 9, new QTableWidgetItem(q.value("SITE_WEB_FB").toString()));
        row++;
    }
}

void ClientsWidget::onAjouter()
{
    Client c;
    c.nom = ui->lineEditNom->text().trimmed();
    c.prenom = ui->lineEditPrenom->text().trimmed();
    c.telephone = ui->lineEditTelephone->text().trimmed();
    c.email = ui->lineEditEmail->text().trimmed();
    c.adresse = ui->textEditAdresse->toPlainText().trimmed();
    c.societe = ui->lineEditSociete->text().trimmed();
    c.matriculeFiscale = ui->lineEditMatricule->text().trimmed();
    c.cin = ui->lineEditCIN->text().trimmed();
    c.siteWeb = ui->lineEditSiteWeb->text().trimmed();

    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Client ajouté.");
        chargerTable();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur SQL", c.lastSqlError);
    }
}

void ClientsWidget::onModifier()
{
    const QString id = ui->tableWidgetClients->currentItem()
        ? ui->tableWidgetClients->item(ui->tableWidgetClients->currentRow(), 0)->text()
        : "";

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionne un client.");
        return;
    }

    Client c;
    c.id = id;
    c.nom = ui->lineEditNom->text().trimmed();
    c.prenom = ui->lineEditPrenom->text().trimmed();
    c.telephone = ui->lineEditTelephone->text().trimmed();
    c.email = ui->lineEditEmail->text().trimmed();
    c.adresse = ui->textEditAdresse->toPlainText().trimmed();
    c.societe = ui->lineEditSociete->text().trimmed();
    c.matriculeFiscale = ui->lineEditMatricule->text().trimmed();
    c.cin = ui->lineEditCIN->text().trimmed();
    c.siteWeb = ui->lineEditSiteWeb->text().trimmed();

    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié.");
        chargerTable();
    } else {
        QMessageBox::warning(this, "Erreur SQL", c.lastSqlError);
    }
}

void ClientsWidget::onSupprimer()
{
    const QString id = ui->tableWidgetClients->currentItem()
        ? ui->tableWidgetClients->item(ui->tableWidgetClients->currentRow(), 0)->text()
        : "";

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionne un client.");
        return;
    }

    if (Client::supprimer(id)) {
        QMessageBox::information(this, "Succès", "Client supprimé.");
        chargerTable();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur SQL", "Échec de suppression. Vérifiez les contraintes FK.");
    }
}

void ClientsWidget::onVider()
{
    clearForm();
}

void ClientsWidget::onRechercher()
{
    const QString term = ui->lineRecherche->text().trimmed();
    if (term.isEmpty()) {
        chargerTable();
        return;
    }
    chargerTable(Client::rechercher(term));
}

void ClientsWidget::onAfficherTout()
{
    ui->lineRecherche->clear();
    chargerTable();
}

void ClientsWidget::onTrier()
{
    const QString tri = ui->comboTri->currentText();
    if (tri.contains("A-Z")) {
        chargerTable("NOM ASC");
    } else {
        chargerTable("NOM DESC");
    }
}

void ClientsWidget::onTableClicked(int row, int)
{
    const QString id = ui->tableWidgetClients->item(row, 0)->text();
    remplirFormulaireDepuisTable(id);
}

void ClientsWidget::remplirFormulaireDepuisTable(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ATELIER.CLIENT WHERE ID_CLIENT = :id");
    query.bindValue(":id", id.toInt());
    query.exec();
    if (query.next()) {
        ui->lineEditNom->setText(query.value("NOM").toString());
        ui->lineEditPrenom->setText(query.value("PRENOM").toString());
        ui->lineEditTelephone->setText(query.value("TELEPHONE").toString());
        ui->lineEditEmail->setText(query.value("EMAIL").toString());
        ui->textEditAdresse->setPlainText(query.value("ADDRESSE").toString());
        ui->lineEditSociete->setText(query.value("SOCIETE").toString());
        ui->lineEditMatricule->setText(query.value("MATRICULE_FISCALE").toString());
        ui->lineEditCIN->setText(query.value("N_CIN").toString());
        ui->lineEditSiteWeb->setText(query.value("SITE_WEB_FB").toString());
    }
}

void ClientsWidget::onExportPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QTextDocument doc;
    QString html = "<h2>Historique des clients</h2><table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>ID</th><th>Nom</th><th>Prénom</th><th>Téléphone</th><th>Email</th><th>Adresse</th></tr>";
    for (int row = 0; row < ui->tableWidgetClients->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < 6; ++col) {
            auto item = ui->tableWidgetClients->item(row, col);
            html += "<td>" + (item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";
    doc.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté.");
}

void ClientsWidget::onActualiserStats()
{
    QSqlQuery query("SELECT COUNT(*) FROM ATELIER.CLIENT");
    if (query.next()) {
        ui->labelTotalClientsValeur->setText(query.value(0).toString());
    }
}

void ClientsWidget::clearForm()
{
    ui->lineEditNom->clear();
    ui->lineEditPrenom->clear();
    ui->lineEditTelephone->clear();
    ui->lineEditEmail->clear();
    ui->textEditAdresse->clear();
    ui->lineEditSociete->clear();
    ui->lineEditMatricule->clear();
    ui->lineEditCIN->clear();
    ui->lineEditSiteWeb->clear();
}
