#ifndef CLIENTSWIDGET_H
#define CLIENTSWIDGET_H

#include <QWidget>
#include <QSqlQuery>

namespace Ui {
class ClientsWidget;
}

class ClientsWidget : public QWidget
{
    Q_OBJECT

public:
    explicit ClientsWidget(QWidget *parent = nullptr);
    ~ClientsWidget();

private slots:
    void onValider();
    void onConfirmerModification();
    void onAjouter();
    void onModifier();
    void onSupprimer();
    void onVider();
    void onRechercher();
    void onAfficherTout();
    void onTrier();
    void onTableClicked(int row, int column);
    void onExportPDF();
    void onActualiserStats();

    void onMatriculeTextChanged(const QString &text); // ✅ nouveau

private:
    Ui::ClientsWidget *ui;

    void chargerTable(const QString &orderBy = QString());
    void chargerTable(const QSqlQuery &query);
    void remplirFormulaireDepuisTable(const QString &id);
    void clearForm();

    bool validateForm(QStringList &errors, const QString &excludeId = QString()) const;
    bool cinExists(const QString &cin, const QString &excludeId = QString()) const;
    bool emailExists(const QString &email, const QString &excludeId = QString()) const;
    bool telExists(const QString &tel, const QString &excludeId = QString()) const;
    bool matriculeExists(const QString &mf, const QString &excludeId = QString()) const;

    QString currentEditId;

    QString origNom;
    QString origPrenom;
    QString origTel;
    QString origEmail;
    QString origAdresse;
    QString origSociete;
    QString origMF;
    QString origCin;
    QString origSite;

    bool hasChanges() const;
};

#endif // CLIENTSWIDGET_H
