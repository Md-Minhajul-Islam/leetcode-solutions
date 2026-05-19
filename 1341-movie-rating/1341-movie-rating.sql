/* Write your T-SQL query statement below */

WITH firstQuery AS (
    SELECT TOP 1
    m.user_id,
    u.name,
    COUNT(*) AS movie_count
    FROM MovieRating m
    JOIN Users u ON m.user_id = u.user_id
    GROUP BY m.user_id, u.name
    ORDER BY movie_count DESC, u.name ASC
),
fabRat AS (
    SELECT *
    FROM MovieRating
    WHERE FORMAT(created_at, 'yyyy-MM') = '2020-02'
),
secondQuery AS(
    SELECT TOP 1
    fr.movie_id,
    m.title,
    AVG(fr.rating*1.0) AS avg_rating
    FROM fabRat fr
    JOIN Movies m ON fr.movie_id = m.movie_id
    GROUP BY fr.movie_id, m.title
    ORDER BY avg_rating DESC, m.title ASC
)

SELECT name AS results FROM firstQuery

UNION ALL

SELECT title AS results FROM secondQuery

