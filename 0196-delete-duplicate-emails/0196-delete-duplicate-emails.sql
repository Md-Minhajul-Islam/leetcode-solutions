/* Write your T-SQL query statement below */
WITH ranked AS (
    SELECT *,
    DENSE_RANK() OVER (PARTITION BY email ORDER BY id) AS rn
    FROM Person
)
DELETE FROM ranked
WHERE rn > 1;