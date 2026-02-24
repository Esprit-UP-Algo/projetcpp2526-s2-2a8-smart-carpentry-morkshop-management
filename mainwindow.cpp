#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_HomeWidget.h"
#include "ui_ClientsWidget.h"
#include "ui_CommandesWidget.h"
#include "ui_StockWidget.h"
#include "atelierwidget.h"
#include <QStackedWidget>

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

    QWidget *employesWidget = ui->tabWidget;

    clientsWidget = new QWidget();
    clientsUi = new Ui::ClientsWidget();
    clientsUi->setupUi(clientsWidget);

    commandesWidget = new QWidget();
    commandesUi = new Ui::CommandesWidget();
    commandesUi->setupUi(commandesWidget);

    stockWidget = new QWidget();
    stockUi = new Ui::StockWidget();
    stockUi->setupUi(stockWidget);

    // ✅ correct atelier widget
    atelierWidget = new AtelierWidget();

    stackedWidget->addWidget(homeWidget);      // 0
    stackedWidget->addWidget(employesWidget);  // 1
    stackedWidget->addWidget(clientsWidget);   // 2
    stackedWidget->addWidget(commandesWidget); // 3
    stackedWidget->addWidget(stockWidget);     // 4
    stackedWidget->addWidget(atelierWidget);   // 5

    QLayout *mainLayout = ui->centralwidget->layout();
    mainLayout->addWidget(stackedWidget);

    stackedWidget->setCurrentIndex(0);
    ui->sidebar->setVisible(false);

    connect(stackedWidget, &QStackedWidget::currentChanged, this, [this](int index) {
        ui->sidebar->setVisible(index != 0);
    });

    connect(homeUi->btnAccederModules, &QPushButton::clicked, this, [this](){
        stackedWidget->setCurrentIndex(1);
        ui->tabWidget->setCurrentIndex(0);
        ui->btnEmployes->setChecked(true);
    });

    connect(ui->btnEmployes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(1); });
    connect(ui->btnClients, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(2); });
    connect(ui->btnCommandes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(3); });
    connect(ui->btnStock, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(4); });
    connect(ui->btnAtelier, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(5); });

    connect(clientsUi->btnAjouter,   &QPushButton::clicked, this, [this](){ clientsUi->tabWidget->setCurrentIndex(0); });
    connect(clientsUi->btnModifier,  &QPushButton::clicked, this, [this](){ clientsUi->tabWidget->setCurrentIndex(0); });
    connect(clientsUi->btnSupprimer, &QPushButton::clicked, this, [this](){ clientsUi->tabWidget->setCurrentIndex(0); });
}

MainWindow::~MainWindow()
{
    delete homeUi;
    delete clientsUi;
    delete commandesUi;
    delete stockUi;
    delete atelierWidget;
    delete ui;
}
