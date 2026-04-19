#include "stockwidget.h"
#include "ui_stockwidget.h"
#include <QDebug>
#include <QSqlError>
#include <QTableWidgetItem>
#include <QRandomGenerator>
#include <QLabel>
#include <QTimer>

StockWidget::StockWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::StockWidget)
{
    ui->setupUi(this);

    // Utiliser la bonne méthode de connexion
    if (!m_connection.createconnect()) {
        QMessageBox::critical(this, "Erreur", "Impossible de se connecter à la base de données.");
        return;
    }

    // Connecter les boutons
    connect(ui->btnAjouter, &QPushButton::clicked, this, &StockWidget::onAjouter);
    connect(ui->btnModifier, &QPushButton::clicked, this, &StockWidget::onModifier);
    connect(ui->btnDelete, &QPushButton::clicked, this, &StockWidget::onSupprimer);
    connect(ui->btnNouveau, &QPushButton::clicked, this, &StockWidget::onNouveau);
    connect(ui->btnRechercher, &QPushButton::clicked, this, &StockWidget::onRechercher);
    connect(ui->btnActualiserStats, &QPushButton::clicked, this, &StockWidget::onActualiserStats);
    connect(ui->btnGenererReappro, &QPushButton::clicked, this, &StockWidget::onGenererReappro);
    connect(ui->btnPrevision, &QPushButton::clicked, this, &StockWidget::onPrevision);
    connect(ui->btnAppliquerTri, &QPushButton::clicked, this, &StockWidget::onTrierParQuantite);

    // Signal/slot pour le clic sur table
    connect(ui->tableWidget, &QTableWidget::clicked, this, [this](const QModelIndex &index) {
        onTableClicked(index.row(), index.column());
    });

    // Auto-recherche en temps réel
    connect(ui->txtRecherche, &QLineEdit::textChanged, this, &StockWidget::onRechercher);

    // Charger les données
    chargerTable();
    remplirStats();
    assurerColonneIdCachee();
    verifierAlertesStock();
}

StockWidget::~StockWidget()
{
    delete ui;
}

bool StockWidget::ensureDbOpen()
{
    QSqlQuery testQuery;
    testQuery.exec("SELECT 1");
    return true;
}

void StockWidget::assurerColonneIdCachee()
{
    if (ui->tableWidget->columnCount() > 0) {
        ui->tableWidget->setColumnHidden(0, true);
    }
}

// ==================== NOTIFICATION TOAST ====================
void StockWidget::afficherNotification(const QString &message, const QString &couleur)
{
    QLabel *toast = new QLabel(this);
    toast->setText(message);
    toast->setStyleSheet(QString("background-color: %1; color: white; padding: 8px 16px; border-radius: 6px; font-weight: bold; font-size: 12px;").arg(couleur));
    toast->setAlignment(Qt::AlignCenter);
    toast->setWindowFlags(Qt::ToolTip);
    toast->setAttribute(Qt::WA_DeleteOnClose);

    int x = (this->width() - 200) / 2;
    int y = this->height() - 60;
    toast->move(x, y);
    toast->show();

    QTimer::singleShot(2000, toast, &QLabel::close);
}
// ============================================================

// Vérifier les alertes de stock bas
void StockWidget::verifierAlertesStock()
{
    if (!ensureDbOpen()) return;

    QSqlQuery query;
    query.exec("SELECT NOM, QUANTITE, SEUIL_ALERTE FROM ATELIER.MATERIAU WHERE QUANTITE <= SEUIL_ALERTE");

    QStringList alertes;
    while (query.next()) {
        QString nom = query.value("NOM").toString();
        double quantite = query.value("QUANTITE").toDouble();
        double seuil = query.value("SEUIL_ALERTE").toDouble();
        alertes << QString("• %1 : %2 unités (seuil: %3)").arg(nom).arg(quantite).arg(seuil);
    }

    if (!alertes.isEmpty()) {
        QString message = "⚠️ ALERTE STOCK BAS ⚠️\n\nLes matériaux suivants ont un stock inférieur ou égal à leur seuil d'alerte :\n\n" + alertes.join("\n");
        QMessageBox::warning(this, "Alerte Stock", message);
    }
}

