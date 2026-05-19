/* Write your T-SQL query statement below */


DECLARE @cnt INT = (SELECT COUNT(DISTINCT visited_on) FROM Customer)
DECLARE @offset INT = CASE WHEN @cnt < 7 THEN @cnt-1 ELSE 6 END

;WITH perDayTotalSum AS (
    SELECT
    visited_on,
    SUM(amount) AS amount
    FROM Customer
    GROUP BY visited_on 
) 

SELECT
visited_on,
SUM(amount) OVER(
    ORDER BY visited_on
    ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
    ) AS amount,
ROUND(AVG(amount*1.0) OVER(
    ORDER BY visited_on
    ROWS BETWEEN 6 PRECEDING AND CURRENT ROW
), 2) AS average_amount
FROM perDayTotalSum
ORDER BY visited_on
OFFSET @offset ROWS

