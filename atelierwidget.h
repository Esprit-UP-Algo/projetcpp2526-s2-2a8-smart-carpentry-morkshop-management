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

private:
    Ui::AtelierWidget *ui;

    void connectSignals();
    void initialiserTableau();
    void chargerDonnees();
    void chargerMachinesCritiques();
    void chargerMachinesSollicitees();
};

#endif // ATELIERWIDGET_H