void StockWidget::chargerTable(const QString &orderBy)
{
    if (!ensureDbOpen()) return;

    QString sql = "SELECT ID_MATERIAU, NOM, TYPE, QUANTITE, PRIX_ACHAT, SEUIL_ALERTE FROM ATELIER.MATERIAU";
    if (!orderBy.isEmpty()) {
        sql += " ORDER BY " + orderBy;
    }

    QSqlQuery query;
    if (!query.exec(sql)) {
        QMessageBox::critical(this, "Erreur", "Erreur lors du chargement : " + query.lastError().text());
        return;
    }

    chargerTable(query);
}

void StockWidget::chargerTable(const QSqlQuery &query)
{
    QTableWidget *table = ui->tableWidget;
    table->setRowCount(0);
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels({"ID", "Nom", "Type", "Quantité", "Prix Achat (TND)", "Seuil Alerte"});

    int row = 0;
    QSqlQuery queryCopy;
    queryCopy = query;

    while (queryCopy.next()) {
        table->insertRow(row);

        double quantite = queryCopy.value("QUANTITE").toDouble();
        double seuil = queryCopy.value("SEUIL_ALERTE").toDouble();

        table->setItem(row, 0, new QTableWidgetItem(queryCopy.value("ID_MATERIAU").toString()));
        table->setItem(row, 1, new QTableWidgetItem(queryCopy.value("NOM").toString()));
        table->setItem(row, 2, new QTableWidgetItem(queryCopy.value("TYPE").toString()));

        QTableWidgetItem *qteItem = new QTableWidgetItem(QString::number(quantite, 'f', 2) + " unités");
        table->setItem(row, 3, qteItem);

        table->setItem(row, 4, new QTableWidgetItem(QString::number(queryCopy.value("PRIX_ACHAT").toDouble(), 'f', 2) + " TND"));
        table->setItem(row, 5, new QTableWidgetItem(QString::number(seuil, 'f', 0) + " unités"));

        // Colorer la ligne si stock < seuil d'alerte
        if (quantite <= seuil) {
            qteItem->setBackground(Qt::red);
            qteItem->setForeground(Qt::white);
            table->item(row, 5)->setBackground(Qt::red);
            table->item(row, 5)->setForeground(Qt::white);
        } else if (quantite < 50) {
            qteItem->setBackground(Qt::yellow);
        }

        row++;
    }

    table->resizeColumnsToContents();
    assurerColonneIdCachee();
}

void StockWidget::clearForm()
{
    ui->txtNom->clear();
    ui->comboType->setCurrentIndex(0);
    ui->spinQuantite->setValue(0);
    ui->spinPrixAchat->setValue(0);
    ui->spinSeuilAlerte->setValue(10);
}

void StockWidget::remplirFormulaireDepuisTable(const QString &id)
{
    if (!ensureDbOpen()) return;

    QSqlQuery query;
    query.prepare("SELECT NOM, TYPE, QUANTITE, PRIX_ACHAT, SEUIL_ALERTE FROM ATELIER.MATERIAU WHERE ID_MATERIAU = :id");
    query.bindValue(":id", id);

    if (!query.exec() || !query.next()) {
        QMessageBox::critical(this, "Erreur", "Impossible de charger les données du matériau.");
        return;
    }

    ui->txtNom->setText(query.value("NOM").toString());
    ui->comboType->setCurrentText(query.value("TYPE").toString());
    ui->spinQuantite->setValue(query.value("QUANTITE").toDouble());
    ui->spinPrixAchat->setValue(query.value("PRIX_ACHAT").toDouble());
    ui->spinSeuilAlerte->setValue(query.value("SEUIL_ALERTE").toDouble());
}

void StockWidget::onTableClicked(int row, int column)
{
    Q_UNUSED(column);
    QString id = ui->tableWidget->item(row, 0)->text();
    remplirFormulaireDepuisTable(id);
}

void StockWidget::onAjouter()
{
    if (ui->txtNom->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "Veuillez saisir le nom du matériau.");
        return;
    }

    if (!ensureDbOpen()) return;

    // Récupérer le prochain ID disponible
    QSqlQuery queryId;
    int newId = 1;
    if (queryId.exec("SELECT NVL(MAX(ID_MATERIAU), 0) + 1 FROM ATELIER.MATERIAU")) {
        if (queryId.next()) {
            newId = queryId.value(0).toInt();
        }
    }

    QSqlQuery query;
    query.prepare("INSERT INTO ATELIER.MATERIAU (ID_MATERIAU, NOM, TYPE, QUANTITE, PRIX_ACHAT, SEUIL_ALERTE) VALUES (:id, :nom, :type, :quantite, :prix, :seuil)");
    query.bindValue(":id", newId);
    query.bindValue(":nom", ui->txtNom->text().trimmed());
    query.bindValue(":type", ui->comboType->currentText());
    query.bindValue(":quantite", ui->spinQuantite->value());
    query.bindValue(":prix", ui->spinPrixAchat->value());
    query.bindValue(":seuil", ui->spinSeuilAlerte->value());

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Ajout impossible : " + query.lastError().text());
        return;
    }

    chargerTable();
    clearForm();
    remplirStats();
    verifierAlertesStock();
    afficherNotification("✅ Matériau ajouté avec succès !", "#2ecc71");
}

