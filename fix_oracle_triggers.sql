-- ============================================================
-- CORRECTIONS ORACLE - A exécuter dans SQL Developer
-- ============================================================

-- 1. Corriger le trigger MACHINE_TRG (était vide, ne générait pas l'ID)
CREATE OR REPLACE TRIGGER "ATELIER"."MACHINE_TRG"
BEFORE INSERT ON ATELIER.MACHINE
FOR EACH ROW
BEGIN
  IF :NEW.ID_MACHINE IS NULL THEN
    :NEW.ID_MACHINE := ATELIER.MACHINE_SEQ.NEXTVAL;
  END IF;
END;
/
ALTER TRIGGER "ATELIER"."MACHINE_TRG" ENABLE;

-- 2. Vérifier que la séquence MACHINE_SEQ existe (déjà dans le script original)
-- Si elle n'existe pas, la créer :
-- CREATE SEQUENCE "ATELIER"."MACHINE_SEQ" MINVALUE 1 INCREMENT BY 1 START WITH 1 CACHE 20 NOCYCLE;

-- 3. Vérifier les triggers existants sont bien activés
ALTER TRIGGER "ATELIER"."TRG_CLIENT_ID" ENABLE;
ALTER TRIGGER "ATELIER"."TRG_COMMANDE_ID" ENABLE;
ALTER TRIGGER "ATELIER"."TRG_EMPLOYE_ID" ENABLE;
