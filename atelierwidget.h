#ifndef ATELIERWIDGET_H
#define ATELIERWIDGET_H

#include <QWidget>

namespace Ui {
class AtelierWidget;
}

class AtelierWidget : public QWidget
{
    Q_OBJECT

public:
    explicit AtelierWidget(QWidget *parent = nullptr);
    ~AtelierWidget();

private slots:
    void onBtnAjouterClicked();
    void onBtnModifierClicked();
    void onBtnSupprimerClicked();
    void onBtnExporterClicked();
    void onBtnAppliquerTriClicked();
    void onBtnReinitialiserClicked();
    void onBtnPlanifierMaintenanceClicked();
    void onBtnDetecterCritiquesClicked();
    void onBtnAnalyserRisquesClicked();
    void onCalendrierDateChanged();
    void onCalendrierPageChanged(int year, int month);
    void onPlanAjouter();
    void onPlanSupprimer();
    void onPlanModifierStatut();
    void onPlanFiltreChanged();
    void onBtnExportCSVMachinesClicked();

private:
    Ui::AtelierWidget *ui;

    void connectSignals();
    void initialiserTableau();
    void chargerDonnees();
    void chargerMachinesCritiques();
    void chargerMachinesSollicitees();
    void highlighterDatesCommandes();
    void planRemplirCombos();
    void planChargerTaches();
};

#endif // ATELIERWIDGET_H