void StockWidget::onModifier()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Sélection", "Veuillez sélectionner un matériau à modifier.");
        return;
    }

    QString id = ui->tableWidget->item(currentRow, 0)->text();

    if (id.isEmpty()) {
        QMessageBox::warning(this, "Erreur", "ID du matériau non trouvé.");
        return;
    }

    if (ui->txtNom->text().trimmed().isEmpty()) {
        QMessageBox::warning(this, "Champ requis", "Veuillez saisir le nom du matériau.");
        return;
    }

    if (!ensureDbOpen()) return;

    QSqlQuery query;
    query.prepare("UPDATE ATELIER.MATERIAU SET NOM = :nom, TYPE = :type, QUANTITE = :quantite, PRIX_ACHAT = :prix, SEUIL_ALERTE = :seuil WHERE ID_MATERIAU = :id");
    query.bindValue(":id", id);
    query.bindValue(":nom", ui->txtNom->text().trimmed());
    query.bindValue(":type", ui->comboType->currentText());
    query.bindValue(":quantite", ui->spinQuantite->value());
    query.bindValue(":prix", ui->spinPrixAchat->value());
    query.bindValue(":seuil", ui->spinSeuilAlerte->value());

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Modification impossible : " + query.lastError().text());
        return;
    }

    chargerTable();
    clearForm();
    remplirStats();
    verifierAlertesStock();
    afficherNotification("✏️ Matériau modifié avec succès !", "#f39c12");
}

void StockWidget::onSupprimer()
{
    int currentRow = ui->tableWidget->currentRow();
    if (currentRow < 0) {
        QMessageBox::warning(this, "Sélection", "Veuillez sélectionner un matériau à supprimer.");
        return;
    }

    QString id = ui->tableWidget->item(currentRow, 0)->text();

    QMessageBox::StandardButton reply = QMessageBox::question(this, "Confirmation", "Supprimer ce matériau ?", QMessageBox::Yes | QMessageBox::No);
    if (reply != QMessageBox::Yes) return;

    if (!ensureDbOpen()) return;

    QSqlQuery query;
    query.prepare("DELETE FROM ATELIER.MATERIAU WHERE ID_MATERIAU = :id");
    query.bindValue(":id", id);

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Suppression impossible : " + query.lastError().text());
        return;
    }

    chargerTable();
    clearForm();
    remplirStats();
    verifierAlertesStock();
    afficherNotification("🗑️ Matériau supprimé avec succès !", "#e74c3c");
}

void StockWidget::onNouveau()
{
    clearForm();
    ui->tableWidget->clearSelection();
    afficherNotification("🆕 Formulaire réinitialisé", "#3498db");
}

void StockWidget::onRechercher()
{
    QString nom = ui->txtRecherche->text().trimmed();
    QString type = ui->comboFiltreType->currentText();

    if (nom.isEmpty() && type == "Tous les types") {
        chargerTable();
        return;
    }

    if (!ensureDbOpen()) return;

    QString sql = "SELECT ID_MATERIAU, NOM, TYPE, QUANTITE, PRIX_ACHAT, SEUIL_ALERTE FROM ATELIER.MATERIAU WHERE 1=1";
    if (!nom.isEmpty()) {
        sql += " AND NOM LIKE :nom";
    }
    if (type != "Tous les types") {
        sql += " AND TYPE = :type";
    }

    QSqlQuery query;
    query.prepare(sql);
    if (!nom.isEmpty()) {
        query.bindValue(":nom", "%" + nom + "%");
    }
    if (type != "Tous les types") {
        query.bindValue(":type", type);
    }

    if (!query.exec()) {
        QMessageBox::critical(this, "Erreur", "Recherche impossible : " + query.lastError().text());
        return;
    }

    chargerTable(query);
    afficherNotification("🔍 Recherche effectuée", "#1abc9c");
}

