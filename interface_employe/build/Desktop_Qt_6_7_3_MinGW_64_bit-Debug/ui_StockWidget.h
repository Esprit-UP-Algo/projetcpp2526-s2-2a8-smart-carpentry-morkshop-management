/********************************************************************************
** Form generated from reading UI file 'stockwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STOCKWIDGET_H
#define UI_STOCKWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *lblTitle;
    QTabWidget *tabWidget;
    QWidget *tabGestion;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBoxForm;
    QVBoxLayout *verticalLayout_2;
    QLabel *labelNom;
    QLineEdit *txtNom;
    QLabel *labelType;
    QComboBox *comboType;
    QLabel *labelQuantite;
    QDoubleSpinBox *spinQuantite;
    QLabel *labelPrix;
    QDoubleSpinBox *spinPrixAchat;
    QLabel *labelSeuil;
    QSpinBox *spinSeuilAlerte;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnDelete;
    QPushButton *btnNouveau;
    QGroupBox *groupBoxRecherche;
    QVBoxLayout *verticalLayout_3;
    QLineEdit *txtRecherche;
    QComboBox *comboFiltreType;
    QPushButton *btnRechercher;
    QTableWidget *tableWidget;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_4;
    QHBoxLayout *horizontalLayoutStats;
    QLabel *labelTotal;
    QLabel *lblTotalMateriaux;
    QLabel *labelTypes;
    QLabel *lblTypesMateriaux;
    QSpacerItem *horizontalSpacerStats;
    QTableWidget *tableStats;
    QPushButton *btnActualiserStats;
    QWidget *tabInnovant;
    QVBoxLayout *verticalLayout_5;
    QPushButton *btnGenererReappro;
    QTableWidget *tableReappro;
    QLabel *labelPrevision;
    QGridLayout *gridLayoutPrevision;
    QLabel *labelNbCommandes;
    QSpinBox *spinNbCommandes;
    QSpacerItem *horizontalSpacer;
    QLabel *labelPeriode;
    QSpinBox *spinPeriode;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnPrevision;
    QTableWidget *tablePrevision;
    QWidget *tabTriQuantite;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBoxTri;
    QVBoxLayout *verticalLayout_tri;
    QHBoxLayout *horizontalLayout_tri;
    QRadioButton *radioCroissant;
    QRadioButton *radioDecroissant;
    QPushButton *btnAppliquerTri;
    QTableWidget *tableTriQuantite;

    void setupUi(QWidget *StockWidget)
    {
        if (StockWidget->objectName().isEmpty())
            StockWidget->setObjectName("StockWidget");
        StockWidget->resize(1200, 800);
        verticalLayout = new QVBoxLayout(StockWidget);
        verticalLayout->setObjectName("verticalLayout");
        lblTitle = new QLabel(StockWidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(lblTitle);

        tabWidget = new QTabWidget(StockWidget);
        tabWidget->setObjectName("tabWidget");
        tabGestion = new QWidget();
        tabGestion->setObjectName("tabGestion");
        horizontalLayout = new QHBoxLayout(tabGestion);
        horizontalLayout->setObjectName("horizontalLayout");
        groupBoxForm = new QGroupBox(tabGestion);
        groupBoxForm->setObjectName("groupBoxForm");
        verticalLayout_2 = new QVBoxLayout(groupBoxForm);
        verticalLayout_2->setObjectName("verticalLayout_2");
        labelNom = new QLabel(groupBoxForm);
        labelNom->setObjectName("labelNom");

        verticalLayout_2->addWidget(labelNom);

        txtNom = new QLineEdit(groupBoxForm);
        txtNom->setObjectName("txtNom");

        verticalLayout_2->addWidget(txtNom);

        labelType = new QLabel(groupBoxForm);
        labelType->setObjectName("labelType");

        verticalLayout_2->addWidget(labelType);

        comboType = new QComboBox(groupBoxForm);
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->addItem(QString());
        comboType->setObjectName("comboType");

        verticalLayout_2->addWidget(comboType);

        labelQuantite = new QLabel(groupBoxForm);
        labelQuantite->setObjectName("labelQuantite");

        verticalLayout_2->addWidget(labelQuantite);

        spinQuantite = new QDoubleSpinBox(groupBoxForm);
        spinQuantite->setObjectName("spinQuantite");

        verticalLayout_2->addWidget(spinQuantite);

        labelPrix = new QLabel(groupBoxForm);
        labelPrix->setObjectName("labelPrix");

        verticalLayout_2->addWidget(labelPrix);

        spinPrixAchat = new QDoubleSpinBox(groupBoxForm);
        spinPrixAchat->setObjectName("spinPrixAchat");
        spinPrixAchat->setDecimals(2);

        verticalLayout_2->addWidget(spinPrixAchat);

        labelSeuil = new QLabel(groupBoxForm);
        labelSeuil->setObjectName("labelSeuil");

        verticalLayout_2->addWidget(labelSeuil);

        spinSeuilAlerte = new QSpinBox(groupBoxForm);
        spinSeuilAlerte->setObjectName("spinSeuilAlerte");
        spinSeuilAlerte->setMinimum(1);
        spinSeuilAlerte->setMaximum(10000);
        spinSeuilAlerte->setValue(10);

        verticalLayout_2->addWidget(spinSeuilAlerte);

        btnAjouter = new QPushButton(groupBoxForm);
        btnAjouter->setObjectName("btnAjouter");

        verticalLayout_2->addWidget(btnAjouter);

        btnModifier = new QPushButton(groupBoxForm);
        btnModifier->setObjectName("btnModifier");

        verticalLayout_2->addWidget(btnModifier);

        btnDelete = new QPushButton(groupBoxForm);
        btnDelete->setObjectName("btnDelete");

        verticalLayout_2->addWidget(btnDelete);

        btnNouveau = new QPushButton(groupBoxForm);
        btnNouveau->setObjectName("btnNouveau");

        verticalLayout_2->addWidget(btnNouveau);


        horizontalLayout->addWidget(groupBoxForm);

        groupBoxRecherche = new QGroupBox(tabGestion);
        groupBoxRecherche->setObjectName("groupBoxRecherche");
        verticalLayout_3 = new QVBoxLayout(groupBoxRecherche);
        verticalLayout_3->setObjectName("verticalLayout_3");
        txtRecherche = new QLineEdit(groupBoxRecherche);
        txtRecherche->setObjectName("txtRecherche");

        verticalLayout_3->addWidget(txtRecherche);

        comboFiltreType = new QComboBox(groupBoxRecherche);
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->setObjectName("comboFiltreType");

        verticalLayout_3->addWidget(comboFiltreType);

        btnRechercher = new QPushButton(groupBoxRecherche);
        btnRechercher->setObjectName("btnRechercher");

        verticalLayout_3->addWidget(btnRechercher);

        tableWidget = new QTableWidget(groupBoxRecherche);
        if (tableWidget->columnCount() < 6)
            tableWidget->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        tableWidget->setObjectName("tableWidget");

        verticalLayout_3->addWidget(tableWidget);


        horizontalLayout->addWidget(groupBoxRecherche);

        tabWidget->addTab(tabGestion, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayout_4 = new QVBoxLayout(tabStatistiques);
        verticalLayout_4->setObjectName("verticalLayout_4");
        horizontalLayoutStats = new QHBoxLayout();
        horizontalLayoutStats->setObjectName("horizontalLayoutStats");
        labelTotal = new QLabel(tabStatistiques);
        labelTotal->setObjectName("labelTotal");
        QFont font;
        font.setPointSize(11);
        font.setBold(true);
        labelTotal->setFont(font);

        horizontalLayoutStats->addWidget(labelTotal);

        lblTotalMateriaux = new QLabel(tabStatistiques);
        lblTotalMateriaux->setObjectName("lblTotalMateriaux");
        lblTotalMateriaux->setFont(font);

        horizontalLayoutStats->addWidget(lblTotalMateriaux);

        labelTypes = new QLabel(tabStatistiques);
        labelTypes->setObjectName("labelTypes");
        labelTypes->setFont(font);

        horizontalLayoutStats->addWidget(labelTypes);

        lblTypesMateriaux = new QLabel(tabStatistiques);
        lblTypesMateriaux->setObjectName("lblTypesMateriaux");
        lblTypesMateriaux->setFont(font);

        horizontalLayoutStats->addWidget(lblTypesMateriaux);

        horizontalSpacerStats = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        horizontalLayoutStats->addItem(horizontalSpacerStats);


        verticalLayout_4->addLayout(horizontalLayoutStats);

        tableStats = new QTableWidget(tabStatistiques);
        if (tableStats->columnCount() < 4)
            tableStats->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(0, __qtablewidgetitem6);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(1, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(2, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(3, __qtablewidgetitem9);
        tableStats->setObjectName("tableStats");

        verticalLayout_4->addWidget(tableStats);

        btnActualiserStats = new QPushButton(tabStatistiques);
        btnActualiserStats->setObjectName("btnActualiserStats");

        verticalLayout_4->addWidget(btnActualiserStats);

        tabWidget->addTab(tabStatistiques, QString());
        tabInnovant = new QWidget();
        tabInnovant->setObjectName("tabInnovant");
        verticalLayout_5 = new QVBoxLayout(tabInnovant);
        verticalLayout_5->setObjectName("verticalLayout_5");
        btnGenererReappro = new QPushButton(tabInnovant);
        btnGenererReappro->setObjectName("btnGenererReappro");

        verticalLayout_5->addWidget(btnGenererReappro);

        tableReappro = new QTableWidget(tabInnovant);
        if (tableReappro->columnCount() < 4)
            tableReappro->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(0, __qtablewidgetitem10);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(1, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(2, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(3, __qtablewidgetitem13);
        tableReappro->setObjectName("tableReappro");

        verticalLayout_5->addWidget(tableReappro);

        labelPrevision = new QLabel(tabInnovant);
        labelPrevision->setObjectName("labelPrevision");
        QFont font1;
        font1.setPointSize(12);
        font1.setBold(true);
        labelPrevision->setFont(font1);

        verticalLayout_5->addWidget(labelPrevision);

        gridLayoutPrevision = new QGridLayout();
        gridLayoutPrevision->setObjectName("gridLayoutPrevision");
        labelNbCommandes = new QLabel(tabInnovant);
        labelNbCommandes->setObjectName("labelNbCommandes");
        labelNbCommandes->setMinimumSize(QSize(250, 0));

        gridLayoutPrevision->addWidget(labelNbCommandes, 0, 0, 1, 1);

        spinNbCommandes = new QSpinBox(tabInnovant);
        spinNbCommandes->setObjectName("spinNbCommandes");
        spinNbCommandes->setMinimum(1);
        spinNbCommandes->setMaximum(1000);
        spinNbCommandes->setValue(10);
        spinNbCommandes->setMinimumSize(QSize(120, 0));

        gridLayoutPrevision->addWidget(spinNbCommandes, 0, 1, 1, 1);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayoutPrevision->addItem(horizontalSpacer, 0, 2, 1, 1);

        labelPeriode = new QLabel(tabInnovant);
        labelPeriode->setObjectName("labelPeriode");
        labelPeriode->setMinimumSize(QSize(250, 0));

        gridLayoutPrevision->addWidget(labelPeriode, 1, 0, 1, 1);

        spinPeriode = new QSpinBox(tabInnovant);
        spinPeriode->setObjectName("spinPeriode");
        spinPeriode->setMinimum(1);
        spinPeriode->setMaximum(365);
        spinPeriode->setValue(30);
        spinPeriode->setMinimumSize(QSize(120, 0));

        gridLayoutPrevision->addWidget(spinPeriode, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Minimum);

        gridLayoutPrevision->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        btnPrevision = new QPushButton(tabInnovant);
        btnPrevision->setObjectName("btnPrevision");
        btnPrevision->setMinimumSize(QSize(200, 35));

        gridLayoutPrevision->addWidget(btnPrevision, 2, 0, 1, 2);


        verticalLayout_5->addLayout(gridLayoutPrevision);

        tablePrevision = new QTableWidget(tabInnovant);
        if (tablePrevision->columnCount() < 5)
            tablePrevision->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(0, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(1, __qtablewidgetitem15);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(2, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(3, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(4, __qtablewidgetitem18);
        tablePrevision->setObjectName("tablePrevision");

        verticalLayout_5->addWidget(tablePrevision);

        tabWidget->addTab(tabInnovant, QString());
        tabTriQuantite = new QWidget();
        tabTriQuantite->setObjectName("tabTriQuantite");
        verticalLayout_6 = new QVBoxLayout(tabTriQuantite);
        verticalLayout_6->setObjectName("verticalLayout_6");
        groupBoxTri = new QGroupBox(tabTriQuantite);
        groupBoxTri->setObjectName("groupBoxTri");
        verticalLayout_tri = new QVBoxLayout(groupBoxTri);
        verticalLayout_tri->setObjectName("verticalLayout_tri");
        horizontalLayout_tri = new QHBoxLayout();
        horizontalLayout_tri->setObjectName("horizontalLayout_tri");
        radioCroissant = new QRadioButton(groupBoxTri);
        radioCroissant->setObjectName("radioCroissant");
        radioCroissant->setChecked(true);

        horizontalLayout_tri->addWidget(radioCroissant);

        radioDecroissant = new QRadioButton(groupBoxTri);
        radioDecroissant->setObjectName("radioDecroissant");

        horizontalLayout_tri->addWidget(radioDecroissant);


        verticalLayout_tri->addLayout(horizontalLayout_tri);

        btnAppliquerTri = new QPushButton(groupBoxTri);
        btnAppliquerTri->setObjectName("btnAppliquerTri");

        verticalLayout_tri->addWidget(btnAppliquerTri);

        tableTriQuantite = new QTableWidget(groupBoxTri);
        if (tableTriQuantite->columnCount() < 6)
            tableTriQuantite->setColumnCount(6);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tableTriQuantite->setHorizontalHeaderItem(0, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tableTriQuantite->setHorizontalHeaderItem(1, __qtablewidgetitem20);
        QTableWidgetItem *__qtablewidgetitem21 = new QTableWidgetItem();
        tableTriQuantite->setHorizontalHeaderItem(2, __qtablewidgetitem21);
        QTableWidgetItem *__qtablewidgetitem22 = new QTableWidgetItem();
        tableTriQuantite->setHorizontalHeaderItem(3, __qtablewidgetitem22);
        QTableWidgetItem *__qtablewidgetitem23 = new QTableWidgetItem();
        tableTriQuantite->setHorizontalHeaderItem(4, __qtablewidgetitem23);
        QTableWidgetItem *__qtablewidgetitem24 = new QTableWidgetItem();
        tableTriQuantite->setHorizontalHeaderItem(5, __qtablewidgetitem24);
        tableTriQuantite->setObjectName("tableTriQuantite");

        verticalLayout_tri->addWidget(tableTriQuantite);


        verticalLayout_6->addWidget(groupBoxTri);

        tabWidget->addTab(tabTriQuantite, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(StockWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StockWidget);
    } // setupUi

    void retranslateUi(QWidget *StockWidget)
    {
        StockWidget->setWindowTitle(QCoreApplication::translate("StockWidget", "Gestion du Stock", nullptr));
        lblTitle->setText(QCoreApplication::translate("StockWidget", "\360\237\224\247 Gestion du Stock - Menuiserie", nullptr));
        groupBoxForm->setTitle(QCoreApplication::translate("StockWidget", "Informations du Mat\303\251riau", nullptr));
        labelNom->setText(QCoreApplication::translate("StockWidget", "\360\237\223\235 Nom:", nullptr));
        labelType->setText(QCoreApplication::translate("StockWidget", "\360\237\217\267\357\270\217 Type:", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("StockWidget", "Bois", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("StockWidget", "Clou", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("StockWidget", "Vernis", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("StockWidget", "Colle", nullptr));
        comboType->setItemText(4, QCoreApplication::translate("StockWidget", "Peinture", nullptr));
        comboType->setItemText(5, QCoreApplication::translate("StockWidget", "Vis", nullptr));
        comboType->setItemText(6, QCoreApplication::translate("StockWidget", "Charni\303\250re", nullptr));
        comboType->setItemText(7, QCoreApplication::translate("StockWidget", "Autre", nullptr));

        labelQuantite->setText(QCoreApplication::translate("StockWidget", "\360\237\223\212 Quantit\303\251:", nullptr));
        spinQuantite->setSuffix(QCoreApplication::translate("StockWidget", " unit\303\251s", nullptr));
        labelPrix->setText(QCoreApplication::translate("StockWidget", "\360\237\222\260 Prix d'Achat:", nullptr));
        spinPrixAchat->setSuffix(QCoreApplication::translate("StockWidget", " TND", nullptr));
        labelSeuil->setText(QCoreApplication::translate("StockWidget", "\342\232\240\357\270\217 Seuil d'Alerte:", nullptr));
        spinSeuilAlerte->setSuffix(QCoreApplication::translate("StockWidget", " unit\303\251s", nullptr));
        btnAjouter->setText(QCoreApplication::translate("StockWidget", "\342\236\225 Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("StockWidget", "\342\234\217\357\270\217 Modifier", nullptr));
        btnDelete->setText(QCoreApplication::translate("StockWidget", "\360\237\227\221\357\270\217 Supprimer", nullptr));
        btnNouveau->setText(QCoreApplication::translate("StockWidget", "\360\237\206\225 Nouveau", nullptr));
        groupBoxRecherche->setTitle(QCoreApplication::translate("StockWidget", "\360\237\224\215 Recherche", nullptr));
        txtRecherche->setPlaceholderText(QCoreApplication::translate("StockWidget", "Nom du mat\303\251riau...", nullptr));
        comboFiltreType->setItemText(0, QCoreApplication::translate("StockWidget", "Tous les types", nullptr));
        comboFiltreType->setItemText(1, QCoreApplication::translate("StockWidget", "Bois", nullptr));
        comboFiltreType->setItemText(2, QCoreApplication::translate("StockWidget", "Clou", nullptr));
        comboFiltreType->setItemText(3, QCoreApplication::translate("StockWidget", "Vernis", nullptr));
        comboFiltreType->setItemText(4, QCoreApplication::translate("StockWidget", "Colle", nullptr));
        comboFiltreType->setItemText(5, QCoreApplication::translate("StockWidget", "Peinture", nullptr));
        comboFiltreType->setItemText(6, QCoreApplication::translate("StockWidget", "Vis", nullptr));
        comboFiltreType->setItemText(7, QCoreApplication::translate("StockWidget", "Charni\303\250re", nullptr));

        btnRechercher->setText(QCoreApplication::translate("StockWidget", "\360\237\224\215 Rechercher", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StockWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StockWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StockWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StockWidget", "Prix", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StockWidget", "Seuil", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QCoreApplication::translate("StockWidget", "\360\237\223\246 Gestion des Mat\303\251riaux", nullptr));
        labelTotal->setText(QCoreApplication::translate("StockWidget", "\360\237\223\246 Total Mat\303\251riaux :", nullptr));
        lblTotalMateriaux->setText(QCoreApplication::translate("StockWidget", "0", nullptr));
        labelTypes->setText(QCoreApplication::translate("StockWidget", "   \360\237\217\267\357\270\217 Types de Mat\303\251riaux :", nullptr));
        lblTypesMateriaux->setText(QCoreApplication::translate("StockWidget", "0", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableStats->horizontalHeaderItem(0);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("StockWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableStats->horizontalHeaderItem(1);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("StockWidget", "Nombre d'articles", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableStats->horizontalHeaderItem(2);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251 Totale", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableStats->horizontalHeaderItem(3);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("StockWidget", "Pourcentage", nullptr));
        btnActualiserStats->setText(QCoreApplication::translate("StockWidget", "\360\237\224\204 Actualiser les Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("StockWidget", "\360\237\223\212 Statistiques", nullptr));
        btnGenererReappro->setText(QCoreApplication::translate("StockWidget", "\360\237\224\256 G\303\251n\303\251rer R\303\251approvisionnement", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableReappro->horizontalHeaderItem(0);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("StockWidget", "Mat\303\251riau", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableReappro->horizontalHeaderItem(1);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("StockWidget", "Stock Actuel", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableReappro->horizontalHeaderItem(2);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251 Recommand\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableReappro->horizontalHeaderItem(3);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("StockWidget", "Priorit\303\251", nullptr));
        labelPrevision->setText(QCoreApplication::translate("StockWidget", "\360\237\223\212 Pr\303\251vision de Consommation selon les Commandes", nullptr));
        labelNbCommandes->setText(QCoreApplication::translate("StockWidget", "\360\237\223\246 Nombre de commandes pr\303\251vues :", nullptr));
        labelPeriode->setText(QCoreApplication::translate("StockWidget", "\360\237\223\205 P\303\251riode (jours) :", nullptr));
        btnPrevision->setText(QCoreApplication::translate("StockWidget", "\360\237\223\210 Calculer Pr\303\251visions", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tablePrevision->horizontalHeaderItem(0);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("StockWidget", "Mat\303\251riau", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tablePrevision->horizontalHeaderItem(1);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("StockWidget", "Consommation Moyenne", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tablePrevision->horizontalHeaderItem(2);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("StockWidget", "Consommation Pr\303\251vue", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tablePrevision->horizontalHeaderItem(3);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("StockWidget", "Stock Actuel", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tablePrevision->horizontalHeaderItem(4);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("StockWidget", "Stock Suffisant?", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInnovant), QCoreApplication::translate("StockWidget", "\360\237\244\226 M\303\251tiers Innovants", nullptr));
        groupBoxTri->setTitle(QCoreApplication::translate("StockWidget", "Trier les mat\303\251riaux par quantit\303\251", nullptr));
        radioCroissant->setText(QCoreApplication::translate("StockWidget", "\360\237\223\210 Croissant (du plus petit au plus grand)", nullptr));
        radioDecroissant->setText(QCoreApplication::translate("StockWidget", "\360\237\223\211 D\303\251croissant (du plus grand au plus petit)", nullptr));
        btnAppliquerTri->setText(QCoreApplication::translate("StockWidget", "\342\234\205 Appliquer le tri", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tableTriQuantite->horizontalHeaderItem(0);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("StockWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tableTriQuantite->horizontalHeaderItem(1);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("StockWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem21 = tableTriQuantite->horizontalHeaderItem(2);
        ___qtablewidgetitem21->setText(QCoreApplication::translate("StockWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem22 = tableTriQuantite->horizontalHeaderItem(3);
        ___qtablewidgetitem22->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem23 = tableTriQuantite->horizontalHeaderItem(4);
        ___qtablewidgetitem23->setText(QCoreApplication::translate("StockWidget", "Prix", nullptr));
        QTableWidgetItem *___qtablewidgetitem24 = tableTriQuantite->horizontalHeaderItem(5);
        ___qtablewidgetitem24->setText(QCoreApplication::translate("StockWidget", "Seuil", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabTriQuantite), QCoreApplication::translate("StockWidget", "\360\237\223\212 Tri par Quantit\303\251", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StockWidget: public Ui_StockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWIDGET_H
