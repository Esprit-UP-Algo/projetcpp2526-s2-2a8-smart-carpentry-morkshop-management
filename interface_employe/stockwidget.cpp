#include "stockwidget.h"
#include "ui_StockWidget.h"
#include "stock.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QFileDialog>
#include <QTextStream>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlDatabase>
#include <QSqlDriver>
#include <QDate>
#include <QRandomGenerator>
#include <utility>

StockWidget::StockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockWidget)
{
    ui->setupUi(this);

    if (!m_connection.createconnect()) {
        QMessageBox::critical(this, "DB", "Connexion à la base impossible.");
    }

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableStats->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableReappro->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablePrevision->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // ✅ Connexions uniques (pas d'auto-connect)
    connect(ui->btnAjouter, &QPushButton::clicked, this, &StockWidget::onAjouter);
    connect(ui->btnModifier, &QPushButton::clicked, this, &StockWidget::onModifier);
    connect(ui->btnDelete, &QPushButton::clicked, this, &StockWidget::onSupprimer);
    connect(ui->btnNouveau, &QPushButton::clicked, this, &StockWidget::onNouveau);
    connect(ui->btnRechercher, &QPushButton::clicked, this, &StockWidget::onRechercher);
    connect(ui->btnActualiserStats, &QPushButton::clicked, this, &StockWidget::onActualiserStats);
    connect(ui->btnGenererReappro, &QPushButton::clicked, this, &StockWidget::onGenererReappro);
    connect(ui->btnPrevision, &QPushButton::clicked, this, &StockWidget::onPrevision);
    connect(ui->btnExportPDF, &QPushButton::clicked, this, &StockWidget::onExportPDF);
    connect(ui->btnExportCSV, &QPushButton::clicked, this, &StockWidget::onExportCSV);
    connect(ui->btnExportExcel, &QPushButton::clicked, this, &StockWidget::onExportExcel);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &StockWidget::onTableClicked);

    assurerColonneIdCachee();
    chargerTable();
    remplirStats();
}

StockWidget::~StockWidget()
{
    delete ui;
}

bool StockWidget::ensureDbOpen()
{
    QSqlDatabase db = QSqlDatabase::database();
    if (db.isOpen()) return true;

    if (!m_connection.createconnect()) {
        QMessageBox::critical(this, "DB", "Connexion DB fermée et réouverture impossible.");
        return false;
    }
    return true;
}

void StockWidget::assurerColonneIdCachee()
{
    if (ui->tableWidget->columnCount() == 4) {
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("ID"));
    }
    ui->tableWidget->setColumnHidden(0, true);
}

void StockWidget::chargerTable(const QString &orderBy)
{
    QSqlQuery query = Stock::getAll(orderBy);
    chargerTable(std::move(query));
}

void StockWidget::chargerTable(QSqlQuery query)
{
    assurerColonneIdCachee();

    ui->tableWidget->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(query.value("ID_MATERIAU").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(query.value("QUANTITE").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(query.value("PRIX_ACHAT").toString()));
        row++;
    }
}

void StockWidget::onAjouter()
{
    if (!ensureDbOpen()) return;

    Stock s;
    s.nom = ui->txtNom->text().trimmed();
    s.type = ui->comboType->currentText();
    s.quantite = ui->spinQuantite->value();
    s.prixAchat = ui->spinPrixAchat->value();

    if (s.nom.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Le nom du matériau est obligatoire.");
        return;
    }

    if (s.ajouter()) {
        QMessageBox::information(this, "Succès", "Matériau ajouté.");
        chargerTable();
        remplirStats();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur SQL", Stock::lastError());
    }
}

void StockWidget::onModifier()
{
    if (!ensureDbOpen()) return;

    const QString id = ui->tableWidget->currentItem()
        ? ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text()
        : "";

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionne un matériau.");
        return;
    }

    Stock s;
    s.idMateriau = id;
    s.nom = ui->txtNom->text().trimmed();
    s.type = ui->comboType->currentText();
    s.quantite = ui->spinQuantite->value();
    s.prixAchat = ui->spinPrixAchat->value();

    if (s.modifier()) {
        QMessageBox::information(this, "Succès", "Matériau modifié.");
        chargerTable();
        remplirStats();
    } else {
        QMessageBox::warning(this, "Erreur SQL", Stock::lastError());
    }
}

