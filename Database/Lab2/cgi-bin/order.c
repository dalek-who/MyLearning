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
	printf("<html> <head> <meta charset=\"UTF-8\"> <meta http-equiv=\"Content-Type\" content=\"text/html"";"" charset=UTF-8\"> <meta name=\"renderer\" content=\"webkit\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Home</title> <style type='text/css'> #top_title, #sideMenu { display: none"";"" } #content { width: 100%%"";"" margin: 0"";"" padding: 0"";"" } </style> <!--jQuery--> <script src=\"../jquery_min.js\"></script> <!--bootstrap--> <link href=\"../bootstrap_min.css\" rel=\"stylesheet\"> <script src=\"../bootstrap_min.js\"></script> <!--customer--> <link href=\"../nav.css\" rel=\"stylesheet\"> <link href=\"../customer.css\" rel=\"stylesheet\"> </head><body><div class=\"container-fluid\" style=\"background-color: black\"><p style=\"float: left"";"" font-size: 30px"";"" height: 40px"";"" color: #cccccc\">1 2 3 0 6</p>\n");
	urldecode(data);
	int p, q, n;
	char value[5][32] = {'\0'};
	p = 0;	
	for(q = 0; q < 5; q++)
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

	int   param_len[5]= {0};
    	int   param_format[5]= {0}; 
	const Oid paramTypes[5] = {1043,1043,1043,1043,1043}; 
	PGresult *Qx = PQprepare(conn, "check", "select * from client where national_id = $1 and passward = $2;", 2, paramTypes);
	char *param_valx[2] = {value[0], value[1]};
	Qx = PQexecPrepared(conn, "check", 2, (const char **)param_valx, param_len, param_format, 0);
	int num_rowsx = PQntuples(Qx);
	if(num_rowsx) printf(" <nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\">  <ul>  <li><a href=\"index.cgi?身份证=%s&密码=%s\">主页</a></li>  <li><a href=\"train.cgi?身份证=%s&密码=%s\">查车</a></li>  <li><a href=\"ticket.cgi?身份证=%s&密码=%s\">查票</a></li>  <li><a href=\"booking.cgi?身份证=%s&密码=%s\">预定</a></li>  <li><a href=\"../index.html\">登出</a></li>  <li><a href=\"order.cgi?身份证=%s&密码=%s\">订单</a></li>  <li><a href=\"administrator.cgi?身份证=%s&密码=%s\">管理员</a></li>  </ul>  </nav>  </div>\n<div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n",value[0],value[1],value[0],value[1],value[0],value[1],value[0],value[1],value[0],value[1],value[0],value[1]);
	else printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li>  <li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");
	if(num_rowsx == 0) {printf("<br/><p style=\"font-size:20px\">登录信息错误，请重新登录。</p>");printf("</div></div></body></html>");PQfinish(conn);return 0;}

	printf(" <br/> <form method=\"get\" action=\"/cgi-bin/order.cgi\"> <p><input type=\"hidden\" name=\"身份证\" value=\"%s\"><input type=\"hidden\" name=\"密码\" value=\"%s\"> 订单号 : <input type=\"text\" name=\"订单号\"> 出发日期 从: <select name=\"2\"> <option value=\"\"> <option value=\"2016-11-18\">2016-11-18 <option value=\"2016-11-19\">2016-11-19 <option value=\"2016-11-20\">2016-11-20 <option value=\"2016-11-21\">2016-11-21 <option value=\"2016-11-22\">2016-11-22 <option value=\"2016-11-23\">2016-11-23 <option value=\"2016-11-24\">2016-11-24 <option value=\"2016-11-25\">2016-11-25 <option value=\"2016-11-26\">2016-11-26 <option value=\"2016-11-27\">2016-11-27 <option value=\"2016-11-28\">2016-11-28 <option value=\"2016-11-29\">2016-11-29 <option value=\"2016-11-30\">2016-11-30 <option value=\"2016-12-01\">2016-12-01 <option value=\"2016-12-02\">2016-12-02 <option value=\"2016-12-03\">2016-12-03 <option value=\"2016-12-04\">2016-12-04 <option value=\"2016-12-05\">2016-12-05 <option value=\"2016-12-06\">2016-12-06 <option value=\"2016-12-07\">2016-12-07 <option value=\"2016-12-08\">2016-12-08 <option value=\"2016-12-09\">2016-12-09 <option value=\"2016-12-10\">2016-12-10 <option value=\"2016-12-11\">2016-12-11 <option value=\"2016-12-12\">2016-12-12 <option value=\"2016-12-13\">2016-12-13 <option value=\"2016-12-14\">2016-12-14 <option value=\"2016-12-15\">2016-12-15 <option value=\"2016-12-16\">2016-12-16 <option value=\"2016-12-17\">2016-12-17 <option value=\"2016-12-18\">2016-12-18 <option value=\"2016-12-19\">2016-12-19 </select>\n", value[0], value[1]);
	printf("到: <select name=\"3\"> <option value=\"\"> <option value=\"2016-11-18\">2016-11-18 <option value=\"2016-11-19\">2016-11-19 <option value=\"2016-11-20\">2016-11-20 <option value=\"2016-11-21\">2016-11-21 <option value=\"2016-11-22\">2016-11-22 <option value=\"2016-11-23\">2016-11-23 <option value=\"2016-11-24\">2016-11-24 <option value=\"2016-11-25\">2016-11-25 <option value=\"2016-11-26\">2016-11-26 <option value=\"2016-11-27\">2016-11-27 <option value=\"2016-11-28\">2016-11-28 <option value=\"2016-11-29\">2016-11-29 <option value=\"2016-11-30\">2016-11-30 <option value=\"2016-12-01\">2016-12-01 <option value=\"2016-12-02\">2016-12-02 <option value=\"2016-12-03\">2016-12-03 <option value=\"2016-12-04\">2016-12-04 <option value=\"2016-12-05\">2016-12-05 <option value=\"2016-12-06\">2016-12-06 <option value=\"2016-12-07\">2016-12-07 <option value=\"2016-12-08\">2016-12-08 <option value=\"2016-12-09\">2016-12-09 <option value=\"2016-12-10\">2016-12-10 <option value=\"2016-12-11\">2016-12-11 <option value=\"2016-12-12\">2016-12-12 <option value=\"2016-12-13\">2016-12-13 <option value=\"2016-12-14\">2016-12-14 <option value=\"2016-12-15\">2016-12-15 <option value=\"2016-12-16\">2016-12-16 <option value=\"2016-12-17\">2016-12-17 <option value=\"2016-12-18\">2016-12-18 <option value=\"2016-12-19\">2016-12-19 </select> <input type=\"submit\" value=\"提交\"> </p> </form>\n");

	int flag1 = (value[2][0] != '\0') ? 1:0;
	int flag2 = (value[3][0] != '\0') ? 1:0;
	int flag3 = (value[4][0] != '\0') ? 1:0;
	if(flag2 && !flag3) bcopy(value[3], value[4], 32);

	int num_rows1 = 1; int num_rows2 = 1; int num_rows3 = 1;
	double money1 = 0; double money2 = 0; double money3 = 0;

	int num_rows, num_cols;
	int i, r;
	char *val, *val1, *val2, *val3;

	char *param_val1[2] ={value[2], value[0]};
	PGresult *Q1 = PQprepare(conn, "p1","select o.order_id, o.train_id, o.departure_date, o.departure_time, s1.station_name, s2.station_name, o.price, o.seat_type, o.order_time from order_table as o, station as s1, station as s2, database1 as d1, database1 as d2 where o.order_id = $1 and d1.train_id = o.train_id and d2.train_id = o.train_id and o.national_id = $2 and s1.station_id = d1.outer_station_id and d1.inner_station_id = o.departure_station_id and s2.station_id = d2.outer_station_id and d2.inner_station_id = o.destination_station_id order by o.departure_date, o.departure_time;", 2, paramTypes);

	if(flag1)
	{
		Q1 = PQexecPrepared(conn, "p1", 2, (const char **)param_val1, param_len, param_format, 0);
		num_rows = PQntuples(Q1);
		num_cols = PQnfields(Q1);
		if(num_rows == 0) printf("<br/><p style=\"font-size:20px\">订单号有误</p>");
		else{
		printf("<table class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\">订单详情</caption>\n");
		printf("<tr><th align=\"right\">订单号</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 0);printf("<td>%s", val);printf("</td>");}
		printf("</tr>\n");
		printf("<tr><th align=\"right\">车次</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 1);printf("<td>%s", val);printf("</td>");}
		printf("</tr>\n");
		printf("<tr><th align=\"right\">出发日期时间</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 2);printf("<td>%s ", val);
			val = PQgetvalue(Q1, r, 3);printf("%s", val);printf("</td>");}
		printf("</tr>\n");
		printf("<tr><th align=\"right\">出发站</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 4);printf("<td>%s", val);printf("</td>");}
		printf("</tr>\n");
		printf("<tr><th align=\"right\">目的站</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 5);printf("<td>%s", val);printf("</td>");}
		printf("</tr>\n");
		printf("<tr><th align=\"right\">票价</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 6);printf("<td>%s", val);printf("</td>");}
		printf("<tr><th align=\"right\">座位类型</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 7);printf("<td>%s", val);printf("</td>");}
		printf("</tr>\n");
		printf("<tr><th align=\"right\">订单日期</th>");
		for(r = 0 ; r < num_rows; r++)
			{val = PQgetvalue(Q1, r, 8);printf("<td>%s", val);printf("</td>");}
		printf("</tr>\n");
		printf("<tr><th align=\"right\">操作</th>");
		val1 = value[0]; val2 = value[1]; val3 = value[2];
		printf("<td colspan=\"%d\"><a href=\"http://localhost/cgi-bin/delete.cgi?1=%s&2=%s&3=%s\">删除订单</a></td>",num_rows, val1, val2, val3);
		printf("</tr>\n");
		printf("</table>");
		PQclear(Q1);
		}
	}

	PGresult *Q2 = PQprepare(conn, "p2","select o.order_id, o.train_id, o.departure_date, o.departure_time, s1.station_name, s2.station_name, o.price from order_table as o, station as s1, station as s2, database1 as d1, database1 as d2, the_date as td1, the_date as td2, the_date as td where o.departure_date = td.actual_date and td1.actual_date = cast($1 as date) and td2.actual_date = cast($2 as date) and td.date_id between td1.date_id and td2.date_id and o.national_id = $3 and d1.train_id = o.train_id and d2.train_id = o.train_id  and s1.station_id = d1.outer_station_id and d1.inner_station_id = o.departure_station_id and s2.station_id = d2.outer_station_id and d2.inner_station_id = o.destination_station_id;", 3, paramTypes);
	char *param_val2[3] ={value[3], value[4], value[0]};
	if(flag2)
	{
		Q2 = PQexecPrepared(conn, "p2", 3, (const char **)param_val2, param_len, param_format, 0);
		num_rows = PQntuples(Q2);
		printf("%s\n", PQresultErrorMessage(Q2));
		num_cols = PQnfields(Q2);
		printf("<table class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\">订单信息</caption>\n<tr><th align=\"right\">订单号</th><th align=\"right\">车次</th><th align=\"right\">出发日期时间</th><th align=\"right\">出发站</th><th align=\"right\">目的站</th><th align=\"right\">票价</th><th align=\"right\">查看</th>");
		for(r = 0; r < num_rows; r++)
		{
			printf("<tr>");
			for(i = 0; i < num_cols; i++)
			{
				if(i == 2)
				{
					if(r % 2 == 0) printf("<td style=\"color:white\">");
					else printf("<td style=\"color:black\">");
					val = PQgetvalue(Q2, r, i);printf("%s ", (val[0] != '\0') ? val:"--");
					val = PQgetvalue(Q2, r, i + 1);printf("%s", (val[0] != '\0') ? val:"—");printf("</td>");
					i++;i++;
				}
				val = PQgetvalue(Q2, r, i);
				if(r % 2 == 0) printf("<td style=\"color:white\">");
				else printf("<td style=\"color:black\">");
				printf("%s", val);
				printf("</td>");
			}
			val = PQgetvalue(Q2, r, 0);
			printf("<td><a href=\"order.cgi?1=%s&2=%s&3=%s&4=&5=\">订单详情</a></td>", value[0], value[1], val);
			printf("</tr>\n");
		}
		printf("</table>");
		PQclear(Q2);
	}

	char *param_val3[2] = {value[0],value[1]};
	PGresult *Q3 = PQprepare(conn, "p3", "select o.order_id, o.train_id, o.departure_date, o.departure_time, s1.station_name, s2.station_name, o.price from order_table as o, station as s1, station as s2, database1 as d1, database1 as d2 where o.national_id = $1 and d1.train_id = o.train_id and d2.train_id = o.train_id and s1.station_id = d1.outer_station_id and d1.inner_station_id = o.departure_station_id and s2.station_id = d2.outer_station_id and d2.inner_station_id = o.destination_station_id;", 1, paramTypes);
	printf("%s\n", PQresultErrorMessage(Q3));
	if(1)
	{
		Q3 = PQexecPrepared(conn, "p3", 1, (const char **)param_val3, param_len, param_format, 0);
		num_rows = PQntuples(Q3);
		printf("%s\n", PQresultErrorMessage(Q3));
		num_cols = PQnfields(Q3);
		printf("<table class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\">所有订单</caption>\n<tr><th align=\"right\">订单号</th><th align=\"right\">车次</th><th align=\"right\">出发日期时间</th><th align=\"right\">出发站</th><th align=\"right\">目的站</th><th align=\"right\">票价</th><th align=\"right\">查看</th>");
		for(r = 0; r < num_rows; r++)
		{
			printf("<tr>");
			for(i = 0; i < num_cols; i++)
			{
				if(i == 2)
				{
					if(r % 2 == 0) printf("<td style=\"color:white\">");
					else printf("<td style=\"color:black\">");
					val = PQgetvalue(Q3, r, i);printf("%s ", (val[0] != '\0') ? val:"--");
					val = PQgetvalue(Q3, r, i + 1);printf("%s", (val[0] != '\0') ? val:"—");printf("</td>");
					i++;i++;
				}
				val = PQgetvalue(Q3, r, i);
				if(r % 2 == 0) printf("<td style=\"color:white\">");
				else printf("<td style=\"color:black\">");
				printf("%s", val);
				printf("</td>");
			}
			val = PQgetvalue(Q3, r, 0);
			printf("<td><a href=\"order.cgi?1=%s&2=%s&3=%s&4=&5=\">订单详情</a></td>", value[0], value[1], val);
			printf("</tr>\n");
		}
		printf("</table>");
		PQclear(Q3);
	}
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
