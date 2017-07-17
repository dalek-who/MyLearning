//
//  SQLgroupby.c
//  database
//
//  Created by 孔静 on 2016/12/29.
//  Copyright © 2016年 University of Chinese Academy of Sciences. All rights reserved.
//

#include "SQLexec.h"
#define MAX_COLUMN_NAME 128

void free_group_hash(group_hash_bucket_t group_hash_table[HASH_TABLE_SIZE])
{
	int i, flag;
	group_hash_bucket_t *now_bucket, *next_bucket;
	for(i = 0; i < HASH_TABLE_SIZE; i++)
	{
		flag = 1;
		next_bucket = &group_hash_table[i];
		while(next_bucket != NULL)
		{
			now_bucket = next_bucket;
			next_bucket = now_bucket->next;
			if(now_bucket->hash_varchar != NULL)
				free(now_bucket->hash_varchar);
			if(now_bucket->result != NULL)
			{
				free(now_bucket->result);
				if(now_bucket->resultnum != NULL)
					free(now_bucket->resultnum);
			}
			if(flag == 1)
				flag = 0;
			else free(now_bucket);
		}
	}
}
int select_groupby(char *table_name, char **columnname, int columnnum, char *type, condition_t *condition, char *group, char group_table)
{
	char *table_file = NULL;
	int len;
	FILE *file = NULL;
	output_info_t *output_info_list = NULL;

	int i, j;
	for(i = 0;i < columnnum; i++)
		if(group != NULL)
		{
			if(type[i] == 0 && strcmp(columnname[i], group) != 0)
			{
				printf("Non-group-by column %s in select list\n", columnname[i]);
				goto groupby_fail;
			}
		}
		else if(type[i] == 0)
		{
			printf("Non-group-by column %s in select list\n", columnname[i]);
			goto groupby_fail;
		}

	len = (int)strlen(table_name);
	table_file = (char *)malloc(sizeof(char) * (len + 10));
	strcpy(table_file, "db/");
	strcat(table_file, table_name);
	strcat(table_file, ".tbl");
	
	file = fopen(table_file, "rb");
	if(file == NULL)
	{
		printf("Table %s doesn't exist\n",table_name);
		goto groupby_fail;
	}

	table_data_t metadata;
	fread(&metadata, 1, sizeof(table_data_t), file);

	char coltype;
	int colnum, column_int = -1, column_var = -1, find = 0;
	int condition_column = -1, group_column = -1, group_type;
	char namebuffer[MAX_COLUMN_NAME + 1];
	output_info_list = (output_info_t *)malloc(sizeof(output_info_t) * columnnum);
    for(i = 0; i < columnnum; ++i)
        output_info_list[i].find = 0;
    for(i = 0; i < metadata.columnnum; i++)
    {
        fread((void *)&coltype, 1, sizeof(char), file);
        fread((void *)&len, 1, sizeof(int), file);
        fread((void *)namebuffer, 1, len + 1, file);
        
        if(coltype == INT)
            colnum = ++column_int;
        else colnum = ++column_var;
        find += output_info_search(output_info_list, columnname, columnnum, namebuffer, coltype, colnum);
        
        if(condition != NULL && condition_column == -1)
        {
            if(strcmp(namebuffer, condition->columnname) == 0)
            {
                if(coltype != condition->type)
                {
                    printf("Predicate %s ",namebuffer);
                    switch (condition->op)
                    {
                        case op_l:printf("<");break;
                        case op_g:printf(">");break;
                        case op_eq:printf("=");break;
                        case op_leq:printf("<=");break;
                        case op_geq:printf(">=");break;
                        case op_neq:printf("!=");break;
                        case op_nlike:printf("not like");break;
                        case op_like:printf("like");break;
                        default:break;
                    }
                    if(condition->type == INT)
                        printf(" %d error\n", condition->condition_int);
                    else printf(" '%s' error\n", condition->condition_varchar);
                    goto groupby_fail;
                }
                else condition_column = colnum;
            }
        }

        if(group != NULL && group_column == -1)
        	if(strcmp(namebuffer, group) == 0)
        	{
        		group_column = colnum;
        		group_type = coltype;
        	}
    }
    if(find != columnnum)
        for(i = 0; i < columnnum; i++)
            if(output_info_list[i].find != 1 && type[i] != -1)
            {
                printf("Column %s doesn't exist\n", columnname[i]);
                goto groupby_fail;
            }

    if(condition != NULL && condition_column == -1)
    {
        printf("Column %s doesn't exist\n", condition->columnname);
        goto groupby_fail;
    }

    if(group != NULL && group_column == -1)
    {
        printf("Column %s doesn't exist\n", group);
        goto groupby_fail;
    }

    for(i = 0; i < columnnum; i++)
    	if(type[i] > 1 && output_info_list[i].type != INT)
    	{
    		printf("Column %s is not int and can’t be used in aggregation\n", columnname[i]);
    		goto groupby_fail;
    	}


    for(i = 0; i < columnnum; i++)
    {
		switch(type[i])
        {
        	case -1:printf("count(*)");break;
        	case 0:printf("%s", columnname[i]);break;
        	case 1:printf("count(%s)", columnname[i]);break;
        	case 2:printf("avg(%s)", columnname[i]);break;
        	case 3:printf("sum(%s)", columnname[i]);break;
        	case 4:printf("min(%s)", columnname[i]);break;
        	case 5:printf("max(%s)", columnname[i]);break;
        	default:break;
        }
        if(i != columnnum - 1)
            printf("|");
        else printf("\n");
    }

    fseek(file, metadata.datastartpage * PAGE_SIZE, SEEK_SET);
    page_header_t *page_header;
    char databuffer[PAGE_SIZE];
    char pagebuffer[PAGE_SIZE];
    page_header = (page_header_t *)pagebuffer;
    fread(pagebuffer, 1, PAGE_SIZE, file);

	unsigned short idinpage;
    unsigned short *var_offset;
    int *fixed_data;

    var_offset = (unsigned short *)databuffer;
    var_offset++;
    fixed_data = (int *)((char *)databuffer + 2 * (1 + metadata.varcharnum));

    idinpage = 0;
    int flag = 0;
    if(group == NULL)
    {
    	int *result = NULL;
		int *resultnum = NULL;
    	result = (int *)malloc(sizeof(int) * columnnum);
		resultnum = (int *)malloc(sizeof(int) * columnnum);
	    if(result == NULL || resultnum == NULL)
		{
			if(result != NULL)
				free(result);
			printf("Malloc failed\n");
			goto groupby_fail;
		}
    	for(i = 0; i < columnnum; i++)
    		switch(type[i])
	    	{
	        	case -1:result[i] = 0;resultnum[i] = 1;break;
	        	case 1:result[i] = 0;resultnum[i] = 1;break;
	        	case 2:result[i] = 0;resultnum[i] = 0;break;
	        	case 3:result[i] = 0;resultnum[i] = 1;break;
	        	case 4:result[i] = 0x7fffffff;resultnum[i] = 1;break;
	        	case 5:result[i] = 0x80000000;resultnum[i] = 1;break;
	        	default:break;
	        }
	    for(i = 0; i < metadata.tuplenum; i++, idinpage++)
	    {
	        if(idinpage >= page_header->tuplenum)
	        {
	            fread(pagebuffer, 1, PAGE_SIZE, file);
	            idinpage = 0;
	        }
	        get_tuple(pagebuffer, databuffer, idinpage);
	        if(condition != NULL)
	        {
	            if(condition->type == INT)
	            {
	                if(int_compare(condition->op, fixed_data[condition_column], condition->condition_int) == FALSE)
	                    continue;
	            }
	            else if(varchar_compare(condition->op, &databuffer[var_offset[condition_column]+2], condition->condition_varchar) == FALSE)
	                    continue;
	        }
	        flag = 1;
	        for(j = 0; j < columnnum; j++)
	        {
	        	switch(type[j])
		    	{
		        	case -1:result[j]++;break;
		        	case 1:result[j]++;break;
		        	case 2:result[j] += fixed_data[output_info_list[j].columnnum];resultnum[j]++;break;
		        	case 3:result[j] += fixed_data[output_info_list[j].columnnum];break;
		        	case 4:result[j] = (fixed_data[output_info_list[j].columnnum] > result[j]) ? result[j]:fixed_data[output_info_list[j].columnnum];break;
		        	case 5:result[j] = (result[j] > fixed_data[output_info_list[j].columnnum]) ? result[j]:fixed_data[output_info_list[j].columnnum];break;
		        	default:break;
		        }
	        }
	    }
	    if(flag)
		    for(i = 0; i < columnnum; i++)
	        {
	        	printf("%d", result[i] / resultnum[i]);
	            if(i != columnnum - 1)
	                printf("|");
	            else printf("\n");
	        }
        free(result);
		free(resultnum);
	}
	else
	{
		group_hash_bucket_t hash_table[HASH_TABLE_SIZE];
		group_hash_bucket_t *search_bucket;

		unsigned int hash_result;
        for(i = 0; i < HASH_TABLE_SIZE; i++)
        {
        	hash_table[i].next = NULL;
        	hash_table[i].result = NULL;
			hash_table[i].hash_varchar = NULL;
    	}
    	for(i = 0; i < metadata.tuplenum; i++, idinpage++)
    	{
	        if(idinpage >= page_header->tuplenum)
	        {
	            fread(pagebuffer, 1, PAGE_SIZE, file);
	            idinpage = 0;
	        }
        	get_tuple(pagebuffer, databuffer, idinpage);

	        if(condition != NULL)
	        {
	            if(condition->type == INT)
	            {
	                if(int_compare(condition->op, fixed_data[condition_column], condition->condition_int) == FALSE)
	                    continue;
	            }
	            else if(varchar_compare(condition->op, &databuffer[var_offset[condition_column]+2], condition->condition_varchar) == FALSE)
	                    continue;
	        }
        
	        if(group_type == INT)
	            hash_result = int_hash(fixed_data[group_column]);
	        else
	        {
	            memcpy(&len, &databuffer[var_offset[group_column]], 2);
	            hash_result = varchar_hash(&databuffer[var_offset[group_column] + 2], len);
	        }
	        hash_result %= HASH_TABLE_SIZE;
	        search_bucket = &hash_table[hash_result];

	        while(1)
	        {
	            if(search_bucket->result == NULL)
	            {
	                if(group_type == INT)
	                    search_bucket->hash_int = fixed_data[group_column];
	                else
	                {
	                    search_bucket->hash_varchar = (char *)malloc(sizeof(char)*(len + 1));
                        if(search_bucket->hash_varchar == NULL)
						{
							free_group_hash(hash_table);
							printf("Malloc failed\n");
							goto groupby_fail;
						}
	                    strcpy(search_bucket->hash_varchar, &databuffer[var_offset[group_column] + 2]);
	                }
	                break;
	            }
	            else if((group_type == INT && fixed_data[group_column] == search_bucket->hash_int) || (group_type == VARCHAR && strcmp(&databuffer[var_offset[group_column] + 2], search_bucket->hash_varchar) == 0))
	            	break;
	            else if(search_bucket->next == NULL)
	            {
	                search_bucket->next = (group_hash_bucket_t *)malloc(sizeof(group_hash_bucket_t));
	                if(search_bucket->next == NULL)
			    	{
						free_group_hash(hash_table);
			    		printf("Malloc failed\n");
			    		goto groupby_fail;
			    	}
	                search_bucket = search_bucket->next;
					search_bucket->hash_varchar = NULL;
	                search_bucket->result = NULL;
	                search_bucket->next = NULL;
	            }
	            else search_bucket = search_bucket->next;
	        }
	        
	        if (search_bucket->result == NULL)
	        {
	        	search_bucket->result = (int *)malloc(sizeof(int) * columnnum);
	        	search_bucket->resultnum = (int *)malloc(sizeof(int) * columnnum);
        	    if(search_bucket->resultnum == NULL || search_bucket->result == NULL)
		    	{
					free_group_hash(hash_table);
		    		printf("Malloc failed\n");
		    		goto groupby_fail;
		    	}
		    	for(j = 0; j < columnnum; j++)
		    		switch(type[j])
			    	{
			        	case -1:search_bucket->result[j] = 1;search_bucket->resultnum[j] = 1;break;
			        	case 1:search_bucket->result[j] = 1;search_bucket->resultnum[j] = 1;break;
			        	case 2:search_bucket->result[j] = fixed_data[output_info_list[j].columnnum];search_bucket->resultnum[j] = 1;break;
			        	case 3:search_bucket->result[j] = fixed_data[output_info_list[j].columnnum];search_bucket->resultnum[j] = 1;break;
			        	case 4:search_bucket->result[j] = fixed_data[output_info_list[j].columnnum];search_bucket->resultnum[j] = 1;break;
			        	case 5:search_bucket->result[j] = fixed_data[output_info_list[j].columnnum];search_bucket->resultnum[j] = 1;break;
			        	default:break;
			        }
	        }
	        else
	        {
	            for(j = 0; j < columnnum; j++)
		        	switch(type[j])
			    	{
			        	case -1:search_bucket->result[j]++;break;
			        	case 1:search_bucket->result[j]++;break;
			        	case 2:search_bucket->result[j] += fixed_data[output_info_list[j].columnnum];search_bucket->resultnum[j]++;break;
			        	case 3:search_bucket->result[j] += fixed_data[output_info_list[j].columnnum];break;
			        	case 4:search_bucket->result[j] = (fixed_data[output_info_list[j].columnnum] > search_bucket->result[j]) ? search_bucket->result[j]:fixed_data[output_info_list[j].columnnum];break;
			        	case 5:search_bucket->result[j] = (search_bucket->result[j] > fixed_data[output_info_list[j].columnnum]) ? search_bucket->result[j]:fixed_data[output_info_list[j].columnnum];break;
			        	default:break;
			        }
	        }
	    }
	    group_hash_bucket_t *next_bucket;
	    for(i = 0; i < HASH_TABLE_SIZE; i++)
	    {
	    	search_bucket = &hash_table[i];
	    	flag = 0;
	    	while(search_bucket != NULL)
	    	{
	    		if(search_bucket->result == NULL)
	    			break;
	    		next_bucket = search_bucket->next;
		    	for(j = 0; j < columnnum; j++)
		    	{
		    		if(type[j] == 0)
		    		{
		    			if(group_type == INT)
		    				printf("%d", search_bucket->hash_int);
		    			else printf("%s", search_bucket->hash_varchar);
		    		}
		    		else printf("%d", search_bucket->result[j] / search_bucket->resultnum[j]);
		    		if(j != columnnum - 1)
		    			printf("|");
		    		else printf("\n");
		    	}
		    	if(group_type == VARCHAR)
		    		free(search_bucket->hash_varchar);
		    	free(search_bucket->result);
		    	free(search_bucket->resultnum);
		    	if(flag)
		    		free(search_bucket);
		    	else flag = 1;
		    	search_bucket = next_bucket;
		    }
	    }
	}

	free(table_file);
	fclose(file);
	free(output_info_list);
	return 1;

groupby_fail:
	if(table_file != NULL)
		free(table_file);
	if(file != NULL)
		fclose(file);
	if(output_info_list != NULL)
		free(output_info_list);
	return 0;
}

