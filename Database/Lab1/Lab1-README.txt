--------------------------------------------------------------------------------
Install PostgreSQL Database
--------------------------------------------------------------------------------
0. install PostgreSQL 
  $ sudo apt-get install postgresql

  login PostgreSQL as postgres, which is default user
  $ sudo -u postgres psql

  add user 'dbms' as postgresql user
    postgres=# create user dbms with createdb createuser createrole login;
    postgres=# create database dbms owner dbms;
    postgres=# \q


1. service start|stop|restart
  $ sudo service postgresql start|stop|restart

2. run PostgreSQL shell command 
  $ psql
    psql (9.3.14)
    Type "help" for help.
    
    dbms=# 

  (tips) PostgreSQL command:
      \l	show databases
      \c db	use database db
      \dt	show tables
      \q	exit
    more command @ man psql 

3. postgresql directories:

  config /etc/postgresql/9.3/main
  data   /var/lib/postgresql/9.3/main


--------------------------------------------------------------------------------
TPCH: create database, create tables
--------------------------------------------------------------------------------
0. directory structure

  TPCH/tpch2.8.0.pdf      The TPCH specification document
  TPCH/tpch-gen           dbgen and qgen to generate data and queries

1. create database
  $ psql
  dbms=# create database tpch;
  CREATE DATABASE
  dbms=# \q

2. create tables in psql (See tpch 2.8.0 pdf pp13--16)
  $ psql -d tpch

  Then enter the following create table statements in psql:

create table region  (r_regionkey  integer primary key,
                      r_name       char(25) not null,
                      r_comment    varchar(152));

create table nation  (n_nationkey  integer primary key,
                      n_name       char(25) not null,
                      n_regionkey  integer not null,
                      n_comment    varchar(152),
                      foreign key (n_regionkey) references region(r_regionkey)
                      );

create table supplier (s_suppkey     integer primary key,
                       s_name        char(25) not null,
                       s_address     varchar(40) not null,
                       s_nationkey   integer not null,
                       s_phone       char(15) not null,
                       s_acctbal     decimal(15,2) not null,
                       s_comment     varchar(101),
                       foreign key (s_nationkey) references nation(n_nationkey)
                       );

create table customer (c_custkey     integer primary key,
                       c_name        varchar(25) not null,
                       c_address     varchar(40) not null,
                       c_nationkey   integer not null,
                       c_phone       char(15) not null,
                       c_acctbal     decimal(15,2)   not null,
                       c_mktsegment  char(10) not null,
                       c_comment     varchar(117),
                       foreign key (c_nationkey) references nation(n_nationkey)
                       );

Similary, please create tables of part, partsupp, orders, lineitem.


--------------------------------------------------------------------------------
TPCH: data gen, load data
--------------------------------------------------------------------------------
1. compile the source code in tpch-gen/

(1) modify/check the tpch-gen/Makefile 
       CC      = gcc   
       DATABASE= POSTGRESQL
       MACHINE = LINUX
       WORKLOAD = TPCH

(2) compile
     
     $ cd tpch-gen
     $ make 

    check if dbgen and qgen are generated.

2. use dbgen to generate random data for TPCH

(1) run dbgen

     $ mkdir data
     $ cd data
     $ cp ../dists.dss .
     $ ../dbgen -vfF -s 0.01

     Note: -s <scale factor> 
     when scale factor = 1, the generated data is 1GB.
     Here, we use scale factor = 0.01, so the generated data is 10MB.

(2) look at the generated data in data/*.tbl

e.g., 
     $ less region.tbl

0|AFRICA|lar deposits. blithely final packages cajole. regular waters are final requests. regular accounts are according to 
1|AMERICA|hs use ironic, even requests. s
2|ASIA|ges. thinly even pinto beans ca
3|EUROPE|ly final courts cajole furiously final excuse
4|MIDDLE EAST|uickly special accounts cajole carefully blithely close requests. carefully final asymptotes haggle furiousl

Every line is a record. Fields are separated with '|'.


3. import the generated data into postgresql tables

  $ psql -d tpch

  tpch=# copy region from '/home/dbms/Lab1/TPCH/tpch-gen/data/region.tbl' with (format csv, delimiter '|');
  tpch=# copy nation from '/home/dbms/Lab1/TPCH/tpch-gen/data/nation.tbl' with (format csv, delimiter '|');
  tpch=# copy supplier from '/home/dbms/Lab1/TPCH/tpch-gen/data/supplier.tbl' with (format csv, delimiter '|');
  tpch=# copy customer from '/home/dbms/Lab1/TPCH/tpch-gen/data/customer.tbl' with (format csv, delimiter '|');
  tpch=# copy part from '/home/dbms/Lab1/TPCH/tpch-gen/data/part.tbl' with (format csv, delimiter '|');
  tpch=# copy partsupp from '/home/dbms/Lab1/TPCH/tpch-gen/data/partsupp.tbl' with (format csv, delimiter '|');
  tpch=# copy orders from '/home/dbms/Lab1/TPCH/tpch-gen/data/orders.tbl' with (format csv, delimiter '|');
  tpch=# copy lineitem from '/home/dbms/Lab1/TPCH/tpch-gen/data/lineitem.tbl' with (format csv, delimiter '|');

  
--------------------------------------------------------------------------------
TPCH: generate queries and run queries
--------------------------------------------------------------------------------
1. use qgen to generate queries

qgen produces the queries on the console so we redirect the output to files

  $ mkdir pg-queries

  $ for q in `seq 1 22`; do
      DSS_QUERY=./queries ./qgen -d -s 0.01 $q > pg-queries/$q.sql
    done

2. fix query 1

  remove (3) from query 1

3. run a single query

  $ cd pg-queries
  $ psql -d tpch -f 1.sql

4. run all the queries
