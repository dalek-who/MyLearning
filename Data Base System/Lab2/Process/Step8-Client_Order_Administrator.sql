create table Client
(
    National_ID char(18),
    Passward    varchar(18),
    Name        varchar(10),
    Phone       char(10),
    Bank        varchar(10),
    Credit_Card char(16),
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
  Order_ID                  varchar(100),
  Train_ID                  varchar(30),
  National_ID               varchar(18),
  Departure_Station_ID      integer,
  Destination_Station_ID    integer,
  Price                     decimal(8,1),
  Seat_Type                 varchar(20),
  Departure_Time            varchar(10),
  Departure_Date            date,
  Order_Time                timestamp,
  foreign key(Train_ID) references Train(Train_ID),
  foreign key(Departure_Station_ID) references Station(Station_ID),
  foreign key(Destination_Station_ID) references Station(Station_ID),
  foreign key(National_ID) references Client(National_ID)
);

insert into Administrator(Account, Passward)
values('12','12');
