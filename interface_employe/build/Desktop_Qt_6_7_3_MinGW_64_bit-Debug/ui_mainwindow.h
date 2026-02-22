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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
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
    QSpacerItem *verticalSpacerSidebar;
    QTabWidget *tabWidget;
    QWidget *tabConsulter;
    QVBoxLayout *verticalLayoutConsulter;
    QGroupBox *groupRechercheEtTri;
    QHBoxLayout *horizontalRechercheEtTri;
    QLabel *labelRechercher;
    QLineEdit *lineEditRecherche;
    QPushButton *btnRechercher;
    QSpacerItem *spacerRecherche;
    QLabel *labelTrierPar;
    QComboBox *comboBoxTri;
    QPushButton *btnTrier;
    QPushButton *btnAfficherTout;
    QGroupBox *groupBoxInfoEmployes;
    QVBoxLayout *verticalLayoutInfo;
    QHBoxLayout *horizontalID;
    QLabel *labelID;
    QLineEdit *lineEditID;
    QHBoxLayout *horizontalNom;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QHBoxLayout *horizontalPoste;
    QLabel *labelPoste;
    QLineEdit *lineEditPoste;
    QHBoxLayout *horizontalSalaire;
    QLabel *labelSalaire;
    QDoubleSpinBox *doubleSpinBoxSalaire;
    QHBoxLayout *horizontalDispo;
    QLabel *labelDispo;
    QComboBox *comboBoxDispo;
    QSpacerItem *verticalSpacerForm;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayoutAffichage;
    QGroupBox *groupBoxActions;
    QHBoxLayout *horizontalLayoutActions;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnAfficherTout1;
    QSpacerItem *horizontalSpacerActions;
    QPushButton *btnVider;
    QTableWidget *tableWidgetEmployes;
    QGroupBox *groupBoxExport;
    QVBoxLayout *verticalLayoutExport;
    QLabel *labelExportInfo;
    QHBoxLayout *horizontalLayoutExportButtons;
    QPushButton *btnExportPDF;
    QGroupBox *groupBoxExportOptions;
    QVBoxLayout *verticalLayoutOptions;
    QCheckBox *checkBoxInclureEntete;
    QCheckBox *checkBoxDateExport;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayoutStats;
    QGroupBox *groupBoxStats;
    QGridLayout *gridLayoutStats;
    QLabel *labelTotalEmployes;
    QLabel *labelTotalEmployesValeur;
    QPushButton *btnActualiserStats;
    QSpacerItem *verticalSpacerStats;
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
"    QLineEdit, QDoubleSpinBox, QComboBox { background-color: #FFFFFF; border: 2px solid #C9B59A; border-radius: 5px; padding: 8px; color: #3D2817; font-size: 10pt; }\n"
""
                        "    QLineEdit:focus, QDoubleSpinBox:focus, QComboBox:focus { border: 2px solid #8B5A2B; }\n"
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
"    QPushButton#btnSupprimer { background-color: #5D4037; }\n"
"    QPushButton#btnSupprimer:hover { backgrou"
                        "nd-color: #6D4C41; }\n"
"    QPushButton#btnAnnuler, QPushButton#btnVider, QPushButton#btnAfficherTout, QPushButton#btnTrier, QPushButton#btnRechercher { background-color: #C9B59A; color: #3D2817; }\n"
"    QPushButton#btnAnnuler:hover, QPushButton#btnVider:hover, QPushButton#btnAfficherTout:hover, QPushButton#btnTrier:hover, QPushButton#btnRechercher:hover { background-color: #D9C5AA; }\n"
"    QTableWidget { background-color: #FFFFFF; alternate-background-color: #F5EBE0; border: 2px solid #C9B59A; border-radius: 5px; gridline-color: #C9B59A; color: #3D2817; }\n"
"    QTableWidget::item:selected { background-color: #8B5A2B; color: #F5EBE0; }\n"
"    QHeaderView::section { background-color: #8B5A2B; color: #F5EBE0; padding: 6px; border: none; font-weight: bold; font-size: 10pt; }\n"
"    QPushButton#btnEmployes { background-color: #C9B59A; color: #3D2817; border: none; border-left: 0px solid #8B5A2B; border-radius: 0; padding: 20px 15px; font-size: 15pt; font-weight: bold; text-align: left; }\n"
"    QPushButt"
                        "on#btnEmployes:hover { background-color: #9B8068; color: white; }\n"
