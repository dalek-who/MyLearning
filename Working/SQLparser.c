#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "SQLparser.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("No file.");
		return -1;
	}
	if (access("db",0) == -1)
    	mkdir("db", 0777);
	FILE *fp;
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		printf("No file %s.", argv[1]);
		return -1;
	}
	char *sql_sentence;
	int cursor, flag;
	int len;
	while(!feof(fp))
	{
		sql_sentence = (char *)calloc(MAX_LENGTH, sizeof(char));
		len = MAX_LENGTH;
		sql_sentence[0] = '\0';
		flag = 0;
		while(stop_signal(sql_sentence, cursor) && !feof(fp))
		{
			cursor = strlen(sql_sentence);
			sql_sentence[cursor++] = ' ';
			if(cursor >= MAX_LENGTH){
				sql_sentence = realloc(sql_sentence, MAX_LENGTH + len);
				len += MAX_LENGTH;
			}
			fgets(sql_sentence + cursor, len - cursor, fp);
			flag = find_critical(sql_sentence, cursor, flag);
			if(flag == 2)
			{
				flag = 1;
				cursor = 0;
			}
		}
		if(flag == 0)
		{
			if(feof(fp))
				if(ignore_blank(sql_sentence, 0) == strlen(sql_sentence))
					break;
			else error_print(sql_sentence);
		}
		if(classifier(sql_sentence) == 0)
			error_print(sql_sentence);
		// else printf("GOOD\n");
		free(sql_sentence);
	}
	fclose(fp);
	return 0;
}

int classifier(char *sql_sentence)
{
	int i;
	int cursor = 0;
	char *word;
	trans_lower(sql_sentence);
	for(i = 0; i < strlen(sql_sentence); i++)
		printf("%c", sql_sentence[i]);
	printf("\n");
	word = (char *)malloc(MAX_LENGTH);
	cursor = get_word(word, sql_sentence, cursor);
	int flag;
	if(strcmp(word, sql_create) == 0)
		flag = parser_create(sql_sentence, cursor);
	else if(strcmp(word, sql_drop) == 0)
		flag = parser_drop(sql_sentence, cursor);
	else if(strcmp(word, sql_insert) == 0)
		flag = parser_insert(sql_sentence, cursor);
	else if(strcmp(word, sql_select) == 0)
		flag = parser_select(sql_sentence, cursor);
	free(word);
	return flag;
}
int parser_create(char *sql_sentence, int cursor)
{
	int nextword = 0;
	char *word;
	word = (char *)malloc(MAX_LENGTH);

	char *table_name = NULL;
	int columnnum = 0;
	column_type_t *column;
	column = (column_type_t *)malloc(sizeof(column_type_t) * MAX_COLUMN);
	
	//table
	cursor = get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_table) != 0)
		goto create_fail;
	//table_name
	cursor = get_word(word, sql_sentence, cursor);
	if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME)
		goto create_fail;
	table_name = (char *)malloc(strlen(word) + 1);
	strncpy(table_name, word, strlen(word) + 1);

	if(sql_sentence[cursor] != '(')
		goto create_fail;
	cursor++;
	int i;
	char *name;
	while(1)
	{
		//column name
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME)
			goto create_fail;
		name = (char *)malloc(strlen(word) + 1);
		strncpy(name, word, strlen(word) + 1);
		column[columnnum].name = name;
		columnnum++;
		//column type
		cursor = get_word(word, sql_sentence, cursor);
		if(strcmp(word, sql_int) == 0 || strcmp(word, sql_varchar) == 0)
		{

			for(i = 0; i < columnnum - 1; i++)
				if(strcmp(name, column[i].name) == 0)
					goto create_fail;
			if(strcmp(word, sql_int) == 0)
				column[columnnum - 1].type = INT;
			else column[columnnum - 1].type = VARCHAR;
			// printf("%s\n", column[columnnum].name);
		}
		else goto create_fail;
		if(sql_sentence[cursor] == ',')
			cursor++;
		else if(sql_sentence[cursor] == ')')
			break;
		else goto create_fail;
	}
	cursor++;
	cursor = ignore_blank(sql_sentence, cursor);
	if(sql_sentence[cursor] != ';')
		return 0;
	create_table(table_name, column, columnnum);
	free(word);
	free(table_name);
	for(i = 0; i < columnnum; i++)
		free(column[i].name);
	free(column);
	return 1;

