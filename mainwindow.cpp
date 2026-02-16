#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_ClientsWidget.h"
#include "ui_CommandesWidget.h"
#include "ui_StockWidget.h"
#include "ui_AtelierWidget.h"
#include <QStackedWidget>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Create button group for exclusive navigation buttons
    navigationButtonGroup = new QButtonGroup(this);
    navigationButtonGroup->setExclusive(true);
    navigationButtonGroup->addButton(ui->btnEmployes);
    navigationButtonGroup->addButton(ui->btnClients);
    navigationButtonGroup->addButton(ui->btnCommandes);
    navigationButtonGroup->addButton(ui->btnStock);
    navigationButtonGroup->addButton(ui->btnAtelier);

    // Create stacked widget to hold different module widgets
    stackedWidget = new QStackedWidget();

    // Get the current tab widget (Employés content)
    QWidget *employesWidget = ui->tabWidget;

    // Create Clients widget
    clientsWidget = new QWidget();
    Ui::ClientsWidget *clientsUi = new Ui::ClientsWidget();
    clientsUi->setupUi(clientsWidget);

    // Create placeholder widgets for other modules
    commandesWidget = new QWidget();
    Ui::CommandesWidget *commandesUi = new Ui::CommandesWidget();
    commandesUi->setupUi(commandesWidget);

    stockWidget = new QWidget();
    Ui::StockWidget *stockUi = new Ui::StockWidget();
    stockUi->setupUi(stockWidget);

    atelierWidget = new QWidget();
    Ui::AtelierWidget *atelierUi = new Ui::AtelierWidget();
    atelierUi->setupUi(atelierWidget);

    // Add all widgets to stacked widget
    stackedWidget->addWidget(employesWidget);     // Index 0
    stackedWidget->addWidget(clientsWidget);      // Index 1
    stackedWidget->addWidget(commandesWidget);    // Index 2
    stackedWidget->addWidget(stockWidget);        // Index 3
    stackedWidget->addWidget(atelierWidget);      // Index 4

    // Replace the tab widget in the main layout with the stacked widget
    QLayout *mainLayout = ui->centralwidget->layout();
    mainLayout->addWidget(stackedWidget);

    // Connect navigation buttons
    connect(ui->btnEmployes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(0); });
    connect(ui->btnClients, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(1); });
    connect(ui->btnCommandes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(2); });
    connect(ui->btnStock, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(3); });
    connect(ui->btnAtelier, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(4); });
}

MainWindow::~MainWindow()
{
    delete ui;
}
