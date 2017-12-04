#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "normal.h"
#include "advanced.h"

void advanced(){
	hash_table_t **hash_table;
	// hash_table = create_hash_table();
	muti_table_t **muti_table;
	muti_table = create_muti_table();

	scanf_file_advanced(hash_table, muti_table);
	FILE *fp;
	if((fp = fopen("forwarding-table.txt", "rt")) == NULL){
		printf("File Open Error\n");
		return;
	}
	char row[32];
	u32 ip;
	u16 port, result;
	u8 length;
	int number = 0;
	clock_t tStart, tFinish;
    tStart = clock();
	while(!feof(fp)){
		number++;
		fgets(row, 32, fp);
		if(row[0] == '\0'){
			break;
		}
		// printf("%s\n", row);
		scanf_row(row, &ip, &length, &port);
		result = advanced_search(muti_table, ip, length);
		// if(result != port){
		// 	printf("false %u %d %d\n", ip, result, port);
		// }
		row[0] = '\0';
	}
	tFinish = clock();
	totaltime = (tFinish - tStart - totaltime) * 1000 / number;

	free_muti_table(muti_table);
	// free_hash_table(hash_table);
}
u16 advanced_search(muti_table_t **muti_table, u32 ip, u8 length){
	u8 shift = 24;
	u8 dest;
	u8 port = 0;
	muti_table_t *current_muti;
	while(shift >= 0){
		dest = ip >> shift;
		current_muti = muti_table[dest];
		
		if(current_muti == NULL){
			break;
		}
		// printf("%d %d %d\n", dest, current_muti->valid, current_muti->info->port);
		if(current_muti->valid){
			port = current_muti->info->port;
		}
		// if(length == current_muti->info->length && ip == current_muti->info->prefix){
		// 	break;
		// }
		if(current_muti->table == NULL){
			break;
		}
		muti_table = current_muti->table;
		shift -= 8;
	}
	return port;
}
void insert_muti_table(muti_table_t **muti_table, u32 ip, u8 length, info_t *info, int shift){
	if(info == NULL){
		return;
	}
	u8 dest = ip >> shift;
	muti_table_t *current_muti;
	current_muti = init_muti_table(info, 32 - shift);

	// printf("dest %d %d\n", dest, current_muti->valid);
	int count = 1;
	if(length + shift <= 32){
		count = 1 << ((32 - length) % 8); 
	}
	for(int i = dest; i < dest + count; i++){
		if(muti_table[i] == NULL){
			muti_table[i] = current_muti;
			current_muti->count++;
			// printf("replace %d %d %d\n", shift, i, info->port);
		}else if(current_muti->valid > muti_table[i]->valid){
			muti_table[i]->count--;
			if(muti_table[i]->count == 0){
				current_muti->table = muti_table[i]->table;
				free(muti_table[i]);
				space -= sizeof(muti_table_t *);
			}
			muti_table[i] = current_muti;
			current_muti->count++;
			// printf("replace %d %d %d\n", shift, i, info->port);
		}
	}
	if(length + shift > 32 && shift){
		if(muti_table[dest]->count > 1){
			muti_table[dest]->count--;
			current_muti->valid = muti_table[dest]->valid;
			current_muti->info = muti_table[dest]->info;
			muti_table[dest] = current_muti;
			current_muti->count++;
		}
		if(muti_table[dest]->table == NULL){
			muti_table[dest]->table = create_muti_table();
		}
		insert_muti_table(muti_table[dest]->table, ip, length, info, shift - 8);
	}
	if(current_muti->count == 0){
		free(current_muti);
		space -= sizeof(muti_table_t *);
	}
}
void scanf_file_advanced(hash_table_t **hash_table, muti_table_t **muti_table){
	FILE *fp;
	if((fp = fopen("forwarding-table.txt", "rt")) == NULL){
		printf("File Open Error\n");
		return;
	}

	char row[32];
	u32 ip;
	u16 port;
	u8 length;
	info_t *info;
	int number;
	while(!feof(fp)){
		fgets(row, 32, fp);
		if(row[0] == '\0'){
			return;
		}
		scanf_row(row, &ip, &length, &port);
		// info = insert_hash_table(hash_table, ip, length, port);
		info = init_info(ip, length, port);
		insert_muti_table(muti_table, ip, length, info, 24);
		row[0] = '\0';
	}

	fclose(fp);
}
info_t *init_info(u32 ip, u8 length, u16 port){
	info_t *info;
	info = (info_t *)malloc(INFO_SIZE);
	space += INFO_SIZE;

	info->prefix = ip;
	info->length = length;
	info->port = port;
	info->next = NULL;

	return info;
}
muti_table_t *init_muti_table(info_t *info, int max_length){
	muti_table_t *muti_table;
	muti_table = (muti_table_t *)malloc(MUTI_SIZE);
	space += MUTI_SIZE;

	muti_table->table = NULL;
	muti_table->info = info;
	muti_table->count = 0;
	muti_table->valid = (info->length <= max_length) ? info->length:0;

	return muti_table;
}
muti_table_t **create_muti_table(){
	muti_table_t **muti_table;
	muti_table = (muti_table_t **)malloc(MUTI_TABLE_SIZE);
	space += MUTI_TABLE_SIZE;

	for(int i = 0; i < MUTI_LENGTH; i++){
		muti_table[i] = NULL;
	}

	return muti_table;
}
void free_muti_table(muti_table_t **muti_table){
	if(muti_table == NULL){
		return;
	}
	for(int i = 0; i < MUTI_LENGTH; i++){
		if(muti_table[i] != NULL){
			muti_table[i]->count--;
			if(muti_table[i]->count == 0){
				free_muti_table(muti_table[i]->table);
				free(muti_table[i]);
			}else{
				muti_table[i] = NULL;
			}
		}
	}

	free(muti_table);
}
// info_t *insert_hash_table(hash_table_t **hash_table, u32 ip, u8 length, u16 port){
// 	if(length > 32){
// 		printf("prefix_length %d %d\n", length, ip);
// 		return NULL;
// 	}
// 	info_t *info, *last;
// 	hash_table_t *current_hash;
// 	current_hash = hash_table[length - 1];

// 	info = current_hash->next;
// 	// while(info != NULL){
// 	// 	if(info->prefix == ip){
// 	// 		return NULL;
// 	// 	}
// 	// 	last = info;
// 	// 	info = info->next;
// 	// }
// 	info = init_info(ip, length, port);
// 	last->next = info;
// 	return info;
// }
// hash_table_t **create_hash_table(){
// 	hash_table_t **hash_table;
// 	hash_table = (hash_table_t **)malloc(HASH_TABLE_SIZE);
// 	space += HASH_TABLE_SIZE;

// 	for(int i = 0; i < HASH_LENGTH; i++){
// 		hash_table[i] = (hash_table_t *)malloc(HASH_SIZE);
// 		space += HASH_SIZE;
// 		hash_table[i]->next = init_info(0, 0, 0);
// 	}

// 	return hash_table;
// }
// void free_hash_table(hash_table_t **hash_table){
// 	info_t *info, *next;
// 	for(int i = 0; i < HASH_LENGTH; i++){
// 		if(hash_table[i] != NULL){
// 			info = hash_table[i]->next;
// 			while(info != NULL){
// 				next = info->next;
// 				free(info);
// 				info = next;
// 			}
// 			free(hash_table[i]);
// 		}
// 	}
// 	free(hash_table);
// }