//
//  SQLjoin.c
//  database
//
//  Created by 谈清扬 on 2016/12/29.
//  Copyright © 2016年 University of Chinese Academy of Sciences. All rights reserved.
//

#include "SQLexec.h"

void int_swap(int* a, int* b){
    int temp;
    
    temp = *a;
    *a = *b;
    *b = temp;
}

void char_swap(char *a, char *b){
    char temp[128+1];
    
    strcpy(temp, a);
    strcpy(a, b);
    strcpy(b, temp);
}

unsigned int int_hash(int a)
{
    a = (a+0x7ed55d16) + (a<<12);
    a = (a^0xc761c23c) ^ (a>>19);
    a = (a+0x165667b1) + (a<<5);
    a = (a+0xd3a2646c) ^ (a<<9);
    a = (a+0xfd7046c5) + (a<<3);
    a = (a^0xb55a4f09) ^ (a>>16);
    return a;
}

unsigned int varchar_hash(char *key, int len) {
    
    unsigned int hash;
    int i;
    for(hash = i = 0; i < len; ++i) {
        
        hash += key[i];
        
        hash += (hash << 10);
        
        hash ^= (hash >> 6);
    }
    hash += (hash << 3);
    hash ^= (hash >> 11);
    hash += (hash << 15);
    
    return hash;
    
}

void free_join_hash(join_hash_bucket_t hash_table[HASH_TABLE_SIZE]){
    int i;
    join_hash_bucket_t *next_bucket;
    join_hash_bucket_t *now_bucket;
    join_bucket_tuple_t *next_tuple;
    join_bucket_tuple_t *now_tuple;
    
    for (i=0; i<HASH_TABLE_SIZE; i++) {
        now_tuple = hash_table[i].first;
        while (now_tuple!=NULL) {
            next_tuple = now_tuple->next;
            free(now_tuple->tuple);
            free(now_tuple);
            now_tuple = next_tuple;
        }
        if(hash_table[i].hash_varchar != NULL)
         	free(hash_table[i].hash_varchar);
        now_bucket = hash_table[i].next;
        while (now_bucket!=NULL) {
            next_bucket = now_bucket->next;
            
            now_tuple = now_bucket->first;
            while (now_tuple!=NULL) {
                next_tuple = now_tuple->next;
                free(now_tuple->tuple);
                free(now_tuple);
                now_tuple = next_tuple;
            }
	        if(now_bucket->hash_varchar != NULL)
	         	free(now_bucket->hash_varchar);
            free(now_bucket);
            now_bucket = next_bucket;
        }
    }
}

int join_hash(join_hash_bucket_t hash_table[HASH_TABLE_SIZE], condition_t *condition, int condition_column, FILE *file, table_data_t *metadata,int join_column, char join_type){
    int i;
    char pagebuffer[PAGE_SIZE];
    char databuffer[PAGE_SIZE];
    page_header_t *page_header;
    unsigned short idinpage;
    unsigned short *var_offset;
    join_hash_bucket_t *insert_bucket;
    join_bucket_tuple_t *insert_tuple;
    int *fixed_data;
    unsigned int hash_result;
    unsigned short len=0;
    
    for (i=0; i<HASH_TABLE_SIZE; i++) {
        hash_table[i].next  = NULL;
        hash_table[i].first = NULL;
        hash_table[i].hash_varchar = NULL;
    }
    
    fseek(file, metadata->datastartpage*PAGE_SIZE, SEEK_SET);
    page_header = (page_header_t *)pagebuffer;
    fread(pagebuffer, 1, PAGE_SIZE, file);
    
    var_offset = (unsigned short *)databuffer;
    var_offset++;
    fixed_data = (int *)((char *)databuffer+2*(1+metadata->varcharnum));
    
    idinpage = 0;
    for (i=0; i<metadata->tuplenum; i++,idinpage++) {
        if (idinpage>=page_header->tuplenum) {
            fread(pagebuffer, 1, PAGE_SIZE, file);
            idinpage = 0;
        }
        get_tuple(pagebuffer, databuffer, idinpage);
        
        if (condition!=NULL) {
            if (condition->type == INT) {
                if (int_compare(condition->op, fixed_data[condition_column], condition->condition_int)==FALSE) {
                    continue;
                }
            }
            else{
                if (varchar_compare(condition->op, &databuffer[var_offset[condition_column]+2], condition->condition_varchar) == FALSE) {
                    continue;
                }
            }
        }
        
        if (join_type == INT) {
            hash_result = int_hash(fixed_data[join_column]);
        }
        else{
            memcpy(&len, &databuffer[var_offset[join_column]], 2);
            hash_result = varchar_hash(&databuffer[var_offset[join_column]+2], len);
        }
        
        hash_result %= HASH_TABLE_SIZE;
        
        insert_bucket = &hash_table[hash_result];
        
        for (; ; ) {
            if (insert_bucket->first==NULL){
                if (join_type == INT) {
                    insert_bucket->hash_int = fixed_data[join_column];
                }
                else{
                    insert_bucket->hash_varchar = malloc(sizeof(char)*(len+1));
                    if(insert_bucket->hash_varchar == NULL){
                        return FAIL;
                    }
                    strcpy(insert_bucket->hash_varchar, &databuffer[var_offset[join_column]+2]);
                }
                break;
            }
            else if((join_type == INT && fixed_data[join_column] == insert_bucket->hash_int)||(join_type == VARCHAR && strcmp(&databuffer[var_offset[join_column]+2], insert_bucket->hash_varchar)==0)) {
                break;
            }
            else{
                if (insert_bucket->next == NULL) {
                    insert_bucket->next = malloc(sizeof(join_hash_bucket_t));
                    if(insert_bucket->next == NULL){
                        return FAIL;
                    }
	                insert_bucket = insert_bucket->next;
	                insert_bucket->first = NULL;
	                insert_bucket->next = NULL;
	                insert_bucket->hash_varchar = NULL;
            	}
            	else { 
            		insert_bucket = insert_bucket->next;
            	}
            }
        }
        
        memcpy(&len, databuffer, 2);
        
        if (insert_bucket->first == NULL) {
            insert_bucket->first = malloc(sizeof(join_bucket_tuple_t));
            if(insert_bucket->first == NULL){
                return FAIL;
            }
            insert_tuple = insert_bucket->first;
            insert_tuple->next = NULL;
        }
        else{
            insert_tuple = insert_bucket->first;
            while (insert_tuple->next!=NULL){
                insert_tuple = insert_tuple->next;
            }
            insert_tuple->next = malloc(sizeof(join_bucket_tuple_t));
            if(insert_tuple->next == NULL){
                return FAIL;
            }
            insert_tuple = insert_tuple->next;
            insert_tuple->next = NULL;
        }
        
        insert_tuple->tuple = malloc(sizeof(char)*len);
        if(insert_tuple->tuple == NULL){
            return FAIL;
        }
        memcpy(insert_tuple->tuple, databuffer, len);
    }
    return SUCCESS;
}


