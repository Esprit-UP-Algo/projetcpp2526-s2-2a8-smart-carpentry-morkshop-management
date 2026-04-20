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

StockWidget::StockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockWidget)
{
    ui->setupUi(this);

    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableStats->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tableReappro->setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui->tablePrevision->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->btnAjouter,        &QPushButton::clicked, this, &StockWidget::onAjouter);
    connect(ui->btnModifier,       &QPushButton::clicked, this, &StockWidget::onModifier);
    connect(ui->btnDelete,         &QPushButton::clicked, this, &StockWidget::onSupprimer);
    connect(ui->btnNouveau,        &QPushButton::clicked, this, &StockWidget::onNouveau);
    connect(ui->btnRechercher,     &QPushButton::clicked, this, &StockWidget::onRechercher);
    connect(ui->btnActualiserStats,&QPushButton::clicked, this, &StockWidget::onActualiserStats);
    connect(ui->btnGenererReappro, &QPushButton::clicked, this, &StockWidget::onGenererReappro);
    connect(ui->btnPrevision,      &QPushButton::clicked, this, &StockWidget::onPrevision);
    connect(ui->btnExportPDF,      &QPushButton::clicked, this, &StockWidget::onExportPDF);
    connect(ui->btnExportCSV,      &QPushButton::clicked, this, &StockWidget::onExportCSV);
    connect(ui->btnExportExcel,    &QPushButton::clicked, this, &StockWidget::onExportExcel);
    connect(ui->tableWidget, &QTableWidget::cellClicked, this, &StockWidget::onTableClicked);

    assurerColonneIdCachee();
    chargerTable();
    remplirStats();
}

StockWidget::~StockWidget() { delete ui; }

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
    chargerTable(Stock::getAll(orderBy));
}

void StockWidget::chargerTable(const QSqlQuery &query)
{
    assurerColonneIdCachee();
    ui->tableWidget->setRowCount(0);
    int row = 0;
    QSqlQuery q = query;
    while (q.next()) {
        ui->tableWidget->insertRow(row);
        ui->tableWidget->setItem(row, 0, new QTableWidgetItem(q.value("ID_MATERIAU").toString()));
        ui->tableWidget->setItem(row, 1, new QTableWidgetItem(q.value("NOM").toString()));
        ui->tableWidget->setItem(row, 2, new QTableWidgetItem(q.value("TYPE").toString()));
        ui->tableWidget->setItem(row, 3, new QTableWidgetItem(q.value("QUANTITE").toString()));
        ui->tableWidget->setItem(row, 4, new QTableWidgetItem(q.value("PRIX_ACHAT").toString()));
        row++;
    }
}

void StockWidget::onAjouter()
{
    if (!ensureDbOpen()) return;
    Stock s;
    s.nom      = ui->txtNom->text().trimmed();
    s.type     = ui->comboType->currentText();
    s.quantite = ui->spinQuantite->value();
    s.prixAchat= ui->spinPrixAchat->value();
    if (s.nom.isEmpty()) { QMessageBox::warning(this, "Erreur", "Nom obligatoire."); return; }
    if (s.ajouter()) { QMessageBox::information(this, "Succès", "Matériau ajouté."); chargerTable(); remplirStats(); clearForm(); }
    else QMessageBox::warning(this, "Erreur SQL", Stock::lastError());
}

void StockWidget::onModifier()
{
    if (!ensureDbOpen()) return;
    const QString id = ui->tableWidget->currentItem() ? ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text() : "";
    if (id.isEmpty()) { QMessageBox::warning(this, "Erreur", "Sélectionne un matériau."); return; }
    Stock s;
    s.idMateriau = id;
    s.nom      = ui->txtNom->text().trimmed();
    s.type     = ui->comboType->currentText();
    s.quantite = ui->spinQuantite->value();
    s.prixAchat= ui->spinPrixAchat->value();
    if (s.modifier()) { QMessageBox::information(this, "Succès", "Matériau modifié."); chargerTable(); remplirStats(); }
    else QMessageBox::warning(this, "Erreur SQL", Stock::lastError());
}

void StockWidget::onSupprimer()
{
    if (!ensureDbOpen()) return;
    const QString id = ui->tableWidget->currentItem() ? ui->tableWidget->item(ui->tableWidget->currentRow(), 0)->text() : "";
    if (id.isEmpty()) { QMessageBox::warning(this, "Erreur", "Sélectionne un matériau."); return; }
    if (Stock::supprimer(id)) { QMessageBox::information(this, "Succès", "Matériau supprimé."); chargerTable(); remplirStats(); clearForm(); }
    else QMessageBox::warning(this, "Erreur SQL", Stock::lastError());
}

void StockWidget::onNouveau() { clearForm(); }

void StockWidget::onRechercher()
{
    const QString term = ui->txtRecherche->text().trimmed();
    const QString typeFiltre = ui->comboFiltreType->currentText();
    if (term.isEmpty() && (typeFiltre.isEmpty() || typeFiltre == "Tous les types")) { chargerTable(); return; }
    chargerTable(Stock::rechercher(term, typeFiltre));
}

void StockWidget::onTableClicked(int row, int)
{
    remplirFormulaireDepuisTable(ui->tableWidget->item(row, 0)->text());
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
void StockWidget::onGenererReappro() {}
void StockWidget::onPrevision() {}
void StockWidget::onExportPDF() {}
void StockWidget::onExportCSV() {}
void StockWidget::onExportExcel() {}
void StockWidget::remplirStats() {}
void StockWidget::exporterCSV(const QString&) {}

void StockWidget::clearForm()
{
    ui->txtNom->clear();
    ui->comboType->setCurrentIndex(0);
    ui->spinQuantite->setValue(0);
    ui->spinPrixAchat->setValue(0);
}
