#ifndef DIALOGMACHINE_H
#define DIALOGMACHINE_H

#include <QDialog>

namespace Ui {
class DialogMachine;
}

class DialogMachine : public QDialog
{
    Q_OBJECT

public:
    explicit DialogMachine(QWidget *parent = nullptr);
    ~DialogMachine();

    // Méthodes pour récupérer les données du formulaire
    QString getID() const;
    QString getReference() const;
    QString getNom() const;
    QString getType() const;
    QString getEtat() const;
    QString getDateMaintenance() const;
    int getHeuresCumulees() const;
    int getQuantite() const;
    QString getResponsableMaintenance() const;
    QString getResponsableAtelier() const;

    // Méthodes pour remplir le formulaire (mode modification)
    void setID(const QString &id);
    void setReference(const QString &ref);
    void setNom(const QString &nom);
    void setType(const QString &type);
    void setEtat(const QString &etat);
    void setDateMaintenance(const QString &date);
    void setHeuresCumulees(int heures);
    void setQuantite(int quantite);
    void setResponsableMaintenance(const QString &resp);
    void setResponsableAtelier(const QString &resp);

private:
    Ui::DialogMachine *ui;
};

#endif // DIALOGMACHINE_H
