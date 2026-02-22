/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QDate>
#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
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
    QVBoxLayout *verticalLayout;
    QLabel *labelHeader;
    QLabel *labelAlerte;
    QTabWidget *tabWidget;
    QWidget *tabGestion;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBoxForm;
    QGridLayout *gridLayout;
    QLabel *label_ID;
    QLineEdit *txtID;
    QLabel *label_Date;
    QDateEdit *dateCommande;
    QLabel *label_Details;
    QTextEdit *txtDetails;
    QLabel *label_Dimensions;
    QHBoxLayout *horizontalLayout_2;
    QSpinBox *spinLongueur;
    QLabel *label_x1;
    QSpinBox *spinLargeur;
    QLabel *label_x2;
    QSpinBox *spinHauteur;
    QLabel *label_Prix;
    QDoubleSpinBox *spinPrix;
    QLabel *label_Etat;
    QComboBox *comboEtat;
    QLabel *label_Responsable;
    QComboBox *comboResponsable;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnVider;
    QGroupBox *groupBoxListe;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableCommandes;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnTriPrixCroissant;
    QPushButton *btnTriPrixDecroissant;
    QSpacerItem *horizontalSpacer;
    QLabel *labelTotal;
    QWidget *tabRecherche;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBoxRecherche;
    QGridLayout *gridLayout_2;
    QLabel *label_RecherchePar;
    QComboBox *comboCritere;
    QLabel *label_Valeur;
    QLineEdit *txtRecherche;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *btnRechercher;
    QPushButton *btnResetRecherche;
    QGroupBox *groupBoxMetiers;
    QGridLayout *gridLayout_3;
    QLabel *label_Delai;
    QLabel *valueDelai;
    QLabel *label_Charge;
    QProgressBar *progressCharge;
    QLabel *label_Alertes;
    QLabel *valueAlertes;
    QGroupBox *groupBoxResultats;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *tableResultats;
    QWidget *tabStats;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupBoxStats;
    QVBoxLayout *verticalLayout_9;
    QTableWidget *tableStatsMois;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *btnGenererStats;
    QWidget *tabFacture;
    QVBoxLayout *verticalLayout_11;
    QGroupBox *groupBoxFacture;
    QGridLayout *gridLayout_4;
    QLabel *label_SelectCommande;
    QComboBox *comboFactureCommande;
    QLabel *label_ClientInfo;
    QTextEdit *txtClientInfo;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *btnGenererPDF;
    QPushButton *btnApercuPDF;
    QSpacerItem *horizontalSpacer_3;
    QGroupBox *groupBoxPreview;
    QVBoxLayout *verticalLayout_12;
    QLabel *labelPreview;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1225, 808);
        MainWindow->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow { background-color: #F5EBE0; }\n"
"    QWidget { background-color: #F5EBE0; color: #3D2817; font-family: 'Segoe UI', Arial, sans-serif; }\n"
"    QTabWidget::pane { border: 2px solid #8B5A2B; background-color: #F5EBE0; border-radius: 5px; }\n"
"    QTabBar::tab { background-color: #C9B59A; color: #3D2817; padding: 10px 20px; margin-right: 2px; border-top-left-radius: 5px; border-top-right-radius: 5px; font-weight: bold; }\n"
"    QTabBar::tab:selected { background-color: #8B5A2B; color: #F5EBE0; }\n"
"    QTabBar::tab:hover { background-color: #9B8068; }\n"
"    QGroupBox { background-color: #FFFFFF; border: 2px solid #8B5A2B; border-radius: 8px; margin-top: 15px; padding-top: 15px; font-weight: bold; }\n"
"    QGroupBox::title { color: #5D4037; subcontrol-origin: margin; left: 10px; padding: 0 5px; font-size: 10pt; }\n"
"    QLineEdit, QTextEdit, QDateEdit, QComboBox, QSpinBox, QDoubleSpinBox { background-color: #FFFFFF; border: 2px solid #C9B59A; border-radius: 5px; padding: 8px; color: "
                        "#3D2817; font-size: 10pt; }\n"
"    QLineEdit:focus, QTextEdit:focus, QDateEdit:focus, QComboBox:focus, QSpinBox:focus, QDoubleSpinBox:focus { border: 2px solid #8B5A2B; }\n"
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
"    QPushButton#btnSupprime"
                        "r { background-color: #5D4037; }\n"
"    QPushButton#btnSupprimer:hover { background-color: #6D4C41; }\n"
"    QPushButton#btnVider, QPushButton#btnRechercher, QPushButton#btnResetRecherche, QPushButton#btnTriPrixCroissant, QPushButton#btnTriPrixDecroissant, QPushButton#btnGenererStats { background-color: #C9B59A; color: #3D2817; }\n"
"    QPushButton#btnVider:hover, QPushButton#btnRechercher:hover, QPushButton#btnResetRecherche:hover, QPushButton#btnTriPrixCroissant:hover, QPushButton#btnTriPrixDecroissant:hover, QPushButton#btnGenererStats:hover { background-color: #D9C5AA; }\n"
"    QTableWidget { background-color: #FFFFFF; alternate-background-color: #F5EBE0; border: 2px solid #C9B59A; border-radius: 5px; gridline-color: #C9B59A; color: #3D2817; }\n"
"    QTableWidget::item:selected { background-color: #8B5A2B; color: #F5EBE0; }\n"
"    QHeaderView::section { background-color: #8B5A2B; color: #F5EBE0; padding: 6px; border: none; font-weight: bold; font-size: 10pt; }\n"
"    QLabel#headerTitle { font-size: "
                        "22px; font-weight: bold; color: #3D2817; padding: 15px; background-color: #C9B59A; border-radius: 8px; margin: 10px; border: 2px solid #8B5A2B; }\n"
"    QLabel#alerteLabel { background-color: #FFF3CD; color: #856404; padding: 10px; border-radius: 5px; border: 1px solid #FFEAA7; font-weight: bold; }\n"
"    QProgressBar { border: 2px solid #C9B59A; border-radius: 5px; text-align: center; background-color: #FFFFFF; color: #3D2817; }\n"
"    QProgressBar::chunk { background-color: #8B9B6A; border-radius: 3px; }\n"
"    QPushButton#btnGenererPDF, QPushButton#btnApercuPDF, QPushButton#btnEnvoyerEmail { background-color: #8B9B6A; }\n"
"    QPushButton#btnGenererPDF:hover, QPushButton#btnApercuPDF:hover, QPushButton#btnEnvoyerEmail:hover { background-color: #9BAB7A; }\n"
"  "));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName("verticalLayout");
        labelHeader = new QLabel(centralwidget);
        labelHeader->setObjectName("labelHeader");
        labelHeader->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelHeader);

        labelAlerte = new QLabel(centralwidget);
        labelAlerte->setObjectName("labelAlerte");
        labelAlerte->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelAlerte);

        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabGestion = new QWidget();
        tabGestion->setObjectName("tabGestion");
        horizontalLayout = new QHBoxLayout(tabGestion);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBoxForm = new QGroupBox(tabGestion);
        groupBoxForm->setObjectName("groupBoxForm");
        gridLayout = new QGridLayout(groupBoxForm);
        gridLayout->setObjectName("gridLayout");
        label_ID = new QLabel(groupBoxForm);
        label_ID->setObjectName("label_ID");

        gridLayout->addWidget(label_ID, 0, 0, 1, 1);

        txtID = new QLineEdit(groupBoxForm);
        txtID->setObjectName("txtID");

        gridLayout->addWidget(txtID, 0, 1, 1, 1);

        label_Date = new QLabel(groupBoxForm);
        label_Date->setObjectName("label_Date");

        gridLayout->addWidget(label_Date, 1, 0, 1, 1);

        dateCommande = new QDateEdit(groupBoxForm);
        dateCommande->setObjectName("dateCommande");
        dateCommande->setCalendarPopup(true);
        dateCommande->setDate(QDate(2025, 2, 16));

        gridLayout->addWidget(dateCommande, 1, 1, 1, 1);

        label_Details = new QLabel(groupBoxForm);
        label_Details->setObjectName("label_Details");

        gridLayout->addWidget(label_Details, 2, 0, 1, 1);

        txtDetails = new QTextEdit(groupBoxForm);
        txtDetails->setObjectName("txtDetails");

        gridLayout->addWidget(txtDetails, 2, 1, 1, 1);

        label_Dimensions = new QLabel(groupBoxForm);
        label_Dimensions->setObjectName("label_Dimensions");

        gridLayout->addWidget(label_Dimensions, 3, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        spinLongueur = new QSpinBox(groupBoxForm);
        spinLongueur->setObjectName("spinLongueur");
        spinLongueur->setMaximum(1000);
        spinLongueur->setValue(60);

        horizontalLayout_2->addWidget(spinLongueur);

        label_x1 = new QLabel(groupBoxForm);
        label_x1->setObjectName("label_x1");

        horizontalLayout_2->addWidget(label_x1);

        spinLargeur = new QSpinBox(groupBoxForm);
        spinLargeur->setObjectName("spinLargeur");
        spinLargeur->setMaximum(1000);
        spinLargeur->setValue(40);

        horizontalLayout_2->addWidget(spinLargeur);

        label_x2 = new QLabel(groupBoxForm);
        label_x2->setObjectName("label_x2");

        horizontalLayout_2->addWidget(label_x2);

        spinHauteur = new QSpinBox(groupBoxForm);
        spinHauteur->setObjectName("spinHauteur");
        spinHauteur->setMaximum(1000);
        spinHauteur->setValue(55);

        horizontalLayout_2->addWidget(spinHauteur);


        gridLayout->addLayout(horizontalLayout_2, 3, 1, 1, 1);

        label_Prix = new QLabel(groupBoxForm);
        label_Prix->setObjectName("label_Prix");

        gridLayout->addWidget(label_Prix, 4, 0, 1, 1);

        spinPrix = new QDoubleSpinBox(groupBoxForm);
        spinPrix->setObjectName("spinPrix");
        spinPrix->setMaximum(100000.000000000000000);
        spinPrix->setSingleStep(50.000000000000000);
        spinPrix->setValue(180.000000000000000);

        gridLayout->addWidget(spinPrix, 4, 1, 1, 1);

        label_Etat = new QLabel(groupBoxForm);
        label_Etat->setObjectName("label_Etat");

        gridLayout->addWidget(label_Etat, 5, 0, 1, 1);

        comboEtat = new QComboBox(groupBoxForm);
        comboEtat->addItem(QString());
        comboEtat->addItem(QString());
        comboEtat->addItem(QString());
        comboEtat->setObjectName("comboEtat");

        gridLayout->addWidget(comboEtat, 5, 1, 1, 1);

        label_Responsable = new QLabel(groupBoxForm);
        label_Responsable->setObjectName("label_Responsable");

        gridLayout->addWidget(label_Responsable, 6, 0, 1, 1);

        comboResponsable = new QComboBox(groupBoxForm);
        comboResponsable->addItem(QString());
        comboResponsable->addItem(QString());
        comboResponsable->addItem(QString());
        comboResponsable->setObjectName("comboResponsable");

        gridLayout->addWidget(comboResponsable, 6, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        btnAjouter = new QPushButton(groupBoxForm);
        btnAjouter->setObjectName("btnAjouter");

        horizontalLayout_3->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxForm);
        btnModifier->setObjectName("btnModifier");

        horizontalLayout_3->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxForm);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayout_3->addWidget(btnSupprimer);

        btnVider = new QPushButton(groupBoxForm);
        btnVider->setObjectName("btnVider");

        horizontalLayout_3->addWidget(btnVider);


        gridLayout->addLayout(horizontalLayout_3, 7, 0, 1, 2);


        horizontalLayout->addWidget(groupBoxForm);

        groupBoxListe = new QGroupBox(tabGestion);
        groupBoxListe->setObjectName("groupBoxListe");
        verticalLayout_6 = new QVBoxLayout(groupBoxListe);
        verticalLayout_6->setObjectName("verticalLayout_6");
        tableCommandes = new QTableWidget(groupBoxListe);
        if (tableCommandes->columnCount() < 7)
            tableCommandes->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableCommandes->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        if (tableCommandes->rowCount() < 4)
            tableCommandes->setRowCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableCommandes->setVerticalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableCommandes->setVerticalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableCommandes->setVerticalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableCommandes->setVerticalHeaderItem(3, __qtablewidgetitem10);
        tableCommandes->setObjectName("tableCommandes");
        tableCommandes->setEditTriggers(QAbstractItemView::EditTrigger::DoubleClicked|QAbstractItemView::EditTrigger::EditKeyPressed|QAbstractItemView::EditTrigger::SelectedClicked);
        tableCommandes->setAlternatingRowColors(true);
        tableCommandes->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);
        tableCommandes->setRowCount(4);
        tableCommandes->setColumnCount(7);
        tableCommandes->horizontalHeader()->setVisible(true);
        tableCommandes->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_6->addWidget(tableCommandes);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnTriPrixCroissant = new QPushButton(groupBoxListe);
        btnTriPrixCroissant->setObjectName("btnTriPrixCroissant");

        horizontalLayout_4->addWidget(btnTriPrixCroissant);

        btnTriPrixDecroissant = new QPushButton(groupBoxListe);
        btnTriPrixDecroissant->setObjectName("btnTriPrixDecroissant");

        horizontalLayout_4->addWidget(btnTriPrixDecroissant);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer);

        labelTotal = new QLabel(groupBoxListe);
        labelTotal->setObjectName("labelTotal");
        labelTotal->setAlignment(Qt::AlignmentFlag::AlignRight|Qt::AlignmentFlag::AlignTrailing|Qt::AlignmentFlag::AlignVCenter);

        horizontalLayout_4->addWidget(labelTotal);


        verticalLayout_6->addLayout(horizontalLayout_4);


        horizontalLayout->addWidget(groupBoxListe);

        tabWidget->addTab(tabGestion, QString());
        tabRecherche = new QWidget();
        tabRecherche->setObjectName("tabRecherche");
        verticalLayout_7 = new QVBoxLayout(tabRecherche);
        verticalLayout_7->setObjectName("verticalLayout_7");
        groupBoxRecherche = new QGroupBox(tabRecherche);
        groupBoxRecherche->setObjectName("groupBoxRecherche");
        gridLayout_2 = new QGridLayout(groupBoxRecherche);
        gridLayout_2->setObjectName("gridLayout_2");
        label_RecherchePar = new QLabel(groupBoxRecherche);
        label_RecherchePar->setObjectName("label_RecherchePar");

        gridLayout_2->addWidget(label_RecherchePar, 0, 0, 1, 1);

        comboCritere = new QComboBox(groupBoxRecherche);
        comboCritere->addItem(QString());
        comboCritere->addItem(QString());
        comboCritere->setObjectName("comboCritere");

        gridLayout_2->addWidget(comboCritere, 0, 1, 1, 1);

        label_Valeur = new QLabel(groupBoxRecherche);
        label_Valeur->setObjectName("label_Valeur");

        gridLayout_2->addWidget(label_Valeur, 1, 0, 1, 1);

        txtRecherche = new QLineEdit(groupBoxRecherche);
        txtRecherche->setObjectName("txtRecherche");

        gridLayout_2->addWidget(txtRecherche, 1, 1, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        btnRechercher = new QPushButton(groupBoxRecherche);
        btnRechercher->setObjectName("btnRechercher");

        horizontalLayout_5->addWidget(btnRechercher);

        btnResetRecherche = new QPushButton(groupBoxRecherche);
        btnResetRecherche->setObjectName("btnResetRecherche");

        horizontalLayout_5->addWidget(btnResetRecherche);


        gridLayout_2->addLayout(horizontalLayout_5, 2, 0, 1, 2);


        verticalLayout_7->addWidget(groupBoxRecherche);

        groupBoxMetiers = new QGroupBox(tabRecherche);
        groupBoxMetiers->setObjectName("groupBoxMetiers");
        gridLayout_3 = new QGridLayout(groupBoxMetiers);
        gridLayout_3->setObjectName("gridLayout_3");
        label_Delai = new QLabel(groupBoxMetiers);
        label_Delai->setObjectName("label_Delai");

        gridLayout_3->addWidget(label_Delai, 0, 0, 1, 1);

        valueDelai = new QLabel(groupBoxMetiers);
        valueDelai->setObjectName("valueDelai");

        gridLayout_3->addWidget(valueDelai, 0, 1, 1, 1);

        label_Charge = new QLabel(groupBoxMetiers);
        label_Charge->setObjectName("label_Charge");

        gridLayout_3->addWidget(label_Charge, 1, 0, 1, 1);

        progressCharge = new QProgressBar(groupBoxMetiers);
        progressCharge->setObjectName("progressCharge");
        progressCharge->setValue(75);

        gridLayout_3->addWidget(progressCharge, 1, 1, 1, 1);

        label_Alertes = new QLabel(groupBoxMetiers);
        label_Alertes->setObjectName("label_Alertes");

        gridLayout_3->addWidget(label_Alertes, 2, 0, 1, 1);

        valueAlertes = new QLabel(groupBoxMetiers);
        valueAlertes->setObjectName("valueAlertes");

        gridLayout_3->addWidget(valueAlertes, 2, 1, 1, 1);


        verticalLayout_7->addWidget(groupBoxMetiers);

        groupBoxResultats = new QGroupBox(tabRecherche);
        groupBoxResultats->setObjectName("groupBoxResultats");
        verticalLayout_10 = new QVBoxLayout(groupBoxResultats);
        verticalLayout_10->setObjectName("verticalLayout_10");
        tableResultats = new QTableWidget(groupBoxResultats);
        if (tableResultats->columnCount() < 6)
            tableResultats->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableResultats->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableResultats->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableResultats->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableResultats->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableResultats->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableResultats->setHorizontalHeaderItem(5, __qtablewidgetitem16);
        tableResultats->setObjectName("tableResultats");

        verticalLayout_10->addWidget(tableResultats);


        verticalLayout_7->addWidget(groupBoxResultats);

        tabWidget->addTab(tabRecherche, QString());
        tabStats = new QWidget();
        tabStats->setObjectName("tabStats");
        verticalLayout_8 = new QVBoxLayout(tabStats);
        verticalLayout_8->setObjectName("verticalLayout_8");
        groupBoxStats = new QGroupBox(tabStats);
        groupBoxStats->setObjectName("groupBoxStats");
        verticalLayout_9 = new QVBoxLayout(groupBoxStats);
        verticalLayout_9->setObjectName("verticalLayout_9");
        tableStatsMois = new QTableWidget(groupBoxStats);
        if (tableStatsMois->columnCount() < 2)
            tableStatsMois->setColumnCount(2);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableStatsMois->setHorizontalHeaderItem(0, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableStatsMois->setHorizontalHeaderItem(1, __qtablewidgetitem18);
        if (tableStatsMois->rowCount() < 12)
            tableStatsMois->setRowCount(12);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(5, __qtablewidgetitem24);
        QTableWidgetItem *__qtablewidgetitem25 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(6, __qtablewidgetitem25);
        QTableWidgetItem *__qtablewidgetitem26 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(7, __qtablewidgetitem26);
        QTableWidgetItem *__qtablewidgetitem27 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(8, __qtablewidgetitem27);
        QTableWidgetItem *__qtablewidgetitem28 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(9, __qtablewidgetitem28);
        QTableWidgetItem *__qtablewidgetitem29 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(10, __qtablewidgetitem29);
        QTableWidgetItem *__qtablewidgetitem30 = new QTableWidgetItem();
        tableStatsMois->setVerticalHeaderItem(11, __qtablewidgetitem30);
        tableStatsMois->setObjectName("tableStatsMois");
        tableStatsMois->setAlternatingRowColors(true);
        tableStatsMois->setRowCount(12);
        tableStatsMois->setColumnCount(2);
        tableStatsMois->horizontalHeader()->setVisible(true);
        tableStatsMois->horizontalHeader()->setStretchLastSection(true);

        verticalLayout_9->addWidget(tableStatsMois);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        btnGenererStats = new QPushButton(groupBoxStats);
        btnGenererStats->setObjectName("btnGenererStats");

        horizontalLayout_6->addWidget(btnGenererStats);


        verticalLayout_9->addLayout(horizontalLayout_6);


        verticalLayout_8->addWidget(groupBoxStats);

        tabWidget->addTab(tabStats, QString());
        tabFacture = new QWidget();
        tabFacture->setObjectName("tabFacture");
        verticalLayout_11 = new QVBoxLayout(tabFacture);
        verticalLayout_11->setObjectName("verticalLayout_11");
        groupBoxFacture = new QGroupBox(tabFacture);
        groupBoxFacture->setObjectName("groupBoxFacture");
        gridLayout_4 = new QGridLayout(groupBoxFacture);
        gridLayout_4->setObjectName("gridLayout_4");
        label_SelectCommande = new QLabel(groupBoxFacture);
        label_SelectCommande->setObjectName("label_SelectCommande");

        gridLayout_4->addWidget(label_SelectCommande, 0, 0, 1, 1);

        comboFactureCommande = new QComboBox(groupBoxFacture);
        comboFactureCommande->addItem(QString());
        comboFactureCommande->addItem(QString());
        comboFactureCommande->addItem(QString());
        comboFactureCommande->addItem(QString());
        comboFactureCommande->setObjectName("comboFactureCommande");

        gridLayout_4->addWidget(comboFactureCommande, 0, 1, 1, 1);

        label_ClientInfo = new QLabel(groupBoxFacture);
        label_ClientInfo->setObjectName("label_ClientInfo");

        gridLayout_4->addWidget(label_ClientInfo, 1, 0, 1, 1);

        txtClientInfo = new QTextEdit(groupBoxFacture);
        txtClientInfo->setObjectName("txtClientInfo");

        gridLayout_4->addWidget(txtClientInfo, 1, 1, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        btnGenererPDF = new QPushButton(groupBoxFacture);
        btnGenererPDF->setObjectName("btnGenererPDF");

        horizontalLayout_7->addWidget(btnGenererPDF);

        btnApercuPDF = new QPushButton(groupBoxFacture);
        btnApercuPDF->setObjectName("btnApercuPDF");

        horizontalLayout_7->addWidget(btnApercuPDF);

        horizontalSpacer_3 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_7->addItem(horizontalSpacer_3);


        gridLayout_4->addLayout(horizontalLayout_7, 2, 0, 1, 2);


        verticalLayout_11->addWidget(groupBoxFacture);

        groupBoxPreview = new QGroupBox(tabFacture);
        groupBoxPreview->setObjectName("groupBoxPreview");
        verticalLayout_12 = new QVBoxLayout(groupBoxPreview);
        verticalLayout_12->setObjectName("verticalLayout_12");
        labelPreview = new QLabel(groupBoxPreview);
        labelPreview->setObjectName("labelPreview");
        labelPreview->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_12->addWidget(labelPreview);


        verticalLayout_11->addWidget(groupBoxPreview);

        tabWidget->addTab(tabFacture, QString());

        verticalLayout->addWidget(tabWidget);

        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Smart Carpentry - Gestion des Commandes", nullptr));
        labelHeader->setText(QCoreApplication::translate("MainWindow", "\360\237\223\246 GESTION DES COMMANDES - SMART CARPENTRY WORKSHOP", nullptr));
        labelAlerte->setText(QCoreApplication::translate("MainWindow", "\342\232\240\357\270\217 ALERTE: 2 commandes en retard de livraison", nullptr));
        groupBoxForm->setTitle(QCoreApplication::translate("MainWindow", "Informations Commande", nullptr));
        label_ID->setText(QCoreApplication::translate("MainWindow", "ID Commande:", nullptr));
        txtID->setText(QCoreApplication::translate("MainWindow", "CMD-004", nullptr));
        label_Date->setText(QCoreApplication::translate("MainWindow", "Date:", nullptr));
        label_Details->setText(QCoreApplication::translate("MainWindow", "D\303\251tails:", nullptr));
        txtDetails->setPlainText(QCoreApplication::translate("MainWindow", "Table de chevet en ch\303\252ne", nullptr));
        label_Dimensions->setText(QCoreApplication::translate("MainWindow", "Dimensions (L\303\227l\303\227H):", nullptr));
        spinLongueur->setSuffix(QCoreApplication::translate("MainWindow", " cm", nullptr));
        label_x1->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        spinLargeur->setSuffix(QCoreApplication::translate("MainWindow", " cm", nullptr));
        label_x2->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
        spinHauteur->setSuffix(QCoreApplication::translate("MainWindow", " cm", nullptr));
        label_Prix->setText(QCoreApplication::translate("MainWindow", "Prix (\342\202\254):", nullptr));
        spinPrix->setPrefix(QCoreApplication::translate("MainWindow", "\342\202\254 ", nullptr));
        label_Etat->setText(QCoreApplication::translate("MainWindow", "\303\211tat:", nullptr));
        comboEtat->setItemText(0, QCoreApplication::translate("MainWindow", "\360\237\237\241 En cours", nullptr));
        comboEtat->setItemText(1, QCoreApplication::translate("MainWindow", "\360\237\237\242 Termin\303\251e", nullptr));
        comboEtat->setItemText(2, QCoreApplication::translate("MainWindow", "\360\237\224\265 Livr\303\251e", nullptr));

        label_Responsable->setText(QCoreApplication::translate("MainWindow", "Responsable:", nullptr));
        comboResponsable->setItemText(0, QCoreApplication::translate("MainWindow", "Jean Martin", nullptr));
        comboResponsable->setItemText(1, QCoreApplication::translate("MainWindow", "Marie Dubois", nullptr));
        comboResponsable->setItemText(2, QCoreApplication::translate("MainWindow", "Pierre Lambert", nullptr));

        btnAjouter->setText(QCoreApplication::translate("MainWindow", "\342\236\225 Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("MainWindow", "\342\234\217\357\270\217 Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("MainWindow", "\360\237\227\221\357\270\217 Supprimer", nullptr));
        btnVider->setText(QCoreApplication::translate("MainWindow", "\360\237\247\271 Vider", nullptr));
        groupBoxListe->setTitle(QCoreApplication::translate("MainWindow", "Liste des Commandes", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableCommandes->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableCommandes->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableCommandes->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("MainWindow", "D\303\251tails", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableCommandes->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("MainWindow", "Dimensions", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableCommandes->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableCommandes->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableCommandes->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("MainWindow", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableCommandes->verticalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("MainWindow", "Jean Martin", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableCommandes->verticalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("MainWindow", "Marie Dubois", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableCommandes->verticalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("MainWindow", "Pierre Lambert", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableCommandes->verticalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("MainWindow", "Jean Martin", nullptr));
        btnTriPrixCroissant->setText(QCoreApplication::translate("MainWindow", "\360\237\222\260 Tri Prix Croissant", nullptr));
        btnTriPrixDecroissant->setText(QCoreApplication::translate("MainWindow", "\360\237\222\260 Tri Prix D\303\251croissant", nullptr));
        labelTotal->setText(QCoreApplication::translate("MainWindow", "Total: \342\202\254 1,600.00", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QCoreApplication::translate("MainWindow", "\360\237\223\213 Gestion de Commande", nullptr));
        groupBoxRecherche->setTitle(QCoreApplication::translate("MainWindow", "Recherche Avanc\303\251e", nullptr));
        label_RecherchePar->setText(QCoreApplication::translate("MainWindow", "Rechercher par:", nullptr));
        comboCritere->setItemText(0, QCoreApplication::translate("MainWindow", "Date", nullptr));
        comboCritere->setItemText(1, QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));

        label_Valeur->setText(QCoreApplication::translate("MainWindow", "Valeur:", nullptr));
        txtRecherche->setPlaceholderText(QCoreApplication::translate("MainWindow", "Saisir la valeur de recherche...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("MainWindow", "\360\237\224\215 Rechercher", nullptr));
        btnResetRecherche->setText(QCoreApplication::translate("MainWindow", "\360\237\224\204 R\303\251initialiser", nullptr));
        groupBoxMetiers->setTitle(QCoreApplication::translate("MainWindow", "\360\237\232\200 M\303\251tiers Innovants", nullptr));
        label_Delai->setText(QCoreApplication::translate("MainWindow", "Estimation intelligente du d\303\251lai:", nullptr));
        valueDelai->setText(QCoreApplication::translate("MainWindow", "\342\217\261\357\270\217 5-7 jours", nullptr));
        label_Charge->setText(QCoreApplication::translate("MainWindow", "Charge actuelle:", nullptr));
        label_Alertes->setText(QCoreApplication::translate("MainWindow", "Alertes retards:", nullptr));
        valueAlertes->setText(QCoreApplication::translate("MainWindow", "\360\237\224\264 2 commandes en retard", nullptr));
        groupBoxResultats->setTitle(QCoreApplication::translate("MainWindow", "R\303\251sultats de Recherche", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableResultats->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("MainWindow", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableResultats->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("MainWindow", "Date", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableResultats->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("MainWindow", "D\303\251tails", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableResultats->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("MainWindow", "Prix", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableResultats->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("MainWindow", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableResultats->horizontalHeaderItem(5);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("MainWindow", "Responsable", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabRecherche), QCoreApplication::translate("MainWindow", "\360\237\224\215 Recherche", nullptr));
        groupBoxStats->setTitle(QCoreApplication::translate("MainWindow", "R\303\251partition des commandes par mois", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableStatsMois->horizontalHeaderItem(0);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("MainWindow", "Nombre de commandes", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableStatsMois->horizontalHeaderItem(1);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("MainWindow", "Chiffre d'affaires (\342\202\254)", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableStatsMois->verticalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("MainWindow", "Janvier", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableStatsMois->verticalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("MainWindow", "F\303\251vrier", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableStatsMois->verticalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("MainWindow", "Mars", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableStatsMois->verticalHeaderItem(3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("MainWindow", "Avril", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableStatsMois->verticalHeaderItem(4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("MainWindow", "Mai", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableStatsMois->verticalHeaderItem(5);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("MainWindow", "Juin", nullptr));
        QTableWidgetItem *___qtablewidgetitem25 = tableStatsMois->verticalHeaderItem(6);
        ___qtablewidgetitem25->setText(QCoreApplication::translate("MainWindow", "Juillet", nullptr));
        QTableWidgetItem *___qtablewidgetitem26 = tableStatsMois->verticalHeaderItem(7);
        ___qtablewidgetitem26->setText(QCoreApplication::translate("MainWindow", "Ao\303\273t", nullptr));
        QTableWidgetItem *___qtablewidgetitem27 = tableStatsMois->verticalHeaderItem(8);
        ___qtablewidgetitem27->setText(QCoreApplication::translate("MainWindow", "Septembre", nullptr));
        QTableWidgetItem *___qtablewidgetitem28 = tableStatsMois->verticalHeaderItem(9);
        ___qtablewidgetitem28->setText(QCoreApplication::translate("MainWindow", "Octobre", nullptr));
        QTableWidgetItem *___qtablewidgetitem29 = tableStatsMois->verticalHeaderItem(10);
        ___qtablewidgetitem29->setText(QCoreApplication::translate("MainWindow", "Novembre", nullptr));
        QTableWidgetItem *___qtablewidgetitem30 = tableStatsMois->verticalHeaderItem(11);
        ___qtablewidgetitem30->setText(QCoreApplication::translate("MainWindow", "D\303\251cembre", nullptr));
        btnGenererStats->setText(QCoreApplication::translate("MainWindow", "\360\237\223\212 Actualiser les statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStats), QCoreApplication::translate("MainWindow", "\360\237\223\212 Statistiques", nullptr));
        groupBoxFacture->setTitle(QCoreApplication::translate("MainWindow", "G\303\251n\303\251ration automatique de facture PDF", nullptr));
        label_SelectCommande->setText(QCoreApplication::translate("MainWindow", "S\303\251lectionner une commande:", nullptr));
        comboFactureCommande->setItemText(0, QCoreApplication::translate("MainWindow", "CMD-001 - Table en ch\303\252ne", nullptr));
        comboFactureCommande->setItemText(1, QCoreApplication::translate("MainWindow", "CMD-002 - Biblioth\303\250que", nullptr));
        comboFactureCommande->setItemText(2, QCoreApplication::translate("MainWindow", "CMD-003 - Chaise design", nullptr));
        comboFactureCommande->setItemText(3, QCoreApplication::translate("MainWindow", "CMD-004 - Table de chevet", nullptr));

        label_ClientInfo->setText(QCoreApplication::translate("MainWindow", "Informations client:", nullptr));
        txtClientInfo->setPlaceholderText(QCoreApplication::translate("MainWindow", "Nom, adresse, t\303\251l\303\251phone, email...", nullptr));
        btnGenererPDF->setText(QCoreApplication::translate("MainWindow", "\360\237\223\204 G\303\251n\303\251rer Facture PDF", nullptr));
        btnApercuPDF->setText(QCoreApplication::translate("MainWindow", "\360\237\221\201\357\270\217 Aper\303\247u Facture", nullptr));
        groupBoxPreview->setTitle(QCoreApplication::translate("MainWindow", "Aper\303\247u Facture", nullptr));
        labelPreview->setText(QCoreApplication::translate("MainWindow", "Votre facture PDF sera g\303\251n\303\251r\303\251e ici...", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabFacture), QCoreApplication::translate("MainWindow", "\360\237\247\276 G\303\251n\303\251ration Facture", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
