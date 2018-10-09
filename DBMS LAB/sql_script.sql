CREATE DATABASE test_db;
USE test_db;
CREATE TABLE test (id INT, name VARCHAR(10));
INSERT INTO test VALUES(1, 'Adarsh'), (2, 'Augustine');

DELIMITER // 

# Control structure
CREATE PROCEDURE test_proc(IN i INT)
BEGIN
SELECT * FROM test WHERE name = IF(i>0, "Adarsh", "Augustine");
END //

CALL test_proc(0) //

# Procedure
CREATE PROCEDURE proc_for_loop(IN i INT) 
BEGIN
DECLARE counter INT UNSIGNED DEFAULT 0;
WHILE counter < i DO
INSERT INTO test VALUES(counter, "looper");
SET counter = counter+1;
END WHILE;
END //

CALL proc_for_loop(5)//

SELECT * FROM test//

# Trigger
CREATE TRIGGER test_trigger 
BEFORE INSERT ON trigger_target
FOR EACH ROW 
IF NEW.id > 0 THEN
   INSERT INTO trigger_message VALUES(CONCAT("trigger", NEW.id));
END IF
//

# Cursor


