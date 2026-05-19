/* Write your T-SQL query statement below */
SELECT
*
FROM Patients
WHERE CHARINDEX('DIAB1', conditions) = 1 OR CHARINDEX(' DIAB1', conditions) > 1