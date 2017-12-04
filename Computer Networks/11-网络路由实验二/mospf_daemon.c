#include "mospf_daemon.h"
#include "mospf_proto.h"
#include "mospf_nbr.h"
#include "mospf_database.h"

#include "ip.h"
#include "packet.h"

#include "list.h"
#include "log.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

extern ustack_t *instance;

#define HDR_OFFSET ETHER_HDR_SIZE + IP_BASE_HDR_SIZE
#define LSU_OFFSET ETHER_HDR_SIZE + IP_BASE_HDR_SIZE + MOSPF_HDR_SIZE
#define LSU_PACKET_SIZE ETHER_HDR_SIZE + IP_BASE_HDR_SIZE + MOSPF_HDR_SIZE + MOSPF_LSU_SIZE

pthread_mutex_t mospf_lock;

void mospf_init()
{
    pthread_mutex_init(&mospf_lock, NULL);

    instance->area_id = 0;
    // get the ip address of the first interface
    iface_info_t *iface = list_entry(instance->iface_list.next, iface_info_t, list);
    instance->router_id = iface->ip;
    instance->sequence_num = 0;
    instance->lsuint = MOSPF_DEFAULT_LSUINT;

    iface = NULL;
    list_for_each_entry(iface, &instance->iface_list, list)
    {
        iface->helloint = MOSPF_DEFAULT_HELLOINT;
        init_list_head(&iface->nbr_list);
    }

    init_mospf_db();
}

void *sending_mospf_hello_thread(void *param);
void *sending_mospf_lsu_thread(void *param);
void *checking_nbr_thread(void *param);
void *checking_database_thread(void *param);

void mospf_run()
{
    pthread_t hello, lsu, nbr, sweep;
    pthread_create(&hello, NULL, sending_mospf_hello_thread, NULL);
    pthread_create(&lsu, NULL, sending_mospf_lsu_thread, NULL);
    pthread_create(&nbr, NULL, checking_nbr_thread, NULL);
    pthread_create(&sweep, NULL, checking_database_thread, NULL);
}

void *checking_database_thread(void *param){
	mospf_db_entry_t* db, *db_q;

	while(1){
		sleep(1);
		pthread_mutex_lock(&mospf_lock);

		list_for_each_entry_safe(db, db_q, &mospf_db, list){
			if(--db->alive == 0){
				list_delete_entry(&db->list);
				free(db->array);
				free(db);
                update_rtable();
			}
		}

		pthread_mutex_unlock(&mospf_lock);
	}
	return NULL;
}

void broadcast_mospf_lsu()
{
 //    struct mospf_lsa *current;
 //    mospf_db_entry_t *db;
 //    fprintf(stdout, "------------\n");
	// list_for_each_entry(db, &mospf_db, list){
	// 	fprintf(stdout, ""IP_FMT" %u %u %u\n", HOST_IP_FMT_STR(db->rid), db->seq, db->nadv, db->alive);
	// 	for(int i = 0; i < db->nadv; i++){
	// 		current = db->array + i;
	// 		fprintf(stdout, "\t  ");
	// 		fprintf(stdout, IP_FMT, HOST_IP_FMT_STR(current->subnet));
	// 		fprintf(stdout, " ");
	// 		fprintf(stdout, IP_FMT, HOST_IP_FMT_STR(current->mask));
	// 		fprintf(stdout, " ");
	// 		fprintf(stdout, IP_FMT, HOST_IP_FMT_STR(current->rid));
	// 		fprintf(stdout, "\n");
	// 	}
	// }
    struct mospf_lsa lsa[16];
    int lsa_size = 16 * MOSPF_LSA_SIZE;
    int number = 0;
    memset(lsa, 0, 16 * MOSPF_LSA_SIZE);
    iface_info_t *iface;
    mospf_nbr_t *nbr;
    list_for_each_entry(iface, &(instance->iface_list), list){
        if(list_empty(&(iface->nbr_list))){
            lsa[number].subnet = htonl(iface->ip);
            lsa[number].mask = htonl(iface->mask);
            lsa[number].rid = htonl(0);
            number++;
        }else{
            list_for_each_entry(nbr, &(iface->nbr_list), list){
                lsa[number].subnet = htonl(nbr->nbr_ip);
                lsa[number].mask = htonl(nbr->nbr_mask);
                lsa[number].rid = htonl(nbr->nbr_id);
                number++;
            }
        }   
    }
    char *packet;
    struct ether_header *eh;
    struct iphdr *ip;
    struct mospf_hdr *hdr;
    struct mospf_lsu *lsu;

    lsa_size = number * MOSPF_LSA_SIZE;
    int length = LSU_PACKET_SIZE + lsa_size;
    list_for_each_entry(iface, &(instance->iface_list), list){
        list_for_each_entry(nbr, &(iface->nbr_list), list){
            packet = (char *)malloc(length);
            eh = (struct ether_header *)packet;
            ip = packet_to_ip_hdr(packet);
            hdr = (struct mospf_hdr *)(packet + HDR_OFFSET);
            lsu = (struct mospf_lsu *)(packet + LSU_OFFSET);
            
            eh->ether_type = htons(ETH_P_IP);
            mospf_init_lsu(lsu, number);
            memcpy((char *)(packet + LSU_PACKET_SIZE), lsa, lsa_size);
            mospf_init_hdr(hdr, MOSPF_TYPE_LSU, length - ETHER_HDR_SIZE - IP_BASE_HDR_SIZE, instance->router_id, instance->area_id);
            hdr->checksum = mospf_checksum(hdr);
            ip_init_hdr(ip, iface->ip, nbr->nbr_ip, length - ETHER_HDR_SIZE, IPPROTO_MOSPF);
            ip_send_packet(packet, length);
        }
    }
    instance->sequence_num++;
}

