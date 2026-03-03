#ifndef EMPLOYEWIDGET_H
#define EMPLOYEWIDGET_H

#include <QWidget>

namespace Ui {
class EmployeWidget;
}

class EmployeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmployeWidget(QWidget *parent = nullptr);
    ~EmployeWidget();

private slots:
    void onAjouter();
    void onModifier();
    void onSupprimer();
    void onVider();
    void onRechercher();
    void onAfficherTout();
    void onTrier();
    void onTableClicked(int row, int column);
    void onRechercheTexteChanged(const QString &text);
    void onExportPDF();
    void onActualiserStats();

private:
    Ui::EmployeWidget *ui;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(QSqlQuery query);
    void remplirFormulaireDepuisTable(int row);
    void clearForm();
};

#endif // EMPLOYEWIDGET_H
