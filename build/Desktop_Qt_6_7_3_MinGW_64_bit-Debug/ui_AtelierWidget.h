/********************************************************************************
** Form generated from reading UI file 'AtelierWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ATELIERWIDGET_H
#define UI_ATELIERWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AtelierWidget
{
public:
    QVBoxLayout *verticalLayout;
    QFrame *frameHeader;
    QHBoxLayout *horizontalLayout_header;
    QLabel *lblLogo;
    QVBoxLayout *verticalLayout_9;
    QLabel *lblTitre;
    QLabel *lblSousTitre;
    QSpacerItem *horizontalSpacer_header;
    QTabWidget *tabWidget;
    QWidget *tabMachines;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupRecherche;
    QGridLayout *gridLayout;
    QComboBox *comboRechercheType;
    QLabel *label;
    QLabel *label_11;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnAppliquerTri;
    QPushButton *btnReinitialiser;
    QComboBox *comboRechercheEtat;
    QLabel *label_2;
    QComboBox *comboTriPar;
    QGroupBox *groupActions;
    QVBoxLayout *verticalLayout_3;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnExporter;
    QSpacerItem *verticalSpacer;
    QTableWidget *tableMachines;
    QWidget *tabFormulaire;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupFormulaire;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QLineEdit *lineEditID;
    QLabel *label_4;
    QLineEdit *lineEditNom;
    QLabel *label_5;
    QComboBox *comboBoxType;
    QLabel *label_6;
    QComboBox *comboBoxEtat;
    QLabel *label_7;
    QDateEdit *dateEditMaintenance;
    QLabel *label_8;
    QSpinBox *spinBoxHeures;
    QLabel *label_9;
    QLineEdit *lineEditRespMaintenance;
    QLabel *label_10;
    QLineEdit *lineEditRespAtelier;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnEnregistrer;
    QPushButton *btnAnnuler;
    QSpacerItem *verticalSpacer_2;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupStatistiques;
    QGridLayout *gridLayout_3;
    QLabel *lblTotalMachines;
    QLabel *lblMachinesDisponibles;
    QLabel *lblMachinesMaintenance;
    QLabel *lblMachinesHS;
    QGroupBox *groupMachinesCritiques;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableMachinesCritiques;
    QGroupBox *groupMachinesSollicitees;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableMachinesSollicitees;
    QGroupBox *groupPlanificationAuto;
    QHBoxLayout *horizontalLayout_4;
    QPushButton *btnPlanifierMaintenance;
    QPushButton *btnDetecterCritiques;
    QPushButton *btnAnalyserRisques;
    QSpacerItem *horizontalSpacer_2;
    QLabel *lblGraphique;
    QSpacerItem *verticalSpacer_3;

    void setupUi(QWidget *AtelierWidget)
    {
        if (AtelierWidget->objectName().isEmpty())
            AtelierWidget->setObjectName("AtelierWidget");
        AtelierWidget->resize(1400, 903);
        AtelierWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #F5F0E8;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #6B4423;\n"
"    color: #FAF8F3;\n"
"    border: none;\n"
"    padding: 12px 24px;\n"
"    border-radius: 6px;\n"
"    font-weight: 600;\n"
"    font-size: 10pt;\n"
"    min-height: 35px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8B6F47;\n"
"    border: 1px solid #6B4423;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5A3820;\n"
"}\n"
"\n"
"QPushButton:disabled {\n"
"    background-color: #C9B896;\n"
"    color: #9B8B5B;\n"
"}\n"
"\n"
"QPushButton#btnRechercher,\n"
"QPushButton#btnReinitialiser,\n"
"QPushButton#btnExporter {\n"
"    background-color: #9B8B5B;\n"
"    color: #FAF8F3;\n"
"}\n"
"\n"
"QPushButton#btnRechercher:hover,\n"
"QPushButton#btnReinitialiser:hover,\n"
"QPushButton#btnExporter:hover {\n"
"    background-color: #B5A572;\n"
"    border: 1px solid #8B6F47;\n"
"}\n"
"\n"
"QPushButton#btnSupprimer {\n"
"    background-color: #A0522D;\n"
"    color: #FAF8F3;\n"
""
                        "}\n"
"\n"
"QPushButton#btnSupprimer:hover {\n"
"    background-color: #C86432;\n"
"}\n"
"\n"
"QPushButton#btnEnregistrer,\n"
"QPushButton#btnValider {\n"
"    background-color: #6B7B3E;\n"
"}\n"
"\n"
"QPushButton#btnEnregistrer:hover,\n"
"QPushButton#btnValider:hover {\n"
"    background-color: #7E9147;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    background-color: #FAF8F3;\n"
"    border: 2px solid #C9B896;\n"
"    border-radius: 10px;\n"
"    margin-top: 20px;\n"
"    padding-top: 20px;\n"
"    font-weight: 600;\n"
"    font-size: 11pt;\n"
"    color: #6B4423;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 8px 16px;\n"
"    background-color: #6B4423;\n"
"    color: #FAF8F3;\n"
"    border-radius: 5px;\n"
"    left: 10px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #5A3820;\n"
"    font-size: 10pt;\n"
"    font-weight: 500;\n"
"}\n"
"\n"
"QLabel#lblLogo {\n"
"    background-color: transparent;\n"
"    padding: 10px;\n"
"}\n"
"\n"
"QLabel#lblTitre "
                        "{\n"
"    font-size: 24pt;\n"
"    font-weight: 700;\n"
"    color: #6B4423;\n"
"    padding: 15px;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QLabel#lblSousTitre {\n"
"    font-size: 12pt;\n"
"    color: #8B6F47;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QLineEdit, QComboBox, QSpinBox, QDateEdit, QTextEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 2px solid #C9B896;\n"
"    border-radius: 6px;\n"
"    padding: 8px 12px;\n"
"    font-size: 10pt;\n"
"    color: #5A3820;\n"
"    selection-background-color: #9B8B5B;\n"
"    selection-color: #FAF8F3;\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus, QSpinBox:focus, QDateEdit:focus, QTextEdit:focus {\n"
"    border: 2px solid #8B6F47;\n"
"    background-color: #FAF8F3;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: #FFFFFF;\n"
"    alternate-background-color: #FAF8F3;\n"
"    border: 2px solid #C9B896;\n"
"    gridline-color: #E8DCC4;\n"
"    font-size: 10pt;\n"
"    border-radius: 8px;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    paddin"
                        "g: 10px;\n"
"    border-bottom: 1px solid #E8DCC4;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #9B8B5B;\n"
"    color: #FAF8F3;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #6B4423;\n"
"    color: #FAF8F3;\n"
"    padding: 12px 8px;\n"
"    border: none;\n"
"    font-weight: 700;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 2px solid #C9B896;\n"
"    background-color: #F5F0E8;\n"
"    border-radius: 8px;\n"
"    top: -2px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #E8DCC4;\n"
"    color: #5A3820;\n"
"    padding: 12px 25px;\n"
"    margin-right: 3px;\n"
"    border-top-left-radius: 8px;\n"
"    border-top-right-radius: 8px;\n"
"    font-weight: 600;\n"
"    font-size: 10pt;\n"
"    min-width: 120px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #6B4423;\n"
"    color: #FAF8F3;\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(AtelierWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        frameHeader = new QFrame(AtelierWidget);
        frameHeader->setObjectName("frameHeader");
        frameHeader->setStyleSheet(QString::fromUtf8("QFrame#frameHeader {\n"
"    background-color: #6B4423;\n"
"    border-bottom: 3px solid #8B6F47;\n"
"}"));
        frameHeader->setFrameShape(QFrame::StyledPanel);
        horizontalLayout_header = new QHBoxLayout(frameHeader);
        horizontalLayout_header->setSpacing(15);
        horizontalLayout_header->setObjectName("horizontalLayout_header");
        horizontalLayout_header->setContentsMargins(20, 10, 20, 10);
        lblLogo = new QLabel(frameHeader);
        lblLogo->setObjectName("lblLogo");
        lblLogo->setMinimumSize(QSize(80, 80));
        lblLogo->setMaximumSize(QSize(80, 80));
        lblLogo->setScaledContents(true);
        lblLogo->setAlignment(Qt::AlignCenter);

        horizontalLayout_header->addWidget(lblLogo);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(5);
        verticalLayout_9->setObjectName("verticalLayout_9");
        lblTitre = new QLabel(frameHeader);
        lblTitre->setObjectName("lblTitre");
        lblTitre->setStyleSheet(QString::fromUtf8("color: #FAF8F3;"));
        lblTitre->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_9->addWidget(lblTitre);

        lblSousTitre = new QLabel(frameHeader);
        lblSousTitre->setObjectName("lblSousTitre");
        lblSousTitre->setStyleSheet(QString::fromUtf8("color: #E8DCC4; font-size: 11pt;"));
        lblSousTitre->setAlignment(Qt::AlignLeft|Qt::AlignVCenter);

        verticalLayout_9->addWidget(lblSousTitre);


        horizontalLayout_header->addLayout(verticalLayout_9);

        horizontalSpacer_header = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_header->addItem(horizontalSpacer_header);


        verticalLayout->addWidget(frameHeader);

        tabWidget = new QTabWidget(AtelierWidget);
        tabWidget->setObjectName("tabWidget");
        tabMachines = new QWidget();
        tabMachines->setObjectName("tabMachines");
        verticalLayout_2 = new QVBoxLayout(tabMachines);
        verticalLayout_2->setSpacing(15);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(15, 15, 15, 15);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(15);
        horizontalLayout->setObjectName("horizontalLayout");
        groupRecherche = new QGroupBox(tabMachines);
        groupRecherche->setObjectName("groupRecherche");
        gridLayout = new QGridLayout(groupRecherche);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setHorizontalSpacing(15);
        gridLayout->setVerticalSpacing(12);
        gridLayout->setContentsMargins(20, 25, 20, 20);
        comboRechercheType = new QComboBox(groupRecherche);
        comboRechercheType->addItem(QString());
        comboRechercheType->addItem(QString());
        comboRechercheType->addItem(QString());
        comboRechercheType->addItem(QString());
        comboRechercheType->addItem(QString());
        comboRechercheType->addItem(QString());
        comboRechercheType->addItem(QString());
        comboRechercheType->setObjectName("comboRechercheType");

        gridLayout->addWidget(comboRechercheType, 0, 1, 1, 1);

        label = new QLabel(groupRecherche);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

        label_11 = new QLabel(groupRecherche);
        label_11->setObjectName("label_11");

        gridLayout->addWidget(label_11, 2, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(10);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnAppliquerTri = new QPushButton(groupRecherche);
        btnAppliquerTri->setObjectName("btnAppliquerTri");

        horizontalLayout_2->addWidget(btnAppliquerTri);

        btnReinitialiser = new QPushButton(groupRecherche);
        btnReinitialiser->setObjectName("btnReinitialiser");

        horizontalLayout_2->addWidget(btnReinitialiser);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 2);

        comboRechercheEtat = new QComboBox(groupRecherche);
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->setObjectName("comboRechercheEtat");

        gridLayout->addWidget(comboRechercheEtat, 1, 1, 1, 1);

        label_2 = new QLabel(groupRecherche);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboTriPar = new QComboBox(groupRecherche);
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->addItem(QString());
        comboTriPar->setObjectName("comboTriPar");

        gridLayout->addWidget(comboTriPar, 2, 1, 1, 1);


        horizontalLayout->addWidget(groupRecherche);

        groupActions = new QGroupBox(tabMachines);
        groupActions->setObjectName("groupActions");
        verticalLayout_3 = new QVBoxLayout(groupActions);
        verticalLayout_3->setSpacing(12);
        verticalLayout_3->setObjectName("verticalLayout_3");
        verticalLayout_3->setContentsMargins(20, 25, 20, 20);
        btnAjouter = new QPushButton(groupActions);
        btnAjouter->setObjectName("btnAjouter");

        verticalLayout_3->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupActions);
        btnModifier->setObjectName("btnModifier");

        verticalLayout_3->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupActions);
        btnSupprimer->setObjectName("btnSupprimer");

        verticalLayout_3->addWidget(btnSupprimer);

        btnExporter = new QPushButton(groupActions);
        btnExporter->setObjectName("btnExporter");

        verticalLayout_3->addWidget(btnExporter);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addWidget(groupActions);


        verticalLayout_2->addLayout(horizontalLayout);

        tableMachines = new QTableWidget(tabMachines);
        if (tableMachines->columnCount() < 8)
            tableMachines->setColumnCount(8);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableMachines->setHorizontalHeaderItem(7, __qtablewidgetitem7);
        tableMachines->setObjectName("tableMachines");
        tableMachines->setAlternatingRowColors(true);
        tableMachines->setSelectionMode(QAbstractItemView::SingleSelection);
        tableMachines->setSelectionBehavior(QAbstractItemView::SelectRows);
        tableMachines->setSortingEnabled(true);

        verticalLayout_2->addWidget(tableMachines);

        tabWidget->addTab(tabMachines, QString());
        tabFormulaire = new QWidget();
        tabFormulaire->setObjectName("tabFormulaire");
        verticalLayout_4 = new QVBoxLayout(tabFormulaire);
        verticalLayout_4->setSpacing(15);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(15, 15, 15, 15);
        groupFormulaire = new QGroupBox(tabFormulaire);
        groupFormulaire->setObjectName("groupFormulaire");
        gridLayout_2 = new QGridLayout(groupFormulaire);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(20);
        gridLayout_2->setVerticalSpacing(18);
        gridLayout_2->setContentsMargins(30, 30, 30, 30);
        label_3 = new QLabel(groupFormulaire);
        label_3->setObjectName("label_3");

        gridLayout_2->addWidget(label_3, 0, 0, 1, 1);

        lineEditID = new QLineEdit(groupFormulaire);
        lineEditID->setObjectName("lineEditID");
        lineEditID->setReadOnly(true);

        gridLayout_2->addWidget(lineEditID, 0, 1, 1, 1);

        label_4 = new QLabel(groupFormulaire);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 1, 0, 1, 1);

        lineEditNom = new QLineEdit(groupFormulaire);
        lineEditNom->setObjectName("lineEditNom");

        gridLayout_2->addWidget(lineEditNom, 1, 1, 1, 1);

        label_5 = new QLabel(groupFormulaire);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 2, 0, 1, 1);

        comboBoxType = new QComboBox(groupFormulaire);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName("comboBoxType");

        gridLayout_2->addWidget(comboBoxType, 2, 1, 1, 1);

        label_6 = new QLabel(groupFormulaire);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 3, 0, 1, 1);

        comboBoxEtat = new QComboBox(groupFormulaire);
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->setObjectName("comboBoxEtat");

        gridLayout_2->addWidget(comboBoxEtat, 3, 1, 1, 1);

        label_7 = new QLabel(groupFormulaire);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 4, 0, 1, 1);

        dateEditMaintenance = new QDateEdit(groupFormulaire);
        dateEditMaintenance->setObjectName("dateEditMaintenance");
        dateEditMaintenance->setCalendarPopup(true);

        gridLayout_2->addWidget(dateEditMaintenance, 4, 1, 1, 1);

        label_8 = new QLabel(groupFormulaire);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 5, 0, 1, 1);

        spinBoxHeures = new QSpinBox(groupFormulaire);
        spinBoxHeures->setObjectName("spinBoxHeures");
        spinBoxHeures->setMaximum(999999);

        gridLayout_2->addWidget(spinBoxHeures, 5, 1, 1, 1);

        label_9 = new QLabel(groupFormulaire);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 6, 0, 1, 1);

        lineEditRespMaintenance = new QLineEdit(groupFormulaire);
        lineEditRespMaintenance->setObjectName("lineEditRespMaintenance");

        gridLayout_2->addWidget(lineEditRespMaintenance, 6, 1, 1, 1);

        label_10 = new QLabel(groupFormulaire);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 7, 0, 1, 1);

        lineEditRespAtelier = new QLineEdit(groupFormulaire);
        lineEditRespAtelier->setObjectName("lineEditRespAtelier");

        gridLayout_2->addWidget(lineEditRespAtelier, 7, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(15);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnEnregistrer = new QPushButton(groupFormulaire);
        btnEnregistrer->setObjectName("btnEnregistrer");
        btnEnregistrer->setMinimumSize(QSize(150, 59));

        horizontalLayout_3->addWidget(btnEnregistrer);

        btnAnnuler = new QPushButton(groupFormulaire);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setMinimumSize(QSize(150, 59));

        horizontalLayout_3->addWidget(btnAnnuler);


        gridLayout_2->addLayout(horizontalLayout_3, 8, 0, 1, 2);


        verticalLayout_4->addWidget(groupFormulaire);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        tabWidget->addTab(tabFormulaire, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayout_5 = new QVBoxLayout(tabStatistiques);
        verticalLayout_5->setSpacing(15);
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(15, 15, 15, 15);
        groupStatistiques = new QGroupBox(tabStatistiques);
        groupStatistiques->setObjectName("groupStatistiques");
        gridLayout_3 = new QGridLayout(groupStatistiques);
        gridLayout_3->setObjectName("gridLayout_3");
        lblTotalMachines = new QLabel(groupStatistiques);
        lblTotalMachines->setObjectName("lblTotalMachines");

        gridLayout_3->addWidget(lblTotalMachines, 0, 0, 1, 1);

        lblMachinesDisponibles = new QLabel(groupStatistiques);
        lblMachinesDisponibles->setObjectName("lblMachinesDisponibles");

        gridLayout_3->addWidget(lblMachinesDisponibles, 0, 1, 1, 1);

        lblMachinesMaintenance = new QLabel(groupStatistiques);
        lblMachinesMaintenance->setObjectName("lblMachinesMaintenance");

        gridLayout_3->addWidget(lblMachinesMaintenance, 1, 0, 1, 1);

        lblMachinesHS = new QLabel(groupStatistiques);
        lblMachinesHS->setObjectName("lblMachinesHS");

        gridLayout_3->addWidget(lblMachinesHS, 1, 1, 1, 1);


        verticalLayout_5->addWidget(groupStatistiques);

        groupMachinesCritiques = new QGroupBox(tabStatistiques);
        groupMachinesCritiques->setObjectName("groupMachinesCritiques");
        verticalLayout_6 = new QVBoxLayout(groupMachinesCritiques);
        verticalLayout_6->setObjectName("verticalLayout_6");
        tableMachinesCritiques = new QTableWidget(groupMachinesCritiques);
        if (tableMachinesCritiques->columnCount() < 5)
            tableMachinesCritiques->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableMachinesCritiques->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableMachinesCritiques->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableMachinesCritiques->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableMachinesCritiques->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableMachinesCritiques->setHorizontalHeaderItem(4, __qtablewidgetitem12);
        tableMachinesCritiques->setObjectName("tableMachinesCritiques");
        tableMachinesCritiques->setAlternatingRowColors(true);

        verticalLayout_6->addWidget(tableMachinesCritiques);


        verticalLayout_5->addWidget(groupMachinesCritiques);

        groupMachinesSollicitees = new QGroupBox(tabStatistiques);
        groupMachinesSollicitees->setObjectName("groupMachinesSollicitees");
        verticalLayout_7 = new QVBoxLayout(groupMachinesSollicitees);
        verticalLayout_7->setObjectName("verticalLayout_7");
        tableMachinesSollicitees = new QTableWidget(groupMachinesSollicitees);
        if (tableMachinesSollicitees->columnCount() < 5)
            tableMachinesSollicitees->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableMachinesSollicitees->setHorizontalHeaderItem(0, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableMachinesSollicitees->setHorizontalHeaderItem(1, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableMachinesSollicitees->setHorizontalHeaderItem(2, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableMachinesSollicitees->setHorizontalHeaderItem(3, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableMachinesSollicitees->setHorizontalHeaderItem(4, __qtablewidgetitem17);
        tableMachinesSollicitees->setObjectName("tableMachinesSollicitees");
        tableMachinesSollicitees->setAlternatingRowColors(true);

        verticalLayout_7->addWidget(tableMachinesSollicitees);


        verticalLayout_5->addWidget(groupMachinesSollicitees);

        groupPlanificationAuto = new QGroupBox(tabStatistiques);
        groupPlanificationAuto->setObjectName("groupPlanificationAuto");
        horizontalLayout_4 = new QHBoxLayout(groupPlanificationAuto);
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        btnPlanifierMaintenance = new QPushButton(groupPlanificationAuto);
        btnPlanifierMaintenance->setObjectName("btnPlanifierMaintenance");

        horizontalLayout_4->addWidget(btnPlanifierMaintenance);

        btnDetecterCritiques = new QPushButton(groupPlanificationAuto);
        btnDetecterCritiques->setObjectName("btnDetecterCritiques");

        horizontalLayout_4->addWidget(btnDetecterCritiques);

        btnAnalyserRisques = new QPushButton(groupPlanificationAuto);
        btnAnalyserRisques->setObjectName("btnAnalyserRisques");

        horizontalLayout_4->addWidget(btnAnalyserRisques);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        verticalLayout_5->addWidget(groupPlanificationAuto);

        lblGraphique = new QLabel(tabStatistiques);
        lblGraphique->setObjectName("lblGraphique");
        lblGraphique->setAlignment(Qt::AlignCenter);

        verticalLayout_5->addWidget(lblGraphique);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_5->addItem(verticalSpacer_3);

        tabWidget->addTab(tabStatistiques, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(AtelierWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AtelierWidget);
    } // setupUi

    void retranslateUi(QWidget *AtelierWidget)
    {
        lblLogo->setText(QString());
        lblTitre->setText(QCoreApplication::translate("AtelierWidget", "SYST\303\210ME DE GESTION D'ATELIER", nullptr));
        lblSousTitre->setText(QCoreApplication::translate("AtelierWidget", "Production Menuiserie - Gestion des Machines et Maintenance", nullptr));
        groupRecherche->setTitle(QCoreApplication::translate("AtelierWidget", " Filtres de Recherche", nullptr));
        comboRechercheType->setItemText(0, QCoreApplication::translate("AtelierWidget", "-- Tous les types --", nullptr));
        comboRechercheType->setItemText(1, QCoreApplication::translate("AtelierWidget", "Scie", nullptr));
        comboRechercheType->setItemText(2, QCoreApplication::translate("AtelierWidget", "Perceuse", nullptr));
        comboRechercheType->setItemText(3, QCoreApplication::translate("AtelierWidget", "Raboteuse", nullptr));
        comboRechercheType->setItemText(4, QCoreApplication::translate("AtelierWidget", "Ponceuse", nullptr));
        comboRechercheType->setItemText(5, QCoreApplication::translate("AtelierWidget", "D\303\251fonceuse", nullptr));
        comboRechercheType->setItemText(6, QCoreApplication::translate("AtelierWidget", "Tour \303\240 bois", nullptr));

        label->setText(QCoreApplication::translate("AtelierWidget", "Type de Machine :", nullptr));
        label_11->setText(QCoreApplication::translate("AtelierWidget", "Tri par :", nullptr));
        btnAppliquerTri->setText(QCoreApplication::translate("AtelierWidget", "Appliquer Tri", nullptr));
        btnReinitialiser->setText(QCoreApplication::translate("AtelierWidget", "R\303\251initialiser", nullptr));
        comboRechercheEtat->setItemText(0, QCoreApplication::translate("AtelierWidget", "-- Tous les \303\251tats --", nullptr));
        comboRechercheEtat->setItemText(1, QCoreApplication::translate("AtelierWidget", "Disponible", nullptr));
        comboRechercheEtat->setItemText(2, QCoreApplication::translate("AtelierWidget", "En maintenance", nullptr));
        comboRechercheEtat->setItemText(3, QCoreApplication::translate("AtelierWidget", "Hors service", nullptr));

        label_2->setText(QCoreApplication::translate("AtelierWidget", "\303\211tat :", nullptr));
        comboTriPar->setItemText(0, QCoreApplication::translate("AtelierWidget", "-- Aucun tri --", nullptr));
        comboTriPar->setItemText(1, QCoreApplication::translate("AtelierWidget", "Date de maintenance", nullptr));
        comboTriPar->setItemText(2, QCoreApplication::translate("AtelierWidget", "Heures d'utilisation", nullptr));
        comboTriPar->setItemText(3, QCoreApplication::translate("AtelierWidget", "Niveau de risque", nullptr));
        comboTriPar->setItemText(4, QCoreApplication::translate("AtelierWidget", "Machines critiques", nullptr));

        groupActions->setTitle(QCoreApplication::translate("AtelierWidget", " Actions", nullptr));
        btnAjouter->setText(QCoreApplication::translate("AtelierWidget", "+ Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("AtelierWidget", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("AtelierWidget", "Supprimer", nullptr));
        btnExporter->setText(QCoreApplication::translate("AtelierWidget", "Exporter", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableMachines->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AtelierWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableMachines->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AtelierWidget", "NOM", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableMachines->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AtelierWidget", "TYPE", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableMachines->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AtelierWidget", "\303\211TAT", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableMachines->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AtelierWidget", "MAINTENANCE", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableMachines->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AtelierWidget", "HEURES", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableMachines->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AtelierWidget", "RESP. MAINTENANCE", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableMachines->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AtelierWidget", "RESP. ATELIER", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMachines), QCoreApplication::translate("AtelierWidget", "  Gestion des Machines  ", nullptr));
        groupFormulaire->setTitle(QCoreApplication::translate("AtelierWidget", " Informations Machine", nullptr));
        label_3->setText(QCoreApplication::translate("AtelierWidget", "ID Machine :", nullptr));
        lineEditID->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "Auto-g\303\251n\303\251r\303\251", nullptr));
        label_4->setText(QCoreApplication::translate("AtelierWidget", "Nom :", nullptr));
        lineEditNom->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "Ex: Scie circulaire principale", nullptr));
        label_5->setText(QCoreApplication::translate("AtelierWidget", "Type :", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("AtelierWidget", "Scie", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("AtelierWidget", "Perceuse", nullptr));
        comboBoxType->setItemText(2, QCoreApplication::translate("AtelierWidget", "Raboteuse", nullptr));
        comboBoxType->setItemText(3, QCoreApplication::translate("AtelierWidget", "Ponceuse", nullptr));
        comboBoxType->setItemText(4, QCoreApplication::translate("AtelierWidget", "D\303\251fonceuse", nullptr));
        comboBoxType->setItemText(5, QCoreApplication::translate("AtelierWidget", "Tour \303\240 bois", nullptr));

        label_6->setText(QCoreApplication::translate("AtelierWidget", "\303\211tat :", nullptr));
        comboBoxEtat->setItemText(0, QCoreApplication::translate("AtelierWidget", "Disponible", nullptr));
        comboBoxEtat->setItemText(1, QCoreApplication::translate("AtelierWidget", "En maintenance", nullptr));
        comboBoxEtat->setItemText(2, QCoreApplication::translate("AtelierWidget", "Hors service", nullptr));

        label_7->setText(QCoreApplication::translate("AtelierWidget", "Date Maintenance :", nullptr));
        label_8->setText(QCoreApplication::translate("AtelierWidget", "Heures Cumul\303\251es :", nullptr));
        spinBoxHeures->setSuffix(QCoreApplication::translate("AtelierWidget", " h", nullptr));
        label_9->setText(QCoreApplication::translate("AtelierWidget", "Resp. Maintenance :", nullptr));
        lineEditRespMaintenance->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "Nom du responsable", nullptr));
        label_10->setText(QCoreApplication::translate("AtelierWidget", "Resp. Atelier :", nullptr));
        lineEditRespAtelier->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "Nom du responsable", nullptr));
        btnEnregistrer->setText(QCoreApplication::translate("AtelierWidget", "Enregistrer", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("AtelierWidget", "Annuler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabFormulaire), QCoreApplication::translate("AtelierWidget", "  Formulaire  ", nullptr));
        groupStatistiques->setTitle(QCoreApplication::translate("AtelierWidget", " Vue d'Ensemble", nullptr));
        lblTotalMachines->setText(QCoreApplication::translate("AtelierWidget", "Total Machines: 0", nullptr));
        lblMachinesDisponibles->setText(QCoreApplication::translate("AtelierWidget", "Disponibles: 0", nullptr));
        lblMachinesMaintenance->setText(QCoreApplication::translate("AtelierWidget", "En Maintenance: 0", nullptr));
        lblMachinesHS->setText(QCoreApplication::translate("AtelierWidget", "Hors Service: 0", nullptr));
        groupMachinesCritiques->setTitle(QCoreApplication::translate("AtelierWidget", " Machines Critiques & Alertes", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableMachinesCritiques->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("AtelierWidget", "PRIORIT\303\211", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableMachinesCritiques->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("AtelierWidget", "MACHINE", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableMachinesCritiques->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("AtelierWidget", "TYPE ALERTE", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableMachinesCritiques->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("AtelierWidget", "NIVEAU RISQUE", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableMachinesCritiques->horizontalHeaderItem(4);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("AtelierWidget", "ACTION REQUISE", nullptr));
        groupMachinesSollicitees->setTitle(QCoreApplication::translate("AtelierWidget", " Top 5 Machines les Plus Sollicit\303\251es", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableMachinesSollicitees->horizontalHeaderItem(0);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("AtelierWidget", "RANG", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableMachinesSollicitees->horizontalHeaderItem(1);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("AtelierWidget", "MACHINE", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableMachinesSollicitees->horizontalHeaderItem(2);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("AtelierWidget", "HEURES TOTALES", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableMachinesSollicitees->horizontalHeaderItem(3);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("AtelierWidget", "PANNES FR\303\211QUENTES", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableMachinesSollicitees->horizontalHeaderItem(4);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("AtelierWidget", "PROCHAINE MAINTENANCE", nullptr));
        groupPlanificationAuto->setTitle(QCoreApplication::translate("AtelierWidget", " Planification Automatique", nullptr));
        btnPlanifierMaintenance->setText(QCoreApplication::translate("AtelierWidget", "G\303\251n\303\251rer Plan Maintenance", nullptr));
        btnDetecterCritiques->setText(QCoreApplication::translate("AtelierWidget", "D\303\251tecter Machines Critiques", nullptr));
        btnAnalyserRisques->setText(QCoreApplication::translate("AtelierWidget", "Analyser Niveaux Risque", nullptr));
        lblGraphique->setText(QCoreApplication::translate("AtelierWidget", "<h3>Pr\303\251vention des Goulots d'\303\211tranglement</h3>\n"
"<p>Syst\303\250me intelligent de d\303\251tection et pr\303\251vention des surcharges continues.</p>\n"
"<p><b>R\303\250gles de Maintenance Automatique:</b></p>\n"
"<p>\342\200\242 Scie: Maintenance tous les 500h</p>\n"
"<p>\342\200\242 Perceuse: Maintenance tous les 300h</p>\n"
"<p>\342\200\242 Raboteuse: Maintenance tous les 400h</p>", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("AtelierWidget", "  Statistiques  ", nullptr));
        (void)AtelierWidget;
    } // retranslateUi

};

namespace Ui {
    class AtelierWidget: public Ui_AtelierWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATELIERWIDGET_H
