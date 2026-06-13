/* Write your T-SQL query statement below */
select *, round(amount / 7.0, 2) as average_amount
from (
    select c.visited_on, sum(amount) over (order by visited_on rows between 6 preceding and current row) as amount
    from (
        select visited_on, sum(amount) as amount
        from customer
        group by visited_on
    ) c
) a
order by visited_on
offset 6 rows