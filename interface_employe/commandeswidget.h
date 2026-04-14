#ifndef COMMANDESWIDGET_H
#define COMMANDESWIDGET_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class CommandesWidget;
}

class CommandesWidget : public QWidget
{
    Q_OBJECT

public:
    explicit CommandesWidget(QWidget *parent = nullptr);
    ~CommandesWidget();

private slots:
    void onAjouter();
    void onModifier();
    void onSupprimer();
    void onVider();
    void onTriPrixCroissant();
    void onTriPrixDecroissant();
    void onTableClicked(int row, int column);
    void onRechercher();
    void onResetRecherche();
    void onGenererStats();
    void onGenererPDF();

private:
    Ui::CommandesWidget *ui;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(const QSqlQuery &query);
    void remplirFormulaireDepuisTable(int row);
    void clearForm();
    QString buildDimensions() const;
    void parseDimensions(const QString &dims);
    void remplirComboFacture();
    void updateAlertes();
    void chargerResponsables();
    void chargerResultats(const QSqlQuery &query);
};

#endif // COMMANDESWIDGET_H
