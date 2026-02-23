-- Script de création de la table MACHINES pour Oracle
-- Exécutez ce script dans Oracle SQL Developer

-- Supprimer la table si elle existe déjà
DROP TABLE MACHINES CASCADE CONSTRAINTS;

-- Créer la table MACHINES
CREATE TABLE MACHINES (
    ID VARCHAR2(10) PRIMARY KEY,
    NOM VARCHAR2(100) NOT NULL,
    TYPE VARCHAR2(50) NOT NULL,
    ETAT VARCHAR2(50) NOT NULL,
    DATE_MAINTENANCE DATE,
    HEURES_CUMULEES NUMBER,
    RESP_MAINTENANCE VARCHAR2(100),
    RESP_ATELIER VARCHAR2(100)
);

-- Insérer des données de test
INSERT INTO MACHINES VALUES ('001', 'Scie Circulaire A', 'Scie', 'Disponible', TO_DATE('2024-01-15', 'YYYY-MM-DD'), 520, 'Ahmed Ben Ali', 'Mohamed Trabelsi');
INSERT INTO MACHINES VALUES ('002', 'Perceuse B', 'Perceuse', 'Disponible', TO_DATE('2024-02-10', 'YYYY-MM-DD'), 180, 'Fatma Gharbi', 'Mohamed Trabelsi');
INSERT INTO MACHINES VALUES ('003', 'Raboteuse C', 'Raboteuse', 'En maintenance', TO_DATE('2024-01-20', 'YYYY-MM-DD'), 380, 'Ahmed Ben Ali', 'Salah Mansour');
INSERT INTO MACHINES VALUES ('004', 'Ponceuse D', 'Ponceuse', 'Disponible', TO_DATE('2024-02-05', 'YYYY-MM-DD'), 450, 'Leila Sassi', 'Mohamed Trabelsi');
INSERT INTO MACHINES VALUES ('005', 'Tour à bois E', 'Tour à bois', 'Hors service', TO_DATE('2023-12-28', 'YYYY-MM-DD'), 650, 'Ahmed Ben Ali', 'Salah Mansour');

-- Valider les changements
COMMIT;

-- Vérifier les données
SELECT * FROM MACHINES ORDER BY ID;
