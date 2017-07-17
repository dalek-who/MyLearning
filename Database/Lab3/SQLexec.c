//
//  SQLexec.c
//  database
//
//  Created by 谈清扬 on 2016/12/24.
//  Copyright © 2016年 University of Chinese Academy of Sciences. All rights reserved.
//

#include "SQLexec.h"


int create_table(char *table_name, column_type_t* column, int columnnum){
    int i;
    int len;
    char *table_file;
    int cursor;
    char buffer[PAGE_SIZE];
    table_data_t metadata;
    page_header_t page_header;
    char type;
    
    memset(buffer, 0, PAGE_SIZE);
    
    len = (int)strlen(table_name);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name);
    strcat(table_file, ".tbl");
    
    FILE* file = fopen(table_file, "rb+");
    if (file!=NULL) {
        printf("Can't create table %s\n",table_name);
        free(table_file);
        return FAIL;
    }
    file = fopen(table_file, "wb+");
    free(table_file);
    
    metadata.columnnum = (unsigned short)columnnum;
    metadata.tuplenum = 0;
    metadata.intnum = 0;
    metadata.varcharnum = 0;
    metadata.datapage = 1;
    
    cursor = sizeof(metadata);
    
    fseek(file, sizeof(metadata), SEEK_SET);
    
    for (i = 0; i<columnnum; i++) {
        if (column[i].type==VARCHAR) {
            metadata.varcharnum++;
        }
        else{
            metadata.intnum++;
        }
        type = (char)column[i].type;
        fwrite((void *)&type, 1, sizeof(char), file);
        len = (int)strlen(column[i].name);
        fwrite((void *)&len, 1, sizeof(int), file);
        cursor += sizeof(char)+sizeof(int);
        fwrite(column[i].name,1,len+1,file);
        cursor += len + 1;
    }
    
    metadata.datastartpage = cursor/PAGE_SIZE;

    cursor %= PAGE_SIZE;
    
    if (cursor>0) {
        metadata.datastartpage++;
        fwrite(buffer, 1, PAGE_SIZE-cursor, file);
    }
    

    
    page_header.tuplenum = 0;
    page_header.start = sizeof(page_header_t);
    page_header.end = PAGE_SIZE;
    page_header.remain = PAGE_SIZE-sizeof(page_header_t);
    
    fwrite((void *)&page_header, 1, sizeof(page_header_t), file);
    fwrite(buffer, 1, PAGE_SIZE-sizeof(page_header_t), file);
    
    fseek(file, 0, SEEK_SET);
    fwrite((void *)&metadata, 1, sizeof(table_data_t), file);
    
    printf("Successfully created table %s\n",table_name);
    fclose(file);
    
    return SUCCESS;
}

int read_table(char *table_file){
    char name[PAGE_SIZE];
    FILE* file = fopen(table_file, "rb");
    table_data_t metadata;
    int i;
    int len;
    char type;
    
    
    fread((void *)&metadata, 1, sizeof(table_data_t), file);
    
    for (i=0; i<metadata.columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), file);
        if (type == INT) {
            printf("INT  ");
        }
        else{
            printf("VAR  ");
        }
        fread((void *)&len, 1, sizeof(int), file);
        fread(name, 1, len+1, file);
        printf("%s\n",name);
    }
    
    fclose(file);
    
    return SUCCESS;
}

int drop_table(char *table_name){
    int len;
    char *table_file;
    
    len = (int)strlen(table_name);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name);
    strcat(table_file, ".tbl");
    
    FILE* file = fopen(table_file, "rb+");
    if (file==NULL) {
        printf("Can't drop table %s\n",table_name);
        free(table_file);
        return FAIL;
    }
    fclose(file);
    remove(table_file);
    free(table_file);
    printf("Successfully dropped table %s\n",table_name);
    
    return SUCCESS;
}