void StockWidget::onSupprimer()
{
    if (!ensureDbOpen()) return;

    const QString id = ui->tableWidget->currentItem()
        ? ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text()
        : "";

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Sélectionne un matériau.");
        return;
    }

    if (Stock::supprimer(id)) {
        QMessageBox::information(this, "Succès", "Matériau supprimé.");
        chargerTable();
        remplirStats();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur SQL", Stock::lastError());
    }
}

void StockWidget::onNouveau() { clearForm(); }

void StockWidget::onRechercher()
{
    const QString term = ui->txtRecherche->text().trimmed();
    const QString typeFiltre = ui->comboFiltreType->currentText();

    if (term.isEmpty() && (typeFiltre.isEmpty() || typeFiltre == "Tous les types")) {
        chargerTable();
        return;
    }
    chargerTable(Stock::rechercher(term, typeFiltre));
}

void StockWidget::onTableClicked(int row, int)
{
    const QString id = ui->tableWidget->item(row, 0)->text();
    remplirFormulaireDepuisTable(id);
}

void StockWidget::remplirFormulaireDepuisTable(const QString &id)
{
    QSqlQuery query;
    query.prepare("SELECT * FROM ATELIER.MATERIAU WHERE ID_MATERIAU = :id");
    query.bindValue(":id", id.toInt());
    query.exec();
    if (query.next()) {
        ui->txtNom->setText(query.value("NOM").toString());
        ui->comboType->setCurrentText(query.value("TYPE").toString());
        ui->spinQuantite->setValue(query.value("QUANTITE").toDouble());
        ui->spinPrixAchat->setValue(query.value("PRIX_ACHAT").toDouble());
    }
}

void StockWidget::onActualiserStats() { remplirStats(); }

