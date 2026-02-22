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

<<<<<<< HEAD
=======
private slots:
    void on_btnRechercher_clicked();

    void on_btnAjouter_clicked();

>>>>>>> e303fc50f5cb6035c40509c672af40e2e0aa50fd
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
