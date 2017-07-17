drop table Database1;
create table Database1
(
  Train_Type                char,
  Train_ID                  varchar(30) not NULL,
  Inner_Station_ID          integer not NULL,
  Station_Name              varchar(32) not NULL,
  Arriving_Time             time,
  Departing_Time            time,
  Stay_Minute               integer,
  Spend_Minute              integer,
  Distance                  integer,
  Hard_Seat_Price           decimal(5,1),
  Soft_Seat_Price           decimal(5,1),
  Hard_Sleeper_Up_Price     decimal(5,1),
  Hard_Sleeper_Middle_Price decimal(5,1),
  Hard_Sleeper_Down_Price   decimal(5,1),
  Soft_Sleeper_Up_Price     decimal(5,1),
  Soft_Sleeper_Down_Price   decimal(5,1),
  primary key(Train_ID,Inner_Station_ID)
);

copy Database1 from '/home/dbms/Desktop/Stepx-all_data.csv' with (format csv, delimiter ',');

--计算时间
update Database1 set Arriving_Time = '00:00:00' where Arriving_Time is NULL;
alter table Database1 add Arriving_Minute integer;
update Database1
set Arriving_Minute = date_part('hour',Arriving_Time)*60 + date_part('minute',Arriving_Time);

update Database1 set Departing_Time = '00:00:00' where Departing_Time is NULL;
alter table Database1 add Departing_Minute integer;
update Database1
set Departing_Minute = date_part('hour',Departing_Time)*60 + date_part('minute',Departing_Time);

--处理成所需数据
update Database1 set Hard_Seat_Price = NULL where Hard_Seat_Price = 0;
update Database1 set Soft_Seat_Price = NULL where Soft_Seat_Price = 0;
update Database1 set Hard_Sleeper_Up_Price = NULL where Hard_Sleeper_Up_Price = 0;
update Database1 set Hard_Sleeper_Middle_Price = NULL where Hard_Sleeper_Middle_Price = 0;
update Database1 set Hard_Sleeper_Down_Price = NULL where Hard_Sleeper_Down_Price = 0;
update Database1 set Soft_Sleeper_Up_Price = NULL where Soft_Sleeper_Up_Price = 0;
update Database1 set Soft_Sleeper_Down_Price = NULL where Soft_Sleeper_Down_Price = 0;

update Database1 
set Hard_Sleeper_Up_Price = 0, Hard_Sleeper_Down_Price = 0, Hard_SLeeper_Middle_Price = 0, Soft_Sleeper_Down_Price = 0, Soft_Sleeper_Up_Price = 0, Hard_Seat_Price = 0, Soft_Seat_Price = 0 
where Inner_Station_ID = 1;

--增加外键链接Station_ID
alter table Database1 add Outer_Station_ID integer;

alter table Database1 
add foreign key(Outer_Station_ID) references Station(Station_ID);

update Database1
set Outer_Station_ID = Station.Station_ID
from Station
where Database1.Station_Name = Station.Station_Name;

