QT       += core gui sql printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    connection.cpp \
    employe.cpp \
    employewidget.cpp \
    main.cpp \
    mainwindow.cpp \
    atelierwidget.cpp \
    dialogmachine.cpp

HEADERS += \
    connection.h \
    employe.h \
    employewidget.h \
    mainwindow.h \
    atelierwidget.h \
    dialogmachine.h

FORMS += \
    AtelierWidget.ui \
    ClientsWidget.ui \
    CommandesWidget.ui \
    DialogMachine.ui \
    EmployeWidget.ui \
    EmployeWidget.ui \
    HomeWidget.ui \
    StockWidget.ui \
    mainwindow.ui

RESOURCES += \
    logo.qrc
