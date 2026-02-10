/********************************************************************************
** Form generated from reading UI file 'HomeWidget.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_HOMEWIDGET_H
#define UI_HOMEWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_HomeWidget
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelLogo;
    QLabel *labelTitle;
    QLabel *labelSubtitle;
    QPushButton *btnAccederModules;
    QLabel *labelFooter;

    void setupUi(QWidget *HomeWidget)
    {
        if (HomeWidget->objectName().isEmpty())
            HomeWidget->setObjectName("HomeWidget");
        verticalLayout = new QVBoxLayout(HomeWidget);
        verticalLayout->setSpacing(20);
        verticalLayout->setObjectName("verticalLayout");
        verticalLayout->setContentsMargins(40, 40, 40, 40);
        labelLogo = new QLabel(HomeWidget);
        labelLogo->setObjectName("labelLogo");
        labelLogo->setMinimumSize(QSize(200, 200));
        labelLogo->setMaximumSize(QSize(200, 200));
        labelLogo->setPixmap(QPixmap(QString::fromUtf8(":/images/logo.jpeg")));
        labelLogo->setScaledContents(true);
        labelLogo->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelLogo, 0, Qt::AlignmentFlag::AlignHCenter);

        labelTitle = new QLabel(HomeWidget);
        labelTitle->setObjectName("labelTitle");
        QFont font;
        font.setFamilies({QString::fromUtf8("Segoe UI")});
        font.setPointSize(20);
        font.setBold(true);
        labelTitle->setFont(font);
        labelTitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelTitle, 0, Qt::AlignmentFlag::AlignHCenter);

        labelSubtitle = new QLabel(HomeWidget);
        labelSubtitle->setObjectName("labelSubtitle");
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Segoe UI")});
        font1.setPointSize(12);
        labelSubtitle->setFont(font1);
        labelSubtitle->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelSubtitle, 0, Qt::AlignmentFlag::AlignHCenter);

        btnAccederModules = new QPushButton(HomeWidget);
        btnAccederModules->setObjectName("btnAccederModules");
        btnAccederModules->setMinimumSize(QSize(250, 50));

        verticalLayout->addWidget(btnAccederModules, 0, Qt::AlignmentFlag::AlignHCenter);

        labelFooter = new QLabel(HomeWidget);
        labelFooter->setObjectName("labelFooter");
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Segoe UI")});
        font2.setPointSize(9);
        labelFooter->setFont(font2);
        labelFooter->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout->addWidget(labelFooter, 0, Qt::AlignmentFlag::AlignHCenter);


        retranslateUi(HomeWidget);

        QMetaObject::connectSlotsByName(HomeWidget);
    } // setupUi

    void retranslateUi(QWidget *HomeWidget)
    {
        labelTitle->setText(QCoreApplication::translate("HomeWidget", "CARPENTRY WOODWORKING", nullptr));
        labelSubtitle->setText(QCoreApplication::translate("HomeWidget", "Employ\303\251s \342\200\242 Clients \342\200\242 Commandes \342\200\242 Stock \342\200\242 Atelier", nullptr));
        btnAccederModules->setText(QCoreApplication::translate("HomeWidget", "Acc\303\251der aux modules", nullptr));
        labelFooter->setText(QCoreApplication::translate("HomeWidget", "\302\251 2026 - Gestion Atelier", nullptr));
        (void)HomeWidget;
    } // retranslateUi

};

namespace Ui {
    class HomeWidget: public Ui_HomeWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_HOMEWIDGET_H
