select d1.inner_station_id as inner1, d2.inner_station_id as inner2, d1.train_id, min(r.tickets), r.the_day, r.seat_type into temp41 from station as s1, station as s2, database1 as d1, database1 as d2, remaining_ticket as r, the_date as td where s1.station_name = '北京南' and s2.station_name = '南京' and s1.station_id = d1.outer_station_id and s2.station_id = d2.outer_station_id and d1.train_id = d2.train_id and d1.train_id = 'D313' and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id and td.actual_date = cast('2016-11-22' as date) and r.train_id = d1.train_id and r.the_day + d1.departing_day = td.date_id and (td.actual_date > current_date or ( td.actual_date = current_date and d1.departing_time > current_time)) and r.seat_type = 'Hard_Seat' group by d1.inner_station_id, d2.inner_station_id, d1.train_id, r.tickets, r.the_day, r.seat_type;


alter table temp41 add price decimal(5,1); update temp41 set price = p2.price - p1.price + 5 from possible_ticket as p1, possible_ticket as p2 where temp41.train_id = p1.train_id and temp41.train_id = p2.train_id and temp41.inner1 = p1.inner_station_id and temp41.inner2 = p2.inner_station_id and temp41.seat_type = p1.seat_type and temp41.seat_type = p2.seat_type;

select * from temp41 where min > 0;

select * from client where national_id = '123453123456123456' and passward = '123456';

insert into order_table (order_id, train_id, national_id, departure_station_id, destination_station_id, price, seat_type, departure_time, departure_date, order_time) 
select 'xxxxx', t.train_id, '123453123456123456', t.inner1, t.inner2, t.price, t.seat_type, d.departing_time, td.actual_date, current_timestamp 
from temp41 as t, database1 as d, the_date as td, client as c
where t.train_id = d.train_id and t.inner1 = d.inner_station_id and td.date_id = t.the_day + d.departing_day and c.national_id = '123453123456123456'; 
