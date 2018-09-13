CREATE DATABASE test_db;
USE test_db;
CREATE TABLE test (id INT, name VARCHAR(10));
INSERT INTO test VALUES(1, 'Adarsh'), (2, 'Augustine');

DELIMITER //

CREATE PROCEDURE test_proc(IN i INT)
BEGIN
SELECT * FROM test WHERE name = IF(i>0, "Adarsh", "Augustine");
END //


CALL test_proc(4) //
