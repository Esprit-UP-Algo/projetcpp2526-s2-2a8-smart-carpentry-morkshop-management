#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QDate>
#include <QSqlQuery>

class Employe
{
public:
    QString id;
    QString cin;
    QString nom;
    QString poste;
    double salaire = 0.0;
    QString disponibilite;
    QString telephone;
    QString email;
    QDate dateEmbauche;
    QString adresse;

    Employe() = default;

    bool ajouter() const;
    bool modifier() const;
    static bool supprimer(const QString &id);

    static QSqlQuery getAll(const QString &orderBy = QString());
    static QSqlQuery rechercher(const QString &term);
};

#endif // EMPLOYE_H
