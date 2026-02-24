/********************************************************************************
** Form generated from reading UI file 'StockWidget.ui'
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
    QLabel *label;
    QLineEdit *txtIdMateriau;
    QLabel *label_2;
    QLineEdit *txtNom;
    QLabel *label_3;
    QComboBox *comboType;
    QLabel *label_4;
    QDoubleSpinBox *spinQuantite;
    QLabel *label_5;
    QDoubleSpinBox *spinSeuilAlerte;
    QLabel *label_6;
    QLineEdit *txtResponsable;
    QSpacerItem *verticalSpacer;
    QPushButton *btnAjouter;
    QPushButton *btnModifier;
    QPushButton *btnDelete;
    QPushButton *btnNouveau;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBoxRecherche;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_7;
    QLineEdit *txtRecherche;
    QLabel *label_8;
    QComboBox *comboFiltreType;
    QPushButton *btnRechercher;
    QLabel *lblAlert;
    QTableWidget *tableWidget;
    QWidget *tabStatistiques;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLabel *label_9;
    QLabel *lblTotalMateriaux;
    QLabel *label_11;
    QLabel *lblMateriauxAlerte;
    QLabel *label_13;
    QLabel *lblTypesMateriaux;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_5;
    QTableWidget *tableStats;
    QPushButton *btnActualiserStats;
    QWidget *tabInnovant;
    QVBoxLayout *verticalLayout_6;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_7;
    QLabel *label_14;
    QPushButton *btnGenererReappro;
    QTableWidget *tableReappro;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_15;
    QSpinBox *spinNbCommandes;
    QLabel *label_16;
    QSpinBox *spinPeriode;
    QPushButton *btnPrevision;
    QTableWidget *tablePrevision;
    QWidget *tabExport;
    QVBoxLayout *verticalLayout_9;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_10;
    QLabel *label_17;
    QPushButton *btnExportExcel;
    QPushButton *btnExportCSV;
    QPushButton *btnExportPDF;
    QSpacerItem *verticalSpacer_2;

    void setupUi(QWidget *StockWidget)
    {
        if (StockWidget->objectName().isEmpty())
            StockWidget->setObjectName("StockWidget");
        StockWidget->resize(1400, 900);
        StockWidget->setStyleSheet(QString::fromUtf8("QWidget {\n"
"    background-color: #FAF3E0;\n"
"}\n"
"\n"
"QPushButton {\n"
"    background-color: #8B6F47;\n"
"    color: white;\n"
"    border: none;\n"
"    padding: 8px 16px;\n"
"    border-radius: 4px;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"    background-color: #6B4423;\n"
"}\n"
"\n"
"QPushButton:pressed {\n"
"    background-color: #5A3A1F;\n"
"}\n"
"\n"
"QPushButton#btnDelete {\n"
"    background-color: #6B4423;\n"
"}\n"
"\n"
"QPushButton#btnDelete:hover {\n"
"    background-color: #5A3A1F;\n"
"}\n"
"\n"
"QPushButton#btnNouveau {\n"
"    background-color: #A4A964;\n"
"}\n"
"\n"
"QPushButton#btnNouveau:hover {\n"
"    background-color: #8B8B4F;\n"
"}\n"
"\n"
"QPushButton#btnExportExcel {\n"
"    background-color: #A4A964;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton#btnExportExcel:hover {\n"
"    background-color: #8B8B4F;\n"
"}\n"
"\n"
"QPushButton#btnExportCSV {\n"
"    background-color: #C4B69C;\n"
"    color: #333;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton"
                        "#btnExportCSV:hover {\n"
"    background-color: #B0A082;\n"
"}\n"
"\n"
"QPushButton#btnExportPDF {\n"
"    background-color: #8B6F47;\n"
"    font-size: 14px;\n"
"}\n"
"\n"
"QPushButton#btnExportPDF:hover {\n"
"    background-color: #6B4423;\n"
"}\n"
"\n"
"QGroupBox {\n"
"    font-weight: bold;\n"
"    border: 2px solid #8B6F47;\n"
"    border-radius: 5px;\n"
"    margin-top: 10px;\n"
"    padding-top: 10px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QGroupBox::title {\n"
"    subcontrol-origin: margin;\n"
"    left: 10px;\n"
"    padding: 0 5px;\n"
"    color: #6B4423;\n"
"}\n"
"\n"
"QLineEdit, QSpinBox, QDoubleSpinBox, QComboBox {\n"
"    padding: 6px;\n"
"    border: 2px solid #C4B69C;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QLineEdit:focus, QSpinBox:focus, QDoubleSpinBox:focus, QComboBox:focus {\n"
"    border: 2px solid #8B6F47;\n"
"}\n"
"\n"
"QTableWidget {\n"
"    border: 2px solid #C4B69C;\n"
"    border-radius: 4px;\n"
"    gridline-color: #C4B69C;\n"
"    back"
                        "ground-color: white;\n"
"}\n"
"\n"
"QTableWidget::item:selected {\n"
"    background-color: #8B6F47;\n"
"    color: white;\n"
"}\n"
"\n"
"QTableWidget::item:hover {\n"
"    background-color: #F9E79F;\n"
"}\n"
"\n"
"QHeaderView::section {\n"
"    background-color: #8B6F47;\n"
"    color: white;\n"
"    padding: 8px;\n"
"    border: none;\n"
"    font-weight: bold;\n"
"}\n"
"\n"
"QLabel#lblTitle {\n"
"    font-size: 24px;\n"
"    font-weight: bold;\n"
"    color: #6B4423;\n"
"    background-color: transparent;\n"
"}\n"
"\n"
"QLabel#lblAlert {\n"
"    font-size: 14px;\n"
"    font-weight: bold;\n"
"    color: #6B4423;\n"
"    background-color: #F9E79F;\n"
"    padding: 5px;\n"
"    border-radius: 4px;\n"
"}\n"
"\n"
"QTabWidget::pane {\n"
"    border: 2px solid #8B6F47;\n"
"    border-radius: 4px;\n"
"    background-color: white;\n"
"}\n"
"\n"
"QTabBar::tab {\n"
"    background-color: #C4B69C;\n"
"    color: #333;\n"
"    padding: 10px 20px;\n"
"    margin-right: 2px;\n"
"    border-top-left-radius: 4px;\n"
"    b"
                        "order-top-right-radius: 4px;\n"
"}\n"
"\n"
"QTabBar::tab:selected {\n"
"    background-color: #8B6F47;\n"
"    color: white;\n"
"}\n"
"\n"
"QTabBar::tab:hover {\n"
"    background-color: #A4A964;\n"
"    color: white;\n"
"}\n"
"\n"
"QLabel {\n"
"    color: #333;\n"
"}\n"
"\n"
"QSpinBox::up-button, QDoubleSpinBox::up-button {\n"
"    background-color: #8B6F47;\n"
"}\n"
"\n"
"QSpinBox::down-button, QDoubleSpinBox::down-button {\n"
"    background-color: #8B6F47;\n"
"}\n"
"\n"
"QComboBox::drop-down {\n"
"    background-color: #8B6F47;\n"
"}\n"
"\n"
"QComboBox QAbstractItemView {\n"
"    background-color: white;\n"
"    border: 2px solid #8B6F47;\n"
"    selection-background-color: #8B6F47;\n"
"}"));
        verticalLayout = new QVBoxLayout(StockWidget);
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(15, 15, 15, 15);
        lblTitle = new QLabel(StockWidget);
        lblTitle->setObjectName("lblTitle");
        lblTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

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
        label = new QLabel(groupBoxForm);
        label->setObjectName("label");

        verticalLayout_2->addWidget(label);

        txtIdMateriau = new QLineEdit(groupBoxForm);
        txtIdMateriau->setObjectName("txtIdMateriau");
        txtIdMateriau->setReadOnly(true);

        verticalLayout_2->addWidget(txtIdMateriau);

        label_2 = new QLabel(groupBoxForm);
        label_2->setObjectName("label_2");

        verticalLayout_2->addWidget(label_2);

        txtNom = new QLineEdit(groupBoxForm);
        txtNom->setObjectName("txtNom");

        verticalLayout_2->addWidget(txtNom);

        label_3 = new QLabel(groupBoxForm);
        label_3->setObjectName("label_3");

        verticalLayout_2->addWidget(label_3);

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

        label_4 = new QLabel(groupBoxForm);
        label_4->setObjectName("label_4");

        verticalLayout_2->addWidget(label_4);

        spinQuantite = new QDoubleSpinBox(groupBoxForm);
        spinQuantite->setObjectName("spinQuantite");
        spinQuantite->setMaximum(999999.000000000000000);

        verticalLayout_2->addWidget(spinQuantite);

        label_5 = new QLabel(groupBoxForm);
        label_5->setObjectName("label_5");

        verticalLayout_2->addWidget(label_5);

        spinSeuilAlerte = new QDoubleSpinBox(groupBoxForm);
        spinSeuilAlerte->setObjectName("spinSeuilAlerte");
        spinSeuilAlerte->setMaximum(999999.000000000000000);
        spinSeuilAlerte->setValue(10.000000000000000);

        verticalLayout_2->addWidget(spinSeuilAlerte);

        label_6 = new QLabel(groupBoxForm);
        label_6->setObjectName("label_6");

        verticalLayout_2->addWidget(label_6);

        txtResponsable = new QLineEdit(groupBoxForm);
        txtResponsable->setObjectName("txtResponsable");

        verticalLayout_2->addWidget(txtResponsable);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_2->addItem(verticalSpacer);

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

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        groupBoxRecherche = new QGroupBox(tabGestion);
        groupBoxRecherche->setObjectName("groupBoxRecherche");
        horizontalLayout_2 = new QHBoxLayout(groupBoxRecherche);
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_7 = new QLabel(groupBoxRecherche);
        label_7->setObjectName("label_7");

        horizontalLayout_2->addWidget(label_7);

        txtRecherche = new QLineEdit(groupBoxRecherche);
        txtRecherche->setObjectName("txtRecherche");

        horizontalLayout_2->addWidget(txtRecherche);

        label_8 = new QLabel(groupBoxRecherche);
        label_8->setObjectName("label_8");

        horizontalLayout_2->addWidget(label_8);

        comboFiltreType = new QComboBox(groupBoxRecherche);
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->addItem(QString());
        comboFiltreType->setObjectName("comboFiltreType");

        horizontalLayout_2->addWidget(comboFiltreType);

        btnRechercher = new QPushButton(groupBoxRecherche);
        btnRechercher->setObjectName("btnRechercher");

        horizontalLayout_2->addWidget(btnRechercher);


        verticalLayout_3->addWidget(groupBoxRecherche);

        lblAlert = new QLabel(tabGestion);
        lblAlert->setObjectName("lblAlert");

        verticalLayout_3->addWidget(lblAlert);

        tableWidget = new QTableWidget(tabGestion);
        if (tableWidget->columnCount() < 7)
            tableWidget->setColumnCount(7);
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
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        tableWidget->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        tableWidget->setObjectName("tableWidget");
        tableWidget->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);
        tableWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
        tableWidget->setSelectionBehavior(QAbstractItemView::SelectionBehavior::SelectRows);

        verticalLayout_3->addWidget(tableWidget);


        horizontalLayout->addLayout(verticalLayout_3);

        tabWidget->addTab(tabGestion, QString());
        tabStatistiques = new QWidget();
        tabStatistiques->setObjectName("tabStatistiques");
        verticalLayout_4 = new QVBoxLayout(tabStatistiques);
        verticalLayout_4->setObjectName("verticalLayout_4");
        groupBox = new QGroupBox(tabStatistiques);
        groupBox->setObjectName("groupBox");
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName("gridLayout");
        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        label_9->setFont(font);

        gridLayout->addWidget(label_9, 0, 0, 1, 1);

        lblTotalMateriaux = new QLabel(groupBox);
        lblTotalMateriaux->setObjectName("lblTotalMateriaux");
        QFont font1;
        font1.setPointSize(12);
        lblTotalMateriaux->setFont(font1);

        gridLayout->addWidget(lblTotalMateriaux, 0, 1, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName("label_11");
        label_11->setFont(font);

        gridLayout->addWidget(label_11, 1, 0, 1, 1);

        lblMateriauxAlerte = new QLabel(groupBox);
        lblMateriauxAlerte->setObjectName("lblMateriauxAlerte");
        lblMateriauxAlerte->setFont(font);
        lblMateriauxAlerte->setStyleSheet(QString::fromUtf8("color: #6B4423; font-weight: bold;"));

        gridLayout->addWidget(lblMateriauxAlerte, 1, 1, 1, 1);

        label_13 = new QLabel(groupBox);
        label_13->setObjectName("label_13");
        label_13->setFont(font);

        gridLayout->addWidget(label_13, 2, 0, 1, 1);

        lblTypesMateriaux = new QLabel(groupBox);
        lblTypesMateriaux->setObjectName("lblTypesMateriaux");
        lblTypesMateriaux->setFont(font1);

        gridLayout->addWidget(lblTypesMateriaux, 2, 1, 1, 1);


        verticalLayout_4->addWidget(groupBox);

        groupBox_2 = new QGroupBox(tabStatistiques);
        groupBox_2->setObjectName("groupBox_2");
        verticalLayout_5 = new QVBoxLayout(groupBox_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        tableStats = new QTableWidget(groupBox_2);
        if (tableStats->columnCount() < 4)
            tableStats->setColumnCount(4);
        QTableWidgetItem *__qtablewidgetitem7 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(0, __qtablewidgetitem7);
        QTableWidgetItem *__qtablewidgetitem8 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(1, __qtablewidgetitem8);
        QTableWidgetItem *__qtablewidgetitem9 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(2, __qtablewidgetitem9);
        QTableWidgetItem *__qtablewidgetitem10 = new QTableWidgetItem();
        tableStats->setHorizontalHeaderItem(3, __qtablewidgetitem10);
        tableStats->setObjectName("tableStats");
        tableStats->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_5->addWidget(tableStats);


        verticalLayout_4->addWidget(groupBox_2);

        btnActualiserStats = new QPushButton(tabStatistiques);
        btnActualiserStats->setObjectName("btnActualiserStats");

        verticalLayout_4->addWidget(btnActualiserStats);

        tabWidget->addTab(tabStatistiques, QString());
        tabInnovant = new QWidget();
        tabInnovant->setObjectName("tabInnovant");
        verticalLayout_6 = new QVBoxLayout(tabInnovant);
        verticalLayout_6->setObjectName("verticalLayout_6");
        groupBox_3 = new QGroupBox(tabInnovant);
        groupBox_3->setObjectName("groupBox_3");
        verticalLayout_7 = new QVBoxLayout(groupBox_3);
        verticalLayout_7->setObjectName("verticalLayout_7");
        label_14 = new QLabel(groupBox_3);
        label_14->setObjectName("label_14");
        label_14->setWordWrap(true);

        verticalLayout_7->addWidget(label_14);

        btnGenererReappro = new QPushButton(groupBox_3);
        btnGenererReappro->setObjectName("btnGenererReappro");

        verticalLayout_7->addWidget(btnGenererReappro);

        tableReappro = new QTableWidget(groupBox_3);
        if (tableReappro->columnCount() < 5)
            tableReappro->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem11 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(0, __qtablewidgetitem11);
        QTableWidgetItem *__qtablewidgetitem12 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(1, __qtablewidgetitem12);
        QTableWidgetItem *__qtablewidgetitem13 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(2, __qtablewidgetitem13);
        QTableWidgetItem *__qtablewidgetitem14 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(3, __qtablewidgetitem14);
        QTableWidgetItem *__qtablewidgetitem15 = new QTableWidgetItem();
        tableReappro->setHorizontalHeaderItem(4, __qtablewidgetitem15);
        tableReappro->setObjectName("tableReappro");
        tableReappro->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_7->addWidget(tableReappro);


        verticalLayout_6->addWidget(groupBox_3);

        groupBox_4 = new QGroupBox(tabInnovant);
        groupBox_4->setObjectName("groupBox_4");
        verticalLayout_8 = new QVBoxLayout(groupBox_4);
        verticalLayout_8->setObjectName("verticalLayout_8");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_15 = new QLabel(groupBox_4);
        label_15->setObjectName("label_15");

        horizontalLayout_3->addWidget(label_15);

        spinNbCommandes = new QSpinBox(groupBox_4);
        spinNbCommandes->setObjectName("spinNbCommandes");
        spinNbCommandes->setMinimum(1);
        spinNbCommandes->setMaximum(1000);
        spinNbCommandes->setValue(10);

        horizontalLayout_3->addWidget(spinNbCommandes);

        label_16 = new QLabel(groupBox_4);
        label_16->setObjectName("label_16");

        horizontalLayout_3->addWidget(label_16);

        spinPeriode = new QSpinBox(groupBox_4);
        spinPeriode->setObjectName("spinPeriode");
        spinPeriode->setMinimum(1);
        spinPeriode->setMaximum(365);
        spinPeriode->setValue(30);

        horizontalLayout_3->addWidget(spinPeriode);

        btnPrevision = new QPushButton(groupBox_4);
        btnPrevision->setObjectName("btnPrevision");

        horizontalLayout_3->addWidget(btnPrevision);


        verticalLayout_8->addLayout(horizontalLayout_3);

        tablePrevision = new QTableWidget(groupBox_4);
        if (tablePrevision->columnCount() < 5)
            tablePrevision->setColumnCount(5);
        QTableWidgetItem *__qtablewidgetitem16 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(0, __qtablewidgetitem16);
        QTableWidgetItem *__qtablewidgetitem17 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(1, __qtablewidgetitem17);
        QTableWidgetItem *__qtablewidgetitem18 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(2, __qtablewidgetitem18);
        QTableWidgetItem *__qtablewidgetitem19 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(3, __qtablewidgetitem19);
        QTableWidgetItem *__qtablewidgetitem20 = new QTableWidgetItem();
        tablePrevision->setHorizontalHeaderItem(4, __qtablewidgetitem20);
        tablePrevision->setObjectName("tablePrevision");
        tablePrevision->setEditTriggers(QAbstractItemView::EditTrigger::NoEditTriggers);

        verticalLayout_8->addWidget(tablePrevision);


        verticalLayout_6->addWidget(groupBox_4);

        tabWidget->addTab(tabInnovant, QString());
        tabExport = new QWidget();
        tabExport->setObjectName("tabExport");
        verticalLayout_9 = new QVBoxLayout(tabExport);
        verticalLayout_9->setObjectName("verticalLayout_9");
        groupBox_5 = new QGroupBox(tabExport);
        groupBox_5->setObjectName("groupBox_5");
        verticalLayout_10 = new QVBoxLayout(groupBox_5);
        verticalLayout_10->setObjectName("verticalLayout_10");
        label_17 = new QLabel(groupBox_5);
        label_17->setObjectName("label_17");
        label_17->setWordWrap(true);

        verticalLayout_10->addWidget(label_17);

        btnExportExcel = new QPushButton(groupBox_5);
        btnExportExcel->setObjectName("btnExportExcel");
        btnExportExcel->setMinimumSize(QSize(0, 50));

        verticalLayout_10->addWidget(btnExportExcel);

        btnExportCSV = new QPushButton(groupBox_5);
        btnExportCSV->setObjectName("btnExportCSV");
        btnExportCSV->setMinimumSize(QSize(0, 50));

        verticalLayout_10->addWidget(btnExportCSV);

        btnExportPDF = new QPushButton(groupBox_5);
        btnExportPDF->setObjectName("btnExportPDF");
        btnExportPDF->setMinimumSize(QSize(0, 50));

        verticalLayout_10->addWidget(btnExportPDF);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);

        verticalLayout_10->addItem(verticalSpacer_2);


        verticalLayout_9->addWidget(groupBox_5);

        tabWidget->addTab(tabExport, QString());

        verticalLayout->addWidget(tabWidget);


        retranslateUi(StockWidget);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(StockWidget);
    } // setupUi

    void retranslateUi(QWidget *StockWidget)
    {
        StockWidget->setWindowTitle(QCoreApplication::translate("StockWidget", "Gestion du Stock de Mat\303\251riaux", nullptr));
        lblTitle->setText(QCoreApplication::translate("StockWidget", "\360\237\224\247 Gestion du Stock de Mat\303\251riaux - Atelier de Menuiserie", nullptr));
        groupBoxForm->setTitle(QCoreApplication::translate("StockWidget", "Informations du Mat\303\251riau", nullptr));
        label->setText(QCoreApplication::translate("StockWidget", "ID Mat\303\251riau:", nullptr));
        txtIdMateriau->setPlaceholderText(QCoreApplication::translate("StockWidget", "Auto-g\303\251n\303\251r\303\251", nullptr));
        label_2->setText(QCoreApplication::translate("StockWidget", "Nom du Mat\303\251riau: *", nullptr));
        txtNom->setPlaceholderText(QCoreApplication::translate("StockWidget", "Ex: Planche de ch\303\252ne", nullptr));
        label_3->setText(QCoreApplication::translate("StockWidget", "Type: *", nullptr));
        comboType->setItemText(0, QCoreApplication::translate("StockWidget", "Bois", nullptr));
        comboType->setItemText(1, QCoreApplication::translate("StockWidget", "Clou", nullptr));
        comboType->setItemText(2, QCoreApplication::translate("StockWidget", "Vernis", nullptr));
        comboType->setItemText(3, QCoreApplication::translate("StockWidget", "Colle", nullptr));
        comboType->setItemText(4, QCoreApplication::translate("StockWidget", "Peinture", nullptr));
        comboType->setItemText(5, QCoreApplication::translate("StockWidget", "Vis", nullptr));
        comboType->setItemText(6, QCoreApplication::translate("StockWidget", "Charni\303\250re", nullptr));
        comboType->setItemText(7, QCoreApplication::translate("StockWidget", "Autre", nullptr));

        label_4->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251: *", nullptr));
        spinQuantite->setSuffix(QCoreApplication::translate("StockWidget", " unit\303\251s", nullptr));
        label_5->setText(QCoreApplication::translate("StockWidget", "Seuil d'Alerte: *", nullptr));
        spinSeuilAlerte->setSuffix(QCoreApplication::translate("StockWidget", " unit\303\251s", nullptr));
        label_6->setText(QCoreApplication::translate("StockWidget", "Responsable du Stock:", nullptr));
        txtResponsable->setPlaceholderText(QCoreApplication::translate("StockWidget", "Nom du responsable", nullptr));
        btnAjouter->setText(QCoreApplication::translate("StockWidget", "\342\236\225 Ajouter", nullptr));
        btnModifier->setText(QCoreApplication::translate("StockWidget", "\342\234\217\357\270\217 Modifier", nullptr));
        btnDelete->setText(QCoreApplication::translate("StockWidget", "\360\237\227\221\357\270\217 Supprimer", nullptr));
        btnNouveau->setText(QCoreApplication::translate("StockWidget", "\360\237\206\225 Nouveau", nullptr));
        groupBoxRecherche->setTitle(QCoreApplication::translate("StockWidget", "Recherche et Filtres", nullptr));
        label_7->setText(QCoreApplication::translate("StockWidget", "Rechercher:", nullptr));
        txtRecherche->setPlaceholderText(QCoreApplication::translate("StockWidget", "Nom du mat\303\251riau...", nullptr));
        label_8->setText(QCoreApplication::translate("StockWidget", "Type:", nullptr));
        comboFiltreType->setItemText(0, QCoreApplication::translate("StockWidget", "Tous les types", nullptr));
        comboFiltreType->setItemText(1, QCoreApplication::translate("StockWidget", "Bois", nullptr));
        comboFiltreType->setItemText(2, QCoreApplication::translate("StockWidget", "Clou", nullptr));
        comboFiltreType->setItemText(3, QCoreApplication::translate("StockWidget", "Vernis", nullptr));
        comboFiltreType->setItemText(4, QCoreApplication::translate("StockWidget", "Colle", nullptr));
        comboFiltreType->setItemText(5, QCoreApplication::translate("StockWidget", "Peinture", nullptr));
        comboFiltreType->setItemText(6, QCoreApplication::translate("StockWidget", "Vis", nullptr));
        comboFiltreType->setItemText(7, QCoreApplication::translate("StockWidget", "Charni\303\250re", nullptr));
        comboFiltreType->setItemText(8, QCoreApplication::translate("StockWidget", "Autre", nullptr));

        btnRechercher->setText(QCoreApplication::translate("StockWidget", "\360\237\224\215 Rechercher", nullptr));
        lblAlert->setText(QCoreApplication::translate("StockWidget", "\342\232\240\357\270\217 Alertes de Stock Bas: 0 mat\303\251riau(x)", nullptr));
        QTableWidgetItem *___qtablewidgetitem = tableWidget->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QCoreApplication::translate("StockWidget", "ID", nullptr));
        QTableWidgetItem *___qtablewidgetitem1 = tableWidget->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QCoreApplication::translate("StockWidget", "Nom", nullptr));
        QTableWidgetItem *___qtablewidgetitem2 = tableWidget->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QCoreApplication::translate("StockWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem3 = tableWidget->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251", nullptr));
        QTableWidgetItem *___qtablewidgetitem4 = tableWidget->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QCoreApplication::translate("StockWidget", "Seuil Alerte", nullptr));
        QTableWidgetItem *___qtablewidgetitem5 = tableWidget->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QCoreApplication::translate("StockWidget", "Responsable", nullptr));
        QTableWidgetItem *___qtablewidgetitem6 = tableWidget->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QCoreApplication::translate("StockWidget", "Statut", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabGestion), QCoreApplication::translate("StockWidget", "\360\237\223\246 Gestion des Mat\303\251riaux", nullptr));
        groupBox->setTitle(QCoreApplication::translate("StockWidget", "Statistiques G\303\251n\303\251rales", nullptr));
        label_9->setText(QCoreApplication::translate("StockWidget", "Total Mat\303\251riaux:", nullptr));
        lblTotalMateriaux->setText(QCoreApplication::translate("StockWidget", "0", nullptr));
        label_11->setText(QCoreApplication::translate("StockWidget", "Mat\303\251riaux en Alerte:", nullptr));
        lblMateriauxAlerte->setText(QCoreApplication::translate("StockWidget", "0", nullptr));
        label_13->setText(QCoreApplication::translate("StockWidget", "Types de Mat\303\251riaux:", nullptr));
        lblTypesMateriaux->setText(QCoreApplication::translate("StockWidget", "0", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("StockWidget", "R\303\251partition par Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem7 = tableStats->horizontalHeaderItem(0);
        ___qtablewidgetitem7->setText(QCoreApplication::translate("StockWidget", "Type", nullptr));
        QTableWidgetItem *___qtablewidgetitem8 = tableStats->horizontalHeaderItem(1);
        ___qtablewidgetitem8->setText(QCoreApplication::translate("StockWidget", "Nombre d'articles", nullptr));
        QTableWidgetItem *___qtablewidgetitem9 = tableStats->horizontalHeaderItem(2);
        ___qtablewidgetitem9->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251 Totale", nullptr));
        QTableWidgetItem *___qtablewidgetitem10 = tableStats->horizontalHeaderItem(3);
        ___qtablewidgetitem10->setText(QCoreApplication::translate("StockWidget", "Pourcentage", nullptr));
        btnActualiserStats->setText(QCoreApplication::translate("StockWidget", "\360\237\224\204 Actualiser les Statistiques", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabStatistiques), QCoreApplication::translate("StockWidget", "\360\237\223\212 Statistiques & Consommation", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("StockWidget", "1. Proposition Automatique de R\303\251approvisionnement", nullptr));
        label_14->setText(QCoreApplication::translate("StockWidget", "Le syst\303\250me analyse automatiquement le stock et propose les mat\303\251riaux \303\240 r\303\251approvisionner", nullptr));
        btnGenererReappro->setText(QCoreApplication::translate("StockWidget", "\360\237\224\256 G\303\251n\303\251rer Propositions de R\303\251approvisionnement", nullptr));
        QTableWidgetItem *___qtablewidgetitem11 = tableReappro->horizontalHeaderItem(0);
        ___qtablewidgetitem11->setText(QCoreApplication::translate("StockWidget", "Mat\303\251riau", nullptr));
        QTableWidgetItem *___qtablewidgetitem12 = tableReappro->horizontalHeaderItem(1);
        ___qtablewidgetitem12->setText(QCoreApplication::translate("StockWidget", "Stock Actuel", nullptr));
        QTableWidgetItem *___qtablewidgetitem13 = tableReappro->horizontalHeaderItem(2);
        ___qtablewidgetitem13->setText(QCoreApplication::translate("StockWidget", "Seuil Alerte", nullptr));
        QTableWidgetItem *___qtablewidgetitem14 = tableReappro->horizontalHeaderItem(3);
        ___qtablewidgetitem14->setText(QCoreApplication::translate("StockWidget", "Quantit\303\251 Recommand\303\251e", nullptr));
        QTableWidgetItem *___qtablewidgetitem15 = tableReappro->horizontalHeaderItem(4);
        ___qtablewidgetitem15->setText(QCoreApplication::translate("StockWidget", "Priorit\303\251", nullptr));
        groupBox_4->setTitle(QCoreApplication::translate("StockWidget", "2. Pr\303\251vision de Consommation selon les Commandes", nullptr));
        label_15->setText(QCoreApplication::translate("StockWidget", "Nombre de commandes pr\303\251vues:", nullptr));
        label_16->setText(QCoreApplication::translate("StockWidget", "P\303\251riode (jours):", nullptr));
        btnPrevision->setText(QCoreApplication::translate("StockWidget", "\360\237\223\210 Calculer Pr\303\251visions", nullptr));
        QTableWidgetItem *___qtablewidgetitem16 = tablePrevision->horizontalHeaderItem(0);
        ___qtablewidgetitem16->setText(QCoreApplication::translate("StockWidget", "Mat\303\251riau", nullptr));
        QTableWidgetItem *___qtablewidgetitem17 = tablePrevision->horizontalHeaderItem(1);
        ___qtablewidgetitem17->setText(QCoreApplication::translate("StockWidget", "Consommation Moyenne", nullptr));
        QTableWidgetItem *___qtablewidgetitem18 = tablePrevision->horizontalHeaderItem(2);
        ___qtablewidgetitem18->setText(QCoreApplication::translate("StockWidget", "Consommation Pr\303\251vue", nullptr));
        QTableWidgetItem *___qtablewidgetitem19 = tablePrevision->horizontalHeaderItem(3);
        ___qtablewidgetitem19->setText(QCoreApplication::translate("StockWidget", "Stock Actuel", nullptr));
        QTableWidgetItem *___qtablewidgetitem20 = tablePrevision->horizontalHeaderItem(4);
        ___qtablewidgetitem20->setText(QCoreApplication::translate("StockWidget", "Stock Suffisant?", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabInnovant), QCoreApplication::translate("StockWidget", "\360\237\244\226 M\303\251tiers Innovants", nullptr));
        groupBox_5->setTitle(QCoreApplication::translate("StockWidget", "Export des Donn\303\251es", nullptr));
        label_17->setText(QCoreApplication::translate("StockWidget", "Exportez vos donn\303\251es de stock au format Excel pour archivage ou analyse externe", nullptr));
        btnExportExcel->setText(QCoreApplication::translate("StockWidget", "\360\237\223\212 Exporter en Excel (.xlsx)", nullptr));
        btnExportCSV->setText(QCoreApplication::translate("StockWidget", "\360\237\223\213 Exporter en CSV", nullptr));
        btnExportPDF->setText(QCoreApplication::translate("StockWidget", "\360\237\223\204 G\303\251n\303\251rer Rapport PDF", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tabExport), QCoreApplication::translate("StockWidget", "\360\237\223\204 Export & Rapports", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StockWidget: public Ui_StockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWIDGET_H
