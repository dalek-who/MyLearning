/**
 * compile: gcc simple.c -o simple.cgi
 */

#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <time.h>
#include <postgresql/libpq-fe.h>
#include <arpa/inet.h> 
void urldecode(char *url);
void urlencode(char *url);
int hex2dec(char c);
char dec2hex(short int c);
int main()
{
	PGconn* conn = PQconnectdb("dbname=train");

	char *data;
	data = getenv("QUERY_STRING");
	printf("Content-type:text/html\n\n");

	printf("<head> <meta charset=\"UTF-8\"> <meta http-equiv=\"Content-Type\" content=\"text/html"";"" charset=UTF-8\"> <meta name=\"renderer\" content=\"webkit\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Home</title> <style type='text/css'> #top_title, #sideMenu { display: none"";"" } #content { width: 100%%"";"" margin: 0"";"" padding: 0"";"" } </style> <!--jQuery--><script src=\"../jquery_min.js\"></script><!--bootstrap--><link href=\"../bootstrap_min.css\" rel=\"stylesheet\"><script src=\"../bootstrap_min.js\"></script><!--customer--><link href=\"../nav.css\" rel=\"stylesheet\"><link href=\"../customer.css\" rel=\"stylesheet\"></head>\n<body> <div class=\"container-fluid\" style=\"background-color: black\"> 	<p style=\"float: left"";"" font-size: 30px"";"" height: 40px"";"" color: #cccccc\">1 2 3 0 6</p> ");

	urldecode(data);
	int p, q, n;
	char value[4][32];
	p = 0;
	for(q = 0; q < 4; q++)
	{
		while(data[p] != '=')
			p++;
		p++;n = 0;
		while(data[p] != '&' && p < strlen(data))
		{
			value[q][n] = data[p];
			p++;n++;
		}
		value[q][n] = '\0';
	}
	int flagx = (value[2][0] != '\0')? 1:0; 
	if(flagx) printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\">  <ul>  <li><a href=\"index.cgi?身份证=%s&密码=%s\">主页</a></li>  <li><a href=\"train.cgi?身份证=%s&密码=%s\">查车</a></li>  <li><a href=\"ticket.cgi?身份证=%s&密码=%s\">查票</a></li>  <li><a href=\"booking.cgi?身份证=%s&密码=%s\">预定</a></li>  <li><a href=\"../index.html\">登出</a></li>  <li><a href=\"order.cgi?身份证=%s&密码=%s\">订单</a></li>  <li><a href=\"administrator.cgi?身份证=%s&密码=%s\">管理员</a></li>  </ul>  </nav>  </div>  <div class=\"container home-content\" style=\"background-color: white\">  <div class=\"row\" style=\"text-align: center\">",value[2],value[3],value[2],value[3],value[2],value[3],value[2],value[3],value[2],value[3],value[2],value[3]);
	else printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li>  <li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");

	printf(" <p> <form method=\"get\" action=\"/cgi-bin/query2.cgi\"> 车次 : <input type=\"text\" name=\"车次\" value=\"%s\"> 日期 : <select name=\"3\"> <option value=\"0\"><option value=\"6\">2016-11-23 <option value=\"7\">2016-11-24 <option value=\"8\">2016-11-25 <option value=\"9\">2016-11-26 <option value=\"10\">2016-11-27 <option value=\"11\">2016-11-28 <option value=\"12\">2016-11-29 <option value=\"13\">2016-11-30 <option value=\"14\">2016-12-01 <option value=\"15\">2016-12-02 <option value=\"16\">2016-12-03 <option value=\"17\">2016-12-04 <option value=\"18\">2016-12-05 <option value=\"19\">2016-12-06 <option value=\"20\">2016-12-07 <option value=\"21\">2016-12-08 <option value=\"22\">2016-12-09 <option value=\"23\">2016-12-10 <option value=\"24\">2016-12-11 <option value=\"25\">2016-12-12 <option value=\"26\">2016-12-13 <option value=\"27\">2016-12-14 <option value=\"28\">2016-12-15 <option value=\"29\">2016-12-16 <option value=\"30\">2016-12-17 <option value=\"31\">2016-12-18 <option value=\"32\">2016-12-19 </select> ",value[0]);
	printf("<input type=\"hidden\" name=\"身份证\" value=\"%s\"><input type=\"hidden\" name=\"车次\" value=\"%s\"><input type=\"submit\" value=\"查询\"> </form>",value[2],value[3]);
	printf("%s",PQerrorMessage(conn));
	int m = atoi(value[1]);
	time_t timep;
   	struct tm *px;
    	time(&timep);
    	px = gmtime(&timep);
	if(m == 0) m = px->tm_mday - 16;
	int flag = (m > px->tm_mday - 18) ? 1:0; 
	int k = (int)ntohl(m);
	const Oid paramTypes1[2] = {1043,23}; 
	PGresult *Q11 = PQprepare(conn, "Query_One1","select t.actual_date, $2 as date_id, d.train_id, d.inner_station_id, s.station_name, d.arriving_time, d.departing_time into temp0 from the_date as t, station as s, database1 as d where d.train_id = $1 and t.date_id + d.departing_day = $2 and s.station_id = d.outer_station_id;", 2, paramTypes1);
	 	char *param_val1[2] ={value[0], (char *)&k};
		int   param_len1[2]= {0,4};
	    	int   param_format1[2]= {0,1};
		Q11 = PQexecPrepared(conn, "Query_One1", 2, (const char **)param_val1, param_len1, param_format1, 0);
		PGresult *Q12 = PQexec(conn, "alter table temp0 add Hard_Seat_Price decimal(5,1); update temp0 set Hard_Seat_Price = p.price from possible_ticket as p where temp0.train_id = p.train_id and temp0.inner_station_id = p.inner_station_id and p.seat_type = 'Hard_Seat'; alter table temp0 add Soft_Seat_Price decimal(5,1); update temp0 set Soft_Seat_Price = p.price from possible_ticket as p where temp0.train_id = p.train_id and temp0.inner_station_id = p.inner_station_id and p.seat_type = 'Soft_Seat'; alter table temp0 add Hard_Sleeper_Up_Price decimal(5,1); update temp0 set Hard_Sleeper_Up_Price = p.price from possible_ticket as p where temp0.train_id = p.train_id and temp0.inner_station_id = p.inner_station_id and p.seat_type = 'Hard_Up'; alter table temp0 add Hard_Sleeper_Middle_Price decimal(5,1); update temp0 set Hard_Sleeper_Middle_Price = p.price from possible_ticket as p where temp0.train_id = p.train_id and temp0.inner_station_id = p.inner_station_id and p.seat_type = 'Hard_Middle'; alter table temp0 add Hard_Sleeper_Down_Price decimal(5,1); update temp0 set Hard_Sleeper_Down_Price = p.price from possible_ticket as p where temp0.train_id = p.train_id and temp0.inner_station_id = p.inner_station_id and p.seat_type = 'Hard_Down'; alter table temp0 add Soft_Sleeper_Up_Price decimal(5,1); update temp0 set Soft_Sleeper_Up_Price = p.price from possible_ticket as p where temp0.train_id = p.train_id and temp0.inner_station_id = p.inner_station_id and p.seat_type = 'Soft_Up'; alter table temp0 add Soft_Sleeper_Down_Price decimal(5,1); update temp0 set Soft_Sleeper_Down_Price = p.price from possible_ticket as p where temp0.train_id = p.train_id and temp0.inner_station_id = p.inner_station_id and p.seat_type = 'Soft_Down'; update temp0 set actual_date = t.actual_date from the_date as t where t.date_id = temp0.date_id;  alter table temp0 add Hard_Seat integer; update temp0 set Hard_Seat = r.tickets from remaining_ticket as r where r.train_id = temp0.train_id and r.inner_station_id = temp0.inner_station_id and r.inner_station_id > 1 and r.the_day = temp0.date_id and r.seat_type = 'Hard_Seat';  alter table temp0 add Soft_Seat integer; update temp0 set Soft_Seat = r.tickets from remaining_ticket as r where r.train_id = temp0.train_id and r.inner_station_id = temp0.inner_station_id and r.inner_station_id > 1 and r.the_day = temp0.date_id and r.seat_type = 'Soft_Seat';  alter table temp0 add Hard_Up integer; update temp0 set Hard_Up = r.tickets from remaining_ticket as r where r.train_id = temp0.train_id and r.inner_station_id = temp0.inner_station_id and r.inner_station_id > 1 and r.the_day = temp0.date_id and r.seat_type = 'Hard_Up';  alter table temp0 add Hard_Middle integer; update temp0 set Hard_Middle = r.tickets from remaining_ticket as r where r.train_id = temp0.train_id and r.inner_station_id = temp0.inner_station_id and r.inner_station_id > 1 and r.the_day = temp0.date_id and r.seat_type = 'Hard_Middle';  alter table temp0 add Hard_Down integer; update temp0 set Hard_Down = r.tickets from remaining_ticket as r where r.train_id = temp0.train_id and r.inner_station_id = temp0.inner_station_id and r.inner_station_id > 1 and r.the_day = temp0.date_id and r.seat_type = 'Hard_Down';  alter table temp0 add Soft_Up integer; update temp0 set Soft_Up = r.tickets from remaining_ticket as r where r.train_id = temp0.train_id and r.inner_station_id = temp0.inner_station_id and r.inner_station_id > 1 and r.the_day = temp0.date_id and r.seat_type = 'Soft_Up';  alter table temp0 add Soft_Down integer; update temp0 set Soft_Down = r.tickets from remaining_ticket as r where r.train_id = temp0.train_id and r.inner_station_id = temp0.inner_station_id and r.inner_station_id > 1 and r.the_day = temp0.date_id and r.seat_type = 'Soft_Down';update temp0 set Hard_Seat_Price = NULL, Soft_Seat_Price = NULL, Hard_Sleeper_Up_Price = NULL, Hard_Sleeper_Down_Price = NULL,Hard_Sleeper_Middle_Price = NULL, Soft_Sleeper_Down_Price = NULL, Soft_Sleeper_Up_Price = NULL where Inner_Station_ID = 1; select actual_date, train_id, inner_station_id, station_name, departing_time, arriving_time, hard_seat,hard_seat_price, soft_seat, soft_seat_price, hard_up, hard_sleeper_up_price, hard_middle, hard_sleeper_middle_price, hard_down, hard_sleeper_down_price, soft_up,soft_sleeper_up_price, soft_down, soft_sleeper_down_price from temp0 order by inner_station_id;");

		int num_rows = PQntuples(Q12);
		if(num_rows == 0) printf("非法输入,请再次尝试\n");
		int num_cols = PQnfields(Q12);
		int i, r;
		char *val;
		if(flag)
		{
		printf("<form method=\"get\" action=\"/cgi-bin/buy.cgi\"><input type=\"hidden\" name=\"1\" value=\"1\"><input type=\"hidden\" name=\"车次\" value=\"%s\">出发地 :<select name=\"站名\">\n",value[0]);
		for(r = 0; r < num_rows; r++)
			printf("<option value=\"%s\">%s\n", PQgetvalue(Q12, r, 3), PQgetvalue(Q12, r, 3));
		printf("</select> 目的地 :<select name=\"站名\">\n");
		for(r = 0; r < num_rows; r++)
			printf("<option value=\"%s\">%s\n", PQgetvalue(Q12, r, 3), PQgetvalue(Q12, r, 3));
		printf("<input type=\"hidden\" name=\"日期\" value=\"%s\"><input type=\"hidden\" name=\"身份证\" value=\"%s\"><input type=\"hidden\" name=\"密码\" value=\"%s\">&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;<input type=\"submit\" value=\"预定\"> </form>",PQgetvalue(Q12, 0, 0),value[2],value[3]);
		}
		else printf("信息已过期,无法提供预定链接");
		printf("<table class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\">直达车次信息</caption>\n<tr><th align=\"right\">日期</th><th align=\"right\">车次</th><th align=\"right\">序号</th><th align=\"right\">站名</th><th align=\"right\">发车时间</th><th align=\"right\">抵达时间</th><th align=\"right\">硬座</th><th align=\"right\">票价</th><th align=\"right\">软座</th><th align=\"right\">票价</th><th align=\"right\">硬卧</th><th align=\"right\">票价</th><th align=\"right\">软卧</th><th align=\"right\">票价</th>");
		for(r = 0; r < num_rows; r++)
		{
			printf("<tr>");
			for(i = 0; i < num_cols; i++)
			{
				if(i == 6)
				{
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i);printf("%s ", (val[0] != '\0') ? val:"--");
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i + 1);printf("%s ", (val[0] != '\0') ? val:"—");printf("</td>");
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i + 2);printf("%s", (val[0] != '\0') ? val:"--");printf("</td>");
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i + 3);printf("%s ", (val[0] != '\0') ? val:"—");printf("</td>");
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i + 4);printf("%s/ ", (val[0] != '\0') ? val:"--");
					val = PQgetvalue(Q12, r, i + 6);printf("%s/ ", (val[0] != '\0') ? val:"--");
					val = PQgetvalue(Q12, r, i + 8);printf("%s", (val[0] != '\0') ? val:"--");printf("</td>");
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i + 5);printf("%s/ ", (val[0] != '\0') ? val:"—");
					val = PQgetvalue(Q12, r, i + 7);printf("%s/ ", (val[0] != '\0') ? val:"—");
					val = PQgetvalue(Q12, r, i + 9);printf("%s", (val[0] != '\0') ? val:"—");printf("</td>");
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i + 10);printf("%s/ ", (val[0] != '\0') ? val:"--");
					val = PQgetvalue(Q12, r, i + 12);printf("%s", (val[0] != '\0') ? val:"--");printf("</td>");
					if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
					else printf("<td align=\"right\" style=\"color:black\">");
					val = PQgetvalue(Q12, r, i + 11);printf("%s/ ", (val[0] != '\0') ? val:"—");
					val = PQgetvalue(Q12, r, i + 13);printf("%s", (val[0] != '\0') ? val:"—");printf("</td>");
					break;
				}
				val = PQgetvalue(Q12, r, i);
				if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
				else printf("<td align=\"right\" style=\"color:black\">");
				printf("%s", val);
				printf("</td>");
			}
			printf("</tr>\n");
		}
		printf("</table>");
	ExecStatusType status = PQresultStatus(Q12);
	if((status != PGRES_TUPLES_OK) && (status != PGRES_SINGLE_TUPLE) && (status !=  PGRES_COMMAND_OK))
	{
		printf("failed execution: %s\n", PQresultErrorMessage(Q12));
		PQfinish(conn);
		return 1;
	}
	PQclear(Q12);
	PGresult *Q13 = PQexec(conn, "drop table temp0;");
	printf("</div></div></body></html>");
	PQfinish(conn);
     return 0;
}

//以下代码来源于百度 url 解码
#define BURSIZE 1024  
  
int hex2dec(char c)  
{  
    if ('0' <= c && c <= '9') {  
        return c - '0';  
    } else if ('a' <= c && c <= 'f') {  
        return c - 'a' + 10;  
    } else if ('A' <= c && c <= 'F') {  
        return c - 'A' + 10;  
    } else {  
        return -1;  
    }  
}  
  
char dec2hex(short int c)  
{  
    if (0 <= c && c <= 9) {  
        return c + '0';  
    } else if (10 <= c && c <= 15) {  
        return c + 'A' - 10;  
    } else {  
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
        } else {  
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
        } else {  
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
  
