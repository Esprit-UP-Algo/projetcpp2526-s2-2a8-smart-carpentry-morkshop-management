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
#include <QRegularExpression>

ClientsWidget::ClientsWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ClientsWidget)
{
    ui->setupUi(this);

    ui->tableWidgetClients->setEditTriggers(QAbstractItemView::NoEditTriggers);

    ui->tableWidgetClients->setColumnCount(8);
    ui->tableWidgetClients->setHorizontalHeaderLabels({
        "ID", "Nom", "Prénom", "CIN", "Téléphone", "Email", "Adresse", "Matricule Fiscale"
    });
    ui->tableWidgetClients->setColumnHidden(0, true);

    connect(ui->btnValider, &QPushButton::clicked, this, &ClientsWidget::onValider);
    connect(ui->btnConfirmerModification, &QPushButton::clicked, this, &ClientsWidget::onConfirmerModification);

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

    connect(ui->lineEditMatricule, &QLineEdit::textChanged, this, &ClientsWidget::onMatriculeTextChanged);

    ui->btnConfirmerModification->setEnabled(false);

    chargerTable();
    onActualiserStats();
}

ClientsWidget::~ClientsWidget()
{
    delete ui;
}

void ClientsWidget::onMatriculeTextChanged(const QString &text)
{
    QString s = text;
    s.remove(QRegularExpression("\\s+"));
    s = s.toUpper();

    if (s != text) {
        QSignalBlocker blocker(ui->lineEditMatricule);
        ui->lineEditMatricule->setText(s);
    }
}

// ====== UNIQUENESS CHECKS ======
bool ClientsWidget::cinExists(const QString &cin, const QString &excludeId) const
{
    QSqlQuery q;
    QString sql = "SELECT COUNT(*) FROM ATELIER.CLIENT WHERE N_CIN = :cin";
    if (!excludeId.isEmpty()) sql += " AND ID_CLIENT <> :id";
    q.prepare(sql);
    q.bindValue(":cin", cin);
    if (!excludeId.isEmpty()) q.bindValue(":id", excludeId);
    if (q.exec() && q.next()) return q.value(0).toInt() > 0;
    return false;
}

bool ClientsWidget::emailExists(const QString &email, const QString &excludeId) const
{
    QSqlQuery q;
    QString sql = "SELECT COUNT(*) FROM ATELIER.CLIENT WHERE LOWER(EMAIL) = LOWER(:email)";
    if (!excludeId.isEmpty()) sql += " AND ID_CLIENT <> :id";
    q.prepare(sql);
    q.bindValue(":email", email);
    if (!excludeId.isEmpty()) q.bindValue(":id", excludeId);
    if (q.exec() && q.next()) return q.value(0).toInt() > 0;
    return false;
}

bool ClientsWidget::telExists(const QString &tel, const QString &excludeId) const
{
    QSqlQuery q;
    QString sql = "SELECT COUNT(*) FROM ATELIER.CLIENT WHERE TELEPHONE = :tel";
    if (!excludeId.isEmpty()) sql += " AND ID_CLIENT <> :id";
    q.prepare(sql);
    q.bindValue(":tel", tel);
    if (!excludeId.isEmpty()) q.bindValue(":id", excludeId);
    if (q.exec() && q.next()) return q.value(0).toInt() > 0;
    return false;
}

bool ClientsWidget::matriculeExists(const QString &mf, const QString &excludeId) const
{
    QSqlQuery q;
    QString sql = "SELECT COUNT(*) FROM ATELIER.CLIENT WHERE MATRICULE_FISCALE = :mf";
    if (!excludeId.isEmpty()) sql += " AND ID_CLIENT <> :id";
    q.prepare(sql);
    q.bindValue(":mf", mf);
    if (!excludeId.isEmpty()) q.bindValue(":id", excludeId);
    if (q.exec() && q.next()) return q.value(0).toInt() > 0;
    return false;
}