int add_tuple(char *page_buffer, char *tuple_buffer, unsigned short len){
    page_header_t *page_head;
    unsigned short *tuple_offset;
    unsigned short start;
    
    page_head = (page_header_t *)page_buffer;
    tuple_offset = (unsigned short *)(page_buffer + sizeof(page_header_t));
    
    page_head->end -= len;
    
    start = tuple_offset[page_head->tuplenum] = page_head->end;
    memcpy(&page_buffer[start], tuple_buffer, len);
    
    page_head->start +=sizeof(unsigned short);
    page_head->remain -= len + sizeof(unsigned short);
    page_head->tuplenum++;
    
    return SUCCESS;
}

unsigned short get_tuple(char *page_buffer, char *tuple_buffer, unsigned short id){
    unsigned short *tuple_offset;
    unsigned short start;
    unsigned short shortlen;
    
    tuple_offset = (unsigned short *)(page_buffer + sizeof(page_header_t));
    
    start = tuple_offset[id];
    
    memcpy(&shortlen, &page_buffer[start], sizeof(unsigned short));
    memcpy(tuple_buffer, &page_buffer[start], shortlen);
    
    return shortlen;
}

int insert_table(char *table_name, insert_t *insert, int columnnum){
    int len;
    unsigned short short_len;
    char *table_file;
    table_data_t metadata;
    page_header_t *page_head;
    char databuffer[PAGE_SIZE];
    char pagebuffer[PAGE_SIZE];
    unsigned short *var_offset;
    int *fixed_data;
    int i;
    char type;
    unsigned short cursor;
    
    len = (int)strlen(table_name);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name);
    strcat(table_file, ".tbl");
    
    FILE* filemeta = fopen(table_file, "rb+");
    if (filemeta==NULL) {
        printf("Table %s do not exist!\n",table_name);
        free(table_file);
        return FAIL;
    }
    FILE* file = fopen(table_file, "rb+");
    free(table_file);
    
    fread((void *)&metadata, 1, sizeof(table_data_t), filemeta);

    if (columnnum != metadata.columnnum) {
        printf("Wrong number of columns\n");
        fclose(file);
        fclose(filemeta);
        return FAIL;
    }
    
    var_offset = (unsigned short *)databuffer;
    var_offset++;
    fixed_data = (int *)((char *)databuffer+2*(1+metadata.varcharnum));
    cursor = 2*(1+metadata.varcharnum)+4*(metadata.intnum);
    
    for (i=0; i<columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), filemeta);
        if (type!=(char)insert[i].type) {
            printf("Value and column type mismatch\n");
            fclose(filemeta);
            fclose(file);
            return FAIL;
        }
        fread((void *)&len, 1, sizeof(int), filemeta);
        fseek(filemeta, len+1, SEEK_CUR);
        if (type == INT) {
            *fixed_data = insert[i].content_int;
            fixed_data ++;

        }
        else{
            *var_offset = cursor;
            var_offset++;
            short_len = (unsigned short)strlen(insert[i].content_varchar);
            memcpy(&databuffer[cursor], &short_len, sizeof(unsigned short));
            cursor+=sizeof(unsigned short);
            memcpy(&databuffer[cursor], insert[i].content_varchar, short_len+1);
            cursor+=short_len+1;
        }
    }
    
    memcpy(databuffer, &cursor, sizeof(unsigned short));
    
    fseek(file, (metadata.datastartpage+metadata.datapage-1)*PAGE_SIZE, SEEK_SET);
    fread(pagebuffer, 1, PAGE_SIZE, file);
    page_head = (page_header_t *)pagebuffer;

    if ((cursor + sizeof(unsigned short))> PAGE_SIZE - sizeof(page_header_t))
    {   
        printf("Tuple larger than one page\n");
        fclose(filemeta);
        fclose(file);
        return FAIL;
    }
    
    if (page_head->remain < cursor + sizeof(unsigned short)) {
        metadata.datapage++;
        memset(pagebuffer, 0, PAGE_SIZE);
        page_head->tuplenum = 0;
        page_head->end = PAGE_SIZE;
        page_head->start = sizeof(page_header_t);
        page_head->remain = PAGE_SIZE-sizeof(page_header_t);
        //fseek(file, PAGE_SIZE, SEEK_CUR);
        fseek(file, (metadata.datastartpage+metadata.datapage-1)*PAGE_SIZE, SEEK_SET);
    }
    else{
        //fseek(file, -PAGE_SIZE, SEEK_CUR);
        fseek(file, (metadata.datastartpage+metadata.datapage-1)*PAGE_SIZE, SEEK_SET);
    }
    
    add_tuple(pagebuffer, databuffer, cursor);

    fwrite(pagebuffer, 1, PAGE_SIZE, file);
    metadata.tuplenum++;
    fseek(filemeta, 0, SEEK_SET);
    fwrite(&metadata, 1, sizeof(table_data_t), filemeta);
    
    fclose(filemeta);
    fclose(file);
    
    return SUCCESS;
}

