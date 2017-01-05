//
//  SQLparser.c
//  database
//
//  Created by 孔静 on 2016/12/24.
//  Copyright © 2016年 University of Chinese Academy of Sciences. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "SQLparser.h"
#include "SQLexec.h"

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("No file.\n");
		return -1;
	}
	if (access("db",0) == -1)
    	mkdir("db", 0777);
	FILE *fp;
	fp = fopen(argv[1],"r");
	if(fp == NULL)
	{
		printf("No file %s.\n", argv[1]);
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
			while(!feof(fp))
			{
				if(strlen(sql_sentence) >= len - 1)
				{
					sql_sentence = realloc(sql_sentence, MAX_LENGTH + len);
					len += MAX_LENGTH;
				}
				fgets(sql_sentence + strlen(sql_sentence), len - strlen(sql_sentence) - 1, fp);
				if(sql_sentence[strlen(sql_sentence) - 1] == '\n')
					break;//确保读取了一行。
			}
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
				{
					free(sql_sentence);
					break;
				}
			else
			{
				error_print(sql_sentence);
				free(sql_sentence);
			}
		}
		else if(classifier(sql_sentence) == 0)
			error_print(sql_sentence);
	}
	fclose(fp);
	return 0;
}

int classifier(char *sql_sentence)
{
	int i;
	int cursor = 0;
	char *word;
	// trans_lower(sql_sentence);
	// for(i = 0; i < strlen(sql_sentence); i++)
		// printf("%c", sql_sentence[i]);
	// printf("\n");
	word = (char *)malloc(MAX_LENGTH);
	cursor = get_word(word, sql_sentence, cursor);
	int flag = 0;
	if(strcmp(word, sql_create) == 0)
		flag = parser_create(sql_sentence, cursor);
	else if(strcmp(word, sql_drop) == 0)
		flag = parser_drop(sql_sentence, cursor);
	else if(strcmp(word, sql_insert) == 0)
		flag = parser_insert(sql_sentence, cursor);
	else if(strcmp(word, sql_select) == 0)
		flag = parser_select(sql_sentence, cursor);
	else free(sql_sentence);
	free(word);
	return flag;
}
int parser_create(char *sql_sentence, int cursor)
{
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
	if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME || word[0] > 'z' || word[0] < 'a')
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
		if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME || word[0] > 'z' || word[0] < 'a')
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
	free(sql_sentence);
	create_table(table_name, column, columnnum);
	free(word);
	free(table_name);
	for(i = 0; i < columnnum; i++)
		free(column[i].name);
	free(column);
	return 1;

create_fail:
	free(sql_sentence);
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
	char *word;
	word = (char *)malloc(MAX_LENGTH);

	char *table_name = NULL;
	
	//table
	cursor = get_word(word, sql_sentence, cursor);
	if(strcmp(word, sql_table) != 0)
		goto drop_fail;

	//table_name
	cursor = get_word(word, sql_sentence, cursor);
	if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME || word[0] > 'z' || word[0] < 'a')
		goto drop_fail;
	table_name = (char *)malloc(strlen(word) + 1);
	strncpy(table_name, word, strlen(word) + 1);

	if(sql_sentence[cursor] != ';')
		goto drop_fail;

	free(sql_sentence);
	drop_table(table_name);

	free(word);
	free(table_name);
	return 1;

