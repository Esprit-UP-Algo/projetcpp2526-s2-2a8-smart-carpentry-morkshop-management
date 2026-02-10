#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_HomeWidget.h"
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

    // Home widget
    homeWidget = new QWidget();
    homeUi = new Ui::HomeWidget();
    homeUi->setupUi(homeWidget);

    // Get the current tab widget (Employés content)
    QWidget *employesWidget = ui->tabWidget;

    // Create Clients widget
    clientsWidget = new QWidget();
    clientsUi = new Ui::ClientsWidget();
    clientsUi->setupUi(clientsWidget);

    // Create placeholder widgets for other modules
    commandesWidget = new QWidget();
    commandesUi = new Ui::CommandesWidget();
    commandesUi->setupUi(commandesWidget);

    stockWidget = new QWidget();
    stockUi = new Ui::StockWidget();
    stockUi->setupUi(stockWidget);

    atelierWidget = new QWidget();
    atelierUi = new Ui::AtelierWidget();
    atelierUi->setupUi(atelierWidget);

    // Add all widgets to stacked widget
    stackedWidget->addWidget(homeWidget);         // Index 0 (Home)
    stackedWidget->addWidget(employesWidget);     // Index 1
    stackedWidget->addWidget(clientsWidget);      // Index 2
    stackedWidget->addWidget(commandesWidget);    // Index 3
    stackedWidget->addWidget(stockWidget);        // Index 4
    stackedWidget->addWidget(atelierWidget);      // Index 5

    // Replace the tab widget in the main layout with the stacked widget
    QLayout *mainLayout = ui->centralwidget->layout();
    mainLayout->addWidget(stackedWidget);

    // Go to home page at startup
    stackedWidget->setCurrentIndex(0);
    ui->sidebar->setVisible(false);

    // Hide/show sidebar depending on page
    connect(stackedWidget, &QStackedWidget::currentChanged, this, [this](int index) {
        ui->sidebar->setVisible(index != 0);
    });

    // Button from home page
    connect(homeUi->btnAccederModules, &QPushButton::clicked, this, [this](){
        stackedWidget->setCurrentIndex(1);
        ui->tabWidget->setCurrentIndex(0); // Consulter tab
        ui->btnEmployes->setChecked(true);
    });

    // Connect navigation buttons
    connect(ui->btnEmployes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(1); });
    connect(ui->btnClients, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(2); });
    connect(ui->btnCommandes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(3); });
    connect(ui->btnStock, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(4); });
    connect(ui->btnAtelier, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(5); });
}

MainWindow::~MainWindow()
{
    delete homeUi;
    delete clientsUi;
    delete commandesUi;
    delete stockUi;
    delete atelierUi;
    delete ui;
}
