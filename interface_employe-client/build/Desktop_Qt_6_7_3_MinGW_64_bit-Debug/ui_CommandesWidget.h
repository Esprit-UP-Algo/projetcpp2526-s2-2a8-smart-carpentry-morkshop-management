/********************************************************************************
** Form generated from reading UI file 'CommandesWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMMANDESWIDGET_H
#define UI_COMMANDESWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CommandesWidget
{
public:
    QVBoxLayout *vboxLayout;
    QLabel *label;

    void setupUi(QWidget *CommandesWidget)
    {
        if (CommandesWidget->objectName().isEmpty())
            CommandesWidget->setObjectName("CommandesWidget");
        vboxLayout = new QVBoxLayout(CommandesWidget);
        vboxLayout->setObjectName("vboxLayout");
        label = new QLabel(CommandesWidget);
        label->setObjectName("label");
        QFont font;
        font.setPointSize(16);
        font.setBold(true);
        label->setFont(font);

        vboxLayout->addWidget(label, 0, Qt::AlignCenter);


        retranslateUi(CommandesWidget);

        QMetaObject::connectSlotsByName(CommandesWidget);
    } // setupUi

    void retranslateUi(QWidget *CommandesWidget)
    {
        label->setText(QCoreApplication::translate("CommandesWidget", "Module Commandes - En cours de d\303\251veloppement", nullptr));
        (void)CommandesWidget;
    } // retranslateUi

};

namespace Ui {
    class CommandesWidget: public Ui_CommandesWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMMANDESWIDGET_H
