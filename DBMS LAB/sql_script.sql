CREATE DATABASE test_db;
USE test_db;
CREATE TABLE test (id INT, name VARCHAR(10));
INSERT INTO test VALUES(1, 'Adarsh'), (2, 'Augustine');

DELIMITER // 

# Control structure
CREATE PROCEDURE test_proc(IN i INT)
BEGIN
# 1. If
SELECT * FROM test WHERE name = IF(i>0, "Adarsh", "Augustine");
END //

CALL test_proc(0) //

# Procedure
CREATE PROCEDURE proc_for_loop(IN i INT) 
BEGIN
DECLARE counter INT UNSIGNED DEFAULT 0;
# 2. While
WHILE counter < i DO
INSERT INTO test VALUES(counter, "looper");
SET counter = counter+1;
END WHILE;
END //

CALL proc_for_loop(5)//

/*CREATE PROCEDURE proc_case(IN i)
BEGIN
DECLARE dept CHAR(2);
SET dept = i;
CASE
	WHEN dept = 'D1' THEN
		SELECT "department 1";
	WHEN dept = 'D2' THEN 
		SELECT "department 2";
	ELSE
		SELECT "else case";
END CASE
END //*/

# 3. Case
UPDATE grade SET
grade = (CASE 
				WHEN mark > 90 THEN 'A' 
                WHEN mark = 90 THEN 'B'
                ELSE 'C'
                END)
WHERE id = 1//

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


