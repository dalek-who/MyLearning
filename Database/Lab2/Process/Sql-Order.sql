select o.order_id, o.train_id, o.departure_date, o.departure_time, s1.station_name, s2.station_name, o.price, o.order_time
from order_table as o, station as s1, station as s2, database1 as d1, database1 as d2
where o.order_id = '20161122120949' and d1.train_id = o.train_id and d2.train_id = o.train_id and o.national_id = '330522199509063921'
and s1.station_id = d1.outer_station_id and d1.inner_station_id = o.departure_station_id and s2.station_id = d2.outer_station_id and d2.inner_station_id = o.destination_station_id;

select o.order_id, o.train_id, o.departure_date, o.departure_time, s1.station_name, s2.station_name, o.price
from order_table as o, station as s1, station as s2, database1 as d1, database1 as d2, the_date as td1, the_date as td2, the_date as td
where o.departure_date = td.actual_date and td1.actual_date = '2016-11-18' and td2.actual_date = '2016-11-30' and td.date_id between td1.date_id and td2.date_id and o.national_id = '330522199509063921' and d1.train_id = o.train_id and d2.train_id = o.train_id 
and s1.station_id = d1.outer_station_id and d1.inner_station_id = o.departure_station_id and s2.station_id = d2.outer_station_id and d2.inner_station_id = o.destination_station_id;
