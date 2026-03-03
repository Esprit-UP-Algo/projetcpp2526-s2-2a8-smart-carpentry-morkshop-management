#include "employewidget.h"
#include "ui_EmployeWidget.h"
#include "employe.h"

#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>

EmployeWidget::EmployeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeWidget)
{
    ui->setupUi(this);

    ui->tableWidgetEmployes->setColumnCount(10);
    ui->tableWidgetEmployes->setHorizontalHeaderLabels({
        "ID Employé", "CIN", "Nom", "Poste", "Salaire",
        "Disponibilité", "Téléphone", "Email", "Date d’embauche", "Adresse"
    });

    connect(ui->btnAjouter, &QPushButton::clicked, this, &EmployeWidget::onAjouter);
    connect(ui->btnModifier, &QPushButton::clicked, this, &EmployeWidget::onModifier);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &EmployeWidget::onSupprimer);
    connect(ui->btnVider, &QPushButton::clicked, this, &EmployeWidget::onVider);
    connect(ui->btnRechercher, &QPushButton::clicked, this, &EmployeWidget::onRechercher);
    connect(ui->btnAfficherTout, &QPushButton::clicked, this, &EmployeWidget::onAfficherTout);
    connect(ui->btnTrier, &QPushButton::clicked, this, &EmployeWidget::onTrier);
    connect(ui->lineEditRecherche, &QLineEdit::textChanged, this, &EmployeWidget::onRechercheTexteChanged);
    connect(ui->tableWidgetEmployes, &QTableWidget::cellClicked, this, &EmployeWidget::onTableClicked);
    connect(ui->btnExportPDF, &QPushButton::clicked, this, &EmployeWidget::onExportPDF);
    connect(ui->btnActualiserStats, &QPushButton::clicked, this, &EmployeWidget::onActualiserStats);

    chargerTable();
}

EmployeWidget::~EmployeWidget()
{
    delete ui;
}

void EmployeWidget::chargerTable(const QString &orderBy)
{
    QSqlQuery query = Employe::getAll(orderBy);
    chargerTable(query);
}

void EmployeWidget::chargerTable(QSqlQuery query)
{
    ui->tableWidgetEmployes->setRowCount(0);
    int row = 0;
    while (query.next()) {
        ui->tableWidgetEmployes->insertRow(row);
        ui->tableWidgetEmployes->setItem(row, 0, new QTableWidgetItem(query.value("ID_EMPLOYE").toString()));
        ui->tableWidgetEmployes->setItem(row, 1, new QTableWidgetItem(query.value("CIN").toString()));
        ui->tableWidgetEmployes->setItem(row, 2, new QTableWidgetItem(query.value("NOM").toString()));
        ui->tableWidgetEmployes->setItem(row, 3, new QTableWidgetItem(query.value("POSTE").toString()));
        ui->tableWidgetEmployes->setItem(row, 4, new QTableWidgetItem(query.value("SALAIRE").toString()));
        ui->tableWidgetEmployes->setItem(row, 5, new QTableWidgetItem(query.value("DISPONIBILTE").toString()));
        ui->tableWidgetEmployes->setItem(row, 6, new QTableWidgetItem(query.value("TELEPHONE").toString()));
        ui->tableWidgetEmployes->setItem(row, 7, new QTableWidgetItem(query.value("EMAIL").toString()));
        ui->tableWidgetEmployes->setItem(row, 8, new QTableWidgetItem(query.value("DATE_EMBAUCHE").toString()));
        ui->tableWidgetEmployes->setItem(row, 9, new QTableWidgetItem(query.value("ADRESSE").toString()));
        row++;
    }
}

void EmployeWidget::onAjouter()
{
    Employe e;
    e.id = ui->lineEditID->text();
    e.cin = ui->lineEditCIN->text();
    e.nom = ui->lineEditNom->text();
    e.poste = ui->lineEditPoste->text();
    e.salaire = ui->doubleSpinBoxSalaire->value();
    e.disponibilite = ui->comboBoxDispo->currentText();
    e.telephone = ui->lineEditTelephone->text();
    e.email = ui->lineEditEmail->text();
    e.dateEmbauche = ui->dateEditEmbauche->date();
    e.adresse = ui->textEditAdresse->toPlainText();

    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté.");
        chargerTable();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec d'ajout.");
    }
}

void EmployeWidget::onModifier()
{
    Employe e;
    e.id = ui->lineEditID->text();
    e.cin = ui->lineEditCIN->text();
    e.nom = ui->lineEditNom->text();
    e.poste = ui->lineEditPoste->text();
    e.salaire = ui->doubleSpinBoxSalaire->value();
    e.disponibilite = ui->comboBoxDispo->currentText();
    e.telephone = ui->lineEditTelephone->text();
    e.email = ui->lineEditEmail->text();
    e.dateEmbauche = ui->dateEditEmbauche->date();
    e.adresse = ui->textEditAdresse->toPlainText();

    if (e.modifier()) {
        QMessageBox::information(this, "Succès", "Employé modifié.");
        chargerTable();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de modification.");
    }
}

