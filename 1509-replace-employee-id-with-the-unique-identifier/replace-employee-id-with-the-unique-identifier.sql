# Write your MySQL query statement below

select 
    EU.unique_id,
    E.name
from Employees as E
left join EmployeeUNI as EU
on E.id = EU.id

