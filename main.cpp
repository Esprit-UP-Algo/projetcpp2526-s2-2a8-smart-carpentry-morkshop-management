#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connection c;
    if (c.createconnect()) {
        QMessageBox::information(nullptr, "DONE", "Connection successful");
    } else {
        QMessageBox::critical(nullptr, "ERROR", "Connection failed");
    }

    MainWindow w;
    w.show();
    return a.exec();
}