void EmployeWidget::onSupprimer()
{
    const QString id = ui->lineEditID->text();
    if (id.isEmpty()) {
        QMessageBox::warning(this, "Attention", "Sélectionne un employé.");
        return;
    }

    if (Employe::supprimer(id)) {
        QMessageBox::information(this, "Succès", "Employé supprimé.");
        chargerTable();
        clearForm();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de suppression.");
    }
}

void EmployeWidget::onVider()
{
    clearForm();
}

void EmployeWidget::onRechercher()
{
    const QString term = ui->lineEditRecherche->text().trimmed();
    if (term.isEmpty()) {
        chargerTable();
        return;
    }
    chargerTable(Employe::rechercher(term));
}

void EmployeWidget::onAfficherTout()
{
    ui->lineEditRecherche->clear();
    chargerTable();
}

void EmployeWidget::onTrier()
{
    const QString tri = ui->comboBoxTri->currentText();
    if (tri.contains("croissant")) {
        chargerTable("SALAIRE ASC");
    } else {
        chargerTable("SALAIRE DESC");
    }
}

void EmployeWidget::onTableClicked(int row, int)
{
    remplirFormulaireDepuisTable(row);
}

void EmployeWidget::onRechercheTexteChanged(const QString &text)
{
    if (text.trimmed().isEmpty()) {
        chargerTable();
    } else {
        chargerTable(Employe::rechercher(text));
    }
}

void EmployeWidget::onExportPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QTextDocument doc;
    QString html = "<h2>Planification des employés</h2><table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>ID</th><th>CIN</th><th>Nom</th><th>Poste</th><th>Salaire</th></tr>";
    for (int row = 0; row < ui->tableWidgetEmployes->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 0; col < 5; ++col) {
            auto item = ui->tableWidgetEmployes->item(row, col);
            html += "<td>" + (item ? item->text() : "") + "</td>";
        }
        html += "</tr>";
    }
    html += "</table>";
    doc.setHtml(html);

    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);
    doc.print(&printer);

    QMessageBox::information(this, "Succès", "PDF exporté.");
}

void EmployeWidget::onActualiserStats()
{
    QSqlQuery query;
    if (query.exec("SELECT SUM(HEURES_TRAVAIL) FROM ATELIER.EMPLOYE")) {
        if (query.next()) {
            ui->labelTotalEmployesValeur->setText(query.value(0).toString());
        }
    } else {
        // fallback si colonne inexistante
        QSqlQuery q2("SELECT COUNT(*) FROM ATELIER.EMPLOYE");
        if (q2.next()) {
            ui->labelTotalEmployesValeur->setText(q2.value(0).toString());
        }
    }
}

void EmployeWidget::remplirFormulaireDepuisTable(int row)
{
    ui->lineEditID->setText(ui->tableWidgetEmployes->item(row, 0)->text());
    ui->lineEditCIN->setText(ui->tableWidgetEmployes->item(row, 1)->text());
    ui->lineEditNom->setText(ui->tableWidgetEmployes->item(row, 2)->text());
    ui->lineEditPoste->setText(ui->tableWidgetEmployes->item(row, 3)->text());
    ui->doubleSpinBoxSalaire->setValue(ui->tableWidgetEmployes->item(row, 4)->text().toDouble());
    ui->comboBoxDispo->setCurrentText(ui->tableWidgetEmployes->item(row, 5)->text());
    ui->lineEditTelephone->setText(ui->tableWidgetEmployes->item(row, 6)->text());
    ui->lineEditEmail->setText(ui->tableWidgetEmployes->item(row, 7)->text());
    ui->dateEditEmbauche->setDate(QDate::fromString(ui->tableWidgetEmployes->item(row, 8)->text(), "yyyy-MM-dd"));
    ui->textEditAdresse->setPlainText(ui->tableWidgetEmployes->item(row, 9)->text());
}

void EmployeWidget::clearForm()
{
    ui->lineEditID->clear();
    ui->lineEditCIN->clear();
    ui->lineEditNom->clear();
    ui->lineEditPoste->clear();
    ui->doubleSpinBoxSalaire->setValue(0);
    ui->comboBoxDispo->setCurrentIndex(0);
    ui->lineEditTelephone->clear();
    ui->lineEditEmail->clear();
    ui->dateEditEmbauche->setDate(QDate::currentDate());
    ui->textEditAdresse->clear();
}
