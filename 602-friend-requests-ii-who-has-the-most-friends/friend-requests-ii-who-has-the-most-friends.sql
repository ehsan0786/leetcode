# Write your MySQL query statement below

select 
    requester_id as id,
    count(*) as num
from (
    select requester_id 
    from RequestAccepted 

    union all

    select accepter_id 
    from RequestAccepted  
) as num_friends
group by id
order by num desc
limit 1

-- select requester_id 
-- from RequestAccepted 

-- union all

-- select accepter_id 
-- from RequestAccepted  