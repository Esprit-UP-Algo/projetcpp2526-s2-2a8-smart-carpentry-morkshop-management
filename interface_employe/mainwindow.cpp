#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ui_HomeWidget.h"
#include "atelierwidget.h"
#include "employewidget.h"
#include "clientswidget.h"
#include "commandeswidget.h"
#include "stockwidget.h"

#include <QStackedWidget>
#include <QButtonGroup>
#include <QMessageBox>
#include <QSqlQuery>

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
    stockWidget = new StockWidget();
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

    // ---- LOGIN ACTION (function)
    auto doLogin = [this]() {
        const QString email = homeUi->lineEmail->text().trimmed();
        const QString password = homeUi->linePassword->text().trimmed();

        if (email.isEmpty() || password.isEmpty()) {
            QMessageBox::warning(this, "Erreur", "Veuillez saisir Email et Mot de passe.");
            return;
        }

        // Responsable RH fixe
        if (email == "adminadmin@gmail.com" && password == "admin123") {
            applyRole("RH");
            stackedWidget->setCurrentIndex(1);
            ui->btnEmployes->setChecked(true);
            return;
        }

        // Employé (email + CIN)
        QSqlQuery query;
        query.prepare("SELECT COUNT(*) FROM ATELIER.EMPLOYE WHERE EMAIL = :email AND CIN = :cin");
        query.bindValue(":email", email);
        query.bindValue(":cin", password);
        if (query.exec() && query.next() && query.value(0).toInt() > 0) {
            applyRole("EMPLOYE");
            stackedWidget->setCurrentIndex(2);
            ui->btnClients->setChecked(true);
            return;
        }

        QMessageBox::warning(this, "Erreur", "Email ou mot de passe incorrect.");
    };

    // bouton
    connect(homeUi->btnAccederModules, &QPushButton::clicked, this, doLogin);
    // ENTER sur email + mot de passe
    connect(homeUi->lineEmail, &QLineEdit::returnPressed, this, doLogin);
    connect(homeUi->linePassword, &QLineEdit::returnPressed, this, doLogin);

    connect(ui->btnEmployes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(1); });
    connect(ui->btnClients, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(2); });
    connect(ui->btnCommandes, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(3); });
    connect(ui->btnStock, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(4); });
    connect(ui->btnAtelier, &QPushButton::clicked, this, [this](){ stackedWidget->setCurrentIndex(5); });
}

MainWindow::~MainWindow()
{
    delete homeUi;
    delete atelierWidget;
    delete employesWidget;
    delete clientsWidget;
    delete commandesWidget;
    delete stockWidget;
    delete ui;
}

void MainWindow::applyRole(const QString &role)
{
    currentRole = role;

    if (role == "EMPLOYE") {
        ui->btnEmployes->setEnabled(false);
        ui->btnEmployes->setText("🔒 Employés");
        ui->btnEmployes->setToolTip("Accès réservé au Responsable RH");
    } else {
        ui->btnEmployes->setEnabled(true);
        ui->btnEmployes->setText("Employés");
        ui->btnEmployes->setToolTip("");
    }
}
