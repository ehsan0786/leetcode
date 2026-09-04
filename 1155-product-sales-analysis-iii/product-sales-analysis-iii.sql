# Write your MySQL query statement below
select 
    product_id,
    year as first_year,
    quantity,
    price
from Sales
WHERE (product_id, year) in (
    SELECT 
        product_id, 
        MIN(year) 
    FROM Sales
    GROUP BY product_id
)