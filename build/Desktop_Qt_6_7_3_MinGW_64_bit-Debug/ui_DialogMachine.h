/********************************************************************************
** Form generated from reading UI file 'DialogMachine.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGMACHINE_H
#define UI_DIALOGMACHINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_DialogMachine
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QFormLayout *formLayout;
    QLabel *label;
    QLineEdit *lineEditID;
    QLabel *label_2;
    QLineEdit *lineEditReference;
    QLabel *label_3;
    QLineEdit *lineEditNom;
    QLabel *label_4;
    QComboBox *comboBoxType;
    QLabel *label_5;
    QComboBox *comboBoxEtat;
    QLabel *label_6;
    QDateEdit *dateEditMaintenance;
    QLabel *label_7;
    QSpinBox *spinBoxHeures;
    QLabel *label_8;
    QSpinBox *spinBoxQuantite;
    QLabel *label_9;
    QLineEdit *lineEditRespMaintenance;
    QLabel *label_10;
    QLineEdit *lineEditRespAtelier;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *DialogMachine)
    {
        if (DialogMachine->objectName().isEmpty())
            DialogMachine->setObjectName("DialogMachine");
        DialogMachine->resize(500, 600);
        DialogMachine->setStyleSheet(QString::fromUtf8("QDialog {\n"
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
"QLineEdit, QComboBox, QSpinBox, QDateEdit {\n"
"    background-color: #FFFFFF;\n"
" "
                        "   border: 2px solid #C9B896;\n"
"    border-radius: 5px;\n"
"    padding: 8px;\n"
"    font-size: 10pt;\n"
"}\n"
"\n"
"QLineEdit:focus, QComboBox:focus, QSpinBox:focus, QDateEdit:focus {\n"
"    border: 2px solid #8B6F47;\n"
"}"));
        DialogMachine->setModal(true);
        verticalLayout = new QVBoxLayout(DialogMachine);
        verticalLayout->setObjectName("verticalLayout");
        groupBox = new QGroupBox(DialogMachine);
        groupBox->setObjectName("groupBox");
        formLayout = new QFormLayout(groupBox);
        formLayout->setObjectName("formLayout");
        label = new QLabel(groupBox);
        label->setObjectName("label");

        formLayout->setWidget(0, QFormLayout::LabelRole, label);

        lineEditID = new QLineEdit(groupBox);
        lineEditID->setObjectName("lineEditID");
        lineEditID->setReadOnly(true);

        formLayout->setWidget(0, QFormLayout::FieldRole, lineEditID);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName("label_2");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_2);

        lineEditReference = new QLineEdit(groupBox);
        lineEditReference->setObjectName("lineEditReference");

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEditReference);

        label_3 = new QLabel(groupBox);
        label_3->setObjectName("label_3");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_3);

        lineEditNom = new QLineEdit(groupBox);
        lineEditNom->setObjectName("lineEditNom");

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEditNom);

        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");

        formLayout->setWidget(3, QFormLayout::LabelRole, label_4);

        comboBoxType = new QComboBox(groupBox);
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->addItem(QString());
        comboBoxType->setObjectName("comboBoxType");

        formLayout->setWidget(3, QFormLayout::FieldRole, comboBoxType);

        label_5 = new QLabel(groupBox);
        label_5->setObjectName("label_5");

        formLayout->setWidget(4, QFormLayout::LabelRole, label_5);

        comboBoxEtat = new QComboBox(groupBox);
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->addItem(QString());
        comboBoxEtat->setObjectName("comboBoxEtat");

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxEtat);

        label_6 = new QLabel(groupBox);
        label_6->setObjectName("label_6");

        formLayout->setWidget(5, QFormLayout::LabelRole, label_6);

        dateEditMaintenance = new QDateEdit(groupBox);
        dateEditMaintenance->setObjectName("dateEditMaintenance");
        dateEditMaintenance->setCalendarPopup(true);

        formLayout->setWidget(5, QFormLayout::FieldRole, dateEditMaintenance);

        label_7 = new QLabel(groupBox);
        label_7->setObjectName("label_7");

        formLayout->setWidget(6, QFormLayout::LabelRole, label_7);

        spinBoxHeures = new QSpinBox(groupBox);
        spinBoxHeures->setObjectName("spinBoxHeures");
        spinBoxHeures->setMaximum(999999);

        formLayout->setWidget(6, QFormLayout::FieldRole, spinBoxHeures);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName("label_8");

        formLayout->setWidget(7, QFormLayout::LabelRole, label_8);

        spinBoxQuantite = new QSpinBox(groupBox);
        spinBoxQuantite->setObjectName("spinBoxQuantite");
        spinBoxQuantite->setMinimum(1);
        spinBoxQuantite->setMaximum(100);

        formLayout->setWidget(7, QFormLayout::FieldRole, spinBoxQuantite);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName("label_9");

        formLayout->setWidget(8, QFormLayout::LabelRole, label_9);

        lineEditRespMaintenance = new QLineEdit(groupBox);
        lineEditRespMaintenance->setObjectName("lineEditRespMaintenance");

        formLayout->setWidget(8, QFormLayout::FieldRole, lineEditRespMaintenance);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName("label_10");

        formLayout->setWidget(9, QFormLayout::LabelRole, label_10);

        lineEditRespAtelier = new QLineEdit(groupBox);
        lineEditRespAtelier->setObjectName("lineEditRespAtelier");

        formLayout->setWidget(9, QFormLayout::FieldRole, lineEditRespAtelier);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(DialogMachine);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(DialogMachine);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, DialogMachine, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, DialogMachine, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(DialogMachine);
    } // setupUi

    void retranslateUi(QDialog *DialogMachine)
    {
        DialogMachine->setWindowTitle(QCoreApplication::translate("DialogMachine", "Gestion Machine", nullptr));
        groupBox->setTitle(QCoreApplication::translate("DialogMachine", "Informations Machine", nullptr));
        label->setText(QCoreApplication::translate("DialogMachine", "ID Machine :", nullptr));
        lineEditID->setPlaceholderText(QCoreApplication::translate("DialogMachine", "Auto-g\303\251n\303\251r\303\251", nullptr));
        label_2->setText(QCoreApplication::translate("DialogMachine", "R\303\251f\303\251rence :", nullptr));
        lineEditReference->setPlaceholderText(QCoreApplication::translate("DialogMachine", "Ex: SCE-001", nullptr));
        label_3->setText(QCoreApplication::translate("DialogMachine", "Nom :", nullptr));
        lineEditNom->setPlaceholderText(QCoreApplication::translate("DialogMachine", "Ex: Scie circulaire principale", nullptr));
        label_4->setText(QCoreApplication::translate("DialogMachine", "Type :", nullptr));
        comboBoxType->setItemText(0, QCoreApplication::translate("DialogMachine", "Scie", nullptr));
        comboBoxType->setItemText(1, QCoreApplication::translate("DialogMachine", "Perceuse", nullptr));
        comboBoxType->setItemText(2, QCoreApplication::translate("DialogMachine", "Raboteuse", nullptr));
        comboBoxType->setItemText(3, QCoreApplication::translate("DialogMachine", "Ponceuse", nullptr));
        comboBoxType->setItemText(4, QCoreApplication::translate("DialogMachine", "D\303\251fonceuse", nullptr));
        comboBoxType->setItemText(5, QCoreApplication::translate("DialogMachine", "Tour \303\240 bois", nullptr));

        label_5->setText(QCoreApplication::translate("DialogMachine", "\303\211tat :", nullptr));
        comboBoxEtat->setItemText(0, QCoreApplication::translate("DialogMachine", "Disponible", nullptr));
        comboBoxEtat->setItemText(1, QCoreApplication::translate("DialogMachine", "En maintenance", nullptr));
        comboBoxEtat->setItemText(2, QCoreApplication::translate("DialogMachine", "Hors service", nullptr));

        label_6->setText(QCoreApplication::translate("DialogMachine", "Date Derni\303\250re Maintenance :", nullptr));
        label_7->setText(QCoreApplication::translate("DialogMachine", "Heures Cumul\303\251es :", nullptr));
        spinBoxHeures->setSuffix(QCoreApplication::translate("DialogMachine", " h", nullptr));
        label_8->setText(QCoreApplication::translate("DialogMachine", "Quantit\303\251 :", nullptr));
        label_9->setText(QCoreApplication::translate("DialogMachine", "Responsable Maintenance :", nullptr));
        lineEditRespMaintenance->setPlaceholderText(QCoreApplication::translate("DialogMachine", "Nom du responsable", nullptr));
        label_10->setText(QCoreApplication::translate("DialogMachine", "Responsable Atelier :", nullptr));
        lineEditRespAtelier->setPlaceholderText(QCoreApplication::translate("DialogMachine", "Nom du responsable", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DialogMachine: public Ui_DialogMachine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGMACHINE_H
