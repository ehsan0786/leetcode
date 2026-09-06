# Write your MySQL query statement below
select 
    ST.student_id,
    ST.student_name,
    SB.subject_name,
    count(EX.subject_name) as attended_exams
from Students as ST
cross join Subjects as SB
left join Examinations as EX
on ST.student_id = EX.student_id and SB.subject_name = EX.subject_name
group by ST.student_id , ST.student_name,SB.subject_name
order by student_id,subject_name

-- A CROSS JOIN combines every row of Table A with every row of Table B.

-- A **CROSS JOIN** combines **every row of left Table  with every row of right Table** 
-- (mxn)

-- new table