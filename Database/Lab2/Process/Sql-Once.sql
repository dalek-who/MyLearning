select d1.train_id as train_id, s1.station_name as start_name, d1.departing_time as start_time, d1.inner_station_id as start_id, s2.station_name as end_name, d2.arriving_time as end_time, d2.inner_station_id as end_id, t.date_id as departing_day, t.date_id + d2.arriving_day as arriving_day, d2.arriving_time_number - d1.departing_time_number + (d2.arriving_day - d1.departing_day) * 1440 as travel_time
into temp11
from database1 as d1, database1 as d2, station as s1, station as s2, the_date as t
where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id
and d1.outer_station_id = s1.station_id and s1.city_name = '北京南'
and d2.outer_station_id = s2.station_id and s2.city_name = '南京'
and t.date_id = 3 - d1.departing_day;

select t.train_id, r.seat_type, min(r.tickets) as tickets, t.start_name, t.start_time, t.start_id, t.end_name, t.end_time, t.end_id, t.departing_day, t.arriving_day, t.travel_time
into temp12
from remaining_ticket as r, temp11 as t
where r.inner_station_id between t.start_id + 1 and t.end_id
and r.the_day = t.departing_day
and r.train_id = t.train_id and r.seat_type in (NULL, 'Soft_Seat', 'Hard_Up', 'Hard_Middle', 'Hard_Down', 'Soft_Up', 'Soft_Down') 
group by t.train_id, r.seat_type, t.start_name, t.start_time, t.start_id, t.end_name, t.end_time, t.end_id, t.departing_day, t.arriving_day, t.travel_time;

drop table temp11;
select *
into temp13
from temp12 as t
where t.tickets > 0;
drop table temp12;

select d2.actual_date as now, t.train_id, t.seat_type, t.tickets, t.start_name, t.start_time, t.start_id, t.end_name, t.end_time, t.end_id, d1.actual_date, p2.price - p1.price as price, t.travel_time
into temp14
from temp13 as t, the_date as d1, the_date as d2, possible_ticket as p1, possible_ticket as p2
where d1.date_id = t.arriving_day and d2.date_id = t.departing_day
and p1.inner_station_id = t.start_id and p2.inner_station_id = t.end_id
and p1.train_id = t.train_id and p2.train_id = t.train_id
and p1.seat_type = t.seat_type and p2.seat_type = t.seat_type;
drop table temp13;

select distinct t.now, train_id, t.start_name, t.start_time, t.end_name, t.end_time, t.actual_date, t.travel_time
into temp15
from temp14 as t;

alter table temp15 add Hard_Seat integer;
alter table temp15 add Hard_Seat_Price decimal(5,1);
update temp15
set Hard_Seat = t.tickets, Hard_Seat_Price = t.price 
from temp14 as t
where t.train_id = temp15.train_id
and t.seat_type = 'Hard_Seat';

alter table temp15 add Soft_Seat integer;
alter table temp15 add Soft_Seat_Price decimal(5,1);
update temp15
set Soft_Seat = t.tickets, Soft_Seat_Price = t.price
from temp14 as t
where t.train_id = temp15.train_id
and t.seat_type = 'Soft_Seat';

alter table temp15 add Hard_Up integer;
alter table temp15 add Hard_Up_Price decimal(5,1);
update temp15
set Hard_Up = t.tickets, Hard_Up_Price = t.price
from temp14 as t
where t.train_id = temp15.train_id
and t.seat_type = 'Hard_Up';

alter table temp15 add Hard_Middle integer;
alter table temp15 add Hard_Middle_Price decimal(5,1);
update temp15
set Hard_Middle = t.tickets, Hard_Middle_Price = t.price
from temp14 as t
where t.train_id = temp15.train_id
and t.seat_type = 'Hard_Middle';

alter table temp15 add Hard_Down integer;
alter table temp15 add Hard_Down_Price decimal(5,1);
update temp15
set Hard_Down = t.tickets, Hard_Down_Price = t.price
from temp14 as t
where t.train_id = temp15.train_id
and t.seat_type = 'Hard_Down';

alter table temp15 add Soft_Up integer;
alter table temp15 add Soft_Up_Price decimal(5,1);
update temp15
set Soft_Up = t.tickets, Soft_Up_Price = t.price 
from temp14 as t
where t.train_id = temp15.train_id
and t.seat_type = 'Soft_Up';

alter table temp15 add Soft_Down integer;
alter table temp15 add Soft_Down_Price decimal(5,1);
update temp15
set Soft_Down = t.tickets, Soft_Down_Price = t.price
from temp14 as t
where t.train_id = temp15.train_id
and t.seat_type = 'Soft_Down';
drop table temp14;

select * from temp15;
drop table temp15;
