#define MAX_LENGTH 256
#define ERROR_LENGTH 20

#define MAX_COLUMN 128
#define MAX_COLUMN_NAME 128

#define IGNORE_NUMBER 15
const char ignore[IGNORE_NUMBER] = {'\n','\f','\r',' ','(',')',';',',','>','<','=','!','.','*','\t'};

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
const char sql_like[WORD_LENGTH] = "like";
const char sql_not[WORD_LENGTH] = "not";

const char sql_count[WORD_LENGTH] = "count";
const char sql_sum[WORD_LENGTH] = "sum";
const char sql_avg[WORD_LENGTH] = "avg";
const char sql_min[WORD_LENGTH] = "min";
const char sql_max[WORD_LENGTH] = "max";

const char error_grammar[ERROR_LENGTH] = "Syntax error";

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