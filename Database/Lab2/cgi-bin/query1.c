#include "stdio.h"
#include "stdlib.h"
#define BURSIZE 1024
#include <string.h>
#include <time.h>
#include <postgresql/libpq-fe.h>
#include <arpa/inet.h> 
void urldecode(char *url);
void urlencode(char *url);
int hex2dec(char c);
char dec2hex(short int c);
int main() {
	time_t t_start, t_end;
	t_start = time(NULL) ;

	int r, num_rows, num_cols;
	int num_rows1, num_cols1;
	int i;
	char *val;
	char *val1, *val2, *val3, *val4, *val5, *val6, *val7, *val8, *val9, *val10, *val11, *val12;
	PGconn* conn = PQconnectdb("dbname=train");
	char *data;
	data = getenv("QUERY_STRING");
	printf("Content-type:text/html\n\n");
	printf("<html> <head> <meta charset=\"UTF-8\"> <meta http-equiv=\"Content-Type\" content=\"text/html"";"" charset=UTF-8\"> <meta name=\"renderer\" content=\"webkit\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Home</title> <style type='text/css'> #top_title, #sideMenu { display: none"";"" } #content { width: 100%%"";"" margin: 0"";"" padding: 0"";"" } </style> <!--jQuery--> <script src=\"../jquery_min.js\"></script> <!--bootstrap--> <link href=\"../bootstrap_min.css\" rel=\"stylesheet\"> <script src=\"../bootstrap_min.js\"></script> <!--customer--> <link href=\"../nav.css\" rel=\"stylesheet\"> <link href=\"../customer.css\" rel=\"stylesheet\"> </head><body><div class=\"container-fluid\" style=\"background-color: black\"><p style=\"float: left"";"" font-size: 30px"";"" height: 40px"";"" color: #cccccc\">1 2 3 0 6</p>\n");
	urldecode(data);
	int p, q, n;
	char value[14][32];
	p = 0;
	for (q = 0; q < 14; q++)
	{
		while (data[p] != '=')
			p++;
		p++; n = 0;
		while (data[p] != '&')
		{
			value[q][n] = data[p];
			p++; n++;
		}
		value[q][n] = '\0';
	}
	int   param_lenx[2] = { 0 };
	int   param_formatx[2] = { 0 };
	const Oid paramTypesx[2] = { 1043,1043 };
	PGresult *Qx = PQprepare(conn, "check", "select * from client where national_id = $1 and passward = $2;", 2, paramTypesx);
	char *param_valx[2] = { value[12], value[13] };
	Qx = PQexecPrepared(conn, "check", 2, (const char **)param_valx, param_lenx, param_formatx, 0);
	int num_rowsx = PQntuples(Qx);
	if (num_rowsx) printf(" <nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\">  <ul>  <li><a href=\"index.cgi?身份证=%s&密码=%s\">主页</a></li>  <li><a href=\"train.cgi?身份证=%s&密码=%s\">查车</a></li>  <li><a href=\"ticket.cgi?身份证=%s&密码=%s\">查票</a></li>  <li><a href=\"booking.cgi?身份证=%s&密码=%s\">预定</a></li>  <li><a href=\"../index.html\">登出</a></li>  <li><a href=\"order.cgi?身份证=%s&密码=%s\">订单</a></li>  <li><a href=\"administrator.cgi?身份证=%s&密码=%s\">管理员</a></li>  </ul>  </nav>  </div>\n <div class=\"container home-content\" style=\"background-color: white\">  <div class=\"row\" style=\"text-align: center\"><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n", value[12], value[13], value[12], value[13], value[12], value[13], value[12], value[13], value[12], value[13], value[12], value[13]);
	else printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li>  <li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");
	printf("<p> <form method=\"get\" action=\"/cgi-bin/query1.cgi\"> <b>出发地 :</b> <input type=\"text\" name=\"站名\" value=\"%s\"> <b>目的地 :</b> <input type=\"text\" name=\"站名\" value=\"%s\">", value[0], value[1]);

	printf("<b>日期 :</b> <select name=\"3\"> <option value=\"0\">明天<option value=\"6\">2016-11-23 <option value=\"7\">2016-11-24 <option value=\"8\">2016-11-25 <option value=\"9\">2016-11-26 <option value=\"10\">2016-11-27 <option value=\"11\">2016-11-28 <option value=\"12\">2016-11-29 <option value=\"13\">2016-11-30 <option value=\"14\">2016-12-01 <option value=\"15\">2016-12-02 <option value=\"16\">2016-12-03 <option value=\"17\">2016-12-04 <option value=\"18\">2016-12-05 <option value=\"19\">2016-12-06 <option value=\"20\">2016-12-07 <option value=\"21\">2016-12-08 <option value=\"22\">2016-12-09 <option value=\"23\">2016-12-10 <option value=\"24\">2016-12-11 <option value=\"25\">2016-12-12 <option value=\"26\">2016-12-13 <option value=\"27\">2016-12-14 <option value=\"28\">2016-12-15 <option value=\"29\">2016-12-16 <option value=\"30\">2016-12-17 <option value=\"31\">2016-12-18 <option value=\"32\">2016-12-19 </select><b></p>");
	int k2 = atoi(value[3]);//票价排序方式
	int k3 = atoi(value[8]);//直达
	int k4 = atoi(value[9]);//转乘一次
	int k5 = atoi(value[10]);//转乘两次
	int s1 = atoi(value[4]);//硬座
	int s2 = atoi(value[5]);//软座
	int s3 = atoi(value[6]);//硬卧
	int s4 = atoi(value[7]);//软卧
	if (k2 == 1) printf("<p> <b>排序:</b> 票价<input type=\"radio\" name=\"4\" value=\"1\" checked=\"checked\"> 行程时间<input type=\"radio\" name=\"4\" value=\"2\"> 起始时间<input type=\"radio\" name=\"4\" value=\"3\"> &nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";");
	else if (k2 == 2) printf("<p> <b>排序:</b> 票价<input type=\"radio\" name=\"4\" value=\"1\" > 行程时间<input type=\"radio\" name=\"4\" value=\"2\" checked=\"checked\"> 起始时间<input type=\"radio\" name=\"4\" value=\"3\"> &nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";");
	else if (k2 == 3) printf("<p> <b>排序:</b> 票价<input type=\"radio\" name=\"4\" value=\"1\" > 行程时间<input type=\"radio\" name=\"4\" value=\"2\" > 起始时间<input type=\"radio\" name=\"4\" value=\"3\" checked=\"checked\"> &nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";");

	if (s1) printf("<b>座位类型</b>&nbsp"";"" 硬座<input type=\"radio\" name=\"5\" value=\"1\" checked=\"checked\">是 <input type=\"radio\" name=\"5\" value=\"0\">否&nbsp"";""&nbsp"";""&nbsp"";");
	else printf("<b>座位类型</b>&nbsp"";"" 硬座<input type=\"radio\" name=\"5\" value=\"1\">是 <input type=\"radio\" name=\"5\" value=\"0\" checked=\"checked\">否&nbsp"";""&nbsp"";""&nbsp"";");
	if (s2) printf("软座<input type=\"radio\" name=\"6\" value=\"1\" checked=\"checked\">是 <input type=\"radio\" name=\"6\" value=\"0\">否&nbsp"";""&nbsp"";""&nbsp"";");
	else printf("软座<input type=\"radio\" name=\"6\" value=\"1\">是 <input type=\"radio\" name=\"6\" value=\"0\" checked=\"checked\">否&nbsp"";""&nbsp"";""&nbsp"";");
	if (s3) printf("硬卧<input type=\"radio\" name=\"7\" value=\"1\" checked=\"checked\">是 <input type=\"radio\" name=\"7\" value=\"0\">否&nbsp"";""&nbsp"";""&nbsp"";");
	else printf("硬卧<input type=\"radio\" name=\"7\" value=\"1\">是 <input type=\"radio\" name=\"6\" value=\"0\" checked=\"checked\">否&nbsp"";""&nbsp"";""&nbsp"";");
	if (s4) printf("软卧<input type=\"radio\" name=\"8\" value=\"1\" checked=\"checked\">是 <input type=\"radio\" name=\"8\" value=\"0\">否&nbsp"";""&nbsp"";""&nbsp"";");
	else printf("软卧<input type=\"radio\" name=\"8\" value=\"1\">是 <input type=\"radio\" name=\"8\" value=\"0\" checked=\"checked\">否&nbsp"";""&nbsp"";""&nbsp"";");
	if (k3) printf("</p><p> <b>乘车情况</b> 直达<input type=\"radio\" name=\"9\" value=\"1\" checked=\"checked\">是 <input type=\"radio\" name=\"9\" value=\"0\">否&nbsp"";""&nbsp"";""&nbsp"";");
	else printf("</p><p> <b>乘车情况</b> 直达<input type=\"radio\" name=\"9\" value=\"1\" >是 <input type=\"radio\" name=\"9\" value=\"0\" checked=\"checked\">否&nbsp"";""&nbsp"";""&nbsp"";");
	if (k4) printf("转乘一次<input type=\"radio\" name=\"10\" value=\"1\" checked=\"checked\">是 <input type=\"radio\" name=\"10\" value=\"0\">否&nbsp"";""&nbsp"";""&nbsp"";");
	else printf("转乘一次<input type=\"radio\" name=\"10\" value=\"1\" >是 <input type=\"radio\" name=\"10\" value=\"0\" checked=\"checked\">否&nbsp"";""&nbsp"";""&nbsp"";");
	if (k5) printf("转乘两次直达<input type=\"radio\" name=\"11\" value=\"1\" checked=\"checked\">是 <input type=\"radio\" name=\"11\" value=\"0\">否&nbsp"";""&nbsp"";""&nbsp"";");
	else printf("转乘两次<input type=\"radio\" name=\"11\" value=\"1\" >是 <input type=\"radio\" name=\"11\" value=\"0\" checked=\"checked\">否&nbsp"";""&nbsp"";""&nbsp"";");
	printf("&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";"" ");
	if (atoi(value[11]) > 0) printf("<b>返程日期 :</b> <select name=\"3\"> <option value=\"%d\">是<option value=\"0\">否", atoi(value[11]));
	else printf("<b>返程日期 :</b> <select name=\"3\"> <option value=\"0\">否");
	printf("<option value=\"1\">2016-11-18 <option value=\"2\">2016-11-19 <option value=\"3\">2016-11-20 <option value=\"4\">2016-11-21 <option value=\"5\">2016-11-22 <option value=\"6\">2016-11-23 <option value=\"7\">2016-11-24 <option value=\"8\">2016-11-25 <option value=\"9\">2016-11-26 <option value=\"10\">2016-11-27 <option value=\"11\">2016-11-28 <option value=\"12\">2016-11-29 <option value=\"13\">2016-11-30 <option value=\"14\">2016-12-01 <option value=\"15\">2016-12-02 <option value=\"16\">2016-12-03 <option value=\"17\">2016-12-04 <option value=\"18\">2016-12-05 <option value=\"19\">2016-12-06 <option value=\"20\">2016-12-07 <option value=\"21\">2016-12-08 <option value=\"22\">2016-12-09 <option value=\"23\">2016-12-10 <option value=\"24\">2016-12-11 <option value=\"25\">2016-12-12 <option value=\"26\">2016-12-13 <option value=\"27\">2016-12-14 <option value=\"28\">2016-12-15 <option value=\"29\">2016-12-16 <option value=\"30\">2016-12-17 <option value=\"31\">2016-12-18 <option value=\"32\">2016-12-19 </select> &nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";""&nbsp"";"" ");
	printf("<input type=\"hidden\" name=\"身份证\" value=\"%s\"><input type=\"hidden\" name=\"密码\" value=\"%s\"><input type=\"submit\" value=\"查询\"> </form>", value[12], value[13]);

	int m = atoi(value[2]);//日期
	time_t timep;
	struct tm *px;
	time(&timep);
	px = gmtime(&timep);
	if (m == 0) m = px->tm_mday - 16;
	int k1 = (int)ntohl(m);
	int k1_0 = m;

	m = atoi(value[11]);//返程日期
	int f;
	if (m == 0)
		f = 0;//不需要返程
	else
		f = 1;//需要返程
	if (m<k1_0&&f!=0)
	{
		printf("你逗我吗？ 返程日期比去程还早！！！ 就很气！！！ 很无奈，先帮你查个去程好了，摊手……\n ——崩溃的前后端渣渣均分boy<br/>\n");
		f = 0;
	}
	else if(m==k1_0&&f&&k4&&k5)
	{
		printf("Sorry! 如果需要查询非直达当天返程，需要自行组合！\n ——崩溃的前后端渣渣均分boy<br/>\n");
	}
	int k6 = (int)ntohl(m);//返程日期
	char *seat0, *seat1, *seat2, *seat3, *seat4, *seat5;
	char *seath, *seats;
	if (s1) seath = "Hard_Seat"; else seath = NULL; if (s2) seats = "Soft_Seat"; else seats = NULL;
	if (s3) { seat1 = "Hard_Up"; seat2 = "Hard_Middle"; seat3 = "Hard_Down"; }
	else { seat1 = NULL; seat2 = NULL; seat3 = NULL; }
	if (s4) { seat4 = "Soft_Up"; seat5 = "Soft_Down"; }
	else { seat4 = NULL; seat5 = NULL; }
	printf("<p>");

	if (!k3 && !k4 && !k5)
	{
		printf("你逗我吗？ 一种转车方式都不选！！！ 就很气！！！ 很无奈，帮你选个直达好了，摊手……\n ——崩溃的前后端渣渣均分boy<br/>\n");
		k3 = 1;
		k4 = 0;
		k5 = 0;
	}

	if (!s1 && !s2 && !s3 && !s4)
	{
		printf("你逗我吗？ 一种座位类型都不选！！！ 就很气！！！ 很无奈，帮你选个硬座好了，摊手……\n ——崩溃的前后端渣渣均分boy<br/>\n");
		s1 = 1;
	}

	PQexec(conn, "drop table temp11"); PQexec(conn, "drop table temp111");
	PQexec(conn, "drop table temp12"); PQexec(conn, "drop table temp121");
	PQexec(conn, "drop table temp13"); PQexec(conn, "drop table temp131");
	PQexec(conn, "drop table temp14"); PQexec(conn, "drop table temp141");
	PQexec(conn, "drop table temp15"); PQexec(conn, "drop table temp151"); PQexec(conn, "drop table temp16");
	PQexec(conn, "drop table temp21"); PQexec(conn, "drop table temp211");
	PQexec(conn, "drop table temp22"); PQexec(conn, "drop table temp221");
	PQexec(conn, "drop table temp23"); PQexec(conn, "drop table temp231");
	PQexec(conn, "drop table temp24"); PQexec(conn, "drop table temp241");
	PQexec(conn, "drop table temp25"); PQexec(conn, "drop table temp251");
	PQexec(conn, "drop table temp31"); PQexec(conn, "drop table temp311");
	PQexec(conn, "drop table temp32"); PQexec(conn, "drop table temp321");
	PQexec(conn, "drop table temp33"); PQexec(conn, "drop table temp331");
	PQexec(conn, "drop table temp34"); PQexec(conn, "drop table temp341");
	PQexec(conn,"drop table temp35"); PQexec(conn,"drop table temp351");

	const Oid paramTypes1[3] = { 1043,1043,23 };
	PQprepare(conn, "Query_One1", "select d1.train_id as train_id, s1.station_name as start_name, d1.departing_time as start_time, d1.inner_station_id as start_id, s2.station_name as end_name, d2.arriving_time as end_time, d2.inner_station_id as end_id, t.date_id as train_departing_day, t.date_id + d2.arriving_day as arriving_day, d2.arriving_time_number - d1.departing_time_number + (d2.arriving_day - d1.departing_day) * 1440 as travel_time, $3 as departing_day into temp11 from database1 as d1, database1 as d2, station as s1, station as s2, the_date as t where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = $2 and t.date_id = $3 - d1.departing_day;", 3, paramTypes1);
	char *param_val1_0[3] = { value[1], value[0],(char *)&k6 };
	char *param_val1[3] = { value[0], value[1],(char *)&k1 };
	int   param_len1[3] = { 0,0,4 };
	int   param_format1[3] = {0,0,1};


	PQexecPrepared(conn, "Query_One1", 3, (const char **)param_val1, param_len1, param_format1, 0);
	const Oid paramTypes2[7] = { 1043,1043,1043,1043,1043,1043,1043 };
	PQprepare(conn, "Query_One2", "select t.train_id, p1.seat_type as seat_type, t.start_name, t.start_time, t.start_id, t.end_name, t.end_time, t.end_id, t.train_departing_day, t.arriving_day, t.departing_day, t.travel_time, p2.price - p1.price as price into temp12 from temp11 as t, possible_ticket as p1, possible_ticket as p2 where p1.inner_station_id = t.start_id and p2.inner_station_id = t.end_id and p1.train_id = t.train_id and p2.train_id = t.train_id and p1.seat_type = p2.seat_type and p1.seat_type in ($1,$2,$3,$4,$5,$6,$7);", 7, paramTypes2);

	char *param_val2[7] = { seath, seats, seat1, seat2, seat3, seat4, seat5 };
	int   param_len2[7] = { 0 };
	int   param_format2[7] = { 0 };
	PQexecPrepared(conn, "Query_One2", 7, (const char **)param_val2, param_len2, param_format2, 0);

	PQexec(conn, "drop table temp11");
	PQexec(conn, "select t.train_id, t.seat_type, min(r.tickets) as tickets, t.start_name, t.start_time,t.end_name, t.end_time, t.departing_day, t.arriving_day, t.travel_time,t.price into temp13 from remaining_ticket as r, temp12 as t where r.inner_station_id between t.start_id + 1 and t.end_id and r.the_day = t.train_departing_day and r.train_id = t.train_id and r.seat_type =  t.seat_type group by t.train_id,t.seat_type,t.start_name,t.start_time,t.end_name,t.end_time,t.departing_day,t.arriving_day,t.travel_time,t.price; drop table temp12; delete from temp13 where tickets <=0;");

	if (!k3)
	{
		if (f){
			goto miss0_1;
		}
		else{
			goto miss1;
		}
	}

	PQexec(conn, "select t.train_id,t.seat_type,t.tickets,t.start_name,t.start_time,t.end_name,t.end_time,d1.actual_date as departing_date, d2.actual_date as arriving_date,t.travel_time,t.price into temp14 from temp13 as t, the_date as d1, the_date as d2 where d1.date_id = t.departing_day and d2.date_id = t.arriving_day; select distinct  t.train_id,t.departing_date, t.start_name, t.start_time,  t.arriving_date,t.end_name, t.end_time, t.travel_time into temp15 from temp14 as t; alter table temp15 add Min_Price decimal(5,1) default 9999.9;");

	if (s1) PQexec(conn, "alter table temp15 add Hard_Seat integer; alter table temp15 add Hard_Seat_Price decimal(5,1); update temp15 set Hard_Seat = t.tickets, Hard_Seat_Price = t.price from temp14 as t where t.train_id = temp15.train_id and t.start_name = temp15.start_name and t.end_name = temp15.end_name and t.seat_type = 'Hard_Seat'; update temp15 set Min_Price = Hard_Seat_Price where Min_Price > Hard_Seat_Price;");

	if (s2) PQexec(conn, "alter table temp15 add Soft_Seat integer; alter table temp15 add Soft_Seat_Price decimal(5,1); update temp15 set Soft_Seat = t.tickets, Soft_Seat_Price = t.price from temp14 as t where t.train_id = temp15.train_id and t.start_name = temp15.start_name and t.end_name = temp15.end_name and t.seat_type = 'Soft_Seat'; update temp15 set Min_Price = Soft_Seat_Price where Min_Price > Soft_Seat_Price;");

	if (s3) PQexec(conn, "alter table temp15 add Hard_Up integer; alter table temp15 add Hard_Up_Price decimal(5,1); update temp15 set Hard_Up = t.tickets, Hard_Up_Price = t.price from temp14 as t where t.train_id = temp15.train_id and t.start_name = temp15.start_name and t.end_name = temp15.end_name and t.seat_type = 'Hard_Up'; update temp15 set Min_Price = Hard_Up_Price where Min_Price > Hard_Up_Price; alter table temp15 add Hard_Middle integer; alter table temp15 add Hard_Middle_Price decimal(5,1); update temp15 set Hard_Middle = t.tickets, Hard_Middle_Price = t.price from temp14 as t where t.train_id = temp15.train_id and t.start_name = temp15.start_name and t.end_name = temp15.end_name and t.seat_type = 'Hard_Middle'; update temp15 set Min_Price = Hard_Middle_Price where Min_Price > Hard_Middle_Price; alter table temp15 add Hard_Down integer; alter table temp15 add Hard_Down_Price decimal(5,1); update temp15 set Hard_Down = t.tickets, Hard_Down_Price = t.price from temp14 as t where t.train_id = temp15.train_id and t.start_name = temp15.start_name and t.end_name = temp15.end_name and t.seat_type = 'Hard_Down';");

	if (s4) PQexec(conn, "update temp15 set Min_Price = Hard_Down_Price where Min_Price > Hard_Down_Price; alter table temp15 add Soft_Up integer; alter table temp15 add Soft_Up_Price decimal(5,1); update temp15 set Soft_Up = t.tickets, Soft_Up_Price = t.price from temp14 as t where t.train_id = temp15.train_id and t.start_name = temp15.start_name and t.end_name = temp15.end_name and t.seat_type = 'Soft_Up'; update temp15 set Min_Price = Soft_Up_Price where Min_Price > Soft_Up_Price; alter table temp15 add Soft_Down integer; alter table temp15 add Soft_Down_Price decimal(5,1); update temp15 set Soft_Down = t.tickets, Soft_Down_Price = t.price from temp14 as t where t.train_id = temp15.train_id and t.start_name = temp15.start_name and t.end_name = temp15.end_name and t.seat_type = 'Soft_Down'; update temp15 set Min_Price = Soft_Down_Price where Min_Price > Soft_Down_Price;");


	PQexec(conn, "drop table temp14;");
	if (f) goto miss0_1;
	PGresult *Q14, *Q141;

	if (k2 == 1)
		Q14 = PQexec(conn, "select * from temp15 order by Min_Price;");
	else if (k2 == 2)
		Q14 = PQexec(conn, "select * from temp15 order by travel_time;");
	else if (k2 == 3)
		Q14 = PQexec(conn, "select * from temp15 order by start_time;");

	num_rows = PQntuples(Q14);
	if (num_rows == 0) printf("非法输入,请再次尝试 或 直达搜索无结果\n");
	num_cols = PQnfields(Q14);

	printf("<p align=\"center\" style=\"font-size:18px\">");
	if(f && k3) printf("<a href=\"#11\">往返程-直达</a>&nbsp&nbsp&nbsp");
	else if (k3) printf("<a href=\"#1\">直达</a>&nbsp&nbsp&nbsp");
	if (k4) printf("<a href=\"#2\">去程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (f && k4) printf("<a href=\"#21\">返程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (k5) printf("<a href=\"#3\">去程-转乘二次</a>&nbsp&nbsp&nbsp");
	if (f && k5) printf("<a href=\"#31\">返程-转乘二次</a>&nbsp&nbsp&nbsp");
	printf("</p>");
	printf("<table border=2 class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\"><a name=\"1\">直达:车次信息</a></caption>\n<tr><th align=\"right\">车次</th><th align=\"right\">出发日期</th><th align=\"right\">始发站</th><th align=\"right\">发车时间</th><th align=\"right\">抵达日期</th><th align=\"right\">终点站</th><th align=\"right\">抵达时间</th><th align=\"right\">行程时间</th><th align=\"right\">最低票价</th>");
	if (s1)
	{
		printf("<th align=\"right\">硬座余票</th><th align=\"right\">硬座票价</th>");
	}
	if (s2)
	{
		printf("<th align=\"right\">软座余票</th><th align=\"right\">软座票价</th>");
	}
	if (s3)
	{
		printf("<th align=\"right\">硬卧余票</th><th align=\"right\">硬卧票价</th>");
	}
	if (s4)
	{
		printf("<th align=\"right\">软卧余票</th><th align=\"right\">软卧票价</th>");
	}
	printf("</th><th align=\"right\">预定</th></tr>\n");
	for (r = 0; r < num_rows; r++)
	{
		printf("<tr>");
		for (i = 0; i < num_cols; i++)
		{
			if (i == 9)
			{
				if (s1)
				{
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
				}

				if (s2)
				{
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
				}

				if (s3)
				{
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q14, r, i + 2); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q14, r, i + 4); printf("%s", (val[0] != '\0') ? val : "--"); printf("</td>");
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q14, r, i + 3); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q14, r, i + 5); printf("%s", (val[0] != '\0') ? val : "—"); printf("</td>");
					i += 6;
				}

				if (s4)
				{
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q14, r, i + 2); printf("%s", (val[0] != '\0') ? val : "--"); printf("</td>");
					if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q14, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q14, r, i + 3); printf("%s", (val[0] != '\0') ? val : "—"); printf("</td>");
				}

				if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
				else printf("<td align=\"right\" style=\"color:black\">");
				val1 = PQgetvalue(Q14, r, 0); val2 = PQgetvalue(Q14, r, 2); val3 = PQgetvalue(Q14, r, 5); val4 = PQgetvalue(Q14, r, 1);
				printf("<a href=\"http://localhost/cgi-bin/buy.cgi?1=1&2=%s&3=%s&4=%s&5=%s&6=%s&7=%s\" target=\"_blank\">预定</a>", val1, val2, val3, val4, value[12], value[13]); printf("</td>");
				break;
			}
			val = PQgetvalue(Q14, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
			else printf("<td align=\"right\" style=\"color:black\">");
			printf("%s", val);
			printf("</td>");
		}
		printf("</tr>\n");
	}
	printf("</table>");
	PQclear(Q14);

	if (!f)
	{
		PQexec(conn,"drop table temp15");
		if (!k4 && !k5) 
			goto miss2_3;
		else
			goto miss1;

	}

miss0_1:

	PQprepare(conn, "Query_One1_0", "select d1.train_id as train_id, s1.station_name as start_name, d1.departing_time as start_time, d1.inner_station_id as start_id, s2.station_name as end_name, d2.arriving_time as end_time, d2.inner_station_id as end_id, t.date_id as train_departing_day, t.date_id + d2.arriving_day as arriving_day, d2.arriving_time_number - d1.departing_time_number + (d2.arriving_day - d1.departing_day) * 1440 as travel_time, $3 as departing_day into temp111 from database1 as d1, database1 as d2, station as s1, station as s2, the_date as t where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = $2 and t.date_id = $3 - d1.departing_day;", 3, paramTypes1);

	PQexecPrepared(conn, "Query_One1_0", 3, (const char **)param_val1_0, param_len1, param_format1, 0);

	PQprepare(conn, "Query_One2_0", "select t.train_id, p1.seat_type as seat_type, t.start_name, t.start_time, t.start_id, t.end_name, t.end_time, t.end_id, t.train_departing_day, t.arriving_day, t.departing_day, t.travel_time, p2.price - p1.price as price into temp121 from temp111 as t, possible_ticket as p1, possible_ticket as p2 where p1.inner_station_id = t.start_id and p2.inner_station_id = t.end_id and p1.train_id = t.train_id and p2.train_id = t.train_id and p1.seat_type = p2.seat_type and p1.seat_type in ($1,$2,$3,$4,$5,$6,$7);", 7, paramTypes2);

	PQexecPrepared(conn, "Query_One2_0", 7, (const char **)param_val2, param_len2, param_format2, 0);



	PQexec(conn, "drop table temp111");
	PQexec(conn, "select t.train_id, t.seat_type, min(r.tickets) as tickets, t.start_name, t.start_time,t.end_name, t.end_time, t.departing_day, t.arriving_day, t.travel_time,t.price into temp131 from remaining_ticket as r, temp121 as t where r.inner_station_id between t.start_id + 1 and t.end_id and r.the_day = t.train_departing_day and r.train_id = t.train_id and r.seat_type =  t.seat_type group by t.train_id,t.seat_type,t.start_name,t.start_time,t.end_name,t.end_time,t.departing_day,t.arriving_day,t.travel_time,t.price; drop table temp121; delete from temp131 where tickets <=0;");



	if (k3==1){
		 PQexec(conn, "select t.train_id,t.seat_type,t.tickets,t.start_name,t.start_time,t.end_name,t.end_time,d1.actual_date as departing_date, d2.actual_date as arriving_date,t.travel_time,t.price into temp141 from temp131 as t, the_date as d1, the_date as d2 where d1.date_id = t.departing_day and d2.date_id = t.arriving_day; select distinct  t.train_id,t.departing_date, t.start_name, t.start_time,  t.arriving_date,t.end_name, t.end_time, t.travel_time into temp151 from temp141 as t; alter table temp151 add Min_Price decimal(5,1) default 9999.9;");

		if (s1) PQexec(conn, "alter table temp151 add Hard_Seat integer; alter table temp151 add Hard_Seat_Price decimal(5,1); update temp151 set Hard_Seat = t.tickets, Hard_Seat_Price = t.price from temp141 as t where t.train_id = temp151.train_id and t.start_name = temp151.start_name and t.end_name = temp151.end_name and t.seat_type = 'Hard_Seat'; update temp151 set Min_Price = Hard_Seat_Price where Min_Price > Hard_Seat_Price;");

		if (s2) PQexec(conn, "alter table temp151 add Soft_Seat integer; alter table temp151 add Soft_Seat_Price decimal(5,1); update temp151 set Soft_Seat = t.tickets, Soft_Seat_Price = t.price from temp141 as t where t.train_id = temp151.train_id and t.start_name = temp151.start_name and t.end_name = temp151.end_name and t.seat_type = 'Soft_Seat'; update temp151 set Min_Price = Soft_Seat_Price where Min_Price > Soft_Seat_Price;");

		if (s3) PQexec(conn, "alter table temp151 add Hard_Up integer; alter table temp151 add Hard_Up_Price decimal(5,1); update temp151 set Hard_Up = t.tickets, Hard_Up_Price = t.price from temp141 as t where t.train_id = temp151.train_id and t.start_name = temp151.start_name and t.end_name = temp151.end_name and t.seat_type = 'Hard_Up'; update temp151 set Min_Price = Hard_Up_Price where Min_Price > Hard_Up_Price; alter table temp151 add Hard_Middle integer; alter table temp151 add Hard_Middle_Price decimal(5,1); update temp151 set Hard_Middle = t.tickets, Hard_Middle_Price = t.price from temp141 as t where t.train_id = temp151.train_id and t.start_name = temp151.start_name and t.end_name = temp151.end_name and t.seat_type = 'Hard_Middle'; update temp151 set Min_Price = Hard_Middle_Price where Min_Price > Hard_Middle_Price; alter table temp151 add Hard_Down integer; alter table temp151 add Hard_Down_Price decimal(5,1); update temp151 set Hard_Down = t.tickets, Hard_Down_Price = t.price from temp141 as t where t.train_id = temp151.train_id and t.start_name = temp151.start_name and t.end_name = temp151.end_name and t.seat_type = 'Hard_Down';");

		if (s4) PQexec(conn, "update temp151 set Min_Price = Hard_Down_Price where Min_Price > Hard_Down_Price; alter table temp151 add Soft_Up integer; alter table temp151 add Soft_Up_Price decimal(5,1); update temp151 set Soft_Up = t.tickets, Soft_Up_Price = t.price from temp141 as t where t.train_id = temp151.train_id and t.start_name = temp151.start_name and t.end_name = temp151.end_name and t.seat_type = 'Soft_Up'; update temp151 set Min_Price = Soft_Up_Price where Min_Price > Soft_Up_Price; alter table temp151 add Soft_Down integer; alter table temp151 add Soft_Down_Price decimal(5,1); update temp151 set Soft_Down = t.tickets, Soft_Down_Price = t.price from temp141 as t where t.train_id = temp151.train_id and t.start_name = temp151.start_name and t.end_name = temp151.end_name and t.seat_type = 'Soft_Down'; update temp151 set Min_Price = Soft_Down_Price where Min_Price > Soft_Down_Price;");

		PQexec(conn, "drop table temp141;");
		PQexec(conn, "select t1.train_id as train_id1, t1.departing_date as departing_date1, t1.start_name as start_name1, t1.start_time as start_time1, t1.arriving_date as arriving_date1, t1.end_name as end_name1, t1.end_time as end_time1, t1.travel_time as travel_time1, t1.min_price as min_price1, t1.hard_seat as hard_seat1, t1.hard_seat_price as hard_seat_price1, t1.soft_seat as soft_seat1, t1.soft_seat_price as soft_seat_price1, t1.hard_up as hard_up1, t1.hard_up_price as hard_up_price1, t1.hard_middle as hard_middle1, t1.hard_middle_price as hard_middle_price1, t1.hard_down as hard_down1, t1.hard_down_price as hard_down_price1, t1.soft_up as soft_up1, t1.soft_up_price as soft_up_price1, t1.soft_down as soft_down1, t1.soft_down_price as soft_down_price1, t2.train_id as train_id2, t2.departing_date as departing_date2, t2.start_name as start_name2, t2.start_time as start_time2, t2.arriving_date as arriving_date2, t2.end_name as end_name2, t2.end_time as end_time2, t2.travel_time as travel_time2, t2.min_price as min_price2, t2.hard_seat as hard_seat2, t2.hard_seat_price as hard_seat_price2, t2.soft_seat as soft_seat2, t2.soft_seat_price as soft_seat_price2, t2.hard_up as hard_up2, t2.hard_up_price as hard_up_price2, t2.hard_middle as hard_middle2, t2.hard_middle_price as hard_middle_price2, t2.hard_down as hard_down2, t2.hard_down_price as hard_down_price2, t2.soft_up as soft_up2, t2.soft_up_price as soft_up_price2, t2.soft_down as soft_down2, t2.soft_down_price as soft_down_price2 into temp16 from temp15 as t1, temp151 as t2 where t2.departing_date > t1.arriving_date or (t2.departing_date = t1.arriving_date and t2.start_time > t1.end_time);");
		if (k2 == 1)
			Q141 = PQexec(conn, "select * from temp16 order by Min_Price1 + Min_Price2;");
		else if (k2 == 2)
			Q141 = PQexec(conn, "select * from temp16 order by travel_time1 + travel_time1;");
		else if (k2 == 3)
			Q141 = PQexec(conn, "select * from temp16 order by start_time1, start_time2;");

		num_rows1 = PQntuples(Q141);
		if (num_rows1 == 0) printf("非法输入,请再次尝试 或 直达返程搜索无结果\n");
		num_cols = PQnfields(Q141); num_cols1 = PQnfields(Q141);
	printf("<p align=\"center\" style=\"font-size:18px\">");
	if(f && k3) printf("<a href=\"#11\">往返程-直达</a>&nbsp&nbsp&nbsp");
	else if (k3) printf("<a href=\"#1\">直达</a>&nbsp&nbsp&nbsp");
	if (k4) printf("<a href=\"#2\">去程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (f && k4) printf("<a href=\"#21\">返程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (k5) printf("<a href=\"#3\">去程-转乘二次</a>&nbsp&nbsp&nbsp");
	if (f && k5) printf("<a href=\"#31\">返程-转乘二次</a>&nbsp&nbsp&nbsp");
	printf("</p>");
		printf("<table border=2 class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\"><a name=\"11\">往返程-直达:车次信息</a></caption>\n<tr><th align=\"right\">乘车方案编号</th><th align=\"right\">车次</th><th align=\"right\">出发日期</th><th align=\"right\">始发站</th><th align=\"right\">发车时间</th><th align=\"right\">抵达日期</th><th align=\"right\">终点站</th><th align=\"right\">抵达时间</th><th align=\"right\">行程时间</th><th align=\"right\">最低票价</th>");
		if (s1)
		{
			printf("<th align=\"right\">硬座余票</th><th align=\"right\">硬座票价</th>");
		}
		if (s2)
		{
			printf("<th align=\"right\">软座余票</th><th align=\"right\">软座票价</th>");
		}
		if (s3)
		{
			printf("<th align=\"right\">硬卧余票</th><th align=\"right\">硬卧票价</th>");
		}
		if (s4)
		{
			printf("<th align=\"right\">软卧余票</th><th align=\"right\">软卧票价</th>");
		}
		printf("</th><th align=\"right\">预定</th></tr>\n");
		for (r = 0; r < num_rows1; r++)
		{
			if (r % 2 == 0)
				printf("<tr><td rowspan = 2 align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<tr><td rowspan = 2 align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("方案 %d </td>", r + 1);
			for (i = 0; i < num_cols1; i++)
			{
				if (i == 9 || i == 32)
				{
					if (s1)
					{
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i++);
						printf("%s ", (val[0] != '\0') ? val : "--");
						printf("</td>");
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i++);
						printf("%s ", (val[0] != '\0') ? val : "—");
						printf("</td>");
					}

					if (s2)
					{
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i++);
						printf("%s ", (val[0] != '\0') ? val : "--");
						printf("</td>");
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i++);
						printf("%s ", (val[0] != '\0') ? val : "—");
						printf("</td>");
					}

					if (s3)
					{
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
						val = PQgetvalue(Q141, r, i + 2); printf("%s/ ", (val[0] != '\0') ? val : "--");
						val = PQgetvalue(Q141, r, i + 4); printf("%s", (val[0] != '\0') ? val : "--"); printf("</td>");
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
						val = PQgetvalue(Q141, r, i + 3); printf("%s/ ", (val[0] != '\0') ? val : "—");
						val = PQgetvalue(Q141, r, i + 5); printf("%s", (val[0] != '\0') ? val : "—"); printf("</td>");
						i += 6;
					}

					if (s4)
					{
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
						val = PQgetvalue(Q141, r, i + 2); printf("%s", (val[0] != '\0') ? val : "--"); printf("</td>");
						if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
						val = PQgetvalue(Q141, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
						val = PQgetvalue(Q141, r, i + 3); printf("%s", (val[0] != '\0') ? val : "—"); printf("</td>");
					}
					if (i < 32)
					{
						if (r % 2 == 0) printf("<td rowspan=\"2\" align=\"right\" style=\"color:white"";""background-color:black\">");
						else printf("<td rowspan=\"2\" align=\"right\" style=\"color:black"";""background-color:white\">");
						val1 = PQgetvalue(Q141, r, 0); val2 = PQgetvalue(Q141, r, 2); val3 = PQgetvalue(Q141, r, 5); val4 = PQgetvalue(Q141, r, 1);
						printf("<a href=\"http://localhost/cgi-bin/buy.cgi?1=2&2=%s&3=%s&4=%s&5=%s", val1, val2, val3, val4);
						val1 = PQgetvalue(Q141, r, 23); val2 = PQgetvalue(Q141, r, 25); val3 = PQgetvalue(Q141, r, 28); val4 = PQgetvalue(Q141, r, 24);
						printf("&6=%s&7=%s&8=%s&9=%s&10=%s&11=%s\" target=\"_blank\">预定</a>", val1, val2, val3, val4, value[12], value[13]); printf("</td>");
						printf("</td>"); printf("</tr>");
						i = 23;
					}
					else break;
				}
				val = PQgetvalue(Q141, r, i);
				if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
				else
					printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
				printf("%s", val);
				printf("</td>");
			}
			printf("</tr>\n");
		}
		printf("</table>");
		PQclear(Q141);
		PQexec(conn, "drop table temp15");
		PQexec(conn, "drop table temp151");
		PQexec(conn, "drop table temp16");
		if (!k4 && !k5) 
			goto miss2_3;
	}




	
	const Oid paramTypes1_1[4] = { 1043,1043,23 ,23};
	char *param_val1_1[4] = { value[0], value[1],(char *)&k1,(char *)&k6 };
	int   param_len1_1[4] = { 0,0,4,4 };
	int   param_format1_1[4] = { 0,0,1,1};


	int k6_1;