void *sending_mospf_hello_thread(void *param)
{
	// fprintf(stdout, "TODO: send mOSPF Hello message periodically.\n");
    int length = LSU_OFFSET + MOSPF_HELLO_SIZE;
    char *packet;
    struct ether_header *eh;
    struct iphdr *ip;
    struct mospf_hdr *hdr;
    struct mospf_hello *hello;
    iface_info_t *iface;

    while (1)
    {
        sleep(MOSPF_DEFAULT_HELLOINT);
        pthread_mutex_lock(&mospf_lock);
        list_for_each_entry(iface, &(instance->iface_list), list){
            packet = (char *)malloc(length);
            eh = (struct ether_header *)packet;
            ip = packet_to_ip_hdr(packet);
            hdr = (struct mospf_hdr *)(packet + HDR_OFFSET);
            hello = (struct mospf_hello *)(packet + LSU_OFFSET);

            memcpy(eh->ether_shost, iface->mac, ETH_ALEN);
            memcpy(eh->ether_dhost, "01005E000005", ETH_ALEN);
            eh->ether_type = htons(ETH_P_IP);

            mospf_init_hdr(hdr, MOSPF_TYPE_HELLO, MOSPF_HDR_SIZE + MOSPF_HELLO_SIZE, instance->router_id, instance->area_id);
            hdr->checksum = mospf_checksum(hdr);

            mospf_init_hello(hello, iface->mask);
            ip_init_hdr(ip, iface->ip, MOSPF_ALLSPFRouters, length - ETHER_HDR_SIZE, IPPROTO_MOSPF);
            iface_send_packet(iface, packet, length);
        }
        pthread_mutex_unlock(&mospf_lock);
    }
    return NULL;
}

void *checking_nbr_thread(void *param)
{
	// fprintf(stdout, "TODO: neighbor list timeout operation.\n");
    iface_info_t *iface;
    mospf_nbr_t *nbr, *nbr_q;
    mospf_db_entry_t *db;
    while (1)
    {
        sleep(1);
        pthread_mutex_lock(&mospf_lock);

        list_for_each_entry(iface, &(instance->iface_list), list){
            list_for_each_entry_safe(nbr, nbr_q, &(iface->nbr_list), list){
                if(--nbr->alive == 0){
                    list_delete_entry(&(nbr->list));
                    iface->num_nbr -= 1;
                    broadcast_mospf_lsu();
                    list_for_each_entry(db, &mospf_db, list){
                        if (db->rid == nbr->nbr_id){
                            free(db->array);
                            list_delete_entry(&db->list);
                            free(db);
                            break;
                        }
                    }
                    free(nbr);
                }
            } 
        }
        pthread_mutex_unlock(&mospf_lock);
    }

    return NULL;
}

void handle_mospf_hello(iface_info_t *iface, const char *packet, int len)
{
    // fprintf(stdout, "TODO: handle mOSPF Hello message.\n");
    struct iphdr *ip = packet_to_ip_hdr(packet);
    struct mospf_hdr *hdr = (struct mospf_hdr *)(packet + HDR_OFFSET);
    struct mospf_hello *hll = (struct mospf_hello *)(packet + LSU_OFFSET);
    mospf_nbr_t *nbr;

    u32 rid = ntohl(hdr->rid);
    list_for_each_entry(nbr, &(iface->nbr_list), list){
        if (nbr->nbr_id == rid){
            goto handle;
        }
    }
    nbr = (mospf_nbr_t *)malloc(sizeof(mospf_nbr_t));
    init_list_head(&nbr->list);
    list_add_tail(&(nbr->list), &(iface->nbr_list));
    iface->num_nbr++;

handle:{
	    nbr->nbr_ip = ntohl(ip->saddr);
	    nbr->nbr_id = ntohl(hdr->rid);
	    nbr->nbr_mask = ntohl(hll->mask);
	    nbr->alive = MOSPF_DEFAULT_HELLOINT * 3;

	    pthread_mutex_lock(&mospf_lock);
	    broadcast_mospf_lsu();
	    pthread_mutex_unlock(&mospf_lock);
	}
}

