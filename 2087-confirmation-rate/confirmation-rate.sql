# Write your MySQL query statement below

select 
    s.user_id,        
    coalesce(round(sum(c.action = 'confirmed')/count(c.user_id),2),0.00) as confirmation_rate 
from Signups as s
left join Confirmations as c
on s.user_id  = c.user_id 
group by s.user_id   


-- SUM(c.action = 'confirmed')
-- means:
-- "SUM Count how many times the condition is TRUE.

-- A Foreign Key is a column that connects one table to another table.