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
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StockWidget
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;

    void setupUi(QWidget *StockWidget)
    {
        if (StockWidget->objectName().isEmpty())
            StockWidget->setObjectName("StockWidget");
        vboxLayout = new QVBoxLayout(StockWidget);
        vboxLayout->setObjectName("vboxLayout");
        label = new QLabel(StockWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        vboxLayout->addWidget(label, 0, Qt::AlignCenter);


        retranslateUi(StockWidget);

        QMetaObject::connectSlotsByName(StockWidget);
    } // setupUi

    void retranslateUi(QWidget *StockWidget)
    {
        label->setText(QCoreApplication::translate("StockWidget", "Module Stock - En cours de d\303\251veloppement", nullptr));
        (void)StockWidget;
    } // retranslateUi

};

namespace Ui {
    class StockWidget: public Ui_StockWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STOCKWIDGET_H