int select_all_2(char *table_name_1, char *table_name_2, condition_t * condition_1,char contable_1, condition_t* condition_2,char contable_2,join_condition_t* join_condition){
    int len;
    unsigned short short_len;
    char *table_file;
    table_data_t metadata_1, metadata_2;
    int i,j;
    int condition_column_1 = -1;
    int condition_column_2 = -1;
    condition_t *temp;
    int column_int_1 = -1, column_int_2 = -1;
    int column_var_1 = -1, column_var_2 = -1;
    char type;
    char join_type_1=0,join_type_2=0;
    int join_column_1 = -1;
    int join_column_2 = -1;
    output_info_t * output_info_list_1, *output_info_list_2;
    
    join_hash_bucket_t hash_table[HASH_TABLE_SIZE];
    
    char databuffer[PAGE_SIZE];
    char pagebuffer[PAGE_SIZE];
    char databuffer_1[PAGE_SIZE];
    page_header_t *page_header;
    unsigned short idinpage;
    unsigned short *var_offset;
    int *fixed_data;
    unsigned short *var_offset_1;
    int *fixed_data_1;
    
    unsigned int hash_result;
    join_hash_bucket_t *search_bucket;
    join_bucket_tuple_t *search_tuple;
    
    len = (int)strlen(table_name_1);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name_1);
    strcat(table_file, ".tbl");
    
    FILE* filemeta_1 = fopen(table_file, "rb");
    if (filemeta_1==NULL) {
        printf("Table %s doesn't exist\n",table_name_1);
        free(table_file);
        return FAIL;
    }
    FILE* file_1 = fopen(table_file, "rb");
    free(table_file);
    
    len = (int)strlen(table_name_2);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name_2);
    strcat(table_file, ".tbl");
    
    FILE* filemeta_2 = fopen(table_file, "rb");
    if (filemeta_2==NULL) {
        printf("Table %s doesn't exist\n",table_name_2);
        free(table_file);
        return FAIL;
    }
    FILE* file_2 = fopen(table_file, "rb");
    free(table_file);
    
    fread(&metadata_1, 1, sizeof(table_data_t), filemeta_1);
    fread(&metadata_2, 1, sizeof(table_data_t), filemeta_2);

    output_info_list_1 = malloc(sizeof(output_info_t)*metadata_1.columnnum);
    
    for (i=0; i<metadata_1.columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), filemeta_1);
        if (type == INT) {
            column_int_1++;
            output_info_list_1[i].type = INT;
            output_info_list_1[i].columnnum = column_int_1;
        }
        else{
            column_var_1++;
            output_info_list_1[i].type = VARCHAR;
            output_info_list_1[i].columnnum = column_var_1;
        }
        
        
        fread((void *)&len, 1, sizeof(int), filemeta_1);
        
        fread((void *)output_info_list_1[i].columnname, 1, len+1, filemeta_1);
        
        if (join_column_1 == -1 && join_condition->table1 != 2) {
            if (strcmp(output_info_list_1[i].columnname, join_condition->columnname1)==0) {
                join_column_1 = i;
                if (join_condition->table1 == 0) {
                    join_condition->table1 = 3;
                }
            join_type_1 = type;
        	}
        }
        
        if (join_column_2 == -1 && join_condition->table2 != 2) {
            if (strcmp(output_info_list_1[i].columnname, join_condition->columnname2)==0) {
                join_column_2 = i;
                if (join_condition->table2 == 0) {
                    join_condition->table2 = 3;
                }
                join_type_2 = type;
            }
        }
        
        if (condition_1 && condition_column_1==-1 && contable_1 != 2) {
            if (strcmp(output_info_list_1[i].columnname, condition_1->columnname)==0) {
                if (type!=condition_1->type) {
                    if (contable_1 == 1) {
                        printf("Predicate %s.%s ",table_name_1,output_info_list_1[i].columnname);
                    }
                    else{
                        printf("Predicate %s ",output_info_list_1[i].columnname);
                    }
                    switch (condition_1->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_1->type == INT) {
                        printf(" %d error\n", condition_1->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_1->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list_1);
                    return FAIL;
                }
                else{
                    condition_column_1 = i;
                    if (contable_1 == 0) {
                        contable_1 = 3;
                    }
                }
            }
        }
        
        if (condition_2 && condition_column_2==-1 && contable_2 != 2) {
            if (strcmp(output_info_list_1[i].columnname, condition_2->columnname)==0) {
                if (type!=condition_2->type) {
                    if (contable_2 == 1) {
                        printf("Predicate %s.%s ",table_name_1,output_info_list_1[i].columnname);
                    }
                    else{
                        printf("Predicate %s ",output_info_list_1[i].columnname);
                    }
                    switch (condition_2->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_2->type == INT) {
                        printf(" %d error\n", condition_2->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_2->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list_1);
                    return FAIL;
                }
                else{
                    condition_column_2 = i;
                    if (contable_2 == 0) {
                        contable_2 = 3;
                    }
                }
            }
        }
        
        
    }
    
    output_info_list_2 = malloc(sizeof(output_info_t)*metadata_2.columnnum);
    
    for (i=0; i<metadata_2.columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), filemeta_2);
        if (type == INT) {
            column_int_2++;
            output_info_list_2[i].type = INT;
            output_info_list_2[i].columnnum = column_int_2;
        }
        else{
            column_var_2++;
            output_info_list_2[i].type = VARCHAR;
            output_info_list_2[i].columnnum = column_var_2;
        }
        
        
        fread((void *)&len, 1, sizeof(int), filemeta_2);
        
        fread((void *)output_info_list_2[i].columnname, 1, len+1, filemeta_2);
        
        if ((join_column_1 == -1 && join_condition->table1 != 1)||join_condition->table1 == 3) {
            if (strcmp(output_info_list_2[i].columnname, join_condition->columnname1)==0) {
                join_column_1 = i;
                if (join_condition->table1 == 3) {
                    printf("Ambiguous column %s\n", join_condition->columnname1);
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list_1);
                    free(output_info_list_2);
                    return FAIL;
                }
                join_condition->table1 = 2;
                join_type_1 = type;
            }
        }
        
        if ((join_column_2 == -1 && join_condition->table2 != 1)||join_condition->table2 == 3) {
            if (strcmp(output_info_list_2[i].columnname, join_condition->columnname2)==0) {
                join_column_2 = i;
                if (join_condition->table2 == 3) {
                    printf("Ambiguous column %s\n", join_condition->columnname2);
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list_1);
                    free(output_info_list_2);
                    return FAIL;
                }
                join_condition->table2 = 2;
                join_type_2 = type;
            }
        }
        
        if (condition_1 && ((condition_column_1==-1 && contable_1 != 1)||contable_1 == 3)) {
            if (strcmp(output_info_list_2[i].columnname, condition_1->columnname)==0) {
                if (type!=condition_1->type) {
                    if (contable_1 == 2) {
                        printf("Predicate %s.%s ",table_name_2,output_info_list_2[i].columnname);
                    }
                    else{
                        printf("Predicate %s ",output_info_list_2[i].columnname);
                    }
                    switch (condition_1->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_1->type == INT) {
                        printf(" %d error\n", condition_1->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_1->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list_1);
                    free(output_info_list_2);
                    return FAIL;
                }
                else{
                    if (contable_1 == 3) {
                        printf("Ambiguous column %s\n", condition_1->columnname);
                        fclose(file_1);
                        fclose(filemeta_1);
                        fclose(file_2);
                        fclose(filemeta_2);
                        free(output_info_list_1);
                        free(output_info_list_2);
                        return FAIL;
                    }
                    condition_column_1 = i;
                    contable_1 = 2;
                }
            }
        }
        
        if (condition_2 && ((condition_column_2==-1 && contable_2 != 1)||contable_2==3)) {
            if (strcmp(output_info_list_2[i].columnname, condition_2->columnname)==0) {
                if (type!=condition_2->type) {
                    if (contable_2 == 2) {
                        printf("Predicate %s.%s ",table_name_2,output_info_list_2[i].columnname);
                    }
                    else{
                        printf("Predicate %s ",output_info_list_2[i].columnname);
                    }
                    switch (condition_2->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_2->type == INT) {
                        printf(" %d error\n", condition_2->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_2->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list_1);
                    free(output_info_list_2);
                    return FAIL;
                }
                else{
                    if (contable_2 == 3) {
                        printf("Ambiguous column %s\n", condition_2->columnname);
                        fclose(file_1);
                        fclose(filemeta_1);
                        fclose(file_2);
                        fclose(filemeta_2);
                        free(output_info_list_1);
                        free(output_info_list_2);
                        return FAIL;
                    }
                    condition_column_2 = i;
                    contable_2 = 2;
                }
            }
        }
    }
    
    if (join_column_1==-1) {
        if (join_condition->table1 == 1) {
            printf("Column %s.%s doesn't exist\n",table_name_1,join_condition->columnname1);
        }
        else if(join_condition->table1 == 2){
            printf("Column %s.%s doesn't exist\n",table_name_2,join_condition->columnname1);
        }
        else{
            printf("Column %s doesn't exist\n",join_condition->columnname1);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list_1);
        free(output_info_list_2);
        return FAIL;
    }
    
    if (join_column_2==-1) {
        if (join_condition->table2 == 1) {
            printf("Column %s.%s doesn't exist\n",table_name_1,join_condition->columnname2);
        }
        else if(join_condition->table2 == 2){
            printf("Column %s.%s doesn't exist\n",table_name_2,join_condition->columnname2);
        }
        else{
            printf("Column %s doesn't exist\n",join_condition->columnname2);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list_1);
        free(output_info_list_2);
        return FAIL;
    }
    
    if (join_condition->table1==3) {
        join_condition->table1=1;
    }
    
    if (join_condition->table2==3) {
        join_condition->table2=1;
    }
    
    if (join_condition->table1 == join_condition->table2) {
        printf("Syntax error\n");
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list_1);
        free(output_info_list_2);
        return FAIL;
    }
    
    if (join_type_1!=join_type_2) {
        printf("Join predicate %s = %s error\n", join_condition->columnname1, join_condition->columnname2);
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list_1);
        free(output_info_list_2);
        return FAIL;
    }
    
    if (contable_1==3) {
        contable_1 = 1;
    }
    
    if (contable_2==3) {
        contable_2 = 1;
    }
    
    if (condition_column_1 == -1 && condition_1) {
        if (contable_1 == 2) {
            printf("Column %s.%s doesn't exist\n",table_name_2,condition_1->columnname);
        }
        else if(contable_1 == 1){
            printf("Column %s.%s doesn't exist\n",table_name_1,condition_1->columnname);
        }
        else{
            printf("Column %s doesn't exist\n",condition_1->columnname);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list_1);
        free(output_info_list_2);
        return FAIL;
    }
    
    if (condition_column_2 == -1 && condition_2) {
        if (contable_2 == 2) {
            printf("Column %s.%s doesn't exist\n",table_name_2,condition_2->columnname);
        }
        else if(contable_2 == 1){
            printf("Column %s.%s doesn't exist\n",table_name_1,condition_2->columnname);
        }
        else{
            printf("Column %s doesn't exist\n",condition_2->columnname);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list_1);
        free(output_info_list_2);
        return FAIL;
    }
    
    if (condition_1!=NULL && condition_2!=NULL && contable_1 == contable_2) {
        printf("Syntax error\n");
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list_1);
        free(output_info_list_2);
        return FAIL;
    }
    
    if (join_condition->table1 == 2) {
        int_swap(&join_column_1, &join_column_2);
        char_swap(join_condition->columnname1, join_condition->columnname2);
    }
    
    if ((condition_1!=NULL && contable_1 == 2 )|| (condition_2!=NULL && contable_2 == 1)) {
        temp = condition_1;
        condition_1 = condition_2;
        condition_2 = temp;
        int_swap(&condition_column_1, &condition_column_2);
    }
    
    for (i = 0; i<metadata_1.columnnum; i++) {
        printf("%s|",output_info_list_1[i].columnname);
    }
    
    for (i = 0; i<metadata_2.columnnum; i++) {
        printf("%s",output_info_list_2[i].columnname);
        if (i!=metadata_2.columnnum-1) {
            printf("|");
        }
        else{
            printf("\n");
        }
    }
    
    if(condition_column_1==-1)
        condition_column_1=0;
    if (condition_column_2==-1)
        condition_column_2=0;
    
    int flag;
    
    if (metadata_1.datapage<=metadata_2.datapage) {
        flag = join_hash(hash_table, condition_1, output_info_list_1[condition_column_1].columnnum, file_1, &metadata_1, output_info_list_1[join_column_1].columnnum, join_type_1);
        if(flag == FAIL)
        {
            printf("Malloc failed\n");
            free_join_hash(hash_table);
            fclose(file_1);
            fclose(filemeta_1);
            fclose(file_2);
            fclose(filemeta_2);
            free(output_info_list_1);
            free(output_info_list_2);
            return FAIL;
        }
        fseek(file_2, metadata_2.datastartpage*PAGE_SIZE, SEEK_SET);
        page_header = (page_header_t *)pagebuffer;
        fread(pagebuffer, 1, PAGE_SIZE, file_2);
        
        var_offset = (unsigned short *)databuffer;
        var_offset++;
        fixed_data = (int *)((char *)databuffer+2*(1+metadata_2.varcharnum));
        
        var_offset_1 = (unsigned short *)databuffer_1;
        var_offset_1++;
        fixed_data_1 = (int *)((char *)databuffer_1+2*(1+metadata_1.varcharnum));
        
        idinpage = 0;
        for (i = 0; i<metadata_2.tuplenum; i++,idinpage++) {
            if (idinpage>=page_header->tuplenum) {
                fread(pagebuffer, 1, PAGE_SIZE, file_2);
                idinpage = 0;
            }
            get_tuple(pagebuffer, databuffer, idinpage);
            
            if (condition_2!=NULL) {
                if (output_info_list_2[condition_column_2].type==INT) {
                    if (int_compare(condition_2->op, fixed_data[output_info_list_2[condition_column_2].columnnum], condition_2->condition_int)==FALSE) {
                        continue;
                    }
                }
                else{
                    if (varchar_compare(condition_2->op, &databuffer[var_offset[output_info_list_2[condition_column_2].columnnum]+2], condition_2->condition_varchar)==FALSE) {
                        continue;
                    }
                }
            }
            
            if (join_type_1 == INT) {
                hash_result = int_hash(fixed_data[output_info_list_2[join_column_2].columnnum]);
            }
            else{
                memcpy(&short_len, &databuffer[var_offset[output_info_list_2[join_column_2].columnnum]], 2);
                hash_result = varchar_hash(&databuffer[var_offset[output_info_list_2[join_column_2].columnnum]+2], short_len);
            }
            
            hash_result%=HASH_TABLE_SIZE;
            
            search_bucket = &hash_table[hash_result];
            
            for (; ; ) {
                if (search_bucket->first==NULL){
                    goto noresult1;
                }
                else if((join_type_1 == INT && fixed_data[output_info_list_2[join_column_2].columnnum] == search_bucket->hash_int)||(join_type_1 == VARCHAR && strcmp(&databuffer[var_offset[output_info_list_2[join_column_2].columnnum]+2], search_bucket->hash_varchar)==0)) {
                    break;
                }
                else{
                    if (search_bucket->next == NULL) {
                        goto noresult1;
                    }
                    else{
                        search_bucket = search_bucket->next;
                    }
                }
            }
            
            search_tuple = search_bucket->first;
            while (search_tuple!=NULL) {
                memcpy(&short_len, search_tuple->tuple, 2);
                memcpy(databuffer_1, search_tuple->tuple, short_len);
                for (j=0; j<metadata_1.columnnum; j++) {
                    if (output_info_list_1[j].type==INT) {
                        printf("%d|",fixed_data_1[output_info_list_1[j].columnnum]);
                    }
                    else{
                        printf("%s|",&databuffer_1[var_offset_1[output_info_list_1[j].columnnum]+2]);
                    }
                }
                
                for (j=0; j<metadata_2.columnnum; j++) {
                    if (output_info_list_2[j].type==INT) {
                        printf("%d",fixed_data[output_info_list_2[j].columnnum]);
                    }
                    else{
                        printf("%s",&databuffer[var_offset[output_info_list_2[j].columnnum]+2]);
                    }
                    if (j!=metadata_2.columnnum-1) {
                        printf("|");
                    }
                    else{
                        printf("\n");
                    }
                }
                search_tuple = search_tuple->next;
            }
        noresult1:
            continue;
        }
        
    }
    else{
        flag = join_hash(hash_table, condition_2, output_info_list_2[condition_column_2].columnnum, file_2, &metadata_2, output_info_list_2[join_column_2].columnnum, join_type_1);
        if(flag == FAIL)
        {
            printf("Malloc failed\n");
            free_join_hash(hash_table);
            fclose(file_1);
            fclose(filemeta_1);
            fclose(file_2);
            fclose(filemeta_2);
            free(output_info_list_1);
            free(output_info_list_2);
            return FAIL;
        }
        fseek(file_1, metadata_1.datastartpage*PAGE_SIZE, SEEK_SET);
        page_header = (page_header_t *)pagebuffer;
        fread(pagebuffer, 1, PAGE_SIZE, file_1);
        
        var_offset = (unsigned short *)databuffer;
        var_offset++;
        fixed_data = (int *)((char *)databuffer+2*(1+metadata_1.varcharnum));
        
        var_offset_1 = (unsigned short *)databuffer_1;
        var_offset_1++;
        fixed_data_1 = (int *)((char *)databuffer_1+2*(1+metadata_2.varcharnum));
        
        idinpage = 0;
        for (i = 0; i<metadata_1.tuplenum; i++,idinpage++) {
            if (idinpage>=page_header->tuplenum) {
                fread(pagebuffer, 1, PAGE_SIZE, file_1);
                idinpage = 0;
            }
            get_tuple(pagebuffer, databuffer, idinpage);
            
            if (condition_1!=NULL) {
                if (output_info_list_1[condition_column_1].type==INT) {
                    if (int_compare(condition_1->op, fixed_data[output_info_list_1[condition_column_1].columnnum], condition_1->condition_int)==FALSE) {
                        continue;
                    }
                }
                else{
                    if (varchar_compare(condition_1->op, &databuffer[var_offset[output_info_list_1[condition_column_1].columnnum]+2], condition_1->condition_varchar)==FALSE) {
                        continue;
                    }
                }
            }
            
            if (join_type_1 == INT) {
                hash_result = int_hash(fixed_data[output_info_list_1[join_column_1].columnnum]);
            }
            else{
                memcpy(&short_len, &databuffer[var_offset[output_info_list_1[join_column_1].columnnum]], 2);
                hash_result = varchar_hash(&databuffer[var_offset[output_info_list_1[join_column_1].columnnum]+2], short_len);
            }
            
            hash_result%=HASH_TABLE_SIZE;
            
            search_bucket = &hash_table[hash_result];
            
            for (; ; ) {
                if (search_bucket->first==NULL){
                    goto noresult2;
                }
                else if((join_type_1 == INT && fixed_data[output_info_list_1[join_column_1].columnnum] == search_bucket->hash_int)||(join_type_1 == VARCHAR && strcmp(&databuffer[var_offset[output_info_list_1[join_column_1].columnnum]+2], search_bucket->hash_varchar)==0)) {
                    break;
                }
                else{
                    if (search_bucket->next == NULL) {
                        goto noresult2;
                    }
                    else{
                        search_bucket = search_bucket->next;
                    }
                }
            }
            
            search_tuple = search_bucket->first;
            while (search_tuple!=NULL) {
                memcpy(&short_len, search_tuple->tuple, 2);
                memcpy(databuffer_1, search_tuple->tuple, short_len);
                for (j=0; j<metadata_1.columnnum; j++) {
                    if (output_info_list_1[j].type==INT) {
                        printf("%d|",fixed_data[output_info_list_1[j].columnnum]);
                    }
                    else{
                        printf("%s|",&databuffer[var_offset[output_info_list_1[j].columnnum]+2]);
                    }
                }
                
                for (j=0; j<metadata_2.columnnum; j++) {
                    if (output_info_list_2[j].type==INT) {
                        printf("%d",fixed_data_1[output_info_list_2[j].columnnum]);
                    }
                    else{
                        printf("%s",&databuffer_1[var_offset_1[output_info_list_2[j].columnnum]+2]);
                    }
                    if (j!=metadata_2.columnnum-1) {
                        printf("|");
                    }
                    else{
                        printf("\n");
                    }
                }
                search_tuple = search_tuple->next;
            }
        noresult2:
            continue;
        }
        
    }
    
    free_join_hash(hash_table);
    fclose(file_1);
    fclose(filemeta_1);
    fclose(file_2);
    fclose(filemeta_2);
    free(output_info_list_1);
    free(output_info_list_2);
    
    return SUCCESS;
}

