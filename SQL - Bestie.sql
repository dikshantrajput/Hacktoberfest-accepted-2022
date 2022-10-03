/*USE E1FRIENDS;	--use table command
SELECT * FROM bestie;	--print whole table

CREATE TABLE bestie
(
fname varchar(12),
lname varchar(12),
nickname varchar(12),
age int,
course varchar(12),
destination varchar(12),
Dob date
);

SELECT * FROM bestie;

INSERT INTO bestie(fname, lname, nickname, age, course, destination, DOB)
VALUES('Mudit', 'Pandey', 'Manu', '19', 'BTech', 'canada', '2002-8-10');

SELECT * FROM bestie;

INSERT INTO bestie(fname, lname, nickname, age, course, destination)
VALUES('Avinash', 'Ojha', 'Avi', '19', 'Bcom', 'india'),
('Yash', 'Soni', 'yashu', '17', 'Pcb', 'usa'),
('Altaf', 'Qureshi', 'Altu', '22', 'Bcom', 'NULL'),
('Kanishk', 'Pandey', 'kanu', '16', 'Pcb', 'NULL'),
('Loveleen', 'Singh', 'Lava', '15', '9', 'NULL');

INSERT INTO bestie(fname, lname, nickname, age, course, destination, Dob)
VALUES('Tenver', 'Qureshi', 'NULL', '21', 'BTech', 'London', '2000-10-27');

SELECT * FROM bestie;

DELETE FROM bestie WHERE fname='Mudit';			-- DELETE ROW FROM TABLE

SELECT * FROM bestie;

EXEC sp_rename 'bestie.DOB', 'Dob', 'Column';						-- Rename Table COLUMN NAME
EXEC sp_rename 'bestie.destination', 'Destination', 'Column';

SELECT * FROM bestie;

ALTER DATABASE E1FRIENDS MODIFY NAME = E2FRIENDS;		-- Rename DATABASE NAME
SP_RenameDb N'E2FRIENDS', 'E1FRIENDS';

SELECT * FROM bestie;

UPDATE bestie SET Destination = 'India' WHERE Destination='NULL' OR Destination='india'; -- MULTIPLE UPDATE
UPDATE bestie SET Dob = '2006-11-13' WHERE Fname = 'Loveleen' AND Nickname='Lava';	-- SINGLE Record UPDATE
UPDATE bestie SET Destination = 'Dubai' WHERE Fname IN('Altaf', 'Naveen');	-- IN OPERATOR Record UPDATE

SELECT DATALENGTH (age) FROM bestie;

SELECT DATALENGTH(fname), DATALENGTH (age) FROM bestie;

SELECT * FROM bestie;

ALTER TABLE bestie ADD DOB date;		-- ADD NEW COLUMN IN TABLE

SELECT * FROM bestie;

SELECT fname, lname, nickname, DOB, age, course, destination FROM bestie;
SELECT * FROM bestie;
SELECT fname, age FROM bestie;

SELECT DISTINCT age, fname FROM bestie;

SELECT fname FROM bestie WHERE age=19;
SELECT * FROM bestie WHERE course='Bcom';
SELECT * FROM bestie WHERE age >= 17;

SELECT * FROM bestie;*/



/*--USE E1FRIENDS;
--SELECT * FROM bestie;

---------------------- ORDER DATA 

SELECT * FROM bestie ORDER BY age;		-- ASCENDING ORDER

SELECT * FROM bestie ORDER BY age DESC;		-- DESCENDING ORDER

SELECT * FROM bestie ORDER BY lname, age;		-- WITH TWO VALUES, ASCENDING ORDER

SELECT * FROM bestie WHERE lname='pandey' AND destination='canada';		-- USING AND OPERATOR

SELECT * FROM bestie WHERE age>='15' AND destination='canada';		-- USING AND OPERATOR

SELECT * FROM bestie;

SELECT * FROM bestie WHERE destination='canada' OR destination='usa';		-- USING OR OPERATOR

SELECT * FROM bestie WHERE NOT destination='canada';		-- USING NOT OPERATOR

DROP TABLE bestie;

BACKUP DATABASE E1FRIENDS
TO DISK='C:\Users\Administrator\Documents\E1 SQL Server Backup\mybackup.bak';

BACKUP DATABASE E1FRIENDS
TO DISK='D:\formal study\mybackup.bak'; 

SELECT * FROM bestie WHERE age IN('19' , '17', '16');		-- USING IN OPERATOR

SELECT * FROM bestie WHERE age NOT IN('19', '17', '16');		-- USING NOT OPERATOR

SELECT * FROM bestie WHERE fname LIKE 'A%';		-- USING LIKE OPERATOR

SELECT * FROM bestie WHERE nickname LIKE '%u';		-- USING LIKE OPERATOR

SELECT * FROM bestie WHERE fname LIKE '_a%';		-- USING LIKE OPERATOR

SELECT * FROM bestie WHERE fname NOT LIKE 'A%';		-- USING NOT LIKE OPERATOR 

SELECT max(age) AS Elder_Bhai FROM bestie;		-- USING MAX OPERATOR

SELECT MIN(age) AS Younger_Bhai FROM bestie;		-- USING MIN OPERATOR	*/



USE E1FRIENDS;
SELECT * FROM bestie;

SELECT SUM(age) AS Sum_of_Age FROM bestie;		-- USING SUM OPERATOR
SELECT SUM(age) AS Sum_of_Age FROM bestie WHERE Age >= 17;		-- USING SUM OPERATOR WITH WHERE CLAUSE

SELECT AVG(Age) AS Avg_Age FROM bestie;		-- USING AVG OPERATOR
SELECT AVG(Age) AS Avg_Age FROM bestie WHERE Age >= 16;		--INT USING AVG OPERATOR WITH WHERE CLAUSE

SELECT * FROM bestie WHERE Age BETWEEN 16 AND 19;
SELECT * FROM bestie WHERE Age NOT BETWEEN 16 AND 19;		--INT USING BETWEEN OPERATOR WITH WHERE & NOT

SELECT * FROM bestie WHERE Fname BETWEEN 'F%' AND 'Loveleen' ORDER BY Fname;	-- TEXT USING BETWEEN

SELECT COUNT(Nickname) FROM bestie WHERE Age > 17;		-- USING COUNT OPERATOR
SELECT COUNT(*) AS TOTAL_RECORDS FROM bestie;

SELECT TOP 2 * FROM bestie;							-- USING TOP STATEMENT

SELECT TOP 50 PERCENT * FROM bestie;

SELECT TOP 2 * FROM bestie WHERE Age > 19;

SELECT TOP 75 PERCENT * FROM bestie WHERE Age > 19;

ALTER TABLE bestie 
ADD PRIMARY KEY (Nickname);
