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
    QTabWidget *tabWidget;
    QWidget *tabGestion;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupRecherche;
    QGridLayout *gridLayout;
    QLabel *label;
    QComboBox *comboRechercheType;
    QLabel *label_2;
    QComboBox *comboRechercheEtat;
    QLabel *label_3;
    QLineEdit *lineEditRecherche;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *btnRechercher;
    QPushButton *btnReinitialiser;
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
    QLabel *label_4;
    QLineEdit *lineEditID;
    QLabel *label_5;
    QLineEdit *lineEditReference;
    QLabel *label_6;
    QComboBox *comboBoxType;
    QLabel *label_7;
    QComboBox *comboBoxEtat;
    QLabel *label_8;
    QDateEdit *dateEditMaintenance;
    QLabel *label_9;
    QSpinBox *spinBoxHeures;
    QLabel *label_10;
    QSpinBox *spinBoxQuantite;
    QLabel *label_11;
    QLineEdit *lineEditResponsable;
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
    QGroupBox *groupAlertes;
    QVBoxLayout *verticalLayout_6;
    QTableWidget *tableAlertes;
    QGroupBox *groupMachinesSollicitees;
    QVBoxLayout *verticalLayout_7;
    QTableWidget *tableSollicitees;
    QWidget *tabMaintenance;
    QVBoxLayout *verticalLayout_8;
    QGroupBox *groupPlanification;
    QVBoxLayout *verticalLayout_9;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QPushButton *btnPlanifierMaintenance;
    QGroupBox *groupPlanMaintenance;
    QVBoxLayout *verticalLayout_10;
    QTableWidget *tableMaintenance;

    void setupUi(QWidget *AtelierWidget)
    {
        if (AtelierWidget->objectName().isEmpty())
            AtelierWidget->setObjectName("AtelierWidget");
        AtelierWidget->resize(1200, 800);
        AtelierWidget->setStyleSheet(QString::fromUtf8("\n"
"QWidget {\n"
"    background-color: #F5F0E8;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #6B4423;\n"
"    color: #FAF8F3;\n"
"    border: none;\n"
"    padding: 10px 20px;\n"
"    border-radius: 5px;\n"
"    font-weight: 600;\n"
"    font-size: 10pt;\n"
"    min-height: 30px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #8B6F47;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5A3820;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    background-color: #FAF8F3;\n"
"    border: 2px solid #C9B896;\n"
"    border-radius: 8px;\n"
"    margin-top: 15px;\n"
"    padding-top: 15px;\n"
"    font-weight: 600;\n"
"    font-size: 11pt;\n"
"    color: #6B4423;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    subcontrol-position: top left;\n"
"    padding: 5px 15px;\n"
"    background-color: #6B4423;\n"
"    color: #FAF8F3;\n"
"    border-radius: 4px;\n"
"    left: 10px;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #5A3820;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEd"
                        "it, QComboBox, QSpinBox, QDateEdit {\n"
"    background-color: #FFFFFF;\n"
"    border: 2px solid #C9B896;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus, QSpinBox:focus, QDateEdit:focus {\n"
"    border: 2px solid #8B6F47;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    background-color: #FFFFFF;\n"
"    alternate-background-color: #FAF8F3;\n"
"    border: 2px solid #C9B896;\n"
"    gridline-color: #E8DCC4;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTableWidget::item {\n"
"    padding: 8px;\n"
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
"    padding: 10px;\n"
"    border: none;\n"
"    font-weight: 700;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 2px solid #C9B896;\n"
"    background-color: #F5F0E8;\n"
"    border-radius: 5px;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #"
                        "E8DCC4;\n"
"    color: #5A3820;\n"
"    padding: 10px 20px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 5px;\n"
"    border-top-right-radius: 5px;\n"
"    font-weight: 600;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #6B4423;\n"
"    color: #FAF8F3;\n"
"}\n"
"   "));
        verticalLayout = new QVBoxLayout(AtelierWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        tabWidget = new QTabWidget(AtelierWidget);
        tabWidget->setObjectName("tabWidget");
        tabGestion = new QWidget();
        tabGestion->setObjectName("tabGestion");
        verticalLayout_2 = new QVBoxLayout(tabGestion);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        groupRecherche = new QGroupBox(tabGestion);
        groupRecherche->setObjectName("groupRecherche");
        gridLayout = new QGridLayout(groupRecherche);
        gridLayout->setObjectName("gridLayout");
        label = new QLabel(groupRecherche);
        label->setObjectName("label");

        gridLayout->addWidget(label, 0, 0, 1, 1);

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

        label_2 = new QLabel(groupRecherche);
        label_2->setObjectName("label_2");

        gridLayout->addWidget(label_2, 1, 0, 1, 1);

        comboRechercheEtat = new QComboBox(groupRecherche);
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->addItem(QString());
        comboRechercheEtat->setObjectName("comboRechercheEtat");

        gridLayout->addWidget(comboRechercheEtat, 1, 1, 1, 1);

        label_3 = new QLabel(groupRecherche);
        label_3->setObjectName("label_3");

        gridLayout->addWidget(label_3, 2, 0, 1, 1);

        lineEditRecherche = new QLineEdit(groupRecherche);
        lineEditRecherche->setObjectName("lineEditRecherche");

        gridLayout->addWidget(lineEditRecherche, 2, 1, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        btnRechercher = new QPushButton(groupRecherche);
        btnRechercher->setObjectName("btnRechercher");

        horizontalLayout_2->addWidget(btnRechercher);

        btnReinitialiser = new QPushButton(groupRecherche);
        btnReinitialiser->setObjectName("btnReinitialiser");

        horizontalLayout_2->addWidget(btnReinitialiser);


        gridLayout->addLayout(horizontalLayout_2, 3, 0, 1, 2);


        horizontalLayout->addWidget(groupRecherche);

        groupActions = new QGroupBox(tabGestion);
        groupActions->setObjectName("groupActions");
        verticalLayout_3 = new QVBoxLayout(groupActions);
        verticalLayout_3->setObjectName("verticalLayout_3");
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

        tableMachines = new QTableWidget(tabGestion);
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

        tabWidget->addTab(tabGestion, QString());
        tabFormulaire = new QWidget();
        tabFormulaire->setObjectName("tabFormulaire");
        verticalLayout_4 = new QVBoxLayout(tabFormulaire);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupFormulaire = new QGroupBox(tabFormulaire);
        groupFormulaire->setObjectName("groupFormulaire");
        gridLayout_2 = new QGridLayout(groupFormulaire);
        gridLayout_2->setObjectName("gridLayout_2");
        label_4 = new QLabel(groupFormulaire);
        label_4->setObjectName("label_4");

        gridLayout_2->addWidget(label_4, 0, 0, 1, 1);

        lineEditID = new QLineEdit(groupFormulaire);
        lineEditID->setObjectName("lineEditID");
        lineEditID->setReadOnly(true);

        gridLayout_2->addWidget(lineEditID, 0, 1, 1, 1);

        label_5 = new QLabel(groupFormulaire);
        label_5->setObjectName("label_5");

        gridLayout_2->addWidget(label_5, 1, 0, 1, 1);

        lineEditReference = new QLineEdit(groupFormulaire);
        lineEditReference->setObjectName("lineEditReference");

        gridLayout_2->addWidget(lineEditReference, 1, 1, 1, 1);

        label_6 = new QLabel(groupFormulaire);
        label_6->setObjectName("label_6");

        gridLayout_2->addWidget(label_6, 2, 0, 1, 1);

        comboBoxType = new QComboBox(groupFormulaire);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName("comboBoxType");

        gridLayout_2->addWidget(comboBoxType, 2, 1, 1, 1);

        label_7 = new QLabel(groupFormulaire);
        label_7->setObjectName("label_7");

        gridLayout_2->addWidget(label_7, 3, 0, 1, 1);

        comboBoxEtat = new QComboBox(groupFormulaire);
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->setObjectName("comboBoxEtat");

        gridLayout_2->addWidget(comboBoxEtat, 3, 1, 1, 1);

        label_8 = new QLabel(groupFormulaire);
        label_8->setObjectName("label_8");

        gridLayout_2->addWidget(label_8, 4, 0, 1, 1);

        dateEditMaintenance = new QDateEdit(groupFormulaire);
        dateEditMaintenance->setObjectName("dateEditMaintenance");
        dateEditMaintenance->setCalendarPopup(true);

        gridLayout_2->addWidget(dateEditMaintenance, 4, 1, 1, 1);

        label_9 = new QLabel(groupFormulaire);
        label_9->setObjectName("label_9");

        gridLayout_2->addWidget(label_9, 5, 0, 1, 1);

        spinBoxHeures = new QSpinBox(groupFormulaire);
        spinBoxHeures->setObjectName("spinBoxHeures");
        spinBoxHeures->setMaximum(999999);

        gridLayout_2->addWidget(spinBoxHeures, 5, 1, 1, 1);

        label_10 = new QLabel(groupFormulaire);
        label_10->setObjectName("label_10");

        gridLayout_2->addWidget(label_10, 6, 0, 1, 1);

        spinBoxQuantite = new QSpinBox(groupFormulaire);
        spinBoxQuantite->setObjectName("spinBoxQuantite");
        spinBoxQuantite->setMinimum(1);
        spinBoxQuantite->setMaximum(100);

        gridLayout_2->addWidget(spinBoxQuantite, 6, 1, 1, 1);

        label_11 = new QLabel(groupFormulaire);
        label_11->setObjectName("label_11");

        gridLayout_2->addWidget(label_11, 7, 0, 1, 1);

        lineEditResponsable = new QLineEdit(groupFormulaire);
        lineEditResponsable->setObjectName("lineEditResponsable");

        gridLayout_2->addWidget(lineEditResponsable, 7, 1, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer);

        btnEnregistrer = new QPushButton(groupFormulaire);
        btnEnregistrer->setObjectName("btnEnregistrer");
        btnEnregistrer->setMinimumSize(QSize(120, 40));

        horizontalLayout_3->addWidget(btnEnregistrer);

        btnAnnuler = new QPushButton(groupFormulaire);
        btnAnnuler->setObjectName("btnAnnuler");
        btnAnnuler->setMinimumSize(QSize(120, 40));

        horizontalLayout_3->addWidget(btnAnnuler);


        gridLayout_2->addLayout(horizontalLayout_3, 8, 0, 1, 2);


        verticalLayout_4->addWidget(groupFormulaire);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_4->addItem(verticalSpacer_2);

        tabWidget->addTab(tabFormulaire, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayout_5 = new QVBoxLayout(tabStatistiques);
        verticalLayout_5->setObjectName("verticalLayout_5");
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

        groupAlertes = new QGroupBox(tabStatistiques);
        groupAlertes->setObjectName("groupAlertes");
        verticalLayout_6 = new QVBoxLayout(groupAlertes);
        verticalLayout_6->setObjectName("verticalLayout_6");
        tableAlertes = new QTableWidget(groupAlertes);
        if (tableAlertes->columnCount() < 4)
            tableAlertes->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableAlertes->setHorizontalHeaderItem(0, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableAlertes->setHorizontalHeaderItem(1, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableAlertes->setHorizontalHeaderItem(2, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableAlertes->setHorizontalHeaderItem(3, __qtablewidgetitem11);
        tableAlertes->setObjectName("tableAlertes");

        verticalLayout_6->addWidget(tableAlertes);


        verticalLayout_5->addWidget(groupAlertes);

        groupMachinesSollicitees = new QGroupBox(tabStatistiques);
        groupMachinesSollicitees->setObjectName("groupMachinesSollicitees");
        verticalLayout_7 = new QVBoxLayout(groupMachinesSollicitees);
        verticalLayout_7->setObjectName("verticalLayout_7");
        tableSollicitees = new QTableWidget(groupMachinesSollicitees);
        if (tableSollicitees->columnCount() < 4)
            tableSollicitees->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableSollicitees->setHorizontalHeaderItem(0, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableSollicitees->setHorizontalHeaderItem(1, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableSollicitees->setHorizontalHeaderItem(2, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableSollicitees->setHorizontalHeaderItem(3, __qtablewidgetitem15);
        tableSollicitees->setObjectName("tableSollicitees");

        verticalLayout_7->addWidget(tableSollicitees);


        verticalLayout_5->addWidget(groupMachinesSollicitees);

        tabWidget->addTab(tabStatistiques, QString());
        tabMaintenance = new QWidget();
        tabMaintenance->setObjectName("tabMaintenance");
        verticalLayout_8 = new QVBoxLayout(tabMaintenance);
        verticalLayout_8->setObjectName("verticalLayout_8");
        groupPlanification = new QGroupBox(tabMaintenance);
        groupPlanification->setObjectName("groupPlanification");
        verticalLayout_9 = new QVBoxLayout(groupPlanification);
        verticalLayout_9->setObjectName("verticalLayout_9");
        label_12 = new QLabel(groupPlanification);
        label_12->setObjectName("label_12");

        verticalLayout_9->addWidget(label_12);

        label_13 = new QLabel(groupPlanification);
        label_13->setObjectName("label_13");

        verticalLayout_9->addWidget(label_13);

        label_14 = new QLabel(groupPlanification);
        label_14->setObjectName("label_14");

        verticalLayout_9->addWidget(label_14);

        label_15 = new QLabel(groupPlanification);
        label_15->setObjectName("label_15");

        verticalLayout_9->addWidget(label_15);

        btnPlanifierMaintenance = new QPushButton(groupPlanification);
        btnPlanifierMaintenance->setObjectName("btnPlanifierMaintenance");

        verticalLayout_9->addWidget(btnPlanifierMaintenance);


        verticalLayout_8->addWidget(groupPlanification);

        groupPlanMaintenance = new QGroupBox(tabMaintenance);
        groupPlanMaintenance->setObjectName("groupPlanMaintenance");
        verticalLayout_10 = new QVBoxLayout(groupPlanMaintenance);
        verticalLayout_10->setObjectName("verticalLayout_10");
        tableMaintenance = new QTableWidget(groupPlanMaintenance);
        if (tableMaintenance->columnCount() < 5)
            tableMaintenance->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableMaintenance->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        tableMaintenance->setObjectName("tableMaintenance");

        verticalLayout_10->addWidget(tableMaintenance);


        verticalLayout_8->addWidget(groupPlanMaintenance);

        tabWidget->addTab(tabMaintenance, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(AtelierWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(AtelierWidget);
    } // setupUi

    void retranslateUi(QWidget *AtelierWidget)
    {
        groupRecherche->setTitle(QCoreApplication::translate("AtelierWidget", "Filtres de Recherche", nullptr));
        label->setText(QCoreApplication::translate("AtelierWidget", "Type de Machine :", nullptr));
        comboRechercheType->setItemText(0, QCoreApplication::translate("AtelierWidget", "-- Tous les types --", nullptr));
        comboRechercheType->setItemText(1, QCoreApplication::translate("AtelierWidget", "Scie", nullptr));
        comboRechercheType->setItemText(2, QCoreApplication::translate("AtelierWidget", "Perceuse", nullptr));
        comboRechercheType->setItemText(3, QCoreApplication::translate("AtelierWidget", "Raboteuse", nullptr));
        comboRechercheType->setItemText(4, QCoreApplication::translate("AtelierWidget", "Ponceuse", nullptr));
        comboRechercheType->setItemText(5, QCoreApplication::translate("AtelierWidget", "D\303\251fonceuse", nullptr));
        comboRechercheType->setItemText(6, QCoreApplication::translate("AtelierWidget", "Tour \303\240 bois", nullptr));

        label_2->setText(QCoreApplication::translate("AtelierWidget", "\303\211tat :", nullptr));
        comboRechercheEtat->setItemText(0, QCoreApplication::translate("AtelierWidget", "-- Tous les \303\251tats --", nullptr));
        comboRechercheEtat->setItemText(1, QCoreApplication::translate("AtelierWidget", "Disponible", nullptr));
        comboRechercheEtat->setItemText(2, QCoreApplication::translate("AtelierWidget", "En maintenance", nullptr));
        comboRechercheEtat->setItemText(3, QCoreApplication::translate("AtelierWidget", "Hors service", nullptr));

        label_3->setText(QCoreApplication::translate("AtelierWidget", "Recherche :", nullptr));
        lineEditRecherche->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "ID ou r\303\251f\303\251rence...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("AtelierWidget", "Rechercher", nullptr));
        btnReinitialiser->setText(QCoreApplication::translate("AtelierWidget", "R\303\251initialiser", nullptr));
        groupActions->setTitle(QCoreApplication::translate("AtelierWidget", "Actions", nullptr));
        btnAjouter->setText(QCoreApplication::translate("AtelierWidget", "+ Ajouter Machine", nullptr));
        btnModifier->setText(QCoreApplication::translate("AtelierWidget", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("AtelierWidget", "Supprimer", nullptr));
        btnExporter->setText(QCoreApplication::translate("AtelierWidget", "Exporter CSV", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableMachines->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("AtelierWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableMachines->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("AtelierWidget", "R\303\251f\303\251rence", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableMachines->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("AtelierWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableMachines->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("AtelierWidget", "\303\211tat", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableMachines->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("AtelierWidget", "Derni\303\250re Maintenance", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableMachines->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("AtelierWidget", "Heures Cumul\303\251es", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableMachines->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("AtelierWidget", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableMachines->horizontalHeaderItem(7);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("AtelierWidget", "Responsable", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QCoreApplication::translate("AtelierWidget", "Gestion des Machines", nullptr));
        groupFormulaire->setTitle(QCoreApplication::translate("AtelierWidget", "Informations Machine", nullptr));
        label_4->setText(QCoreApplication::translate("AtelierWidget", "ID Machine :", nullptr));
        lineEditID->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "Auto-g\303\251n\303\251r\303\251", nullptr));
        label_5->setText(QCoreApplication::translate("AtelierWidget", "R\303\251f\303\251rence :", nullptr));
        lineEditReference->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "Ex: SCE-001", nullptr));
        label_6->setText(QCoreApplication::translate("AtelierWidget", "Type :", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("AtelierWidget", "Scie", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("AtelierWidget", "Perceuse", nullptr));
        comboBoxType->setItemText(2, QCoreApplication::translate("AtelierWidget", "Raboteuse", nullptr));
        comboBoxType->setItemText(3, QCoreApplication::translate("AtelierWidget", "Ponceuse", nullptr));
        comboBoxType->setItemText(4, QCoreApplication::translate("AtelierWidget", "D\303\251fonceuse", nullptr));
        comboBoxType->setItemText(5, QCoreApplication::translate("AtelierWidget", "Tour \303\240 bois", nullptr));

        label_7->setText(QCoreApplication::translate("AtelierWidget", "\303\211tat :", nullptr));
        comboBoxEtat->setItemText(0, QCoreApplication::translate("AtelierWidget", "Disponible", nullptr));
        comboBoxEtat->setItemText(1, QCoreApplication::translate("AtelierWidget", "En maintenance", nullptr));
        comboBoxEtat->setItemText(2, QCoreApplication::translate("AtelierWidget", "Hors service", nullptr));

        label_8->setText(QCoreApplication::translate("AtelierWidget", "Date Derni\303\250re Maintenance :", nullptr));
        label_9->setText(QCoreApplication::translate("AtelierWidget", "Heures Cumul\303\251es :", nullptr));
        spinBoxHeures->setSuffix(QCoreApplication::translate("AtelierWidget", " h", nullptr));
        label_10->setText(QCoreApplication::translate("AtelierWidget", "Quantit\303\251 :", nullptr));
        label_11->setText(QCoreApplication::translate("AtelierWidget", "Responsable Maintenance :", nullptr));
        lineEditResponsable->setPlaceholderText(QCoreApplication::translate("AtelierWidget", "Nom du responsable", nullptr));
        btnEnregistrer->setText(QCoreApplication::translate("AtelierWidget", "Enregistrer", nullptr));
        btnAnnuler->setText(QCoreApplication::translate("AtelierWidget", "Annuler", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabFormulaire), QCoreApplication::translate("AtelierWidget", "Formulaire Machine", nullptr));
        groupStatistiques->setTitle(QCoreApplication::translate("AtelierWidget", "Vue d'Ensemble", nullptr));
        lblTotalMachines->setText(QCoreApplication::translate("AtelierWidget", "Total Machines: 0", nullptr));
        lblMachinesDisponibles->setText(QCoreApplication::translate("AtelierWidget", "Disponibles: 0", nullptr));
        lblMachinesMaintenance->setText(QCoreApplication::translate("AtelierWidget", "En Maintenance: 0", nullptr));
        lblMachinesHS->setText(QCoreApplication::translate("AtelierWidget", "Hors Service: 0", nullptr));
        groupAlertes->setTitle(QCoreApplication::translate("AtelierWidget", "Alertes & Machines Critiques", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableAlertes->horizontalHeaderItem(0);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("AtelierWidget", "Priorit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableAlertes->horizontalHeaderItem(1);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("AtelierWidget", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableAlertes->horizontalHeaderItem(2);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("AtelierWidget", "Type d'Alerte", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableAlertes->horizontalHeaderItem(3);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("AtelierWidget", "Description", nullptr));
        groupMachinesSollicitees->setTitle(QCoreApplication::translate("AtelierWidget", "Machines les Plus Sollicit\303\251es", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableSollicitees->horizontalHeaderItem(0);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("AtelierWidget", "Rang", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableSollicitees->horizontalHeaderItem(1);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("AtelierWidget", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableSollicitees->horizontalHeaderItem(2);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("AtelierWidget", "Heures Utilisation", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableSollicitees->horizontalHeaderItem(3);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("AtelierWidget", "Niveau Risque", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("AtelierWidget", "Statistiques & Alertes", nullptr));
        groupPlanification->setTitle(QCoreApplication::translate("AtelierWidget", "Maintenance Automatique", nullptr));
        label_12->setText(QCoreApplication::translate("AtelierWidget", "<b>R\303\250gles de Planification:</b>", nullptr));
        label_13->setText(QCoreApplication::translate("AtelierWidget", "\342\200\242 Scie: Maintenance tous les 500h", nullptr));
        label_14->setText(QCoreApplication::translate("AtelierWidget", "\342\200\242 Perceuse: Maintenance tous les 300h", nullptr));
        label_15->setText(QCoreApplication::translate("AtelierWidget", "\342\200\242 Raboteuse: Maintenance tous les 400h", nullptr));
        btnPlanifierMaintenance->setText(QCoreApplication::translate("AtelierWidget", "G\303\251n\303\251rer Plan de Maintenance", nullptr));
        groupPlanMaintenance->setTitle(QCoreApplication::translate("AtelierWidget", "Machines N\303\251cessitant une Maintenance", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tableMaintenance->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("AtelierWidget", "Machine", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tableMaintenance->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("AtelierWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tableMaintenance->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("AtelierWidget", "Heures Actuelles", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableMaintenance->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("AtelierWidget", "Seuil Maintenance", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableMaintenance->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("AtelierWidget", "Urgence", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabMaintenance), QCoreApplication::translate("AtelierWidget", "Planification Maintenance", nullptr));
        (void)AtelierWidget;
    } // retranslateUi

};

namespace Ui {
    class AtelierWidget: public Ui_AtelierWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATELIERWIDGET_H
