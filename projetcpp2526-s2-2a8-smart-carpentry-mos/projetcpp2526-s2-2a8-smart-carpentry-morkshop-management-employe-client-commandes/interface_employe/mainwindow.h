#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QButtonGroup>
#include <QStackedWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
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

    // Module widgets
    QWidget *clientsWidget;
    QWidget *commandesWidget;
    QWidget *stockWidget;
    QWidget *atelierWidget;
};
#endif // MAINWINDOW_H
