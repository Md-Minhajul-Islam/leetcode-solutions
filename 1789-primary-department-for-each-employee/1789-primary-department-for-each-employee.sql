# Write your MySQL query statement below

WITH departmentCount AS (
    SELECT
    employee_id,
    COUNT(DISTINCT department_id) as count
    FROM Employee
    GROUP BY employee_id
)

SELECT
e.employee_id,
e.department_id
FROM Employee e
JOIN departmentCount dc
ON e.employee_id = dc.employee_id
WHERE dc.count = 1 OR e.primary_flag = 'Y'