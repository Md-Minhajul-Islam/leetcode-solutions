/* Write your T-SQL query statement below */
SELECT
activity_date as day,
COUNT(DISTINCT user_id) AS active_users
FROM Activity
WHERE 
DATEDIFF(Day, activity_date, '2019-07-27') < 30
AND 
DATEDIFF(DAY, activity_date, '2019-07-27') >= 0
AND
(activity_type = 'open_session' OR activity_type = 'end_session' OR activity_type = 'scroll_down' OR activity_type = 'send_message')
GROUP BY activity_date;