miss1:
	if (f)
	{	
		if(k1_0 == m){
			k6_1 = (int)ntohl(m+1);
			param_val1_1[3] = (char *)&k6_1;
		}
		PQprepare(conn, "Query_Two1_1", "select d1.train_id as train_id_1, d3.train_id as train_id_2 , s1.station_name as start_name_1, d1.departing_time as start_time_1, d1.inner_station_id as start_id_1, s2.station_name as end_name_1, d2.arriving_time as end_time_1, d2.inner_station_id as end_id_1, s3.station_name as start_name_2, d3.departing_time as start_time_2, d3.inner_station_id as start_id_2, s4.station_name as end_name_2, d4.arriving_time as end_time_2, d4.inner_station_id as end_id_2, t1.date_id as train_departing_day_1,$3 as departing_day_1, t1.date_id + d2.arriving_day as arriving_day_1, t2.date_id as train_departing_day_2, t2.date_id + d3.departing_day as departing_day_2, t2.date_id + d4.arriving_day as arriving_day_2, ((D3.departing_time_number+1440-D2.arriving_time_number)%1440 + (D2.arriving_day-D1.departing_day)*1440 + D2.arriving_time_number - D1.departing_time_number + (D4.arriving_day-D3.departing_day)*1440 + D4.arriving_time_number - D3.departing_time_number) as travel_time into temp21 from database1 as d1, database1 as d2,database1 as d3,database1 as d4, station as s1, station as s2,station as s3, station as s4, the_date as t1, the_date as t2 where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.train_id not in(select train_id from temp13 ) and d3.train_id = d4.train_id and d3.inner_station_id < d4.inner_station_id and d3.train_id not in(select train_id from temp13 ) and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = s3.city_name and d3.outer_station_id = s3.station_id and d4.outer_station_id = s4.station_id and s4.city_name = $2 and (d3.departing_time_number + 1440 - d2.arriving_time_number)%1440 < 240 and (((d3.departing_time_number+1440-d2.arriving_time_number)%1440>60 and s2.station_id = s3.station_id) or ((d3.departing_time_number+1440-d2.arriving_time_number)%1440>120 and s2.station_id != s3.station_id)) and ((d3.departing_time_number>d2.arriving_time_number and t2.date_id = t1.date_id + d2.arriving_day - d3.departing_day) or (d3.departing_time_number<d2.arriving_time_number and t2.date_id = t1.date_id + D2.arriving_day  + 1 - d3.departing_day)) and t1.date_id = $3 - d1.departing_day and t2.date_id + d4.arriving_day < $4;", 4, paramTypes1_1);
		
		PQexecPrepared(conn, "Query_Two1_1", 4, (const char **)param_val1_1, param_len1_1, param_format1_1, 0);
	}
	else
	{
		PQprepare(conn, "Query_Two1", "select d1.train_id as train_id_1, d3.train_id as train_id_2 , s1.station_name as start_name_1, d1.departing_time as start_time_1, d1.inner_station_id as start_id_1, s2.station_name as end_name_1, d2.arriving_time as end_time_1, d2.inner_station_id as end_id_1, s3.station_name as start_name_2, d3.departing_time as start_time_2, d3.inner_station_id as start_id_2, s4.station_name as end_name_2, d4.arriving_time as end_time_2, d4.inner_station_id as end_id_2, t1.date_id as train_departing_day_1,$3 as departing_day_1, t1.date_id + d2.arriving_day as arriving_day_1, t2.date_id as train_departing_day_2, t2.date_id + d3.departing_day as departing_day_2, t2.date_id + d4.arriving_day as arriving_day_2, ((D3.departing_time_number+1440-D2.arriving_time_number)%1440 + (D2.arriving_day-D1.departing_day)*1440 + D2.arriving_time_number - D1.departing_time_number + (D4.arriving_day-D3.departing_day)*1440 + D4.arriving_time_number - D3.departing_time_number) as travel_time into temp21 from database1 as d1, database1 as d2,database1 as d3,database1 as d4, station as s1, station as s2,station as s3, station as s4, the_date as t1, the_date as t2 where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.train_id not in(select train_id from temp13 ) and d3.train_id = d4.train_id and d3.inner_station_id < d4.inner_station_id and d3.train_id not in(select train_id from temp13 ) and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = s3.city_name and d3.outer_station_id = s3.station_id and d4.outer_station_id = s4.station_id and s4.city_name = $2 and (d3.departing_time_number + 1440 - d2.arriving_time_number)%1440 < 240 and (((d3.departing_time_number+1440-d2.arriving_time_number)%1440>60 and s2.station_id = s3.station_id) or ((d3.departing_time_number+1440-d2.arriving_time_number)%1440>120 and s2.station_id != s3.station_id)) and ((d3.departing_time_number>d2.arriving_time_number and t2.date_id = $3 + d2.arriving_day - d1.departing_day - d3.departing_day) or (d3.departing_time_number<d2.arriving_time_number and t2.date_id = $3 + D2.arriving_day - D1.departing_day + 1 - d3.departing_day)) and t1.date_id = $3 - d1.departing_day;", 3, paramTypes1);

		PQexecPrepared(conn, "Query_Two1", 3, (const char **)param_val1, param_len1, param_format1, 0);
	}
	
	PQprepare(conn, "Query_Two2", "select t.train_id_1, t.train_id_2,p1.seat_type as seat_type_1,p3.seat_type as seat_type_2, t.start_name_1, t.start_time_1, t.start_id_1, t.end_name_1, t.end_time_1, t.end_id_1, t.train_departing_day_1, t.departing_day_1,t.arriving_day_1, t.start_name_2, t.start_time_2, t.start_id_2, t.end_name_2, t.end_time_2, t.end_id_2, t.train_departing_day_2, t.departing_day_2, t.travel_time,t.arriving_day_2, p2.price - p1.price as price_1,p4.price - p3.price as price_2 into temp22 from temp21 as t, possible_ticket as p1, possible_ticket as p2,possible_ticket as p3, possible_ticket as p4 where p1.inner_station_id = t.start_id_1 and p2.inner_station_id = t.end_id_1 and p3.inner_station_id = t.start_id_2 and p4.inner_station_id = t.end_id_2 and p1.train_id = t.train_id_1 and p2.train_id = t.train_id_1 and p3.train_id = t.train_id_2 and p4.train_id = t.train_id_2 and p1.seat_type = p2.seat_type and p3.seat_type = p4.seat_type and p1.seat_type in ($1,$2,$3,$4,$5,$6,$7) and p3.seat_type in ($1,$2,$3,$4,$5,$6,$7);", 7, paramTypes2);
	PQexecPrepared(conn, "Query_Two2", 7, (const char **)param_val2, param_len2, param_format2, 0);

	PQexec(conn, "drop table temp21; select t.train_id_1,t.train_id_2,t.seat_type_1,t.seat_type_2,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.travel_time, min(r1.tickets) as tickets_1, min(r2.tickets) as tickets_2 into temp23 from remaining_ticket as r1,remaining_ticket as r2 ,temp22 as t where r1.inner_station_id between t.start_id_1 + 1 and t.end_id_1 and r1.the_day = t.train_departing_day_1 and r1.train_id = t.train_id_1 and r1.seat_type =  t.seat_type_1 and r2.inner_station_id between t.start_id_2 + 1 and t.end_id_2 and r2.the_day = t.train_departing_day_2 and r2.train_id = t.train_id_2 and r2.seat_type =  t.seat_type_2 group by t.train_id_1,t.train_id_2,t.seat_type_1,t.seat_type_2,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.travel_time; drop table temp22; delete from temp23 where tickets_1 <=0 or tickets_2 <=0;");

	if (!k4) {
		if (f){
			goto miss1_1;
		}
		else{
			goto miss2;
		}
	}

	PQexec(conn, "select t.train_id_1,t.train_id_2,t.seat_type_1,t.seat_type_2,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.price_2,t.travel_time, t.tickets_1, t.tickets_2,d1.actual_date as departing_date_1,d2.actual_date as arriving_date_1,d3.actual_date as departing_date_2,d4.actual_date as arriving_date_2 into temp24 from temp23 as t, the_date as d1, the_date as d2,the_date as d3,the_date as d4 where d1.date_id = t.departing_day_1 and d2.date_id = t.arriving_day_1 and d3.date_id = t.departing_day_2 and d4.date_id = t.arriving_day_2; select distinct t.train_id_1,t.train_id_2,t.departing_date_1, t.departing_date_2, t.start_name_1,t.start_name_2,t.start_time_1,t.start_time_2,t.arriving_date_1,t.arriving_date_2,t.end_name_1,t.end_name_2,t.end_time_1,t.end_time_2,t.travel_time into temp25 from temp24 as t; alter table temp25 add Min_Price decimal(5,1) default 9999.9; alter table temp25 add Min_Price_1 decimal(5,1) default 9999.9; alter table temp25 add Min_Price_2 decimal(5,1) default 9999.9;");

	if (s1)
		PQexec(conn, "alter table temp25 add Hard_Seat_1 integer; alter table temp25 add Hard_Seat_Price_1 decimal(5,1); update temp25 set Hard_Seat_1 = t.tickets_1, Hard_Seat_Price_1 = t.price_1 from temp24 as t where t.train_id_1 = temp25.train_id_1 and t.start_name_1 = temp25.start_name_1 and t.end_name_1 = temp25.end_name_1 and t.seat_type_1 = 'Hard_Seat'; update temp25 set Min_Price_1 = Hard_Seat_Price_1 where Min_Price_1 > Hard_Seat_Price_1; alter table temp25 add Hard_Seat_2 integer; alter table temp25 add Hard_Seat_Price_2 decimal(5,1); update temp25 set Hard_Seat_2 = t.tickets_2, Hard_Seat_Price_2 = t.price_2 from temp24 as t where t.train_id_2 = temp25.train_id_2 and t.start_name_2 = temp25.start_name_2 and t.end_name_2 = temp25.end_name_2 and t.seat_type_2 = 'Hard_Seat'; update temp25 set Min_Price_2 = Hard_Seat_Price_2 where Min_Price_2 > Hard_Seat_Price_2;");

	if (s2)
		PQexec(conn, "alter table temp25 add Soft_Seat_1 integer; alter table temp25 add Soft_Seat_Price_1 decimal(5,1); update temp25 set Soft_Seat_1 = t.tickets_1, Soft_Seat_Price_1 = t.price_1 from temp24 as t where t.train_id_1 = temp25.train_id_1 and t.start_name_1 = temp25.start_name_1 and t.end_name_1 = temp25.end_name_1 and t.seat_type_1 = 'Soft_Seat'; update temp25 set Min_Price_1 = Soft_Seat_Price_1 where Min_Price_1 > Soft_Seat_Price_1; alter table temp25 add Soft_Seat_2 integer; alter table temp25 add Soft_Seat_Price_2 decimal(5,1); update temp25 set Soft_Seat_2 = t.tickets_2, Soft_Seat_Price_2 = t.price_2 from temp24 as t where t.train_id_2 = temp25.train_id_2 and t.start_name_2 = temp25.start_name_2 and t.end_name_2 = temp25.end_name_2 and t.seat_type_2 = 'Soft_Seat'; update temp25 set Min_Price_2 = Soft_Seat_Price_2 where Min_Price_2 > Soft_Seat_Price_2;");

	if (s3)
		PQexec(conn, "alter table temp25 add Hard_Up_1 integer; alter table temp25 add Hard_Up_Price_1 decimal(5,1); update temp25 set Hard_Up_1 = t.tickets_1, Hard_Up_Price_1 = t.price_1 from temp24 as t where t.train_id_1 = temp25.train_id_1 and t.start_name_1 = temp25.start_name_1 and t.end_name_1 = temp25.end_name_1 and t.seat_type_1 = 'Hard_Up'; update temp25 set Min_Price_1 = Hard_Up_Price_1 where Min_Price_1 > Hard_Up_Price_1; alter table temp25 add Hard_Up_2 integer; alter table temp25 add Hard_Up_Price_2 decimal(5,1); update temp25 set Hard_Up_2 = t.tickets_2, Hard_Up_Price_2 = t.price_2 from temp24 as t where t.train_id_2 = temp25.train_id_2 and t.start_name_2 = temp25.start_name_2 and t.end_name_2 = temp25.end_name_2 and t.seat_type_2 = 'Hard_Up'; update temp25 set Min_Price_2 = Hard_Up_Price_2 where Min_Price_2 > Hard_Up_Price_2; alter table temp25 add Hard_Middle_1 integer; alter table temp25 add Hard_Middle_Price_1 decimal(5,1); update temp25 set Hard_Middle_1 = t.tickets_1, Hard_Middle_Price_1 = t.price_1 from temp24 as t where t.train_id_1 = temp25.train_id_1 and t.start_name_1 = temp25.start_name_1 and t.end_name_1 = temp25.end_name_1 and t.seat_type_1 = 'Hard_Middle'; update temp25 set Min_Price_1 = Hard_Middle_Price_1 where Min_Price_1 > Hard_Middle_Price_1; alter table temp25 add Hard_Middle_2 integer; alter table temp25 add Hard_Middle_Price_2 decimal(5,1); update temp25 set Hard_Middle_2 = t.tickets_2, Hard_Middle_Price_2 = t.price_2 from temp24 as t where t.train_id_2 = temp25.train_id_2 and t.start_name_2 = temp25.start_name_2 and t.end_name_2 = temp25.end_name_2 and t.seat_type_2 = 'Hard_Middle'; update temp25 set Min_Price_2 = Hard_Middle_Price_2 where Min_Price_2 > Hard_Middle_Price_2; alter table temp25 add Hard_Down_1 integer; alter table temp25 add Hard_Down_Price_1 decimal(5,1); update temp25 set Hard_Down_1 = t.tickets_1, Hard_Down_Price_1 = t.price_1 from temp24 as t where t.train_id_1 = temp25.train_id_1 and t.start_name_1 = temp25.start_name_1 and t.end_name_1 = temp25.end_name_1 and t.seat_type_1 = 'Hard_Down'; update temp25 set Min_Price_1 = Hard_Down_Price_1 where Min_Price_1 > Hard_Down_Price_1; alter table temp25 add Hard_Down_2 integer; alter table temp25 add Hard_Down_Price_2 decimal(5,1); update temp25 set Hard_Down_2 = t.tickets_2, Hard_Down_Price_2 = t.price_2 from temp24 as t where t.train_id_2 = temp25.train_id_2 and t.start_name_2 = temp25.start_name_2 and t.end_name_2 = temp25.end_name_2 and t.seat_type_2 = 'Hard_Down'; update temp25 set Min_Price_2 = Hard_Down_Price_2 where Min_Price_2 > Hard_Down_Price_2;");

	if (s4)
		PQexec(conn, "alter table temp25 add Soft_Up_1 integer; alter table temp25 add Soft_Up_Price_1 decimal(5,1); update temp25 set Soft_Up_1 = t.tickets_1, Soft_Up_Price_1 = t.price_1 from temp24 as t where t.train_id_1 = temp25.train_id_1 and t.start_name_1 = temp25.start_name_1 and t.end_name_1 = temp25.end_name_1 and t.seat_type_1 = 'Soft_Up'; update temp25 set Min_Price_1 = Soft_Up_Price_1 where Min_Price_1 > Soft_Up_Price_1; alter table temp25 add Soft_Up_2 integer; alter table temp25 add Soft_Up_Price_2 decimal(5,1); update temp25 set Soft_Up_2 = t.tickets_2, Soft_Up_Price_2 = t.price_2 from temp24 as t where t.train_id_2 = temp25.train_id_2 and t.start_name_2 = temp25.start_name_2 and t.end_name_2 = temp25.end_name_2 and t.seat_type_2 = 'Soft_Up'; update temp25 set Min_Price_2 = Soft_Up_Price_2 where Min_Price_2 > Soft_Up_Price_2; alter table temp25 add Soft_Down_1 integer; alter table temp25 add Soft_Down_Price_1 decimal(5,1); update temp25 set Soft_Down_1 = t.tickets_1, Soft_Down_Price_1 = t.price_1 from temp24 as t where t.train_id_1 = temp25.train_id_1 and t.start_name_1 = temp25.start_name_1 and t.end_name_1 = temp25.end_name_1 and t.seat_type_1 = 'Soft_Down'; update temp25 set Min_Price_1 = Soft_Down_Price_1 where Min_Price_1 > Soft_Down_Price_1; alter table temp25 add Soft_Down_2 integer; alter table temp25 add Soft_Down_Price_2 decimal(5,1); update temp25 set Soft_Down_2 = t.tickets_2, Soft_Down_Price_2 = t.price_2 from temp24 as t where t.train_id_2 = temp25.train_id_2 and t.start_name_2 = temp25.start_name_2 and t.end_name_2 = temp25.end_name_2 and t.seat_type_2 = 'Soft_Down'; update temp25 set Min_Price_2 = Soft_Down_Price_2 where Min_Price_2 > Soft_Down_Price_2;");

	PQexec(conn, "update temp25 set Min_Price = Min_Price_1+Min_Price_2; alter table temp25 drop Min_Price_1; alter table temp25 drop Min_Price_2; drop table temp24;");

	PGresult *Q23;

	if (k2 == 1)
		Q23 = PQexec(conn, "select * from temp25 order by Min_Price;");
	else if (k2 == 2)
		Q23 = PQexec(conn, "select * from temp25 order by travel_time;");
	else if (k2 == 3)
		Q23 = PQexec(conn, "select * from temp25 order by start_time_1;");

	num_rows = PQntuples(Q23);
	if (num_rows == 0)
		printf("非法输入,请再次尝试 或 转乘一次无结果\n");

	num_cols = PQnfields(Q23);

	printf("<p align=\"center\" style=\"font-size:18px\">");
	if(f && k3) printf("<a href=\"#11\">往返程-直达</a>&nbsp&nbsp&nbsp");
	else if (k3) printf("<a href=\"#1\">直达</a>&nbsp&nbsp&nbsp");
	if (k4) printf("<a href=\"#2\">去程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (f && k4) printf("<a href=\"#21\">返程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (k5) printf("<a href=\"#3\">去程-转乘二次</a>&nbsp&nbsp&nbsp");
	if (f && k5) printf("<a href=\"#31\">返程-转乘二次</a>&nbsp&nbsp&nbsp");
	printf("</p>");
	printf("<table border=2 class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\"><a name=\"2\">转乘一次:车次信息</a></caption>\n<tr><th align=\"right\">乘车方案编号</th><th align=\"right\">车次</th><th align=\"right\">出发日期</th><th align=\"right\">始发站</th><th align=\"right\">发车时间</th><th align=\"right\">抵达日期</th><th align=\"right\">终点站</th><th align=\"right\">抵达时间</th><th align=\"right\">行程时间</th><th align=\"right\">最低票价</th>");
	if (s1)
	{
		printf("<th align=\"right\">硬座余票</th><th align=\"right\">硬座票价</th>");
	}
	if (s2)
	{
		printf("<th align=\"right\">软座余票</th><th align=\"right\">软座票价</th>");
	}
	if (s3)
	{
		printf("<th align=\"right\">硬卧余票</th><th align=\"right\">硬卧票价</th>");
	}
	if (s4)
	{
		printf("<th align=\"right\">软卧余票</th><th align=\"right\">软卧票价</th>");
	}
	printf("</th><th align=\"right\">预定</th></tr>\n");

	for (r = 0; r < num_rows; r++)
	{
		if (r % 2 == 0)
			printf("<tr><td rowspan = 2 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<tr><td rowspan = 2 align=\"right\" style=\"color:black"";""background-color:white\">");
		printf("方案 %d </td>", r + 1);

		for (i = 0; i < 14; i += 2)
		{
			val = PQgetvalue(Q23, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		for (; i <= 16; ++i)
		{
			if (i == 14 || i == 15)
			{
				val = PQgetvalue(Q23, r, i);
				if (r % 2 == 0)
					printf("<td rowspan = 2 align=\"right\" style=\"color:white"";""background-color:black\">");
				else
					printf("<td rowspan = 2 align=\"right\" style=\"color:black"";""background-color:white\">");
				printf("%s", val);
				printf("</td>");
			}
			else if (i == 16)
			{
				if (s1)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 3;
				}

				if (s2)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 3;
				}

				if (s3)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q23, r, i + 4); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q23, r, i + 8); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q23, r, i + 5); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q23, r, i + 9); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 12;
				}

				if (s4)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q23, r, i + 4); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q23, r, i + 5); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
				}
			}
		}

		if (r % 2 == 0)
			printf("<td rowspan = 2 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<td rowspan = 2 align=\"right\" style=\"color:black"";""background-color:white\">");

		val1 = PQgetvalue(Q23, r, 0);
		val2 = PQgetvalue(Q23, r, 4);
		val3 = PQgetvalue(Q23, r, 10);
		val4 = PQgetvalue(Q23, r, 2);
		val5 = PQgetvalue(Q23, r, 1);
		val6 = PQgetvalue(Q23, r, 5);
		val7 = PQgetvalue(Q23, r, 11);
		val8 = PQgetvalue(Q23, r, 3);
		printf("<a href=\"http://localhost/cgi-bin/buy.cgi?1=2&2=%s&3=%s&4=%s&5=%s&6=%s&7=%s&8=%s&9=%s&10=%s&11=%s\" target=\"_blank\">预定</a>", val1, val2, val3, val4, val5, val6, val7, val8, value[12], value[13]); printf("</td>");

		printf("</tr>\n");
		printf("<tr>\n");


		for (i = 1; i < 14; i += 2)
		{
			val = PQgetvalue(Q23, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		i = 18;

		if (s1)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 3;
		}

		if (s2)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 3;
		}

		if (s3)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q23, r, i + 4); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q23, r, i + 8); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q23, r, i + 5); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q23, r, i + 9); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 12;
		}

		if (s4)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q23, r, i + 4); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q23, r, i + 5); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
		}

		printf("</tr>\n");

	}
	printf("</table>");

	PQclear(Q23);

	PQexec(conn, "drop table temp25;");

	if (!f)
	{
		goto miss2;
	}