int int_compare(int op, int data, int condition){
    switch (op) {
        case op_l:
            return data<condition;
            break;
        
        case op_leq:
            return data<=condition;
            break;
        
        case op_g:
            return data>condition;
            break;
            
        case op_geq:
            return data>=condition;
        
        case op_eq:
            return data==condition;
            
        case op_neq:
            return data!=condition;
            
        default:
            return FALSE;
            break;
    }
}

int varchar_compare(int op, char *data, char *condition){
    switch (op) {
        case op_eq:
            if (strcmp(data, condition)==0) {
                return TRUE;
            }
            else{
                return FALSE;
            }
            break;
            
        case op_neq:
            if (strcmp(data, condition)==0) {
                return FALSE;
            }
            else{
                return TRUE;
            }
            break;
        
        case op_like:
            if (strstr(data, condition)!=NULL) {
                return TRUE;
            }
            else{
                return FALSE;
            }
            
        case op_nlike:
            if (strstr(data, condition)!=NULL) {
                return FALSE;
            }
            else{
                return TRUE;
            }
            
        default:
            return FALSE;
            break;
    }
}

int output_info_search(output_info_t *list, char **outputname, int outputnum, char *columnname, char type, int columnnum){
    int i;
    int find;
    
    for (i = 0 ,find = 0; i<outputnum; i++) {
        if (strcmp(outputname[i], columnname)==0) {
            if (list[i].find == 1) {
                printf("ERROR");
                return -1;
            }
            list[i].find = 1;
            list[i].type = type;
            list[i].columnnum = (short)columnnum;
            strcpy(list[i].columnname, columnname);
            find++;
        }

    }
    
    return find;
}

