/**
 * compile: gcc simple.c -o simple.cgi
 */

#include "stdio.h"
#include "stdlib.h"
#include <string.h>
#include <postgresql/libpq-fe.h>
#include <arpa/inet.h> 
void urldecode(char *url);
void urlencode(char *url);
int main()
{
	PGconn* conn = PQconnectdb("dbname=train");
	char *data;
	data = getenv("QUERY_STRING");
	printf("Content-type:text/html\n\n");
	printf("<html> <head> <meta charset=\"UTF-8\"> <meta http-equiv=\"Content-Type\" content=\"text/html"";"" charset=UTF-8\"> <meta name=\"renderer\" content=\"webkit\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Home</title> <style type='text/css'> #top_title, #sideMenu { display: none"";"" } #content { width: 100%%"";"" margin: 0"";"" padding: 0"";"" } </style> <!--jQuery--> <script src=\"../jquery_min.js\"></script> <!--bootstrap--> <link href=\"../bootstrap_min.css\" rel=\"stylesheet\"> <script src=\"../bootstrap_min.js\"></script> <!--customer--> <link href=\"../nav.css\" rel=\"stylesheet\"> <link href=\"../customer.css\" rel=\"stylesheet\"> </head><body><div class=\"container-fluid\" style=\"background-color: black\"><p style=\"float: left"";"" font-size: 30px"";"" height: 40px"";"" color: #cccccc\">1 2 3 0 6</p>\n");
	urldecode(data);
	int p, q, n;
	char value[4][32];
	p = 0;
	for(q = 0; q < 4; q++)
	{
		while(data[p] != '=')
			p++;
		p++;n=0;
		while(data[p] != '&' && p < strlen(data))
		{
			value[q][n] = data[p];
			p++;n++;
		}
		value[q][n] = '\0';
	}
	int   param_len[2]= {0};
    	int   param_format[2]= {0}; 
	const Oid paramTypes[2] = {1043,1043};
	char *param_val[2] ={value[0],value[1]};

	PGresult *Qx = PQprepare(conn, "check", "select * from client where national_id = $1 and passward = $2;", 2, paramTypes);
	char *param_valx[2] = {value[2], value[3]};
	Qx = PQexecPrepared(conn, "check", 2, (const char **)param_valx, param_len, param_format, 0);
	int num_rowsx = PQntuples(Qx);
	if(num_rowsx) printf(" <nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\">  <ul>  <li><a href=\"index.cgi?身份证=%s&密码=%s\">主页</a></li>  <li><a href=\"train.cgi?身份证=%s&密码=%s\">查车</a></li>  <li><a href=\"ticket.cgi?身份证=%s&密码=%s\">查票</a></li>  <li><a href=\"booking.cgi?身份证=%s&密码=%s\">预定</a></li>  <li><a href=\"../index.html\">登出</a></li>  <li><a href=\"order.cgi?身份证=%s&密码=%s\">订单</a></li>  <li><a href=\"administrator.cgi?身份证=%s&密码=%s\">管理员</a></li>  </ul>  </nav>  </div>\n<div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n",value[2],value[3],value[2],value[3],value[2],value[3],value[2],value[3],value[2],value[3],value[2],value[3]);
	else printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li><li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");

	PGresult *Q1 = PQprepare(conn, "login","select * from administrator where account = $1 and passward = $2;", 2, paramTypes);
	Q1= PQexecPrepared(conn, "login", 2, (const char **)param_val, param_len, param_format, 0);
	ExecStatusType status = PQresultStatus(Q1);
	int num_rows = PQntuples(Q1);
	if((status != PGRES_TUPLES_OK) && (status != PGRES_SINGLE_TUPLE) && (num_rows != 1))
	{
		printf("failed execution: %s\n", PQresultErrorMessage(Q1));
		printf("账号密码错误！\n");
		PQfinish(conn);
     		return 0;
	}
	
	PGresult *Q2 = PQexec(conn, "select distinct order_id, national_id from order_table;");
	num_rows = PQntuples(Q2);
	printf("<br/><p style=\"font-size:20px\">总订单数为 : %d个</p>",num_rows);
	Q2 = PQexec(conn, "select sum(price) from order_table;");
	num_rows = PQntuples(Q2);
	double money1 = (num_rows == 0 ) ? 0 : atof(PQgetvalue(Q2, 0, 0));
	Q2 = PQexec(conn, "select * from order_table;");
	num_rows = PQntuples(Q2);
	int money2 = num_rows * 5;
	printf("<br/><p style=\"font-size:20px\">总票价(总订票费) :%.1f元 (%d元)</p>",money1, money2);
	Q2 = PQexec(conn, "select train_id, countt from ( select train_id, row_number() over(order by countt desc) as rownum, countt from ( select distinct train_id, COUNT(*) over(PARTITION by train_id) countt from order_table ) as t1 ) as t2 order by rownum;");
	num_rows = PQntuples(Q2);
	printf("<table class=\"table table-striped table-bordered\" style=\"color:#999999"";""background-color:#222222"";""width:100%%\" border=2 align=center><caption align=\"top\">Top10最热点车次信息</caption>\n<tr><th align=\"right\">序号</th><th align=\"right\">车次</th><th align=\"right\">购买次数</th>");
		int i, r;
		char *val;
		for(r = 0; r < num_rows && r < 10; r++)
		{
			printf("<tr>");
			if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
			else printf("<td align=\"right\" style=\"color:black\">");
			printf("%d</td>",r + 1);
			for(i = 0; i < 2; i++)
			{
				val = PQgetvalue(Q2, r, i);
				if(r % 2 == 0) printf("<td align=\"right\" style=\"color:white\">");
				else printf("<td align=\"right\" style=\"color:black\">");
				printf("%s", val);
				printf("</td>");
			}
			printf("</tr>\n");
		}
		printf("</table>");
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
  
