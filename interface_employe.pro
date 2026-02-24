QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    connection.cpp \
    main.cpp \
    mainwindow.cpp \
    atelierwidget.cpp \
    dialogmachine.cpp

HEADERS += \
    connection.h \
    mainwindow.h \
    atelierwidget.h \
    dialogmachine.h

FORMS += \
    AtelierWidget.ui \
    ClientsWidget.ui \
    CommandesWidget.ui \
    DialogMachine.ui \
    HomeWidget.ui \
    StockWidget.ui \
    mainwindow.ui

RESOURCES += \
    logo.qrc