int select_all_1(char *table_name, condition_t * condition){
    int len;
    char *table_file;
    table_data_t metadata;
    int i,j;
    int condition_sign = 0;
    int condition_column=-1;
    int column_int=-1;
    int column_var=-1;
    char type;
    output_info_t * output_info_list;
    char databuffer[PAGE_SIZE];
    char pagebuffer[PAGE_SIZE];
    page_header_t *page_header;
    unsigned short idinpage;
    unsigned short *var_offset;
    int *fixed_data;
    
    
    len = (int)strlen(table_name);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name);
    strcat(table_file, ".tbl");
    
    FILE* filemeta = fopen(table_file, "rb");
    if (filemeta==NULL) {
        printf("Table %s doesn't exist\n",table_name);
        free(table_file);
        return FAIL;
    }
    FILE* file = fopen(table_file, "rb");
    free(table_file);
    
    fread(&metadata, 1, sizeof(table_data_t), filemeta);
    
    output_info_list = malloc(sizeof(output_info_t)*metadata.columnnum);
    
    if (condition!=NULL) {
        condition_sign = 1;
    }
    
    for (i=0; i<metadata.columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), filemeta);
        if (type == INT) {
            column_int++;
            output_info_list[i].type = INT;
            output_info_list[i].columnnum = column_int;
        }
        else{
            column_var++;
            output_info_list[i].type = VARCHAR;
            output_info_list[i].columnnum = column_var;
        }
        
        
        fread((void *)&len, 1, sizeof(int), filemeta);
        
        fread((void *)output_info_list[i].columnname, 1, len+1, filemeta);
        
        if (condition_sign&&condition_column==-1) {
            
            if (strcmp(output_info_list[i].columnname, condition->columnname)==0) {
                if (type!=condition->type) {
                    printf("Predicate %s ",output_info_list[i].columnname);
                    switch (condition->op) {
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
                    if (condition->type == INT) {
                        printf(" %d error\n", condition->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition->condition_varchar);
                    }
                    fclose(file);
                    fclose(filemeta);
                    free(output_info_list);
                    return FAIL;
                }
                else{
                    condition_column = i;
                }
            }
        }
        
    }
    
    if (condition_column == -1&&condition_sign == 1) {
        printf("Column %s doesn't exist\n",condition->columnname);
        free(output_info_list);
        fclose(file);
        fclose(filemeta);
        return FAIL;
    }
    
    fseek(file, metadata.datastartpage*PAGE_SIZE, SEEK_SET);
    page_header = (page_header_t *)pagebuffer;
    fread(pagebuffer, 1, PAGE_SIZE, file);

    
    var_offset = (unsigned short *)databuffer;
    var_offset++;
    fixed_data = (int *)((char *)databuffer+2*(1+metadata.varcharnum));
    
    for (i=0; i<metadata.columnnum; i++) {
        printf("%s",output_info_list[i].columnname);
        if (i!=metadata.columnnum-1) {
            printf("|");
        }
        else{
            printf("\n");
        }
    }
    
    idinpage = 0;
    for (i=0; i<metadata.tuplenum; i++,idinpage++) {
        if (idinpage>=page_header->tuplenum) {
            fread(pagebuffer, 1, PAGE_SIZE, file);
            idinpage = 0;
        }
        get_tuple(pagebuffer, databuffer, idinpage);
        
        if (condition_sign) {
            if (output_info_list[condition_column].type==INT) {
                if (int_compare(condition->op, fixed_data[output_info_list[condition_column].columnnum], condition->condition_int)==FALSE) {
                    continue;
                }
            }
            else{
                if (varchar_compare(condition->op, &databuffer[var_offset[output_info_list[condition_column].columnnum]+2], condition->condition_varchar)==FALSE) {
                    continue;
                }
            }
        }
        
        for (j=0; j<metadata.columnnum; j++) {
            if (output_info_list[j].type==INT) {
                printf("%d",fixed_data[output_info_list[j].columnnum]);
            }
            else{
                printf("%s",&databuffer[var_offset[output_info_list[j].columnnum]+2]);
            }
            if (j!=metadata.columnnum-1) {
                printf("|");
            }
            else{
                printf("\n");
            }
        }
    }
    
    free(output_info_list);
    fclose(file);
    fclose(filemeta);
    
    return SUCCESS;
}

