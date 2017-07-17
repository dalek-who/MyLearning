-- 新建Train表
select distinct Train_ID into Train from Database1;

alter table Train
add primary key(Train_ID);

alter table Database1
add foreign key(Train_ID) references Train(Train_ID);

alter table Train
add Starting_Station_ID integer not NULL default 0;

update Train
set Starting_Station_ID = Database1.Outer_Station_ID
from
	Database1
where 
	Database1.Inner_Station_ID = 1 
	and Database1.Train_ID = Train.Train_ID;

alter table Train
add foreign key(Starting_Station_ID) references Station(Station_ID);

alter table Train
add Terminal_Station_ID integer not NULL default 0;

update Train
set Terminal_Station_ID = D1.Outer_Station_ID
from
	Database1 as D1
where D1.Train_ID = Train.Train_ID and D1.Inner_Station_ID = (
	select max(D2.Inner_Station_ID)
	from Database1 as D2
	where D2.Train_ID = D1.Train_ID);

alter table Train
add foreign key(Terminal_Station_ID) references Station(Station_ID);	

create table The_Date
(
  Date_ID               integer,
  Actual_Date           Date,
  primary key(Date_ID)
);
insert into The_Date(Date_ID,Actual_Date) values(1,'2016-11-18');
insert into The_Date(Date_ID,Actual_Date) values(2,'2016-11-19');
insert into The_Date(Date_ID,Actual_Date) values(3,'2016-11-20');
insert into The_Date(Date_ID,Actual_Date) values(4,'2016-11-21');
insert into The_Date(Date_ID,Actual_Date) values(5,'2016-11-22');
insert into The_Date(Date_ID,Actual_Date) values(6,'2016-11-23');
insert into The_Date(Date_ID,Actual_Date) values(7,'2016-11-24');
insert into The_Date(Date_ID,Actual_Date) values(8,'2016-11-25');
insert into The_Date(Date_ID,Actual_Date) values(9,'2016-11-26');
insert into The_Date(Date_ID,Actual_Date) values(10,'2016-11-27');
insert into The_Date(Date_ID,Actual_Date) values(11,'2016-11-28');
insert into The_Date(Date_ID,Actual_Date) values(12,'2016-11-29');
insert into The_Date(Date_ID,Actual_Date) values(13,'2016-11-30');
insert into The_Date(Date_ID,Actual_Date) values(14,'2016-12-01');
insert into The_Date(Date_ID,Actual_Date) values(15,'2016-12-02');
insert into The_Date(Date_ID,Actual_Date) values(16,'2016-12-03');
insert into The_Date(Date_ID,Actual_Date) values(17,'2016-12-04');
insert into The_Date(Date_ID,Actual_Date) values(18,'2016-12-05');
insert into The_Date(Date_ID,Actual_Date) values(19,'2016-12-06');
insert into The_Date(Date_ID,Actual_Date) values(20,'2016-12-07');
insert into The_Date(Date_ID,Actual_Date) values(21,'2016-12-08');
insert into The_Date(Date_ID,Actual_Date) values(22,'2016-12-09');
insert into The_Date(Date_ID,Actual_Date) values(23,'2016-12-10');
insert into The_Date(Date_ID,Actual_Date) values(24,'2016-12-11');
insert into The_Date(Date_ID,Actual_Date) values(25,'2016-12-12');
insert into The_Date(Date_ID,Actual_Date) values(26,'2016-12-13');
insert into The_Date(Date_ID,Actual_Date) values(27,'2016-12-14');
insert into The_Date(Date_ID,Actual_Date) values(28,'2016-12-15');
insert into The_Date(Date_ID,Actual_Date) values(29,'2016-12-16');
insert into The_Date(Date_ID,Actual_Date) values(30,'2016-12-17');
insert into The_Date(Date_ID,Actual_Date) values(31,'2016-12-18');
insert into The_Date(Date_ID,Actual_Date) values(32,'2016-12-19');

