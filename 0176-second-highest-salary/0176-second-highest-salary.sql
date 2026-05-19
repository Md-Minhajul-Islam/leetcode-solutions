/* Write your T-SQL query statement below */

WITH Salary AS  (
    SELECT
    *,
    DENSE_RANK() OVER(ORDER BY salary DESC) AS rnk
    FROM Employee
)

SELECT
MAX(CASE WHEN rnk = 2 THEN salary END) AS SecondHighestSalary
FROM Salary
