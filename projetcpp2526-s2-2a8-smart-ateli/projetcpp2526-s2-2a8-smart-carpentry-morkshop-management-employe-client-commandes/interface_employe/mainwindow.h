#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui {
    class MainWindow;
    class HomeWidget;
    class ClientsWidget;
    class CommandesWidget;
    class StockWidget;
    class AtelierWidget;
}
QT_END_NAMESPACE

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

    // Home widget
    QWidget *homeWidget;
    Ui::HomeWidget *homeUi;

    // Module widgets
    QWidget *clientsWidget;
    QWidget *commandesWidget;
    QWidget *stockWidget;
    QWidget *atelierWidget;

    // UI objects for module widgets
    Ui::ClientsWidget *clientsUi;
    Ui::CommandesWidget *commandesUi;
    Ui::StockWidget *stockUi;
    Ui::AtelierWidget *atelierUi;
};

#endif // MAINWINDOW_H
