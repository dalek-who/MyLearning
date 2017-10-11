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
	char *data;
	data = getenv("QUERY_STRING");
	printf("Content-type:text/html\n\n");
	printf("<html> <head> <meta charset=\"UTF-8\"> <meta http-equiv=\"Content-Type\" content=\"text/html"";"" charset=UTF-8\"> <meta name=\"renderer\" content=\"webkit\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Home</title> <style type='text/css'> #top_title, #sideMenu { display: none"";"" } #content { width: 100%%"";"" margin: 0"";"" padding: 0"";"" } </style> <!--jQuery--> <script src=\"../jquery_min.js\"></script> <!--bootstrap--> <link href=\"../bootstrap_min.css\" rel=\"stylesheet\"> <script src=\"../bootstrap_min.js\"></script> <!--customer--> <link href=\"../nav.css\" rel=\"stylesheet\"> <link href=\"../customer.css\" rel=\"stylesheet\"> </head><body><div class=\"container-fluid\" style=\"background-color: black\"><p style=\"float: left"";"" font-size: 30px"";"" height: 40px"";"" color: #cccccc\">1 2 3 0 6</p>\n");
	urldecode(data);
	int p, q, n;
	char value[2][32] = {'\0'};
	p = 0;	
	for(q = 0; q < 2; q++)
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
	PGconn* conn = PQconnectdb("dbname=train");
	int   param_len[2]= {0};
    	int   param_format[2]= {0}; 
	const Oid paramTypes[2] = {1043,1043}; 
	PGresult *Qx = PQprepare(conn, "check", "select * from client where national_id = $1 and passward = $2;", 2, paramTypes);
	char *param_valx[2] = {value[0], value[1]};
	Qx = PQexecPrepared(conn, "check", 2, (const char **)param_valx, param_len, param_format, 0);
	int num_rowsx = PQntuples(Qx);
	PQfinish(conn);
	if(num_rowsx) printf(" <nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\">  <ul>  <li><a href=\"index.cgi?身份证=%s&密码=%s\">主页</a></li>  <li><a href=\"train.cgi?身份证=%s&密码=%s\">查车</a></li>  <li><a href=\"ticket.cgi?身份证=%s&密码=%s\">查票</a></li>  <li><a href=\"booking.cgi?身份证=%s&密码=%s\">预定</a></li>  <li><a href=\"../index.html\">登出</a></li>  <li><a href=\"order.cgi?身份证=%s&密码=%s\">订单</a></li>  <li><a href=\"administrator.cgi?身份证=%s&密码=%s\">管理员</a></li>  </ul>  </nav>  </div>\n<div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n",value[0],value[1],value[0],value[1],value[0],value[1],value[0],value[1],value[0],value[1],value[0],value[1]);
	else printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li>  <li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");
	
	printf("<p> <form method=\"get\" action=\"/cgi-bin/admin.cgi\"> 管理员账号 : <input type=\"text\" name=\"账号\"> 密码 : <input type=\"password\" name=\"密码\"> <input type=\"hidden\" name=\"身份证\" value=\"%s\"> <input type=\"hidden\" name=\"密码\" value=\"%s\"> <input type=\"submit\" value=\"提交\"> </form>",value[0],value[1]);

	printf("</div></div></body></html>");

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
  
