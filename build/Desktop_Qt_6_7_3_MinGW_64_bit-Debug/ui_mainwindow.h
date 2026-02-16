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
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
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
    QPushButton *btnClient;
    QSpacerItem *verticalSpacer;
    QTabWidget *tabWidget;
    QWidget *tabConsulter;
    QVBoxLayout *verticalLayoutConsulter;
    QGroupBox *groupRecherche;
    QHBoxLayout *horizontalRecherche;
    QLabel *labelRech;
    QLineEdit *lineRecherche;
    QPushButton *btnRechercher;
    QSpacerItem *spacerRech;
    QLabel *labelTri;
    QComboBox *comboTri;
    QPushButton *btnTrier;
    QPushButton *btnAfficherTout;
    QGroupBox *groupBoxInfo;
    QFormLayout *formLayout;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QLabel *labelPrenom;
    QLineEdit *lineEditPrenom;
    QLabel *labelTelephone;
    QLineEdit *lineEditTelephone;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelAdresse;
    QTextEdit *textEditAdresse;
    QLabel *labelSociete;
    QLineEdit *lineEditSociete;
    QLabel *labelMatricule;
    QLineEdit *lineEditMatricule;
    QLabel *labelCIN;
    QLineEdit *lineEditCIN;
    QLabel *labelSiteWeb;
    QLineEdit *lineEditSiteWeb;
    QSpacerItem *horizontalSpacerValider;
    QPushButton *btnValider;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBoxActions;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnAfficher;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnVider;
    QTableWidget *tableWidgetClients;
    QGroupBox *groupBoxExport;
    QVBoxLayout *verticalLayout_5;
    QLabel *labelExportInfo;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnExportPDF;
    QSpacerItem *verticalSpacer1;
    QGroupBox *groupBoxOptions;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBoxInclureEntete;
    QCheckBox *checkBoxDateExport;
    QSpacerItem *verticalSpacer_2;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBoxStats;
    QGridLayout *gridLayout_2;
    QLabel *labelTotalClients;
    QLabel *labelTotalClientsValeur;
    QPushButton *btnActualiserStats;
    QSpacerItem *verticalSpacerStats;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1100, 750);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow {\n"
"        background-color: #F5EBE0;\n"
"    }\n"
"    QWidget {\n"
"        background-color: #F5EBE0;\n"
"        color: #3D2817;\n"
"        font-family: 'Segoe UI', Arial, sans-serif;\n"
"    }\n"
"    QTabWidget::pane {\n"
"        border: 2px solid #8B5A2B;\n"
"        background-color: #F5EBE0;\n"
"        border-radius: 5px;\n"
"    }\n"
"    QTabBar::tab {\n"
"        background-color: #C9B59A;\n"
"        color: #3D2817;\n"
"        padding: 10px 20px;\n"
"        margin-right: 2px;\n"
"        border-top-left-radius: 5px;\n"
"        border-top-right-radius: 5px;\n"
"        font-weight: bold;\n"
"    }\n"
"    QTabBar::tab:selected {\n"
"        background-color: #8B5A2B;\n"
"        color: #F5EBE0;\n"
"    }\n"
"    QTabBar::tab:hover {\n"
"        background-color: #9B8068;\n"
"    }\n"
"    QGroupBox {\n"
"        background-color: #FFFFFF;\n"
"        border: 2px solid #8B5A2B;\n"
"        border-radius: 8px;\n"
"        margin-top: 10px;\n"
"        padding-top: 15px;\n"
""
                        "        font-weight: bold;\n"
"    }\n"
"    QGroupBox::title {\n"
"        color: #5D4037;\n"
"        subcontrol-origin: margin;\n"
"        left: 10px;\n"
"        padding: 0 5px;\n"
"    }\n"
"    QLineEdit, QTextEdit {\n"
"        background-color: #FFFFFF;\n"
"        border: 2px solid #C9B59A;\n"
"        border-radius: 5px;\n"
"        padding: 8px;\n"
"        color: #3D2817;\n"
"    }\n"
"    QLineEdit:focus, QTextEdit:focus {\n"
"        border: 2px solid #8B5A2B;\n"
"    }\n"
"    QComboBox {\n"
"        background-color: #FFFFFF;\n"
"        border: 2px solid #C9B59A;\n"
"        border-radius: 5px;\n"
"        padding: 8px;\n"
"        color: #3D2817;\n"
"    }\n"
"    QComboBox:hover {\n"
"        border: 2px solid #8B5A2B;\n"
"    }\n"
"    QComboBox::drop-down {\n"
"        border: none;\n"
"        width: 30px;\n"
"    }\n"
"    QComboBox::down-arrow {\n"
"        image: none;\n"
"        border-left: 5px solid transparent;\n"
"        border-right: 5px solid transparent;\n"
"        border-t"
                        "op: 5px solid #8B5A2B;\n"
"        margin-right: 10px;\n"
"    }\n"
"    QPushButton {\n"
"        background-color: #8B5A2B;\n"
"        color: #F5EBE0;\n"
"        border: none;\n"
"        border-radius: 5px;\n"
"        padding: 10px 20px;\n"
"        font-weight: bold;\n"
"        font-size: 11pt;\n"
"    }\n"
"    QPushButton:hover {\n"
"        background-color: #9B8068;\n"
"    }\n"
"    QPushButton:pressed {\n"
"        background-color: #5D4037;\n"
"    }\n"
"    QPushButton#btnSupprimer {\n"
"        background-color: #5D4037;\n"
"    }\n"
"    QPushButton#btnSupprimer:hover {\n"
"        background-color: #6D4C41;\n"
"    }\n"
"    QPushButton#btnAjouter {\n"
"        background-color: #8B9B6A;\n"
"    }\n"
"    QPushButton#btnAjouter:hover {\n"
"        background-color: #9BAB7A;\n"
"    }\n"
"    QPushButton#btnVider {\n"
"        background-color: #C9B59A;\n"
"        color: #3D2817;\n"
"    }\n"
"    QPushButton#btnVider:hover {\n"
"        background-color: #D9C5AA;\n"
"    }\n"
"    QTableWid"
                        "get {\n"
"        background-color: #FFFFFF;\n"
"        alternate-background-color: #F5EBE0;\n"
"        border: 2px solid #C9B59A;\n"
"        border-radius: 5px;\n"
"        gridline-color: #C9B59A;\n"
"        color: #3D2817;\n"
"    }\n"
"    QTableWidget::item:selected {\n"
"        background-color: #8B5A2B;\n"
"        color: #F5EBE0;\n"
"    }\n"
"    QHeaderView::section {\n"
"        background-color: #8B5A2B;\n"
"        color: #F5EBE0;\n"
"        padding: 8px;\n"
"        border: none;\n"
"        font-weight: bold;\n"
"    }\n"
"    QPushButton#btnClient {\n"
"        background-color: #C9B59A;\n"
"        color: #3D2817;\n"
"        border: none;\n"
"        border-left: 0px solid #8B5A2B;\n"
"        border-radius: 0;\n"
"        padding: 20px 15px;\n"
"        font-size: 15pt;\n"
"        font-weight: bold;\n"
"        text-align: left;\n"
"    }\n"
"    QPushButton#btnClient:hover {\n"
"        background-color: #9B8068;\n"
"        color: white;\n"
"    }\n"
"    QPushButton#btnClient:check"
                        "ed {\n"
"        background-color: #8B5A2B;\n"
"        color: #F5EBE0;\n"
"        border-left: 6px solid #5D4037;\n"
"    }\n"
"    QPushButton#btnClient:pressed {\n"
"        background-color: #5D4037;\n"
"        color: white;\n"
"    }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutPrincipal = new QHBoxLayout(centralwidget);
        horizontalLayoutPrincipal->setObjectName("horizontalLayoutPrincipal");
        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setStyleSheet(QString::fromUtf8("background-color: #C9B59A; border-right: 2px solid #8B5A2B;"));
        verticalLayoutSidebar = new QVBoxLayout(sidebar);
        verticalLayoutSidebar->setSpacing(0);
        verticalLayoutSidebar->setObjectName("verticalLayoutSidebar");
        verticalLayoutSidebar->setContentsMargins(0, 0, 0, 0);
        labelLogo = new QLabel(sidebar);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setMinimumSize(QSize(140, 140));
        labelLogo->setMaximumSize(QSize(160, 160));
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/image.jpg")));
        labelLogo->setScaledContents(true);
        labelLogo->setAlignment(Qt::AlignmentFlag::AlignLeading|Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        verticalLayoutSidebar->addWidget(labelLogo, 0, Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignTop);

        btnClient = new QPushButton(sidebar);
        btnClient->setObjectName("btnClient");
        btnClient->setCheckable(true);
        btnClient->setChecked(true);

        verticalLayoutSidebar->addWidget(btnClient);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayoutSidebar->addItem(verticalSpacer);


        horizontalLayoutPrincipal->addWidget(sidebar);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabConsulter = new QWidget();
        tabConsulter->setObjectName("tabConsulter");
        verticalLayoutConsulter = new QVBoxLayout(tabConsulter);
        verticalLayoutConsulter->setObjectName("verticalLayoutConsulter");
        groupRecherche = new QGroupBox(tabConsulter);
        groupRecherche->setObjectName("groupRecherche");
        horizontalRecherche = new QHBoxLayout(groupRecherche);
        horizontalRecherche->setObjectName("horizontalRecherche");
        labelRech = new QLabel(groupRecherche);
        labelRech->setObjectName("labelRech");

        horizontalRecherche->addWidget(labelRech);

        lineRecherche = new QLineEdit(groupRecherche);
        lineRecherche->setObjectName("lineRecherche");

        horizontalRecherche->addWidget(lineRecherche);

        btnRechercher = new QPushButton(groupRecherche);
        btnRechercher->setObjectName("btnRechercher");

        horizontalRecherche->addWidget(btnRechercher);

        spacerRech = new QSpacerItem(20, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalRecherche->addItem(spacerRech);

        labelTri = new QLabel(groupRecherche);
        labelTri->setObjectName("labelTri");

        horizontalRecherche->addWidget(labelTri);

        comboTri = new QComboBox(groupRecherche);
        comboTri->addItem(QString());
        comboTri->addItem(QString());
        comboTri->setObjectName("comboTri");

        horizontalRecherche->addWidget(comboTri);

        btnTrier = new QPushButton(groupRecherche);
        btnTrier->setObjectName("btnTrier");

        horizontalRecherche->addWidget(btnTrier);

        btnAfficherTout = new QPushButton(groupRecherche);
        btnAfficherTout->setObjectName("btnAfficherTout");

        horizontalRecherche->addWidget(btnAfficherTout);


        verticalLayoutConsulter->addWidget(groupRecherche);

        groupBoxInfo = new QGroupBox(tabConsulter);
        groupBoxInfo->setObjectName("groupBoxInfo");
        formLayout = new QFormLayout(groupBoxInfo);
        formLayout->setObjectName("formLayout");
        labelNom = new QLabel(groupBoxInfo);
        labelNom->setObjectName("labelNom");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelNom);

        lineEditNom = new QLineEdit(groupBoxInfo);
        lineEditNom->setObjectName("lineEditNom");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditNom);

        labelPrenom = new QLabel(groupBoxInfo);
        labelPrenom->setObjectName("labelPrenom");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelPrenom);

        lineEditPrenom = new QLineEdit(groupBoxInfo);
        lineEditPrenom->setObjectName("lineEditPrenom");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditPrenom);

        labelTelephone = new QLabel(groupBoxInfo);
        labelTelephone->setObjectName("labelTelephone");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelTelephone);

        lineEditTelephone = new QLineEdit(groupBoxInfo);
        lineEditTelephone->setObjectName("lineEditTelephone");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditTelephone);

        labelEmail = new QLabel(groupBoxInfo);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(groupBoxInfo);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditEmail);

        labelAdresse = new QLabel(groupBoxInfo);
        labelAdresse->setObjectName("labelAdresse");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelAdresse);

        textEditAdresse = new QTextEdit(groupBoxInfo);
        textEditAdresse->setObjectName("textEditAdresse");

        formLayout->setWidget(4, QFormLayout::FieldRole, textEditAdresse);

        labelSociete = new QLabel(groupBoxInfo);
        labelSociete->setObjectName("labelSociete");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelSociete);

        lineEditSociete = new QLineEdit(groupBoxInfo);
        lineEditSociete->setObjectName("lineEditSociete");

        formLayout->setWidget(5, QFormLayout::FieldRole, lineEditSociete);

        labelMatricule = new QLabel(groupBoxInfo);
        labelMatricule->setObjectName("labelMatricule");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelMatricule);

        lineEditMatricule = new QLineEdit(groupBoxInfo);
        lineEditMatricule->setObjectName("lineEditMatricule");
        lineEditMatricule->setMaxLength(20);

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditMatricule);

        labelCIN = new QLabel(groupBoxInfo);
        labelCIN->setObjectName("labelCIN");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelCIN);

        lineEditCIN = new QLineEdit(groupBoxInfo);
        lineEditCIN->setObjectName("lineEditCIN");
        lineEditCIN->setMaxLength(8);

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditCIN);

        labelSiteWeb = new QLabel(groupBoxInfo);
        labelSiteWeb->setObjectName("labelSiteWeb");

        formLayout->setWidget(8, QFormLayout::LabelRole, labelSiteWeb);

        lineEditSiteWeb = new QLineEdit(groupBoxInfo);
        lineEditSiteWeb->setObjectName("lineEditSiteWeb");

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEditSiteWeb);

        horizontalSpacerValider = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        formLayout->setItem(9, QFormLayout::LabelRole, horizontalSpacerValider);

        btnValider = new QPushButton(groupBoxInfo);
        btnValider->setObjectName("btnValider");
        btnValider->setMinimumHeight(45);
        btnValider->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; color: white; font-weight: bold;"));

        formLayout->setWidget(9, QFormLayout::FieldRole, btnValider);


        verticalLayoutConsulter->addWidget(groupBoxInfo);

        tabWidget->addTab(tabConsulter, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayout_4 = new QVBoxLayout(tabAffichage);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBoxActions = new QGroupBox(tabAffichage);
        groupBoxActions->setObjectName("groupBoxActions");
        horizontalLayout = new QHBoxLayout(groupBoxActions);
        horizontalLayout->setObjectName("horizontalLayout");
        btnAjouter = new QPushButton(groupBoxActions);
        btnAjouter->setObjectName("btnAjouter");
        QIcon icon(QIcon::fromTheme(QString::fromUtf8("list-add")));
        btnAjouter->setIcon(icon);

        horizontalLayout->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxActions);
        btnModifier->setObjectName("btnModifier");
        QIcon icon1(QIcon::fromTheme(QString::fromUtf8("document-edit")));
        btnModifier->setIcon(icon1);

        horizontalLayout->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxActions);
        btnSupprimer->setObjectName("btnSupprimer");
        QIcon icon2(QIcon::fromTheme(QString::fromUtf8("edit-delete")));
        btnSupprimer->setIcon(icon2);

        horizontalLayout->addWidget(btnSupprimer);

        btnAfficher = new QPushButton(groupBoxActions);
        btnAfficher->setObjectName("btnAfficher");
        QIcon icon3(QIcon::fromTheme(QString::fromUtf8("view-refresh")));
        btnAfficher->setIcon(icon3);

        horizontalLayout->addWidget(btnAfficher);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnVider = new QPushButton(groupBoxActions);
        btnVider->setObjectName("btnVider");

        horizontalLayout->addWidget(btnVider);


        verticalLayout_4->addWidget(groupBoxActions);

        tableWidgetClients = new QTableWidget(tabAffichage);
        if (tableWidgetClients->columnCount() < 6)
            tableWidgetClients->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetClients->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetClients->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetClients->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetClients->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetClients->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidgetClients->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidgetClients->setObjectName("tableWidgetClients");
        tableWidgetClients->setAlternatingRowColors(true);
        tableWidgetClients->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableWidgetClients->setSortingEnabled(true);

        verticalLayout_4->addWidget(tableWidgetClients);

        groupBoxExport = new QGroupBox(tabAffichage);
        groupBoxExport->setObjectName("groupBoxExport");
        verticalLayout_5 = new QVBoxLayout(groupBoxExport);
        verticalLayout_5->setObjectName("verticalLayout_5");
        labelExportInfo = new QLabel(groupBoxExport);
        labelExportInfo->setObjectName("labelExportInfo");

        verticalLayout_5->addWidget(labelExportInfo);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnExportPDF = new QPushButton(groupBoxExport);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setMinimumSize(QSize(0, 50));
        QIcon icon4(QIcon::fromTheme(QString::fromUtf8("document-save")));
        btnExportPDF->setIcon(icon4);

        horizontalLayout_2->addWidget(btnExportPDF);


        verticalLayout_5->addLayout(horizontalLayout_2);

        verticalSpacer1 = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer1);

        groupBoxOptions = new QGroupBox(groupBoxExport);
        groupBoxOptions->setObjectName("groupBoxOptions");
        verticalLayout_6 = new QVBoxLayout(groupBoxOptions);
        verticalLayout_6->setObjectName("verticalLayout_6");
        checkBoxInclureEntete = new QCheckBox(groupBoxOptions);
        checkBoxInclureEntete->setObjectName("checkBoxInclureEntete");
        checkBoxInclureEntete->setChecked(true);

        verticalLayout_6->addWidget(checkBoxInclureEntete);

        checkBoxDateExport = new QCheckBox(groupBoxOptions);
        checkBoxDateExport->setObjectName("checkBoxDateExport");
        checkBoxDateExport->setChecked(true);

        verticalLayout_6->addWidget(checkBoxDateExport);


        verticalLayout_5->addWidget(groupBoxOptions);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_2);


        verticalLayout_4->addWidget(groupBoxExport);

        tabWidget->addTab(tabAffichage, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayout_7 = new QVBoxLayout(tabStatistiques);
        verticalLayout_7->setObjectName("verticalLayout_7");
        groupBoxStats = new QGroupBox(tabStatistiques);
        groupBoxStats->setObjectName("groupBoxStats");
        gridLayout_2 = new QGridLayout(groupBoxStats);
        gridLayout_2->setObjectName("gridLayout_2");
        labelTotalClients = new QLabel(groupBoxStats);
        labelTotalClients->setObjectName("labelTotalClients");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        labelTotalClients->setFont(font);

        gridLayout_2->addWidget(labelTotalClients, 0, 0, 1, 1);

        labelTotalClientsValeur = new QLabel(groupBoxStats);
        labelTotalClientsValeur->setObjectName("labelTotalClientsValeur");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(12);
        labelTotalClientsValeur->setFont(font1);

        gridLayout_2->addWidget(labelTotalClientsValeur, 0, 1, 1, 1);

        btnActualiserStats = new QPushButton(groupBoxStats);
        btnActualiserStats->setObjectName("btnActualiserStats");

        gridLayout_2->addWidget(btnActualiserStats, 1, 0, 1, 1);


        verticalLayout_7->addWidget(groupBoxStats);

        verticalSpacerStats = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_7->addItem(verticalSpacerStats);

        tabWidget->addTab(tabStatistiques, QString());

        horizontalLayoutPrincipal->addWidget(tabWidget);

        horizontalLayoutPrincipal->setStretch(1, 1);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Clients", nullptr));
        labelLogo->setText(QString());
        btnClient->setText(QCoreApplication::translate("MainWindow", "Client", nullptr));
        groupRecherche->setTitle(QCoreApplication::translate("MainWindow", "Recherche et Tri", nullptr));
        labelRech->setText(QCoreApplication::translate("MainWindow", "Rechercher :", nullptr));
        lineRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom ou t\303\251l\303\251phone...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        labelTri->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboTri->setItemText(0, QCoreApplication::translate("MainWindow", "Nom (A-Z)", nullptr));
        comboTri->setItemText(1, QCoreApplication::translate("MainWindow", "Nom (Z-A)", nullptr));

        btnTrier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        btnAfficherTout->setText(QCoreApplication::translate("MainWindow", "Afficher tout", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("MainWindow", "Informations Client", nullptr));
        labelNom->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        lineEditNom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nom", nullptr));
        labelPrenom->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom :", nullptr));
        lineEditPrenom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le pr\303\251nom", nullptr));
        labelTelephone->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone :", nullptr));
        lineEditTelephone->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le t\303\251l\303\251phone", nullptr));
        labelEmail->setText(QCoreApplication::translate("MainWindow", "Email :", nullptr));
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez l'email", nullptr));
        labelAdresse->setText(QCoreApplication::translate("MainWindow", "Adresse :", nullptr));
        textEditAdresse->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez l'adresse compl\303\250te", nullptr));
        labelSociete->setText(QCoreApplication::translate("MainWindow", "Soci\303\251t\303\251 :", nullptr));
        lineEditSociete->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom de l'entreprise / Raison sociale", nullptr));
        labelMatricule->setText(QCoreApplication::translate("MainWindow", "Matricule Fiscale :", nullptr));
        lineEditMatricule->setPlaceholderText(QCoreApplication::translate("MainWindow", "0000000A / 123456789 / A", nullptr));
        labelCIN->setText(QCoreApplication::translate("MainWindow", "N\302\260 CIN :", nullptr));
        lineEditCIN->setPlaceholderText(QCoreApplication::translate("MainWindow", "01234567", nullptr));
        labelSiteWeb->setText(QCoreApplication::translate("MainWindow", "Site web / FB :", nullptr));
        lineEditSiteWeb->setPlaceholderText(QCoreApplication::translate("MainWindow", "https:// ou www. ou facebook.com/", nullptr));
        btnValider->setText(QCoreApplication::translate("MainWindow", "Valider", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabConsulter), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnAfficher->setText(QCoreApplication::translate("MainWindow", "Afficher Tout", nullptr));
        btnVider->setText(QCoreApplication::translate("MainWindow", "Vider", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetClients->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetClients->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetClients->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetClients->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetClients->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetClients->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "Adresse", nullptr));
        groupBoxExport->setTitle(QCoreApplication::translate("MainWindow", "Exporter la Liste des Clients", nullptr));
        labelExportInfo->setText(QCoreApplication::translate("MainWindow", "Choisissez le format d'exportation de la liste des clients :", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("MainWindow", "Exporter en PDF", nullptr));
        groupBoxOptions->setTitle(QCoreApplication::translate("MainWindow", "Options d'exportation", nullptr));
        checkBoxInclureEntete->setText(QCoreApplication::translate("MainWindow", "Inclure l'en-t\303\252te", nullptr));
        checkBoxDateExport->setText(QCoreApplication::translate("MainWindow", "Inclure la date d'exportation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        groupBoxStats->setTitle(QCoreApplication::translate("MainWindow", "Statistiques G\303\251n\303\251rales", nullptr));
        labelTotalClients->setText(QCoreApplication::translate("MainWindow", "Nombre total de clients :", nullptr));
        labelTotalClientsValeur->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnActualiserStats->setText(QCoreApplication::translate("MainWindow", "Actualiser les Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