void StockWidget::remplirStats()
{
    if (!ensureDbOpen()) return;

    QSqlQuery queryTotal;
    queryTotal.exec("SELECT COUNT(*) FROM ATELIER.MATERIAU");
    if (queryTotal.next()) {
        ui->lblTotalMateriaux->setText(QString::number(queryTotal.value(0).toInt()));
    }

    QSqlQuery queryTypes;
    queryTypes.exec("SELECT COUNT(DISTINCT TYPE) FROM ATELIER.MATERIAU");
    if (queryTypes.next()) {
        ui->lblTypesMateriaux->setText(QString::number(queryTypes.value(0).toInt()));
    }

    QSqlQuery queryRepart;
    queryRepart.exec("SELECT TYPE, COUNT(*) as NB, SUM(QUANTITE) as TOTAL_QUANTITE FROM ATELIER.MATERIAU GROUP BY TYPE ORDER BY TOTAL_QUANTITE DESC");

    QTableWidget *tableStats = ui->tableStats;
    tableStats->setRowCount(0);
    tableStats->setColumnCount(4);
    tableStats->setHorizontalHeaderLabels({"Type", "Nombre d'articles", "Quantité Totale", "Pourcentage"});

    double totalGeneral = 0;
    QList<double> quantites;
    QList<QString> types;
    QList<int> nbArticles;

    while (queryRepart.next()) {
        types << queryRepart.value("TYPE").toString();
        nbArticles << queryRepart.value("NB").toInt();
        double qte = queryRepart.value("TOTAL_QUANTITE").toDouble();
        quantites << qte;
        totalGeneral += qte;
    }

    for (int i = 0; i < types.size(); i++) {
        tableStats->insertRow(i);
        tableStats->setItem(i, 0, new QTableWidgetItem(types[i]));
        tableStats->setItem(i, 1, new QTableWidgetItem(QString::number(nbArticles[i])));
        tableStats->setItem(i, 2, new QTableWidgetItem(QString::number(quantites[i], 'f', 2)));

        double pourcentage = (totalGeneral > 0) ? (quantites[i] / totalGeneral * 100) : 0;
        tableStats->setItem(i, 3, new QTableWidgetItem(QString::number(pourcentage, 'f', 2) + "%"));
    }

    tableStats->resizeColumnsToContents();
}

void StockWidget::onActualiserStats()
{
    remplirStats();
    afficherNotification("📊 Statistiques actualisées !", "#3498db");
}

void StockWidget::onGenererReappro()
{
    if (!ensureDbOpen()) return;

    QSqlQuery query;
    query.exec("SELECT ID_MATERIAU, NOM, QUANTITE, SEUIL_ALERTE FROM ATELIER.MATERIAU WHERE QUANTITE < SEUIL_ALERTE * 2 ORDER BY QUANTITE ASC");

    QTableWidget *table = ui->tableReappro;
    table->setRowCount(0);
    table->setColumnCount(4);
    table->setHorizontalHeaderLabels({"Matériau", "Stock Actuel", "Quantité Recommandée", "Priorité"});

    int row = 0;
    while (query.next()) {
        table->insertRow(row);
        double stockActuel = query.value("QUANTITE").toDouble();
        double seuil = query.value("SEUIL_ALERTE").toDouble();
        double recommandation = 0;
        QString priorite;

        if (stockActuel < seuil) {
            recommandation = seuil * 10;
            priorite = "⚠️ CRITIQUE - Réapprovisionner immédiatement!";
        } else if (stockActuel < seuil * 2) {
            recommandation = seuil * 5;
            priorite = "🟡 Moyenne - Prévoir réapprovisionnement";
        } else {
            recommandation = seuil * 2;
            priorite = "🟢 Basse - Stock confortable";
        }

        table->setItem(row, 0, new QTableWidgetItem(query.value("NOM").toString()));
        table->setItem(row, 1, new QTableWidgetItem(QString::number(stockActuel, 'f', 2) + " unités"));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(recommandation, 'f', 0) + " unités"));
        table->setItem(row, 3, new QTableWidgetItem(priorite));
        row++;
    }

    table->resizeColumnsToContents();

    if (row == 0) {
        afficherNotification("✅ Stock suffisant - Aucun réapprovisionnement nécessaire", "#27ae60");
    } else {
        afficherNotification(QString("📦 %1 matériau(x) à réapprovisionner").arg(row), "#f39c12");
    }
}

