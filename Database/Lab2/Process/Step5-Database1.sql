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
  Arriving_Time_Number      integer,
  Departing_Time_Number     integer,
  Outer_Station_ID          integer,
  Arriving_Day              integer,
  Departing_Day             integer,
  primary key(Train_ID,Inner_Station_ID),
  foreign key(Outer_Station_ID) references Station(Station_ID)
);

copy Database1 from '/home/dbms/Desktop/Stepx-Database1-2.csv' with (format csv, delimiter '|');
