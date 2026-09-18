# Write your MySQL query statement below

-- select 
--     d.name as Department,
--     e.name  as Employee,
--     e.salary as Salary
-- from Employee as e
-- inner join Department as d
-- on e.departmentId = d.id
-- where 3 > (
--     select count(distinct e1.salary)
--     from Employee as e1
--     where e1.salary > e.salary and
--     e1.departmentId = e.departmentId
-- )


WITH new_table AS (
    SELECT 
        d.name AS Department,
        e.name AS Employee,
        e.salary AS Salary,
        DENSE_RANK() OVER(PARTITION BY d.name ORDER BY e.salary DESC) AS ranking
    FROM Employee as e
    inner JOIN Department as d
    ON e.departmentId = d.id
)
SELECT Department, Employee, Salary
FROM new_table
WHERE ranking <= 3;