// ====== VALIDATION ======
bool ClientsWidget::validateForm(QStringList &errors, const QString &excludeId) const
{
    const QString nom = ui->lineEditNom->text().trimmed();
    const QString prenom = ui->lineEditPrenom->text().trimmed();
    const QString tel = ui->lineEditTelephone->text().trimmed();
    const QString email = ui->lineEditEmail->text().trimmed();
    const QString adresse = ui->textEditAdresse->toPlainText().trimmed();
    const QString societe = ui->lineEditSociete->text().trimmed();
    const QString mf = ui->lineEditMatricule->text().trimmed();
    const QString cin = ui->lineEditCIN->text().trimmed();
    const QString site = ui->lineEditSiteWeb->text().trimmed();

    if (nom.isEmpty()) {
        errors << "• Nom obligatoire.";
    } else if (!QRegularExpression("^[A-Za-zÀ-ÿ\\s-]+$").match(nom).hasMatch()) {
        errors << "• Nom invalide : uniquement des lettres.";
    }

    if (prenom.isEmpty()) {
        errors << "• Prénom obligatoire.";
    } else if (!QRegularExpression("^[A-Za-zÀ-ÿ\\s-]+$").match(prenom).hasMatch()) {
        errors << "• Prénom invalide : uniquement des lettres.";
    }

    if (tel.isEmpty()) {
        errors << "• Téléphone obligatoire (8 chiffres).";
    } else if (!QRegularExpression("^[0-9]{8}$").match(tel).hasMatch()) {
        errors << "• Téléphone invalide : 8 chiffres.";
    } else if (telExists(tel, excludeId)) {
        errors << "• Téléphone déjà utilisé par un autre client.";
    }

    if (email.isEmpty()) {
        errors << "• Email obligatoire.";
    } else if (!QRegularExpression("^[A-Za-z0-9._%+-]+@gmail\\.com$").match(email).hasMatch()) {
        errors << "• Email invalide : doit se terminer par @gmail.com.";
    } else if (emailExists(email, excludeId)) {
        errors << "• Email déjà utilisé par un autre client.";
    }

    if (adresse.isEmpty()) {
        errors << "• Adresse obligatoire.";
    }

    if (societe.isEmpty()) {
        errors << "• Société obligatoire.";
    } else if (societe.length() < 2) {
        errors << "• Société invalide.";
    }

    if (mf.isEmpty()) {
        errors << "• Matricule fiscale obligatoire.";
    } else {
        if (!QRegularExpression("^[0-9]{7}[A-Z]/[0-9]{9}/[A-Z]$").match(mf).hasMatch()) {
            errors << "• Matricule fiscale invalide (ex: 0000000A/123456789/A).";
        } else if (matriculeExists(mf, excludeId)) {
            errors << "• Matricule fiscale déjà utilisé.";
        }
    }

    if (cin.isEmpty()) {
        errors << "• CIN obligatoire.";
    } else {
        if (!QRegularExpression("^[0-9]{8}$").match(cin).hasMatch()) {
            errors << "• CIN invalide : 8 chiffres.";
        } else if (cinExists(cin, excludeId)) {
            errors << "• CIN déjà utilisé par un autre client.";
        }
    }

    if (!site.isEmpty()) {
        if (!QRegularExpression("^(https?://|www\\.|[A-Za-z0-9.-]+\\.[A-Za-z]{2,})(/.*)?$").match(site).hasMatch()) {
            errors << "• Site web/FB invalide.";
        }
    }

    return errors.isEmpty();
}

bool ClientsWidget::hasChanges() const
{
    return
        ui->lineEditNom->text().trimmed() != origNom ||
        ui->lineEditPrenom->text().trimmed() != origPrenom ||
        ui->lineEditTelephone->text().trimmed() != origTel ||
        ui->lineEditEmail->text().trimmed() != origEmail ||
        ui->textEditAdresse->toPlainText().trimmed() != origAdresse ||
        ui->lineEditSociete->text().trimmed() != origSociete ||
        ui->lineEditMatricule->text().trimmed() != origMF ||
        ui->lineEditCIN->text().trimmed() != origCin ||
        ui->lineEditSiteWeb->text().trimmed() != origSite;
}

