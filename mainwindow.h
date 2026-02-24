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
}
QT_END_NAMESPACE

class AtelierWidget;

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

    QWidget *clientsWidget;
    QWidget *commandesWidget;
    QWidget *stockWidget;
    AtelierWidget *atelierWidget;

    Ui::ClientsWidget *clientsUi;
    Ui::CommandesWidget *commandesUi;
    Ui::StockWidget *stockUi;
};

#endif // MAINWINDOW_H
