# Write your MySQL query statement below

-- you need to count the number of players that logged in for at least two consecutive days starting from their first login date, then divide that number by the total number of players.


SELECT
  ROUND(COUNT(DISTINCT player_id) / (SELECT COUNT(DISTINCT player_id) FROM Activity), 2) AS fraction
FROM  Activity
where (player_id,DATE_SUB(event_date ,INTERVAL 1 DAY)) IN(
    select 
        player_id,
        min(event_date) as first_login
    from Activity
    group by player_id 
)


-- INTERVAL 1 DAY --> do conservative date jinka interval one hai..
-- DATE_SUB(event_date, INTERVAL 1 DAY) converts the current date into "yesterday", and the tuple IN checks whether that yesterday was the player's first login date.