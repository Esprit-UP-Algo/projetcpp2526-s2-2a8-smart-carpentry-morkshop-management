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
#include <QGridLayout>
#include <QComboBox>
#include <QLabel>
#include <QSignalBlocker>
#include <utility>

CommandesWidget::CommandesWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::CommandesWidget)
    , comboMateriau(nullptr)
    , labelPrixPrediction(nullptr)
    , updatingPredictedPrice(false)
{
    ui->setupUi(this);

    setupPredictionUi();
    remplirMateriaux();

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
    updatePricePrediction();
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
    chargerTable(std::move(query));
}

void CommandesWidget::chargerTable(QSqlQuery query)
{
    ui->tableCommandes->setRowCount(0);
    int row = 0;
    while (query.next()) {
        const QString detailsWithTag = query.value("DETAILS_COMMANDE").toString();
        const QString material = extractMaterialTag(detailsWithTag);

        ui->tableCommandes->insertRow(row);
        ui->tableCommandes->setItem(row, 0, new QTableWidgetItem(query.value("ID_COMMANDE").toString()));
        ui->tableCommandes->setItem(row, 1, new QTableWidgetItem(query.value("DATE_COMMANDE").toString()));
        ui->tableCommandes->setItem(row, 2, new QTableWidgetItem(stripMaterialTag(detailsWithTag)));
        ui->tableCommandes->setItem(row, 3, new QTableWidgetItem(query.value("DIMENSIONS").toString()));
        ui->tableCommandes->setItem(row, 4, new QTableWidgetItem(query.value("PRIX").toString()));
        ui->tableCommandes->setItem(row, 5, new QTableWidgetItem(query.value("ETAT").toString()));
        ui->tableCommandes->setItem(row, 6, new QTableWidgetItem(material.isEmpty() ? "-" : material));
        row++;
    }
}

