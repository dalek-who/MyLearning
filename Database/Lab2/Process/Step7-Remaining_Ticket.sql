drop table Remaining_Ticket;
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

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, 'Hard_Seat', 1, 5
from Database1
where Hard_Seat_Price is not NULL;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, 'Soft_Seat', 1, 5
from Database1
where Soft_Seat_Price is not NULL;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, 'Hard_Up', 1, 5
from Database1
where Hard_Sleeper_Up_Price is not NULL;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, 'Hard_Middle', 1, 5
from Database1
where Hard_Sleeper_Middle_Price is not NULL;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, 'Hard_Down', 1, 5
from Database1
where Hard_Sleeper_Down_Price is not NULL;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, 'Soft_Up', 1, 5
from Database1
where Soft_Sleeper_Up_Price is not NULL;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, 'Soft_Down', 1, 5
from Database1
where Soft_Sleeper_Down_Price is not NULL;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, Seat_Type, The_Day + 1, Tickets
from Remaining_Ticket;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, Seat_Type, The_Day + 2, Tickets
from Remaining_Ticket;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, Seat_Type, The_Day + 4, Tickets
from Remaining_Ticket;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, Seat_Type, The_Day + 8, Tickets
from Remaining_Ticket;

insert into Remaining_Ticket(Train_ID, Inner_Station_ID, Seat_Type, The_Day, Tickets)
select Train_ID, Inner_Station_ID, Seat_Type, The_Day + 16, Tickets
from Remaining_Ticket;

update Remaining_Ticket
set Tickets = 0
where Inner_Station_ID = 1;