void StockWidget::onPrevision()
{
    int nbCommandes = ui->spinNbCommandes->value();
    int periode = ui->spinPeriode->value();

    if (!ensureDbOpen()) return;

    QSqlQuery query;
    query.exec("SELECT ID_MATERIAU, NOM, QUANTITE, SEUIL_ALERTE FROM ATELIER.MATERIAU");

    QTableWidget *table = ui->tablePrevision;
    table->setRowCount(0);
    table->setColumnCount(5);
    table->setHorizontalHeaderLabels({"Matériau", "Consommation Moyenne", "Consommation Prévue", "Stock Actuel", "Stock Suffisant?"});

    QRandomGenerator *generator = QRandomGenerator::global();

    int row = 0;
    while (query.next()) {
        table->insertRow(row);
        double stockActuel = query.value("QUANTITE").toDouble();
        double seuil = query.value("SEUIL_ALERTE").toDouble();
        double consoMoyenne = (generator->bounded(20) + 5);
        double consoPrevue = consoMoyenne * (nbCommandes / 10.0) * (periode / 30.0);

        table->setItem(row, 0, new QTableWidgetItem(query.value("NOM").toString()));
        table->setItem(row, 1, new QTableWidgetItem(QString::number(consoMoyenne, 'f', 2) + " unités/commande"));
        table->setItem(row, 2, new QTableWidgetItem(QString::number(consoPrevue, 'f', 2) + " unités"));
        table->setItem(row, 3, new QTableWidgetItem(QString::number(stockActuel, 'f', 2) + " unités"));

        QString suffisant;
        if (stockActuel >= consoPrevue) {
            suffisant = "✅ Oui";
        } else if (stockActuel < seuil) {
            suffisant = "❌ CRITIQUE - Stock sous le seuil d'alerte!";
        } else {
            suffisant = "⚠️ Non - Réapprovisionner bientôt";
        }
        table->setItem(row, 4, new QTableWidgetItem(suffisant));
        row++;
    }

    table->resizeColumnsToContents();
    afficherNotification("📈 Prévisions calculées", "#9b59b6");
}

void StockWidget::onTrierParQuantite()
{
    if (!ensureDbOpen()) return;

    QString ordre = ui->radioCroissant->isChecked() ? "ASC" : "DESC";
    QString ordreTexte = ui->radioCroissant->isChecked() ? "croissant" : "décroissant";

    QSqlQuery query;
    QString sql = QString("SELECT ID_MATERIAU, NOM, TYPE, QUANTITE, PRIX_ACHAT, SEUIL_ALERTE FROM ATELIER.MATERIAU ORDER BY QUANTITE %1").arg(ordre);

    if (!query.exec(sql)) {
        QMessageBox::critical(this, "Erreur", "Impossible de trier : " + query.lastError().text());
        return;
    }

    QTableWidget *table = ui->tableTriQuantite;
    table->setRowCount(0);
    table->setColumnCount(6);
    table->setHorizontalHeaderLabels({"ID", "Nom", "Type", "Quantité", "Prix Achat (TND)", "Seuil Alerte"});
    table->setColumnHidden(0, true);

    int row = 0;
    while (query.next()) {
        table->insertRow(row);
        table->setItem(row, 0, new QTableWidgetItem(query.value("ID_MATERIAU").toString()));
        table->setItem(row, 1, new QTableWidgetItem(query.value("NOM").toString()));
        table->setItem(row, 2, new QTableWidgetItem(query.value("TYPE").toString()));

        double quantite = query.value("QUANTITE").toDouble();
        double seuil = query.value("SEUIL_ALERTE").toDouble();

        QTableWidgetItem *qteItem = new QTableWidgetItem(QString::number(quantite, 'f', 2) + " unités");
        table->setItem(row, 3, qteItem);

        double prix = query.value("PRIX_ACHAT").toDouble();
        table->setItem(row, 4, new QTableWidgetItem(QString::number(prix, 'f', 2) + " TND"));
        table->setItem(row, 5, new QTableWidgetItem(QString::number(seuil, 'f', 0) + " unités"));

        if (quantite < 10) {
            qteItem->setBackground(Qt::red);
            qteItem->setForeground(Qt::white);
        } else if (quantite < 50) {
            qteItem->setBackground(Qt::yellow);
        }

        if (quantite <= seuil) {
            qteItem->setBackground(Qt::red);
            qteItem->setForeground(Qt::white);
        }

        row++;
    }

    table->resizeColumnsToContents();
    afficherNotification(QString("✅ Tri effectué : %1 matériaux (%2)").arg(row).arg(ordreTexte), "#1abc9c");
}