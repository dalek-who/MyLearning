#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "normal.h"

void normal(){
	node_t *root_node;
	root_node = init_node_t(0, 0, 0);

	scanf_file(root_node);

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
		result = normal_search(root_node, ip);
		// if(result != port){
		// 	printf("false %u %d %d\n", ip, result, port);
		// }
		row[0] = '\0';
	}
	tFinish = clock();
	totaltime = (tFinish - tStart - totaltime) * 1000 / number;

	fclose(fp);
	free_tree(root_node);
}

u16 normal_search(node_t *root_node, u32 ip){
	node_t *current_node;
	u8 shift, length, port;

	length = 0;
	current_node = root_node;
	while(length < 32){
		length++;
		shift = 32 - length;
		if(ip >> shift & 1){
			if(current_node->right == NULL){
				break;
			}else{
				current_node = current_node->right;
			}
		}else{
			if(current_node->left == NULL){
				break;
			}else{
				current_node = current_node->left;
			}
		}
		if(current_node->type){
			port = current_node->port;
		}
	}

	return port;
}

void scanf_file(node_t *root_node){
	FILE *fp;
	if((fp = fopen("forwarding-table.txt", "rt")) == NULL){
		printf("File Open Error\n");
		return;
	}

	char row[32];
	u32 ip;
	u16 port;
	u8 length;
	while(!feof(fp)){
		fgets(row, 32, fp);
		if(row[0] == '\0'){
			return;
		}
		scanf_row(row, &ip, &length, &port);
		insert_node_t(root_node, ip, length, port);
		row[0] = '\0';
	}

	fclose(fp);
}
node_t *init_node_t(u32 prefix, u8 length, u16 port){
	node_t *node;
	if((node = (node_t *)malloc(NODE_SIZE)) == NULL){
		printf("Not Enough Memory!/n");
		return NULL;
	};
	node->left = NULL;
	node->right = NULL;
	node->prefix = prefix;
	node->length = length;
	node->port = port;
	node->type = 0;

	space += NODE_SIZE;
	return node;
}

void insert_node_t(node_t *root_node, u32 ip, u8 length, u16 port){
	if(length > 32){
		printf("prefix_length %d %d\n", length, ip);
		return;
	}
	node_t *current_node;
	current_node = root_node;
	u8 shift, now_length = 0;
	u32 prefix;
	//create tree
	while(now_length < length){
		now_length++;
		shift = 32 - now_length;
		prefix = ip >> shift << shift;
		if(ip >> shift & 1){
			if(current_node->right == NULL){				
				current_node->right = init_node_t(prefix, now_length, port);
			}
			current_node = current_node->right;
		}else{
			if(current_node->left == NULL){
				current_node->left = init_node_t(prefix, now_length, port);
			}
			current_node = current_node->left;
		}
	}
	//update info
	current_node->port = port;
	current_node->type = 1;
}

void free_tree(node_t *root_node){
	if(root_node == NULL){
		return;
	}
	free_tree(root_node->left);
	free_tree(root_node->right);
	free(root_node);
}

void scanf_ip(char *src, u32 *ip){
	*ip = 0 + atoi(strtok(src, ". "));
	*ip = *ip << 8;

	*ip = *ip + atoi(strtok(NULL, ". "));
	*ip = *ip << 8;

	*ip = *ip + atoi(strtok(NULL, ". "));
	*ip = *ip << 8;

	*ip = *ip + atoi(strtok(NULL, ". "));
}
void scanf_prefix_length(char *src, u8 *length){
	*length = atoi(strtok(NULL, ". "));
}
void scanf_port(char *src, u16 *port){
	*port = atoi(strtok(NULL, ". "));
}
void scanf_row(char *src, u32 *ip, u8 *length, u16 *port){
	scanf_ip(src, ip);
	scanf_prefix_length(src, length);
	scanf_port(src, port);
}