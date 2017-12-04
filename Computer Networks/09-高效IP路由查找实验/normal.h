#define MAX_LENGTH 32

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;

typedef struct node{
	struct node *left, *right;
	u32 prefix;
	u16 port;
	u8 length;
	u8 type;
}node_t;
#define NODE_SIZE sizeof(node_t)

void normal();

u16 normal_search(node_t *root_node, u32 ip);
void scanf_file(node_t *root_node);
node_t *init_node_t(u32 prefix, u8 length, u16 port);
void insert_node_t(node_t *root_node, u32 ip, u8 length, u16 port);
void free_tree(node_t *root_node);

void scanf_ip(char *src, u32 *ip);
void scanf_prefix_length(char *src, u8 *length);
void scanf_port(char *src, u16 *port);
void scanf_row(char *src, u32 *ip, u8 *length, u16 *port);

long int totaltime;
int space;