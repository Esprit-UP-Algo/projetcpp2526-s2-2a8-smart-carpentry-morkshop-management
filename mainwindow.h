#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    // Slots pour les boutons de gestion
    void onBtnAjouterClicked();
    void onBtnModifierClicked();
    void onBtnSupprimerClicked();
    void onBtnExporterClicked();
    
    // Slots pour les filtres et tri
    void onBtnAppliquerTriClicked();
    void onBtnReinitialiserClicked();
    
    // Slots pour les statistiques avancées
    void onBtnPlanifierMaintenanceClicked();
    void onBtnDetecterCritiquesClicked();
    void onBtnAnalyserRisquesClicked();

private:
    Ui::MainWindow *ui;
    
    // Méthodes privées
    void connectSignals();
    void initialiserTableau();
    void chargerDonnees();
    void chargerMachinesCritiques();
    void chargerMachinesSollicitees();
    void appliquerTri();
    void detecterMachinesCritiques();
    void calculerNiveauRisque();
    void genererAlertes();
};
#endif // MAINWINDOW_H
