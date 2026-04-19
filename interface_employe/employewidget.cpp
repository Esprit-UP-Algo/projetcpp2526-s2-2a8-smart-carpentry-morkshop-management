#include "employewidget.h"
#include "ui_EmployeWidget.h"
#include "employe.h"

#include <QMessageBox>
#include <QFileDialog>
#include <QPrinter>
#include <QTextDocument>
#include <QSqlQuery>
#include <QSqlError>
#include <QDate>
#include <QRegularExpression>

EmployeWidget::EmployeWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmployeWidget)
{
    ui->setupUi(this);

    ui->tableWidgetEmployes->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // ID est gardé mais caché
    ui->tableWidgetEmployes->setColumnCount(10);
    ui->tableWidgetEmployes->setHorizontalHeaderLabels({
        "ID Employé", "CIN", "Nom", "Poste", "Salaire",
        "Disponibilité", "Téléphone", "Email", "Date d’embauche", "Adresse"
    });
    ui->tableWidgetEmployes->setColumnHidden(0, true); // ✅ cacher ID

    connect(ui->btnValider, &QPushButton::clicked, this, &EmployeWidget::onValider);
    connect(ui->btnConfirmerModification, &QPushButton::clicked, this, &EmployeWidget::onConfirmerModification);

    connect(ui->btnAjouter, &QPushButton::clicked, this, &EmployeWidget::onAjouter);
    connect(ui->btnModifier, &QPushButton::clicked, this, &EmployeWidget::onModifier);
    connect(ui->btnSupprimer, &QPushButton::clicked, this, &EmployeWidget::onSupprimer);
    connect(ui->btnVider, &QPushButton::clicked, this, &EmployeWidget::onVider);

    connect(ui->btnRechercher, &QPushButton::clicked, this, &EmployeWidget::onRechercher);
    connect(ui->btnAfficherTout, &QPushButton::clicked, this, &EmployeWidget::onAfficherTout);
    connect(ui->btnAfficherToutActions, &QPushButton::clicked, this, &EmployeWidget::onAfficherTout);
    connect(ui->btnTrier, &QPushButton::clicked, this, &EmployeWidget::onTrier);

    connect(ui->lineEditRecherche, &QLineEdit::textChanged, this, &EmployeWidget::onRechercheTexteChanged);
    connect(ui->tableWidgetEmployes, &QTableWidget::cellClicked, this, &EmployeWidget::onTableClicked);
    connect(ui->btnExportPDF, &QPushButton::clicked, this, &EmployeWidget::onExportPDF);
    connect(ui->btnActualiserStats, &QPushButton::clicked, this, &EmployeWidget::onActualiserStats);

    ui->btnConfirmerModification->setEnabled(false);

    chargerTable();
    onActualiserStats();
}

EmployeWidget::~EmployeWidget()
{
    delete ui;
}

// ====== UNIQUE CIN CHECK ======
bool EmployeWidget::cinExists(const QString &cin, const QString &excludeId) const
{
    QSqlQuery q;
    QString sql = "SELECT COUNT(*) FROM ATELIER.EMPLOYE WHERE CIN = :cin";
    if (!excludeId.isEmpty()) {
        sql += " AND ID_EMPLOYE <> :id";
    }
    q.prepare(sql);
    q.bindValue(":cin", cin);
    if (!excludeId.isEmpty()) q.bindValue(":id", excludeId);
    if (q.exec() && q.next()) return q.value(0).toInt() > 0;
    return false;
}

// ====== UNIQUE EMAIL CHECK ======
bool EmployeWidget::emailExists(const QString &email, const QString &excludeId) const
{
    QSqlQuery q;
    QString sql = "SELECT COUNT(*) FROM ATELIER.EMPLOYE WHERE LOWER(EMAIL) = LOWER(:email)";
    if (!excludeId.isEmpty()) {
        sql += " AND ID_EMPLOYE <> :id";
    }
    q.prepare(sql);
    q.bindValue(":email", email);
    if (!excludeId.isEmpty()) q.bindValue(":id", excludeId);
    if (q.exec() && q.next()) return q.value(0).toInt() > 0;
    return false;
}

