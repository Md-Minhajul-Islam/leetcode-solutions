
WITH sortedWeightSum AS (
    SELECT
    person_id, 
    person_name,
    turn,
    SUM(weight) OVER(ORDER BY turn) AS total_weight
    FROM Queue
)

SELECT TOP 1
person_name
FROM sortedWeightSum
WHERE total_weight <= 1000
ORDER BY turn DESC