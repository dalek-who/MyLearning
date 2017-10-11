#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

#define TRUE 1
#define FALSE 0
#define SUCCESS 1
#define FAIL 0
#define PAGE_SIZE 4096
#define INT 0
#define VARCHAR 1
#define HASH_TABLE_SIZE 10

enum{
    op_l,
    op_leq,
    op_g,
    op_geq,
    op_eq,
    op_neq,
    op_like,
    op_nlike
};

typedef struct{
    unsigned int tuplenum;
    unsigned int datapage;
    unsigned int datastartpage;
    unsigned short columnnum;
    unsigned short intnum;
    unsigned short varcharnum;
}table_data_t;

typedef struct{
    char type;
    short columnnum;
    char columnname[128+1];
    int find;
}output_info_t;

typedef struct{
    short tuplenum;
    short start;
    short end;
    short remain;
}page_header_t;

typedef struct{
    char *columnname;
    char type;
    int op;
    int condition_int;
    char *condition_varchar;
}condition_t;

typedef struct{
    char *name;
    int type;
}column_type_t;

typedef struct{
    char type;
    int content_int;
    char *content_varchar;
}insert_t;

typedef struct{
    char *columnname1;
    char table1;
    char *columnname2;
    char table2;
}join_condition_t;

typedef struct join_bucket_tuple_t{
    char *tuple;
    struct join_bucket_tuple_t *next;
}join_bucket_tuple_t;

typedef struct join_hash_bucket_t{
    struct join_hash_bucket_t *next;
    struct join_bucket_tuple_t *first;
    char *hash_varchar;
    int hash_int;
}join_hash_bucket_t;

typedef struct group_hash_bucket{
    struct group_hash_bucket *next;
    int *result;
    int *resultnum;
    char *hash_varchar;
    int hash_int;
}group_hash_bucket_t;

int create_table(char *table_name, column_type_t* column, int columnnum);
int drop_table(char *table_name);
int insert_table(char *table_name, insert_t *insert, int columnnum);
int select_all_1(char *table_name, condition_t * condition);
int select_partial_1(char *table_name, char ** outputname, int outputnum, condition_t* condition);

void int_swap(int* a, int* b);
void char_swap(char *a, char *b);
unsigned int int_hash(int a);
unsigned int varchar_hash(char *key, int len);
void free_join_hash(join_hash_bucket_t hash_table[HASH_TABLE_SIZE]);
int join_hash(join_hash_bucket_t hash_table[HASH_TABLE_SIZE], condition_t *condition, int condition_column, FILE *file, table_data_t *metadata,int join_column, char join_type);
int select_all_2(char *table_name_1, char *table_name_2, condition_t *condition_1, char contable_1, condition_t *condition_2, char contable_2, join_condition_t *join_condition);
int select_partial_2(char *table_name_1, char *table_name_2, char **outputname, char *outputtable, int outputnum, condition_t *condition_1, char contable_1, condition_t *condition_2, char contable_2, join_condition_t *join_condition);
int output_info_search_join(output_info_t *list, char **outputname, int outputnum, char *outputtable, char *columnname, char type, int columnnum, char nowtable);

void free_group_hash(group_hash_bucket_t group_hash_table[HASH_TABLE_SIZE]);
int select_groupby(char *table_name, char **columnname, int columnnum, char *type, condition_t *condition, char *group, char group_table);
int select_groupby_join(char *tablename[2], char **columnname, int columnnum, char *type, char *columntable, condition_t *condition[3], char conditiontable[3], join_condition_t *join_condition, char *group, char group_table);

int add_tuple(char *page_buffer, char *tuple_buffer, unsigned short len);
unsigned short get_tuple(char *page_buffer, char *tuple_buffer, unsigned short id);
int int_compare(int op, int data, int condition);
int varchar_compare(int op, char *data, char *condition);
int output_info_search(output_info_t *list, char **outputname, int outputnum, char *columnname, char type, int columnnum);