miss1_1:
	PQprepare(conn, "Query_Two1_0", "select d1.train_id as train_id_1, d3.train_id as train_id_2 , s1.station_name as start_name_1, d1.departing_time as start_time_1, d1.inner_station_id as start_id_1, s2.station_name as end_name_1, d2.arriving_time as end_time_1, d2.inner_station_id as end_id_1, s3.station_name as start_name_2, d3.departing_time as start_time_2, d3.inner_station_id as start_id_2, s4.station_name as end_name_2, d4.arriving_time as end_time_2, d4.inner_station_id as end_id_2, t1.date_id as train_departing_day_1,$3 as departing_day_1, t1.date_id + d2.arriving_day as arriving_day_1, t2.date_id as train_departing_day_2, t2.date_id + d3.departing_day as departing_day_2, t2.date_id + d4.arriving_day as arriving_day_2, ((D3.departing_time_number+1440-D2.arriving_time_number)%1440 + (D2.arriving_day-D1.departing_day)*1440 + D2.arriving_time_number - D1.departing_time_number + (D4.arriving_day-D3.departing_day)*1440 + D4.arriving_time_number - D3.departing_time_number) as travel_time into temp211 from database1 as d1, database1 as d2,database1 as d3,database1 as d4, station as s1, station as s2,station as s3, station as s4, the_date as t1, the_date as t2 where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.train_id not in(select train_id from temp131 ) and d3.train_id = d4.train_id and d3.inner_station_id < d4.inner_station_id and d3.train_id not in(select train_id from temp13 ) and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = s3.city_name and d3.outer_station_id = s3.station_id and d4.outer_station_id = s4.station_id and s4.city_name = $2 and (d3.departing_time_number + 1440 - d2.arriving_time_number)%1440 < 240 and (((d3.departing_time_number+1440-d2.arriving_time_number)%1440>60 and s2.station_id = s3.station_id) or ((d3.departing_time_number+1440-d2.arriving_time_number)%1440>120 and s2.station_id != s3.station_id)) and ((d3.departing_time_number>d2.arriving_time_number and t2.date_id = $3 + d2.arriving_day - d1.departing_day - d3.departing_day) or (d3.departing_time_number<d2.arriving_time_number and t2.date_id = $3 + D2.arriving_day - D1.departing_day + 1 - d3.departing_day)) and t1.date_id = $3 - d1.departing_day;", 3, paramTypes1);

	PQexecPrepared(conn, "Query_Two1_0", 3, (const char **)param_val1_0, param_len1, param_format1, 0);

	PQprepare(conn, "Query_Two2_0", "select t.train_id_1, t.train_id_2,p1.seat_type as seat_type_1,p3.seat_type as seat_type_2, t.start_name_1, t.start_time_1, t.start_id_1, t.end_name_1, t.end_time_1, t.end_id_1, t.train_departing_day_1, t.departing_day_1,t.arriving_day_1, t.start_name_2, t.start_time_2, t.start_id_2, t.end_name_2, t.end_time_2, t.end_id_2, t.train_departing_day_2, t.departing_day_2, t.travel_time,t.arriving_day_2, p2.price - p1.price as price_1,p4.price - p3.price as price_2 into temp221 from temp211 as t, possible_ticket as p1, possible_ticket as p2,possible_ticket as p3, possible_ticket as p4 where p1.inner_station_id = t.start_id_1 and p2.inner_station_id = t.end_id_1 and p3.inner_station_id = t.start_id_2 and p4.inner_station_id = t.end_id_2 and p1.train_id = t.train_id_1 and p2.train_id = t.train_id_1 and p3.train_id = t.train_id_2 and p4.train_id = t.train_id_2 and p1.seat_type = p2.seat_type and p3.seat_type = p4.seat_type and p1.seat_type in ($1,$2,$3,$4,$5,$6,$7) and p3.seat_type in ($1,$2,$3,$4,$5,$6,$7);", 7, paramTypes2);
	
	PQexecPrepared(conn, "Query_Two2_0", 7, (const char **)param_val2, param_len2, param_format2, 0);

	PQexec(conn, "drop table temp211; select t.train_id_1,t.train_id_2,t.seat_type_1,t.seat_type_2,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.travel_time, min(r1.tickets) as tickets_1, min(r2.tickets) as tickets_2 into temp231 from remaining_ticket as r1,remaining_ticket as r2 ,temp221 as t where r1.inner_station_id between t.start_id_1 + 1 and t.end_id_1 and r1.the_day = t.train_departing_day_1 and r1.train_id = t.train_id_1 and r1.seat_type =  t.seat_type_1 and r2.inner_station_id between t.start_id_2 + 1 and t.end_id_2 and r2.the_day = t.train_departing_day_2 and r2.train_id = t.train_id_2 and r2.seat_type =  t.seat_type_2 group by t.train_id_1,t.train_id_2,t.seat_type_1,t.seat_type_2,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.travel_time; drop table temp221; delete from temp231 where tickets_1 <=0 or tickets_2 <=0;");

	if (!k4) {
		goto miss2;
	}

	PQexec(conn, "select t.train_id_1,t.train_id_2,t.seat_type_1,t.seat_type_2,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.price_2,t.travel_time, t.tickets_1, t.tickets_2,d1.actual_date as departing_date_1,d2.actual_date as arriving_date_1,d3.actual_date as departing_date_2,d4.actual_date as arriving_date_2 into temp241 from temp231 as t, the_date as d1, the_date as d2,the_date as d3,the_date as d4 where d1.date_id = t.departing_day_1 and d2.date_id = t.arriving_day_1 and d3.date_id = t.departing_day_2 and d4.date_id = t.arriving_day_2; select distinct t.train_id_1,t.train_id_2,t.departing_date_1, t.departing_date_2, t.start_name_1,t.start_name_2,t.start_time_1,t.start_time_2,t.arriving_date_1,t.arriving_date_2,t.end_name_1,t.end_name_2,t.end_time_1,t.end_time_2,t.travel_time into temp251 from temp241 as t; alter table temp251 add Min_Price decimal(5,1) default 9999.9; alter table temp251 add Min_Price_1 decimal(5,1) default 9999.9; alter table temp251 add Min_Price_2 decimal(5,1) default 9999.9;");

	if (s1)
		PQexec(conn, "alter table temp251 add Hard_Seat_1 integer; alter table temp251 add Hard_Seat_Price_1 decimal(5,1); update temp251 set Hard_Seat_1 = t.tickets_1, Hard_Seat_Price_1 = t.price_1 from temp241 as t where t.train_id_1 = temp251.train_id_1 and t.start_name_1 = temp251.start_name_1 and t.end_name_1 = temp251.end_name_1 and t.seat_type_1 = 'Hard_Seat'; update temp251 set Min_Price_1 = Hard_Seat_Price_1 where Min_Price_1 > Hard_Seat_Price_1; alter table temp251 add Hard_Seat_2 integer; alter table temp251 add Hard_Seat_Price_2 decimal(5,1); update temp251 set Hard_Seat_2 = t.tickets_2, Hard_Seat_Price_2 = t.price_2 from temp241 as t where t.train_id_2 = temp251.train_id_2 and t.start_name_2 = temp251.start_name_2 and t.end_name_2 = temp251.end_name_2 and t.seat_type_2 = 'Hard_Seat'; update temp251 set Min_Price_2 = Hard_Seat_Price_2 where Min_Price_2 > Hard_Seat_Price_2;");

	if (s2)
		PQexec(conn, "alter table temp251 add Soft_Seat_1 integer; alter table temp251 add Soft_Seat_Price_1 decimal(5,1); update temp251 set Soft_Seat_1 = t.tickets_1, Soft_Seat_Price_1 = t.price_1 from temp241 as t where t.train_id_1 = temp251.train_id_1 and t.start_name_1 = temp251.start_name_1 and t.end_name_1 = temp251.end_name_1 and t.seat_type_1 = 'Soft_Seat'; update temp251 set Min_Price_1 = Soft_Seat_Price_1 where Min_Price_1 > Soft_Seat_Price_1; alter table temp251 add Soft_Seat_2 integer; alter table temp251 add Soft_Seat_Price_2 decimal(5,1); update temp251 set Soft_Seat_2 = t.tickets_2, Soft_Seat_Price_2 = t.price_2 from temp241 as t where t.train_id_2 = temp251.train_id_2 and t.start_name_2 = temp251.start_name_2 and t.end_name_2 = temp251.end_name_2 and t.seat_type_2 = 'Soft_Seat'; update temp251 set Min_Price_2 = Soft_Seat_Price_2 where Min_Price_2 > Soft_Seat_Price_2;");

	if (s3)
		PQexec(conn, "alter table temp251 add Hard_Up_1 integer; alter table temp251 add Hard_Up_Price_1 decimal(5,1); update temp251 set Hard_Up_1 = t.tickets_1, Hard_Up_Price_1 = t.price_1 from temp241 as t where t.train_id_1 = temp251.train_id_1 and t.start_name_1 = temp251.start_name_1 and t.end_name_1 = temp251.end_name_1 and t.seat_type_1 = 'Hard_Up'; update temp251 set Min_Price_1 = Hard_Up_Price_1 where Min_Price_1 > Hard_Up_Price_1; alter table temp251 add Hard_Up_2 integer; alter table temp251 add Hard_Up_Price_2 decimal(5,1); update temp251 set Hard_Up_2 = t.tickets_2, Hard_Up_Price_2 = t.price_2 from temp241 as t where t.train_id_2 = temp251.train_id_2 and t.start_name_2 = temp251.start_name_2 and t.end_name_2 = temp251.end_name_2 and t.seat_type_2 = 'Hard_Up'; update temp251 set Min_Price_2 = Hard_Up_Price_2 where Min_Price_2 > Hard_Up_Price_2; alter table temp251 add Hard_Middle_1 integer; alter table temp251 add Hard_Middle_Price_1 decimal(5,1); update temp251 set Hard_Middle_1 = t.tickets_1, Hard_Middle_Price_1 = t.price_1 from temp241 as t where t.train_id_1 = temp251.train_id_1 and t.start_name_1 = temp251.start_name_1 and t.end_name_1 = temp251.end_name_1 and t.seat_type_1 = 'Hard_Middle'; update temp251 set Min_Price_1 = Hard_Middle_Price_1 where Min_Price_1 > Hard_Middle_Price_1; alter table temp251 add Hard_Middle_2 integer; alter table temp251 add Hard_Middle_Price_2 decimal(5,1); update temp251 set Hard_Middle_2 = t.tickets_2, Hard_Middle_Price_2 = t.price_2 from temp241 as t where t.train_id_2 = temp251.train_id_2 and t.start_name_2 = temp251.start_name_2 and t.end_name_2 = temp251.end_name_2 and t.seat_type_2 = 'Hard_Middle'; update temp251 set Min_Price_2 = Hard_Middle_Price_2 where Min_Price_2 > Hard_Middle_Price_2; alter table temp251 add Hard_Down_1 integer; alter table temp251 add Hard_Down_Price_1 decimal(5,1); update temp251 set Hard_Down_1 = t.tickets_1, Hard_Down_Price_1 = t.price_1 from temp241 as t where t.train_id_1 = temp251.train_id_1 and t.start_name_1 = temp251.start_name_1 and t.end_name_1 = temp251.end_name_1 and t.seat_type_1 = 'Hard_Down'; update temp251 set Min_Price_1 = Hard_Down_Price_1 where Min_Price_1 > Hard_Down_Price_1; alter table temp251 add Hard_Down_2 integer; alter table temp251 add Hard_Down_Price_2 decimal(5,1); update temp251 set Hard_Down_2 = t.tickets_2, Hard_Down_Price_2 = t.price_2 from temp241 as t where t.train_id_2 = temp251.train_id_2 and t.start_name_2 = temp251.start_name_2 and t.end_name_2 = temp251.end_name_2 and t.seat_type_2 = 'Hard_Down'; update temp251 set Min_Price_2 = Hard_Down_Price_2 where Min_Price_2 > Hard_Down_Price_2;");

	if (s4)
		PQexec(conn, "alter table temp251 add Soft_Up_1 integer; alter table temp251 add Soft_Up_Price_1 decimal(5,1); update temp251 set Soft_Up_1 = t.tickets_1, Soft_Up_Price_1 = t.price_1 from temp241 as t where t.train_id_1 = temp251.train_id_1 and t.start_name_1 = temp251.start_name_1 and t.end_name_1 = temp251.end_name_1 and t.seat_type_1 = 'Soft_Up'; update temp251 set Min_Price_1 = Soft_Up_Price_1 where Min_Price_1 > Soft_Up_Price_1; alter table temp251 add Soft_Up_2 integer; alter table temp251 add Soft_Up_Price_2 decimal(5,1); update temp251 set Soft_Up_2 = t.tickets_2, Soft_Up_Price_2 = t.price_2 from temp241 as t where t.train_id_2 = temp251.train_id_2 and t.start_name_2 = temp251.start_name_2 and t.end_name_2 = temp251.end_name_2 and t.seat_type_2 = 'Soft_Up'; update temp251 set Min_Price_2 = Soft_Up_Price_2 where Min_Price_2 > Soft_Up_Price_2; alter table temp251 add Soft_Down_1 integer; alter table temp251 add Soft_Down_Price_1 decimal(5,1); update temp251 set Soft_Down_1 = t.tickets_1, Soft_Down_Price_1 = t.price_1 from temp241 as t where t.train_id_1 = temp251.train_id_1 and t.start_name_1 = temp251.start_name_1 and t.end_name_1 = temp251.end_name_1 and t.seat_type_1 = 'Soft_Down'; update temp251 set Min_Price_1 = Soft_Down_Price_1 where Min_Price_1 > Soft_Down_Price_1; alter table temp251 add Soft_Down_2 integer; alter table temp251 add Soft_Down_Price_2 decimal(5,1); update temp251 set Soft_Down_2 = t.tickets_2, Soft_Down_Price_2 = t.price_2 from temp241 as t where t.train_id_2 = temp251.train_id_2 and t.start_name_2 = temp251.start_name_2 and t.end_name_2 = temp251.end_name_2 and t.seat_type_2 = 'Soft_Down'; update temp251 set Min_Price_2 = Soft_Down_Price_2 where Min_Price_2 > Soft_Down_Price_2;");

	PQexec(conn, "update temp251 set Min_Price = Min_Price_1+Min_Price_2; alter table temp251 drop Min_Price_1; alter table temp251 drop Min_Price_2; drop table temp241;");


	if (k2 == 1)
		Q23 = PQexec(conn, "select * from temp251 order by Min_Price;");
	else if (k2 == 2)
		Q23 = PQexec(conn, "select * from temp251 order by travel_time;");
	else if (k2 == 3)
		Q23 = PQexec(conn, "select * from temp251 order by start_time_1;");

	num_rows = PQntuples(Q23);
	if (num_rows == 0)
		printf("非法输入,请再次尝试 或 转乘一次返程无结果\n");

	num_cols = PQnfields(Q23);

	printf("<p align=\"center\" style=\"font-size:18px\">");
	if(f && k3) printf("<a href=\"#11\">往返程-直达</a>&nbsp&nbsp&nbsp");
	else if (k3) printf("<a href=\"#1\">直达</a>&nbsp&nbsp&nbsp");
	if (k4) printf("<a href=\"#2\">去程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (f && k4) printf("<a href=\"#21\">返程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (k5) printf("<a href=\"#3\">去程-转乘二次</a>&nbsp&nbsp&nbsp");
	if (f && k5) printf("<a href=\"#31\">返程-转乘二次</a>&nbsp&nbsp&nbsp");
	printf("</p>");
	printf("<table border=2 class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\"><a name=\"21\">返程-转乘一次:车次信息</a></caption>\n<tr><th align=\"right\">乘车方案编号</th><th align=\"right\">车次</th><th align=\"right\">出发日期</th><th align=\"right\">始发站</th><th align=\"right\">发车时间</th><th align=\"right\">抵达日期</th><th align=\"right\">终点站</th><th align=\"right\">抵达时间</th><th align=\"right\">行程时间</th><th align=\"right\">最低票价</th>");
	if (s1)
	{
		printf("<th align=\"right\">硬座余票</th><th align=\"right\">硬座票价</th>");
	}
	if (s2)
	{
		printf("<th align=\"right\">软座余票</th><th align=\"right\">软座票价</th>");
	}
	if (s3)
	{
		printf("<th align=\"right\">硬卧余票</th><th align=\"right\">硬卧票价</th>");
	}
	if (s4)
	{
		printf("<th align=\"right\">软卧余票</th><th align=\"right\">软卧票价</th>");
	}
	printf("</th><th align=\"right\">预定</th></tr>\n");

	for (r = 0; r < num_rows; r++)
	{
		if (r % 2 == 0)
			printf("<tr><td rowspan = 2 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<tr><td rowspan = 2 align=\"right\" style=\"color:black"";""background-color:white\">");
		printf("方案 %d </td>", r + 1);

		for (i = 0; i < 14; i += 2)
		{
			val = PQgetvalue(Q23, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		for (; i <= 16; ++i)
		{
			if (i == 14 || i == 15)
			{
				val = PQgetvalue(Q23, r, i);
				if (r % 2 == 0)
					printf("<td rowspan = 2 align=\"right\" style=\"color:white"";""background-color:black\">");
				else
					printf("<td rowspan = 2 align=\"right\" style=\"color:black"";""background-color:white\">");
				printf("%s", val);
				printf("</td>");
			}
			else if (i == 16)
			{
				if (s1)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 3;
				}

				if (s2)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 3;
				}

				if (s3)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q23, r, i + 4); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q23, r, i + 8); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q23, r, i + 5); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q23, r, i + 9); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 12;
				}

				if (s4)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q23, r, i + 4); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q23, r, i + 5); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
				}
			}
		}

		if (r % 2 == 0)
			printf("<td rowspan = 2 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<td rowspan = 2 align=\"right\" style=\"color:black"";""background-color:white\">");

		val1 = PQgetvalue(Q23, r, 0);
		val2 = PQgetvalue(Q23, r, 4);
		val3 = PQgetvalue(Q23, r, 10);
		val4 = PQgetvalue(Q23, r, 2);
		val5 = PQgetvalue(Q23, r, 1);
		val6 = PQgetvalue(Q23, r, 5);
		val7 = PQgetvalue(Q23, r, 11);
		val8 = PQgetvalue(Q23, r, 3);
		printf("<a href=\"http://localhost/cgi-bin/buy.cgi?1=2&2=%s&3=%s&4=%s&5=%s&6=%s&7=%s&8=%s&9=%s&10=%s&11=%s\" target=\"_blank\">预定</a>", val1, val2, val3, val4, val5, val6, val7, val8, value[12], value[13]); printf("</td>");

		printf("</tr>\n");
		printf("<tr>\n");


		for (i = 1; i < 14; i += 2)
		{
			val = PQgetvalue(Q23, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		i = 18;

		if (s1)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 3;
		}

		if (s2)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 3;
		}

		if (s3)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q23, r, i + 4); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q23, r, i + 8); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q23, r, i + 5); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q23, r, i + 9); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 12;
		}

		if (s4)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q23, r, i + 4); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q23, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q23, r, i + 5); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
		}

		printf("</tr>\n");

	}
	printf("</table>");

	PQclear(Q23);

	PQexec(conn, "drop table temp251;");

