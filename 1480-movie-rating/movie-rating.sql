# Write your MySQL query statement below
(select 
    u.name as results
from Users as u
inner join MovieRating as m1
on u.user_id = m1.user_id      
group by u.user_id
order by count(m1.rating) desc,u.name
limit 1)

union all

(select
    m.title as results
from Movies as m
inner join MovieRating as m2
on m.movie_id = m2.movie_id
where extract(month from m2.created_at) =2 and
    extract(year from m2.created_at) = 2020
group by m.movie_id  
order by avg(m2.rating) desc, m.title
limit 1)


-- UNION combines the results and removes duplicate rows.
-- UNION ALL combines the results but keeps duplicates.

-- UNION = Combine + Remove duplicates
-- UNION ALL = Combine + Keep ALL rows