// ====== VALIDATION ======
bool EmployeWidget::validateForm(QStringList &errors, const QString &excludeId) const
{
    const QString cin = ui->lineEditCIN->text().trimmed();
    const QString nom = ui->lineEditNom->text().trimmed();
    const QString tel = ui->lineEditTelephone->text().trimmed();
    const QString email = ui->lineEditEmail->text().trimmed();
    const QString adresse = ui->textEditAdresse->toPlainText().trimmed();

    if (cin.isEmpty()) {
        errors << "• CIN obligatoire (8 chiffres).";
    } else if (!QRegularExpression("^[0-9]{8}$").match(cin).hasMatch()) {
        errors << "• CIN invalide : doit contenir exactement 8 chiffres.";
    } else if (cinExists(cin, excludeId)) {
        errors << "• CIN déjà utilisé par un autre employé.";
    }

    if (nom.isEmpty()) {
        errors << "• Nom obligatoire.";
    } else if (!QRegularExpression("^[A-Za-zÀ-ÿ\\s-]+$").match(nom).hasMatch()) {
        errors << "• Nom invalide : uniquement des lettres et espaces.";
    }

    if (tel.isEmpty()) {
        errors << "• Téléphone obligatoire (8 chiffres).";
    } else if (!QRegularExpression("^[0-9]{8}$").match(tel).hasMatch()) {
        errors << "• Téléphone invalide : doit contenir exactement 8 chiffres.";
    }

    if (email.isEmpty()) {
        errors << "• Email obligatoire.";
    } else if (!QRegularExpression("^[A-Za-z0-9._%+-]+@gmail\\.com$").match(email).hasMatch()) {
        errors << "• Email invalide : doit se terminer par @gmail.com.";
    } else if (emailExists(email, excludeId)) {
        errors << "• Email déjà utilisé par un autre employé.";
    }

    if (adresse.isEmpty()) {
        errors << "• Adresse obligatoire.";
    }

    return errors.isEmpty();
}

bool EmployeWidget::hasChanges() const
{
    return
        ui->lineEditCIN->text().trimmed() != origCin ||
        ui->lineEditNom->text().trimmed() != origNom ||
        ui->comboBoxPoste->currentText() != origPoste ||
        ui->doubleSpinBoxSalaire->value() != origSalaire ||
        ui->comboBoxDispo->currentText() != origDispo ||
        ui->lineEditTelephone->text().trimmed() != origTel ||
        ui->lineEditEmail->text().trimmed() != origEmail ||
        ui->dateEditEmbauche->date() != origDate ||
        ui->textEditAdresse->toPlainText().trimmed() != origAdresse;
}

// ====== AJOUT ======
void EmployeWidget::onValider()
{
    if (!currentEditId.isEmpty()) {
        QMessageBox::warning(this, "Modification en cours", "Utilise 'Confirmer modification' pour modifier.");
        return;
    }

    QStringList errors;
    if (!validateForm(errors)) {
        QMessageBox::warning(this, "Erreurs de saisie", errors.join("\n"));
        return;
    }

    Employe e;
    e.cin = ui->lineEditCIN->text().trimmed();
    e.nom = ui->lineEditNom->text().trimmed();
    e.poste = ui->comboBoxPoste->currentText();
    e.salaire = ui->doubleSpinBoxSalaire->value();
    e.disponibilite = ui->comboBoxDispo->currentText();
    e.telephone = ui->lineEditTelephone->text().trimmed();
    e.email = ui->lineEditEmail->text().trimmed();
    e.dateEmbauche = ui->dateEditEmbauche->date();
    e.adresse = ui->textEditAdresse->toPlainText().trimmed();

    if (e.ajouter()) {
        QMessageBox::information(this, "Succès", "Employé ajouté.");
        chargerTable();
        clearForm();
        onActualiserStats();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec d'ajout.");
    }
}

