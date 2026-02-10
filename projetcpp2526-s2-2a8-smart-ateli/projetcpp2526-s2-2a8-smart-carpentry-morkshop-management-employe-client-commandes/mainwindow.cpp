#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <QDebug>
#include <QCoreApplication>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Charger le logo depuis le même dossier que l'exe
    QString logoPath = QCoreApplication::applicationDirPath() + "/logo.png";
    QPixmap logo(logoPath);
    
    qDebug() << "Tentative de chargement depuis:" << logoPath;
    qDebug() << "Logo null?" << logo.isNull();

    if (logo.isNull()) {
        qDebug() << "ERREUR : Logo introuvable !";
        ui->lblLogo->setText("LOGO");
        ui->lblLogo->setStyleSheet("background-color: red; color: white;");
    } else {
        qDebug() << "Logo chargé avec succès ! Taille:" << logo.size();
        ui->lblLogo->setPixmap(logo.scaled(80, 80, Qt::KeepAspectRatio, Qt::SmoothTransformation));
        setWindowIcon(QIcon(logo));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}
