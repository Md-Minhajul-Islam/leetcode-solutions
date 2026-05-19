/* Write your T-SQL query statement below */

WITH requester AS (
    SELECT 
    requester_id AS id,
    COUNT(*) AS num
    FROM RequestAccepted
    GROUP BY requester_id

),
accepter AS (
    SELECT 
    accepter_id AS id,
    COUNT(*) AS num
    FROM RequestAccepted
    GROUP BY accepter_id
),
allIds AS (
    (SELECT DISTINCT id FROM requester)
    UNION
    (SELECT DISTINCT id FROM accepter)
)

SELECT TOP 1
al.id,
ISNULL(r.num, 0)+ISNULL(a.num, 0) AS num
FROM allIds al
LEFT JOIN requester r ON al.id = r.id
LEFT JOIN accepter a ON al.id = a.id
ORDER BY num DESC