drop_fail:
	free(sql_sentence);
	free(word);
	if(table_name != NULL)
		free(table_name);
	return 0;
}
int parser_select(char *sql_sentence, int cursor)
{
	char *word;
	word = (char *)malloc(MAX_LENGTH);

	char *tablename[2] = {NULL, NULL};
	int columnnum = 0;
	char **columnname;
	char **table_names;
	char *table_name;
	char *type;
	columnname = (char **)malloc(sizeof(char *) * MAX_COLUMN);
	table_name = (char *)malloc(sizeof(char) * MAX_COLUMN);
	table_names = (char **)malloc(sizeof(char *) * MAX_COLUMN);
	type = (char *)malloc(sizeof(char) * MAX_COLUMN);

	condition_t *condition[3] = {NULL, NULL, NULL};
	char condition_table[3];

	join_condition_t *join_condition = NULL;

	char *group = NULL;
	char group_table = -1;
	
	int i;
	char *name;
	while(1)
	{
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) > MAX_COLUMN_NAME)
			goto select_fail;
		if(strlen(word) == 0)
		{
			if(sql_sentence[cursor] == '*' && columnnum == 0)
			{
				cursor++;
				break;
			}
			else goto select_fail;
		}
		else if(word[0] > 'z' || word[0] < 'a')
			goto select_fail;
		type[columnnum] = 0;
		//count
		if(strcmp(word, sql_count) == 0)
			type[columnnum] = 1;
		//avg
		if(strcmp(word, sql_avg) == 0)
			type[columnnum] = 2;
		//sum
		if(strcmp(word, sql_sum) == 0)
			type[columnnum] = 3;
		//min
		if(strcmp(word, sql_min) == 0)
			type[columnnum] = 4;
		//max
		if(strcmp(word, sql_max) == 0)
			type[columnnum] = 5;

		if(type[columnnum] > 0)
		{
			group_table = -2;
			if(sql_sentence[cursor] != '(')
				goto select_fail;
			cursor++;
			cursor = get_word(word, sql_sentence, cursor);
			if(strlen(word) > MAX_COLUMN_NAME)
				goto select_fail;
			if(strlen(word) == 0 && sql_sentence[cursor] == '*' && type[columnnum] == 1)
			{
				cursor++;
				columnname[columnnum] = (char *)malloc(2);//for free no use
				columnname[columnnum][0] = '*';
				columnname[columnnum][1] = '\0';
				table_names[columnnum] = NULL;
				type[columnnum] = -1;
				columnnum++;
				cursor = ignore_blank(sql_sentence, cursor);
				if(sql_sentence[cursor] != ')')
					goto select_fail;
				cursor++;
				cursor = ignore_blank(sql_sentence, cursor);
				if(sql_sentence[cursor] == 'f')
					break;
				else if(sql_sentence[cursor] == ',')
					cursor++;
				else goto select_fail;
				continue;
			}
			else if(strlen(word) == 0 || word[0] > 'z' || word[0] < 'a')
				goto select_fail;
		}
		
		name = (char *)malloc(strlen(word) + 1);
		strncpy(name, word, strlen(word) + 1);
		//table_name
		if(sql_sentence[cursor] == '.')
		{
			table_names[columnnum] = name;
			cursor++;
			cursor = get_word(word, sql_sentence, cursor);
			if(strlen(word) > MAX_COLUMN_NAME || strlen(word) == 0 || word[0] > 'z' || word[0] < 'a')
				goto select_fail;
			name = (char *)malloc(strlen(word) + 1);
			strncpy(name, word, strlen(word) + 1);
		}
		else table_names[columnnum] = NULL;
		//column_name
		columnname[columnnum] = name;
		if(type[columnnum] > 0)
		{
			if(sql_sentence[cursor] != ')')
				goto select_fail;
			cursor++;
			cursor = ignore_blank(sql_sentence, cursor);
		}
		columnnum++;

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

	//tablename[0]
	cursor = get_word(word, sql_sentence, cursor);
	if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME || word[0] > 'z' || word[0] < 'a')
		goto select_fail;
	tablename[0] = (char *)malloc(strlen(word) + 1);
	strncpy(tablename[0], word, strlen(word) + 1);

	//tablename[1]
	if(sql_sentence[cursor] == ',')
	{
		cursor++;
		cursor = get_word(word, sql_sentence, cursor);
		if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME || strcmp(word, tablename[0]) == 0 || word[0] > 'z' || word[0] < 'a')
			goto select_fail;
		tablename[1] = (char *)malloc(strlen(word) + 1);
		strncpy(tablename[1], word, strlen(word) + 1);
	}
	
	//check table name
	for(i = 0; i < columnnum; i++)
		if(table_names[i] != NULL)
		{
			if(strcmp(table_names[i], tablename[0]) == 0)
				table_name[i] = 1;
			else if(tablename[1] != NULL)
			{
				if(strcmp(table_names[i], tablename[1]) == 0)
					table_name[i] = 2;
				else goto select_fail;
			}
			else goto select_fail;
		}
		else table_name[i] = 0;
	
	cursor = get_word(word, sql_sentence, cursor);
	//where
	i = 0;
	int j = 0, k = 0;
	if(strcmp(word, sql_where) == 0)
	{
		while(j < 3)
		{
			condition_table[j - k] = 0;
			cursor = get_word(word, sql_sentence, cursor);
			if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME || word[0] > 'z' || word[0] < 'a')
				goto select_fail;
			
			if(j > 0)
			{
				if(strcmp(word, sql_and) == 0)
					cursor = get_word(word, sql_sentence, cursor);
				else if(strcmp(word, sql_group) == 0)
					break;
				else goto select_fail;
			}
				
			//table_name
			if(sql_sentence[cursor] == '.')
			{
				if(strcmp(word, tablename[0]) == 0)
					condition_table[j - k] = 1;
				else if(tablename[1] != NULL)
				{
					if(strcmp(word, tablename[1]) == 0)
						condition_table[j - k] = 2;
					else goto select_fail;
				}
				else goto select_fail;
				cursor++;
				cursor = get_word(word, sql_sentence, cursor);
				if(strlen(word) > MAX_COLUMN_NAME || strlen(word) == 0 || word[0] > 'z' || word[0] < 'a')
					goto select_fail;
			}
			else condition_table[j - k] = 0;
			//column_name
			name = (char *)malloc(strlen(word));
			strncpy(name, word, strlen(word) + 1);
			condition[j - k] = (condition_t *)malloc(sizeof(condition_t));
			condition[j - k]->columnname = name;
			condition[j - k]->condition_varchar = NULL;
			if(j - k < 2)
				condition[j - k + 1] = NULL;

			//op
			cursor = get_word(word, sql_sentence, cursor);
			if(strlen(word) == 0)
			{
				if(sql_sentence[cursor] == '<') // <
				{
					cursor++;
					if(sql_sentence[cursor] == '=') // <=
					{
						cursor++;
						condition[j - k]->op = op_leq;
					}
					else condition[j - k]->op = op_l;
				}
				else if(sql_sentence[cursor] == '>') // >
				{
					cursor++;
					if(sql_sentence[cursor] == '=') // >=
					{
						cursor++;
						condition[j - k]->op = op_geq;
					}
					else condition[j - k]->op = op_g;
				}
				else if(sql_sentence[cursor] == '!') // !=
				{
					cursor++;
					if(sql_sentence[cursor] == '=')
					{
						cursor++;
						condition[j - k]->op = op_neq;
					}
					else goto select_fail;
				}
				else if(sql_sentence[cursor] == '=') // =
				{
					cursor++;
					condition[j - k]->op = op_eq;
				}
				else goto select_fail;
			}
			else
			{
				if(strcmp(word, sql_not) == 0) // not like
				{
					cursor = get_word(word, sql_sentence, cursor);
					if(strcmp(word, sql_like) == 0)
						condition[j - k]->op = op_nlike;
					else goto select_fail;
				}
				else if(strcmp(word, sql_like) == 0) // like
					condition[j - k]->op = op_like;
				else goto select_fail;
			}
			//condition
			cursor = get_word(word, sql_sentence, cursor);
			if(strlen(word) == 0)
				goto select_fail;
			
			if(word[0] == '\'')
			{

				if(condition[j - k]->op != op_like && condition[j - k]->op != op_nlike && condition[j - k]->op != op_eq && condition[j - k]->op != op_neq)
					goto select_fail;
				name = (char *)malloc(strlen(word));
				strncpy(name, word + 1, strlen(word));
				condition[j - k]->type = VARCHAR;
				condition[j - k]->condition_varchar = name;
			}
			else
			{
				if(condition[j - k]->op == op_like || condition[j - k]->op == op_nlike)
					goto select_fail;
				if(k == 0 && word[0] >= 'a' && word[0] <= 'z' && condition[j - k]->op == op_eq)
				{
					join_condition = (join_condition_t *)malloc(sizeof(join_condition_t));
					join_condition->columnname1 = NULL;
					join_condition->columnname2 = NULL;
					join_condition->columnname1 = condition[j - k]->columnname;
					join_condition->table1 = condition_table[j - k];
					join_condition->table2 = 0;
					condition_table[j - k] = 0;
					free(condition[j - k]);
					condition[j - k] = NULL;
					if(sql_sentence[cursor] == '.')
					{
						if(strcmp(word, tablename[0]) == 0)
							join_condition->table2 = 1;
						else if(tablename[1] != NULL)
						{
							if(strcmp(word, tablename[1]) == 0)
								join_condition->table2 = 2;
							else goto select_fail;
						}
						else goto select_fail;
						cursor++;
						cursor = get_word(word, sql_sentence, cursor);
						if(strlen(word) > MAX_COLUMN_NAME || strlen(word) == 0 || word[0] > 'z' || word[0] < 'a')
							goto select_fail;
					}
					join_condition->columnname2 = (char *)malloc(strlen(word));
					strncpy(join_condition->columnname2, word, strlen(word) + 1);
					k++;
				}
				else 
				{
					if(word[0] == '-')
						i = 1;
					else i = 0;
					for(; i < strlen(word); i++)
						if(word[i] > '9' || word[i] < '0')
							goto select_fail;
					condition[j - k]->type = INT;
					condition[j - k]->condition_int = atoi(word);
				}
			}
			j++;
			if(sql_sentence[cursor] == ';')
				break;
		}
		if(j != 1 && !(k == 1 && tablename[1] != NULL))
			goto select_fail;
	}
	
	if(strcmp(word, sql_group) == 0)
	{
		cursor = get_word(word, sql_sentence, cursor);
		if(strcmp(word, sql_by) == 0)
		{
			if(columnnum == 0)
				goto select_fail;
			cursor = get_word(word, sql_sentence, cursor);
			if(strlen(word) == 0 || strlen(word) > MAX_COLUMN_NAME || word[0] > 'z' || word[0] < 'a')
				goto select_fail;
			//table_name
			group_table = 0; 
			if(sql_sentence[cursor] == '.')
			{
				if(strcmp(word, tablename[0]) == 0)
					group_table = 1;
				else if(tablename[1] != NULL)
				{
					if(strcmp(word, tablename[1]) == 0)
						group_table = 2;
					else goto select_fail;
				}
				else goto select_fail;
				cursor++;
				cursor = get_word(word, sql_sentence, cursor);
				if(strlen(word) > MAX_COLUMN_NAME || strlen(word) == 0 || word[0] > 'z' || word[0] < 'a')
					goto select_fail;
			}
			//column_name
			group = (char *)malloc(strlen(word));
			strncpy(group, word, strlen(word) + 1);
		}
		else goto select_fail;
	}
	if(sql_sentence[cursor] != ';')
		goto select_fail;

	if(tablename[1] != NULL && join_condition == NULL)
		goto select_fail;
	
	free(sql_sentence);
	if(group_table != -1)//group
	{
		if(k == 0) //一个表的情况
			select_groupby(tablename[0], columnname, columnnum, type, condition[0], group, group_table);
		else select_groupby_join(tablename, columnname, columnnum, type, table_name, condition, condition_table, join_condition, group, group_table);
	}
	else if(columnnum == 0)//* all的情况
	{

		if(k == 0) //一个表的情况
			select_all_1(tablename[0], condition[0]);
		else //两个表的情况
			select_all_2(tablename[0], tablename[1], condition[0], condition_table[0], condition[1], condition_table[1], join_condition);
	}
	else//具体列的情况
	{
		if(k == 0) //一个表的情况
			select_partial_1(tablename[0], columnname, columnnum, condition[0]);
		else //两个表的情况
			select_partial_2(tablename[0], tablename[1], columnname, table_name, columnnum, condition[0], condition_table[0], condition[1], condition_table[1], join_condition);
	}

	free(word);
	for(i = 0; i < 2; i++)
		if(tablename[i] != NULL)
			free(tablename[i]);
	for(i = 0; i < columnnum; i++)
		free(columnname[i]);
	free(columnname);
	free(table_name);
	for(i = 0; i < columnnum; i++)
		if(table_names[i] != NULL)
			free(table_names[i]);
	free(table_names);
	free(type);
	for(i = 0; i < 3; i++)
		if(condition[i] != NULL)
		{
			free(condition[i]->columnname);
			if(condition[i]->condition_varchar != NULL)
				free(condition[i]->condition_varchar);
			free(condition[i]);
		}
		else break;
	if(join_condition != NULL)
	{
		if(join_condition->columnname1 != NULL)
			free(join_condition->columnname1);
		if(join_condition->columnname2 != NULL)
			free(join_condition->columnname2);
		free(join_condition);
	}
	if(group != NULL)
		free(group);
	return 1;