int select_groupby_join(char *tablename[2], char **columnname, int columnnum, char *type, char *columntable, condition_t *condition[3], char conditiontable[3], join_condition_t *join_condition, char *group, char group_table)
{
	char *table_file[2] = {NULL, NULL};
	int len;
	FILE *file[2] = {NULL, NULL};
	output_info_t *output_info_list = NULL;

	int i, j, k;
	for(i = 0;i < columnnum; i++)
		if(group != NULL && type[i] == 0)
		{
			if(strcmp(columnname[i], group) != 0)
			{
				printf("Non-group-by column %s in select list\n", columnname[i]);
				goto groupby_join_fail;
			}
			else if((group_table == 1 && columntable[i] == 2) || (group_table == 2 && columntable[i] == 1))
			{
				printf("Non-group-by column %s.%s in select list\n", tablename[columntable[i] - 1], columnname[i]);
				goto groupby_join_fail;
			}
		}
		else if(group == NULL && type[i] == 0)
		{
			printf("Non-group-by column %s in select list\n", columnname[i]);
			goto groupby_join_fail;
		}

	table_data_t metadata[2];
	for(i = 0; i < 2; i++)
	{
		len = (int)strlen(tablename[i]);
		table_file[i] = (char *)malloc(sizeof(char) * (len + 10));
		strcpy(table_file[i], "db/");
		strcat(table_file[i], tablename[i]);
		strcat(table_file[i], ".tbl");

		file[i] = fopen(table_file[i], "rb");
		if(file[i] == NULL)
		{
			printf("Table %s doesn't exist\n",tablename[i]);
			goto groupby_join_fail;
		}
		fread(&metadata[i], 1, sizeof(table_data_t), file[i]);
	}

	char coltype;
	int colnum, column_int, column_var, find = 0;
	int condition_column[2] = {-1, -1}, group_column = -1, group_type;
	int join_column[2] = {-1, -1}, join_type[2] = {-1, -1};
	char namebuffer[MAX_COLUMN_NAME + 1];
	int flag;

	output_info_list = (output_info_t *)malloc(sizeof(output_info_t) * columnnum);

    for(i = 0; i < columnnum; ++i)
        output_info_list[i].find = 0;
    for(j = 0; j < 2; j++)
    {
    	column_int = -1;
    	column_var = -1;
	    for(i = 0; i < metadata[j].columnnum; i++)
	    {
	        fread((void *)&coltype, 1, sizeof(char), file[j]);
	        fread((void *)&len, 1, sizeof(int), file[j]);
	        fread((void *)namebuffer, 1, len + 1, file[j]);
	        
	        if(coltype == INT)
	            colnum = ++column_int;
	        else colnum = ++column_var;
	        flag = output_info_search_join(output_info_list, columnname, columnnum, columntable, namebuffer, coltype, colnum, j + 1);
	        if(flag == -1)
	        	goto groupby_join_fail;
	        else find += flag;
	        for(k = 0; k < 2; k++)
	        {
	        	if(condition[k] == NULL)
	        		break;
	        	if(conditiontable[k] == 0 || conditiontable[k] == 4 - j || conditiontable[k] == j + 1)
	        	{
		        	if((condition[k] != NULL && condition_column[k] == -1) || conditiontable[k] == 4 - j)
		        	{
		            	if(strcmp(namebuffer, condition[k]->columnname) == 0)
		            	{
			                if(coltype != condition[k]->type)
			                {
			                    printf("Predicate %s ",namebuffer);
			                    switch (condition[k]->op)
			                    {
			                        case op_l:printf("<");break;
			                        case op_g:printf(">");break;
			                        case op_eq:printf("=");break;
			                        case op_leq:printf("<=");break;
			                        case op_geq:printf(">=");break;
			                        case op_neq:printf("!=");break;
			                        case op_nlike:printf("not like");break;
			                        case op_like:printf("like");break;
			                        default:break;
			                    }
			                    if(condition[k]->type == INT)
			                        printf(" %d error\n", condition[k]->condition_int);
			                    else printf(" '%s' error\n", condition[k]->condition_varchar);
			                    goto groupby_join_fail;
			                }
			                else if(conditiontable[k] == 4 - j)
			                {
			                	printf("Ambiguous column %s\n", condition[k]->columnname);
			                	goto groupby_join_fail;
			                }
			                else
			                {
			                	condition_column[k] = colnum;
			                	if(conditiontable[k] == 0)
				                	conditiontable[k] = j + 3;
			                }
			            }
			        }
			    }
		    }
 
	        if((join_column[0] == -1 && join_condition->table1 != 2 - j) || join_condition->table1 == 4 - j)
	        {
	            if (strcmp(namebuffer, join_condition->columnname1) == 0)
	            {
	            	join_column[0] = colnum;
	                if(join_condition->table1 == 4 - j)
	                {
	                    printf("Ambiguous column %s\n", join_condition->columnname1);
	                    goto groupby_join_fail;
	                }
	                if(join_condition->table1 == 0)
	                    join_condition->table1 = j + 3;
	            	join_type[0] = coltype;
	            }
	        }

	        if((join_column[1] == -1 && join_condition->table2 != 2 - j) || join_condition->table2 == 4 - j)
	        {
	            if (strcmp(namebuffer, join_condition->columnname2) == 0)
	            {
	            	join_column[1] = colnum;
	                if(join_condition->table2 == 4 - j)
	                {
	                    printf("Ambiguous column %s\n", join_condition->columnname2);
	                    goto groupby_join_fail;
	                }
	                if(join_condition->table2 == 0)
	                    join_condition->table2 = j + 3;
	            	join_type[1] = coltype;
	            }
	        }

		    if(group_table == 0 || group_table == j + 1 || group_table == 4 - j)
		    {
		        if((group != NULL && group_column == -1) || group_table == 4 - j)
		        	if(strcmp(namebuffer, group) == 0)
		        	{
		        		if(group_table == 4 - j)
		        		{
		                	printf("Ambiguous column %s\n", group);
		                	goto groupby_join_fail;
			            }
		        		group_column = colnum;
		        		group_type = coltype;
		        		if(group_table == 0)
			        		group_table = j + 3;
		        	}
	        }


	    }
	}

    if(find != columnnum)
        for(i = 0; i < columnnum; i++)
            if(output_info_list[i].find != 1 && type[i] != -1)
            {
            	if(columntable[i] == 1 || columntable[i] == 2)
            		printf("Column %s.%s doesn't exist\n", tablename[columntable[i] - 1], columnname[i]);
                else printf("Column %s doesn't exist\n", columnname[i]);
                goto groupby_join_fail;
            }
    for(i = 0; i < columnnum; i++)
    	if(type[i] > 1 && output_info_list[i].type != INT)
    	{
    		if(columntable[i] == 1 || columntable[i] == 2)
            		printf("Column %s.%s doesn't exist\n", tablename[columntable[i] - 1], columnname[i]);
            else printf("Column %s is not int and can’t be used in aggregation\n", columnname[i]);
    		goto groupby_join_fail;
    	}

    if(join_column[0] == -1)
    {
    	if(join_condition->table1 == 1 || join_condition->table1 == 2)
            printf("Column %s.%s doesn't exist\n", tablename[join_condition->table1 - 1], join_condition->columnname1);
        else printf("Column %s doesn't exist\n", join_condition->columnname1);
        goto groupby_join_fail;
    }
    if(join_column[1] == -1)
    {
    	if(join_condition->table2 == 1 || join_condition->table2 == 2)
            printf("Column %s.%s doesn't exist\n", tablename[join_condition->table2 - 1], join_condition->columnname2);
        else printf("Column %s doesn't exist\n", join_condition->columnname2);
        goto groupby_join_fail;
    }
    if((join_condition->table1 + join_condition->table2) % 2 == 0)
    {
    	printf("Syntax error\n");
    	goto groupby_join_fail;
    }
    if(join_type[0] != join_type[1])
    {
    	printf("Join predicate error\n");
    	goto groupby_join_fail;
    }
    if(join_condition->table1 == 2 || join_condition->table1 == 4)
    {
    	i = join_column[1];
    	join_column[1] = join_column[0];
    	join_column[0] = i;
    	i = join_condition->table2;
    	join_condition->table2 = join_condition->table1;
    	join_condition->table1 = i;
    }

    for(i = 0; i < 2; i++)
	    if(condition[i] != NULL && condition_column[i] == -1)
	    {
	        if(conditiontable[i] == 1 || conditiontable[i] == 2)
        		printf("Column %s.%s doesn't exist\n", tablename[conditiontable[i] - 1], condition[i]->columnname);
            else printf("Column %s doesn't exist\n", condition[i]->columnname);
	        goto groupby_join_fail;
	    }
	if(condition[0] != NULL && condition[1] != NULL)
		if((conditiontable[0] + conditiontable[1]) % 2 == 0)
	    {
	    	printf("Syntax error\n");
	    	goto groupby_join_fail;
	    }
	char con[2] = {0, 1};
	if(conditiontable[0] == 2 || conditiontable[0] == 4)
	{
		con[0] = 1;
		con[1] = 0;
	}

    if(group != NULL && group_column == -1)
    {
    	if(group_table == 1 || group_table == 2)
	        printf("Column %s.%s doesn't exist\n", tablename[group_table - 1], group);
	    else printf("Column %s doesn't exist\n", group);
        goto groupby_join_fail;
    }
    	

    for(i = 0; i < columnnum; i++)
    {
        switch(type[i])
        {
        	case -1:printf("count(");break;
        	case 1:printf("count(");break;
        	case 2:printf("avg(");break;
        	case 3:printf("sum(");break;
        	case 4:printf("min(");break;
        	case 5:printf("max(");break;
        	default:break;
        }
        if(columntable[i] == 1 || columntable[i] == 2)
    		printf("%s.%s", tablename[columntable[i] - 1], columnname[i]);
        else printf("%s", columnname[i]);
        if(type[i] != 0)
        	printf(")");
        if(i != columnnum - 1)
            printf("|");
        else printf("\n");
    }


    page_header_t *page_header;
    char databuffer[2][PAGE_SIZE];
    char pagebuffer[PAGE_SIZE];

	unsigned short idinpage;
    unsigned short *var_offset[2];
    int *fixed_data[2];

    for(i = 0; i < 2; i ++)
    {
	    var_offset[i] = (unsigned short *)(databuffer[i]);
	    var_offset[i]++;
	    fixed_data[i] = (int *)((char *)(databuffer[i]) + 2 * (1 + metadata[i].varcharnum));
	}
	char hashtable;
	if(metadata[0].datapage <= metadata[1].datapage)
        hashtable = 0;
    else hashtable = 1;

    join_hash_bucket_t hash_table[HASH_TABLE_SIZE];
    join_hash_bucket_t *search_bucket;
	join_bucket_tuple_t *search_tuple;
	unsigned int hash_result;

    flag = join_hash(hash_table, condition[con[hashtable]], condition_column[con[hashtable]], file[hashtable], &metadata[hashtable], join_column[hashtable], join_type[hashtable]);
    if(flag == FAIL)
	{
		free_join_hash(hash_table);
		printf("Malloc failed\n");
		goto groupby_join_fail;
	}
    fseek(file[1 - hashtable], metadata[1 - hashtable].datastartpage * PAGE_SIZE, SEEK_SET);
    page_header = (page_header_t *)pagebuffer;
    fread(pagebuffer, 1, PAGE_SIZE, file[1 - hashtable]);

    idinpage = 0;
    flag = 0;
    if(group == NULL)
    {
    	int *result = NULL;
		int *resultnum = NULL;
    	result = (int *)malloc(sizeof(int) * columnnum);
		resultnum = (int *)malloc(sizeof(int) * columnnum);
	    if(result == NULL || resultnum == NULL)
		{
			free_join_hash(hash_table);
			if(result != NULL);
				free(result);
			printf("Malloc failed\n");
			goto groupby_join_fail;
		}
		int medium;
    	for(i = 0; i < columnnum; i++)
    		switch(type[i])
	    	{
	        	case -1:result[i] = 0;resultnum[i] = 1;break;
	        	case 1:result[i] = 0;resultnum[i] = 1;break;
	        	case 2:result[i] = 0;resultnum[i] = 0;break;
	        	case 3:result[i] = 0;resultnum[i] = 1;break;
	        	case 4:result[i] = 0x7fffffff;resultnum[i] = 1;break;
	        	case 5:result[i] = 0x80000000;resultnum[i] = 1;break;
	        	default:break;
	        }
		
		for(i = 0; i < metadata[1 - hashtable].tuplenum; i++, idinpage++)
		{
            if(idinpage >= page_header->tuplenum)
            {
                fread(pagebuffer, 1, PAGE_SIZE, file[1 - hashtable]);
                idinpage = 0;
            }
            get_tuple(pagebuffer, databuffer[1 - hashtable], idinpage);
            
            if(condition[con[1 - hashtable]] != NULL)
            {
                if(condition[con[1 - hashtable]]->type == INT)
                {
                    if(int_compare(condition[con[1 - hashtable]]->op, fixed_data[1 - hashtable][condition_column[con[1 - hashtable]]], condition[con[1 - hashtable]]->condition_int) == FALSE)
                        continue;
                }
                else if(varchar_compare(condition[con[1 - hashtable]]->op, &databuffer[1 - hashtable][var_offset[1 - hashtable][condition_column[con[1 - hashtable]]] + 2], condition[con[1 - hashtable]]->condition_varchar) == FALSE)
                        continue;
            }
            
            if (join_type[hashtable] == INT)
                hash_result = int_hash(fixed_data[1 - hashtable][join_column[1 - hashtable]]);
            else
            {
                memcpy(&len, &databuffer[1 - hashtable][var_offset[1 - hashtable][join_column[1 - hashtable]]], 2);
                hash_result = varchar_hash(&databuffer[1 - hashtable][var_offset[1 - hashtable][join_column[1 - hashtable]] + 2], len);
            }
            
            hash_result %= HASH_TABLE_SIZE;
            search_bucket = &hash_table[hash_result];
            
            while(1)
            {
                if(search_bucket->first == NULL)
                    goto groupby_join_continue;
                else if((join_type[hashtable] == INT && fixed_data[1 - hashtable][join_column[1 - hashtable]] == search_bucket->hash_int) || (join_type[hashtable] == VARCHAR && strcmp(&databuffer[1 - hashtable][var_offset[1 - hashtable][join_column[1 - hashtable]] + 2], search_bucket->hash_varchar) == 0))
                    break;
                else if (search_bucket->next == NULL)
                   	goto groupby_join_continue;
                else search_bucket = search_bucket->next;
            }
	        
	        search_tuple = search_bucket->first;
	        while(search_tuple != NULL)
	        {
	            memcpy(&len, search_tuple->tuple, 2);
                memcpy(databuffer[hashtable], search_tuple->tuple, len);
                flag = 1;
	            for(j = 0; j < columnnum; j++)
	            {
	            	medium = 1 - (columntable[j] % 2);
		        	switch(type[j])
			    	{
			        	case -1:result[j]++;break;
			        	case 1:result[j]++;break;
			        	case 2:result[j] += fixed_data[medium][output_info_list[j].columnnum];resultnum[j]++;break;
			        	case 3:result[j] += fixed_data[medium][output_info_list[j].columnnum];break;
			        	case 4:result[j] = (fixed_data[medium][output_info_list[j].columnnum] > result[j]) ? result[j]:fixed_data[medium][output_info_list[j].columnnum];break;
			        	case 5:result[j] = (result[j] > fixed_data[medium][output_info_list[j].columnnum]) ? result[j]:fixed_data[medium][output_info_list[j].columnnum];break;
			        	default:break;
			        }
	            }
	            search_tuple = search_tuple->next;
	        }
	        
	    groupby_join_continue:
	        continue;
	    }
	    if(flag)
		    for(i = 0; i < columnnum; i++)
	        {
				printf("%d", result[i] / resultnum[i]);
	            if(i != columnnum - 1)
	                printf("|");
	            else printf("\n");
	        }
        free(result);
		free(resultnum);
	}
	else
	{
		group_hash_bucket_t group_hash_table[HASH_TABLE_SIZE];
		group_hash_bucket_t *group_search_bucket;
		int medium;
		int grouptable = (group_table + 1) % 2;
		unsigned int hash_result;
        for(i = 0; i < HASH_TABLE_SIZE; i++)
        {
        	group_hash_table[i].next = NULL;
        	group_hash_table[i].result = NULL;
			group_hash_table[i].hash_varchar = NULL;
    	}
    	for(i = 0; i < metadata[1 - hashtable].tuplenum; i++, idinpage++)
    	{
	        if(idinpage >= page_header->tuplenum)
	        {
	            fread(pagebuffer, 1, PAGE_SIZE, file[1 - hashtable]);
	            idinpage = 0;
	        }
        	get_tuple(pagebuffer, databuffer[1 - hashtable], idinpage);

            if(condition[con[1 - hashtable]] != NULL)
            {
                if(condition[con[1 - hashtable]]->type == INT)
                {
                    if(int_compare(condition[con[1 - hashtable]]->op, fixed_data[1 - hashtable][condition_column[con[1 - hashtable]]], condition[con[1 - hashtable]]->condition_int) == FALSE)
                        continue;
                }
                else if(varchar_compare(condition[con[1 - hashtable]]->op, &databuffer[1 - hashtable][var_offset[1 - hashtable][condition_column[con[1 - hashtable]]] + 2], condition[con[1 - hashtable]]->condition_varchar) == FALSE)
                        continue;
            }
            
            if (join_type[hashtable] == INT)
                hash_result = int_hash(fixed_data[1 - hashtable][join_column[1 - hashtable]]);
            else
            {
                memcpy(&len, &databuffer[1 - hashtable][var_offset[1 - hashtable][join_column[1 - hashtable]]], 2);
                hash_result = varchar_hash(&databuffer[1 - hashtable][var_offset[1 - hashtable][join_column[1 - hashtable]] + 2], len);
            }
            
            hash_result %= HASH_TABLE_SIZE;
            search_bucket = &hash_table[hash_result];
            
            while(1)
            {
                if(search_bucket->first == NULL)
                    goto groupby_join_continue_not_null;
                else if((join_type[hashtable] == INT && fixed_data[1 - hashtable][join_column[1 - hashtable]] == search_bucket->hash_int) || (join_type[hashtable] == VARCHAR && strcmp(&databuffer[1 - hashtable][var_offset[1 - hashtable][join_column[1 - hashtable]] + 2], search_bucket->hash_varchar) == 0))
                    break;
                else if (search_bucket->next == NULL)
                   	goto groupby_join_continue_not_null;
                else search_bucket = search_bucket->next;
            }
	        
	        search_tuple = search_bucket->first;
	        while(search_tuple != NULL)
	        {
	            memcpy(&len, search_tuple->tuple, 2);
                memcpy(databuffer[hashtable], search_tuple->tuple, len);
                flag = 1;
                //group hash
		        if(group_type == INT)
		            hash_result = int_hash(fixed_data[grouptable][group_column]);
		        else
		        {
		            memcpy(&len, &databuffer[grouptable][var_offset[grouptable][group_column]], 2);
		            hash_result = varchar_hash(&databuffer[grouptable][var_offset[grouptable][group_column] + 2], len);
		        }
        		hash_result %= HASH_TABLE_SIZE;
	        	group_search_bucket = &group_hash_table[hash_result];

		        while(1)
		        {
		            if(group_search_bucket->result == NULL)
		            {
		                if(group_type == INT)
		                    group_search_bucket->hash_int = fixed_data[grouptable][group_column];
		                else
		                {
		                    group_search_bucket->hash_varchar = (char *)malloc(sizeof(char)*(len + 1));
                    	    if(group_search_bucket->hash_varchar == NULL)
							{
								free_join_hash(hash_table);
								free_group_hash(group_hash_table);
								printf("Malloc failed\n");
								goto groupby_join_fail;
							}
		                    strcpy(group_search_bucket->hash_varchar, &databuffer[grouptable][var_offset[grouptable][group_column] + 2]);
		                }
		                break;
		            }
		            else if((group_type == INT && fixed_data[grouptable][group_column] == group_search_bucket->hash_int) || (group_type == VARCHAR && strcmp(&databuffer[grouptable][var_offset[grouptable][group_column] + 2], group_search_bucket->hash_varchar) == 0))
		            	break;
		            else if(group_search_bucket->next == NULL)
		            {
		                group_search_bucket->next = (group_hash_bucket_t *)malloc(sizeof(group_hash_bucket_t));
		                if(group_search_bucket->next == NULL)
						{
							free_join_hash(hash_table);
							free_group_hash(group_hash_table);
							printf("Malloc failed\n");
							goto groupby_join_fail;
						}
		                group_search_bucket = group_search_bucket->next;
		                group_search_bucket->result = NULL;
		                group_search_bucket->next = NULL;
						group_search_bucket->hash_varchar = NULL;
		            }
		            else group_search_bucket = group_search_bucket->next;
		        }
		        
		        if (group_search_bucket->result == NULL)
		        {
		        	group_search_bucket->result = (int *)malloc(sizeof(int) * columnnum);
		        	group_search_bucket->resultnum = (int *)malloc(sizeof(int) * columnnum);
		        	if(group_search_bucket->result == NULL || group_search_bucket->resultnum == NULL)
					{
						free_join_hash(hash_table);
						free_group_hash(group_hash_table);
						printf("Malloc failed\n");
						goto groupby_join_fail;
					}
			    	for(j = 0; j < columnnum; j++)
			    	{
			    		medium = 1 - (columntable[j] % 2);
			    		switch(type[j])
				    	{
				        	case -1:group_search_bucket->result[j] = 1;group_search_bucket->resultnum[j] = 1;break;
				        	case 1:group_search_bucket->result[j] = 1;group_search_bucket->resultnum[j] = 1;break;
				        	case 2:group_search_bucket->result[j] = fixed_data[medium][output_info_list[j].columnnum];group_search_bucket->resultnum[j] = 1;break;
				        	case 3:group_search_bucket->result[j] = fixed_data[medium][output_info_list[j].columnnum];group_search_bucket->resultnum[j] = 1;break;
				        	case 4:group_search_bucket->result[j] = fixed_data[medium][output_info_list[j].columnnum];group_search_bucket->resultnum[j] = 1;break;
				        	case 5:group_search_bucket->result[j] = fixed_data[medium][output_info_list[j].columnnum];group_search_bucket->resultnum[j] = 1;break;
				        	default:break;
				        }
				    }
		        }
		        else
		        {
		            for(j = 0; j < columnnum; j++)
		            {
		            	medium = 1 - (columntable[j] % 2);
			        	switch(type[j])
				    	{
				        	case -1:group_search_bucket->result[j]++;break;
				        	case 1:group_search_bucket->result[j]++;break;
				        	case 2:group_search_bucket->result[j] += fixed_data[medium][output_info_list[j].columnnum];group_search_bucket->resultnum[j]++;break;
				        	case 3:group_search_bucket->result[j] += fixed_data[medium][output_info_list[j].columnnum];break;
				        	case 4:group_search_bucket->result[j] = (fixed_data[medium][output_info_list[j].columnnum] > group_search_bucket->result[j]) ? group_search_bucket->result[j]:fixed_data[medium][output_info_list[j].columnnum];break;
				        	case 5:group_search_bucket->result[j] = (group_search_bucket->result[j] > fixed_data[medium][output_info_list[j].columnnum]) ? group_search_bucket->result[j]:fixed_data[medium][output_info_list[j].columnnum];break;
				        	default:break;
				        }
				    }
		        }

	            search_tuple = search_tuple->next;
	        }
	    groupby_join_continue_not_null:
	        continue;
	    }
	    group_hash_bucket_t *next_bucket;
	    for(i = 0; i < HASH_TABLE_SIZE; i++)
	    {
	    	group_search_bucket = &group_hash_table[i];
	    	flag = 0;
	    	while(group_search_bucket != NULL)
	    	{
	    		if(group_search_bucket->result == NULL)
	    			break;
	    		next_bucket = group_search_bucket->next;
		    	for(j = 0; j < columnnum; j++)
		    	{
		    		if(type[j] == 0)
		    		{
		    			if(group_type == INT)
		    				printf("%d", group_search_bucket->hash_int);
		    			else printf("%s", group_search_bucket->hash_varchar);
		    		}
		    		else printf("%d", group_search_bucket->result[j] / group_search_bucket->resultnum[j]);
		    		if(j != columnnum - 1)
		    			printf("|");
		    		else printf("\n");
		    	}
		    	if(group_type == VARCHAR)
		    		free(group_search_bucket->hash_varchar);
		    	free(group_search_bucket->result);
		    	free(group_search_bucket->resultnum);
		    	if(flag)
		    		free(group_search_bucket);
		    	else flag = 1;
		    	group_search_bucket = next_bucket;
		    }
	    }
	}

	free_join_hash(hash_table);

    for(i = 0; i < 2; i++)
    {
    	free(table_file[i]);
    	fclose(file[i]);
    }
	return 1;

groupby_join_fail:
    for(i = 0; i < 2; i++)
    {
    	if(table_file[i] != NULL)
	    	free(table_file[i]);
    	if(file[i] != NULL)
	    	fclose(file[i]);
    }
	return 0;
}
