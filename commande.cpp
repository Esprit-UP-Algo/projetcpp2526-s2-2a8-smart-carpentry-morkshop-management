#include "commande.h"
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

bool Commande::ajouter() const
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO ATELIER.COMMANDE "
        "(DATE_COMMANDE, DETAILS_COMMANDE, DIMENSIONS, PRIX, ETAT) "
        "VALUES (:date, :details, :dimensions, :prix, :etat)"
    );
    query.bindValue(":date", dateCommande);
    query.bindValue(":details", details);
    query.bindValue(":dimensions", dimensions);
    query.bindValue(":prix", prix);
    query.bindValue(":etat", etat);
    bool ok = query.exec();
    if (!ok) {
        lastSqlError = query.lastError().text();
        qDebug() << "Commande::ajouter error:" << lastSqlError;
    }
    return ok;
}

bool Commande::modifier() const
{
    QSqlQuery query;
    query.prepare(
        "UPDATE ATELIER.COMMANDE SET "
        "DATE_COMMANDE=:date, DETAILS_COMMANDE=:details, DIMENSIONS=:dimensions, PRIX=:prix, ETAT=:etat "
        "WHERE ID_COMMANDE=:id"
    );
    query.bindValue(":id", id);
    query.bindValue(":date", dateCommande);
    query.bindValue(":details", details);
    query.bindValue(":dimensions", dimensions);
    query.bindValue(":prix", prix);
    query.bindValue(":etat", etat);
    bool ok = query.exec();
    if (!ok) {
        lastSqlError = query.lastError().text();
        qDebug() << "Commande::modifier error:" << lastSqlError;
    }
    return ok;
}

bool Commande::supprimer(const QString &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ATELIER.COMMANDE WHERE ID_COMMANDE=:id");
    query.bindValue(":id", id);
    return query.exec();
}

QSqlQuery Commande::getAll(const QString &orderBy)
{
    QSqlQuery query;
    QString sql = "SELECT * FROM ATELIER.COMMANDE";
    if (!orderBy.isEmpty())
        sql += " ORDER BY " + orderBy;
    query.prepare(sql);
    query.exec();
    return query;
}

QSqlQuery Commande::rechercher(const QString &critere, const QString &valeur)
{
    QSqlQuery query;
    if (critere.toLower() == "date") {
        query.prepare(
            "SELECT * FROM ATELIER.COMMANDE "
            "WHERE TO_CHAR(DATE_COMMANDE, 'YYYY-MM-DD') LIKE :valeur "
            "ORDER BY DATE_COMMANDE DESC"
        );
    } else {
        query.prepare(
            "SELECT * FROM ATELIER.COMMANDE "
            "WHERE LOWER(ETAT) LIKE :valeur "
            "ORDER BY DATE_COMMANDE DESC"
        );
    }
    query.bindValue(":valeur", "%" + valeur.toLower() + "%");
    query.exec();
    return query;
}

QSqlQuery Commande::statsParMois()
{
    QSqlQuery query;
    query.prepare(
        "SELECT TO_CHAR(DATE_COMMANDE, 'MM') AS MOIS, COUNT(*) AS NB, SUM(PRIX) AS TOTAL "
        "FROM ATELIER.COMMANDE "
        "GROUP BY TO_CHAR(DATE_COMMANDE, 'MM') "
        "ORDER BY MOIS"
    );
    query.exec();
    return query;
}
