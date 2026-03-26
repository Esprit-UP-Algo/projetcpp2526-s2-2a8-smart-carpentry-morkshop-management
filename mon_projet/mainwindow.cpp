#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , clientsWidget(new ClientsWidget(this))
{
    ui->setupUi(this);
    ui->contentLayout->addWidget(clientsWidget);
}

MainWindow::~MainWindow()
{
    delete ui;
}
