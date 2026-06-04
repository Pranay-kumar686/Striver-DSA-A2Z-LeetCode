# Write your MySQL query statement below
UPDATE Salary
SET Sex = CASE
WHEN Sex = 'f' THEN 'm'
ELSE 'f'
END