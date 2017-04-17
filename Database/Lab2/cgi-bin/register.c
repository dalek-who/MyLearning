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
int test(char *str)
{
	int len = strlen(str);
	int i;
	for(i = 0; i < len; i++)
		if(str[i] >'9' || str[i] < '0')
			return 0;
	return 1;
}
int main()
{
	printf("Content-type:text/html\n\n");
	PGconn* conn = PQconnectdb("dbname=train");
	char *data;
	data = getenv("QUERY_STRING");
	printf("<html> <head> <meta charset=\"UTF-8\"> <meta http-equiv=\"Content-Type\" content=\"text/html"";"" charset=UTF-8\"> <meta name=\"renderer\" content=\"webkit\"> <meta http-equiv=\"X-UA-Compatible\" content=\"IE=edge\"> <meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\"> <title>Home</title> <style type='text/css'> #top_title, #sideMenu { display: none"";"" } #content { width: 100%%"";"" margin: 0"";"" padding: 0"";"" } </style> <!--jQuery--> <script src=\"../jquery_min.js\"></script> <!--bootstrap--> <link href=\"../bootstrap_min.css\" rel=\"stylesheet\"> <script src=\"../bootstrap_min.js\"></script> <!--customer--> <link href=\"../nav.css\" rel=\"stylesheet\"> <link href=\"../customer.css\" rel=\"stylesheet\"> </head><body><div class=\"container-fluid\" style=\"background-color: black\"><p style=\"float: left"";"" font-size: 30px"";"" height: 40px"";"" color: #cccccc\">1 2 3 0 6</p>\n");
	printf("<nav class=\"homeNav\" style=\"float: right"";"" font-size: 22px\"> <ul> <li><a href=\"../index.html\">主页</a></li> <li><a href=\"../train.html\">查车</a></li> <li><a href=\"../query.html\">查票</a></li> <li><a href=\"../booking.html\">预定</a></li> <li><a href=\"../signin.html\">登录</a></li>  <li><a href=\"../admin.html\">管理员</a></li> </ul> </nav> </div><div class=\"container home-content\" style=\"background-color: white\"> <div class=\"row\" style=\"text-align: center\">\n");
	urldecode(data);
	int p, q, n;
	char value[6][32];
	p = 0;
	for(q = 0; q < 6; q++)
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
	int   param_len[6]= {0};
    	int   param_format[6]= {0}; 
	const Oid paramTypes[6] = {1043,1043,1043,1043,1043,1043};
	char *param_val[6] ={value[0],value[1],value[2],value[3],value[4],value[5]};
	//printf("%s %s %s %s %s %s",value[0],value[1],value[2],value[3],value[4],value[5]);
	if(!test(value[0]) || !test(value[3]) || !test(value[5]) || strlen(value[0])!=18 || strlen(value[3])!=10 || strlen(value[5])!=16 )
	{
		printf("<br/><p style=\"font-size:20px\">非法输入！输出不合法！\n");
		printf("请再次输入！</p>\n");
		printf("<p> <form method=\"get\" action=\"/cgi-bin/register.cgi\"> 身份证 18位: <input type=\"text\" name=\"身份证\"> </p><p> .. 密 .... 码 ..: <input type=\"password\" name=\"密码\"> </p><p> .. 姓 .... 名 ..: <input type=\"text\" name=\"姓名\"> </p><p> 电话 10位 ..: <input type=\"text\" name=\"电话\"> </p><p> 开 户 银 行: <input type=\"text\" name=\"开户银行\"> </p><p> 信用卡 16位: <input type=\"text\" name=\"信用卡\"></p><p> <input type=\"submit\" value=\"Submit\"> </form> </div> </div> </body> </html>");
		PQfinish(conn);
     		return 0;
	}
	PGresult *Q1 = PQprepare(conn, "register","insert into client(National_ID, Passward, Name, Phone, Bank, Credit_Card) values($1,$2,$3,$4,$5,$6);", 6, paramTypes);

	Q1= PQexecPrepared(conn, "register", 6, (const char **)param_val, param_len, param_format, 0);
	ExecStatusType status = PQresultStatus(Q1);
	if(status !=  PGRES_COMMAND_OK)
	{
		//printf("failed execution: %s\n", PQresultErrorMessage(Q1));
		printf("<br/><p style=\"font-size:20px\">非法输入！用户已存在！\n");
		printf("请再次输入！</p>\n");
	}
	else {printf("<br/><p style=\"font-size:20px\">注册成功！\n</p>");printf("<br/><p style=\"font-size:18px\">您的注册信息是<br/>身份证%s<br/>密码%s<br/>姓名%s<br/>电话%s<br/>银行%s<br/>信用卡%s</p></div></div></body></html>",value[0],value[1],value[2],value[3],value[4],value[5]);PQfinish(conn);return 0;}
	printf("<p> <form method=\"get\" action=\"/cgi-bin/register.cgi\"> 身份证 18位: <input type=\"text\" name=\"1\"> </p><p> .. 密 .... 码 ..: <input type=\"passward\" name=\"2\"> </p><p> .. 姓 .... 名 ..: <input type=\"text\" name=\"3\"> </p><p> 电话 10位 ..: <input type=\"text\" name=\"4\"> </p><p> .. 银 .... 行 ..: <input type=\"text\" name=\"5\"> </p><p> 信用卡 16位: <input type=\"text\" name=\"6\"> </p><p> <input type=\"submit\" value=\"注册\"> </form> </div> </div> </body>");
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
  
