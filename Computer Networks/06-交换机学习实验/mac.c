#include "mac.h"
#include "headers.h"
#include "log.h"

mac_port_map_t mac_port_map;

void init_mac_hash_table()
{
	bzero(&mac_port_map, sizeof(mac_port_map_t));

	pthread_mutexattr_init(&mac_port_map.attr);
	pthread_mutexattr_settype(&mac_port_map.attr, PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&mac_port_map.lock, &mac_port_map.attr);

	pthread_create(&mac_port_map.tid, NULL, sweeping_mac_port_thread, NULL);
}

void destory_mac_hash_table()
{
	pthread_mutex_lock(&mac_port_map.lock);
	mac_port_entry_t *tmp, *entry;
	for (int i = 0; i < HASH_8BITS; i++) {
		entry = mac_port_map.hash_table[i];
		if (!entry) 
			continue;

		tmp = entry->next;
		while (tmp) {
			entry->next = tmp->next;
			free(tmp);
			tmp = entry->next;
		}
		free(entry);
	}
	pthread_mutex_unlock(&mac_port_map.lock);
}

iface_info_t *lookup_port(u8 mac[ETH_ALEN])
{
	// TODO: implement the lookup process here
	pthread_mutex_lock(&mac_port_map.lock);

	iface_info_t *iface = NULL;
	mac_port_entry_t *entry;

	for(entry = mac_port_map.hash_table[hash8(mac, ETH_ALEN)]; entry != NULL; entry = entry->next){
		if (memcmp(mac, entry->mac, ETH_ALEN) == 0){
			iface = entry->iface;
			entry->visited = 0;
			break;
		}
	}

	pthread_mutex_unlock(&mac_port_map.lock);

	return iface;
	// fprintf(stdout, "TODO: implement the lookup process here.\n");
	// fflush(stdout);
	// return NULL;
}

void insert_mac_port(u8 mac[ETH_ALEN], iface_info_t *iface)
{
	// TODO: implement the insertion process here
	pthread_mutex_lock(&mac_port_map.lock);

	mac_port_entry_t *entry;
	entry = mac_port_map.hash_table[hash8(mac, ETH_ALEN)];

	if(entry == NULL){
		entry = (mac_port_entry_t *)malloc(sizeof(mac_port_entry_t));
		memcpy(entry->mac, mac, ETH_ALEN);
		entry->iface = iface;
		entry->visited = 0;
		entry->next = NULL;
		mac_port_map.hash_table[hash8(mac, ETH_ALEN)] = entry;
	}
	else{
		for( ; entry != NULL; entry = entry->next){
			if(memcmp(mac, entry->mac, ETH_ALEN) == 0){
				break;
			}

			if(entry->next == NULL){
				entry->next = (mac_port_entry_t *)malloc(sizeof(mac_port_entry_t));
				entry = entry->next;
				memcpy(entry->mac, mac, ETH_ALEN);
				entry->iface = iface;
				entry->visited = 0;
				entry->next = NULL;
				break;
			}
		}
	}

	pthread_mutex_unlock(&mac_port_map.lock);
	// fprintf(stdout, "TODO: implement the insertion process here.\n");
	// fflush(stdout);
}

void dump_mac_port_table()
{
	mac_port_entry_t *entry = NULL;
	time_t now = time(NULL);

	fprintf(stdout, "dumping the mac_port table:\n");
	pthread_mutex_lock(&mac_port_map.lock);
	for (int i = 0; i < HASH_8BITS; i++) {
		entry = mac_port_map.hash_table[i];
		while (entry) {
			fprintf(stdout, ETHER_STRING " -> %s, %d\n", ETHER_FMT(entry->mac), \
					entry->iface->name, (int)(now - entry->visited));

			entry = entry->next;
		}
	}

	pthread_mutex_unlock(&mac_port_map.lock);
}

int sweep_aged_mac_port_entry()
{
	// TODO: implement the sweeping process here
	pthread_mutex_lock(&mac_port_map.lock);

	mac_port_entry_t *entry, *next_entry;
	int number = 0;

	for(int i = 0; i < HASH_8BITS; i++){
		entry = mac_port_map.hash_table[i];

		while(entry != NULL && entry->visited >= 30){
			next_entry = entry->next;
			free(entry);
			entry = next_entry;
		}

		mac_port_map.hash_table[i] = entry;

		if(entry != NULL){
			entry->visited++;
			next_entry = entry->next;

			while(next_entry != NULL){
				if(next_entry->visited >= 30){
					entry->next = next_entry->next;
					free(next_entry);
					next_entry = entry->next;
				}
				else{
					entry = next_entry;
					entry->visited++;
					next_entry = entry->next;
				}
			}
		}
	}

	pthread_mutex_unlock(&mac_port_map.lock);

	return number;
	// fprintf(stdout, "TODO: implement the sweeping process here.\n");
	// fflush(stdout);

	// return 0;
}

void *sweeping_mac_port_thread(void *nil)
{
	while (1) {
		sleep(1);
		int n = sweep_aged_mac_port_entry();

		if (n > 0)
			log(DEBUG, "%d aged entries in mac_port table are removed.", n);
	}

	return NULL;
}
