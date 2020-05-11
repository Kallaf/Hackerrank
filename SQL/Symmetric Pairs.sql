with pairs as (select *,ROW_NUMBER() OVER(ORDER BY x,y)id from functions)
select  t1.x, t1.y
from pairs t1
join pairs t2
on t1.x = t2.y and t2.x = t1.y and t1.id < t2.id
order by t1.x,t1.y;
