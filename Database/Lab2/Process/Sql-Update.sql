

select d1.inner_station_id as inner1, d2.inner_station_id as inner2, d1.train_id, min(r.tickets), r.the_day, r.seat_type
into temp4
from station as s1, station as s2, database1 as d1, database1 as d2, remaining_ticket as r
where s1.station_name = $1 and s2.station_name = $2
and s1.station_id = d1.outer_station_id and s2.station_id = d2.outer_station_id
and d1.train_id = d2.train_id and d1.train_id = $3
and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id
and r.train_id = d1.train_id and r.the_day = $4 and r.seat_type = $5
group by d1.inner_station_id, d2.inner_station_id, d1.train_id, r.tickets, r.the_day, r.seat_type;


update remaining_ticket
set tickets = tickets - 1
from temp4 as t
where remaining_ticket.inner_station_id between t.inner1 + 1 and t.inner2
and remaining_ticket.train_id = t.train_id
and remaining_ticket.the_day = 1
and remaining_ticket.seat_type = t.seat_type
and t.min > 0;

drop table temp4;
