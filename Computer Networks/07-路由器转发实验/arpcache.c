#include "arpcache.h"
#include "arp.h"
#include "ether.h"
#include "packet.h"
#include "icmp.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>

static arpcache_t arpcache;

void arpcache_init()
{
	bzero(&arpcache, sizeof(arpcache_t));

	init_list_head(&(arpcache.req_list));

	pthread_mutex_init(&arpcache.lock, NULL);

	pthread_create(&arpcache.thread, NULL, arpcache_sweep, NULL);
}

void arpcache_destroy()
{
	pthread_mutex_lock(&arpcache.lock);

	struct arp_req *req_entry = NULL, *req_q;
	list_for_each_entry_safe(req_entry, req_q, &(arpcache.req_list), list) {
		struct cached_pkt *pkt_entry = NULL, *pkt_q;
		list_for_each_entry_safe(pkt_entry, pkt_q, &(req_entry->cached_packets), list) {
			list_delete_entry(&(pkt_entry->list));
			free(pkt_entry->packet);
			free(pkt_entry);
		}

		list_delete_entry(&(req_entry->list));
		free(req_entry);
	}

	pthread_kill(arpcache.thread, SIGTERM);

	pthread_mutex_unlock(&arpcache.lock);
}

int arpcache_lookup(u32 ip4, u8 mac[ETH_ALEN])
{
	// fprintf(stderr, "TODO: lookup ip address in arp cache.\n");
	// return 0;
	int result = 0;
    pthread_mutex_lock(&arpcache.lock);

    for(int i = 0; i < MAX_ARP_SIZE; i++){
        if(ip4 == arpcache.entries[i].ip4 && arpcache.entries[i].valid){
            memcpy(mac, arpcache.entries[i].mac, ETH_ALEN);
            result = 1;
            break;
        }
    }
    pthread_mutex_unlock(&arpcache.lock);
    return result;
}

void arpcache_append_packet(iface_info_t *iface, u32 ip4, char *packet, int len)
{
	// fprintf(stderr, "TODO: append the ip address if lookup failed, and send arp request if necessary.\n");
    pthread_mutex_lock(&arpcache.lock);

    struct arp_req *req_entry;
    struct cached_pkt *pkt_entry;
    list_for_each_entry(req_entry, &arpcache.req_list, list){
        if (ip4 == req_entry->ip4){
            goto append_packet;
        }
    }
    req_entry = (struct arp_req *)malloc(sizeof(struct arp_req));
    init_list_head(&req_entry->list);
    list_add_tail(&req_entry->list, &arpcache.req_list);
    init_list_head(&req_entry->cached_packets);
    req_entry->iface = (iface_info_t *)malloc(sizeof(iface_info_t));
    memcpy(req_entry->iface, iface, sizeof(iface_info_t));
    req_entry->ip4 = ip4;
    req_entry->sent = 0;
    req_entry->retries = 0;
    arp_send_request(iface, ip4);

append_packet:
    pkt_entry = (struct cached_pkt *)malloc(sizeof(struct cached_pkt));
    init_list_head(&pkt_entry->list);
    list_add_tail(&pkt_entry->list, &req_entry->cached_packets);
    pkt_entry->packet = packet;
    // pkt_entry->packet = (char *)malloc(len);
    // memcpy(pkt_entry->packet, packet, len);
    pkt_entry->len = len;
    
    pthread_mutex_unlock(&arpcache.lock);
}

void arpcache_insert(u32 ip4, u8 mac[ETH_ALEN])
{
	// fprintf(stderr, "TODO: insert ip->mac entry, and send all the pending packets.\n");
	pthread_mutex_lock(&arpcache.lock);

	struct arp_req *req_entry, *req_q;
	list_for_each_entry_safe(req_entry, req_q, &(arpcache.req_list), list) {
		if(req_entry->ip4 == ip4){
			break;
		}
	}
	
	int index;
	for(index = 0; index < MAX_ARP_SIZE; index++){
		if(arpcache.entries[index].valid == 0){
			break;
		}
	}
	if(index == MAX_ARP_SIZE){
		index = rand() % MAX_ARP_SIZE;
	}

	memcpy(arpcache.entries[index].mac, mac, ETH_ALEN);
	arpcache.entries[index].ip4 = ip4;
	arpcache.entries[index].valid = 1;
	arpcache.entries[index].added = 0;

	pthread_mutex_unlock(&arpcache.lock);

	struct cached_pkt *pkt_entry, *pkt_q;
	list_for_each_entry_safe(pkt_entry, pkt_q, &(req_entry->cached_packets), list) {
		iface_send_packet_by_arp(req_entry->iface, ip4, pkt_entry->packet, pkt_entry->len);
		free(pkt_entry);
	}

	list_delete_entry(&(req_entry->list));
	free(req_entry->iface);
	free(req_entry);
}


void *arpcache_sweep(void *arg) 
{
	struct arp_req *req_entry , *req_q;
	struct cached_pkt *pkt_entry, *pkt_q;

	while (1) {
		sleep(1);
		// fprintf(stderr, "TODO: sweep arpcache periodically: remove old entries, resend arp requests .\n");
		pthread_mutex_lock(&arpcache.lock);

		for(int index = 0; index < MAX_ARP_SIZE; index++){
			if(++arpcache.entries[index].added > ARP_ENTRY_TIMEOUT){
				arpcache.entries[index].valid = 0;
			}
		}

		list_for_each_entry_safe(req_entry, req_q, &(arpcache.req_list), list) {
			if(req_entry->retries >= ARP_REQUEST_MAX_RETRIES){
				list_delete_entry(&(req_entry->list));

				pthread_mutex_unlock(&arpcache.lock);
				list_for_each_entry_safe(pkt_entry, pkt_q, &(req_entry->cached_packets), list){
					icmp_send_packet(pkt_entry->packet, pkt_entry->len, (u8)3, (u8)1);
					free(pkt_entry->packet);
					free(pkt_entry);
				}
				pthread_mutex_lock(&arpcache.lock);
				
				free(req_entry->iface);
				free(req_entry);
			}
			else{
				arp_send_request(req_entry->iface, req_entry->ip4);
				req_entry->sent = time(NULL);
				req_entry->retries += 1;
			}
			
		}

		pthread_mutex_unlock(&arpcache.lock);
	}
	return NULL;
}
