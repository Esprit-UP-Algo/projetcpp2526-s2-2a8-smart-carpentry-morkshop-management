/********************************************************************************
** Form generated from reading UI file 'EmployeWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMPLOYEWIDGET_H
#define UI_EMPLOYEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmployeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tabConsulter;
    QVBoxLayout *verticalLayoutConsulter;
    QGroupBox *groupBoxInfoEmployes;
    QFormLayout *formLayoutEmploye;
    QLabel *labelCIN;
    QLineEdit *lineEditCIN;
    QLabel *labelNom;
    QLineEdit *lineEditNom;
    QLabel *labelPoste;
    QComboBox *comboBoxPoste;
    QLabel *labelSalaire;
    QDoubleSpinBox *doubleSpinBoxSalaire;
    QLabel *labelDispo;
    QComboBox *comboBoxDispo;
    QLabel *labelTelephone;
    QLineEdit *lineEditTelephone;
    QLabel *labelEmail;
    QLineEdit *lineEditEmail;
    QLabel *labelDateEmbauche;
    QDateEdit *dateEditEmbauche;
    QLabel *labelAdresse;
    QTextEdit *textEditAdresse;
    QWidget *tabAffichage;
    QVBoxLayout *verticalLayoutAffichage;
    QGroupBox *groupRechercheEtTri;
    QHBoxLayout *horizontalRechercheEtTri;
    QLabel *labelRechercher;
    QLineEdit *lineEditRecherche;
    QPushButton *btnRechercher;
    QLabel *labelTrierPar;
    QComboBox *comboBoxTri;
    QPushButton *btnTrier;
    QPushButton *btnAfficherTout;
    QGroupBox *groupBoxActions;
    QHBoxLayout *hboxLayout;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnSupprimer;
    QPushButton *btnAfficherToutActions;
    QPushButton *btnVider;
    QTableWidget *tableWidgetEmployes;
    QGroupBox *groupBoxExport;
    QVBoxLayout *vboxLayout;
    QPushButton *btnExportPDF;
    QGroupBox *groupBoxExportOptions;
    QVBoxLayout *vboxLayout1;
    QCheckBox *checkBoxInclureEntete;
    QCheckBox *checkBoxDateExport;
    QWidget *tabStatistiques;
    QVBoxLayout *vboxLayout2;
    QGroupBox *groupBoxStats;
    QGridLayout *gridLayout;
    QLabel *labelTotalEmployes;
    QLabel *labelTotalEmployesValeur;
    QPushButton *btnActualiserStats;

    void setupUi(QWidget *EmployeWidget)
    {
        if (EmployeWidget->objectName().isEmpty())
            EmployeWidget->setObjectName("EmployeWidget");
        verticalLayout = new QVBoxLayout(EmployeWidget);
        verticalLayout->setObjectName("verticalLayout");
        tabWidget = new QTabWidget(EmployeWidget);
        tabWidget->setObjectName("tabWidget");
        tabConsulter = new QWidget();
        tabConsulter->setObjectName("tabConsulter");
        verticalLayoutConsulter = new QVBoxLayout(tabConsulter);
        verticalLayoutConsulter->setObjectName("verticalLayoutConsulter");
        groupBoxInfoEmployes = new QGroupBox(tabConsulter);
        groupBoxInfoEmployes->setObjectName("groupBoxInfoEmployes");
        formLayoutEmploye = new QFormLayout(groupBoxInfoEmployes);
        formLayoutEmploye->setObjectName("formLayoutEmploye");
        formLayoutEmploye->setLabelAlignment(Qt::AlignmentFlag::AlignLeft|Qt::AlignmentFlag::AlignVCenter);
        formLayoutEmploye->setFormAlignment(Qt::AlignmentFlag::AlignTop);
        formLayoutEmploye->setHorizontalSpacing(12);
        formLayoutEmploye->setVerticalSpacing(10);
        labelCIN = new QLabel(groupBoxInfoEmployes);
        labelCIN->setObjectName("labelCIN");

        formLayoutEmploye->setWidget(0, QFormLayout::LabelRole, labelCIN);

        lineEditCIN = new QLineEdit(groupBoxInfoEmployes);
        lineEditCIN->setObjectName("lineEditCIN");

        formLayoutEmploye->setWidget(0, QFormLayout::FieldRole, lineEditCIN);

        labelNom = new QLabel(groupBoxInfoEmployes);
        labelNom->setObjectName("labelNom");

        formLayoutEmploye->setWidget(1, QFormLayout::LabelRole, labelNom);

        lineEditNom = new QLineEdit(groupBoxInfoEmployes);
        lineEditNom->setObjectName("lineEditNom");

        formLayoutEmploye->setWidget(1, QFormLayout::FieldRole, lineEditNom);

        labelPoste = new QLabel(groupBoxInfoEmployes);
        labelPoste->setObjectName("labelPoste");

        formLayoutEmploye->setWidget(2, QFormLayout::LabelRole, labelPoste);

        comboBoxPoste = new QComboBox(groupBoxInfoEmployes);
        comboBoxPoste->addItem(QString());
        comboBoxPoste->addItem(QString());
        comboBoxPoste->addItem(QString());
        comboBoxPoste->addItem(QString());
        comboBoxPoste->setObjectName("comboBoxPoste");

        formLayoutEmploye->setWidget(2, QFormLayout::FieldRole, comboBoxPoste);

        labelSalaire = new QLabel(groupBoxInfoEmployes);
        labelSalaire->setObjectName("labelSalaire");

        formLayoutEmploye->setWidget(3, QFormLayout::LabelRole, labelSalaire);

        doubleSpinBoxSalaire = new QDoubleSpinBox(groupBoxInfoEmployes);
        doubleSpinBoxSalaire->setObjectName("doubleSpinBoxSalaire");
        doubleSpinBoxSalaire->setMaximum(999999.989999999990687);

        formLayoutEmploye->setWidget(3, QFormLayout::FieldRole, doubleSpinBoxSalaire);

        labelDispo = new QLabel(groupBoxInfoEmployes);
        labelDispo->setObjectName("labelDispo");

        formLayoutEmploye->setWidget(4, QFormLayout::LabelRole, labelDispo);

        comboBoxDispo = new QComboBox(groupBoxInfoEmployes);
        comboBoxDispo->addItem(QString());
        comboBoxDispo->addItem(QString());
        comboBoxDispo->addItem(QString());
        comboBoxDispo->setObjectName("comboBoxDispo");

        formLayoutEmploye->setWidget(4, QFormLayout::FieldRole, comboBoxDispo);

        labelTelephone = new QLabel(groupBoxInfoEmployes);
        labelTelephone->setObjectName("labelTelephone");

        formLayoutEmploye->setWidget(5, QFormLayout::LabelRole, labelTelephone);

        lineEditTelephone = new QLineEdit(groupBoxInfoEmployes);
        lineEditTelephone->setObjectName("lineEditTelephone");

        formLayoutEmploye->setWidget(5, QFormLayout::FieldRole, lineEditTelephone);

        labelEmail = new QLabel(groupBoxInfoEmployes);
        labelEmail->setObjectName("labelEmail");

        formLayoutEmploye->setWidget(6, QFormLayout::LabelRole, labelEmail);

        lineEditEmail = new QLineEdit(groupBoxInfoEmployes);
        lineEditEmail->setObjectName("lineEditEmail");

        formLayoutEmploye->setWidget(6, QFormLayout::FieldRole, lineEditEmail);

        labelDateEmbauche = new QLabel(groupBoxInfoEmployes);
        labelDateEmbauche->setObjectName("labelDateEmbauche");

        formLayoutEmploye->setWidget(7, QFormLayout::LabelRole, labelDateEmbauche);

        dateEditEmbauche = new QDateEdit(groupBoxInfoEmployes);
        dateEditEmbauche->setObjectName("dateEditEmbauche");
        dateEditEmbauche->setCalendarPopup(true);

        formLayoutEmploye->setWidget(7, QFormLayout::FieldRole, dateEditEmbauche);

        labelAdresse = new QLabel(groupBoxInfoEmployes);
        labelAdresse->setObjectName("labelAdresse");

        formLayoutEmploye->setWidget(8, QFormLayout::LabelRole, labelAdresse);

        textEditAdresse = new QTextEdit(groupBoxInfoEmployes);
        textEditAdresse->setObjectName("textEditAdresse");

        formLayoutEmploye->setWidget(8, QFormLayout::FieldRole, textEditAdresse);


        verticalLayoutConsulter->addWidget(groupBoxInfoEmployes);

        tabWidget->addTab(tabConsulter, QString());
        tabAffichage = new QWidget();
        tabAffichage->setObjectName("tabAffichage");
        verticalLayoutAffichage = new QVBoxLayout(tabAffichage);
        verticalLayoutAffichage->setObjectName("verticalLayoutAffichage");
        groupRechercheEtTri = new QGroupBox(tabAffichage);
        groupRechercheEtTri->setObjectName("groupRechercheEtTri");
        horizontalRechercheEtTri = new QHBoxLayout(groupRechercheEtTri);
        horizontalRechercheEtTri->setObjectName("horizontalRechercheEtTri");
        labelRechercher = new QLabel(groupRechercheEtTri);
        labelRechercher->setObjectName("labelRechercher");

        horizontalRechercheEtTri->addWidget(labelRechercher);

        lineEditRecherche = new QLineEdit(groupRechercheEtTri);
        lineEditRecherche->setObjectName("lineEditRecherche");

        horizontalRechercheEtTri->addWidget(lineEditRecherche);

        btnRechercher = new QPushButton(groupRechercheEtTri);
        btnRechercher->setObjectName("btnRechercher");

        horizontalRechercheEtTri->addWidget(btnRechercher);

        labelTrierPar = new QLabel(groupRechercheEtTri);
        labelTrierPar->setObjectName("labelTrierPar");

        horizontalRechercheEtTri->addWidget(labelTrierPar);

        comboBoxTri = new QComboBox(groupRechercheEtTri);
        comboBoxTri->addItem(QString());
        comboBoxTri->addItem(QString());
        comboBoxTri->setObjectName("comboBoxTri");

        horizontalRechercheEtTri->addWidget(comboBoxTri);

        btnTrier = new QPushButton(groupRechercheEtTri);
        btnTrier->setObjectName("btnTrier");

        horizontalRechercheEtTri->addWidget(btnTrier);

        btnAfficherTout = new QPushButton(groupRechercheEtTri);
        btnAfficherTout->setObjectName("btnAfficherTout");

        horizontalRechercheEtTri->addWidget(btnAfficherTout);


        verticalLayoutAffichage->addWidget(groupRechercheEtTri);

        groupBoxActions = new QGroupBox(tabAffichage);
        groupBoxActions->setObjectName("groupBoxActions");
        hboxLayout = new QHBoxLayout(groupBoxActions);
        hboxLayout->setObjectName("hboxLayout");
        btnAjouter = new QPushButton(groupBoxActions);
        btnAjouter->setObjectName("btnAjouter");

        hboxLayout->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxActions);
        btnModifier->setObjectName("btnModifier");

        hboxLayout->addWidget(btnModifier);

        btnSupprimer = new QPushButton(groupBoxActions);
        btnSupprimer->setObjectName("btnSupprimer");

        hboxLayout->addWidget(btnSupprimer);

        btnAfficherToutActions = new QPushButton(groupBoxActions);
        btnAfficherToutActions->setObjectName("btnAfficherToutActions");

        hboxLayout->addWidget(btnAfficherToutActions);

        btnVider = new QPushButton(groupBoxActions);
        btnVider->setObjectName("btnVider");

        hboxLayout->addWidget(btnVider);


        verticalLayoutAffichage->addWidget(groupBoxActions);

        tableWidgetEmployes = new QTableWidget(tabAffichage);
        tableWidgetEmployes->setObjectName("tableWidgetEmployes");

        verticalLayoutAffichage->addWidget(tableWidgetEmployes);

        groupBoxExport = new QGroupBox(tabAffichage);
        groupBoxExport->setObjectName("groupBoxExport");
        vboxLayout = new QVBoxLayout(groupBoxExport);
        vboxLayout->setObjectName("vboxLayout");
        btnExportPDF = new QPushButton(groupBoxExport);
        btnExportPDF->setObjectName("btnExportPDF");

        vboxLayout->addWidget(btnExportPDF);

        groupBoxExportOptions = new QGroupBox(groupBoxExport);
        groupBoxExportOptions->setObjectName("groupBoxExportOptions");
        vboxLayout1 = new QVBoxLayout(groupBoxExportOptions);
        vboxLayout1->setObjectName("vboxLayout1");
        checkBoxInclureEntete = new QCheckBox(groupBoxExportOptions);
        checkBoxInclureEntete->setObjectName("checkBoxInclureEntete");
        checkBoxInclureEntete->setChecked(true);

        vboxLayout1->addWidget(checkBoxInclureEntete);

        checkBoxDateExport = new QCheckBox(groupBoxExportOptions);
        checkBoxDateExport->setObjectName("checkBoxDateExport");
        checkBoxDateExport->setChecked(true);

        vboxLayout1->addWidget(checkBoxDateExport);


        vboxLayout->addWidget(groupBoxExportOptions);


        verticalLayoutAffichage->addWidget(groupBoxExport);

        tabWidget->addTab(tabAffichage, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        vboxLayout2 = new QVBoxLayout(tabStatistiques);
        vboxLayout2->setObjectName("vboxLayout2");
        groupBoxStats = new QGroupBox(tabStatistiques);
        groupBoxStats->setObjectName("groupBoxStats");
        gridLayout = new QGridLayout(groupBoxStats);
        gridLayout->setObjectName("gridLayout");
        labelTotalEmployes = new QLabel(groupBoxStats);
        labelTotalEmployes->setObjectName("labelTotalEmployes");

        gridLayout->addWidget(labelTotalEmployes, 0, 0, 1, 1);

        labelTotalEmployesValeur = new QLabel(groupBoxStats);
        labelTotalEmployesValeur->setObjectName("labelTotalEmployesValeur");

        gridLayout->addWidget(labelTotalEmployesValeur, 0, 1, 1, 1);

        btnActualiserStats = new QPushButton(groupBoxStats);
        btnActualiserStats->setObjectName("btnActualiserStats");

        gridLayout->addWidget(btnActualiserStats, 1, 0, 1, 1);


        vboxLayout2->addWidget(groupBoxStats);

        tabWidget->addTab(tabStatistiques, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(EmployeWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(EmployeWidget);
    } // setupUi

    void retranslateUi(QWidget *EmployeWidget)
    {
        EmployeWidget->setWindowTitle(QCoreApplication::translate("EmployeWidget", "Gestion des Employ\303\251s", nullptr));
        groupBoxInfoEmployes->setTitle(QCoreApplication::translate("EmployeWidget", "Informations des Employ\303\251s", nullptr));
        labelCIN->setText(QCoreApplication::translate("EmployeWidget", "CIN :", nullptr));
        lineEditCIN->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez le CIN", nullptr));
        labelNom->setText(QCoreApplication::translate("EmployeWidget", "Nom :", nullptr));
        lineEditNom->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez le nom", nullptr));
        labelPoste->setText(QCoreApplication::translate("EmployeWidget", "Poste :", nullptr));
        comboBoxPoste->setItemText(0, QCoreApplication::translate("EmployeWidget", "Responsable RH", nullptr));
        comboBoxPoste->setItemText(1, QCoreApplication::translate("EmployeWidget", "Gestionnaire Commandes", nullptr));
        comboBoxPoste->setItemText(2, QCoreApplication::translate("EmployeWidget", "Technicien Machines", nullptr));
        comboBoxPoste->setItemText(3, QCoreApplication::translate("EmployeWidget", "Assistant Email/Support", nullptr));

        labelSalaire->setText(QCoreApplication::translate("EmployeWidget", "Salaire :", nullptr));
        labelDispo->setText(QCoreApplication::translate("EmployeWidget", "Disponibilit\303\251 :", nullptr));
        comboBoxDispo->setItemText(0, QCoreApplication::translate("EmployeWidget", "disponible", nullptr));
        comboBoxDispo->setItemText(1, QCoreApplication::translate("EmployeWidget", "en cong\303\251", nullptr));
        comboBoxDispo->setItemText(2, QCoreApplication::translate("EmployeWidget", "absent", nullptr));

        labelTelephone->setText(QCoreApplication::translate("EmployeWidget", "T\303\251l\303\251phone :", nullptr));
        lineEditTelephone->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez le t\303\251l\303\251phone", nullptr));
        labelEmail->setText(QCoreApplication::translate("EmployeWidget", "Email :", nullptr));
        lineEditEmail->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez l'email", nullptr));
        labelDateEmbauche->setText(QCoreApplication::translate("EmployeWidget", "Date d\342\200\231embauche :", nullptr));
        labelAdresse->setText(QCoreApplication::translate("EmployeWidget", "Adresse :", nullptr));
        textEditAdresse->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "Entrez l'adresse compl\303\250te", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabConsulter), QCoreApplication::translate("EmployeWidget", "Consulter", nullptr));
        groupRechercheEtTri->setTitle(QCoreApplication::translate("EmployeWidget", "Recherche et Tri", nullptr));
        labelRechercher->setText(QCoreApplication::translate("EmployeWidget", "Rechercher :", nullptr));
        lineEditRecherche->setPlaceholderText(QCoreApplication::translate("EmployeWidget", "CIN ou poste...", nullptr));
        btnRechercher->setText(QCoreApplication::translate("EmployeWidget", "Rechercher", nullptr));
        labelTrierPar->setText(QCoreApplication::translate("EmployeWidget", "Trier par :", nullptr));
        comboBoxTri->setItemText(0, QCoreApplication::translate("EmployeWidget", "Salaire (croissant)", nullptr));
        comboBoxTri->setItemText(1, QCoreApplication::translate("EmployeWidget", "Salaire (d\303\251croissant)", nullptr));

        btnTrier->setText(QCoreApplication::translate("EmployeWidget", "Trier", nullptr));
        btnAfficherTout->setText(QCoreApplication::translate("EmployeWidget", "Afficher tout", nullptr));
        groupBoxActions->setTitle(QCoreApplication::translate("EmployeWidget", "Actions", nullptr));
        btnAjouter->setText(QCoreApplication::translate("EmployeWidget", "+ Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("EmployeWidget", "Modifier", nullptr));
        btnSupprimer->setText(QCoreApplication::translate("EmployeWidget", "Supprimer", nullptr));
        btnAfficherToutActions->setText(QCoreApplication::translate("EmployeWidget", "Afficher Tout", nullptr));
        btnVider->setText(QCoreApplication::translate("EmployeWidget", "Vider", nullptr));
        groupBoxExport->setTitle(QCoreApplication::translate("EmployeWidget", "Emploi de travail", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("EmployeWidget", "Exporter en PDF", nullptr));
        groupBoxExportOptions->setTitle(QCoreApplication::translate("EmployeWidget", "Options d'exportation", nullptr));
        checkBoxInclureEntete->setText(QCoreApplication::translate("EmployeWidget", "Inclure l'en-t\303\252te", nullptr));
        checkBoxDateExport->setText(QCoreApplication::translate("EmployeWidget", "Inclure la date d'exportation", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabAffichage), QCoreApplication::translate("EmployeWidget", "Affichage", nullptr));
        groupBoxStats->setTitle(QCoreApplication::translate("EmployeWidget", "Statistiques : heures des travails des employ\303\251s", nullptr));
        labelTotalEmployes->setText(QCoreApplication::translate("EmployeWidget", "Heures de travail des employ\303\251s :", nullptr));
        labelTotalEmployesValeur->setText(QCoreApplication::translate("EmployeWidget", "0", nullptr));
        btnActualiserStats->setText(QCoreApplication::translate("EmployeWidget", "Actualiser les heures", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("EmployeWidget", "Statistiques", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmployeWidget: public Ui_EmployeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMPLOYEWIDGET_H
