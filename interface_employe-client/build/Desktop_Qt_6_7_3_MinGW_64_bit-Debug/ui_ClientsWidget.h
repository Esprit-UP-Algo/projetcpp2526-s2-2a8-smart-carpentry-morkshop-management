/********************************************************************************
** Form generated from reading UI file 'ClientsWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CLIENTSWIDGET_H
#define UI_CLIENTSWIDGET_H

#include <QtCore/QVariant>
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
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ClientsWidget
{
public:
    QVBoxLayout *verticalLayout;
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
    QGroupBox *groupBoxOptions;
    QVBoxLayout *verticalLayout_6;
    QCheckBox *checkBoxInclureEntete;
    QCheckBox *checkBoxDateExport;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBoxStats;
    QGridLayout *gridLayout_2;
    QLabel *labelTotalClients;
    QLabel *labelTotalClientsValeur;
    QPushButton *btnActualiserStats;
    QSpacerItem *verticalSpacerStats;

    void setupUi(QWidget *ClientsWidget)
    {
        if (ClientsWidget->objectName().isEmpty())
            ClientsWidget->setObjectName("ClientsWidget");
        ClientsWidget->resize(920, 750);
        verticalLayout = new QVBoxLayout(ClientsWidget);
        verticalLayout->setSpacing(0);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        tabWidget = new QTabWidget(ClientsWidget);
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

        horizontalLayout->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxActions);
        btnModifier->setObjectName("btnModifier");

        horizontalLayout->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxActions);
        btnSupprimer->setObjectName("btnSupprimer");

        horizontalLayout->addWidget(btnSupprimer);

        btnAfficher = new QPushButton(groupBoxActions);
        btnAfficher->setObjectName("btnAfficher");

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
        tableWidgetClients->setSelectionBehavior(QAbstractItemView::SelectRows);
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

        horizontalLayout_2->addWidget(btnExportPDF);


        verticalLayout_5->addLayout(horizontalLayout_2);

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

        verticalLayout->addWidget(tabWidget);


        retranslateUi(ClientsWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(ClientsWidget);
    } // setupUi

    void retranslateUi(QWidget *ClientsWidget)
    {
        ClientsWidget->setWindowTitle(QCoreApplication::translate("ClientsWidget", "Clients", nullptr));
        groupRecherche->setTitle(QCoreApplication::translate("ClientsWidget", "Recherche et Tri", nullptr));
        labelRech->setText(QCoreApplication::translate("ClientsWidget", "Rechercher :", nullptr));
        lineRecherche->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Nom ou t\303\251l\303\251phone...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("ClientsWidget", "Rechercher", nullptr));
        labelTri->setText(QCoreApplication::translate("ClientsWidget", "Trier par :", nullptr));
        comboTri->setItemText(0, QCoreApplication::translate("ClientsWidget", "Nom (A-Z)", nullptr));
        comboTri->setItemText(1, QCoreApplication::translate("ClientsWidget", "Nom (Z-A)", nullptr));

        btnTrier->setText(QCoreApplication::translate("ClientsWidget", "Trier", nullptr));
        btnAfficherTout->setText(QCoreApplication::translate("ClientsWidget", "Afficher tout", nullptr));
        groupBoxInfo->setTitle(QCoreApplication::translate("ClientsWidget", "Informations Client", nullptr));
        labelNom->setText(QCoreApplication::translate("ClientsWidget", "Nom :", nullptr));
        lineEditNom->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Entrez le nom", nullptr));
        labelPrenom->setText(QCoreApplication::translate("ClientsWidget", "Pr\303\251nom :", nullptr));
        lineEditPrenom->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Entrez le pr\303\251nom", nullptr));
        labelTelephone->setText(QCoreApplication::translate("ClientsWidget", "T\303\251l\303\251phone :", nullptr));
        lineEditTelephone->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Entrez le t\303\251l\303\251phone", nullptr));
        labelEmail->setText(QCoreApplication::translate("ClientsWidget", "Email :", nullptr));
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Entrez l'email", nullptr));
        labelAdresse->setText(QCoreApplication::translate("ClientsWidget", "Adresse :", nullptr));
        textEditAdresse->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Entrez l'adresse compl\303\250te", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabConsulter), QCoreApplication::translate("ClientsWidget", "Consulter", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("ClientsWidget", "Actions", nullptr));
        btnAjouter->setText(QCoreApplication::translate("ClientsWidget", "Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("ClientsWidget", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("ClientsWidget", "Supprimer", nullptr));
        btnAfficher->setText(QCoreApplication::translate("ClientsWidget", "Afficher Tout", nullptr));
        btnVider->setText(QCoreApplication::translate("ClientsWidget", "Vider", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidgetClients->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("ClientsWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidgetClients->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("ClientsWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidgetClients->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("ClientsWidget", "Pr\303\251nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidgetClients->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("ClientsWidget", "T\303\251l\303\251phone", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidgetClients->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("ClientsWidget", "Email", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidgetClients->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("ClientsWidget", "Adresse", nullptr));
        groupBoxExport->setTitle(QCoreApplication::translate("ClientsWidget", "Exporter la Liste des Clients", nullptr));
        labelExportInfo->setText(QCoreApplication::translate("ClientsWidget", "Choisissez le format d'exportation de la liste des clients :", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("ClientsWidget", "Exporter en PDF", nullptr));
        groupBoxOptions->setTitle(QCoreApplication::translate("ClientsWidget", "Options d'exportation", nullptr));
        checkBoxInclureEntete->setText(QCoreApplication::translate("ClientsWidget", "Inclure l'en-t\303\252te", nullptr));
        checkBoxDateExport->setText(QCoreApplication::translate("ClientsWidget", "Inclure la date d'exportation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("ClientsWidget", "Affichage", nullptr));
        groupBoxStats->setTitle(QCoreApplication::translate("ClientsWidget", "Statistiques G\303\251n\303\251rales", nullptr));
        labelTotalClients->setText(QCoreApplication::translate("ClientsWidget", "Nombre total de clients :", nullptr));
        labelTotalClientsValeur->setText(QCoreApplication::translate("ClientsWidget", "0", nullptr));
        btnActualiserStats->setText(QCoreApplication::translate("ClientsWidget", "Actualiser les Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("ClientsWidget", "Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ClientsWidget: public Ui_ClientsWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CLIENTSWIDGET_H
