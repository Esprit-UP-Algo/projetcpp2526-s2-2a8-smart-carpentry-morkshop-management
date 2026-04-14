QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    connection.cpp \
    employe.cpp \
    employewidget.cpp \
    commande.cpp \
    commandeswidget.cpp \
    client.cpp \
    clientswidget.cpp \
    main.cpp \
    mainwindow.cpp \
    atelierwidget.cpp \
    dialogmachine.cpp \
    stock.cpp \
    stockwidget.cpp

HEADERS += \
    connection.h \
    employe.h \
    employewidget.h \
    commande.h \
    commandeswidget.h \
    client.h \
    clientswidget.h \
    mainwindow.h \
    atelierwidget.h \
    dialogmachine.h \
    stock.h \
    stockwidget.h

FORMS += \
    AtelierWidget.ui \
    ClientsWidget.ui \
    CommandesWidget.ui \
    DialogMachine.ui \
    EmployeWidget.ui \
    HomeWidget.ui \
    StockWidget.ui \
    mainwindow.ui

RESOURCES += \
    logo.qrc
