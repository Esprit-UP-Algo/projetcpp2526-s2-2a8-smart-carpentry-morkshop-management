#ifndef COMMANDE_H
#define COMMANDE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>

class Commande
{
public:
    QString id;
    QDate dateCommande;
    QString details;
    QString dimensions;
    double prix = 0.0;
    QString etat;

    Commande() = default;

    bool ajouter() const;
    bool modifier() const;
    static bool supprimer(const QString &id);

    static QSqlQuery getAll(const QString &orderBy = QString());
    static QSqlQuery rechercher(const QString &critere, const QString &valeur);
    static QSqlQuery statsParMois();

    mutable QString lastSqlError;
};

#endif // COMMANDE_H