int output_info_search_join(output_info_t *list, char **outputname, int outputnum, char *outputtable, char *columnname, char type, int columnnum, char nowtable){
    int i;
    int find;
    
    for (i = 0 ,find = 0; i<outputnum; i++) {
        if ((list[i].find==0&&(outputtable[i]==nowtable||outputtable[i]==0))||(nowtable==2&&outputtable[i]==3)) {
            if (strcmp(outputname[i], columnname)==0) {
                if (outputtable[i]==0) {
                    outputtable[i]=nowtable+2;
                }
                else if(outputtable[i]==3){
                    printf("Ambiguous column %s\n",columnname);
                    return -1;
                }
                list[i].find = 1;
                list[i].type = type;
                list[i].columnnum = (short)columnnum;
                strcpy(list[i].columnname, columnname);
                find++;
            }
        }
    }
    
    return find;
}

int select_partial_2(char *table_name_1, char *table_name_2, char ** outputname, char *outputtable, int outputnum,condition_t * condition_1,char contable_1, condition_t* condition_2,char contable_2,join_condition_t* join_condition){
    int len;
    unsigned short short_len;
    char *table_file;
    table_data_t metadata_1, metadata_2;
    int i,j;
    int condition_column_1 = -1;
    int condition_column_2 = -1;
    char condition_type_1 = 0, condition_type_2 = 0;
    condition_t *temp;
    int column_int_1 = -1, column_int_2 = -1;
    int column_var_1 = -1, column_var_2 = -1;
    char type;
    char join_type_1=0,join_type_2=0;
    int join_column_1 = -1;
    int join_column_2 = -1;
    output_info_t * output_info_list;
    char namebuffer[128+1];
    join_hash_bucket_t hash_table[HASH_TABLE_SIZE];
    int find=0,findtemp;
    char hashtable=1;
    int another_tuplenum;
    
    char pagebuffer[PAGE_SIZE];
    char databuffer_1[PAGE_SIZE];
    char databuffer_2[PAGE_SIZE];
    page_header_t *page_header;
    unsigned short idinpage;
    unsigned short *var_offset_1;
    int *fixed_data_1;
    unsigned short *var_offset_2;
    int *fixed_data_2;
    
    unsigned int hash_result;
    join_hash_bucket_t *search_bucket;
    join_bucket_tuple_t *search_tuple;
    
    len = (int)strlen(table_name_1);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name_1);
    strcat(table_file, ".tbl");
    
    FILE* filemeta_1 = fopen(table_file, "rb");
    if (filemeta_1==NULL) {
        printf("Table %s doesn't exist\n",table_name_1);
        free(table_file);
        return FAIL;
    }
    FILE* file_1 = fopen(table_file, "rb");
    free(table_file);
    
    len = (int)strlen(table_name_2);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name_2);
    strcat(table_file, ".tbl");
    
    FILE* filemeta_2 = fopen(table_file, "rb");
    if (filemeta_2==NULL) {
        printf("Table %s doesn't exist\n",table_name_2);
        free(table_file);
        return FAIL;
    }
    FILE* file_2 = fopen(table_file, "rb");
    free(table_file);
    
    fread(&metadata_1, 1, sizeof(table_data_t), filemeta_1);
    fread(&metadata_2, 1, sizeof(table_data_t), filemeta_2);
    
    output_info_list = malloc(outputnum*sizeof(output_info_t));
    
    for (i = 0; i < outputnum; ++i)
    {
        output_info_list[i].find = 0;
    }
    
    for (i=0; i<metadata_1.columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), filemeta_1);
        fread((void *)&len, 1, sizeof(int), filemeta_1);
        fread((void *)namebuffer, 1, len+1, filemeta_1);
        
        if (type == INT) {
            column_int_1++;
            find+=output_info_search_join(output_info_list, outputname, outputnum, outputtable, namebuffer, type, column_int_1, 1);
        }
        else{
            column_var_1++;
            find+=output_info_search_join(output_info_list, outputname, outputnum, outputtable, namebuffer, type, column_var_1, 1);
        }
        
        if (join_column_1 == -1 && join_condition->table1 != 2) {
            if (strcmp(namebuffer, join_condition->columnname1)==0) {
                if (type==INT) {
                    join_column_1 = column_int_1;
                }
                else{
                    join_column_1 = column_var_1;
                }
                if (join_condition->table1 == 0) {
                    join_condition->table1 = 3;
                }
                join_type_1 = type;
            }  
        }
        
        if (join_column_2 == -1 && join_condition->table2 != 2) {
            if (strcmp(namebuffer, join_condition->columnname2)==0) {
                if (type==INT) {
                    join_column_2 = column_int_1;
                }
                else{
                    join_column_2 = column_var_1;
                }
                if (join_condition->table2 == 0) {
                    join_condition->table2 = 3;
                }
                join_type_2 = type;
            }
        }
        
        if (condition_1 && condition_column_1==-1 && contable_1 != 2) {
            if (strcmp(namebuffer, condition_1->columnname)==0) {
                if (type!=condition_1->type) {
                    if (contable_1 == 1) {
                        printf("Predicate %s.%s ",table_name_1,namebuffer);
                    }
                    else{
                        printf("Predicate %s ",namebuffer);
                    }
                    switch (condition_1->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_1->type == INT) {
                        printf(" %d error\n", condition_1->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_1->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list);
                    return FAIL;
                }
                else{
                    if (type==INT) {
                        condition_column_1 = column_int_1;
                    }
                    else{
                        condition_column_1 = column_var_1;
                    }
                    if (contable_1 == 0) {
                        contable_1 = 3;
                    }
                    condition_type_1 = type;
                }
            }
        }
        
        if (condition_2 && condition_column_2==-1 && contable_2 != 2) {
            if (strcmp(namebuffer, condition_2->columnname)==0) {
                if (type!=condition_2->type) {
                    if (contable_2 == 1) {
                        printf("Predicate %s.%s ",table_name_1,namebuffer);
                    }
                    else{
                        printf("Predicate %s ",namebuffer);
                    }
                    switch (condition_2->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_2->type == INT) {
                        printf(" %d error\n", condition_2->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_2->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list);
                    return FAIL;
                }
                else{
                    if (type==INT) {
                        condition_column_2 = column_int_1;
                    }
                    else{
                        condition_column_2 = column_var_1;
                    }
                    if (contable_2 == 0) {
                        contable_2 = 3;
                    }
                    condition_type_2 = type;
                }
            }
        }
        
    }
    
    for (i=0; i<metadata_2.columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), filemeta_2);
        fread((void *)&len, 1, sizeof(int), filemeta_2);
        fread((void *)namebuffer, 1, len+1, filemeta_2);
        
        if (type == INT) {
            column_int_2++;
            findtemp=output_info_search_join(output_info_list, outputname, outputnum, outputtable, namebuffer, type, column_int_2, 2);
            if (findtemp==-1) {
                fclose(file_1);
                fclose(filemeta_1);
                fclose(file_2);
                fclose(filemeta_2);
                free(output_info_list);
                return FAIL;
            }
            find+=findtemp;
        }
        else{
            column_var_2++;
            findtemp=output_info_search_join(output_info_list, outputname, outputnum, outputtable, namebuffer, type, column_var_2, 2);
            if (findtemp==-1) {
                fclose(file_1);
                fclose(filemeta_1);
                fclose(file_2);
                fclose(filemeta_2);
                free(output_info_list);
                return FAIL;
            }
            find+=findtemp;
        }
        
        if ((join_column_1 == -1 && join_condition->table1 != 1)||join_condition->table1 == 3) {
            if (strcmp(namebuffer, join_condition->columnname1)==0) {
                if (type==INT) {
                    join_column_1 = column_int_2;
                }
                else{
                    join_column_1 = column_var_2;
                }
                if (join_condition->table1 == 3) {
                    printf("Ambiguous column %s\n", join_condition->columnname1);
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list);
                    return FAIL;
                }
                if (join_condition->table1 == 0) {
                    join_condition->table1 = 2;
                }
            	join_type_1 = type;
            }
        }
        
        if ((join_column_2 == -1 && join_condition->table2 != 1)||join_condition->table2 == 3) {
            if (strcmp(namebuffer, join_condition->columnname2)==0) {
                if (type==INT) {
                    join_column_2 = column_int_2;
                }
                else{
                    join_column_2 = column_var_2;
                }
                if (join_condition->table2 == 3) {
                    printf("Ambiguous column %s\n", join_condition->columnname2);
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list);
                    return FAIL;
                }
                if (join_condition->table2 == 0) {
                    join_condition->table2 = 2;
                }
                join_type_2 = type;
            }
        }
        
        if (condition_1 && ((condition_column_1==-1 && contable_1 != 1)||contable_1 == 3)) {
            if (strcmp(namebuffer, condition_1->columnname)==0) {
                if (type!=condition_1->type) {
                    if (contable_1 == 2) {
                        printf("Predicate %s.%s ",table_name_2,namebuffer);
                    }
                    else{
                        printf("Predicate %s ",namebuffer);
                    }
                    switch (condition_1->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_1->type == INT) {
                        printf(" %d error\n", condition_1->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_1->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list);
                    return FAIL;
                }
                else{
                    if (contable_1 == 3) {
                        printf("Ambiguous column %s\n", condition_1->columnname);
                        fclose(file_1);
                        fclose(filemeta_1);
                        fclose(file_2);
                        fclose(filemeta_2);
                        free(output_info_list);
                        return FAIL;
                    }
                    if (type==INT) {
                        condition_column_1 = column_int_2;
                    }
                    else{
                        condition_column_1 = column_var_2;
                    }
                    contable_1 = 2;
                    condition_type_1 = type;
                }
            }
        }
        
        if (condition_2 &&(( condition_column_2==-1 && contable_2 != 1)||contable_2 == 3)) {
            if (strcmp(namebuffer, condition_2->columnname)==0) {
                if (type!=condition_2->type) {
                    if (contable_2 == 2) {
                        printf("Predicate %s.%s ",table_name_2,namebuffer);
                    }
                    else{
                        printf("Predicate %s ",namebuffer);
                    }
                    switch (condition_2->op) {
                        case op_l:
                            printf("<");
                            break;
                            
                        case op_g:
                            printf(">");
                            break;
                            
                        case op_eq:
                            printf("=");
                            break;
                            
                        case op_leq:
                            printf("<=");
                            break;
                            
                        case op_geq:
                            printf(">=");
                            break;
                            
                        case op_neq:
                            printf("!=");
                            break;
                            
                        case op_nlike:
                            printf("not like");
                            break;
                            
                        case op_like:
                            printf("like");
                            break;
                            
                        default:
                            break;
                    }
                    if (condition_2->type == INT) {
                        printf(" %d error\n", condition_2->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition_2->condition_varchar);
                    }
                    fclose(file_1);
                    fclose(filemeta_1);
                    fclose(file_2);
                    fclose(filemeta_2);
                    free(output_info_list);
                    return FAIL;
                }
                else{
                    if (contable_2 == 3) {
                        printf("Ambiguous column %s\n", condition_2->columnname);
                        fclose(file_1);
                        fclose(filemeta_1);
                        fclose(file_2);
                        fclose(filemeta_2);
                        free(output_info_list);
                        return FAIL;
                    }
                    if (type==INT) {
                        condition_column_2 = column_int_2;
                    }
                    else{
                        condition_column_2 = column_var_2;
                    }
                    contable_2 = 2;
                    condition_type_2 = type;
                }
            }
        }
    }


    
    if (find!=outputnum) {
        for (i=0; i<outputnum; i++) {
            if (output_info_list[i].find!=1) {
                if (outputtable[i]==1) {
                    printf("Column %s.",table_name_1);
                }
                else if(outputtable[i]==2){
                    printf("Column %s.",table_name_2);
                }
                else{
                    printf("Column ");
                }
                printf("%s doesn't exist\n",outputname[i]);
                fclose(file_1);
                fclose(filemeta_1);
                fclose(file_2);
                fclose(filemeta_2);
                free(output_info_list);
                return FAIL;
            }
        }
    }
    
    if (join_column_1==-1) {
        if (join_condition->table1 == 1) {
            printf("Column %s.%s doesn't exist\n",table_name_1,join_condition->columnname1);
        }
        else if(join_condition->table1 == 2){
            printf("Column %s.%s doesn't exist\n",table_name_2,join_condition->columnname1);
        }
        else{
            printf("Column %s doesn't exist\n",join_condition->columnname1);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list);
        return FAIL;
    }
    
    if (join_column_2==-1) {
        if (join_condition->table2 == 1) {
            printf("Column %s.%s doesn't exist\n",table_name_1,join_condition->columnname2);
        }
        else if(join_condition->table2 == 2){
            printf("Column %s.%s doesn't exist\n",table_name_2,join_condition->columnname2);
        }
        else{
            printf("Column %s doesn't exist\n",join_condition->columnname2);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list);
        return FAIL;
    }
    
    if (join_condition->table1==3) {
        join_condition->table1=1;
    }
    
    if (join_condition->table2==3) {
        join_condition->table2=1;
    }
    
    if (join_condition->table1 == join_condition->table2) {
        printf("Syntax error\n");
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list);
        return FAIL;
    }
    
    if (join_type_1!=join_type_2) {
        printf("Join predicate error\n");
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list);
        return FAIL;
    }
    
    if (contable_1==3) {
        contable_1 = 1;
    }
    
    if (contable_2==3) {
        contable_2 = 1;
    }
    
    if (condition_column_1 == -1 && condition_1) {
        if (contable_1 == 2) {
            printf("Column %s.%s doesn't exist\n",table_name_2,condition_1->columnname);
        }
        else if(contable_1 == 1){
            printf("Column %s.%s doesn't exist\n",table_name_1,condition_1->columnname);
        }
        else{
            printf("Column %s doesn't exist\n",condition_1->columnname);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list);
        return FAIL;
    }
    
    if (condition_column_2 == -1 && condition_2) {
        if (contable_2 == 2) {
            printf("Column %s.%s doesn't exist\n",table_name_2,condition_2->columnname);
        }
        else if(contable_2 == 1){
            printf("Column %s.%s doesn't exist\n",table_name_1,condition_2->columnname);
        }
        else{
            printf("Column %s doesn't exist\n",condition_2->columnname);
        }
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list);
        return FAIL;
    }

    if (condition_1!=NULL && condition_2!=NULL && contable_1 == contable_2) {
        printf("Syntax error\n");
        fclose(file_1);
        fclose(filemeta_1);
        fclose(file_2);
        fclose(filemeta_2);
        free(output_info_list);
        return FAIL;
    }
    
    if (join_condition->table1 == 2) {
        int_swap(&join_column_1, &join_column_2);
        char_swap(join_condition->columnname1, join_condition->columnname2);
    }

    
    if ((condition_1!=NULL &&contable_1 == 2 )||( condition_2!=NULL && contable_2 == 1)) {
        temp = condition_1;
        condition_1 = condition_2;
        condition_2 = temp;
        int_swap(&condition_column_1, &condition_column_2);
        type = condition_type_1;
        condition_type_1 = condition_type_2;
        condition_type_2 = type;
    }

    

    
    for (i=0; i<outputnum; i++) {
        if (outputtable[i]==1) {
            printf("%s.",table_name_1);
        }
        else if(outputtable[i]==2){
            printf("%s.",table_name_2);
        }
        printf("%s",output_info_list[i].columnname);
        if (i!=outputnum-1) {
            printf("|");
        }
        else{
            printf("\n");
        }
    }

    
    
    if(condition_column_1==-1)
        condition_column_1=0;
    if (condition_column_2==-1)
        condition_column_2=0;
    
    
    for (i=0; i<outputnum; i++) {
        if (outputtable[i]>=3) {
            outputtable[i]-=2;
        }
    }
    
    
    var_offset_1 = (unsigned short *)databuffer_1;
    var_offset_1++;
    fixed_data_1 = (int *)((char *)databuffer_1+2*(1+metadata_1.varcharnum));
    
    var_offset_2 = (unsigned short *)databuffer_2;
    var_offset_2++;
    fixed_data_2 = (int *)((char *)databuffer_2+2*(1+metadata_2.varcharnum));
    
    if (metadata_1.datapage<=metadata_2.datapage) {
        hashtable=1;
    }
    else{
        hashtable=2;
    }
    int flag;
    if (hashtable==1) {
        flag = join_hash(hash_table, condition_1, condition_column_1, file_1, &metadata_1, join_column_1, join_type_1);
        if(flag == FAIL)
        {
            printf("Malloc failed\n");
            
            free_join_hash(hash_table);
            fclose(file_1);
            fclose(filemeta_1);
            fclose(file_2);
            fclose(filemeta_2);
            free(output_info_list);
            return FAIL;
        }
        fseek(file_2, metadata_2.datastartpage*PAGE_SIZE, SEEK_SET);
        page_header = (page_header_t *)pagebuffer;
        fread(pagebuffer, 1, PAGE_SIZE, file_2);
        
        another_tuplenum = metadata_2.tuplenum;
    }
    else{
        flag = join_hash(hash_table, condition_2, condition_column_2, file_2, &metadata_2, join_column_2, join_type_1);
        if(flag == FAIL)
        {
            printf("Malloc failed\n");
            free_join_hash(hash_table);
            fclose(file_1);
            fclose(filemeta_1);
            fclose(file_2);
            fclose(filemeta_2);
            free(output_info_list);
            return FAIL;
        }      
        fseek(file_1, metadata_1.datastartpage*PAGE_SIZE, SEEK_SET);
        page_header = (page_header_t *)pagebuffer;
        fread(pagebuffer, 1, PAGE_SIZE, file_1);
        
        another_tuplenum = metadata_1.tuplenum;
    }
    
    idinpage = 0;
    for (i=0; i<another_tuplenum; i++,idinpage++) {
        if (hashtable==1) {
            if (idinpage>=page_header->tuplenum) {
                fread(pagebuffer, 1, PAGE_SIZE, file_2);
                idinpage = 0;
            }
            get_tuple(pagebuffer, databuffer_2, idinpage);
            
            if (condition_2!=NULL) {
                if (condition_type_2==INT) {
                    if (int_compare(condition_2->op, fixed_data_2[condition_column_2], condition_2->condition_int)==FALSE) {
                        continue;
                    }
                }
                else{
                    if (varchar_compare(condition_2->op, &databuffer_2[var_offset_2[condition_column_2]+2], condition_2->condition_varchar)==FALSE) {
                        continue;
                    }
                }
            }
            
            if (join_type_1 == INT) {
                hash_result = int_hash(fixed_data_2[join_column_2]);
            }
            else{
                memcpy(&short_len, &databuffer_2[var_offset_2[join_column_2]], 2);
                hash_result = varchar_hash(&databuffer_2[var_offset_2[join_column_2]+2], short_len);
            }
            
            hash_result%=HASH_TABLE_SIZE;
            
            search_bucket = &hash_table[hash_result];
            
            for (; ; ) {
                if (search_bucket->first==NULL){
                    goto noresult_partial;
                }
                else if((join_type_1 == INT && fixed_data_2[join_column_2] == search_bucket->hash_int)||(join_type_1 == VARCHAR && strcmp(&databuffer_2[var_offset_2[join_column_2]+2], search_bucket->hash_varchar)==0)) {
                    break;
                }
                else{
                    if (search_bucket->next == NULL) {
                        goto noresult_partial;
                    }
                    else{
                        search_bucket = search_bucket->next;
                    }
                }
            }
        }
        else{
            if (idinpage>=page_header->tuplenum) {
                fread(pagebuffer, 1, PAGE_SIZE, file_1);
                idinpage = 0;
            }
            get_tuple(pagebuffer, databuffer_1, idinpage);
            
            if (condition_1!=NULL) {
                if (condition_type_1==INT) {
                    if (int_compare(condition_1->op, fixed_data_1[condition_column_1], condition_1->condition_int)==FALSE) {
                        continue;
                    }
                }
                else{
                    if (varchar_compare(condition_1->op, &databuffer_1[var_offset_1[condition_column_1]+2], condition_1->condition_varchar)==FALSE) {
                        continue;
                    }
                }
            }
            
            if (join_type_1 == INT) {
                hash_result = int_hash(fixed_data_1[join_column_1]);
            }
            else{
                memcpy(&short_len, &databuffer_1[var_offset_1[join_column_1]], 2);
                hash_result = varchar_hash(&databuffer_1[var_offset_1[join_column_1]+2], short_len);
            }
            
            hash_result%=HASH_TABLE_SIZE;
            
            search_bucket = &hash_table[hash_result];
            
            for (; ; ) {
                if (search_bucket->first==NULL){
                    goto noresult_partial;
                }
                else if((join_type_1 == INT && fixed_data_1[join_column_1] == search_bucket->hash_int)||(join_type_1 == VARCHAR && strcmp(&databuffer_1[var_offset_1[join_column_1]+2], search_bucket->hash_varchar)==0)) {
                    break;
                }
                else{
                    if (search_bucket->next == NULL) {
                        goto noresult_partial;
                    }
                    else{
                        search_bucket = search_bucket->next;
                    }
                }
            }
        }
        
        search_tuple = search_bucket->first;
        while (search_tuple!=NULL) {
            memcpy(&short_len, search_tuple->tuple, 2);
            if (hashtable==1) {
                memcpy(databuffer_1, search_tuple->tuple, short_len);
            }
            else{
                memcpy(databuffer_2, search_tuple->tuple, short_len);
            }
            
            for (j=0; j<outputnum; j++) {
                if (outputtable[j]==1) {
                    if (output_info_list[j].type==INT) {
                        printf("%d",fixed_data_1[output_info_list[j].columnnum]);
                    }
                    else{
                        printf("%s",&databuffer_1[var_offset_1[output_info_list[j].columnnum]+2]);
                    }
                }
                else{
                    if (output_info_list[j].type==INT) {
                        printf("%d",fixed_data_2[output_info_list[j].columnnum]);
                    }
                    else{
                        printf("%s",&databuffer_2[var_offset_2[output_info_list[j].columnnum]+2]);
                    }
                }
                if (j!=outputnum-1) {
                    printf("|");
                }
                else{
                    printf("\n");
                }
            }
            search_tuple = search_tuple->next;
        }
        
    noresult_partial:
        continue;
    }
    
    free_join_hash(hash_table);
    fclose(file_1);
    fclose(filemeta_1);
    fclose(file_2);
    fclose(filemeta_2);
    free(output_info_list);
    
    return SUCCESS;
}
