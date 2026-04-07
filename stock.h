#ifndef STOCK_H
#define STOCK_H

#include <QString>
#include <QSqlQuery>

class Stock
{
public:
    QString idMateriau;
    QString nom;
    QString type;
    double quantite = 0.0;
    double prixAchat = 0.0;

    Stock() = default;

    bool ajouter() const;
    bool modifier() const;

    static bool supprimer(const QString &id);
    static QSqlQuery getAll(const QString &orderBy = QString());
    static QSqlQuery rechercher(const QString &term, const QString &typeFiltre = QString());
    static QSqlQuery statsParType();

    static QString lastError();

private:
    static QString m_lastError;
};

#endif // STOCK_H
