-- Migration metiers avances (Oracle)
-- Compatible with current export55.sql schema.
-- Safe to run multiple times.

SET SERVEROUTPUT ON;

PROMPT === [1/4] Add SEUIL_ALERTE to ATELIER.MATERIAU if missing ===
DECLARE
    v_count NUMBER := 0;
BEGIN
    SELECT COUNT(*)
      INTO v_count
      FROM ALL_TAB_COLUMNS
     WHERE OWNER = 'ATELIER'
       AND TABLE_NAME = 'MATERIAU'
       AND COLUMN_NAME = 'SEUIL_ALERTE';

    IF v_count = 0 THEN
        EXECUTE IMMEDIATE 'ALTER TABLE ATELIER.MATERIAU ADD (SEUIL_ALERTE NUMBER(10,2))';
        DBMS_OUTPUT.PUT_LINE('Column SEUIL_ALERTE added.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Column SEUIL_ALERTE already exists.');
    END IF;
END;
/

PROMPT === [2/4] Backfill threshold where null ===
UPDATE ATELIER.MATERIAU
   SET SEUIL_ALERTE = CASE
       WHEN QUANTITE IS NULL OR QUANTITE <= 0 THEN 5
       ELSE GREATEST(5, ROUND(QUANTITE * 0.30, 2))
   END
 WHERE SEUIL_ALERTE IS NULL;

COMMIT;

PROMPT === [3/4] Add non-negative check constraint (idempotent) ===
DECLARE
    v_count NUMBER := 0;
BEGIN
    SELECT COUNT(*)
      INTO v_count
      FROM ALL_CONSTRAINTS
     WHERE OWNER = 'ATELIER'
       AND TABLE_NAME = 'MATERIAU'
       AND CONSTRAINT_NAME = 'CHK_MAT_SEUIL_NONNEG';

    IF v_count = 0 THEN
        EXECUTE IMMEDIATE 'ALTER TABLE ATELIER.MATERIAU ADD CONSTRAINT CHK_MAT_SEUIL_NONNEG CHECK (SEUIL_ALERTE IS NULL OR SEUIL_ALERTE >= 0) ENABLE';
        DBMS_OUTPUT.PUT_LINE('Constraint CHK_MAT_SEUIL_NONNEG added.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Constraint CHK_MAT_SEUIL_NONNEG already exists.');
    END IF;
END;
/

PROMPT === [4/4] Optional performance index for stock forecast query ===
DECLARE
    v_count NUMBER := 0;
BEGIN
    SELECT COUNT(*)
      INTO v_count
      FROM ALL_INDEXES
     WHERE OWNER = 'ATELIER'
       AND INDEX_NAME = 'IDX_COMMANDE_DATE';

    IF v_count = 0 THEN
        EXECUTE IMMEDIATE 'CREATE INDEX ATELIER.IDX_COMMANDE_DATE ON ATELIER.COMMANDE (DATE_COMMANDE)';
        DBMS_OUTPUT.PUT_LINE('Index IDX_COMMANDE_DATE created.');
    ELSE
        DBMS_OUTPUT.PUT_LINE('Index IDX_COMMANDE_DATE already exists.');
    END IF;
END;
/

PROMPT === Migration completed ===
