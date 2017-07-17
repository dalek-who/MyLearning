drop table Administrator;
drop table Order_Table;
drop table Client;
drop table Database1;
drop table Possible_Ticket;
drop table Remaining_Ticket;
drop table Train;
drop table Station;
drop table The_Date;
create table Station
(
  Station_Name 		    varchar(32),
  City_Name 		    varchar(32),
  Station_ID 		    integer not NULL,
  primary key(Station_ID)
);
create table Train
(
  Train_ID		    varchar(30) not NULL,
  Starting_Station_ID	    integer not NULL,
  Terminal_Station_ID	    integer not NULL,
  primary key(Train_ID),
  foreign key(Starting_Station_ID) references Station(Station_ID),
  foreign key(Terminal_Station_ID) references Station(Station_ID)
);
create table Database1
(
  Train_Type                char,
  Train_ID                  varchar(30) not NULL,
  Inner_Station_ID	    integer not NULL,
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
  Arriving_Time_Number      integer,
  Departing_Time_Number     integer,
  Outer_Station_ID          integer,
  Arriving_Day	       	    integer,
  Departing_Day		    integer,
  primary key(Train_ID,Inner_Station_ID),
  foreign key(Train_ID) references Train(Train_ID),
  foreign key(Outer_Station_ID) references Station(Station_ID)
);
create table The_Date
(
  Date_ID               integer not NULL,
  Actual_Date           Date,
  primary key(Date_ID)
);
create table Remaining_Ticket
(
  Train_ID              varchar(30) not NULL,
  Inner_Station_ID      integer not NULL,
  Seat_Type             varchar(20),
  The_Day               integer,
  Tickets               integer,
  primary key(Train_ID,Inner_Station_ID,Seat_Type,The_Day),
  foreign key(The_Day) references The_Date(Date_ID),
  foreign key(Train_ID) references Train(Train_ID)
);
create table Possible_Ticket
(
  Train_ID              varchar(30) not NULL,
  Inner_Station_ID      integer not NULL,
  Seat_Type             varchar(20),
  Price                 decimal(5,1),
  primary key(Train_ID,Inner_Station_ID,Seat_Type)
);
create table Client
(
    National_ID char(18) not NULL,
    Passward    varchar(18) not NULL,
    Name        varchar(18) not NULL,
    Phone       char(10) not NULL,
    Bank        varchar(18) not NULL,
    Credit_Card char(16) not NULL,
    primary key(National_ID)
);
create table Administrator
(
    Account	varchar(18),
    Passward    varchar(18),
    primary key(Account)
);
create table Order_Table
(
  Order_ID                  varchar(20) not NULL,
  Train_ID                  varchar(30) not NULL,
  National_ID               char(18) not NULL,
  Departure_Station_ID      integer not NULL,
  Destination_Station_ID    integer not NULL,
  Price                     decimal(8,1) not NULL,
  Seat_Type                 varchar(20) not NULL,
  Departure_Time            varchar(10) not NULL,
  Departure_Date            date not NULL,
  Order_Time                timestamp not NULL,
  primary key(Order_ID,Train_ID,National_ID),
  foreign key(Train_ID) references Train(Train_ID),
  foreign key(Departure_Station_ID) references Station(Station_ID),
  foreign key(Destination_Station_ID) references Station(Station_ID),
  foreign key(National_ID) references Client(National_ID)
);

--路径记得自己改一下,默认在桌面上.
copy Station from '/home/kj/桌面/Final-Station.csv' with (format csv, delimiter '|');
copy Train from '/home/kj/桌面/Final-Train.csv' with (format csv, delimiter '|');
copy Database1 from '/home/kj/桌面/Final-Database1.csv' with (format csv, delimiter '|');
copy Order_Table from '/home/kj/桌面/Final-Order_Table.csv' with (format csv, delimiter '|');
copy The_Date from '/home/kj/桌面/Final-The_Date.csv' with (format csv, delimiter '|');
copy Possible_Ticket from '/home/kj/桌面/Final-Possible_Ticket.csv' with (format csv, delimiter '|');
insert into Administrator(Account, Passward) values('12','12');
--根据需要天数增加/减少注释.
copy Remaining_Ticket from '/home/kj/桌面/Final-Remaining_Ticket1-16.csv' with (format csv, delimiter '|');
copy Remaining_Ticket from '/home/kj/桌面/Final-Remaining_Ticket17-32.csv' with (format csv, delimiter '|');

alter table database1 drop Hard_Seat_Price;
alter table database1 drop Soft_Seat_Price;
alter table database1 drop Hard_Sleeper_Up_Price;
alter table database1 drop Hard_Sleeper_Middle_Price;
alter table database1 drop Hard_Sleeper_Down_Price;
alter table database1 drop Soft_Sleeper_Up_Price;
alter table database1 drop Soft_Sleeper_Down_Price;

create index st1 on possible_ticket(seat_type);
create index st2 on remaining_ticket(seat_type);
create index price on possible_ticket(price);
create index day1 on remaining_ticket(the_day);
create index t1 on remaining_ticket(train_id);
create index t2 on possible_ticket(train_id);
create index t3 on database1(train_id);
create index in1 on remaining_ticket(inner_station_id);
create index in2 on possible_ticket(inner_station_id);
create index in3 on database1(inner_station_id);
create index s1 on station(station_id);
create index c1 on station(city_name);
create index o1 on database1(outer_station_id);
create index d1 on database1(departing_day);
create index d2 on database1(departing_time_number);
create index a1 on database1(arriving_day);
create index ax on database1(arriving_time_number);