void StockWidget::onGenererReappro()
{
    if (!ensureDbOpen()) return;

    bool hasSeuilAlerte = false;
    {
        QSqlQuery qCol;
        qCol.prepare(
            "SELECT COUNT(*) "
            "FROM ALL_TAB_COLUMNS "
            "WHERE UPPER(OWNER)='ATELIER' AND UPPER(TABLE_NAME)='MATERIAU' AND UPPER(COLUMN_NAME)='SEUIL_ALERTE'"
        );
        if (qCol.exec() && qCol.next()) {
            hasSeuilAlerte = qCol.value(0).toInt() > 0;
        }
    }

    QSqlQuery query;
    if (hasSeuilAlerte) {
        query.prepare(
            "SELECT ID_MATERIAU, NOM, TYPE, QUANTITE, NVL(SEUIL_ALERTE, 0) AS SEUIL "
            "FROM ATELIER.MATERIAU "
            "ORDER BY QUANTITE ASC"
        );
    } else {
        query.prepare(
            "SELECT ID_MATERIAU, NOM, TYPE, QUANTITE, 0 AS SEUIL "
            "FROM ATELIER.MATERIAU "
            "ORDER BY QUANTITE ASC"
        );
    }

    if (!query.exec()) {
        QMessageBox::warning(this, "Réapprovisionnement", "Impossible de générer les propositions.");
        return;
    }

    ui->tableReappro->setRowCount(0);
    ui->tableReappro->setColumnCount(4);
    ui->tableReappro->setHorizontalHeaderLabels({"Matériau", "Stock Actuel", "Quantité Recommandée", "Priorité"});

    int row = 0;
    while (query.next()) {
        const QString type = query.value("TYPE").toString();
        const double stockActuel = query.value("QUANTITE").toDouble();
        double seuil = query.value("SEUIL").toDouble();

        if (seuil <= 0.0) {
            QSqlQuery qAvg;
            qAvg.prepare("SELECT NVL(AVG(QUANTITE), 0) FROM ATELIER.MATERIAU WHERE TYPE = :t");
            qAvg.bindValue(":t", type);
            if (qAvg.exec() && qAvg.next()) {
                const double avgType = qAvg.value(0).toDouble();
                seuil = qMax(5.0, avgType * 0.30);
            } else {
                seuil = 10.0;
            }
        }

        if (stockActuel >= seuil * 2.0) {
            continue;
        }

        double recommandation = 0.0;
        QString priorite;
        if (stockActuel < seuil) {
            recommandation = qMax(seuil * 3.0 - stockActuel, seuil);
            priorite = "CRITIQUE";
        } else {
            recommandation = qMax(seuil * 2.0 - stockActuel, seuil * 0.5);
            priorite = "MOYENNE";
        }

        ui->tableReappro->insertRow(row);
        ui->tableReappro->setItem(row, 0, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableReappro->setItem(row, 1, new QTableWidgetItem(QString::number(stockActuel, 'f', 2)));
        ui->tableReappro->setItem(row, 2, new QTableWidgetItem(QString::number(recommandation, 'f', 2)));
        ui->tableReappro->setItem(row, 3, new QTableWidgetItem(priorite));
        ++row;
    }

    ui->tableReappro->resizeColumnsToContents();

    if (row == 0) {
        QMessageBox::information(this, "Réapprovisionnement", "Aucune alerte: stock confortable pour tous les matériaux.");
    } else {
        QMessageBox::information(this, "Réapprovisionnement", QString("%1 matériau(x) à réapprovisionner.").arg(row));
    }
}

void StockWidget::onPrevision()
{
    if (!ensureDbOpen()) return;

    const int nbCommandes = ui->spinNbCommandes->value();
    const int periode = ui->spinPeriode->value();

    QSqlQuery qMateriaux;
    qMateriaux.prepare("SELECT NOM, TYPE, QUANTITE FROM ATELIER.MATERIAU ORDER BY TYPE, NOM");
    if (!qMateriaux.exec()) {
        QMessageBox::warning(this, "Prévision", "Impossible de charger les matériaux.");
        return;
    }

    QSqlQuery qRecent;
    qRecent.prepare(
        "SELECT COUNT(*) "
        "FROM ATELIER.COMMANDE "
        "WHERE DATE_COMMANDE >= TRUNC(SYSDATE) - 30"
    );
    int recentOrders = 0;
    if (qRecent.exec() && qRecent.next()) {
        recentOrders = qRecent.value(0).toInt();
    }
    const double orderFactor = (recentOrders > 0) ? (static_cast<double>(nbCommandes) / recentOrders) : 1.0;

    ui->tablePrevision->setRowCount(0);
    ui->tablePrevision->setColumnCount(5);
    ui->tablePrevision->setHorizontalHeaderLabels({"Matériau", "Conso moyenne", "Conso prévue", "Stock actuel", "Stock suffisant?"});

    int row = 0;
    while (qMateriaux.next()) {
        const QString nom = qMateriaux.value("NOM").toString();
        const QString type = qMateriaux.value("TYPE").toString();
        const double stockActuel = qMateriaux.value("QUANTITE").toDouble();

        // If command details contain [MATIERE:TYPE], this gives a realistic history-based rate.
        QSqlQuery qTypeOrders;
        qTypeOrders.prepare(
            "SELECT COUNT(*) "
            "FROM ATELIER.COMMANDE "
            "WHERE UPPER(DETAILS_COMMANDE) LIKE UPPER(:m)"
        );
        qTypeOrders.bindValue(":m", "%[MATIERE:" + type + "]%");

        int materialOrders = 0;
        if (qTypeOrders.exec() && qTypeOrders.next()) {
            materialOrders = qTypeOrders.value(0).toInt();
        }

        double consoMoyenne = qMax(1.0, 2.0 + materialOrders * 0.3);
        if (materialOrders == 0) {
            consoMoyenne = 3.0 + QRandomGenerator::global()->bounded(3.0);
        }

        const double consoPrevue = consoMoyenne * orderFactor * (static_cast<double>(periode) / 30.0);
        QString suffisant;
        if (stockActuel >= consoPrevue) {
            suffisant = "Oui";
        } else if (stockActuel <= 0.0) {
            suffisant = "CRITIQUE";
        } else {
            suffisant = "Non";
        }

        ui->tablePrevision->insertRow(row);
        ui->tablePrevision->setItem(row, 0, new QTableWidgetItem(nom));
        ui->tablePrevision->setItem(row, 1, new QTableWidgetItem(QString::number(consoMoyenne, 'f', 2)));
        ui->tablePrevision->setItem(row, 2, new QTableWidgetItem(QString::number(consoPrevue, 'f', 2)));
        ui->tablePrevision->setItem(row, 3, new QTableWidgetItem(QString::number(stockActuel, 'f', 2)));
        ui->tablePrevision->setItem(row, 4, new QTableWidgetItem(suffisant));
        ++row;
    }

    ui->tablePrevision->resizeColumnsToContents();
}

void StockWidget::onExportPDF()
{
    const QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF", "rapport_stock.pdf", "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QTextDocument doc;
    QString html;
    html += "<h2>Rapport de stock</h2>";
    html += QString("<p>Date: %1</p>").arg(QDate::currentDate().toString("yyyy-MM-dd"));
    html += "<h3>Stock actuel</h3><table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>Nom</th><th>Type</th><th>Quantité</th><th>Prix achat</th></tr>";

    for (int r = 0; r < ui->tableWidget->rowCount(); ++r) {
        html += "<tr>";
        for (int c = 1; c <= 4; ++c) {
            const auto *item = ui->tableWidget->item(r, c);
            html += "<td>" + (item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";

    doc.setHtml(html);
    QPrinter printer(QPrinter::HighResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    doc.print(&printer);

    QMessageBox::information(this, "Export PDF", "Rapport PDF généré avec succès.");
}

void StockWidget::onExportCSV()
{
    const QString fileName = QFileDialog::getSaveFileName(this, "Exporter CSV", "stock.csv", "CSV (*.csv)");
    if (fileName.isEmpty()) return;
    exporterCSV(fileName);
}

void StockWidget::onExportExcel()
{
    // Excel opens CSV files directly, which keeps export dependency-free.
    const QString fileName = QFileDialog::getSaveFileName(this, "Exporter Excel", "stock_excel.csv", "CSV (*.csv)");
    if (fileName.isEmpty()) return;
    exporterCSV(fileName);
}

void StockWidget::remplirStats()
{
    if (!ensureDbOpen()) return;

    QSqlQuery qTotal;
    qTotal.prepare("SELECT COUNT(*) FROM ATELIER.MATERIAU");
    if (qTotal.exec() && qTotal.next()) {
        ui->lblTotalMateriaux->setText(qTotal.value(0).toString());
    }

    QSqlQuery qTypes;
    qTypes.prepare("SELECT COUNT(DISTINCT TYPE) FROM ATELIER.MATERIAU");
    if (qTypes.exec() && qTypes.next()) {
        ui->lblTypesMateriaux->setText(qTypes.value(0).toString());
    }

    QSqlQuery qStats = Stock::statsParType();
    ui->tableStats->setRowCount(0);
    ui->tableStats->setColumnCount(4);
    ui->tableStats->setHorizontalHeaderLabels({"Type", "Nombre d'articles", "Quantité Totale", "Pourcentage"});

    struct RowData { QString type; int nb; double qte; };
    QList<RowData> rows;
    double totalQte = 0.0;

    while (qStats.next()) {
        RowData d{ qStats.value("TYPE").toString(), qStats.value("NB").toInt(), qStats.value("QTE").toDouble() };
        rows.append(d);
        totalQte += d.qte;
    }

    for (int i = 0; i < rows.size(); ++i) {
        ui->tableStats->insertRow(i);
        const double pct = (totalQte > 0.0) ? (rows[i].qte * 100.0 / totalQte) : 0.0;
        ui->tableStats->setItem(i, 0, new QTableWidgetItem(rows[i].type));
        ui->tableStats->setItem(i, 1, new QTableWidgetItem(QString::number(rows[i].nb)));
        ui->tableStats->setItem(i, 2, new QTableWidgetItem(QString::number(rows[i].qte, 'f', 2)));
        ui->tableStats->setItem(i, 3, new QTableWidgetItem(QString::number(pct, 'f', 1) + "%"));
    }

    ui->tableStats->resizeColumnsToContents();
}

void StockWidget::exporterCSV(const QString& fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::warning(this, "Export", "Impossible d'écrire le fichier.");
        return;
    }

    QTextStream out(&file);
    out.setEncoding(QStringConverter::Utf8);
    out << "Nom;Type;Quantite;Prix_Achat\n";

    for (int r = 0; r < ui->tableWidget->rowCount(); ++r) {
        const QString nom = ui->tableWidget->item(r, 1) ? ui->tableWidget->item(r, 1)->text() : "";
        const QString type = ui->tableWidget->item(r, 2) ? ui->tableWidget->item(r, 2)->text() : "";
        const QString qte = ui->tableWidget->item(r, 3) ? ui->tableWidget->item(r, 3)->text() : "";
        const QString prix = ui->tableWidget->item(r, 4) ? ui->tableWidget->item(r, 4)->text() : "";
        out << nom << ';' << type << ';' << qte << ';' << prix << "\n";
    }

    file.close();
    QMessageBox::information(this, "Export", "Export terminé: " + fileName);
}

void StockWidget::clearForm()
{
    ui->txtNom->clear();
    ui->comboType->setCurrentIndex(0);
    ui->spinQuantite->setValue(0);
    ui->spinPrixAchat->setValue(0);
}
