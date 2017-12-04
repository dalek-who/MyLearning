#include "mospf_database.h"
#include "ip.h"
#include "mospf_nbr.h"
#include "rtable.h"

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <arpa/inet.h>

struct list_head mospf_db;

void init_mospf_db()
{
    init_list_head(&mospf_db);
}
struct queue_t{
    struct list_head list;
    u32 rid;
    u32 gw;
    iface_info_t *iface;
};
#define MAX_NODE_NUM 256
u32 hash(u32 ip){
    return (ip & 0x00000700) >> 8;
}
void update_rtable()
{
    clear_rtable();
    init_rtable();
    struct queue_t *head, *current, *prev;
    head = (struct queue_t *)malloc(sizeof(struct queue_t));
    init_list_head((struct list_head *)head);

    char *visited = (char *)malloc(MAX_NODE_NUM * sizeof(char));
    char *rid_visited = (char *)malloc(MAX_NODE_NUM * sizeof(char));
    memset(visited, 0, MAX_NODE_NUM * sizeof(char));
    memset(rid_visited, 0, MAX_NODE_NUM * sizeof(char));

    iface_info_t *iface;
    mospf_nbr_t *nbr;
    list_for_each_entry(iface, &instance->iface_list, list){
        list_for_each_entry(nbr, &iface->nbr_list, list){
            prev = (struct queue_t *)malloc(sizeof(struct queue_t));
            prev->rid = nbr->nbr_id;
            prev->gw = nbr->nbr_ip;
            prev->iface = iface;
            list_add_tail((struct list_head *)prev, (struct list_head *)head);
        }
        visited[hash(iface->mask & iface->ip)] = 1;
    }
    struct mospf_lsa *lsa;
    mospf_db_entry_t *db;
    current = (struct queue_t *)((struct list_head *)head)->next;
    while(current != head){
        list_for_each_entry(db, &mospf_db, list){
            if(db->rid == current->rid){
                lsa = db->array;
                for (int i = 0; i < db->nadv; i++, lsa++){
                    if (rid_visited[hash(lsa->rid)] == 0){
                        prev = (struct queue_t *)malloc(sizeof(struct queue_t));
                        prev->rid = lsa->rid;
                        prev->gw = current->gw;
                        prev->iface = current->iface;
                        list_add_tail((struct list_head *)prev, (struct list_head *)head);
                        rid_visited[hash(lsa->rid)] = 1;
                    }
                    if (visited[hash(lsa->subnet)] == 0){
                        rt_entry_t *rt_entry;
                        rt_entry = (rt_entry_t *)malloc(sizeof(rt_entry_t));
                        init_list_head(&rt_entry->list);
                        rt_entry->dest = lsa->subnet;
                        rt_entry->gw = current->gw;
                        rt_entry->mask = lsa->mask;
                        rt_entry->iface = current->iface;
                        rt_entry->flags = 0;
                        memcpy(rt_entry->if_name, current->iface->name, 16);
                        add_rt_entry(rt_entry);
                        visited[hash(lsa->subnet)] = 1;
                    }
                }
                break;
            }
        }
        prev = current;
        current = (struct queue_t *)((struct list_head *)current)->next;
        free(prev);
    }
    free(head);
    free(visited);
    free(rid_visited);
    print_rtable();
}