create_fail:
	free(word);
	if(table_name != NULL)
		free(table_name);
	for(i = 0; i < columnnum; i++)
		free(column[i].name);
	free(column);
	return 0;
}
int parser_drop(char *sql_sentence, int cursor)
{
	int nextword = 0;
	char *word;
	word = (char *)malloc(MAX_LENGTH);

	char *table_name = NULL;
	
	//table
	cursor = get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_table) != 0)
		goto drop_fail;

	//table_name
	cursor = get_word(word, sql_sentence, cursor);
	if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME)
		goto drop_fail;
	table_name = (char *)malloc(strlen(word) + 1);
	strncpy(table_name, word, strlen(word) + 1);

	if(sql_sentence[cursor] != ';')
		goto drop_fail;
	drop_table(table_name);

	free(word);
	free(table_name);
	return 1;

drop_fail:
	free(word);
	if(table_name != NULL)
		free(table_name);
	return 0;
}
int parser_select(char *sql_sentence, int cursor)
{
	int nextword = 0;
	char *word;
	word = (char *)malloc(MAX_LENGTH);

	char *table_name = NULL;
	char *table_name2 = NULL;
	int columnnum = 0;
	char **columnname;
	columnname = (char **)malloc(sizeof(char *) * MAX_COLUMN);
	condition_t *condition = NULL;

	int i;
	char *name;
	while(1)
	{
		//column name
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME)
			goto select_fail;
		name = (char *)malloc(strlen(word) + 1);
		strncpy(name, word, strlen(word) + 1);
		columnname[columnnum] = name;
		columnnum++;
		if(strcmp(word, sql_all) == 0)
			break;
		if(sql_sentence[cursor] == ',')
			cursor++;
		else if(sql_sentence[cursor] == 'f')
			break;
		else goto select_fail;
	}
	//from
	cursor = get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_from) != 0)
		goto select_fail;

	//table_name
	cursor = get_word(word, sql_sentence, cursor);
	if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME)
		goto select_fail;
	table_name = (char *)malloc(strlen(word) + 1);
	strncpy(table_name, word, strlen(word) + 1);

	//table_name2
	cursor = get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_where) != 0 && strlen(word) != 0)
	{
		if(strlen(word) > MAX_COLUMN_NAME)
			goto select_fail;
		table_name2 = (char *)malloc(strlen(word) + 1);
		strncpy(table_name2, word, strlen(word) + 1);
		cursor = get_word(word, sql_sentence, cursor);
	}

	//where
	if(strcmp(word, sql_where) == 0)
	{
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) == 0)
			goto select_fail;
		//column_name
		condition = (condition_t *)malloc(sizeof(condition_t));
		name = (char *)malloc(strlen(word));
		strncpy(name, word, strlen(word) + 1);
		condition->columnname = name;
		condition->condition_varchar = NULL;

		//op
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) == 0)
		{
			if(sql_sentence[cursor] == '<')
			{
				cursor++;
				if(sql_sentence[cursor] == '=')
				{
					cursor++;
					condition->op = op_leq;
				}
				else condition->op = op_l;
			}
			else if(sql_sentence[cursor] == '>')
			{
				cursor++;
				if(sql_sentence[cursor] == '=')
				{
					cursor++;
					condition->op = op_geq;
				}
				else condition->op = op_g;
			}
			else if(sql_sentence[cursor] == '!')
			{
				cursor++;
				if(sql_sentence[cursor] == '=')
				{
					cursor++;
					condition->op = op_neq;
				}
				else goto select_fail;
			}
			else if(sql_sentence[cursor] == '=')
			{
				cursor++;
				condition->op = op_eq;
			}
			else goto select_fail;
		}
		else
		{
			if(strcmp(word, sql_not) == 0)
			{
				cursor = get_word(word, sql_sentence, cursor);
				if(strcmp(word, sql_like) == 0)
					condition->op = op_nlike;
				else goto select_fail;
			}
			else if(strcmp(word, sql_like) == 0)
				condition->op = op_like;
			else goto select_fail;
		}
		//condition
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) == 0)
			goto select_fail;
		if(word[0] == '\'')
		{

			if(condition->op != op_like && condition->op != op_nlike && condition->op != op_eq && condition->op != op_neq)
				goto select_fail;
			name = (char *)malloc(strlen(word));
			strncpy(name, word + 1, strlen(word));
			condition->type = VARCHAR;
			condition->condition_varchar = name;
		}
		else
		{
			if(condition->op == op_like || condition->op == op_nlike)
				goto select_fail;
			condition->type = INT;
			for(i = 0; i < strlen(word); i++)
				if(word[i] > '9' || word[i] < '0')
					goto select_fail;
			condition->condition_int = atoi(word);
		}
	}
	if(sql_sentence[cursor] != ';')
		goto select_fail;
	if(strcmp(columnname[columnnum - 1], sql_all) == 0)
	{
		if(columnnum != 1)
			goto select_fail;
		select_all_1(table_name, condition);
	}
	// else select_partial(table_name, columnname, columnnum, condition);

	free(word);
	free(table_name);
	for(i = 0; i < columnnum; i++)
		free(columnname[i]);
	free(columnname);
	if(condition != NULL)
	{
		free(condition->columnname);
		if(condition->condition_varchar != NULL)
			free(condition->condition_varchar);
		free(condition);
	}
	return 1;

