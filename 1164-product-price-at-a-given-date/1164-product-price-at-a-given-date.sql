# Write your MySQL query statement below

WITH smallerDates AS (
    SELECT
    product_id,
    change_date
    FROM Products
    WHERE DATEDIFF('2019-08-16', change_date) >= 0
),
maxSmallerDates AS (
    SELECT
    product_id,
    MAX(change_date) AS change_date
    FROM smallerDates
    GROUP BY product_id
),
uniqueIds AS (
    SELECT 
    DISTINCT(product_id) AS product_id 
    FROM Products
)


SELECT 
ui.product_id,
IF(p.new_price IS NULL, 10, p.new_price) AS price
FROM uniqueIds ui
LEFT JOIN maxSmallerDates msd ON ui.product_id = msd.product_id
LEFT JOIN Products p ON p.product_id = ui.product_id AND p.change_date = msd.change_date

