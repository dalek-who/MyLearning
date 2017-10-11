create table Possible_Ticket
(
  Train_ID              varchar(30) not NULL,
  Inner_Station_ID      integer not NULL,
  Seat_Type             varchar(20),
  Price                 decimal(5,1),
  primary key(Train_ID,Inner_Station_ID,Seat_Type)
);

insert into Possible_ticket(Train_ID, Inner_Station_ID, Seat_Type, Price)
select Train_ID, Inner_Station_ID, 'Hard_Seat', Hard_Seat_Price
from Database1
where Hard_Seat_Price is not NULL;

insert into Possible_ticket(Train_ID, Inner_Station_ID, Seat_Type, Price)
select Train_ID, Inner_Station_ID, 'Soft_Seat', Soft_Seat_Price
from Database1
where Soft_Seat_Price is not NULL;

insert into Possible_ticket(Train_ID, Inner_Station_ID, Seat_Type, Price)
select Train_ID, Inner_Station_ID, 'Hard_Up', Hard_Sleeper_Up_Price
from Database1
where Hard_Sleeper_Up_Price is not NULL;

insert into Possible_ticket(Train_ID, Inner_Station_ID, Seat_Type, Price)
select Train_ID, Inner_Station_ID, 'Hard_Middle', Hard_Sleeper_Middle_Price
from Database1
where Hard_Sleeper_Middle_Price is not NULL;

insert into Possible_ticket(Train_ID, Inner_Station_ID, Seat_Type, Price)
select Train_ID, Inner_Station_ID, 'Hard_Down', Hard_Sleeper_Down_Price
from Database1
where Hard_Sleeper_Down_Price is not NULL;

insert into Possible_ticket(Train_ID, Inner_Station_ID, Seat_Type, Price)
select Train_ID, Inner_Station_ID, 'Soft_Up', Soft_Sleeper_Up_Price
from Database1
where Soft_Sleeper_Up_Price is not NULL;

insert into Possible_ticket(Train_ID, Inner_Station_ID, Seat_Type, Price)
select Train_ID, Inner_Station_ID, 'Soft_Down', Soft_Sleeper_Down_Price
from Database1
where Soft_Sleeper_Down_Price is not NULL;