int select_partial_1(char *table_name, char ** outputname, int outputnum, condition_t* condition)
{
    int len;
    char *table_file;
    table_data_t metadata;
    int i,j;
    int condition_sign = 0;
    int condition_column=-1;
    int column_int=-1;
    int column_var=-1;
    char type;
    int find;
    output_info_t * output_info_list;
    char namebuffer[128+1];
    char databuffer[PAGE_SIZE];
    char pagebuffer[PAGE_SIZE];
    page_header_t *page_header;
    unsigned short idinpage;
    unsigned short *var_offset;
    int *fixed_data;
    
    
    len = (int)strlen(table_name);
    table_file = (char *)malloc((len+10)*sizeof(char));
    strcpy(table_file, "db/");
    strcat(table_file, table_name);
    strcat(table_file, ".tbl");
    
    FILE* filemeta = fopen(table_file, "rb");
    if (filemeta==NULL) {
        printf("Table %s doesn't exist\n",table_name);
        free(table_file);
        return FAIL;
    }
    FILE* file = fopen(table_file, "rb");
    free(table_file);
    
    fread(&metadata, 1, sizeof(table_data_t), filemeta);
    
    output_info_list = malloc(sizeof(output_info_t)*outputnum);
    
    if (condition!=NULL) {
        condition_sign = 1;
    }
    
    find = 0;

    for (i = 0; i < outputnum; ++i)
    {
        output_info_list[i].find = 0;
    }
    
    for (i=0; i<metadata.columnnum; i++) {
        fread((void *)&type, 1, sizeof(char), filemeta);
        fread((void *)&len, 1, sizeof(int), filemeta);
        fread((void *)namebuffer, 1, len+1, filemeta);
        
        if (type == INT) {
            column_int++;
            find += output_info_search(output_info_list, outputname, outputnum, namebuffer, INT, column_int);
        }
        else{
            column_var++;
            find += output_info_search(output_info_list, outputname, outputnum, namebuffer, VARCHAR, column_var);
        }
        
        if (condition_sign && condition_column==-1) {
            
            if (strcmp(namebuffer, condition->columnname)==0) {
                if (type!=condition->type) {
                    printf("Predicate %s ",namebuffer);
                    switch (condition->op) {
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
                    if (condition->type == INT) {
                        printf(" %d error\n", condition->condition_int);
                    }
                    else{
                        printf(" '%s' error\n", condition->condition_varchar);
                    }
                    free(output_info_list);
                    fclose(file);
                    fclose(filemeta);
                    return FAIL;
                }
                else{
                    if (type == INT) {
                        condition_column = column_int;
                    }
                    else{
                        condition_column = column_var;
                    }
                }
            }
        }
        
    }
    
    if (find!=outputnum) {
        for (i=0; i<outputnum; i++) {
            if (output_info_list[i].find!=1) {
                printf("Column %s doesn't exist\n",outputname[i]);
                free(output_info_list);
                fclose(file);
                fclose(filemeta);
                return FAIL;
            }
        }
    }
    
    if (condition_column == -1&&condition_sign == 1) {
        printf("Column %s doesn't exist\n",condition->columnname);
        free(output_info_list);
        fclose(file);
        fclose(filemeta);
        return FAIL;
    }
    
    fseek(file, metadata.datastartpage*PAGE_SIZE, SEEK_SET);
    page_header = (page_header_t *)pagebuffer;
    fread(pagebuffer, 1, PAGE_SIZE, file);
    
    var_offset = (unsigned short *)databuffer;
    var_offset++;
    fixed_data = (int *)((char *)databuffer+2*(1+metadata.varcharnum));
    
    for (i=0; i<outputnum; i++) {
        printf("%s",output_info_list[i].columnname);
        if (i!=outputnum-1) {
            printf("|");
        }
        else{
            printf("\n");
        }
    }
    
    idinpage = 0;
    for (i=0; i<metadata.tuplenum; i++,idinpage++) {
        if (idinpage>=page_header->tuplenum) {
            fread(pagebuffer, 1, PAGE_SIZE, file);
            idinpage = 0;
        }
        
        get_tuple(pagebuffer, databuffer, idinpage);
        
        if (condition_sign) {
            if (condition->type==INT) {
                if (int_compare(condition->op, fixed_data[condition_column], condition->condition_int)==FALSE) {
                    continue;
                }
            }
            else{
                if (varchar_compare(condition->op, &databuffer[var_offset[condition_column]+2], condition->condition_varchar)==FALSE) {
                    continue;
                }
            }
        }
        
        for (j=0; j<outputnum; j++) {
            if (output_info_list[j].type==INT) {
                printf("%d",fixed_data[output_info_list[j].columnnum]);
            }
            else{
                printf("%s",&databuffer[var_offset[output_info_list[j].columnnum]+2]);
            }
            if (j!=outputnum-1) {
                printf("|");
            }
            else{
                printf("\n");
            }
        }
    }
    
    free(output_info_list);
    fclose(file);
    fclose(filemeta);
    
    return SUCCESS;
}
