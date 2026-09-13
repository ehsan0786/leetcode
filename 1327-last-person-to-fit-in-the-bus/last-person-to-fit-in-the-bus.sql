# Write your MySQL query statement below
-- select 
--     person_name,turn,
--     sum(weight) over(order by turn) as total_weight
-- from Queue

-- | person_name | turn | total_weight |
-- | ----------- | ---- | ------------ |
-- | Alice       | 1    | 250          |
-- | Alex        | 2    | 600          |
-- | John Cena   | 3    | 1000         |
-- | Marie       | 4    | 1200         |
-- | Bob         | 5    | 1375         |
-- | Winston     | 6    | 1875         |



select
    person_name
from(
        select 
            turn,person_id,person_name,weight,
        sum(weight) over(order by turn) as total_weight
        from Queue
    ) as q
where total_weight <= 1000
order by turn desc
limit 1 




-- select 
--     turn,person_id,person_name,weight,
--     sum(weight) over(order by turn) as total_weight
-- from Queue

-- | turn | person_id | person_name | weight | total_weight |
-- | ---- | --------- | ----------- | ------ | ------------ |
-- | 1    | 5         | Alice       | 250    | 250          |
-- | 2    | 3         | Alex        | 350    | 600          |
-- | 3    | 6         | John Cena   | 400    | 1000         |
-- | 4    | 2         | Marie       | 200    | 1200         |
-- | 5    | 4         | Bob         | 175    | 1375         |
-- | 6    | 1         | Winston     | 500    | 1875         |