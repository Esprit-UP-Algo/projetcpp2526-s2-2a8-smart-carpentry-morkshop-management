#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include "connection.h"

namespace Ui {
class StockWidget;
}

class StockWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StockWidget(QWidget *parent = nullptr);
    ~StockWidget();

private slots:
    void onAjouter();
    void onModifier();
    void onSupprimer();
    void onNouveau();
    void onRechercher();
    void onActualiserStats();
    void onTableClicked(int row, int column);
    void onGenererReappro();
    void onPrevision();
    void onExportPDF();
    void onExportCSV();
    void onExportExcel();

private:
    Ui::StockWidget *ui;
    Connection m_connection;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(QSqlQuery query);
    void remplirFormulaireDepuisTable(const QString &id);
    void clearForm();
    void remplirStats();
    void exporterCSV(const QString &fileName);
    void assurerColonneIdCachee();
    bool ensureDbOpen();
};

#endif // STOCKWIDGET_H
