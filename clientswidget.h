#ifndef CLIENTSWIDGET_H
#define CLIENTSWIDGET_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class ClientsWidget;
}

class ClientsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientsWidget(QWidget *parent = nullptr);
    ~ClientsWidget();

private slots:
    void onAjouter();
    void onModifier();
    void onSupprimer();
    void onVider();
    void onRechercher();
    void onAfficherTout();
    void onTrier();
    void onTableClicked(int row, int column);
    void onExportPDF();
    void onActualiserStats();

private:
    Ui::ClientsWidget *ui;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(const QSqlQuery &query);
    void remplirFormulaireDepuisTable(const QString &id);
    void clearForm();
};

#endif // CLIENTSWIDGET_H
