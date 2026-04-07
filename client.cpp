#include "client.h"
#include <QSqlQuery>
#include <QVariant>

bool Client::ajouter() const
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO ATELIER.CLIENT "
        "(ID_CLIENT, NOM, PRENOM, TELEPHONE, EMAIL, ADDRESSE, SOCIETE, MATRICULE_FISCALE, N_CIN, SITE_WEB_FB) "
        "VALUES (:id, :nom, :prenom, :tel, :email, :adresse, :societe, :mf, :ncin, :siteweb)"
    );
    query.bindValue(":id", id.toInt());
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", telephone);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":societe", societe);
    query.bindValue(":mf", matriculeFiscale);
    query.bindValue(":ncin", cin);
    query.bindValue(":siteweb", siteWeb);

    return query.exec();
}

bool Client::modifier() const
{
    QSqlQuery query;
    query.prepare(
        "UPDATE ATELIER.CLIENT SET "
        "NOM=:nom, PRENOM=:prenom, TELEPHONE=:tel, EMAIL=:email, ADDRESSE=:adresse, "
        "SOCIETE=:societe, MATRICULE_FISCALE=:mf, N_CIN=:ncin, SITE_WEB_FB=:siteweb "
        "WHERE ID_CLIENT=:id"
    );
    query.bindValue(":id", id.toInt());
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":tel", telephone);
    query.bindValue(":email", email);
    query.bindValue(":adresse", adresse);
    query.bindValue(":societe", societe);
    query.bindValue(":mf", matriculeFiscale);
    query.bindValue(":ncin", cin);
    query.bindValue(":siteweb", siteWeb);

    return query.exec();
}

bool Client::supprimer(const QString &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ATELIER.CLIENT WHERE ID_CLIENT = :id");
    query.bindValue(":id", id.toInt());
    return query.exec();
}

QSqlQuery Client::getAll(const QString &orderBy)
{
    QSqlQuery query;
    QString sql = "SELECT * FROM ATELIER.CLIENT";
    if (!orderBy.isEmpty()) {
        sql += " ORDER BY " + orderBy;
    }
    query.prepare(sql);
    query.exec();
    return query;
}

QSqlQuery Client::rechercher(const QString &term)
{
    QSqlQuery query;
    query.prepare(
        "SELECT * FROM ATELIER.CLIENT "
        "WHERE LOWER(NOM) LIKE :term OR TELEPHONE LIKE :term "
        "ORDER BY NOM"
    );
    query.bindValue(":term", "%" + term.toLower() + "%");
    query.exec();
    return query;
}
