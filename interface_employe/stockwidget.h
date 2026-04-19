#ifndef STOCKWIDGET_H
#define STOCKWIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include <QMessageBox>
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
    void onTrierParQuantite();

private:
    Ui::StockWidget *ui;
    Connection m_connection;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(const QSqlQuery &query);
    void remplirFormulaireDepuisTable(const QString &id);
    void clearForm();
    void remplirStats();
    void assurerColonneIdCachee();
    bool ensureDbOpen();
    void verifierAlertesStock();  // Nouvelle fonction pour vérifier les alertes
    void afficherNotification(const QString &message, const QString &couleur = "#2ecc71");
};

#endif // STOCKWIDGET_H