"    QPushButton#btnEmployes:checked { background-color: #8B5A2B; color: #F5EBE0; border-left: 6px solid #5D4037; }\n"
"    QPushButton#btnEmployes:pressed { background-color: #5D4037; color: white; }\n"
"   "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        horizontalLayoutPrincipal = new QHBoxLayout(centralwidget);
        horizontalLayoutPrincipal->setObjectName("horizontalLayoutPrincipal");
        sidebar = new QWidget(centralwidget);
        sidebar->setObjectName("sidebar");
        sidebar->setMinimumWidth(180);
        sidebar->setMaximumWidth(180);
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
        labelLogo->setAlignment(Qt::AlignCenter);

        verticalLayoutSidebar->addWidget(labelLogo, 0, Qt::AlignHCenter);

        spacerLogoToButton = new QSpacerItem(20, 20, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Fixed);

        verticalLayoutSidebar->addItem(spacerLogoToButton);

        btnEmployes = new QPushButton(sidebar);
        btnEmployes->setObjectName("btnEmployes");
        btnEmployes->setCheckable(true);
        btnEmployes->setChecked(true);

        verticalLayoutSidebar->addWidget(btnEmployes);

        verticalSpacerSidebar = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayoutSidebar->addItem(verticalSpacerSidebar);


        horizontalLayoutPrincipal->addWidget(sidebar);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabConsulter = new QWidget();
        tabConsulter->setObjectName("tabConsulter");
        verticalLayoutConsulter = new QVBoxLayout(tabConsulter);
        verticalLayoutConsulter->setSpacing(10);
        verticalLayoutConsulter->setObjectName("verticalLayoutConsulter");
        groupRechercheEtTri = new QGroupBox(tabConsulter);
        groupRechercheEtTri->setObjectName("groupRechercheEtTri");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(groupRechercheEtTri->sizePolicy().hasHeightForWidth());
        groupRechercheEtTri->setSizePolicy(sizePolicy);
        horizontalRechercheEtTri = new QHBoxLayout(groupRechercheEtTri);
        horizontalRechercheEtTri->setSpacing(10);
        horizontalRechercheEtTri->setObjectName("horizontalRechercheEtTri");
        horizontalRechercheEtTri->setContentsMargins(10, 10, 10, 10);
        labelRechercher = new QLabel(groupRechercheEtTri);
        labelRechercher->setObjectName("labelRechercher");

        horizontalRechercheEtTri->addWidget(labelRechercher, 0, Qt::AlignVCenter);

        lineEditRecherche = new QLineEdit(groupRechercheEtTri);
        lineEditRecherche->setObjectName("lineEditRecherche");

        horizontalRechercheEtTri->addWidget(lineEditRecherche);

        btnRechercher = new QPushButton(groupRechercheEtTri);
        btnRechercher->setObjectName("btnRechercher");

        horizontalRechercheEtTri->addWidget(btnRechercher);

        spacerRecherche = new QSpacerItem(20, 20, QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Minimum);

        horizontalRechercheEtTri->addItem(spacerRecherche);

        labelTrierPar = new QLabel(groupRechercheEtTri);
        labelTrierPar->setObjectName("labelTrierPar");

        horizontalRechercheEtTri->addWidget(labelTrierPar, 0, Qt::AlignVCenter);

        comboBoxTri = new QComboBox(groupRechercheEtTri);
        comboBoxTri->addItem(QString());
        comboBoxTri->addItem(QString());
        comboBoxTri->setObjectName("comboBoxTri");
        comboBoxTri->setMinimumWidth(160);

        horizontalRechercheEtTri->addWidget(comboBoxTri);

        btnTrier = new QPushButton(groupRechercheEtTri);
        btnTrier->setObjectName("btnTrier");

        horizontalRechercheEtTri->addWidget(btnTrier);

        btnAfficherTout = new QPushButton(groupRechercheEtTri);
        btnAfficherTout->setObjectName("btnAfficherTout");

        horizontalRechercheEtTri->addWidget(btnAfficherTout);


        verticalLayoutConsulter->addWidget(groupRechercheEtTri);

        groupBoxInfoEmployes = new QGroupBox(tabConsulter);
        groupBoxInfoEmployes->setObjectName("groupBoxInfoEmployes");
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(groupBoxInfoEmployes->sizePolicy().hasHeightForWidth());
        groupBoxInfoEmployes->setSizePolicy(sizePolicy1);
        verticalLayoutInfo = new QVBoxLayout(groupBoxInfoEmployes);
        verticalLayoutInfo->setSpacing(10);
        verticalLayoutInfo->setObjectName("verticalLayoutInfo");
        verticalLayoutInfo->setContentsMargins(12, 12, 12, 12);
        horizontalID = new QHBoxLayout();
        horizontalID->setObjectName("horizontalID");
        labelID = new QLabel(groupBoxInfoEmployes);
        labelID->setObjectName("labelID");
        labelID->setMinimumWidth(120);
        labelID->setMaximumWidth(120);

        horizontalID->addWidget(labelID);

        lineEditID = new QLineEdit(groupBoxInfoEmployes);
        lineEditID->setObjectName("lineEditID");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(1);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(lineEditID->sizePolicy().hasHeightForWidth());
        lineEditID->setSizePolicy(sizePolicy2);

        horizontalID->addWidget(lineEditID);


        verticalLayoutInfo->addLayout(horizontalID);

        horizontalNom = new QHBoxLayout();
        horizontalNom->setObjectName("horizontalNom");
        labelNom = new QLabel(groupBoxInfoEmployes);
        labelNom->setObjectName("labelNom");
        labelNom->setMinimumWidth(120);
        labelNom->setMaximumWidth(120);

        horizontalNom->addWidget(labelNom);

        lineEditNom = new QLineEdit(groupBoxInfoEmployes);
        lineEditNom->setObjectName("lineEditNom");
        sizePolicy2.setHeightForWidth(lineEditNom->sizePolicy().hasHeightForWidth());
        lineEditNom->setSizePolicy(sizePolicy2);

        horizontalNom->addWidget(lineEditNom);


        verticalLayoutInfo->addLayout(horizontalNom);

        horizontalPoste = new QHBoxLayout();
        horizontalPoste->setObjectName("horizontalPoste");
        labelPoste = new QLabel(groupBoxInfoEmployes);
        labelPoste->setObjectName("labelPoste");
        labelPoste->setMinimumWidth(120);
        labelPoste->setMaximumWidth(120);

        horizontalPoste->addWidget(labelPoste);

        lineEditPoste = new QLineEdit(groupBoxInfoEmployes);
        lineEditPoste->setObjectName("lineEditPoste");
        sizePolicy2.setHeightForWidth(lineEditPoste->sizePolicy().hasHeightForWidth());
        lineEditPoste->setSizePolicy(sizePolicy2);

        horizontalPoste->addWidget(lineEditPoste);


        verticalLayoutInfo->addLayout(horizontalPoste);

        horizontalSalaire = new QHBoxLayout();
        horizontalSalaire->setObjectName("horizontalSalaire");
        labelSalaire = new QLabel(groupBoxInfoEmployes);
        labelSalaire->setObjectName("labelSalaire");
        labelSalaire->setMinimumWidth(120);
        labelSalaire->setMaximumWidth(120);

        horizontalSalaire->addWidget(labelSalaire);

        doubleSpinBoxSalaire = new QDoubleSpinBox(groupBoxInfoEmployes);
        doubleSpinBoxSalaire->setObjectName("doubleSpinBoxSalaire");
        sizePolicy2.setHeightForWidth(doubleSpinBoxSalaire->sizePolicy().hasHeightForWidth());
        doubleSpinBoxSalaire->setSizePolicy(sizePolicy2);
        doubleSpinBoxSalaire->setMaximum(999999.989999999990687);
        doubleSpinBoxSalaire->setValue(0);

        horizontalSalaire->addWidget(doubleSpinBoxSalaire);


        verticalLayoutInfo->addLayout(horizontalSalaire);

        horizontalDispo = new QHBoxLayout();
        horizontalDispo->setObjectName("horizontalDispo");
        labelDispo = new QLabel(groupBoxInfoEmployes);
        labelDispo->setObjectName("labelDispo");
        labelDispo->setMinimumWidth(120);
        labelDispo->setMaximumWidth(120);

        horizontalDispo->addWidget(labelDispo);

        comboBoxDispo = new QComboBox(groupBoxInfoEmployes);
        comboBoxDispo->addItem(QString());
        comboBoxDispo->addItem(QString());
        comboBoxDispo->addItem(QString());
        comboBoxDispo->setObjectName("comboBoxDispo");
        sizePolicy2.setHeightForWidth(comboBoxDispo->sizePolicy().hasHeightForWidth());
        comboBoxDispo->setSizePolicy(sizePolicy2);

        horizontalDispo->addWidget(comboBoxDispo);


        verticalLayoutInfo->addLayout(horizontalDispo);

        verticalSpacerForm = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayoutInfo->addItem(verticalSpacerForm);


        verticalLayoutConsulter->addWidget(groupBoxInfoEmployes);

        tabWidget->addTab(tabConsulter, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayoutAffichage = new QVBoxLayout(tabAffichage);
        verticalLayoutAffichage->setSpacing(10);
        verticalLayoutAffichage->setObjectName("verticalLayoutAffichage");
        groupBoxActions = new QGroupBox(tabAffichage);
        groupBoxActions->setObjectName("groupBoxActions");
        horizontalLayoutActions = new QHBoxLayout(groupBoxActions);
        horizontalLayoutActions->setSpacing(10);
        horizontalLayoutActions->setObjectName("horizontalLayoutActions");
        btnAjouter = new QPushButton(groupBoxActions);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayoutActions->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxActions);
        btnModifier->setObjectName("btnModifier");

        horizontalLayoutActions->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxActions);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayoutActions->addWidget(btnSupprimer);

        btnAfficherTout1 = new QPushButton(groupBoxActions);
        btnAfficherTout1->setObjectName("btnAfficherTout1");

        horizontalLayoutActions->addWidget(btnAfficherTout1);

        horizontalSpacerActions = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutActions->addItem(horizontalSpacerActions);

        btnVider = new QPushButton(groupBoxActions);
        btnVider->setObjectName("btnVider");

        horizontalLayoutActions->addWidget(btnVider);


        verticalLayoutAffichage->addWidget(groupBoxActions);

        tableWidgetEmployes = new QTableWidget(tabAffichage);
        if (tableWidgetEmployes->columnCount() < 5)
            tableWidgetEmployes->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidgetEmployes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        tableWidgetEmployes->setObjectName("tableWidgetEmployes");
        tableWidgetEmployes->setAlternatingRowColors(true);
        tableWidgetEmployes->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableWidgetEmployes->setSortingEnabled(true);

        verticalLayoutAffichage->addWidget(tableWidgetEmployes);

        groupBoxExport = new QGroupBox(tabAffichage);
        groupBoxExport->setObjectName("groupBoxExport");
        verticalLayoutExport = new QVBoxLayout(groupBoxExport);
        verticalLayoutExport->setObjectName("verticalLayoutExport");
        labelExportInfo = new QLabel(groupBoxExport);
        labelExportInfo->setObjectName("labelExportInfo");

        verticalLayoutExport->addWidget(labelExportInfo);

        horizontalLayoutExportButtons = new QHBoxLayout();
        horizontalLayoutExportButtons->setObjectName("horizontalLayoutExportButtons");
        btnExportPDF = new QPushButton(groupBoxExport);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setMinimumSize(QSize(0, 50));

        horizontalLayoutExportButtons->addWidget(btnExportPDF);


        verticalLayoutExport->addLayout(horizontalLayoutExportButtons);

        groupBoxExportOptions = new QGroupBox(groupBoxExport);
        groupBoxExportOptions->setObjectName("groupBoxExportOptions");
        verticalLayoutOptions = new QVBoxLayout(groupBoxExportOptions);
        verticalLayoutOptions->setObjectName("verticalLayoutOptions");
        checkBoxInclureEntete = new QCheckBox(groupBoxExportOptions);
        checkBoxInclureEntete->setObjectName("checkBoxInclureEntete");
        checkBoxInclureEntete->setChecked(true);

        verticalLayoutOptions->addWidget(checkBoxInclureEntete);

        checkBoxDateExport = new QCheckBox(groupBoxExportOptions);
        checkBoxDateExport->setObjectName("checkBoxDateExport");
        checkBoxDateExport->setChecked(true);

        verticalLayoutOptions->addWidget(checkBoxDateExport);


        verticalLayoutExport->addWidget(groupBoxExportOptions);


        verticalLayoutAffichage->addWidget(groupBoxExport);

        tabWidget->addTab(tabAffichage, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayoutStats = new QVBoxLayout(tabStatistiques);
        verticalLayoutStats->setObjectName("verticalLayoutStats");
        groupBoxStats = new QGroupBox(tabStatistiques);
        groupBoxStats->setObjectName("groupBoxStats");
        gridLayoutStats = new QGridLayout(groupBoxStats);
        gridLayoutStats->setObjectName("gridLayoutStats");
        labelTotalEmployes = new QLabel(groupBoxStats);
        labelTotalEmployes->setObjectName("labelTotalEmployes");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setBold(true);
        labelTotalEmployes->setFont(font);

        gridLayoutStats->addWidget(labelTotalEmployes, 0, 0, 1, 1);

        labelTotalEmployesValeur = new QLabel(groupBoxStats);
        labelTotalEmployesValeur->setObjectName("labelTotalEmployesValeur");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(12);
        labelTotalEmployesValeur->setFont(font1);

        gridLayoutStats->addWidget(labelTotalEmployesValeur, 0, 1, 1, 1);

        btnActualiserStats = new QPushButton(groupBoxStats);
        btnActualiserStats->setObjectName("btnActualiserStats");

        gridLayoutStats->addWidget(btnActualiserStats, 1, 0, 1, 1);


        verticalLayoutStats->addWidget(groupBoxStats);

        verticalSpacerStats = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayoutStats->addItem(verticalSpacerStats);

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
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Gestion des Employ\303\251s", nullptr));
        labelLogo->setText(QString());
        btnEmployes->setText(QCoreApplication::translate("MainWindow", "Employ\303\251s", nullptr));
        groupRechercheEtTri->setTitle(QCoreApplication::translate("MainWindow", "Recherche et Tri", nullptr));
        labelRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher :", nullptr));
        lineEditRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "CIN ou poste...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("MainWindow", "Rechercher", nullptr));
        labelTrierPar->setText(QCoreApplication::translate("MainWindow", "Trier par :", nullptr));
        comboBoxTri->setItemText(0, QCoreApplication::translate("MainWindow", "Salaire (croissant)", nullptr));
        comboBoxTri->setItemText(1, QCoreApplication::translate("MainWindow", "Salaire (d\303\251croissant)", nullptr));

        btnTrier->setText(QCoreApplication::translate("MainWindow", "Trier", nullptr));
        btnAfficherTout->setText(QCoreApplication::translate("MainWindow", "Afficher tout", nullptr));
        groupBoxInfoEmployes->setTitle(QCoreApplication::translate("MainWindow", "Informations des Employ\303\251s", nullptr));
        labelID->setText(QCoreApplication::translate("MainWindow", "ID Employ\303\251 :", nullptr));
        labelNom->setText(QCoreApplication::translate("MainWindow", "Nom :", nullptr));
        lineEditNom->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le nom", nullptr));
        labelPoste->setText(QCoreApplication::translate("MainWindow", "Poste :", nullptr));
        lineEditPoste->setPlaceholderText(QCoreApplication::translate("MainWindow", "Entrez le poste", nullptr));
        labelSalaire->setText(QCoreApplication::translate("MainWindow", "Salaire :", nullptr));
        labelDispo->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251 :", nullptr));
        comboBoxDispo->setItemText(0, QCoreApplication::translate("MainWindow", "disponible", nullptr));
        comboBoxDispo->setItemText(1, QCoreApplication::translate("MainWindow", "en cong\303\251", nullptr));
        comboBoxDispo->setItemText(2, QCoreApplication::translate("MainWindow", "absent", nullptr));

        tabWidget->setTabText(tabWidget->indexOf(tabConsulter), QCoreApplication::translate("MainWindow", "Consulter", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("MainWindow", "Actions", nullptr));
        btnAjouter->setText(QCoreApplication::translate("MainWindow", "+ Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        btnAfficherTout1->setText(QCoreApplication::translate("MainWindow", "Afficher Tout", nullptr));
        btnVider->setText(QCoreApplication::translate("MainWindow", "Vider", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetEmployes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID Employ\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetEmployes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetEmployes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "Poste", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetEmployes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Salaire", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetEmployes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Disponibilit\303\251", nullptr));
        groupBoxExport->setTitle(QCoreApplication::translate("MainWindow", "Exporter la Liste des Employ\303\251s", nullptr));
        labelExportInfo->setText(QCoreApplication::translate("MainWindow", "Choisissez le format d'exportation de la liste des employ\303\251s :", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("MainWindow", "Exporter en PDF", nullptr));
        groupBoxExportOptions->setTitle(QCoreApplication::translate("MainWindow", "Options d'exportation", nullptr));
        checkBoxInclureEntete->setText(QCoreApplication::translate("MainWindow", "Inclure l'en-t\303\252te", nullptr));
        checkBoxDateExport->setText(QCoreApplication::translate("MainWindow", "Inclure la date d'exportation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("MainWindow", "Affichage", nullptr));
        groupBoxStats->setTitle(QCoreApplication::translate("MainWindow", "Statistiques G\303\251n\303\251rales", nullptr));
        labelTotalEmployes->setText(QCoreApplication::translate("MainWindow", "Nombre total d'employ\303\251s :", nullptr));
        labelTotalEmployesValeur->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        btnActualiserStats->setText(QCoreApplication::translate("MainWindow", "Actualiser les Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("MainWindow", "Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