select_fail:
	free(word);
	if(table_name != NULL)
		free(table_name);
	for(i = 0; i < columnnum; i++)
		free(columnname[i]);
	free(columnname);
	if(condition != NULL)
	{
		free(condition->columnname);
		if(condition->condition_varchar != NULL)
			free(condition->condition_varchar);
		free(condition);
	}
	return 0;
}
int parser_insert(char *sql_sentence, int cursor)
{
	int nextword = 0;
	char *word;
	word = (char *)malloc(MAX_LENGTH);

	char *table_name = NULL;
	int columnnum = 0;
	insert_t *insert;
	insert = (insert_t *)malloc(sizeof(insert_t) * MAX_COLUMN);

	//into
	cursor = get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_into) != 0)
		goto insert_fail;

	//table_name
	cursor = get_word(word, sql_sentence, cursor);
	if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME)
		goto insert_fail;
	table_name = (char *)malloc(strlen(word) + 1);
	strncpy(table_name, word, strlen(word) + 1);

	//values
	cursor = get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_values) != 0)
		goto insert_fail;

	if(sql_sentence[cursor] != '(')
		goto insert_fail;
	cursor++;
	int i;
	char *name;
	while(1)
	{
		//column name
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) == 0)
			goto insert_fail;
		if(word[0] == '\'')
		{
			name = (char *)malloc(strlen(word));
			strncpy(name, word + 1, strlen(word));
			insert[columnnum].type = VARCHAR;
			insert[columnnum].content_varchar = name;
			// printf("s--%s ", insert[columnnum].content_varchar);
			columnnum++;
		}
		else
		{
			insert[columnnum].type = INT;
			for(i = 0; i < strlen(word); i++)
				if(word[i] > '9' || word[i] < '0')
					goto insert_fail;
			insert[columnnum].content_int = atoi(word);
			// printf("d--%d ", insert[columnnum].content_int);
			columnnum++;
		}
		if(sql_sentence[cursor] == ',')
			cursor++;
		else if(sql_sentence[cursor] == ')')
			break;
		else goto insert_fail;
	}
	cursor++;
	cursor = ignore_blank(sql_sentence, cursor);
	if(sql_sentence[cursor] != ';')
		goto insert_fail;

	// insert_table(table_name, insert, columnnum);

	free(word);
	free(table_name);
	if(table_name2 != NULL)
		free(table_name2);
	for(i = 0; i < columnnum; i++)
		if(insert[i].type == VARCHAR)
			free(insert[i].content_varchar);
	free(insert);
	return 1;