// ====== MODIFICATION ======
void EmployeWidget::onConfirmerModification()
{
    if (currentEditId.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "Aucun employé sélectionné.");
        return;
    }

    if (!hasChanges()) {
        QMessageBox::information(this, "Aucune modification", "Aucune modification détectée.");
        return;
    }

    QStringList errors;
    if (!validateForm(errors, currentEditId)) {
        QMessageBox::warning(this, "Erreurs de saisie", errors.join("\n"));
        return;
    }

    Employe e;
    e.id = currentEditId;
    e.cin = ui->lineEditCIN->text().trimmed();
    e.nom = ui->lineEditNom->text().trimmed();
    e.poste = ui->comboBoxPoste->currentText();
    e.salaire = ui->doubleSpinBoxSalaire->value();
    e.disponibilite = ui->comboBoxDispo->currentText();
    e.telephone = ui->lineEditTelephone->text().trimmed();
    e.email = ui->lineEditEmail->text().trimmed();
    e.dateEmbauche = ui->dateEditEmbauche->date();
    e.adresse = ui->textEditAdresse->toPlainText().trimmed();

    if (e.modifier()) {
        QMessageBox::information(this, "Succès", "Employé modifié.");
        chargerTable();
        clearForm();
        onActualiserStats();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de modification.");
    }
}

// ====== ACTIONS ======
void EmployeWidget::onAjouter()
{
    currentEditId.clear();
    ui->btnConfirmerModification->setEnabled(false);
    ui->tabWidget->setCurrentIndex(0);
    clearForm();
}

void EmployeWidget::onModifier()
{
    if (!ui->tableWidgetEmployes->currentItem()) {
        QMessageBox::warning(this, "Erreur", "Sélectionne un employé.");
        return;
    }

    int row = ui->tableWidgetEmployes->currentRow();
    currentEditId = ui->tableWidgetEmployes->item(row, 0)->text();

    remplirFormulaireDepuisTable(row);
    ui->tabWidget->setCurrentIndex(0);
    ui->btnConfirmerModification->setEnabled(true);

    origCin = ui->lineEditCIN->text().trimmed();
    origNom = ui->lineEditNom->text().trimmed();
    origPoste = ui->comboBoxPoste->currentText();
    origSalaire = ui->doubleSpinBoxSalaire->value();
    origDispo = ui->comboBoxDispo->currentText();
    origTel = ui->lineEditTelephone->text().trimmed();
    origEmail = ui->lineEditEmail->text().trimmed();
    origDate = ui->dateEditEmbauche->date();
    origAdresse = ui->textEditAdresse->toPlainText().trimmed();
}

void EmployeWidget::onSupprimer()
{
    if (!ui->tableWidgetEmployes->currentItem()) {
        QMessageBox::warning(this, "Attention", "Sélectionne un employé.");
        return;
    }

    const int row = ui->tableWidgetEmployes->currentRow();
    const QString id = ui->tableWidgetEmployes->item(row, 0)->text();

    if (Employe::supprimer(id)) {
        QMessageBox::information(this, "Succès", "Employé supprimé.");
        chargerTable();
        clearForm();
        onActualiserStats();
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de suppression.");
    }
}

// ====== VIDER (Oui/Non) ======
void EmployeWidget::onVider()
{
    QMessageBox msg(this);
    msg.setIcon(QMessageBox::Question);
    msg.setWindowTitle("Confirmation");
    msg.setText("Voulez-vous supprimer tous les employés ?");
    msg.setInformativeText("Cette action est irréversible.");
    QPushButton *ouiBtn = msg.addButton("Oui", QMessageBox::YesRole);
    QPushButton *nonBtn = msg.addButton("Non", QMessageBox::NoRole);
    msg.setDefaultButton(nonBtn);
    msg.exec();

    if (msg.clickedButton() != ouiBtn) return;

    QSqlQuery q;
    if (q.exec("DELETE FROM ATELIER.EMPLOYE")) {
        QMessageBox::information(this, "Succès", "Tous les employés ont été supprimés.");
        chargerTable();
        clearForm();
        onActualiserStats();
    } else {
        QMessageBox::warning(this, "Erreur", "Suppression impossible : " + q.lastError().text());
    }
}