// ====== AJOUT ======
void ClientsWidget::onValider()
{
    if (!currentEditId.isEmpty()) {
        QMessageBox::warning(this, "Modification en cours", "Utilise 'Confirmer modification'.");
        return;
    }

    QStringList errors;
    if (!validateForm(errors)) {
        QMessageBox::warning(this, "Erreurs de saisie", errors.join("\n"));
        return;
    }

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
        onActualiserStats();
    } else {
        QSqlQuery q;
        QMessageBox::warning(this, "Erreur SQL", q.lastError().text());
    }
}

// ====== MODIFICATION ======
void ClientsWidget::onConfirmerModification()
{
    if (currentEditId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun client sélectionné.");
        return;
    }

    if (!hasChanges()) {
        QMessageBox::information(this, "Aucune modification", "Aucune modification détectée.");
        return;
    }

    QStringList errors;
    if (!validateForm(errors, currentEditId)) {
        QMessageBox::warning(this, "Erreurs de saisie", errors.join("\n"));
        return;
    }

    Client c;
    c.id = currentEditId;
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
        clearForm();
        onActualiserStats();
    } else {
        QSqlQuery q;
        QMessageBox::warning(this, "Erreur SQL", q.lastError().text());
    }
}

// ====== ACTIONS ======
void ClientsWidget::onAjouter()
{
    currentEditId.clear();
    ui->btnConfirmerModification->setEnabled(false);
    ui->tabWidget->setCurrentIndex(0);
    clearForm();
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

    currentEditId = id;
    remplirFormulaireDepuisTable(id);
    ui->tabWidget->setCurrentIndex(0);
    ui->btnConfirmerModification->setEnabled(true);

    origNom = ui->lineEditNom->text().trimmed();
    origPrenom = ui->lineEditPrenom->text().trimmed();
    origTel = ui->lineEditTelephone->text().trimmed();
    origEmail = ui->lineEditEmail->text().trimmed();
    origAdresse = ui->textEditAdresse->toPlainText().trimmed();
    origSociete = ui->lineEditSociete->text().trimmed();
    origMF = ui->lineEditMatricule->text().trimmed();
    origCin = ui->lineEditCIN->text().trimmed();
    origSite = ui->lineEditSiteWeb->text().trimmed();
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
        onActualiserStats();
    } else {
        QSqlQuery q;
        QMessageBox::warning(this, "Erreur SQL", q.lastError().text());
    }
}

// ====== VIDER (Oui/Non) ======
void ClientsWidget::onVider()
{
    QMessageBox msg(this);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowTitle("Confirmation");
    msg.setText("Voulez-vous supprimer tous les clients ?");
    msg.setInformativeText("Cette action est irréversible.");
    QPushButton *ouiBtn = msg.addButton("Oui", QMessageBox::YesRole);
    QPushButton *nonBtn = msg.addButton("Non", QMessageBox::NoRole);
    msg.setDefaultButton(nonBtn);
    msg.exec();

    if (msg.clickedButton() != ouiBtn) return;

    QSqlQuery q;
    if (q.exec("DELETE FROM ATELIER.CLIENT")) {
        QMessageBox::information(this, "Succès", "Tous les clients ont été supprimés.");
        chargerTable();
        clearForm();
        onActualiserStats();
    } else {
        QMessageBox::warning(this, "Erreur", "Suppression impossible : " + q.lastError().text());
    }
}

// ====== RECHERCHE & TRI ======
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
    ui->comboTri->setCurrentIndex(0);
    chargerTable();
}

void ClientsWidget::onTrier()
{
    const QString tri = ui->comboTri->currentText();
    const QString order = tri.contains("A-Z") ? "ASC" : "DESC";
    const QString term = ui->lineRecherche->text().trimmed();

    if (term.isEmpty()) {
        chargerTable(QString("NOM %1").arg(order));
        return;
    }

    QSqlQuery q;
    q.prepare("SELECT * FROM ATELIER.CLIENT "
              "WHERE LOWER(NOM) LIKE :term OR TELEPHONE LIKE :term "
              "ORDER BY NOM " + order);
    q.bindValue(":term", "%" + term.toLower() + "%");
    q.exec();
    chargerTable(q);
}

