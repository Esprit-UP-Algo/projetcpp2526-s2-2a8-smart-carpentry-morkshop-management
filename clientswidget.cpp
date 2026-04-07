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
#include <QIntValidator>

ClientsWidget::ClientsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientsWidget)
{
    ui->setupUi(this);

    ui->lineEditID->setValidator(new QIntValidator(1, 999999999, this));

    connect(ui->btnValider, &QPushButton::clicked, this, &ClientsWidget::onAjouter);
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
    int row = 0;
    QSqlQuery q = query; // copy only inside, but Qt allows this safely here
    while (q.next()) {
        ui->tableWidgetClients->insertRow(row);
        ui->tableWidgetClients->setItem(row, 0, new QTableWidgetItem(q.value("ID_CLIENT").toString()));
        ui->tableWidgetClients->setItem(row, 1, new QTableWidgetItem(q.value("NOM").toString()));
        ui->tableWidgetClients->setItem(row, 2, new QTableWidgetItem(q.value("PRENOM").toString()));
        ui->tableWidgetClients->setItem(row, 3, new QTableWidgetItem(q.value("TELEPHONE").toString()));
        ui->tableWidgetClients->setItem(row, 4, new QTableWidgetItem(q.value("EMAIL").toString()));
        ui->tableWidgetClients->setItem(row, 5, new QTableWidgetItem(q.value("ADDRESSE").toString()));
        row++;
    }
}

void ClientsWidget::onAjouter()
{
    if (ui->lineEditID->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Erreur", "ID Client obligatoire.");
        return;
    }

    QSqlQuery query;
    query.prepare(
        "INSERT INTO ATELIER.CLIENT "
        "(ID_CLIENT, NOM, PRENOM, TELEPHONE, EMAIL, ADDRESSE, SOCIETE, MATRICULE_FISCALE, N_CIN, SITE_WEB_FB) "
        "VALUES (:id, :nom, :prenom, :tel, :email, :adresse, :societe, :mf, :ncin, :siteweb)"
    );
    query.bindValue(":id", ui->lineEditID->text().trimmed().toInt());
    query.bindValue(":nom", ui->lineEditNom->text().trimmed());
    query.bindValue(":prenom", ui->lineEditPrenom->text().trimmed());
    query.bindValue(":tel", ui->lineEditTelephone->text().trimmed());
    query.bindValue(":email", ui->lineEditEmail->text().trimmed());
    query.bindValue(":adresse", ui->textEditAdresse->toPlainText().trimmed());
    query.bindValue(":societe", ui->lineEditSociete->text().trimmed());
    query.bindValue(":mf", ui->lineEditMatricule->text().trimmed());
    query.bindValue(":ncin", ui->lineEditCIN->text().trimmed());
    query.bindValue(":siteweb", ui->lineEditSiteWeb->text().trimmed());

    if (query.exec()) {
        QMessageBox::information(this, "Succès", "Client ajouté.");
        chargerTable();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur SQL", query.lastError().text());
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
    c.nom = ui->lineEditNom->text();
    c.prenom = ui->lineEditPrenom->text();
    c.telephone = ui->lineEditTelephone->text();
    c.email = ui->lineEditEmail->text();
    c.adresse = ui->textEditAdresse->toPlainText();
    c.societe = ui->lineEditSociete->text();
    c.matriculeFiscale = ui->lineEditMatricule->text();
    c.cin = ui->lineEditCIN->text();
    c.siteWeb = ui->lineEditSiteWeb->text();

    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Client modifié.");
        chargerTable();
    } else {
        QSqlQuery q;
        QMessageBox::warning(this, "Erreur SQL", q.lastError().text());
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
        QSqlQuery q;
        QMessageBox::warning(this, "Erreur SQL", q.lastError().text());
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
        ui->lineEditID->setText(query.value("ID_CLIENT").toString());
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
    ui->lineEditID->clear();
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