miss2:
	if (!k5)
	{
		goto miss2_3;
	}

	if (f){
		if(k1_0 == m){
			k6_1 = (int)ntohl(m+1);
			param_val1_1[3] = (char *)&k6_1;
		}
		PQprepare(conn, "Query_Three1_1", "select d1.train_id as train_id_1, d3.train_id as train_id_2 , d5.train_id as train_id_3,s1.station_name as start_name_1, d1.departing_time as start_time_1, d1.inner_station_id as start_id_1, s2.station_name as end_name_1, d2.arriving_time as end_time_1, d2.inner_station_id as end_id_1, s3.station_name as start_name_2, d3.departing_time as start_time_2, d3.inner_station_id as start_id_2, s4.station_name as end_name_2, d4.arriving_time as end_time_2, d4.inner_station_id as end_id_2, s5.station_name as start_name_3, d5.departing_time as start_time_3, d5.inner_station_id as start_id_3, s6.station_name as end_name_3, d6.arriving_time as end_time_3, d6.inner_station_id as end_id_3, t1.date_id as train_departing_day_1,$3 as departing_day_1, t1.date_id + d2.arriving_day as arriving_day_1, t2.date_id as train_departing_day_2, t2.date_id + d3.departing_day as departing_day_2, t2.date_id + d4.arriving_day as arriving_day_2, t3.date_id as train_departing_day_3, t3.date_id + d5.departing_day as departing_day_3, t3.date_id + d6.arriving_day as arriving_day_3, ((D3.departing_time_number+1440-D2.arriving_time_number)%1440 + (D5.departing_time_number+1440-D4.arriving_time_number)%1440 + (D2.arriving_day-D1.departing_day)*1440 + D2.arriving_time_number - D1.departing_time_number + (D4.arriving_day-D3.departing_day)*1440 + D4.arriving_time_number - D3.departing_time_number + (D6.arriving_day-D5.departing_day)*1440 + D6.arriving_time_number - D5.departing_time_number) as travel_time into temp31 from database1 as d1, database1 as d2,database1 as d3,database1 as d4,database1 as d5,database1 as d6, station as s1, station as s2,station as s3, station as s4,station as s5,station as s6, the_date as t1, the_date as t2,the_date as t3 where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.train_id not in(select train_id from temp13 ) and d1.train_id not in(select train_id_1 from temp23 ) and d1.train_id not in(select train_id_2 from temp23 ) and d3.train_id = d4.train_id and d3.inner_station_id < d4.inner_station_id and d3.train_id not in(select train_id from temp13 ) and d3.train_id not in(select train_id_1 from temp23 ) and d3.train_id not in(select train_id_2 from temp23 ) and d5.train_id = d6.train_id and d5.inner_station_id < d6.inner_station_id and d5.train_id not in(select train_id from temp13 ) and d5.train_id not in(select train_id_1 from temp23 ) and d5.train_id not in(select train_id_2 from temp23 ) and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = s3.city_name and d3.outer_station_id = s3.station_id and d4.outer_station_id = s4.station_id and s4.city_name = s5.city_name and d5.outer_station_id = s5.station_id and d6.outer_station_id = s6.station_id and s6.city_name = $2 and (d3.departing_time_number + 1440 - d2.arriving_time_number)%1440 < 240 and (((d3.departing_time_number+1440-d2.arriving_time_number)%1440>60 and s2.station_id = s3.station_id) or ((d3.departing_time_number+1440-d2.arriving_time_number)%1440>120 and s2.station_id != s3.station_id)) and ((d3.departing_time_number>d2.arriving_time_number and t2.date_id = t1.date_id + d2.arriving_day - d3.departing_day) or (d3.departing_time_number<d2.arriving_time_number and t2.date_id = t1.date_id + D2.arriving_day  + 1 - d3.departing_day)) and (d5.departing_time_number + 1440 - d4.arriving_time_number)%1440 < 240 and (((d5.departing_time_number+1440-d4.arriving_time_number)%1440>60 and s5.station_id = s4.station_id) or ((d5.departing_time_number+1440-d4.arriving_time_number)%1440>120 and s5.station_id != s4.station_id)) and ((d5.departing_time_number>d4.arriving_time_number and t3.date_id = t2.date_id + d4.arriving_day - d5.departing_day) or (d5.departing_time_number<d4.arriving_time_number and t3.date_id = t2.date_id + d4.arriving_day - d5.departing_day + 1)) and t1.date_id = $3 - d1.departing_day and t3.date_id + d6.arriving_day < $4;", 4, paramTypes1_1);
		PQexecPrepared(conn, "Query_Three1_1", 4, (const char **)param_val1_1, param_len1_1, param_format1_1, 0);
	}
	else{
		PQprepare(conn, "Query_Three1", "select d1.train_id as train_id_1, d3.train_id as train_id_2 , d5.train_id as train_id_3,s1.station_name as start_name_1, d1.departing_time as start_time_1, d1.inner_station_id as start_id_1, s2.station_name as end_name_1, d2.arriving_time as end_time_1, d2.inner_station_id as end_id_1, s3.station_name as start_name_2, d3.departing_time as start_time_2, d3.inner_station_id as start_id_2, s4.station_name as end_name_2, d4.arriving_time as end_time_2, d4.inner_station_id as end_id_2, s5.station_name as start_name_3, d5.departing_time as start_time_3, d5.inner_station_id as start_id_3, s6.station_name as end_name_3, d6.arriving_time as end_time_3, d6.inner_station_id as end_id_3, t1.date_id as train_departing_day_1,$3 as departing_day_1, t1.date_id + d2.arriving_day as arriving_day_1, t2.date_id as train_departing_day_2, t2.date_id + d3.departing_day as departing_day_2, t2.date_id + d4.arriving_day as arriving_day_2, t3.date_id as train_departing_day_3, t3.date_id + d5.departing_day as departing_day_3, t3.date_id + d6.arriving_day as arriving_day_3, ((D3.departing_time_number+1440-D2.arriving_time_number)%1440 + (D5.departing_time_number+1440-D4.arriving_time_number)%1440 + (D2.arriving_day-D1.departing_day)*1440 + D2.arriving_time_number - D1.departing_time_number + (D4.arriving_day-D3.departing_day)*1440 + D4.arriving_time_number - D3.departing_time_number + (D6.arriving_day-D5.departing_day)*1440 + D6.arriving_time_number - D5.departing_time_number) as travel_time into temp31 from database1 as d1, database1 as d2,database1 as d3,database1 as d4,database1 as d5,database1 as d6, station as s1, station as s2,station as s3, station as s4,station as s5,station as s6, the_date as t1, the_date as t2,the_date as t3 where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.train_id not in(select train_id from temp13 ) and d1.train_id not in(select train_id_1 from temp23 ) and d1.train_id not in(select train_id_2 from temp23 ) and d3.train_id = d4.train_id and d3.inner_station_id < d4.inner_station_id and d3.train_id not in(select train_id from temp13 ) and d3.train_id not in(select train_id_1 from temp23 ) and d3.train_id not in(select train_id_2 from temp23 ) and d5.train_id = d6.train_id and d5.inner_station_id < d6.inner_station_id and d5.train_id not in(select train_id from temp13 ) and d5.train_id not in(select train_id_1 from temp23 ) and d5.train_id not in(select train_id_2 from temp23 ) and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = s3.city_name and d3.outer_station_id = s3.station_id and d4.outer_station_id = s4.station_id and s4.city_name = s5.city_name and d5.outer_station_id = s5.station_id and d6.outer_station_id = s6.station_id and s6.city_name = $2 and (d3.departing_time_number + 1440 - d2.arriving_time_number)%1440 < 240 and (((d3.departing_time_number+1440-d2.arriving_time_number)%1440>60 and s2.station_id = s3.station_id) or ((d3.departing_time_number+1440-d2.arriving_time_number)%1440>120 and s2.station_id != s3.station_id)) and ((d3.departing_time_number>d2.arriving_time_number and t2.date_id = t1.date_id + d2.arriving_day - d3.departing_day) or (d3.departing_time_number<d2.arriving_time_number and t2.date_id = t1.date_id + D2.arriving_day  + 1 - d3.departing_day)) and (d5.departing_time_number + 1440 - d4.arriving_time_number)%1440 < 240 and (((d5.departing_time_number+1440-d4.arriving_time_number)%1440>60 and s5.station_id = s4.station_id) or ((d5.departing_time_number+1440-d4.arriving_time_number)%1440>120 and s5.station_id != s4.station_id)) and ((d5.departing_time_number>d4.arriving_time_number and t3.date_id = t2.date_id + d4.arriving_day - d5.departing_day) or (d5.departing_time_number<d4.arriving_time_number and t3.date_id = t2.date_id + d4.arriving_day - d5.departing_day + 1)) and t1.date_id = $3 - d1.departing_day;", 3, paramTypes1);
		PQexecPrepared(conn, "Query_Three1", 3, (const char **)param_val1, param_len1, param_format1, 0);
		
	}

	PQprepare(conn, "Query_Three2", "select t.train_id_1, t.train_id_2,t.train_id_3,p1.seat_type as seat_type_1,p3.seat_type as seat_type_2,p5.seat_type as seat_type_3, t.start_name_1, t.start_time_1, t.start_id_1, t.end_name_1, t.end_time_1, t.end_id_1, t.train_departing_day_1, t.departing_day_1,t.arriving_day_1, t.start_name_2, t.start_time_2, t.start_id_2, t.end_name_2, t.end_time_2, t.end_id_2, t.train_departing_day_2, t.departing_day_2, t.arriving_day_2,t.start_name_3, t.start_time_3, t.start_id_3, t.end_name_3, t.end_time_3, t.end_id_3, t.train_departing_day_3, t.departing_day_3, t.arriving_day_3,t.travel_time, p2.price - p1.price as price_1,p4.price - p3.price as price_2,p6.price - p5.price as price_3 into temp32 from temp31 as t, possible_ticket as p1, possible_ticket as p2,possible_ticket as p3, possible_ticket as p4,possible_ticket as p5, possible_ticket as p6 where p1.inner_station_id = t.start_id_1 and p2.inner_station_id = t.end_id_1 and p3.inner_station_id = t.start_id_2 and p4.inner_station_id = t.end_id_2 and p5.inner_station_id = t.start_id_3 and p6.inner_station_id = t.end_id_3 and p1.train_id = t.train_id_1 and p2.train_id = t.train_id_1 and p3.train_id = t.train_id_2 and p4.train_id = t.train_id_2 and p5.train_id = t.train_id_3 and p6.train_id = t.train_id_3 and p1.seat_type = p2.seat_type and p3.seat_type = p4.seat_type and p5.seat_type = p6.seat_type and p1.seat_type in ($1,$2,$3,$4,$5,$6,$7) and p3.seat_type in ($1,$2,$3,$4,$5,$6,$7) and p5.seat_type in ($1,$2,$3,$4,$5,$6,$7);", 7, paramTypes2);
	PQexecPrepared(conn, "Query_Three2", 7, (const char **)param_val2, param_len2, param_format2, 0);
	PQexec(conn, "drop table temp31; select t.train_id_1,t.train_id_2,t.train_id_3,t.seat_type_1,t.seat_type_2,t.seat_type_3,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.start_name_3, t.start_time_3, t.start_id_3, t.end_name_3, t.end_time_3, t.end_id_3, t.train_departing_day_3, t.departing_day_3, t.arriving_day_3,t.price_3, t.travel_time, min(r1.tickets) as tickets_1, min(r2.tickets) as tickets_2, min(r3.tickets) as tickets_3 into temp33 from remaining_ticket as r1,remaining_ticket as r2 ,remaining_ticket as r3,temp32 as t where r1.inner_station_id between t.start_id_1 + 1 and t.end_id_1 and r1.the_day = t.train_departing_day_1 and r1.train_id = t.train_id_1 and r1.seat_type =  t.seat_type_1 and r2.inner_station_id between t.start_id_2 + 1 and t.end_id_2 and r2.the_day = t.train_departing_day_2 and r2.train_id = t.train_id_2 and r2.seat_type =  t.seat_type_2 and r3.inner_station_id between t.start_id_3 + 1 and t.end_id_3 and r3.the_day = t.train_departing_day_3 and r3.train_id = t.train_id_3 and r3.seat_type =  t.seat_type_3 group by t.train_id_1,t.train_id_2,t.train_id_3, t.seat_type_1,t.seat_type_2,t.seat_type_3,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.start_name_3, t.start_time_3, t.start_id_3, t.end_name_3, t.end_time_3, t.end_id_3, t.train_departing_day_3, t.departing_day_3, t.arriving_day_3,t.price_3, t.travel_time; drop table temp32; delete from temp33 where tickets_1 <=0 or tickets_2 <=0 or tickets_3 <=0 ; select t.train_id_1,t.train_id_2,t.train_id_3,t.seat_type_1,t.seat_type_2,t.seat_type_3,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.price_2,t.start_name_3,t.start_time_3,t.end_name_3,t.end_time_3,t.price_3,t.travel_time, t.tickets_1, t.tickets_2,t.tickets_3, d1.actual_date as departing_date_1,d2.actual_date as arriving_date_1,d3.actual_date as departing_date_2,d4.actual_date as arriving_date_2,d5.actual_date as departing_date_3,d5.actual_date as arriving_date_3 into temp34 from temp33 as t, the_date as d1, the_date as d2,the_date as d3,the_date as d4, the_date as d5, the_date as d6 where d1.date_id = t.departing_day_1 and d2.date_id = t.arriving_day_1 and d3.date_id = t.departing_day_2 and d4.date_id = t.arriving_day_2 and d5.date_id = t.departing_day_3 and d6.date_id = t.arriving_day_3; drop table temp33; select distinct t.train_id_1,t.train_id_2,t.train_id_3,t.departing_date_1, t.departing_date_2, t.departing_date_3, t.start_name_1,t.start_name_2, t.start_name_3,t.start_time_1,t.start_time_2,t.start_time_3,t.arriving_date_1,t.arriving_date_2,t.arriving_date_3,t.end_name_1,t.end_name_2,t.end_name_3,t.end_time_1,t.end_time_2,t.end_time_3,t.travel_time into temp35 from temp34 as t; alter table temp35 add Min_Price decimal(5,1) default 9999.9; alter table temp35 add Min_Price_1 decimal(5,1) default 9999.9; alter table temp35 add Min_Price_2 decimal(5,1) default 9999.9; alter table temp35 add Min_Price_3 decimal(5,1) default 9999.9;");

	if (s1)
		PQexec(conn, "alter table temp35 add Hard_Seat_1 integer; alter table temp35 add Hard_Seat_Price_1 decimal(5,1); update temp35 set Hard_Seat_1 = t.tickets_1, Hard_Seat_Price_1 = t.price_1 from temp34 as t where t.train_id_1 = temp35.train_id_1 and t.start_name_1 = temp35.start_name_1 and t.end_name_1 = temp35.end_name_1 and t.seat_type_1 = 'Hard_Seat'; update temp35 set Min_Price_1 = Hard_Seat_Price_1 where Min_Price_1 > Hard_Seat_Price_1; alter table temp35 add Hard_Seat_2 integer; alter table temp35 add Hard_Seat_Price_2 decimal(5,1); update temp35 set Hard_Seat_2 = t.tickets_2, Hard_Seat_Price_2 = t.price_2 from temp34 as t where t.train_id_2 = temp35.train_id_2 and t.start_name_2 = temp35.start_name_2 and t.end_name_2 = temp35.end_name_2 and t.seat_type_2 = 'Hard_Seat'; update temp35 set Min_Price_2 = Hard_Seat_Price_2 where Min_Price_2 > Hard_Seat_Price_2; alter table temp35 add Hard_Seat_3 integer; alter table temp35 add Hard_Seat_Price_3 decimal(5,1); update temp35 set Hard_Seat_3 = t.tickets_3, Hard_Seat_Price_3 = t.price_3 from temp34 as t where t.train_id_3 = temp35.train_id_3 and t.start_name_3 = temp35.start_name_3 and t.end_name_3 = temp35.end_name_3 and t.seat_type_3 = 'Hard_Seat'; update temp35 set Min_Price_3 = Hard_Seat_Price_3 where Min_Price_3 > Hard_Seat_Price_3;");

	if (s2)
		PQexec(conn, "alter table temp35 add Soft_Seat_1 integer; alter table temp35 add Soft_Seat_Price_1 decimal(5,1); update temp35 set Soft_Seat_1 = t.tickets_1, Soft_Seat_Price_1 = t.price_1 from temp34 as t where t.train_id_1 = temp35.train_id_1 and t.start_name_1 = temp35.start_name_1 and t.end_name_1 = temp35.end_name_1 and t.seat_type_1 = 'Soft_Seat'; update temp35 set Min_Price_1 = Soft_Seat_Price_1 where Min_Price_1 > Soft_Seat_Price_1; alter table temp35 add Soft_Seat_2 integer; alter table temp35 add Soft_Seat_Price_2 decimal(5,1); update temp35 set Soft_Seat_2 = t.tickets_2, Soft_Seat_Price_2 = t.price_2 from temp34 as t where t.train_id_2 = temp35.train_id_2 and t.start_name_2 = temp35.start_name_2 and t.end_name_2 = temp35.end_name_2 and t.seat_type_2 = 'Soft_Seat'; update temp35 set Min_Price_2 = Soft_Seat_Price_2 where Min_Price_2 > Soft_Seat_Price_2; alter table temp35 add Soft_Seat_3 integer; alter table temp35 add Soft_Seat_Price_3 decimal(5,1); update temp35 set Soft_Seat_3 = t.tickets_3, Soft_Seat_Price_3 = t.price_3 from temp34 as t where t.train_id_3 = temp35.train_id_3 and t.start_name_3 = temp35.start_name_3 and t.end_name_3 = temp35.end_name_3 and t.seat_type_3 = 'Soft_Seat'; update temp35 set Min_Price_3 = Soft_Seat_Price_3 where Min_Price_3 > Soft_Seat_Price_3;");

	if (s3)
		PQexec(conn, "alter table temp35 add Hard_Up_1 integer; alter table temp35 add Hard_Up_Price_1 decimal(5,1); update temp35 set Hard_Up_1 = t.tickets_1, Hard_Up_Price_1 = t.price_1 from temp34 as t where t.train_id_1 = temp35.train_id_1 and t.start_name_1 = temp35.start_name_1 and t.end_name_1 = temp35.end_name_1 and t.seat_type_1 = 'Hard_Up'; update temp35 set Min_Price_1 = Hard_Up_Price_1 where Min_Price_1 > Hard_Up_Price_1; alter table temp35 add Hard_Up_2 integer; alter table temp35 add Hard_Up_Price_2 decimal(5,1); update temp35 set Hard_Up_2 = t.tickets_2, Hard_Up_Price_2 = t.price_2 from temp34 as t where t.train_id_2 = temp35.train_id_2 and t.start_name_2 = temp35.start_name_2 and t.end_name_2 = temp35.end_name_2 and t.seat_type_2 = 'Hard_Up'; update temp35 set Min_Price_2 = Hard_Up_Price_2 where Min_Price_2 > Hard_Up_Price_2; alter table temp35 add Hard_Up_3 integer; alter table temp35 add Hard_Up_Price_3 decimal(5,1); update temp35 set Hard_Up_3 = t.tickets_3, Hard_Up_Price_3 = t.price_3 from temp34 as t where t.train_id_3 = temp35.train_id_3 and t.start_name_3 = temp35.start_name_3 and t.end_name_3 = temp35.end_name_3 and t.seat_type_3 = 'Hard_Up'; update temp35 set Min_Price_3 = Hard_Up_Price_3 where Min_Price_3 > Hard_Up_Price_3; alter table temp35 add Hard_Middle_1 integer; alter table temp35 add Hard_Middle_Price_1 decimal(5,1); update temp35 set Hard_Middle_1 = t.tickets_1, Hard_Middle_Price_1 = t.price_1 from temp34 as t where t.train_id_1 = temp35.train_id_1 and t.start_name_1 = temp35.start_name_1 and t.end_name_1 = temp35.end_name_1 and t.seat_type_1 = 'Hard_Middle'; update temp35 set Min_Price_1 = Hard_Middle_Price_1 where Min_Price_1 > Hard_Middle_Price_1; alter table temp35 add Hard_Middle_2 integer; alter table temp35 add Hard_Middle_Price_2 decimal(5,1); update temp35 set Hard_Middle_2 = t.tickets_2, Hard_Middle_Price_2 = t.price_2 from temp34 as t where t.train_id_2 = temp35.train_id_2 and t.start_name_2 = temp35.start_name_2 and t.end_name_2 = temp35.end_name_2 and t.seat_type_2 = 'Hard_Middle'; update temp35 set Min_Price_2 = Hard_Middle_Price_2 where Min_Price_2 > Hard_Middle_Price_2; alter table temp35 add Hard_Middle_3 integer; alter table temp35 add Hard_Middle_Price_3 decimal(5,1); update temp35 set Hard_Middle_3 = t.tickets_3, Hard_Middle_Price_3 = t.price_3 from temp34 as t where t.train_id_3 = temp35.train_id_3 and t.start_name_3 = temp35.start_name_3 and t.end_name_3 = temp35.end_name_3 and t.seat_type_3 = 'Hard_Middle'; update temp35 set Min_Price_3 = Hard_Middle_Price_3 where Min_Price_3 > Hard_Middle_Price_3; alter table temp35 add Hard_Down_1 integer; alter table temp35 add Hard_Down_Price_1 decimal(5,1); update temp35 set Hard_Down_1 = t.tickets_1, Hard_Down_Price_1 = t.price_1 from temp34 as t where t.train_id_1 = temp35.train_id_1 and t.start_name_1 = temp35.start_name_1 and t.end_name_1 = temp35.end_name_1 and t.seat_type_1 = 'Hard_Down'; update temp35 set Min_Price_1 = Hard_Down_Price_1 where Min_Price_1 > Hard_Down_Price_1; alter table temp35 add Hard_Down_2 integer; alter table temp35 add Hard_Down_Price_2 decimal(5,1); update temp35 set Hard_Down_2 = t.tickets_2, Hard_Down_Price_2 = t.price_2 from temp34 as t where t.train_id_2 = temp35.train_id_2 and t.start_name_2 = temp35.start_name_2 and t.end_name_2 = temp35.end_name_2 and t.seat_type_2 = 'Hard_Down'; update temp35 set Min_Price_2 = Hard_Down_Price_2 where Min_Price_2 > Hard_Down_Price_2; alter table temp35 add Hard_Down_3 integer; alter table temp35 add Hard_Down_Price_3 decimal(5,1); update temp35 set Hard_Down_3 = t.tickets_3, Hard_Down_Price_3 = t.price_3 from temp34 as t where t.train_id_3 = temp35.train_id_3 and t.start_name_3 = temp35.start_name_3 and t.end_name_3 = temp35.end_name_3 and t.seat_type_3 = 'Hard_Down'; update temp35 set Min_Price_3 = Hard_Down_Price_3 where Min_Price_3 > Hard_Down_Price_3;");

	if (s4)
		PQexec(conn, "alter table temp35 add Soft_Up_1 integer; alter table temp35 add Soft_Up_Price_1 decimal(5,1); update temp35 set Soft_Up_1 = t.tickets_1, Soft_Up_Price_1 = t.price_1 from temp34 as t where t.train_id_1 = temp35.train_id_1 and t.start_name_1 = temp35.start_name_1 and t.end_name_1 = temp35.end_name_1 and t.seat_type_1 = 'Soft_Up'; update temp35 set Min_Price_1 = Soft_Up_Price_1 where Min_Price_1 > Soft_Up_Price_1; alter table temp35 add Soft_Up_2 integer; alter table temp35 add Soft_Up_Price_2 decimal(5,1); update temp35 set Soft_Up_2 = t.tickets_2, Soft_Up_Price_2 = t.price_2 from temp34 as t where t.train_id_2 = temp35.train_id_2 and t.start_name_2 = temp35.start_name_2 and t.end_name_2 = temp35.end_name_2 and t.seat_type_2 = 'Soft_Up'; update temp35 set Min_Price_2 = Soft_Up_Price_2 where Min_Price_2 > Soft_Up_Price_2; alter table temp35 add Soft_Up_3 integer; alter table temp35 add Soft_Up_Price_3 decimal(5,1); update temp35 set Soft_Up_3 = t.tickets_3, Soft_Up_Price_3 = t.price_3 from temp34 as t where t.train_id_3 = temp35.train_id_3 and t.start_name_3 = temp35.start_name_3 and t.end_name_3 = temp35.end_name_3 and t.seat_type_3 = 'Soft_Up'; update temp35 set Min_Price_3 = Soft_Up_Price_3 where Min_Price_3 > Soft_Up_Price_3; alter table temp35 add Soft_Down_1 integer; alter table temp35 add Soft_Down_Price_1 decimal(5,1); update temp35 set Soft_Down_1 = t.tickets_1, Soft_Down_Price_1 = t.price_1 from temp34 as t where t.train_id_1 = temp35.train_id_1 and t.start_name_1 = temp35.start_name_1 and t.end_name_1 = temp35.end_name_1 and t.seat_type_1 = 'Soft_Down'; update temp35 set Min_Price_1 = Soft_Down_Price_1 where Min_Price_1 > Soft_Down_Price_1; alter table temp35 add Soft_Down_2 integer; alter table temp35 add Soft_Down_Price_2 decimal(5,1); update temp35 set Soft_Down_2 = t.tickets_2, Soft_Down_Price_2 = t.price_2 from temp34 as t where t.train_id_2 = temp35.train_id_2 and t.start_name_2 = temp35.start_name_2 and t.end_name_2 = temp35.end_name_2 and t.seat_type_2 = 'Soft_Down'; update temp35 set Min_Price_2 = Soft_Down_Price_2 where Min_Price_2 > Soft_Down_Price_2; alter table temp35 add Soft_Down_3 integer; alter table temp35 add Soft_Down_Price_3 decimal(5,1); update temp35 set Soft_Down_3 = t.tickets_3, Soft_Down_Price_3 = t.price_3 from temp34 as t where t.train_id_3 = temp35.train_id_3 and t.start_name_3 = temp35.start_name_3 and t.end_name_3 = temp35.end_name_3 and t.seat_type_3 = 'Soft_Down'; update temp35 set Min_Price_3 = Soft_Down_Price_3 where Min_Price_3 > Soft_Down_Price_3;");

	PQexec(conn, "update temp35 set Min_Price = Min_Price_1 + Min_Price_2 + Min_Price_3; alter table temp35 drop Min_Price_1; alter table temp35 drop Min_Price_2; alter table temp35 drop Min_Price_3; drop table temp34;");

	PQexec(conn, "drop table temp13;");

	PQexec(conn, "drop table temp23;");

	PGresult *Q33;

	if (k2 == 1)
		Q33 = PQexec(conn, "select * from temp35 order by Min_Price;");
	else if (k2 == 2)
		Q33 = PQexec(conn, "select * from temp35 order by travel_time;");
	else if (k2 == 3)
		Q33 = PQexec(conn, "select * from temp35 order by start_time_1;");

	num_rows = PQntuples(Q33);
	if (num_rows == 0)
		printf("非法输入,请再次尝试 或 转乘两次无结果\n");

	num_cols = PQnfields(Q33);
	printf("<p align=\"center\" style=\"font-size:18px\">");
	if(f && k3) printf("<a href=\"#11\">往返程-直达</a>&nbsp&nbsp&nbsp");
	else if (k3) printf("<a href=\"#1\">直达</a>&nbsp&nbsp&nbsp");
	if (k4) printf("<a href=\"#2\">去程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (f && k4) printf("<a href=\"#21\">返程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (k5) printf("<a href=\"#3\">去程-转乘二次</a>&nbsp&nbsp&nbsp");
	if (f && k5) printf("<a href=\"#31\">返程-转乘二次</a>&nbsp&nbsp&nbsp");
	printf("</p>");
	printf("<table border=2 class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\"><a name=\"3\">转乘两次:车次信息</a></caption>\n<tr><th align=\"right\">乘车方案编号</th><th align=\"right\">车次</th><th align=\"right\">出发日期</th><th align=\"right\">始发站</th><th align=\"right\">发车时间</th><th align=\"right\">抵达日期</th><th align=\"right\">终点站</th><th align=\"right\">抵达时间</th><th align=\"right\">行程时间</th><th align=\"right\">最低票价</th>");

	if (s1)
	{
		printf("<th align=\"right\">硬座余票</th><th align=\"right\">硬座票价</th>");
	}
	if (s2)
	{
		printf("<th align=\"right\">软座余票</th><th align=\"right\">软座票价</th>");
	}
	if (s3)
	{
		printf("<th align=\"right\">硬卧余票</th><th align=\"right\">硬卧票价</th>");
	}
	if (s4)
	{
		printf("<th align=\"right\">软卧余票</th><th align=\"right\">软卧票价</th>");
	}

	printf("</th><th align=\"right\">预定</th></tr>\n");

	for (r = 0; r < num_rows; r++)
	{
		if (r % 2 == 0)
			printf("<tr><td rowspan = 3 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<tr><td rowspan = 3 align=\"right\" style=\"color:black"";""background-color:white\">");
		printf("方案 %d </td>", r + 1);

		for (i = 0; i < 21; i += 3)
		{
			val = PQgetvalue(Q33, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		for (; i <= 23; ++i)
		{
			if (i == 21 || i == 22) {
				val = PQgetvalue(Q33, r, i);
				if (r % 2 == 0)
					printf("<td rowspan = 3 align=\"right\" style=\"color:white"";""background-color:black\">");
				else
					printf("<td rowspan = 3 align=\"right\" style=\"color:black"";""background-color:white\">");
				printf("%s", val);
				printf("</td>");
			}
			else if (i == 23)
			{
				if (s1)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 5;
				}

				if (s2)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 5;
				}

				if (s3)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q33, r, i + 6); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q33, r, i + 12); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q33, r, i + 7); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q33, r, i + 13); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 18;
				}

				if (s4)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q33, r, i + 6); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q33, r, i + 7); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
				}
			}
		}

		if (r % 2 == 0)
			printf("<td rowspan = 3 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<td rowspan = 3 align=\"right\" style=\"color:black"";""background-color:white\">");

		val1 = PQgetvalue(Q33, r, 0);
		val2 = PQgetvalue(Q33, r, 6);
		val3 = PQgetvalue(Q33, r, 15);
		val4 = PQgetvalue(Q33, r, 3);
		val5 = PQgetvalue(Q33, r, 1);
		val6 = PQgetvalue(Q33, r, 7);
		val7 = PQgetvalue(Q33, r, 16);
		val8 = PQgetvalue(Q33, r, 4);
		val9 = PQgetvalue(Q33, r, 2);
		val10 = PQgetvalue(Q33, r, 8);
		val11 = PQgetvalue(Q33, r, 17);
		val12 = PQgetvalue(Q33, r, 5);
		printf("<a href=\"http://localhost/cgi-bin/buy.cgi?1=3&2=%s&3=%s&4=%s&5=%s&6=%s&7=%s&8=%s&9=%s&10=%s&11=%s&12=%s&13=%s&14=%s&15=%s\" target=\"_blank\">预定</a>", val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, value[12], value[13]); printf("</td>");

		printf("</tr>\n");
		printf("<tr>\n");


		for (i = 1; i < 21; i += 3)
		{
			val = PQgetvalue(Q33, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		i = 25;

		if (s1)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s2)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s3)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 12); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 13); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 18;
		}

		if (s4)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
		}
		printf("</tr>\n");
		printf("<tr>\n");

		for (i = 2; i < 21; i += 3)
		{
			val = PQgetvalue(Q33, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		i = 27;

		if (s1)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s2)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s3)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 12); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 13); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 18;
		}

		if (s4)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
		}
		printf("</tr>\n");

	}
	printf("</table>");

	PQclear(Q33);

	PQexec(conn, "drop table temp35;");

	if (!f)
	{
		goto miss2_3;
	}

	PQprepare(conn, "Query_Three1_0", "select d1.train_id as train_id_1, d3.train_id as train_id_2 , d5.train_id as train_id_3,s1.station_name as start_name_1, d1.departing_time as start_time_1, d1.inner_station_id as start_id_1, s2.station_name as end_name_1, d2.arriving_time as end_time_1, d2.inner_station_id as end_id_1, s3.station_name as start_name_2, d3.departing_time as start_time_2, d3.inner_station_id as start_id_2, s4.station_name as end_name_2, d4.arriving_time as end_time_2, d4.inner_station_id as end_id_2, s5.station_name as start_name_3, d5.departing_time as start_time_3, d5.inner_station_id as start_id_3, s6.station_name as end_name_3, d6.arriving_time as end_time_3, d6.inner_station_id as end_id_3, t1.date_id as train_departing_day_1,$3 as departing_day_1, t1.date_id + d2.arriving_day as arriving_day_1, t2.date_id as train_departing_day_2, t2.date_id + d3.departing_day as departing_day_2, t2.date_id + d4.arriving_day as arriving_day_2, t3.date_id as train_departing_day_3, t3.date_id + d5.departing_day as departing_day_3, t3.date_id + d6.arriving_day as arriving_day_3, ((D3.departing_time_number+1440-D2.arriving_time_number)%1440 + (D5.departing_time_number+1440-D4.arriving_time_number)%1440 + (D2.arriving_day-D1.departing_day)*1440 + D2.arriving_time_number - D1.departing_time_number + (D4.arriving_day-D3.departing_day)*1440 + D4.arriving_time_number - D3.departing_time_number + (D6.arriving_day-D5.departing_day)*1440 + D6.arriving_time_number - D5.departing_time_number) as travel_time into temp311 from database1 as d1, database1 as d2,database1 as d3,database1 as d4,database1 as d5,database1 as d6, station as s1, station as s2,station as s3, station as s4,station as s5,station as s6, the_date as t1, the_date as t2,the_date as t3 where d1.train_id = d2.train_id and d1.inner_station_id < d2.inner_station_id and d1.train_id not in(select train_id from temp131 ) and d1.train_id not in(select train_id_1 from temp231 ) and d1.train_id not in(select train_id_2 from temp231 ) and d3.train_id = d4.train_id and d3.inner_station_id < d4.inner_station_id and d3.train_id not in(select train_id from temp131 ) and d3.train_id not in(select train_id_1 from temp231 ) and d3.train_id not in(select train_id_2 from temp231 ) and d5.train_id = d6.train_id and d5.inner_station_id < d6.inner_station_id and d5.train_id not in(select train_id from temp131 ) and d5.train_id not in(select train_id_1 from temp231 ) and d5.train_id not in(select train_id_2 from temp231 ) and d1.outer_station_id = s1.station_id and s1.city_name = $1 and d2.outer_station_id = s2.station_id and s2.city_name = s3.city_name and d3.outer_station_id = s3.station_id and d4.outer_station_id = s4.station_id and s4.city_name = s5.city_name and d5.outer_station_id = s5.station_id and d6.outer_station_id = s6.station_id and s6.city_name = $2 and (d3.departing_time_number + 1440 - d2.arriving_time_number)%1440 < 240 and (((d3.departing_time_number+1440-d2.arriving_time_number)%1440>60 and s2.station_id = s3.station_id) or ((d3.departing_time_number+1440-d2.arriving_time_number)%1440>120 and s2.station_id != s3.station_id)) and ((d3.departing_time_number>d2.arriving_time_number and t2.date_id = t1.date_id + d2.arriving_day - d3.departing_day) or (d3.departing_time_number<d2.arriving_time_number and t2.date_id = t1.date_id + D2.arriving_day  + 1 - d3.departing_day)) and (d5.departing_time_number + 1440 - d4.arriving_time_number)%1440 < 240 and (((d5.departing_time_number+1440-d4.arriving_time_number)%1440>60 and s5.station_id = s4.station_id) or ((d5.departing_time_number+1440-d4.arriving_time_number)%1440>120 and s5.station_id != s4.station_id)) and ((d5.departing_time_number>d4.arriving_time_number and t3.date_id = t2.date_id + d4.arriving_day - d5.departing_day) or (d5.departing_time_number<d4.arriving_time_number and t3.date_id = t2.date_id + d4.arriving_day - d5.departing_day + 1)) and t1.date_id = $3 - d1.departing_day;", 3, paramTypes1);
	
	PQexecPrepared(conn, "Query_Three1_0", 3, (const char **)param_val1_0, param_len1, param_format1, 0);

	PQprepare(conn, "Query_Three2_0", "select t.train_id_1, t.train_id_2,t.train_id_3,p1.seat_type as seat_type_1,p3.seat_type as seat_type_2,p5.seat_type as seat_type_3, t.start_name_1, t.start_time_1, t.start_id_1, t.end_name_1, t.end_time_1, t.end_id_1, t.train_departing_day_1, t.departing_day_1,t.arriving_day_1, t.start_name_2, t.start_time_2, t.start_id_2, t.end_name_2, t.end_time_2, t.end_id_2, t.train_departing_day_2, t.departing_day_2, t.arriving_day_2,t.start_name_3, t.start_time_3, t.start_id_3, t.end_name_3, t.end_time_3, t.end_id_3, t.train_departing_day_3, t.departing_day_3, t.arriving_day_3,t.travel_time, p2.price - p1.price as price_1,p4.price - p3.price as price_2,p6.price - p5.price as price_3 into temp321 from temp311 as t, possible_ticket as p1, possible_ticket as p2,possible_ticket as p3, possible_ticket as p4,possible_ticket as p5, possible_ticket as p6 where p1.inner_station_id = t.start_id_1 and p2.inner_station_id = t.end_id_1 and p3.inner_station_id = t.start_id_2 and p4.inner_station_id = t.end_id_2 and p5.inner_station_id = t.start_id_3 and p6.inner_station_id = t.end_id_3 and p1.train_id = t.train_id_1 and p2.train_id = t.train_id_1 and p3.train_id = t.train_id_2 and p4.train_id = t.train_id_2 and p5.train_id = t.train_id_3 and p6.train_id = t.train_id_3 and p1.seat_type = p2.seat_type and p3.seat_type = p4.seat_type and p5.seat_type = p6.seat_type and p1.seat_type in ($1,$2,$3,$4,$5,$6,$7) and p3.seat_type in ($1,$2,$3,$4,$5,$6,$7) and p5.seat_type in ($1,$2,$3,$4,$5,$6,$7);", 7, paramTypes2);

	PQexecPrepared(conn, "Query_Three2_0", 7, (const char **)param_val2, param_len2, param_format2, 0);

	PQexec(conn, "drop table temp311; select t.train_id_1,t.train_id_2,t.train_id_3,t.seat_type_1,t.seat_type_2,t.seat_type_3,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.start_name_3, t.start_time_3, t.start_id_3, t.end_name_3, t.end_time_3, t.end_id_3, t.train_departing_day_3, t.departing_day_3, t.arriving_day_3,t.price_3, t.travel_time, min(r1.tickets) as tickets_1, min(r2.tickets) as tickets_2, min(r3.tickets) as tickets_3 into temp331 from remaining_ticket as r1,remaining_ticket as r2 ,remaining_ticket as r3,temp321 as t where r1.inner_station_id between t.start_id_1 + 1 and t.end_id_1 and r1.the_day = t.train_departing_day_1 and r1.train_id = t.train_id_1 and r1.seat_type =  t.seat_type_1 and r2.inner_station_id between t.start_id_2 + 1 and t.end_id_2 and r2.the_day = t.train_departing_day_2 and r2.train_id = t.train_id_2 and r2.seat_type =  t.seat_type_2 and r3.inner_station_id between t.start_id_3 + 1 and t.end_id_3 and r3.the_day = t.train_departing_day_3 and r3.train_id = t.train_id_3 and r3.seat_type =  t.seat_type_3 group by t.train_id_1,t.train_id_2,t.train_id_3, t.seat_type_1,t.seat_type_2,t.seat_type_3,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.departing_day_1,t.arriving_day_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.departing_day_2,t.arriving_day_2,t.price_2,t.start_name_3, t.start_time_3, t.start_id_3, t.end_name_3, t.end_time_3, t.end_id_3, t.train_departing_day_3, t.departing_day_3, t.arriving_day_3,t.price_3, t.travel_time; drop table temp321; delete from temp331 where tickets_1 <=0 or tickets_2 <=0 or tickets_3 <=0 ; select t.train_id_1,t.train_id_2,t.train_id_3,t.seat_type_1,t.seat_type_2,t.seat_type_3,t.start_name_1,t.start_time_1,t.end_name_1,t.end_time_1,t.price_1,t.start_name_2,t.start_time_2,t.end_name_2,t.end_time_2,t.price_2,t.start_name_3,t.start_time_3,t.end_name_3,t.end_time_3,t.price_3,t.travel_time, t.tickets_1, t.tickets_2,t.tickets_3, d1.actual_date as departing_date_1,d2.actual_date as arriving_date_1,d3.actual_date as departing_date_2,d4.actual_date as arriving_date_2,d5.actual_date as departing_date_3,d5.actual_date as arriving_date_3 into temp341 from temp331 as t, the_date as d1, the_date as d2,the_date as d3,the_date as d4, the_date as d5, the_date as d6 where d1.date_id = t.departing_day_1 and d2.date_id = t.arriving_day_1 and d3.date_id = t.departing_day_2 and d4.date_id = t.arriving_day_2 and d5.date_id = t.departing_day_3 and d6.date_id = t.arriving_day_3; drop table temp331; select distinct t.train_id_1,t.train_id_2,t.train_id_3,t.departing_date_1, t.departing_date_2, t.departing_date_3, t.start_name_1,t.start_name_2, t.start_name_3,t.start_time_1,t.start_time_2,t.start_time_3,t.arriving_date_1,t.arriving_date_2,t.arriving_date_3,t.end_name_1,t.end_name_2,t.end_name_3,t.end_time_1,t.end_time_2,t.end_time_3,t.travel_time into temp351 from temp341 as t; alter table temp351 add Min_Price decimal(5,1) default 9999.9; alter table temp351 add Min_Price_1 decimal(5,1) default 9999.9; alter table temp351 add Min_Price_2 decimal(5,1) default 9999.9; alter table temp351 add Min_Price_3 decimal(5,1) default 9999.9;");

	if (s1)
		PQexec(conn, "alter table temp351 add Hard_Seat_1 integer; alter table temp351 add Hard_Seat_Price_1 decimal(5,1); update temp351 set Hard_Seat_1 = t.tickets_1, Hard_Seat_Price_1 = t.price_1 from temp341 as t where t.train_id_1 = temp351.train_id_1 and t.start_name_1 = temp351.start_name_1 and t.end_name_1 = temp351.end_name_1 and t.seat_type_1 = 'Hard_Seat'; update temp351 set Min_Price_1 = Hard_Seat_Price_1 where Min_Price_1 > Hard_Seat_Price_1; alter table temp351 add Hard_Seat_2 integer; alter table temp351 add Hard_Seat_Price_2 decimal(5,1); update temp351 set Hard_Seat_2 = t.tickets_2, Hard_Seat_Price_2 = t.price_2 from temp341 as t where t.train_id_2 = temp351.train_id_2 and t.start_name_2 = temp351.start_name_2 and t.end_name_2 = temp351.end_name_2 and t.seat_type_2 = 'Hard_Seat'; update temp351 set Min_Price_2 = Hard_Seat_Price_2 where Min_Price_2 > Hard_Seat_Price_2; alter table temp351 add Hard_Seat_3 integer; alter table temp351 add Hard_Seat_Price_3 decimal(5,1); update temp351 set Hard_Seat_3 = t.tickets_3, Hard_Seat_Price_3 = t.price_3 from temp341 as t where t.train_id_3 = temp351.train_id_3 and t.start_name_3 = temp351.start_name_3 and t.end_name_3 = temp351.end_name_3 and t.seat_type_3 = 'Hard_Seat'; update temp351 set Min_Price_3 = Hard_Seat_Price_3 where Min_Price_3 > Hard_Seat_Price_3;");

	if (s2)
		PQexec(conn, "alter table temp351 add Soft_Seat_1 integer; alter table temp351 add Soft_Seat_Price_1 decimal(5,1); update temp351 set Soft_Seat_1 = t.tickets_1, Soft_Seat_Price_1 = t.price_1 from temp341 as t where t.train_id_1 = temp351.train_id_1 and t.start_name_1 = temp351.start_name_1 and t.end_name_1 = temp351.end_name_1 and t.seat_type_1 = 'Soft_Seat'; update temp351 set Min_Price_1 = Soft_Seat_Price_1 where Min_Price_1 > Soft_Seat_Price_1; alter table temp351 add Soft_Seat_2 integer; alter table temp351 add Soft_Seat_Price_2 decimal(5,1); update temp351 set Soft_Seat_2 = t.tickets_2, Soft_Seat_Price_2 = t.price_2 from temp341 as t where t.train_id_2 = temp351.train_id_2 and t.start_name_2 = temp351.start_name_2 and t.end_name_2 = temp351.end_name_2 and t.seat_type_2 = 'Soft_Seat'; update temp351 set Min_Price_2 = Soft_Seat_Price_2 where Min_Price_2 > Soft_Seat_Price_2; alter table temp351 add Soft_Seat_3 integer; alter table temp351 add Soft_Seat_Price_3 decimal(5,1); update temp351 set Soft_Seat_3 = t.tickets_3, Soft_Seat_Price_3 = t.price_3 from temp341 as t where t.train_id_3 = temp351.train_id_3 and t.start_name_3 = temp351.start_name_3 and t.end_name_3 = temp351.end_name_3 and t.seat_type_3 = 'Soft_Seat'; update temp351 set Min_Price_3 = Soft_Seat_Price_3 where Min_Price_3 > Soft_Seat_Price_3;");

	if (s3)
		PQexec(conn, "alter table temp351 add Hard_Up_1 integer; alter table temp351 add Hard_Up_Price_1 decimal(5,1); update temp351 set Hard_Up_1 = t.tickets_1, Hard_Up_Price_1 = t.price_1 from temp341 as t where t.train_id_1 = temp351.train_id_1 and t.start_name_1 = temp351.start_name_1 and t.end_name_1 = temp351.end_name_1 and t.seat_type_1 = 'Hard_Up'; update temp351 set Min_Price_1 = Hard_Up_Price_1 where Min_Price_1 > Hard_Up_Price_1; alter table temp351 add Hard_Up_2 integer; alter table temp351 add Hard_Up_Price_2 decimal(5,1); update temp351 set Hard_Up_2 = t.tickets_2, Hard_Up_Price_2 = t.price_2 from temp341 as t where t.train_id_2 = temp351.train_id_2 and t.start_name_2 = temp351.start_name_2 and t.end_name_2 = temp351.end_name_2 and t.seat_type_2 = 'Hard_Up'; update temp351 set Min_Price_2 = Hard_Up_Price_2 where Min_Price_2 > Hard_Up_Price_2; alter table temp351 add Hard_Up_3 integer; alter table temp351 add Hard_Up_Price_3 decimal(5,1); update temp351 set Hard_Up_3 = t.tickets_3, Hard_Up_Price_3 = t.price_3 from temp341 as t where t.train_id_3 = temp351.train_id_3 and t.start_name_3 = temp351.start_name_3 and t.end_name_3 = temp351.end_name_3 and t.seat_type_3 = 'Hard_Up'; update temp351 set Min_Price_3 = Hard_Up_Price_3 where Min_Price_3 > Hard_Up_Price_3; alter table temp351 add Hard_Middle_1 integer; alter table temp351 add Hard_Middle_Price_1 decimal(5,1); update temp351 set Hard_Middle_1 = t.tickets_1, Hard_Middle_Price_1 = t.price_1 from temp341 as t where t.train_id_1 = temp351.train_id_1 and t.start_name_1 = temp351.start_name_1 and t.end_name_1 = temp351.end_name_1 and t.seat_type_1 = 'Hard_Middle'; update temp351 set Min_Price_1 = Hard_Middle_Price_1 where Min_Price_1 > Hard_Middle_Price_1; alter table temp351 add Hard_Middle_2 integer; alter table temp351 add Hard_Middle_Price_2 decimal(5,1); update temp351 set Hard_Middle_2 = t.tickets_2, Hard_Middle_Price_2 = t.price_2 from temp341 as t where t.train_id_2 = temp351.train_id_2 and t.start_name_2 = temp351.start_name_2 and t.end_name_2 = temp351.end_name_2 and t.seat_type_2 = 'Hard_Middle'; update temp351 set Min_Price_2 = Hard_Middle_Price_2 where Min_Price_2 > Hard_Middle_Price_2; alter table temp351 add Hard_Middle_3 integer; alter table temp351 add Hard_Middle_Price_3 decimal(5,1); update temp351 set Hard_Middle_3 = t.tickets_3, Hard_Middle_Price_3 = t.price_3 from temp341 as t where t.train_id_3 = temp351.train_id_3 and t.start_name_3 = temp351.start_name_3 and t.end_name_3 = temp351.end_name_3 and t.seat_type_3 = 'Hard_Middle'; update temp351 set Min_Price_3 = Hard_Middle_Price_3 where Min_Price_3 > Hard_Middle_Price_3; alter table temp351 add Hard_Down_1 integer; alter table temp351 add Hard_Down_Price_1 decimal(5,1); update temp351 set Hard_Down_1 = t.tickets_1, Hard_Down_Price_1 = t.price_1 from temp341 as t where t.train_id_1 = temp351.train_id_1 and t.start_name_1 = temp351.start_name_1 and t.end_name_1 = temp351.end_name_1 and t.seat_type_1 = 'Hard_Down'; update temp351 set Min_Price_1 = Hard_Down_Price_1 where Min_Price_1 > Hard_Down_Price_1; alter table temp351 add Hard_Down_2 integer; alter table temp351 add Hard_Down_Price_2 decimal(5,1); update temp351 set Hard_Down_2 = t.tickets_2, Hard_Down_Price_2 = t.price_2 from temp341 as t where t.train_id_2 = temp351.train_id_2 and t.start_name_2 = temp351.start_name_2 and t.end_name_2 = temp351.end_name_2 and t.seat_type_2 = 'Hard_Down'; update temp351 set Min_Price_2 = Hard_Down_Price_2 where Min_Price_2 > Hard_Down_Price_2; alter table temp351 add Hard_Down_3 integer; alter table temp351 add Hard_Down_Price_3 decimal(5,1); update temp351 set Hard_Down_3 = t.tickets_3, Hard_Down_Price_3 = t.price_3 from temp341 as t where t.train_id_3 = temp351.train_id_3 and t.start_name_3 = temp351.start_name_3 and t.end_name_3 = temp351.end_name_3 and t.seat_type_3 = 'Hard_Down'; update temp351 set Min_Price_3 = Hard_Down_Price_3 where Min_Price_3 > Hard_Down_Price_3;");

	if (s4)
		PQexec(conn, "alter table temp351 add Soft_Up_1 integer; alter table temp351 add Soft_Up_Price_1 decimal(5,1); update temp351 set Soft_Up_1 = t.tickets_1, Soft_Up_Price_1 = t.price_1 from temp341 as t where t.train_id_1 = temp351.train_id_1 and t.start_name_1 = temp351.start_name_1 and t.end_name_1 = temp351.end_name_1 and t.seat_type_1 = 'Soft_Up'; update temp351 set Min_Price_1 = Soft_Up_Price_1 where Min_Price_1 > Soft_Up_Price_1; alter table temp351 add Soft_Up_2 integer; alter table temp351 add Soft_Up_Price_2 decimal(5,1); update temp351 set Soft_Up_2 = t.tickets_2, Soft_Up_Price_2 = t.price_2 from temp341 as t where t.train_id_2 = temp351.train_id_2 and t.start_name_2 = temp351.start_name_2 and t.end_name_2 = temp351.end_name_2 and t.seat_type_2 = 'Soft_Up'; update temp351 set Min_Price_2 = Soft_Up_Price_2 where Min_Price_2 > Soft_Up_Price_2; alter table temp351 add Soft_Up_3 integer; alter table temp351 add Soft_Up_Price_3 decimal(5,1); update temp351 set Soft_Up_3 = t.tickets_3, Soft_Up_Price_3 = t.price_3 from temp341 as t where t.train_id_3 = temp351.train_id_3 and t.start_name_3 = temp351.start_name_3 and t.end_name_3 = temp351.end_name_3 and t.seat_type_3 = 'Soft_Up'; update temp351 set Min_Price_3 = Soft_Up_Price_3 where Min_Price_3 > Soft_Up_Price_3; alter table temp351 add Soft_Down_1 integer; alter table temp351 add Soft_Down_Price_1 decimal(5,1); update temp351 set Soft_Down_1 = t.tickets_1, Soft_Down_Price_1 = t.price_1 from temp341 as t where t.train_id_1 = temp351.train_id_1 and t.start_name_1 = temp351.start_name_1 and t.end_name_1 = temp351.end_name_1 and t.seat_type_1 = 'Soft_Down'; update temp351 set Min_Price_1 = Soft_Down_Price_1 where Min_Price_1 > Soft_Down_Price_1; alter table temp351 add Soft_Down_2 integer; alter table temp351 add Soft_Down_Price_2 decimal(5,1); update temp351 set Soft_Down_2 = t.tickets_2, Soft_Down_Price_2 = t.price_2 from temp341 as t where t.train_id_2 = temp351.train_id_2 and t.start_name_2 = temp351.start_name_2 and t.end_name_2 = temp351.end_name_2 and t.seat_type_2 = 'Soft_Down'; update temp351 set Min_Price_2 = Soft_Down_Price_2 where Min_Price_2 > Soft_Down_Price_2; alter table temp351 add Soft_Down_3 integer; alter table temp351 add Soft_Down_Price_3 decimal(5,1); update temp351 set Soft_Down_3 = t.tickets_3, Soft_Down_Price_3 = t.price_3 from temp341 as t where t.train_id_3 = temp351.train_id_3 and t.start_name_3 = temp351.start_name_3 and t.end_name_3 = temp351.end_name_3 and t.seat_type_3 = 'Soft_Down'; update temp351 set Min_Price_3 = Soft_Down_Price_3 where Min_Price_3 > Soft_Down_Price_3;");

	PQexec(conn, "update temp351 set Min_Price = Min_Price_1 + Min_Price_2 + Min_Price_3; alter table temp351 drop Min_Price_1; alter table temp351 drop Min_Price_2; alter table temp351 drop Min_Price_3; drop table temp341;");

	PQexec(conn, "drop table temp131;");

	PQexec(conn, "drop table temp231;");

	if (k2 == 1)
		Q33 = PQexec(conn, "select * from temp351 order by Min_Price;");
	else if (k2 == 2)
		Q33 = PQexec(conn, "select * from temp351 order by travel_time;");
	else if (k2 == 3)
		Q33 = PQexec(conn, "select * from temp351 order by start_time_1;");

	num_rows = PQntuples(Q33);
	if (num_rows == 0)
		printf("非法输入,请再次尝试 或 转乘两次返程无结果\n");

	num_cols = PQnfields(Q33);
	printf("<p align=\"center\" style=\"font-size:18px\">");
	if(f && k3) printf("<a href=\"#11\">往返程-直达</a>&nbsp&nbsp&nbsp");
	else if (k3) printf("<a href=\"#1\">直达</a>&nbsp&nbsp&nbsp");
	if (k4) printf("<a href=\"#2\">去程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (f && k4) printf("<a href=\"#21\">返程-转乘一次</a>&nbsp&nbsp&nbsp");
	if (k5) printf("<a href=\"#3\">去程-转乘二次</a>&nbsp&nbsp&nbsp");
	if (f && k5) printf("<a href=\"#31\">返程-转乘二次</a>&nbsp&nbsp&nbsp");
	printf("</p>");
	printf("<table border=2 class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\"><a name=\"31\">返程-转乘两次:车次信息</a></caption>\n<tr><th align=\"right\">乘车方案编号</th><th align=\"right\">车次</th><th align=\"right\">出发日期</th><th align=\"right\">始发站</th><th align=\"right\">发车时间</th><th align=\"right\">抵达日期</th><th align=\"right\">终点站</th><th align=\"right\">抵达时间</th><th align=\"right\">行程时间</th><th align=\"right\">最低票价</th>");

	if (s1)
	{
		printf("<th align=\"right\">硬座余票</th><th align=\"right\">硬座票价</th>");
	}
	if (s2)
	{
		printf("<th align=\"right\">软座余票</th><th align=\"right\">软座票价</th>");
	}
	if (s3)
	{
		printf("<th align=\"right\">硬卧余票</th><th align=\"right\">硬卧票价</th>");
	}
	if (s4)
	{
		printf("<th align=\"right\">软卧余票</th><th align=\"right\">软卧票价</th>");
	}

	printf("</th><th align=\"right\">预定</th></tr>\n");

	for (r = 0; r < num_rows; r++)
	{
		if (r % 2 == 0)
			printf("<tr><td rowspan = 3 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<tr><td rowspan = 3 align=\"right\" style=\"color:black"";""background-color:white\">");
		printf("方案 %d </td>", r + 1);

		for (i = 0; i < 21; i += 3)
		{
			val = PQgetvalue(Q33, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		for (; i <= 23; ++i)
		{
			if (i == 21 || i == 22) {
				val = PQgetvalue(Q33, r, i);
				if (r % 2 == 0)
					printf("<td rowspan = 3 align=\"right\" style=\"color:white"";""background-color:black\">");
				else
					printf("<td rowspan = 3 align=\"right\" style=\"color:black"";""background-color:white\">");
				printf("%s", val);
				printf("</td>");
			}
			else if (i == 23)
			{
				if (s1)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 5;
				}

				if (s2)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i++);
					printf("%s ", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i);
					printf("%s ", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 5;
				}

				if (s3)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q33, r, i + 6); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q33, r, i + 12); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q33, r, i + 7); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q33, r, i + 13); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
					i += 18;
				}

				if (s4)
				{
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
					val = PQgetvalue(Q33, r, i + 6); printf("%s", (val[0] != '\0') ? val : "--");
					printf("</td>");
					if (r % 2 == 0)
						printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
					else
						printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
					val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
					val = PQgetvalue(Q33, r, i + 7); printf("%s", (val[0] != '\0') ? val : "—");
					printf("</td>");
				}
			}
		}

		if (r % 2 == 0)
			printf("<td rowspan = 3 align=\"right\" style=\"color:white"";""background-color:black\">");
		else
			printf("<td rowspan = 3 align=\"right\" style=\"color:black"";""background-color:white\">");

		val1 = PQgetvalue(Q33, r, 0);
		val2 = PQgetvalue(Q33, r, 6);
		val3 = PQgetvalue(Q33, r, 15);
		val4 = PQgetvalue(Q33, r, 3);
		val5 = PQgetvalue(Q33, r, 1);
		val6 = PQgetvalue(Q33, r, 7);
		val7 = PQgetvalue(Q33, r, 16);
		val8 = PQgetvalue(Q33, r, 4);
		val9 = PQgetvalue(Q33, r, 2);
		val10 = PQgetvalue(Q33, r, 8);
		val11 = PQgetvalue(Q33, r, 17);
		val12 = PQgetvalue(Q33, r, 5);
		printf("<a href=\"http://localhost/cgi-bin/buy.cgi?1=3&2=%s&3=%s&4=%s&5=%s&6=%s&7=%s&8=%s&9=%s&10=%s&11=%s&12=%s&13=%s&14=%s&15=%s\" target=\"_blank\">预定</a>", val1, val2, val3, val4, val5, val6, val7, val8, val9, val10, val11, val12, value[12], value[13]); printf("</td>");

		printf("</tr>\n");
		printf("<tr>\n");


		for (i = 1; i < 21; i += 3)
		{
			val = PQgetvalue(Q33, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		i = 25;

		if (s1)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s2)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s3)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 12); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 13); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 18;
		}

		if (s4)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
		}
		printf("</tr>\n");
		printf("<tr>\n");

		for (i = 2; i < 21; i += 3)
		{
			val = PQgetvalue(Q33, r, i);
			if (r % 2 == 0) printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			printf("%s", val);
			printf("</td>");
		}

		i = 27;

		if (s1)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s2)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i++);
			printf("%s ", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i);
			printf("%s ", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 5;
		}

		if (s3)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 12); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 13); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
			i += 18;
		}

		if (s4)
		{
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i); printf("%s/ ", (val[0] != '\0') ? val : "--");
			val = PQgetvalue(Q33, r, i + 6); printf("%s", (val[0] != '\0') ? val : "--");
			printf("</td>");
			if (r % 2 == 0)
				printf("<td align=\"right\" style=\"color:white"";""background-color:black\">");
			else
				printf("<td align=\"right\" style=\"color:black"";""background-color:white\">");
			val = PQgetvalue(Q33, r, i + 1); printf("%s/ ", (val[0] != '\0') ? val : "—");
			val = PQgetvalue(Q33, r, i + 7); printf("%s", (val[0] != '\0') ? val : "—");
			printf("</td>");
		}
		printf("</tr>\n");

	}
	printf("</table>");

	PQclear(Q33);

	PQexec(conn, "drop table temp351;");

