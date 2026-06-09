# Write your MySQL query statement below
select name, coalesce(travelled_distance, 0) as travelled_distance  
from (
    select user_id, name, sum(distance) as travelled_distance 
    from users u
    left join rides r
    on r.user_id = u.id
    group by user_id, name
) a
order by travelled_distance desc, name