select_fail:
	free(sql_sentence);
	free(word);
	for(i = 0; i < 2; i++)
		if(tablename[i] != NULL)
			free(tablename[i]);
	for(i = 0; i < columnnum; i++)
		free(columnname[i]);
	free(columnname);
	free(table_name);
	for(i = 0; i < columnnum; i++)
		if(table_names[i] != NULL)
			free(table_names[i]);
	free(table_names);
	free(type);
	for(i = 0; i < 3; i++)
		if(condition[i] != NULL)
		{
			free(condition[i]->columnname);
			if(condition[i]->condition_varchar != NULL)
				free(condition[i]->condition_varchar);
			free(condition[i]);
		}
		else break;
	if(join_condition != NULL)
	{
		if(join_condition->columnname1 != NULL)
			free(join_condition->columnname1);
		if(join_condition->columnname2 != NULL)
			free(join_condition->columnname2);
		free(join_condition);
	}
	if(group != NULL)
		free(group);
	return 0;
}
int parser_insert(char *sql_sentence, int cursor)
{
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
			if(word[0] == '-')
				i = 1;
			else i = 0;
			for(; i < strlen(word); i++)
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

	free(sql_sentence);
	insert_table(table_name, insert, columnnum);

	free(word);
	free(table_name);
	for(i = 0; i < columnnum; i++)
		if(insert[i].type == VARCHAR)
			free(insert[i].content_varchar);
	free(insert);
	return 1;

insert_fail:
	free(sql_sentence);
	free(word);
	if(table_name != NULL)
		free(table_name);
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
			// strncpy(sql_sentence, sql_sentence + cursor, strlen(sql_sentence) - cursor);
			for(i = 0; i < strlen(sql_sentence) - cursor; i++)
				sql_sentence[i] = sql_sentence[i + cursor];
			sql_sentence[i] = '\0';
		}
	}
	free(word);
	return flag;
}
int stop_signal(char *sql_sentence, int cursor)
{
	int i;
	int len = strlen(sql_sentence);
	cursor = ignore_blank(sql_sentence, cursor);
	if(sql_sentence[cursor] == '-' && sql_sentence[cursor + 1] == '-')
	{
		for(i = cursor; i < len; i++)
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
	while(sql_sentence[cursor] == ' ' || sql_sentence[cursor] == '\n' || sql_sentence[cursor] == '\r' || sql_sentence[cursor] == '\f' || sql_sentence[cursor] == '\t')
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
	if(i >= MAX_LENGTH)
		i = MAX_LENGTH - 1;
	strncpy(word, sql_sentence + cursor, i);
	word[i] = '\0';
	if(flag)
	{
		cursor++;
		if(i == 1)
			word[0] = '\0';
	}
	else trans_lower(word);
	cursor = cursor + i;
	cursor = ignore_blank(sql_sentence, cursor);
	// printf("%s--%c\n", word,sql_sentence[cursor]);
	return cursor;
}
void error_print(char *sql_sentence)
{
	int i;
	// for(i = 0; i < strlen(sql_sentence); i++)
		// printf("%c", sql_sentence[i]);
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