// ====== RECHERCHE & TRI ======
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
    ui->comboBoxTri->setCurrentIndex(0);
    chargerTable();
}

void EmployeWidget::onTrier()
{
    const QString tri = ui->comboBoxTri->currentText();
    const QString order = tri.contains("croissant") ? "ASC" : "DESC";
    const QString term = ui->lineEditRecherche->text().trimmed();

    if (term.isEmpty()) {
        chargerTable(QString("SALAIRE %1").arg(order));
        return;
    }

    QSqlQuery q;
    q.prepare("SELECT * FROM ATELIER.EMPLOYE "
              "WHERE LOWER(CIN) LIKE :term OR LOWER(POSTE) LIKE :term "
              "ORDER BY SALAIRE " + order);
    q.bindValue(":term", "%" + term.toLower() + "%");
    q.exec();
    chargerTable(q);
}

void EmployeWidget::onTableClicked(int row, int)
{
    currentEditId = ui->tableWidgetEmployes->item(row, 0)->text();
    remplirFormulaireDepuisTable(row);
    ui->btnConfirmerModification->setEnabled(true);

    origCin = ui->lineEditCIN->text().trimmed();
    origNom = ui->lineEditNom->text().trimmed();
    origPoste = ui->comboBoxPoste->currentText();
    origSalaire = ui->doubleSpinBoxSalaire->value();
    origDispo = ui->comboBoxDispo->currentText();
    origTel = ui->lineEditTelephone->text().trimmed();
    origEmail = ui->lineEditEmail->text().trimmed();
    origDate = ui->dateEditEmbauche->date();
    origAdresse = ui->textEditAdresse->toPlainText().trimmed();
}

void EmployeWidget::onRechercheTexteChanged(const QString &text)
{
    if (text.trimmed().isEmpty()) {
        chargerTable();
    } else {
        chargerTable(Employe::rechercher(text));
    }
}

