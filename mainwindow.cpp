#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_HomeWidget.h"
#include "ui_StockWidget.h"
#include "atelierwidget.h"
#include "employewidget.h"
#include "clientswidget.h"
#include "commandeswidget.h"

#include <QStackedWidget>
#include <QButtonGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    navigationButtonGroup = new QButtonGroup(this);
    navigationButtonGroup->setExclusive(true);
    navigationButtonGroup->addButton(ui->btnEmployes);
    navigationButtonGroup->addButton(ui->btnClients);
    navigationButtonGroup->addButton(ui->btnCommandes);
    navigationButtonGroup->addButton(ui->btnStock);
    navigationButtonGroup->addButton(ui->btnAtelier);

    stackedWidget = new QStackedWidget();

    homeWidget = new QWidget();
    homeUi = new Ui::HomeWidget();
    homeUi->setupUi(homeWidget);

    employesWidget = new EmployeWidget();
    clientsWidget = new ClientsWidget();
    commandesWidget = new CommandesWidget();

    stockWidget = new QWidget();
    stockUi = new Ui::StockWidget();
    stockUi->setupUi(stockWidget);

    atelierWidget = new AtelierWidget();

    stackedWidget->addWidget(homeWidget);      // 0
    stackedWidget->addWidget(employesWidget);  // 1
    stackedWidget->addWidget(clientsWidget);   // 2
    stackedWidget->addWidget(commandesWidget); // 3
    stackedWidget->addWidget(stockWidget);     // 4
    stackedWidget->addWidget(atelierWidget);   // 5

    ui->contentLayout->addWidget(stackedWidget);

    stackedWidget->setCurrentIndex(0);
    ui->sidebar->setVisible(false);

    connect(stackedWidget, &QStackedWidget::currentChanged, this, [this](int index) {
        ui->sidebar->setVisible(index != 0);
    });

    connect(homeUi->btnAccederModules, &QPushButton::clicked, this, [this](){
        stackedWidget->setCurrentIndex(1);
        ui->btnEmployes->setChecked(true);
    });

    connect(ui->btnEmployes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(1); });
    connect(ui->btnClients, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(2); });
    connect(ui->btnCommandes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(3); });
    connect(ui->btnStock, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(4); });
    connect(ui->btnAtelier, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(5); });
}

MainWindow::~MainWindow()
{
    delete homeUi;
    delete stockUi;
    delete atelierWidget;
    delete employesWidget;
    delete clientsWidget;
    delete commandesWidget;
    delete ui;
}