void ClientsWidget::onTableClicked(int row, int)
{
    const QString id = ui->tableWidgetClients->item(row, 0)->text();
    currentEditId = id;
    remplirFormulaireDepuisTable(id);
    ui->btnConfirmerModification->setEnabled(true);

    origNom = ui->lineEditNom->text().trimmed();
    origPrenom = ui->lineEditPrenom->text().trimmed();
    origTel = ui->lineEditTelephone->text().trimmed();
    origEmail = ui->lineEditEmail->text().trimmed();
    origAdresse = ui->textEditAdresse->toPlainText().trimmed();
    origSociete = ui->lineEditSociete->text().trimmed();
    origMF = ui->lineEditMatricule->text().trimmed();
    origCin = ui->lineEditCIN->text().trimmed();
    origSite = ui->lineEditSiteWeb->text().trimmed();
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

// ====== EXPORT ======
void ClientsWidget::onExportPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QTextDocument doc;
    QString html = "<h2>Historique des clients</h2><table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>Nom</th><th>Prénom</th><th>CIN</th><th>Téléphone</th><th>Email</th><th>Adresse</th><th>Matricule</th></tr>";
    for (int row = 0; row < ui->tableWidgetClients->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 1; col < 8; ++col) {
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

// ====== STATS ======
void ClientsWidget::onActualiserStats()
{
    QSqlQuery q;
    q.prepare(
        "SELECT "
        "COUNT(*) AS total, "
        "SUM(CASE WHEN SOCIETE IS NOT NULL AND TRIM(SOCIETE) <> '' THEN 1 ELSE 0 END) AS societe, "
        "SUM(CASE WHEN N_CIN IS NOT NULL AND TRIM(N_CIN) <> '' THEN 1 ELSE 0 END) AS cin, "
        "SUM(CASE WHEN LOWER(EMAIL) LIKE '%@gmail.com' THEN 1 ELSE 0 END) AS gmail "
        "FROM ATELIER.CLIENT"
    );

    if (q.exec() && q.next()) {
        ui->labelTotalClientsValeur->setText(q.value("total").toString());
        ui->labelTotalSocieteValeur->setText(q.value("societe").toString());
        ui->labelTotalCINValeur->setText(q.value("cin").toString());
        ui->labelTotalGmailValeur->setText(q.value("gmail").toString());
    }
}

// ====== TABLE ======
void ClientsWidget::chargerTable(const QString &orderBy)
{
    QSqlQuery query = Client::getAll(orderBy);
    chargerTable(query);
}

void ClientsWidget::chargerTable(const QSqlQuery &query)
{
    ui->tableWidgetClients->setRowCount(0);
    int row = 0;
    QSqlQuery q = query;
    while (q.next()) {
        ui->tableWidgetClients->insertRow(row);
        ui->tableWidgetClients->setItem(row, 0, new QTableWidgetItem(q.value("ID_CLIENT").toString()));
        ui->tableWidgetClients->setItem(row, 1, new QTableWidgetItem(q.value("NOM").toString()));
        ui->tableWidgetClients->setItem(row, 2, new QTableWidgetItem(q.value("PRENOM").toString()));
        ui->tableWidgetClients->setItem(row, 3, new QTableWidgetItem(q.value("N_CIN").toString()));
        ui->tableWidgetClients->setItem(row, 4, new QTableWidgetItem(q.value("TELEPHONE").toString()));
        ui->tableWidgetClients->setItem(row, 5, new QTableWidgetItem(q.value("EMAIL").toString()));
        ui->tableWidgetClients->setItem(row, 6, new QTableWidgetItem(q.value("ADDRESSE").toString()));
        ui->tableWidgetClients->setItem(row, 7, new QTableWidgetItem(q.value("MATRICULE_FISCALE").toString()));
        row++;
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

    currentEditId.clear();
    ui->btnConfirmerModification->setEnabled(false);
}