void CommandesWidget::chargerResultats(QSqlQuery query)
{
    ui->tableResultats->setRowCount(0);
    int row = 0;
    while (query.next()) {
        const QString detailsWithTag = query.value("DETAILS_COMMANDE").toString();
        const QString material = extractMaterialTag(detailsWithTag);

        ui->tableResultats->insertRow(row);
        ui->tableResultats->setItem(row, 0, new QTableWidgetItem(query.value("ID_COMMANDE").toString()));
        ui->tableResultats->setItem(row, 1, new QTableWidgetItem(query.value("DATE_COMMANDE").toString()));
        ui->tableResultats->setItem(row, 2, new QTableWidgetItem(stripMaterialTag(detailsWithTag)));
        ui->tableResultats->setItem(row, 3, new QTableWidgetItem(query.value("PRIX").toString()));
        ui->tableResultats->setItem(row, 4, new QTableWidgetItem(query.value("ETAT").toString()));
        ui->tableResultats->setItem(row, 5, new QTableWidgetItem(material.isEmpty() ? "-" : material));
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
    c.details = composeDetailsWithMaterial();
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
    c.details = composeDetailsWithMaterial();
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
    chargerResultats(std::move(query));
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
    if (comboMateriau) {
        html += "<p><b>Matériau :</b> " + comboMateriau->currentText() + "</p>";
    }
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
    if (comboMateriau) {
        comboMateriau->setCurrentText(ui->tableCommandes->item(row, 6)->text());
    }
    updatePricePrediction();
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
    if (comboMateriau) {
        comboMateriau->setCurrentIndex(0);
    }
    updatePricePrediction();
}

void CommandesWidget::remplirComboFacture()
{
    ui->comboFactureCommande->clear();
    QSqlQuery query = Commande::getAll("DATE_COMMANDE DESC");
    while (query.next()) {
        ui->comboFactureCommande->addItem(
            query.value("ID_COMMANDE").toString() + " - " + stripMaterialTag(query.value("DETAILS_COMMANDE").toString())
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

void CommandesWidget::setupPredictionUi()
{
    auto *grid = qobject_cast<QGridLayout*>(ui->groupBoxForm->layout());
    if (!grid) {
        return;
    }

    auto *labelMateriau = new QLabel("Matériau:", this);
    comboMateriau = new QComboBox(this);
    comboMateriau->setEditable(false);

    labelPrixPrediction = new QLabel("Prix prédit: € 0.00", this);

    grid->addWidget(labelMateriau, 7, 0);
    grid->addWidget(comboMateriau, 7, 1);
    grid->addWidget(labelPrixPrediction, 8, 0, 1, 2);

    connect(comboMateriau, &QComboBox::currentTextChanged, this, [this]() { updatePricePrediction(); });
    connect(ui->spinLongueur, qOverload<int>(&QSpinBox::valueChanged), this, [this]() { updatePricePrediction(); });
    connect(ui->spinLargeur, qOverload<int>(&QSpinBox::valueChanged), this, [this]() { updatePricePrediction(); });
    connect(ui->spinHauteur, qOverload<int>(&QSpinBox::valueChanged), this, [this]() { updatePricePrediction(); });
    connect(ui->txtDetails, &QTextEdit::textChanged, this, [this]() { updatePricePrediction(); });
    connect(ui->spinPrix, qOverload<double>(&QDoubleSpinBox::valueChanged), this, [this](double) {
        if (!updatingPredictedPrice) {
            updatePricePrediction();
        }
    });
}

void CommandesWidget::remplirMateriaux()
{
    if (!comboMateriau) {
        return;
    }

    comboMateriau->clear();
    comboMateriau->addItem("Standard");

    QSqlQuery q;
    q.prepare("SELECT DISTINCT TYPE FROM ATELIER.MATERIAU WHERE TYPE IS NOT NULL ORDER BY TYPE");
    if (q.exec()) {
        while (q.next()) {
            const QString type = q.value(0).toString().trimmed();
            if (!type.isEmpty()) {
                comboMateriau->addItem(type);
            }
        }
    }
}

double CommandesWidget::predictPrixCommande() const
{
    const double l = ui->spinLongueur->value();
    const double w = ui->spinLargeur->value();
    const double h = ui->spinHauteur->value();
    const double volumeCm3 = l * w * h;
    if (volumeCm3 <= 0.0) {
        return 0.0;
    }

    QSqlQuery q;
    q.prepare("SELECT DIMENSIONS, PRIX, DETAILS_COMMANDE FROM ATELIER.COMMANDE WHERE PRIX > 0");
    if (!q.exec()) {
        return 0.0;
    }

    const QString selectedMaterial = comboMateriau ? comboMateriau->currentText().trimmed().toLower() : QString();
    double sumUnit = 0.0;
    int count = 0;

    while (q.next()) {
        const QString dims = q.value(0).toString();
        const double prix = q.value(1).toDouble();
        if (prix <= 0.0) {
            continue;
        }

        QRegularExpressionMatch m = QRegularExpression("(\\d+)\\s*[x×]\\s*(\\d+)\\s*[x×]\\s*(\\d+)").match(dims);
        if (!m.hasMatch()) {
            continue;
        }

        const double dl = m.captured(1).toDouble();
        const double dw = m.captured(2).toDouble();
        const double dh = m.captured(3).toDouble();
        const double v = dl * dw * dh;
        if (v <= 0.0) {
            continue;
        }

        if (!selectedMaterial.isEmpty() && selectedMaterial != "standard") {
            const QString material = extractMaterialTag(q.value(2).toString()).trimmed().toLower();
            if (!material.isEmpty() && material != selectedMaterial) {
                continue;
            }
        }

        sumUnit += (prix / v);
        ++count;
    }

    if (count == 0) {
        QSqlQuery qall;
        qall.prepare("SELECT AVG(PRIX) FROM ATELIER.COMMANDE WHERE PRIX > 0");
        if (qall.exec() && qall.next()) {
            const double avgPrix = qall.value(0).toDouble();
            return avgPrix > 0.0 ? avgPrix : 0.0;
        }
        return 0.0;
    }

    double predicted = (sumUnit / static_cast<double>(count)) * volumeCm3;

    if (comboMateriau && comboMateriau->currentText().trimmed().toLower() != "standard") {
        QSqlQuery qMat;
        qMat.prepare("SELECT AVG(PRIX_ACHAT) FROM ATELIER.MATERIAU WHERE LOWER(TYPE)=:t");
        qMat.bindValue(":t", comboMateriau->currentText().trimmed().toLower());

        QSqlQuery qAll;
        qAll.prepare("SELECT AVG(PRIX_ACHAT) FROM ATELIER.MATERIAU WHERE PRIX_ACHAT > 0");

        if (qMat.exec() && qMat.next() && qAll.exec() && qAll.next()) {
            const double matAvg = qMat.value(0).toDouble();
            const double allAvg = qAll.value(0).toDouble();
            if (matAvg > 0.0 && allAvg > 0.0) {
                double coeff = matAvg / allAvg;
                if (coeff < 0.7) coeff = 0.7;
                if (coeff > 1.6) coeff = 1.6;
                predicted *= coeff;
            }
        }
    }

    const QString detailsLower = ui->txtDetails->toPlainText().toLower();
    if (detailsLower.contains("sculpt") || detailsLower.contains("sur mesure") || detailsLower.contains("luxe")) {
        predicted *= 1.15;
    }

    if (predicted < 50.0) {
        predicted = 50.0;
    }
    return predicted;
}

void CommandesWidget::updatePricePrediction()
{
    const double predicted = predictPrixCommande();
    if (labelPrixPrediction) {
        labelPrixPrediction->setText(QString("Prix prédit: € %1").arg(QString::number(predicted, 'f', 2)));
    }

    if (predicted <= 0.0) {
        return;
    }

    updatingPredictedPrice = true;
    {
        QSignalBlocker blocker(ui->spinPrix);
        ui->spinPrix->setValue(predicted);
    }
    updatingPredictedPrice = false;
}

QString CommandesWidget::extractMaterialTag(const QString &details)
{
    const QRegularExpression re("\\[MATIERE:([^\\]]+)\\]", QRegularExpression::CaseInsensitiveOption);
    const QRegularExpressionMatch m = re.match(details);
    return m.hasMatch() ? m.captured(1).trimmed() : QString();
}

QString CommandesWidget::stripMaterialTag(const QString &details)
{
    QString d = details;
    d.remove(QRegularExpression("^\\s*\\[MATIERE:[^\\]]+\\]\\s*", QRegularExpression::CaseInsensitiveOption));
    return d.trimmed();
}

QString CommandesWidget::composeDetailsWithMaterial() const
{
    const QString base = ui->txtDetails->toPlainText().trimmed();
    const QString material = comboMateriau ? comboMateriau->currentText().trimmed() : QString();
    if (material.isEmpty() || material.toLower() == "standard") {
        return base;
    }
    return QString("[MATIERE:%1] %2").arg(material, base);
}
