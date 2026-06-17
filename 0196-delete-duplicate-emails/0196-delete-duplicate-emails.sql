/* Write your T-SQL query statement below */

WITH rankedTable AS (
    SELECT
    *,
    DENSE_RANK() OVER(PARTITION BY email ORDER BY id) as rank
    FROM Person
)

DELETE
FROM rankedTable 
WHERE rank > 1