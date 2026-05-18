# Write your MySQL query statement below


SELECT
    ROUND(
        (SELECT 
            COUNT(*)
            FROM Activity a1
            JOIN Activity a2
            ON a1.player_id = a2.player_id
            WHERE DATEDIFF(a1.event_date, a2.event_date) = 1
            AND a2.event_date = (
                SELECT MIN(event_date)
                FROM Activity
                WHERE player_id = a2.player_id
            ) 
        ) / 
        ( SELECT COUNT(DISTINCT player_id) FROM Activity)
, 2) AS fraction;