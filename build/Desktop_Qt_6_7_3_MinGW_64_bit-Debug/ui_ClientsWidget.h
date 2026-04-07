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
    QLabel *labelID;
    QLineEdit *lineEditID;
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
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_7;
    QGroupBox *groupBoxStats;
    QGridLayout *gridLayout_2;
    QLabel *labelTotalClients;
    QLabel *labelTotalClientsValeur;
    QPushButton *btnActualiserStats;

    void setupUi(QWidget *ClientsWidget)
    {
        if (ClientsWidget->objectName().isEmpty())
            ClientsWidget->setObjectName("ClientsWidget");
        ClientsWidget->resize(1100, 750);
        ClientsWidget->setStyleSheet(QString::fromUtf8("\n"
"    QMainWindow { background-color: #F5EBE0; }\n"
"    QWidget { background-color: #F5EBE0; color: #3D2817; font-family: 'Segoe UI', Arial, sans-serif; }\n"
"    QTabWidget::pane { border: 2px solid #8B5A2B; background-color: #F5EBE0; border-radius: 5px; }\n"
"    QTabBar::tab { background-color: #C9B59A; color: #3D2817; padding: 10px 20px; margin-right: 2px; border-top-left-radius: 5px; border-top-right-radius: 5px; font-weight: bold; }\n"
"    QTabBar::tab:selected { background-color: #8B5A2B; color: #F5EBE0; }\n"
"    QTabBar::tab:hover { background-color: #9B8068; }\n"
"    QGroupBox { background-color: #FFFFFF; border: 2px solid #8B5A2B; border-radius: 8px; margin-top: 10px; padding-top: 15px; font-weight: bold; }\n"
"    QGroupBox::title { color: #5D4037; subcontrol-origin: margin; left: 10px; padding: 0 5px; }\n"
"    QLineEdit, QTextEdit { background-color: #FFFFFF; border: 2px solid #C9B59A; border-radius: 5px; padding: 8px; color: #3D2817; }\n"
"    QLineEdit:focus, QTextEdit:focus { border: 2px"
                        " solid #8B5A2B; }\n"
"    QComboBox { background-color: #FFFFFF; border: 2px solid #C9B59A; border-radius: 5px; padding: 8px; color: #3D2817; }\n"
"    QComboBox:hover { border: 2px solid #8B5A2B; }\n"
"    QComboBox::drop-down { border: none; width: 30px; }\n"
"    QComboBox::down-arrow { image: none; border-left: 5px solid transparent; border-right: 5px solid transparent; border-top: 5px solid #8B5A2B; margin-right: 10px; }\n"
"    QPushButton { background-color: #8B5A2B; color: #F5EBE0; border: none; border-radius: 5px; padding: 10px 20px; font-weight: bold; font-size: 11pt; }\n"
"    QPushButton:hover { background-color: #9B8068; }\n"
"    QPushButton:pressed { background-color: #5D4037; }\n"
"    QPushButton#btnSupprimer { background-color: #5D4037; }\n"
"    QPushButton#btnSupprimer:hover { background-color: #6D4C41; }\n"
"    QPushButton#btnAjouter { background-color: #8B9B6A; }\n"
"    QPushButton#btnAjouter:hover { background-color: #9BAB7A; }\n"
"    QPushButton#btnVider { background-color: #C9B59A; "
                        "color: #3D2817; }\n"
"    QPushButton#btnVider:hover { background-color: #D9C5AA; }\n"
"    QTableWidget { background-color: #FFFFFF; alternate-background-color: #F5EBE0; border: 2px solid #C9B59A; border-radius: 5px; gridline-color: #C9B59A; color: #3D2817; }\n"
"    QTableWidget::item:selected { background-color: #8B5A2B; color: #F5EBE0; }\n"
"    QHeaderView::section { background-color: #8B5A2B; color: #F5EBE0; padding: 8px; border: none; font-weight: bold; }\n"
"   "));
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
        labelID = new QLabel(groupBoxInfo);
        labelID->setObjectName("labelID");

        formLayout->setWidget(0, QFormLayout::LabelRole, labelID);

        lineEditID = new QLineEdit(groupBoxInfo);
        lineEditID->setObjectName("lineEditID");

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditID);

        labelNom = new QLabel(groupBoxInfo);
        labelNom->setObjectName("labelNom");

        formLayout->setWidget(1, QFormLayout::LabelRole, labelNom);

        lineEditNom = new QLineEdit(groupBoxInfo);
        lineEditNom->setObjectName("lineEditNom");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditNom);

        labelPrenom = new QLabel(groupBoxInfo);
        labelPrenom->setObjectName("labelPrenom");

        formLayout->setWidget(2, QFormLayout::LabelRole, labelPrenom);

        lineEditPrenom = new QLineEdit(groupBoxInfo);
        lineEditPrenom->setObjectName("lineEditPrenom");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditPrenom);

        labelTelephone = new QLabel(groupBoxInfo);
        labelTelephone->setObjectName("labelTelephone");

        formLayout->setWidget(3, QFormLayout::LabelRole, labelTelephone);

        lineEditTelephone = new QLineEdit(groupBoxInfo);
        lineEditTelephone->setObjectName("lineEditTelephone");

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEditTelephone);

        labelEmail = new QLabel(groupBoxInfo);
        labelEmail->setObjectName("labelEmail");

        formLayout->setWidget(4, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(groupBoxInfo);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayout->setWidget(4, QFormLayout::FieldRole, lineEditEmail);

        labelAdresse = new QLabel(groupBoxInfo);
        labelAdresse->setObjectName("labelAdresse");

        formLayout->setWidget(5, QFormLayout::LabelRole, labelAdresse);

        textEditAdresse = new QTextEdit(groupBoxInfo);
        textEditAdresse->setObjectName("textEditAdresse");

        formLayout->setWidget(5, QFormLayout::FieldRole, textEditAdresse);

        labelSociete = new QLabel(groupBoxInfo);
        labelSociete->setObjectName("labelSociete");

        formLayout->setWidget(6, QFormLayout::LabelRole, labelSociete);

        lineEditSociete = new QLineEdit(groupBoxInfo);
        lineEditSociete->setObjectName("lineEditSociete");

        formLayout->setWidget(6, QFormLayout::FieldRole, lineEditSociete);

        labelMatricule = new QLabel(groupBoxInfo);
        labelMatricule->setObjectName("labelMatricule");

        formLayout->setWidget(7, QFormLayout::LabelRole, labelMatricule);

        lineEditMatricule = new QLineEdit(groupBoxInfo);
        lineEditMatricule->setObjectName("lineEditMatricule");

        formLayout->setWidget(7, QFormLayout::FieldRole, lineEditMatricule);

        labelCIN = new QLabel(groupBoxInfo);
        labelCIN->setObjectName("labelCIN");

        formLayout->setWidget(8, QFormLayout::LabelRole, labelCIN);

        lineEditCIN = new QLineEdit(groupBoxInfo);
        lineEditCIN->setObjectName("lineEditCIN");

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEditCIN);

        labelSiteWeb = new QLabel(groupBoxInfo);
        labelSiteWeb->setObjectName("labelSiteWeb");

        formLayout->setWidget(9, QFormLayout::LabelRole, labelSiteWeb);

        lineEditSiteWeb = new QLineEdit(groupBoxInfo);
        lineEditSiteWeb->setObjectName("lineEditSiteWeb");

        formLayout->setWidget(9, QFormLayout::FieldRole, lineEditSiteWeb);

        btnValider = new QPushButton(groupBoxInfo);
        btnValider->setObjectName("btnValider");
        btnValider->setMinimumHeight(45);
        btnValider->setStyleSheet(QString::fromUtf8("background-color: #4CAF50; color: white; font-weight: bold;"));

        formLayout->setWidget(10, QFormLayout::FieldRole, btnValider);


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

        horizontalLayout_2->addWidget(btnExportPDF);


        verticalLayout_5->addLayout(horizontalLayout_2);


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

        gridLayout_2->addWidget(labelTotalClients, 0, 0, 1, 1);

        labelTotalClientsValeur = new QLabel(groupBoxStats);
        labelTotalClientsValeur->setObjectName("labelTotalClientsValeur");

        gridLayout_2->addWidget(labelTotalClientsValeur, 0, 1, 1, 1);

        btnActualiserStats = new QPushButton(groupBoxStats);
        btnActualiserStats->setObjectName("btnActualiserStats");

        gridLayout_2->addWidget(btnActualiserStats, 1, 0, 1, 1);


        verticalLayout_7->addWidget(groupBoxStats);

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
        labelID->setText(QCoreApplication::translate("ClientsWidget", "ID Client :", nullptr));
        lineEditID->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Ex: 1001", nullptr));
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
        labelSociete->setText(QCoreApplication::translate("ClientsWidget", "Soci\303\251t\303\251 :", nullptr));
        lineEditSociete->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "Nom de l'entreprise / Raison sociale", nullptr));
        labelMatricule->setText(QCoreApplication::translate("ClientsWidget", "Matricule Fiscale :", nullptr));
        lineEditMatricule->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "0000000A / 123456789 / A", nullptr));
        labelCIN->setText(QCoreApplication::translate("ClientsWidget", "N\302\260 CIN :", nullptr));
        lineEditCIN->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "01234567", nullptr));
        labelSiteWeb->setText(QCoreApplication::translate("ClientsWidget", "Site web / FB :", nullptr));
        lineEditSiteWeb->setPlaceholderText(QCoreApplication::translate("ClientsWidget", "https:// ou www. ou facebook.com/", nullptr));
        btnValider->setText(QCoreApplication::translate("ClientsWidget", "Valider", nullptr));
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