// ====== EXPORT & STATS ======
void EmployeWidget::onExportPDF()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Exporter PDF", "", "PDF (*.pdf)");
    if (fileName.isEmpty()) return;

    QTextDocument doc;
    QString html = "<h2>Planification des employés</h2><table border='1' cellspacing='0' cellpadding='4'>";
    html += "<tr><th>CIN</th><th>Nom</th><th>Poste</th><th>Salaire</th></tr>";
    for (int row = 0; row < ui->tableWidgetEmployes->rowCount(); ++row) {
        html += "<tr>";
        for (int col = 1; col < 5; ++col) { // ✅ sans ID
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
    QSqlQuery q;
    q.prepare(
        "SELECT "
        "COUNT(*) AS total, "
        "NVL(SUM(SALAIRE),0) AS total_salaire, "
        "NVL(AVG(SALAIRE),0) AS avg_salaire, "
        "SUM(CASE WHEN LOWER(DISPONIBILTE)='disponible' THEN 1 ELSE 0 END) AS dispo, "
        "SUM(CASE WHEN LOWER(DISPONIBILTE) IN ('en congé','en conge') THEN 1 ELSE 0 END) AS conge, "
        "SUM(CASE WHEN LOWER(DISPONIBILTE)='absent' THEN 1 ELSE 0 END) AS absent "
        "FROM ATELIER.EMPLOYE"
    );

    if (q.exec() && q.next()) {
        ui->labelTotalEmployesValeur->setText(q.value("total").toString());
        ui->labelSalaireTotalValeur->setText(q.value("total_salaire").toString());
        ui->labelSalaireMoyenValeur->setText(QString::number(q.value("avg_salaire").toDouble(), 'f', 2));
        ui->labelDispoValeur->setText(q.value("dispo").toString());
        ui->labelCongeValeur->setText(q.value("conge").toString());
        ui->labelAbsentValeur->setText(q.value("absent").toString());
    }
}

// ====== TABLE ======
void EmployeWidget::chargerTable(const QString &orderBy)
{
    QSqlQuery query = Employe::getAll(orderBy);
    chargerTable(query);
}

void EmployeWidget::chargerTable(const QSqlQuery &query)
{
    ui->tableWidgetEmployes->setRowCount(0);
    int row = 0;
    QSqlQuery q = query;
    while (q.next()) {
        ui->tableWidgetEmployes->insertRow(row);
        ui->tableWidgetEmployes->setItem(row, 0, new QTableWidgetItem(q.value("ID_EMPLOYE").toString()));
        ui->tableWidgetEmployes->setItem(row, 1, new QTableWidgetItem(q.value("CIN").toString()));
        ui->tableWidgetEmployes->setItem(row, 2, new QTableWidgetItem(q.value("NOM").toString()));
        ui->tableWidgetEmployes->setItem(row, 3, new QTableWidgetItem(q.value("POSTE").toString()));
        ui->tableWidgetEmployes->setItem(row, 4, new QTableWidgetItem(q.value("SALAIRE").toString()));
        ui->tableWidgetEmployes->setItem(row, 5, new QTableWidgetItem(q.value("DISPONIBILTE").toString()));
        ui->tableWidgetEmployes->setItem(row, 6, new QTableWidgetItem(q.value("TELEPHONE").toString()));
        ui->tableWidgetEmployes->setItem(row, 7, new QTableWidgetItem(q.value("EMAIL").toString()));
        ui->tableWidgetEmployes->setItem(row, 8, new QTableWidgetItem(q.value("DATE_EMBAUCHE").toString()));
        ui->tableWidgetEmployes->setItem(row, 9, new QTableWidgetItem(q.value("ADRESSE").toString()));
        row++;
    }
}

void EmployeWidget::remplirFormulaireDepuisTable(int row)
{
    ui->lineEditCIN->setText(ui->tableWidgetEmployes->item(row, 1)->text());
    ui->lineEditNom->setText(ui->tableWidgetEmployes->item(row, 2)->text());
    ui->comboBoxPoste->setCurrentText(ui->tableWidgetEmployes->item(row, 3)->text());
    ui->doubleSpinBoxSalaire->setValue(ui->tableWidgetEmployes->item(row, 4)->text().toDouble());
    ui->comboBoxDispo->setCurrentText(ui->tableWidgetEmployes->item(row, 5)->text());
    ui->lineEditTelephone->setText(ui->tableWidgetEmployes->item(row, 6)->text());
    ui->lineEditEmail->setText(ui->tableWidgetEmployes->item(row, 7)->text());
    ui->dateEditEmbauche->setDate(QDate::fromString(ui->tableWidgetEmployes->item(row, 8)->text(), "yyyy-MM-dd"));
    ui->textEditAdresse->setPlainText(ui->tableWidgetEmployes->item(row, 9)->text());
}

void EmployeWidget::clearForm()
{
    ui->lineEditCIN->clear();
    ui->lineEditNom->clear();
    ui->comboBoxPoste->setCurrentIndex(0);
    ui->doubleSpinBoxSalaire->setValue(0);
    ui->comboBoxDispo->setCurrentIndex(0);
    ui->lineEditTelephone->clear();
    ui->lineEditEmail->clear();
    ui->dateEditEmbauche->setDate(QDate::currentDate());
    ui->textEditAdresse->clear();
    currentEditId.clear();
    ui->btnConfirmerModification->setEnabled(false);
}
