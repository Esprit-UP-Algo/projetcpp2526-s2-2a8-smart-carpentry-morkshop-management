/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QHBoxLayout *horizontalLayoutPrincipal;
    QWidget *sidebar;
    QVBoxLayout *verticalLayoutSidebar;
    QLabel *labelLogo;
    QSpacerItem *spacerLogoToButton;
    QPushButton *btnEmployes;
    QPushButton *btnClients;
    QPushButton *btnCommandes;
    QPushButton *btnStock;
    QPushButton *btnAtelier;
    QSpacerItem *verticalSpacerSidebar;
    QWidget *contentContainer;
    QVBoxLayout *contentLayout;
    QSpacerItem *contentSpacer;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 750);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow { background-color: #F5EBE0; }\n"
"    QWidget { background-color: #F5EBE0; color: #3D2817; font-family: 'Segoe UI', Arial, sans-serif; }\n"
"    QTabWidget::pane { border: 2px solid #8B5A2B; background-color: #F5EBE0; border-radius: 5px; }\n"
"    QTabBar::tab { background-color: #C9B59A; color: #3D2817; padding: 10px 20px; margin-right: 2px; border-top-left-radius: 5px; border-top-right-radius: 5px; font-weight: bold; }\n"
"    QTabBar::tab:selected { background-color: #8B5A2B; color: #F5EBE0; }\n"
"    QTabBar::tab:hover { background-color: #9B8068; }\n"
"    QGroupBox { background-color: #FFFFFF; border: 2px solid #8B5A2B; border-radius: 8px; margin-top: 15px; padding-top: 15px; font-weight: bold; }\n"
"    QGroupBox::title { color: #5D4037; subcontrol-origin: margin; left: 10px; padding: 0 5px; font-size: 10pt; }\n"
"    QLineEdit, QDoubleSpinBox, QComboBox, QTextEdit, QDateEdit { background-color: #FFFFFF; border: 2px solid #C9B59A; border-radius: 5px; padding: 8px; color: #3D2817; f"
                        "ont-size: 10pt; }\n"
"    QLineEdit:focus, QDoubleSpinBox:focus, QComboBox:focus, QTextEdit:focus, QDateEdit:focus { border: 2px solid #8B5A2B; }\n"
"    QComboBox { font-size: 10pt; min-height: 28px; }\n"
"    QComboBox::drop-down { border: none; width: 20px; }\n"
"    QComboBox::down-arrow { image: none; border-left: 4px solid transparent; border-right: 4px solid transparent; border-top: 4px solid #8B5A2B; margin-right: 6px; }\n"
"    QPushButton { background-color: #8B5A2B; color: #F5EBE0; border: none; border-radius: 5px; padding: 10px 20px; font-weight: bold; font-size: 10pt; }\n"
"    QPushButton:hover { background-color: #9B8068; }\n"
"    QPushButton:pressed { background-color: #5D4037; }\n"
"    QPushButton#btnAjouter { background-color: #8B9B6A; }\n"
"    QPushButton#btnAjouter:hover { background-color: #9BAB7A; }\n"
"    QPushButton#btnModifier { background-color: #8B5A2B; }\n"
"    QPushButton#btnModifier:hover { background-color: #9B8068; }\n"
"    QPushButton#btnSupprimer { background-color: #5D4"
                        "037; }\n"
"    QPushButton#btnSupprimer:hover { background-color: #6D4C41; }\n"
"    QPushButton#btnAnnuler, QPushButton#btnVider, QPushButton#btnAfficherTout, QPushButton#btnTrier, QPushButton#btnRechercher { background-color: #C9B59A; color: #3D2817; }\n"
"    QPushButton#btnAnnuler:hover, QPushButton#btnVider:hover, QPushButton#btnAfficherTout:hover, QPushButton#btnTrier:hover, QPushButton#btnRechercher:hover { background-color: #D9C5AA; }\n"
"    QTableWidget { background-color: #FFFFFF; alternate-background-color: #F5EBE0; border: 2px solid #C9B59A; border-radius: 5px; gridline-color: #C9B59A; color: #3D2817; }\n"
"    QTableWidget::item:selected { background-color: #8B5A2B; color: #F5EBE0; }\n"
"    QHeaderView::section { background-color: #8B5A2B; color: #F5EBE0; padding: 6px; border: none; font-weight: bold; font-size: 10pt; }\n"
"    QPushButton#btnEmployes, QPushButton#btnClients, QPushButton#btnCommandes, QPushButton#btnStock, QPushButton#btnAtelier { background-color: #C9B59A; color: #3D2817; borde"
                        "r: none; border-left: 0px solid #8B5A2B; border-radius: 0; padding: 20px 15px; font-size: 15pt; font-weight: bold; text-align: left; }\n"
"    QPushButton#btnEmployes:hover, QPushButton#btnClients:hover, QPushButton#btnCommandes:hover, QPushButton#btnStock:hover, QPushButton#btnAtelier:hover { background-color: #9B8068; color: white; }\n"
"    QPushButton#btnEmployes:checked, QPushButton#btnClients:checked, QPushButton#btnCommandes:checked, QPushButton#btnStock:checked, QPushButton#btnAtelier:checked { background-color: #8B5A2B; color: #F5EBE0; border-left: 6px solid #5D4037; }\n"
"    QPushButton#btnEmployes:pressed, QPushButton#btnClients:pressed, QPushButton#btnCommandes:pressed, QPushButton#btnStock:pressed, QPushButton#btnAtelier:pressed { background-color: #5D4037; color: white; }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutPrincipal = new QHBoxLayout(centralwidget);
        horizontalLayoutPrincipal->setSpacing(0);
        horizontalLayoutPrincipal->setObjectName("horizontalLayoutPrincipal");
        horizontalLayoutPrincipal->setContentsMargins(0, 0, 0, 0);
        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setStyleSheet(QString::fromUtf8("background-color: #C9B59A; border-right: 2px solid #8B5A2B;"));
        verticalLayoutSidebar = new QVBoxLayout(sidebar);
        verticalLayoutSidebar->setSpacing(0);
        verticalLayoutSidebar->setObjectName("verticalLayoutSidebar");
        verticalLayoutSidebar->setContentsMargins(0, 10, 0, 0);
        labelLogo = new QLabel(sidebar);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setMinimumSize(QSize(150, 150));
        labelLogo->setMaximumSize(QSize(150, 150));
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.jpeg")));
        labelLogo->setScaledContents(true);
        labelLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayoutSidebar->addWidget(labelLogo, 0, Qt::AlignmentFlag::AlignHCenter);

        spacerLogoToButton = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayoutSidebar->addItem(spacerLogoToButton);

        btnEmployes = new QPushButton(sidebar);
        btnEmployes->setObjectName("btnEmployes");
        btnEmployes->setCheckable(true);
        btnEmployes->setChecked(true);

        verticalLayoutSidebar->addWidget(btnEmployes);

        btnClients = new QPushButton(sidebar);
        btnClients->setObjectName("btnClients");
        btnClients->setCheckable(true);
        btnClients->setChecked(false);

        verticalLayoutSidebar->addWidget(btnClients);

        btnCommandes = new QPushButton(sidebar);
        btnCommandes->setObjectName("btnCommandes");
        btnCommandes->setCheckable(true);
        btnCommandes->setChecked(false);

        verticalLayoutSidebar->addWidget(btnCommandes);

        btnStock = new QPushButton(sidebar);
        btnStock->setObjectName("btnStock");
        btnStock->setCheckable(true);
        btnStock->setChecked(false);

        verticalLayoutSidebar->addWidget(btnStock);

        btnAtelier = new QPushButton(sidebar);
        btnAtelier->setObjectName("btnAtelier");
        btnAtelier->setCheckable(true);
        btnAtelier->setChecked(false);

        verticalLayoutSidebar->addWidget(btnAtelier);

        verticalSpacerSidebar = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayoutSidebar->addItem(verticalSpacerSidebar);


        horizontalLayoutPrincipal->addWidget(sidebar);

        contentContainer = new QWidget(centralwidget);
        contentContainer->setObjectName("contentContainer");
        contentLayout = new QVBoxLayout(contentContainer);
        contentLayout->setSpacing(0);
        contentLayout->setObjectName("contentLayout");
        contentLayout->setContentsMargins(0, 0, 0, 0);
        contentSpacer = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        contentLayout->addItem(contentSpacer);


        horizontalLayoutPrincipal->addWidget(contentContainer);

        horizontalLayoutPrincipal->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Employ\303\251s", nullptr));
        labelLogo->setText(QString());
        btnEmployes->setText(QCoreApplication::translate("MainWindow", "Employ\303\251s", nullptr));
        btnClients->setText(QCoreApplication::translate("MainWindow", "Clients", nullptr));
        btnCommandes->setText(QCoreApplication::translate("MainWindow", "Commandes", nullptr));
        btnStock->setText(QCoreApplication::translate("MainWindow", "Stock", nullptr));
        btnAtelier->setText(QCoreApplication::translate("MainWindow", "Atelier", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
