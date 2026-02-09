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
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AtelierWidget
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;

    void setupUi(QWidget *AtelierWidget)
    {
        if (AtelierWidget->objectName().isEmpty())
            AtelierWidget->setObjectName("AtelierWidget");
        vboxLayout = new QVBoxLayout(AtelierWidget);
        vboxLayout->setObjectName("vboxLayout");
        label = new QLabel(AtelierWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        vboxLayout->addWidget(label, 0, Qt::AlignCenter);


        retranslateUi(AtelierWidget);

        QMetaObject::connectSlotsByName(AtelierWidget);
    } // setupUi

    void retranslateUi(QWidget *AtelierWidget)
    {
        label->setText(QCoreApplication::translate("AtelierWidget", "Module Atelier - En cours de d\303\251veloppement", nullptr));
        (void)AtelierWidget;
    } // retranslateUi

};

namespace Ui {
    class AtelierWidget: public Ui_AtelierWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ATELIERWIDGET_H