void *sending_mospf_lsu_thread(void *param)
{
	// fprintf(stdout, "TODO: send mOSPF LSU message periodically.\n");
    while (1){
        sleep(MOSPF_DEFAULT_LSUINT);
        pthread_mutex_lock(&mospf_lock);
        broadcast_mospf_lsu();
        pthread_mutex_unlock(&mospf_lock);
    }
    return NULL;
}

void handle_mospf_lsu(iface_info_t *iface, char *packet, int len)
{
    // fprintf(stdout, "TODO: handle mOSPF LSU message.\n");
    struct iphdr *ip = packet_to_ip_hdr(packet);
    struct mospf_hdr *hdr = (struct mospf_hdr *)(packet + HDR_OFFSET);
    struct mospf_lsu *lsu = (struct mospf_lsu *)(packet + LSU_OFFSET);


    int nadv = ntohl(lsu->nadv);
    u32 rid = ntohl(hdr->rid);
    u16 seq = ntohs(lsu->seq);
    mospf_db_entry_t *db;

    if(rid == instance->router_id){
    	return;
    }

    list_for_each_entry(db, &mospf_db, list){
        if (db->rid == rid){
            if(seq > db->seq){
                free(db->array);
                goto handle;
            }else{
                return;
            }

        }
    }

    db = (mospf_db_entry_t *)malloc(sizeof(mospf_db_entry_t));
    db->rid = ntohl(hdr->rid);
    init_list_head(&db->list);
    list_add_tail(&(db->list), &mospf_db);

handle:{
		db->alive = MOSPF_DATABASE_TIMEOUT;
		db->seq = ntohs(lsu->seq);
		db->nadv = nadv;
		db->array = (struct mospf_lsa *)malloc(nadv * MOSPF_LSA_SIZE);
	    struct mospf_lsa *current, *aim;
	    for (int i = 0; i < nadv; i++){
	        current = db->array + i;
	        aim = (struct mospf_lsa *)((char *)lsu + MOSPF_LSU_SIZE) + i;
	        current->subnet = ntohl(aim->subnet);
	        current->mask = ntohl(aim->mask);
	        current->rid = ntohl(aim->rid);
	    }
        update_rtable();
	    char *pkt_new;
	    mospf_nbr_t *nbr;
	    iface_info_t *ifaces;
	    if(--lsu->ttl > 0){
	        list_for_each_entry(ifaces, &(instance->iface_list), list)
	        {
	            if(ifaces->index != iface->index){
		            list_for_each_entry(nbr, &(ifaces->nbr_list), list)
		            {
		                pkt_new = (char *)malloc(len);
		                ip = packet_to_ip_hdr(pkt_new);
		                hdr = (struct mospf_hdr *)(pkt_new + HDR_OFFSET);

		                memcpy(pkt_new, packet, len);
		                
		                hdr->checksum = mospf_checksum(hdr);
		                ip_init_hdr(ip, ifaces->ip, nbr->nbr_ip, len - IP_BASE_HDR_SIZE + MOSPF_HDR_SIZE + MOSPF_LSA_SIZE + nadv * MOSPF_LSU_SIZE, IPPROTO_MOSPF);
		                ip_send_packet(pkt_new, len);
		            }
				}
	        }
	    }
	}
}

void handle_mospf_packet(iface_info_t *iface, char *packet, int len)
{
    struct iphdr *ip = (struct iphdr *)(packet + ETHER_HDR_SIZE);
    struct mospf_hdr *mospf = (struct mospf_hdr *)((char *)ip + IP_HDR_SIZE(ip));

    if (mospf->version != MOSPF_VERSION)
    {
        log(ERROR, "received mospf packet with incorrect version (%d)", mospf->version);
        return;
    }
    if (mospf->checksum != mospf_checksum(mospf))
    {
        log(ERROR, " received mospf packet with incorrect checksum");
        return;
    }
    if (ntohl(mospf->aid) != instance->area_id)
    {
        log(ERROR, "received mospf packet with incorrect area id");
        return;
    }

    // log(DEBUG, "received mospf packet, type: %d", mospf->type);

    switch (mospf->type)
    {
    case MOSPF_TYPE_HELLO:
        handle_mospf_hello(iface, packet, len);
        break;
    case MOSPF_TYPE_LSU:
        handle_mospf_lsu(iface, packet, len);
        break;
    default:
        log(ERROR, "received mospf packet with unknown type (%d).", mospf->type);
        break;
    }
}
