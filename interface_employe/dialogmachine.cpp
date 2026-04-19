#include "dialogmachine.h"
#include "ui_dialogmachine.h"

DialogMachine::DialogMachine(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::DialogMachine)
{
    ui->setupUi(this);
}

DialogMachine::~DialogMachine()
{
    delete ui;
}

QString DialogMachine::getID() const { return ui->lineEditID->text(); }
QString DialogMachine::getReference() const { return ui->lineEditReference->text(); }
QString DialogMachine::getNom() const { return ui->lineEditNom->text(); }
QString DialogMachine::getType() const { return ui->comboBoxType->currentText(); }
QString DialogMachine::getEtat() const { return ui->comboBoxEtat->currentText(); }
QString DialogMachine::getDateMaintenance() const { return ui->dateEditMaintenance->date().toString("dd/MM/yyyy"); }
int DialogMachine::getHeuresCumulees() const { return ui->spinBoxHeures->value(); }
int DialogMachine::getQuantite() const { return ui->spinBoxQuantite->value(); }
QString DialogMachine::getResponsableMaintenance() const { return ui->lineEditRespMaintenance->text(); }
QString DialogMachine::getResponsableAtelier() const { return ui->lineEditRespAtelier->text(); }

void DialogMachine::setID(const QString &id) { ui->lineEditID->setText(id); }
void DialogMachine::setReference(const QString &ref) { ui->lineEditReference->setText(ref); }
void DialogMachine::setNom(const QString &nom) { ui->lineEditNom->setText(nom); }
void DialogMachine::setType(const QString &type) {
    int index = ui->comboBoxType->findText(type);
    if (index >= 0) ui->comboBoxType->setCurrentIndex(index);
}
void DialogMachine::setEtat(const QString &etat) {
    int index = ui->comboBoxEtat->findText(etat);
    if (index >= 0) ui->comboBoxEtat->setCurrentIndex(index);
}
void DialogMachine::setDateMaintenance(const QString &date) {
    QDate qdate = QDate::fromString(date, "dd/MM/yyyy");
    if (qdate.isValid()) ui->dateEditMaintenance->setDate(qdate);
}
void DialogMachine::setHeuresCumulees(int heures) { ui->spinBoxHeures->setValue(heures); }
void DialogMachine::setQuantite(int quantite) { ui->spinBoxQuantite->setValue(quantite); }
void DialogMachine::setResponsableMaintenance(const QString &resp) { ui->lineEditRespMaintenance->setText(resp); }
void DialogMachine::setResponsableAtelier(const QString &resp) { ui->lineEditRespAtelier->setText(resp); }