insert_fail:
	free(word);
	if(table_name != NULL)
		free(table_name);
	if(table_name2 != NULL)
		free(table_name2);
	for(i = 0; i < columnnum; i++)
		if(insert[i].type == VARCHAR)
			free(insert[i].content_varchar);
	free(insert);
	return 0;
}
int find_critical(char *sql_sentence, int cursor, int flag)
{
	int i;
	char *word;
	int length = strlen(sql_sentence);
	word = (char *)malloc(MAX_LENGTH);
	get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_create) == 0 
		|| strcmp(word, sql_drop) == 0
		|| strcmp(word, sql_select) == 0
		|| strcmp(word, sql_insert) == 0)
	{
		flag++;
		if(flag > 1)
		{
			error_print(sql_sentence);
			strncpy(sql_sentence, sql_sentence + cursor, strlen(sql_sentence) - cursor);
			// for(i = 0; i < strlen(sql_sentence) - cursor; i++)
			// 	sql_sentence[i] = sql_sentence[i + cursor];
			// sql_sentence[i] = '\0';
		}
	}
	free(word);
	return flag;
}
int stop_signal(char *sql_sentence, int cursor)
{
	int i;
	for(i = cursor; i < strlen(sql_sentence); i++)
		if(sql_sentence[i] == '-')
			if(sql_sentence[i + 1] == '-')
			{
				sql_sentence[i] = '\0';
				return 1;
			}
	for(i = cursor; i < strlen(sql_sentence); i++)
		if(sql_sentence[i] == ';')
			return 0;
	return 1;
}
int ignore_blank(char *sql_sentence, int cursor)
{
	while(sql_sentence[cursor] == ' ' || sql_sentence[cursor] == '\n' || sql_sentence[cursor] == '\r' || sql_sentence[cursor] == '\f')
		if(cursor == strlen(sql_sentence))
			break;
		else cursor++;
	return cursor;
}
int get_word(char *word, char *sql_sentence, int cursor)
{
	int i = -1, j, flag = 1;
	cursor = ignore_blank(sql_sentence, cursor);
	if(sql_sentence[cursor] == '\'')
	{
		for(i = 1; cursor + i < strlen(sql_sentence); i++)
			if(sql_sentence[cursor + i] == '\'')
				break;
	}
	else while(flag)
	{
		i++;
		if(cursor + i == strlen(sql_sentence))
			break;
		for(j = 0; j < IGNORE_NUMBER; j++)
			if(sql_sentence[cursor + i] == ignore[j])
				flag = 0;
	}
	strncpy(word, sql_sentence + cursor, i);
	word[i] = '\0';
	if(flag)
		cursor++;
	cursor = cursor + i;
	cursor = ignore_blank(sql_sentence, cursor);
	// printf("%s--%c\n", word,sql_sentence[cursor]);
	return cursor;
}
void error_print(char *sql_sentence)
{
	int i;
	// for(i = 0; i < strlen(sql_sentence); i++)
	// 	printf("%c", sql_sentence[i]);
	// printf("\n");
	printf("%s\n", error_grammar);
}
void trans_lower(char *sql_sentence)
{
	int i;
	for(i = 0; i < strlen(sql_sentence); i++)
		if(sql_sentence[i] >= 'A' && sql_sentence[i] <= 'Z')
			sql_sentence[i] = sql_sentence[i] + 'a' - 'A';
}