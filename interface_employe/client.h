#ifndef CLIENT_H
#define CLIENT_H

#include <QString>
#include <QSqlQuery>

class Client
{
public:
    QString id;
    QString nom;
    QString prenom;
    QString telephone;
    QString email;
    QString adresse;
    QString societe;
    QString matriculeFiscale;
    QString cin;
    QString siteWeb;

    Client() = default;

    bool ajouter() const;
    bool modifier() const;

    static bool supprimer(const QString &id);
    static QSqlQuery getAll(const QString &orderBy = QString());
    static QSqlQuery rechercher(const QString &term);
};

#endif // CLIENT_H
