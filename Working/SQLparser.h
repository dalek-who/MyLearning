#define MAX_LENGTH 4096
#define ERROR_LENGTH 20

#define MAX_COLUMN 128
#define MAX_COLUMN_NAME 128

#define IGNORE_NUMBER 14
const char ignore[IGNORE_NUMBER] = {'\n','\f','\r',' ','(',')',';','-',',','>','<','=','!','.'};

#define WORD_LENGTH 8
const char sql_create[WORD_LENGTH] = "create";
const char sql_table[WORD_LENGTH] = "table";
const char sql_int[WORD_LENGTH] = "int";
const char sql_varchar[WORD_LENGTH] = "varchar";

const char sql_drop[WORD_LENGTH] = "drop";
const char sql_insert[WORD_LENGTH] = "insert";
const char sql_values[WORD_LENGTH] = "values";
const char sql_into[WORD_LENGTH] = "into";

const char sql_select[WORD_LENGTH] = "select";
const char sql_where[WORD_LENGTH] = "where";
const char sql_from[WORD_LENGTH] = "from";
const char sql_and[WORD_LENGTH] = "and";
const char sql_group[WORD_LENGTH] = "group";
const char sql_by[WORD_LENGTH] = "by";
const char sql_neq[WORD_LENGTH] = "!=";
const char sql_geq[WORD_LENGTH] = ">=";
const char sql_eq[WORD_LENGTH] = "=";
const char sql_leq[WORD_LENGTH] = "<=";
const char sql_l[WORD_LENGTH] = "<";
const char sql_g[WORD_LENGTH] = ">";
const char sql_like[WORD_LENGTH] = "like";
const char sql_not[WORD_LENGTH] = "not";
const char sql_all[WORD_LENGTH] = "*";

const char error_grammar[ERROR_LENGTH] = "Syntax error";

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

enum{
    INT = 0,
    VARCHAR = 1
};

typedef struct{
    char *columnname;
    char type;
    int op;
    int condition_int;
    char *condition_varchar;
}condition_t;

typedef struct{
    char *name;
    char type;
}column_type_t;

typedef struct{
    char type;
    int content_int;
    char *content_varchar;
}insert_t;

int find_critical(char *sql_sentence, int cursor, int flag);
int stop_signal(char *sql_sentence, int cursor);
int classifier(char *sql_sentence);
int parser_create(char *sql_sentence, int cursor);
int parser_drop(char *sql_sentence, int cursor);
int parser_select(char *sql_sentence, int cursor);
int parser_insert(char *sql_sentence, int cursor);
int ignore_blank(char *sql_sentence, int cursor);
int get_word(char *word, char *sql_sentence, int cursor);
void error_print(char *sql_sentence);
void trans_lower(char *sql_sentence);