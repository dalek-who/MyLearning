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
int getNowTime(char *nowTime);
int main()
{
	PGconn* conn = PQconnectdb("dbname=train");
	char *data;
	data = getenv("QUERY_STRING");
	printf("Content-type:text/html\n\n");
	printf("<html> <head> <meta charset=\"UTF-8\"> <meta http-equiv=\"Content-Type\" content=\"text/html"";"" charset=UTF-8\"> <meta name=\"renderer\" content=\"webkit\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Home</title> <style type='text/css'> #top_title, #sideMenu { display: none"";"" } #content { width: 100%%"";"" margin: 0"";"" padding: 0"";"" } </style> <!--jQuery--> <script src=\"../jquery_min.js\"></script> <!--bootstrap--> <link href=\"../bootstrap_min.css\" rel=\"stylesheet\"> <script src=\"../bootstrap_min.js\"></script> <!--customer--> <link href=\"../nav.css\" rel=\"stylesheet\"> <link href=\"../customer.css\" rel=\"stylesheet\"> </head><body><div class=\"container-fluid\" style=\"background-color: black\"><p style=\"float: left"";"" font-size: 30px"";"" height: 40px"";"" color: #cccccc\">1 2 3 0 6</p>\n");
	urldecode(data);
	int p, q, n, m;
	char value[19][32] = {'\0'};
	p = 0;	
	if(data[2] == '1') m = 8;
	else if(data[2] == '2') m = 13;
	else if(data[2] == '3') m = 18;

	for(q = 0; q < m; q++)
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
	int k = atoi(value[0]);
	int num_rows1 = 1; int num_rows2 = 1; int num_rows3 = 1;
	double money[3] = {0};
	
	int   param_len[5]= {0};
    	int   param_format[5]= {0}; 
	const Oid paramTypes[5] = {1043,1043,1043,1043,1043};

	PGresult *Qx = PQprepare(conn, "check", "select * from client where national_id = $1 and passward = $2;", 2, paramTypes);
	char *param_valx[2] = {value[m - 2], value[m - 1]};
	Qx = PQexecPrepared(conn, "check", 2, (const char **)param_valx, param_len, param_format, 0);
	int num_rowsx = PQntuples(Qx);
	if(num_rowsx) printf(" <nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\">  <ul>  <li><a href=\"index.cgi?身份证=%s&密码=%s\">主页</a></li>  <li><a href=\"train.cgi?身份证=%s&密码=%s\">查车</a></li>  <li><a href=\"ticket.cgi?身份证=%s&密码=%s\">查票</a></li>  <li><a href=\"booking.cgi?身份证=%s&密码=%s\">预定</a></li>  <li><a href=\"../index.html\">登出</a></li>  <li><a href=\"order.cgi?身份证=%s&密码=%s\">订单</a></li>  <li><a href=\"administrator.cgi?身份证=%s&密码=%s\">管理员</a></li>  </ul>  </nav>  </div>\n<div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n",value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1]);
	else printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li>  <li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");
	if(num_rowsx == 0) {printf("<br/><p style=\"font-size:20px\">登录信息错误，请重新登录。</p>");printf("</div></div></body></html>");PQfinish(conn);return 0;}

	char *param_val1[5] ={value[1],value[2],value[3],value[4],value[5]};
	PGresult *Q12, *Q22, *Q32, *Q13, *Q23, *Q33, *Q15, *Q25, *Q35;
	PQexec(conn,"drop table temp41;");PQexec(conn,"drop table temp42;");PQexec(conn,"drop table temp43;");
	//printf("failed execution: %s\n", PQresultErrorMessage(Q01));

	PGresult *Q11 = PQprepare(conn, "p1","select d1.inner_station_id as inner1, d2.inner_station_id as inner2, d1.train_id, min(r.tickets), r.the_day, r.seat_type into temp41 from station as s1, station as s2, database1 as d1, database1 as d2, remaining_ticket as r, the_date as td where s1.station_name = $1 and s2.station_name = $2 and s1.station_id = d1.outer_station_id and s2.station_id = d2.outer_station_id and d1.train_id = d2.train_id and d1.train_id = $3 and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id and td.actual_date = cast($4 as date) and r.train_id = d1.train_id and r.the_day + d1.departing_day = td.date_id and (td.actual_date > current_date or ( td.actual_date = current_date and d1.departing_time > current_time)) and r.seat_type = $5 group by d1.inner_station_id, d2.inner_station_id, d1.train_id, r.tickets, r.the_day, r.seat_type;", 5, paramTypes);

	if(k > 0)
	{
		if(strcmp(value[1], value[2]) == 0) {printf("无法预定，信息出错\n");PQfinish(conn);return 0;}
		Q11 = PQexecPrepared(conn, "p1", 5, (const char **)param_val1, param_len, param_format, 0);
		Q12 = PQexec(conn,"alter table temp41 add price decimal(5,1); update temp41 set price = p2.price - p1.price + 5 from possible_ticket as p1, possible_ticket as p2 where temp41.train_id = p1.train_id and temp41.train_id = p2.train_id and temp41.inner1 = p1.inner_station_id and temp41.inner2 = p2.inner_station_id and temp41.seat_type = p1.seat_type and temp41.seat_type = p2.seat_type;");
		Q13 = PQexec(conn, "select * from temp41 where min > 0;");
		//printf("failed execution: %s\n", PQresultErrorMessage(Q11));
		num_rows1 = PQntuples(Q13);
		if(num_rows1 == 1) money[0] = atof(PQgetvalue(Q13, 0, PQnfields(Q13) - 1));
		PQclear(Q13);
	}

	char *param_val2[5] ={value[6],value[7],value[8],value[9],value[10]};
	PGresult *Q21 = PQprepare(conn, "p2","select d1.inner_station_id as inner1, d2.inner_station_id as inner2, d1.train_id, min(r.tickets), r.the_day, r.seat_type into temp42 from the_date as td, station as s1, station as s2, database1 as d1, database1 as d2, remaining_ticket as r where s1.station_name = $1 and s2.station_name = $2 and s1.station_id = d1.outer_station_id and s2.station_id = d2.outer_station_id and d1.train_id = d2.train_id and d1.train_id = $3 and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id and r.train_id = d1.train_id and td.actual_date = cast($4 as date) and r.the_day + d1.departing_day = td.date_id and (td.actual_date > current_date or ( td.actual_date = current_date and d1.departing_time > current_time)) and r.seat_type = $5 group by d1.inner_station_id, d2.inner_station_id, d1.train_id, r.tickets, r.the_day, r.seat_type;", 5, paramTypes);

	if(k > 1)
	{
		if(strcmp(value[6], value[7]) == 0) {printf("无法预定，信息出错\n");PQfinish(conn);return 0;}
		Q21 = PQexecPrepared(conn, "p2", 5, (const char **)param_val2, param_len, param_format, 0);
		Q22 = PQexec(conn,"alter table temp42 add price decimal(5,1); update temp42 set price = p2.price - p1.price + 5 from possible_ticket as p1, possible_ticket as p2 where temp42.train_id = p1.train_id and temp42.train_id = p2.train_id and temp42.inner1 = p1.inner_station_id and temp42.inner2 = p2.inner_station_id and temp42.seat_type = p1.seat_type and temp42.seat_type = p2.seat_type;");
		Q23 = PQexec(conn, "select * from temp42 where min > 0;");
		num_rows2 = PQntuples(Q23);
		if(num_rows2 == 1) money[1] = atof(PQgetvalue(Q23, 0, PQnfields(Q23) - 1));
		PQclear(Q23);
	}

	char *param_val3[5] ={value[11],value[12],value[13],value[14],value[15]};
	PGresult *Q31 = PQprepare(conn, "p3","select d1.inner_station_id as inner1, d2.inner_station_id as inner2, d1.train_id, min(r.tickets), r.the_day, r.seat_type into temp43 from the_date as td, station as s1, station as s2, database1 as d1, database1 as d2, remaining_ticket as r where s1.station_name = $1 and s2.station_name = $2 and s1.station_id = d1.outer_station_id and s2.station_id = d2.outer_station_id and d1.train_id = d2.train_id and d1.train_id = $3 and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id and r.train_id = d1.train_id and td.actual_date = cast($4 as date) and r.the_day + d1.departing_day = td.date_id and (td.actual_date > current_date or ( td.actual_date = current_date and d1.departing_time > current_time)) and r.seat_type = $5 group by d1.inner_station_id, d2.inner_station_id, d1.train_id, r.tickets, r.the_day, r.seat_type;", 5, paramTypes);

	if(k > 2)
	{
		if(strcmp(value[11], value[12]) == 0) {printf("无法预定，信息出错\n");PQfinish(conn);return 0;}
		Q31 = PQexecPrepared(conn, "p3", 5, (const char **)param_val3, param_len, param_format, 0);
		Q32 = PQexec(conn,"alter table temp43 add price decimal(5,1); update temp43 set price = p2.price - p1.price + 5 from possible_ticket as p1, possible_ticket as p2 where temp43.train_id = p1.train_id and temp43.train_id = p2.train_id and temp43.inner1 = p1.inner_station_id and temp43.inner2 = p2.inner_station_id and temp43.seat_type = p1.seat_type and temp43.seat_type = p2.seat_type;");
		Q33 = PQexec(conn, "select * from temp43 where min > 0;");
		num_rows3 = PQntuples(Q33);
		if(num_rows3 == 1) money[2] = atof(PQgetvalue(Q33, 0, PQnfields(Q33) - 1));
		PQclear(Q33);
	}

	if(num_rows1 == 0 || num_rows2 == 0 || num_rows3 == 0)
	{	
		printf("<p style=\"font-size:20px\">预定失败</p>\n");
		if(num_rows1 == 0) printf("第1辆车信息出错");
		if(num_rows2 == 0) printf("第2辆车信息出错");
		if(num_rows3 == 0) printf("第3辆车信息出错");
		PQfinish(conn);return 0;
	}
	else printf("</br><p style=\"font-size:20px\">预定成功，总价为%.1f元，其中每张票收取5元订票费。</p><br/>\n", money[0] + money[1] + money[2]);
	char nowTime[32] = {0};
	getNowTime(nowTime);
	char *param_val[2] = {nowTime, value[m - 2]};
	printf("<table class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\">订单详情</caption><tr><th>订单号</th><td colspan=\"%d\">%s</td></tr>\n",k,nowTime);
	PGresult *Q14 = PQprepare(conn, "p1-1", "insert into order_table(order_id, train_id, national_id, departure_station_id, destination_station_id, price, seat_type, departure_time, departure_date, order_time) select $1, t.train_id, $2, t.inner1, t.inner2, t.price, t.seat_type, d.departing_time, td.actual_date, current_timestamp from temp41 as t, database1 as d, the_date as td, client as c where t.train_id = d.train_id and t.inner1 = d.inner_station_id and td.date_id = t.the_day + d.departing_day and c.national_id = $2;", 2, paramTypes);
	if(k > 0)
	{
		Q13 = PQexec(conn, "update remaining_ticket set tickets = tickets - 1 from temp41 as t where remaining_ticket.inner_station_id between t.inner1 + 1 and t.inner2 and remaining_ticket.train_id = t.train_id and remaining_ticket.the_day = t.the_day and remaining_ticket.seat_type = t.seat_type and t.min > 0;");
		Q14 = PQexecPrepared(conn, "p1-1", 2, (const char **)param_val, param_len, param_format, 0);
	}
	PGresult *Q24 = PQprepare(conn,"p2-1",  "insert into order_table(order_id, train_id, national_id, departure_station_id, destination_station_id, price, seat_type, departure_time, departure_date, order_time) select $1, t.train_id, $2, t.inner1, t.inner2, t.price, t.seat_type, d.departing_time, td.actual_date, current_timestamp from temp42 as t, database1 as d, the_date as td where t.train_id = d.train_id and t.inner1 = d.inner_station_id and td.date_id = t.the_day + d.departing_day", 2, paramTypes);
	if(k > 1)
	{
		Q23 = PQexec(conn, "update remaining_ticket set tickets = tickets - 1 from temp42 as t where remaining_ticket.inner_station_id between t.inner1 + 1 and t.inner2 and remaining_ticket.train_id = t.train_id and remaining_ticket.the_day = t.the_day and remaining_ticket.seat_type = t.seat_type and t.min > 0;");
		Q24 = PQexecPrepared(conn, "p2-1", 2, (const char **)param_val, param_len, param_format, 0);
		//printf("failed execution: %s\n", PQresultErrorMessage(Q24));
	}
	PGresult *Q34 = PQprepare(conn,"p3-1",  "insert into order_table(order_id, train_id, national_id, departure_station_id, destination_station_id, price, seat_type, departure_time, departure_date, order_time) select $1, t.train_id, $2, t.inner1, t.inner2, t.price, t.seat_type, d.departing_time, td.actual_date, current_timestamp from temp43 as t, database1 as d, the_date as td where t.train_id = d.train_id and t.inner1 = d.inner_station_id and td.date_id = t.the_day + d.departing_day", 2, paramTypes);
	if(k > 2)
	{
		Q33 = PQexec(conn, "update remaining_ticket set tickets = tickets - 1 from temp43 as t where remaining_ticket.inner_station_id between t.inner1 + 1 and t.inner2 and remaining_ticket.train_id = t.train_id and remaining_ticket.the_day = t.the_day and remaining_ticket.seat_type = t.seat_type and t.min > 0;");
		Q34 = PQexecPrepared(conn, "p3-1", 2, (const char **)param_val, param_len, param_format, 0);
	}
	printf("<tr><th>车次</th>");for(p = 0; p < k;p++) printf("<td>%s</td>",value[3 + 5 * p]);printf("</tr>");
	printf("<tr><th>出发站</th>");for(p = 0; p < k;p++) printf("<td>%s</td>",value[1 + 5 * p]);printf("</tr>");
	printf("<tr><th>目的站</th>");for(p = 0; p < k;p++) printf("<td>%s</td>",value[2 + 5 * p]);printf("</tr>");
	printf("<tr><th>乘车日期</th>");for(p = 0; p < k;p++) printf("<td>%s</td>",value[4 + 5 * p]);printf("</tr>");
	printf("<tr><th>座位类型</th>");for(p = 0; p < k;p++) printf("<td>%s</td>",value[5 + 5 * p]);printf("</tr>");
	printf("<tr><th>票价</th>");for(p = 0; p < k;p++) printf("<td>%.1f</td>",money[p]);printf("</tr>");
	printf("<tr><th>查看</th>");printf("<td colspan=\"%d\"><a href=\"order.cgi?1=%s&2=%s&3=%s&4=&5=\">订单详情</a></td></tr>", k, value[m - 2], value[m - 1], nowTime);
	PQexec(conn,"drop table temp41;");PQexec(conn,"drop table temp42;");PQexec(conn,"drop table temp43;");
	printf("</p>");
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

int getNowTime(char *nowTime)
{
	char acYear[5] = {0};
	char acMonth[5] = {0};
	char acDay[5] = {0};
	char acHour[5] = {0};
	char acMin[5] = {0};
	char acSec[5] = {0};

	time_t now;
    struct tm* timenow;
    
    time(&now);
    timenow = localtime(&now);

    strftime(acYear,sizeof(acYear),"%Y",timenow);
    strftime(acMonth,sizeof(acMonth),"%m",timenow);
    strftime(acDay,sizeof(acDay),"%d",timenow);
    strftime(acHour,sizeof(acHour),"%H",timenow);
    strftime(acMin,sizeof(acMin),"%M",timenow);
    strftime(acSec,sizeof(acSec),"%S",timenow);

	strncat(nowTime, acYear, 4);
	strncat(nowTime, acMonth, 2);
	strncat(nowTime, acDay, 2);
	strncat(nowTime, acHour, 2);
	strncat(nowTime, acMin, 2);
	strncat(nowTime, acSec, 2);

	return 0;
}
  
