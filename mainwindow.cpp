#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Démarrer sur l'onglet Consulter (optionnel mais recommandé)
    ui->tabWidget->setCurrentIndex(0);

    // Connexions pour basculer vers Consulter quand on clique sur ces boutons
    connect(ui->btnAjouter,   &QPushButton::clicked, this, &MainWindow::allerVersConsulter);
    connect(ui->btnModifier,  &QPushButton::clicked, this, &MainWindow::allerVersConsulter);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &MainWindow::allerVersConsulter);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// ───────────────────────────────────────────────
// Fonction qui bascule vers l'onglet Consulter
// ───────────────────────────────────────────────
void MainWindow::allerVersConsulter()
{
    ui->tabWidget->setCurrentIndex(0);   // 0 = Consulter
}
