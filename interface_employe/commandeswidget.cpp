#include "commandeswidget.h"
#include "ui_CommandesWidget.h"
#include "commande.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QDate>
#include <QSqlQuery>
#include <QRegularExpression>

CommandesWidget::CommandesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommandesWidget)
{
    ui->setupUi(this);

    connect(ui->btnAjouter, &QPushButton::clicked, this, &CommandesWidget::onAjouter);
    connect(ui->btnModifier, &QPushButton::clicked, this, &CommandesWidget::onModifier);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &CommandesWidget::onSupprimer);
    connect(ui->btnVider, &QPushButton::clicked, this, &CommandesWidget::onVider);

    connect(ui->btnTriPrixCroissant, &QPushButton::clicked, this, &CommandesWidget::onTriPrixCroissant);
    connect(ui->btnTriPrixDecroissant, &QPushButton::clicked, this, &CommandesWidget::onTriPrixDecroissant);

    connect(ui->tableCommandes, &QTableWidget::cellClicked, this, &CommandesWidget::onTableClicked);
    connect(ui->btnRechercher, &QPushButton::clicked, this, &CommandesWidget::onRechercher);
    connect(ui->btnResetRecherche, &QPushButton::clicked, this, &CommandesWidget::onResetRecherche);
    connect(ui->btnGenererStats, &QPushButton::clicked, this, &CommandesWidget::onGenererStats);
    connect(ui->btnGenererPDF, &QPushButton::clicked, this, &CommandesWidget::onGenererPDF);

    chargerResponsables();
    chargerTable();
    remplirComboFacture();
    updateAlertes();
}

CommandesWidget::~CommandesWidget()
{
    delete ui;
}

void CommandesWidget::chargerResponsables()
{
    ui->comboResponsable->clear();
    ui->comboResponsable->addItem("Choisir un responsable");

    QSqlQuery query("SELECT NOM FROM ATELIER.EMPLOYE ORDER BY NOM");
    while (query.next()) {
        ui->comboResponsable->addItem(query.value(0).toString());
    }
}

QString CommandesWidget::buildDimensions() const
{
    return QString("%1x%2x%3 cm")
        .arg(ui->spinLongueur->value())
        .arg(ui->spinLargeur->value())
        .arg(ui->spinHauteur->value());
}

void CommandesWidget::parseDimensions(const QString &dims)
{
    QString cleaned = dims;
    cleaned = cleaned.toLower().replace("cm", "").replace("×", "x");
    const QStringList parts = cleaned.split("x", Qt::SkipEmptyParts);
    if (parts.size() >= 3) {
        ui->spinLongueur->setValue(parts[0].trimmed().toInt());
        ui->spinLargeur->setValue(parts[1].trimmed().toInt());
        ui->spinHauteur->setValue(parts[2].trimmed().toInt());
    }
}

void CommandesWidget::chargerTable(const QString &orderBy)
{
    QSqlQuery query = Commande::getAll(orderBy);
    chargerTable(query);
}

void CommandesWidget::chargerTable(const QSqlQuery &query)
{
    ui->tableCommandes->setRowCount(0);
    int row = 0;
    QSqlQuery q = query;
    while (q.next()) {
        ui->tableCommandes->insertRow(row);
        ui->tableCommandes->setItem(row, 0, new QTableWidgetItem(q.value("ID_COMMANDE").toString()));
        ui->tableCommandes->setItem(row, 1, new QTableWidgetItem(q.value("DATE_COMMANDE").toString()));
        ui->tableCommandes->setItem(row, 2, new QTableWidgetItem(q.value("DETAILS_COMMANDE").toString()));
        ui->tableCommandes->setItem(row, 3, new QTableWidgetItem(q.value("DIMENSIONS").toString()));
        ui->tableCommandes->setItem(row, 4, new QTableWidgetItem(q.value("PRIX").toString()));
        ui->tableCommandes->setItem(row, 5, new QTableWidgetItem(q.value("ETAT").toString()));
        ui->tableCommandes->setItem(row, 6, new QTableWidgetItem("-"));
        row++;
    }
}

void CommandesWidget::chargerResultats(const QSqlQuery &query)
{
    ui->tableResultats->setRowCount(0);
    int row = 0;
    QSqlQuery q = query;
    while (q.next()) {
        ui->tableResultats->insertRow(row);
        ui->tableResultats->setItem(row, 0, new QTableWidgetItem(q.value("ID_COMMANDE").toString()));
        ui->tableResultats->setItem(row, 1, new QTableWidgetItem(q.value("DATE_COMMANDE").toString()));
        ui->tableResultats->setItem(row, 2, new QTableWidgetItem(q.value("DETAILS_COMMANDE").toString()));
        ui->tableResultats->setItem(row, 3, new QTableWidgetItem(q.value("PRIX").toString()));
        ui->tableResultats->setItem(row, 4, new QTableWidgetItem(q.value("ETAT").toString()));
        ui->tableResultats->setItem(row, 5, new QTableWidgetItem("-"));
        row++;
    }
}

void CommandesWidget::onAjouter()
{
    if (ui->comboResponsable->currentIndex() == 0) {
        QMessageBox::warning(this, "Erreur", "Choisir un responsable.");
        return;
    }

    Commande c;
    c.dateCommande = ui->dateCommande->date();
    c.details = ui->txtDetails->toPlainText();
    c.dimensions = buildDimensions();
    c.prix = ui->spinPrix->value();
    c.etat = ui->comboEtat->currentText();

    if (c.ajouter()) {
        QMessageBox::information(this, "Succès", "Commande ajoutée.");
        chargerTable();
        remplirComboFacture();
        updateAlertes();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec d'ajout.");
    }
}

