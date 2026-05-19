/* Write your T-SQL query statement below */
WITH Managers AS (
    SELECT
    reports_to as manager_id,
    COUNT(DISTINCT employee_id) as reports_count,
    AVG(age*1.0) as average_age
    FROM Employees
    GROUP BY reports_to
)

SELECT
e.employee_id,
e.name,
m.reports_count,
ROUND(m.average_age, 0) AS average_age
FROM Employees e
JOIN Managers m
ON e.employee_id = m.manager_id
ORDER BY e.employee_id