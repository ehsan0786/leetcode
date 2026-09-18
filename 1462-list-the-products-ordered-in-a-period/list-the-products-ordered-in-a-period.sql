# Write your MySQL query statement below
select
    p.product_name,
    sum(o.unit) as unit
from Products as p
inner join Orders as o
on p.product_id = o.product_id 
where extract(month from o.order_date) = 2 and
     extract(year from o.order_date) = 2020
group by p.product_name       
having unit>=100