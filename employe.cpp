#include "employe.h"
#include <QSqlQuery>
#include <QVariant>

static double appliquerPenaliteAbsence(double salaire, const QString &dispo)
{
    if (dispo.toLower() == "absent") {
        return salaire * 0.9; // -10% (tu peux changer)
    }
    return salaire;
}

bool Employe::ajouter() const
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO ATELIER.EMPLOYE "
        "(ID_EMPLOYE, CIN, NOM, POSTE, SALAIRE, DISPONIBILTE, TELEPHONE, EMAIL, DATE_EMBAUCHE, ADRESSE) "
        "VALUES (:id, :cin, :nom, :poste, :salaire, :dispo, :tel, :email, :date, :adresse)"
        );

    const double salaireFinal = appliquerPenaliteAbsence(salaire, disponibilite);

    query.bindValue(":id", id);
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaireFinal);
    query.bindValue(":dispo", disponibilite);
    query.bindValue(":tel", telephone);
    query.bindValue(":email", email);
    query.bindValue(":date", dateEmbauche);
    query.bindValue(":adresse", adresse);

    return query.exec();
}

bool Employe::modifier() const
{
    QSqlQuery query;
    query.prepare(
        "UPDATE ATELIER.EMPLOYE SET "
        "CIN=:cin, NOM=:nom, POSTE=:poste, SALAIRE=:salaire, DISPONIBILTE=:dispo, "
        "TELEPHONE=:tel, EMAIL=:email, DATE_EMBAUCHE=:date, ADRESSE=:adresse "
        "WHERE ID_EMPLOYE=:id"
        );

    const double salaireFinal = appliquerPenaliteAbsence(salaire, disponibilite);

    query.bindValue(":id", id);
    query.bindValue(":cin", cin);
    query.bindValue(":nom", nom);
    query.bindValue(":poste", poste);
    query.bindValue(":salaire", salaireFinal);
    query.bindValue(":dispo", disponibilite);
    query.bindValue(":tel", telephone);
    query.bindValue(":email", email);
    query.bindValue(":date", dateEmbauche);
    query.bindValue(":adresse", adresse);

    return query.exec();
}

bool Employe::supprimer(const QString &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ATELIER.EMPLOYE WHERE ID_EMPLOYE = :id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQuery Employe::getAll(const QString &orderBy)
{
    QSqlQuery query;
    QString sql = "SELECT * FROM ATELIER.EMPLOYE";
    if (!orderBy.isEmpty()) {
        sql += " ORDER BY " + orderBy;
    }
    query.prepare(sql);
    query.exec();
    return query;
}

QSqlQuery Employe::rechercher(const QString &term)
{
    QSqlQuery query;
    query.prepare(
        "SELECT * FROM ATELIER.EMPLOYE "
        "WHERE LOWER(CIN) LIKE :term OR LOWER(POSTE) LIKE :term "
        "ORDER BY ID_EMPLOYE"
        );
    query.bindValue(":term", "%" + term.toLower() + "%");
    query.exec();
    return query;
}
