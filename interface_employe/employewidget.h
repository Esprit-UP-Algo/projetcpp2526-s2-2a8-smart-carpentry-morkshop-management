#ifndef EMPLOYEWIDGET_H
#define EMPLOYEWIDGET_H

#include <QWidget>
#include <QSqlQuery>

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
    void onTableClicked(int row, int col);
    void onExportPDF();
    void onActualiserStats();

private:
    Ui::EmployeWidget *ui;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(QSqlQuery query);
    void remplirFormulaireDepuisTable(const QString &id);
    void clearForm();
};

#endif // EMPLOYEWIDGET_H
