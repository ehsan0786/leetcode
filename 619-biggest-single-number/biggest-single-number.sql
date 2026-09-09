# Write your MySQL query statement below

-- select 
--     num
-- from MyNumbers 
-- group by num
-- having count(num) = 1

-- | num |
-- | --- |
-- | 1   |
-- | 4   |
-- | 5   |
-- | 6   |


select 
    max(num) as num
from MyNumbers 
where num in(
    select num
    from MyNumbers 
    group by num
    having count(num) = 1
)