drop table temp0;
select t.actual_date, 3 as date_id, d.train_id, d.inner_station_id, s.station_name, d.arriving_time, d.departing_time,
Hard_Seat_Price, Soft_Seat_Price, Hard_Sleeper_Up_Price, Hard_Sleeper_Middle_Price, Hard_Sleeper_Down_Price, Soft_Sleeper_Up_Price, Soft_Sleeper_Down_Price
into temp0
from the_date as t, station as s, database1 as d
where d.train_id = '1095'
and t.date_id + d.departing_day = 3
and s.station_id = d.outer_station_id;

update temp0
set actual_date = t.actual_date
from the_date as t
where t.date_id = temp0.date_id;

alter table temp0 add Hard_Seat integer;
update temp0
set Hard_Seat = r.tickets
from remaining_ticket as r
where r.train_id = temp0.train_id
and r.inner_station_id = temp0.inner_station_id
and r.inner_station_id > 1
and r.the_day = temp0.date_id
and r.seat_type = 'Hard_Seat';

alter table temp0 add Soft_Seat integer;
update temp0
set Soft_Seat = r.tickets
from remaining_ticket as r
where r.train_id = temp0.train_id
and r.inner_station_id = temp0.inner_station_id
and r.inner_station_id > 1
and r.the_day = temp0.date_id
and r.seat_type = 'Soft_Seat';

alter table temp0 add Hard_Up integer;
update temp0
set Hard_Up = r.tickets
from remaining_ticket as r
where r.train_id = temp0.train_id
and r.inner_station_id = temp0.inner_station_id
and r.inner_station_id > 1
and r.the_day = temp0.date_id
and r.seat_type = 'Hard_Up';

alter table temp0 add Hard_Middle integer;
update temp0
set Hard_Middle = r.tickets
from remaining_ticket as r
where r.train_id = temp0.train_id
and r.inner_station_id = temp0.inner_station_id
and r.inner_station_id > 1
and r.the_day = temp0.date_id
and r.seat_type = 'Hard_Middle';

alter table temp0 add Hard_Down integer;
update temp0
set Hard_Down = r.tickets
from remaining_ticket as r
where r.train_id = temp0.train_id
and r.inner_station_id = temp0.inner_station_id
and r.inner_station_id > 1
and r.the_day = temp0.date_id
and r.seat_type = 'Hard_Down';

alter table temp0 add Soft_Up integer;
update temp0
set Soft_Up = r.tickets
from remaining_ticket as r
where r.train_id = temp0.train_id
and r.inner_station_id = temp0.inner_station_id
and r.inner_station_id > 1
and r.the_day = temp0.date_id
and r.seat_type = 'Soft_Up';

alter table temp0 add Soft_Down integer;
update temp0
set Soft_Down = r.tickets
from remaining_ticket as r
where r.train_id = temp0.train_id
and r.inner_station_id = temp0.inner_station_id
and r.inner_station_id > 1
and r.the_day = temp0.date_id
and r.seat_type = 'Soft_Down';

update temp0
set Hard_Seat = NULL, Soft_Seat = NULL, Hard_Up = NULL, Hard_Middle = NULL, Hard_Down = NULL, Soft_Down = NULL, Soft_Up = NULL
where Inner_Station_ID = 1;

select actual_date, train_id, inner_station_id, station_name, departing_time, arriving_time, hard_seat,hard_seat_price, soft_seat, soft_seat_price, hard_up, hard_sleeper_up_price, hard_middle, hard_sleeper_middle_price, hard_down, hard_sleeper_down_price, soft_up,soft_sleeper_up_price, soft_down, soft_sleeper_down_price from temp0 order by inner_station_id;
