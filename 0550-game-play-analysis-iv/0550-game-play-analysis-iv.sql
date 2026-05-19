/* Write your T-SQL query statement below */
WITH FirstLogin AS (
    SELECT 
    player_id, 
    MIN(event_date) AS event_date
    FROM Activity
    GROUP BY player_id
),
NextLogin AS (
    SELECT DISTINCT a.player_id
    FROM Activity a
    JOIN FirstLogin f
    ON a.player_id = f.player_id
    WHERE DATEDIFF(DAY, f.event_date, a.event_date) = 1
)

SELECT 
ROUND(COUNT(*)*1.0 / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM NextLogin
