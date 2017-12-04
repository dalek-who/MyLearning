#define HASH_LENGTH 32
#define MUTI_LENGTH 256

typedef struct info{
	struct info *next;
	u32 prefix;
	u16 port;
	u8 length;
}info_t;
#define INFO_SIZE sizeof(info_t)
typedef struct hash_table{
	info_t *next;
}hash_table_t;
// #define HASH_SIZE sizeof(hash_table_t)
typedef struct muti_table{
	u8 count;
	u8 valid;
	info_t *info;
	struct muti_table **table;
}muti_table_t;
#define MUTI_SIZE sizeof(muti_table_t)

// #define HASH_TABLE_SIZE HASH_LENGTH * sizeof(hash_table_t *)
#define MUTI_TABLE_SIZE MUTI_LENGTH * sizeof(muti_table_t *)
void advanced();

u16 advanced_search(muti_table_t **muti_table, u32 ip, u8 length);
// info_t *insert_hash_table(hash_table_t **hash_table, u32 ip, u8 length, u16 port);
void insert_muti_table(muti_table_t **muti_table, u32 ip, u8 length, info_t *info, int shift);

void scanf_file_advanced(hash_table_t **hash_table, muti_table_t **muti_table);

info_t *init_info(u32 ip, u8 length, u16 port);

muti_table_t *init_muti_table(info_t *info, int max_length);
muti_table_t **create_muti_table();
void free_muti_table(muti_table_t **muti_table);

// hash_table_t **create_hash_table();
// void free_hash_table(hash_table_t **hash_table);
