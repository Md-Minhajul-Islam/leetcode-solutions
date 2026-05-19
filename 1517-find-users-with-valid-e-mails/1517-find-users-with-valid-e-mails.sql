/* Write your T-SQL query statement below */

SELECT *
FROM Users
WHERE mail LIKE '[A-Za-Z]%@leetcode.com'  COLLATE Latin1_General_CS_AS
AND PATINDEX('%[^A-Za-Z0-9_.-]%', LEFT(mail, LEN(mail)-13)) = 0