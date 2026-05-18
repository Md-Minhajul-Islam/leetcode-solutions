# Write your MySQL query statement below
SELECT 
    ROUND(
        (SELECT COUNT(*)
    FROM(
        SELECT 
            *
        FROM Delivery
        GROUP BY customer_id
        HAVING MIN(order_date) = MIN(customer_pref_delivery_date)) AS t
     ) * 100  / 

        (SELECT COUNT(DISTINCT customer_id) FROM Delivery)
    , 2) AS immediate_percentage