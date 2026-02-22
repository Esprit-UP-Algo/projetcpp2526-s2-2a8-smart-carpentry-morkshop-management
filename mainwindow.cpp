#include "mainwindow.h"
<<<<<<< HEAD
#include "ui_mainwindow.h"
=======
#include "./ui_mainwindow.h"
>>>>>>> e303fc50f5cb6035c40509c672af40e2e0aa50fd

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}
<<<<<<< HEAD
=======

void MainWindow::on_btnRechercher_clicked()
{

}


void MainWindow::on_btnAjouter_clicked()
{

}

>>>>>>> e303fc50f5cb6035c40509c672af40e2e0aa50fd
