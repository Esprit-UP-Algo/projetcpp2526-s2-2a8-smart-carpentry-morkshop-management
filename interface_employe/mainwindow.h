#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
    class HomeWidget;
}
QT_END_NAMESPACE

class AtelierWidget;
class EmployeWidget;
class CommandesWidget;
class ClientsWidget;
class StockWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QButtonGroup *navigationButtonGroup;
    QStackedWidget *stackedWidget;

    QWidget *homeWidget;
    Ui::HomeWidget *homeUi;

    EmployeWidget *employesWidget;
    ClientsWidget *clientsWidget;
    CommandesWidget *commandesWidget;
    StockWidget *stockWidget;      // ✅ vraie classe
    AtelierWidget *atelierWidget;

    QString currentRole;
    void applyRole(const QString &role);
};

#endif // MAINWINDOW_H
