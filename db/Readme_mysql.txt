
MYSQL Cheatsheet
=================

MySQL Workbench is a good tool

From Linux machine to access database "$mysql --password" or
"$mysql -u root -p"

1. show databases;
2. SELECT User, Host FROM mysql.user;
   For connecting with mySQL workbench
   link: https://stackoverflow.com/questions/33827342/how-to-connect-mysql-workbench-to-running-mysql-inside-docker
   create user 'user'@'%' identified by 'pass';
   grant all privileges on *.* to 'user'@'%' with grant option;
   flush privileges;
3. create database testdb
4. show create database testdb; -> returns the database name and the character set and collation of the database
5. use <db_name>
6. show tables;
7. show columns from table1; 

12/01/2023
------------

Querying Data from a Table
~~~~~~~~~~~~~~~~~~~~~~~~~~
SELECT c1,c2 from t;
SELECT * FROM t;
SELECT c1,c2 FROM t WHERE <condition>;
SELECT DISTINCT c1 FROM t;
SELECT c1,c2 FROM t ORDER by c1 ASC [DESC];
SELECT c1,c2 FROM t ORDER by c1 LIMIT n OFFSET offset;
SELECT c1, aggregate(c2) FROM t GROUP BY c1;
SELECT c1, aggregate(c2) FROM t GROUP BY c1 HAVING <condition>

Q. Difference between WHERE and HAVING keywords?
'WHERE' filters individual rows before grouping, while HAVING filters
aggregated results after grouping has occured

