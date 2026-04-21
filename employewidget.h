#ifndef EMPLOYEWIDGET_H
#define EMPLOYEWIDGET_H

#include <QWidget>
#include <QSqlQuery>
#include <QDate>

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
    void onValider();
    void onConfirmerModification();
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

    // ✅ nouveaux
    void onRenvoyerCode();
    void onActualiserAbsences();
    void onExportAbsencesPDF();
    void onAbsenceDoubleClicked(int row, int column);

private:
    Ui::EmployeWidget *ui;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(QSqlQuery query);
    void remplirFormulaireDepuisTable(int row);
    void clearForm();

    bool validateForm(QStringList &errors, const QString &excludeId = QString()) const;
    bool cinExists(const QString &cin, const QString &excludeId = QString()) const;
    bool emailExists(const QString &email, const QString &excludeId = QString()) const;

    void chargerAbsences();
    bool envoyerCodeAcces(const QString& email, const QString& nom, const QString& code);
    bool updateJustificationAbsence(const QString& idAbsence, const QString& justif);

    QString currentEditId;

    QString origCin;
    QString origNom;
    QString origPoste;
    double  origSalaire = 0.0;
    QString origDispo;
    QString origTel;
    QString origEmail;
    QDate   origDate;
    QString origAdresse;

    bool hasChanges() const;
};

#endif // EMPLOYEWIDGET_H