miss2_3:
	PQexec(conn, "drop table temp13;");
	PQexec(conn, "drop table temp23;");
	PQexec(conn, "drop table temp33;");
	PQexec(conn, "drop table temp131;");
	PQexec(conn, "drop table temp231;");
	PQexec(conn, "drop table temp331;");
	t_end = time(NULL) ;
	printf("\n<p>timeuse: %.0f s</p>\n", difftime(t_end,t_start)) ;
	printf("</div></div></body></html>");
	PQfinish(conn);


	return 0;
}

int hex2dec(char c)
{
	if ('0' <= c && c <= '9') {
		return c - '0';
	}
	else if ('a' <= c && c <= 'f') {
		return c - 'a' + 10;
	}
	else if ('A' <= c && c <= 'F') {
		return c - 'A' + 10;
	}
	else {
		return -1;
	}
}

char dec2hex(short int c)
{
	if (0 <= c && c <= 9) {
		return c + '0';
	}
	else if (10 <= c && c <= 15) {
		return c + 'A' - 10;
	}
	else {
		return -1;
	}
}


/*
* 编码一个url
*/
void urlencode(char *url)
{
	int i = 0;
	int len = strlen(url);
	int res_len = 0;
	char res[BURSIZE];
	for (i = 0; i < len; ++i) {
		char c = url[i];
		if (('0' <= c && c <= '9') ||
			('a' <= c && c <= 'z') ||
			('A' <= c && c <= 'Z') || c == '/' || c == '.') {
			res[res_len++] = c;
		}
		else {
			int j = (short int)c;
			if (j < 0)
				j += 256;
			int i1, i0;
			i1 = j / 16;
			i0 = j - i1 * 16;
			res[res_len++] = '%';
			res[res_len++] = dec2hex(i1);
			res[res_len++] = dec2hex(i0);
		}
	}
	res[res_len] = '\0';
	strcpy(url, res);
}

/*
* 解码url
*/
void urldecode(char *url)
{
	int i = 0;
	int len = strlen(url);
	int res_len = 0;
	char res[BURSIZE];
	for (i = 0; i < len; ++i) {
		char c = url[i];
		if (c != '%') {
			res[res_len++] = c;
		}
		else {
			char c1 = url[++i];
			char c0 = url[++i];
			int num = 0;
			num = hex2dec(c1) * 16 + hex2dec(c0);
			res[res_len++] = num;
		}
	}
	res[res_len] = '\0';
	strcpy(url, res);
}
