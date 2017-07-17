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
	int p, q, n, m;
	char value[15][32] = {'\0'};
	p = 0;
	if(data[2] == '1') m = 7;
	else if(data[2] == '2') m = 11;
	else if(data[2] == '3') m = 15;
	for(q = 0; q < m; q++)
	{
		while(data[p] != '=')
			p++;
		p++;n = 0;
		while(data[p] != '&')
		{
			value[q][n] = data[p];
			p++;n++;
		}
		value[q][n] = '\0';
	}

	int   param_len[4]= {0};
    	int   param_format[4]= {0}; 
	const Oid paramTypes[4] = {1043}; 
	PGresult *Qx = PQprepare(conn, "check", "select * from client where national_id = $1 and passward = $2;", 2, paramTypes);
	char *param_valx[2] = {value[m - 2], value[m - 1]};
	Qx = PQexecPrepared(conn, "check", 2, (const char **)param_valx, param_len, param_format, 0);
	int num_rowsx = PQntuples(Qx);
	if(num_rowsx) printf(" <nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\">  <ul>  <li><a href=\"index.cgi?身份证=%s&密码=%s\">主页</a></li>  <li><a href=\"train.cgi?身份证=%s&密码=%s\">查车</a></li>  <li><a href=\"ticket.cgi?身份证=%s&密码=%s\">查票</a></li>  <li><a href=\"booking.cgi?身份证=%s&密码=%s\">预定</a></li>  <li><a href=\"../index.html\">登出</a></li>  <li><a href=\"order.cgi?身份证=%s&密码=%s\">订单</a></li>  <li><a href=\"administrator.cgi?身份证=%s&密码=%s\">管理员</a></li>  </ul>  </nav>  </div>\n <div class=\"container home-content\" style=\"background-color: white\">  <div class=\"row\" style=\"text-align: center\"><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n",value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1],value[m - 2],value[m - 1]);
	else printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li>  <li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");

	PGresult *Q = PQprepare(conn, "Query_One","select r.seat_type from remaining_ticket as r, database1 as d1, database1 as d2, the_date as t where d1.train_id = $1 and d2.train_id = $1 and r.train_id = $1 and d1.station_name = $2 and d2.station_name = $3 and r.inner_station_id between d1.inner_station_id + 1 and d2.inner_station_id and d1.inner_station_id < d2.inner_station_id and r.the_day + d1.departing_day = t.date_id and t.actual_date = cast($4 as date) and (t.actual_date > current_date or ( t.actual_date = current_date and d1.departing_time > current_time)) group by r.seat_type having min(r.tickets) > 0;", 4, paramTypes);
	int k = atoi(value[0]);
	printf("<br/><form method=\"get\" action=\"purchase.cgi\"><p><input type=\"hidden\" name=\"1\" value=\"%d\"></p>", k);
	char *val;
	int r, num_rows;
	if(k > 0)
	{
		printf("<p>出发地 :<input type=\"text\" name=\"站名\" value=\"%s\">目的地 :<input type=\"text\" name=\"站名\" value=\"%s\">车次 :<input type=\"text\" name=\"车次\" value=\"%s\">日期 :<select name=\"5\"><option value=\"%s\">%s</select>", value[2],value[3],value[1],value[4],value[4]);
	 	char *param_val1[4] = {value[1], value[2], value[3],value[4]};
		Q = PQexecPrepared(conn, "Query_One", 4, (const char **)param_val1, param_len, param_format, 0);
		num_rows = PQntuples(Q);
		//printf("failed execution: %s\n", PQresultErrorMessage(Q));
		printf("座位类型 :<select name=\"6\">");
		if(num_rows == 0) printf("<option value=\"\">无法预定");
		for(r = 0; r < num_rows; r++)
		{	
			printf("<option value=\"");		
			val = PQgetvalue(Q, r, 0);
			printf("%s\">%s", val, val);
		}
		printf(" </select></p>");
		PQclear(Q);
	}

	if(k > 1)
	{
		printf("<p>出发地 :<input type=\"text\" name=\"站名\" value=\"%s\">目的地 :<input type=\"text\" name=\"站名\" value=\"%s\">车次 :<input type=\"text\" name=\"车次\" value=\"%s\">日期 :<select name=\"5\"><option value=\"%s\">%s</select>", value[6],value[7],value[5],value[8],value[8]);
		char *param_val2[4] = {value[5], value[6], value[7],value[8]};
		Q = PQexecPrepared(conn, "Query_One", 4, (const char **)param_val2, param_len, param_format, 0);
		num_rows = PQntuples(Q);
		printf("座位类型 :<select name=\"11\">");
		if(num_rows == 0) printf("<option value=\"\">无法预定");
		for(r = 0; r < num_rows; r++)
		{	
			printf("<option value=\"");		
			val = PQgetvalue(Q, r, 0);
			printf("%s\">%s", val, val);
		}
		printf(" </select></p>");
		PQclear(Q);
	}
	if(k > 2)
	{
		printf("<p>出发地 :<input type=\"text\" name=\"站名\" value=\"%s\">目的地 :<input type=\"text\" name=\"站名\" value=\"%s\">车次 :<input type=\"text\" name=\"车次\" value=\"%s\">日期 :<select name=\"5\"><option value=\"%s\">%s</select>", value[10],value[11],value[9],value[12],value[12]);
	 	char *param_val3[4] = {value[9], value[10], value[11],value[12]};
		Q = PQexecPrepared(conn, "Query_One", 4, (const char **)param_val3, param_len, param_format, 0);
		num_rows = PQntuples(Q);
		printf("座位类型 :<select name=\"16\">");
		if(num_rows == 0) printf("<option value=\"\">无法预定");
		printf("num_rows = %d)",num_rows);
		for(r = 0; r < num_rows; r++)
		{	
			printf("<option value=\"");		
			val = PQgetvalue(Q, r, 0);
			printf("%s\">%s", val, val);
		}
		printf(" </select></p>");
		PQclear(Q);
	}
	printf("<p><input type=\"hidden\" name=\"身份证\" value=\"%s\"><input type=\"hidden\" name=\"密码\" value=\"%s\"><input type=\"submit\" value=\"预定\"> </p> </form>",value[m - 2], value[m - 1]);
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
  
