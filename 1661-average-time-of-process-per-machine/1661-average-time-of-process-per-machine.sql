# Write your MySQL query statement below
SELECT
    machine_id,
    ROUND(SUM(CASE WHEN activity_type='start' THEN timeStamp*-1 ELSE timeStamp END)*1.0
    / (SELECT COUNT(DISTINCT process_id)), 3) AS processing_time
FROM activity
GROUP BY machine_id