#include "commandeswidget.h"
#include "ui_CommandesWidget.h"
#include "commande.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QDir>
#include <QFile>
#include <QDate>
#include <QSqlQuery>
#include <QRegularExpression>
#include <QPainter>
#include <QDesktopServices>
#include <QCoreApplication>
#include <QUrl>
#include <QDebug>
#include <QPageSize>
#include <QPageLayout>

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

    // Synchroniser la comboBox avec la commande sélectionnée
    QString id = ui->tableCommandes->item(row, 0)->text();
    for (int i = 0; i < ui->comboFactureCommande->count(); i++) {
        if (ui->comboFactureCommande->itemText(i).startsWith(id)) {
            ui->comboFactureCommande->setCurrentIndex(i);
            break;
        }
    }
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
    int row = -1;

    // 1. Vérifier si une commande est sélectionnée dans le tableau
    if (ui->tableCommandes->currentItem()) {
        row = ui->tableCommandes->currentRow();
        qDebug() << "Commande sélectionnée dans le tableau, row:" << row;
    }
    // 2. Sinon, vérifier si une commande est sélectionnée dans la comboBox
    else if (ui->comboFactureCommande->currentIndex() >= 0) {
        QString selected = ui->comboFactureCommande->currentText();
        QString id = selected.split(" - ").first();
        qDebug() << "Commande sélectionnée dans comboBox, ID:" << id;

        for (int i = 0; i < ui->tableCommandes->rowCount(); i++) {
            if (ui->tableCommandes->item(i, 0)->text() == id) {
                row = i;
                break;
            }
        }
    }

    if (row < 0) {
        QMessageBox::warning(this, "Erreur",
                             "Veuillez sélectionner une commande :\n"
                             "- Cliquez sur une ligne dans le tableau\n"
                             "- OU sélectionnez une commande dans la liste déroulante");
        return;
    }

    QString fileName = QFileDialog::getSaveFileName(this, "Générer Facture",
                                                    QString("Facture_CMD-%1.pdf").arg(ui->tableCommandes->item(row, 0)->text()),
                                                    "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    genererFactureAvecQR(fileName, row);
}

QString CommandesWidget::genererUrlPaiement(int row)
{
    QString htmlPath = QCoreApplication::applicationDirPath() + "/html/paiement.html";
    QString reference = QString("CMD-%1").arg(ui->tableCommandes->item(row, 0)->text());
    QString client = ui->comboResponsable->currentText();
    QString date = ui->tableCommandes->item(row, 1)->text();
    QString produit = ui->tableCommandes->item(row, 2)->text();
    QString montant = ui->tableCommandes->item(row, 4)->text();

    return QString("file:///%1?ref=%2&client=%3&date=%4&produit=%5&montant=%6")
        .arg(htmlPath)
        .arg(reference)
        .arg(client)
        .arg(date)
        .arg(produit)
        .arg(montant);
}

void CommandesWidget::genererFactureAvecQR(const QString &chemin, int row)
{
    // Récupérer les données
    QString id = ui->tableCommandes->item(row, 0)->text();
    QString date = ui->tableCommandes->item(row, 1)->text();
    QString details = ui->tableCommandes->item(row, 2)->text();
    QString dimensions = ui->tableCommandes->item(row, 3)->text();
    QString prix = ui->tableCommandes->item(row, 4)->text();
    QString responsable = ui->comboResponsable->currentText();

    // Générer l'URL de paiement
    QString urlPaiement = genererUrlPaiement(row);

    // Générer le QR code
    QPixmap qr = qrManager.genererQRCode(urlPaiement, 200);

    // Sauvegarder temporairement le QR code
    QString qrTempPath = QDir::tempPath() + "/qr_temp.png";
    qr.save(qrTempPath);

    // Créer le HTML
    QString html = QString(
                       "<!DOCTYPE html>"
                       "<html>"
                       "<head>"
                       "<meta charset='UTF-8'>"
                       "<style>"
                       "body { font-family: Arial, sans-serif; margin: 40px; }"
                       ".header { text-align: center; border-bottom: 2px solid #8B5A2B; padding-bottom: 20px; margin-bottom: 30px; }"
                       ".title { font-size: 24px; font-weight: bold; color: #8B5A2B; }"
                       ".subtitle { font-size: 18px; font-weight: bold; margin: 20px 0 10px 0; }"
                       ".info { margin: 10px 0; }"
                       ".total { font-size: 20px; font-weight: bold; color: #27ae60; margin: 20px 0; }"
                       ".qr { text-align: center; margin: 30px 0; }"
                       ".qr img { max-width: 250px; border: 1px solid #ddd; padding: 10px; }"
                       ".footer { margin-top: 50px; text-align: center; font-size: 10px; color: #999; border-top: 1px solid #ddd; padding-top: 20px; }"
                       "</style>"
                       "</head>"
                       "<body>"
                       "<div class='header'>"
                       "<div class='title'>🏠 SMART CARPENTRY WORKSHOP</div>"
                       "<div>Atelier de menuiserie artisanale</div>"
                       "</div>"

                       "<div class='subtitle'>FACTURE DE COMMANDE</div>"
                       "<div class='info'>Date d'émission: %1</div>"
                       "<hr>"

                       "<div class='subtitle'>Informations commande</div>"
                       "<div class='info'><b>N° commande:</b> %2</div>"
                       "<div class='info'><b>Date commande:</b> %3</div>"
                       "<div class='info'><b>Client:</b> %4</div>"
                       "<hr>"

                       "<div class='subtitle'>Détails produit</div>"
                       "<div class='info'><b>Description:</b> %5</div>"
                       "<div class='info'><b>Dimensions:</b> %6</div>"
                       "<hr>"

                       "<div class='total'>Total à payer: %7 €</div>"

                       "<div class='qr'>"
                       "<img src='%8'>"
                       "<div>🔍 Scannez ce QR code pour payer en ligne</div>"
                       "</div>"

                       "<div class='footer'>"
                       "Smart Carpentry Workshop - Artisans du bois depuis 2020<br>"
                       "Merci de votre confiance !"
                       "</div>"
                       "</body>"
                       "</html>"
                       )
                       .arg(QDate::currentDate().toString("dd/MM/yyyy"))
                       .arg(id)
                       .arg(date)
                       .arg(responsable)
                       .arg(details)
                       .arg(dimensions)
                       .arg(prix)
                       .arg(qrTempPath);

    // Créer le PDF à partir du HTML
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(chemin);
    printer.setPageSize(QPageSize(QPageSize::A4));
    printer.setPageOrientation(QPageLayout::Portrait);

    QTextDocument doc;
    doc.setHtml(html);
    doc.print(&printer);

    // Supprimer le fichier temporaire
    QFile::remove(qrTempPath);

    QMessageBox::information(this, "Succès", "Facture PDF générée avec QR code !");
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
