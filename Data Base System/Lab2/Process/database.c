#include <stdio.h>
#include <stdlib.h>
#include <postgresql/libpq-fe.h>

int main(int argc, char *argv[])
{
	PGconn* conn = PQconnectdb("dbname=train");
	if(PQstatus(conn) != CONNECTION_OK)
	{
		fprintf(stderr, "Connection to db failed: %s", PQerrorMessage(conn));
		PQfinish(conn);
		return 1;
	}

	PGresult *res = PQexec(conn, "select * from The_Date");
	ExecStatusType status = PQresultStatus(res);
	if((status != PGRES_TUPLES_OK) && (status != PGRES_SINGLE_TUPLE) && (status !=  PGRES_COMMAND_OK))
	{
		fprintf(stderr, "failed execution: %s\n", PQresultErrorMessage(res));
		PQfinish(conn);
		return 1;
	}
	/*
	int num_rows = PQntuples(res);
	int num_cols = PQnfields(res);
	int i, r;
	char *val;
	for(i = 0; i < num_cols; i++)
	{
		printf("%s", PQfname(res, i));
		printf("%c", (i < num_cols - 1)? ',':'\n');
	}
	for(r = 0; r < num_rows; r++)
		for(i = 0; i < num_cols; i++)
		{
			val = PQgetvalue(res, r, i);
			printf("%s", val);
			printf("%c", (i < num_cols - 1)? ',':'\n');
		}
	*/
	//printf("<html>\n<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\" />\n<body>\n");
	PQprintOpt po = {0};
	po.header = 0; po.align = 0; po.fieldSep = "|";
	//po.html3 = 1; po.caption = "Information"; po.tableOpt = "border=1";
	PQprint(stdout, res, &po);
	//printf("</body></html>\n");
	PQclear(res);

	PQfinish(conn);
	return 0;
}
