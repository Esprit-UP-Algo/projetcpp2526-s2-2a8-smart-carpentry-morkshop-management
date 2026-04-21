#include "stock.h"
#include <QSqlQuery>
#include <QVariant>
#include <QSqlError>

QString Stock::m_lastError;

QString Stock::lastError()
{
    return m_lastError;
}

bool Stock::ajouter() const
{
    QSqlQuery query;
    query.prepare(
        "INSERT INTO ATELIER.MATERIAU (NOM, TYPE, QUANTITE, PRIX_ACHAT) "
        "VALUES (:nom, :type, :quantite, :prix)"
    );
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prixAchat);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    m_lastError.clear();
    return true;
}

bool Stock::modifier() const
{
    QSqlQuery query;
    query.prepare(
        "UPDATE ATELIER.MATERIAU SET "
        "NOM=:nom, TYPE=:type, QUANTITE=:quantite, PRIX_ACHAT=:prix "
        "WHERE ID_MATERIAU=:id"
    );
    query.bindValue(":id", idMateriau.toInt());
    query.bindValue(":nom", nom);
    query.bindValue(":type", type);
    query.bindValue(":quantite", quantite);
    query.bindValue(":prix", prixAchat);

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    m_lastError.clear();
    return true;
}

bool Stock::supprimer(const QString &id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM ATELIER.MATERIAU WHERE ID_MATERIAU = :id");
    query.bindValue(":id", id.toInt());

    if (!query.exec()) {
        m_lastError = query.lastError().text();
        return false;
    }
    m_lastError.clear();
    return true;
}

QSqlQuery Stock::getAll(const QString &orderBy)
{
    QSqlQuery query;
    QString sql = "SELECT * FROM ATELIER.MATERIAU";
    if (!orderBy.isEmpty()) {
        sql += " ORDER BY " + orderBy;
    }
    query.prepare(sql);
    query.exec();
    return query;
}

QSqlQuery Stock::rechercher(const QString &term, const QString &typeFiltre)
{
    QSqlQuery query;
    QString sql =
        "SELECT * FROM ATELIER.MATERIAU "
        "WHERE LOWER(NOM) LIKE :term ";

    if (!typeFiltre.isEmpty() && typeFiltre != "Tous les types") {
        sql += " AND TYPE = :type ";
    }
    sql += " ORDER BY NOM";

    query.prepare(sql);
    query.bindValue(":term", "%" + term.toLower() + "%");
    if (!typeFiltre.isEmpty() && typeFiltre != "Tous les types") {
        query.bindValue(":type", typeFiltre);
    }
    query.exec();
    return query;
}

QSqlQuery Stock::statsParType()
{
    QSqlQuery query;
    query.prepare(
        "SELECT TYPE, COUNT(*) AS NB, NVL(SUM(QUANTITE),0) AS QTE "
        "FROM ATELIER.MATERIAU "
        "GROUP BY TYPE"
    );
    query.exec();
    return query;
}
