# Write your MySQL query statement below
-- select name from Employee where 
-- id >= '5' having name = 'John'
-- order by name asc;

SELECT name 
FROM Employee 
WHERE id IN (SELECT managerId FROM Employee 
GROUP BY managerId HAVING COUNT(*) >= 5)