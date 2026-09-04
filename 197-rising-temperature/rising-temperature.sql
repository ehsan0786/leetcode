# Write your MySQL query statement below
SELECT 
    W1.id
FROM Weather as W1 -- today's weather
inner JOIN Weather as W2 -- yesterday's weather
ON W1.recordDate = DATE_ADD(W2.recordDate, INTERVAL 1 DAY)
WHERE W1.temperature > W2.temperature

-- DATE_ADD = kisi date mein kuch time add karna.

-- For example:

-- + 1 DAY
-- + 2 DAY
-- + 1 MONTH
-- + 1 YEAR
