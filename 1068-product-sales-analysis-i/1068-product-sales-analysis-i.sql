/* Write your T-SQL query statement below */
SELECT s.year as year, s.price as price, p.product_name as product_name
FROM Sales s
JOIN Product p
ON s.product_id = p.product_id;