void CommandesWidget::onModifier()
{
    if (!ui->tableCommandes->currentItem()) {
        QMessageBox::warning(this, "Erreur", "Sélectionne une commande.");
        return;
    }

    const int row = ui->tableCommandes->currentRow();
    const QString id = ui->tableCommandes->item(row, 0)->text();

    Commande c;
    c.id = id;
    c.dateCommande = ui->dateCommande->date();
    c.details = ui->txtDetails->toPlainText();
    c.dimensions = buildDimensions();
    c.prix = ui->spinPrix->value();
    c.etat = ui->comboEtat->currentText();

    if (c.modifier()) {
        QMessageBox::information(this, "Succès", "Commande modifiée.");
        chargerTable();
        remplirComboFacture();
        updateAlertes();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de modification.");
    }
}

void CommandesWidget::onSupprimer()
{
    if (!ui->tableCommandes->currentItem()) {
        QMessageBox::warning(this, "Erreur", "Sélectionne une commande.");
        return;
    }

    const int row = ui->tableCommandes->currentRow();
    const QString id = ui->tableCommandes->item(row, 0)->text();

    if (Commande::supprimer(id)) {
        QMessageBox::information(this, "Succès", "Commande supprimée.");
        chargerTable();
        remplirComboFacture();
        updateAlertes();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de suppression.");
    }
}

void CommandesWidget::onVider()
{
    clearForm();
}

void CommandesWidget::onTriPrixCroissant()
{
    chargerTable("PRIX ASC");
}

void CommandesWidget::onTriPrixDecroissant()
{
    chargerTable("PRIX DESC");
}

void CommandesWidget::onTableClicked(int row, int)
{
    remplirFormulaireDepuisTable(row);
}

void CommandesWidget::onRechercher()
{
    const QString critere = ui->comboCritere->currentText();
    const QString valeur = ui->txtRecherche->text().trimmed();

    if (valeur.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Saisir une valeur de recherche.");
        return;
    }

    if (critere.toLower() == "date") {
        QRegularExpression regex("^\\d{4}-\\d{2}-\\d{2}$");
        if (!regex.match(valeur).hasMatch()) {
            QMessageBox::warning(this, "Erreur", "Format date attendu: YYYY-MM-DD");
            return;
        }
    }

    QSqlQuery query = Commande::rechercher(critere, valeur);
    chargerResultats(query);
}

void CommandesWidget::onResetRecherche()
{
    ui->txtRecherche->clear();
    ui->tableResultats->setRowCount(0);
}

void CommandesWidget::onGenererStats()
{
    QSqlQuery query = Commande::statsParMois();
    ui->tableStatsMois->setRowCount(0);

    while (query.next()) {
        int row = ui->tableStatsMois->rowCount();
        ui->tableStatsMois->insertRow(row);
        ui->tableStatsMois->setItem(row, 0, new QTableWidgetItem(query.value("NB").toString()));
        ui->tableStatsMois->setItem(row, 1, new QTableWidgetItem(query.value("TOTAL").toString()));
    }
}

void CommandesWidget::onGenererPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Générer Facture", "", "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QTextDocument doc;
    QString html = "<h2>Facture Commande</h2>";
    if (ui->tableCommandes->currentItem()) {
        int row = ui->tableCommandes->currentRow();
        html += "<p><b>ID :</b> " + ui->tableCommandes->item(row, 0)->text() + "</p>";
    }
    html += "<p><b>Date :</b> " + ui->dateCommande->date().toString("yyyy-MM-dd") + "</p>";
    html += "<p><b>Détails :</b> " + ui->txtDetails->toPlainText() + "</p>";
    html += "<p><b>Dimensions :</b> " + buildDimensions() + "</p>";
    html += "<p><b>Prix :</b> " + QString::number(ui->spinPrix->value()) + " €</p>";
    html += "<p><b>État :</b> " + ui->comboEtat->currentText() + "</p>";
    doc.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "Facture PDF générée.");
}

void CommandesWidget::remplirFormulaireDepuisTable(int row)
{
    ui->dateCommande->setDate(QDate::fromString(ui->tableCommandes->item(row, 1)->text(), "yyyy-MM-dd"));
    ui->txtDetails->setPlainText(ui->tableCommandes->item(row, 2)->text());
    parseDimensions(ui->tableCommandes->item(row, 3)->text());
    ui->spinPrix->setValue(ui->tableCommandes->item(row, 4)->text().toDouble());
    ui->comboEtat->setCurrentText(ui->tableCommandes->item(row, 5)->text());
}

void CommandesWidget::clearForm()
{
    ui->txtDetails->clear();
    ui->dateCommande->setDate(QDate::currentDate());
    ui->spinLongueur->setValue(0);
    ui->spinLargeur->setValue(0);
    ui->spinHauteur->setValue(0);
    ui->spinPrix->setValue(0);
    ui->comboEtat->setCurrentIndex(0);
    ui->comboResponsable->setCurrentIndex(0);
}

void CommandesWidget::remplirComboFacture()
{
    ui->comboFactureCommande->clear();
    QSqlQuery query = Commande::getAll("DATE_COMMANDE DESC");
    while (query.next()) {
        ui->comboFactureCommande->addItem(
            query.value("ID_COMMANDE").toString() + " - " + query.value("DETAILS_COMMANDE").toString()
        );
    }
}

void CommandesWidget::updateAlertes()
{
    QSqlQuery query;
    query.exec("SELECT COUNT(*) FROM ATELIER.COMMANDE WHERE ETAT <> '🔵 Livrée' AND DATE_COMMANDE < SYSDATE - 7");
    if (query.next()) {
        int count = query.value(0).toInt();
        ui->labelAlerte->setText(QString("⚠️ ALERTE: %1 commandes en retard de livraison").arg(count));
    }
}
