select r.seat_type
from remaining_ticket as r, database1 as d1, database1 as d2, the_date as t
where d1.train_id = 'D321' and d2.train_id = 'D321' and r.train_id = 'D321'
and d1.station_name = '北京南' and d2.station_name = '南京'
and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id
and d1.inner_station_id < d2.inner_station_id
and r.the_day = t.date_id and t.actual_date = '2016-11-18'
group by r.seat_type
having min(r.tickets) > 0;

select r.seat_type
from remaining_ticket as r, database1 as d1, database1 as d2, the_date as t
where d1.train_id = 'D321' and d2.train_id = 'D321' and r.train_id = 'D321'
and d1.station_name = '北京南' and d2.station_name = '南京'
and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id
and d1.inner_station_id < d2.inner_station_id
and r.the_day = t.date_id and t.date_id = 1
group by r.seat_type
having min(r.tickets) > 0;
