#include "mainwindow.h"
#include "connection.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    
    // Initialiser la connexion à la base de données
    Connection c;
    bool test = c.createconnect();
    
    if (test) {
        QMessageBox::information(nullptr, "Connexion", "Connexion à la base de données réussie!");
        
        MainWindow w;
        w.show();
        return a.exec();
    } else {
        QMessageBox::critical(nullptr, "Erreur", "Échec de la connexion à la base de données Oracle!");
        return 0;
    }
}
