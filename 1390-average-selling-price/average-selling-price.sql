# Write your MySQL query statement below
-- on check every condition like cross join 
select 
    p.product_id,
    coalesce(round(sum(p.price*u.units)/sum(u.units),2),0) as average_price 
from Prices as p
left join UnitsSold as u
on p.product_id = u.product_id and 
    u.purchase_date between p.start_date and p.end_date   
group by p.product_id 



-- u.purchase_date BETWEEN p.start_date AND p.end_date
-- (or)
-- u.purchase_date >= p.start_date
-- AND
-- u.purchase_date <= p.end_date

-- Check whether u.purchase_date falls between p.start_date and p.end_date.