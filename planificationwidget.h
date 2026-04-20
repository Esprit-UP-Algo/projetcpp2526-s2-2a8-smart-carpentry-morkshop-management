#ifndef PLANIFICATIONWIDGET_H
#define PLANIFICATIONWIDGET_H

#include <QWidget>
#include <QDate>
#include <QComboBox>

namespace Ui { class PlanificationWidget; }

class PlanificationWidget : public QWidget
{
    Q_OBJECT
public:
    explicit PlanificationWidget(QWidget *parent = nullptr);
    ~PlanificationWidget();

private slots:
    void onAjouter();
    void onSupprimer();
    void onModifierStatut();
    void onFiltreChanged();
    void onTableClicked(int row, int col);

private:
    Ui::PlanificationWidget *ui;

    void chargerListeTaches();
    void remplirCombos();
    void clearFormulaire();
    QString couleurStatut(const QString &statut) const;
    QString iconePriorite(int priorite) const;
};

#endif // PLANIFICATIONWIDGET_H
