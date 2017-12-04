#include "ip.h"
#include "icmp.h"
#include "packet.h"
#include "arpcache.h"
#include "rtable.h"
#include "arp.h"

#include "log.h"

#include <stdlib.h>

void ip_init_hdr(struct iphdr *ip, u32 saddr, u32 daddr, u16 len, u8 proto)
{
	ip->version = 4;
	ip->ihl = 5;
	ip->tos = 0;
	ip->tot_len = htons(len);
	ip->id = rand();
	ip->frag_off = htons(IP_DF);
	ip->ttl = DEFAULT_TTL;
	ip->protocol = proto;
	ip->saddr = htonl(saddr);
	ip->daddr = htonl(daddr);
	ip->checksum = ip_checksum(ip);
}

// the input address is in host byte order
rt_entry_t *longest_prefix_match(u32 dst)
{
	// fprintf(stderr, "TODO: longest prefix match for the packet.\n");
	// return NULL;
	rt_entry_t *entry, *longest = NULL;

	list_for_each_entry(entry, &rtable, list){
		if((dst & entry->mask) == (entry->dest & entry->mask)){
			if(longest == NULL){
				longest = entry;
			}
			else if(entry->mask > longest->mask){
				longest = entry;
			}
		}
	}

	return longest;
}

void ip_forward_packet(u32 ip_dst, char *packet, int len)
{
	// fprintf(stderr, "TODO: forward ip packet.\n");
	struct iphdr *ip = packet_to_ip_hdr(packet);

	rt_entry_t *entry = longest_prefix_match(ip_dst);
	if(!entry){
		icmp_send_packet(packet, len, (u8)3, (u8)0);
		free(packet);
		return;
	}

	ip->ttl--;
	ip->checksum = ip_checksum(ip);

	if(ip->ttl <= 0){
		icmp_send_packet(packet, len, (u8)11, (u8)0);
		free(packet);
		return;
	}

	ip_send_packet(packet, len);
}

void handle_ip_packet(iface_info_t *iface, char *packet, int len)
{
	// fprintf(stderr, "TODO: handle ip packet: echo the ping packet, and forward other IP packets.\n");
	struct iphdr *ip = packet_to_ip_hdr(packet);
	u32 ip_dst = ntohl(ip->daddr);

	if(iface->ip == ip_dst){
		icmp_send_packet(packet, len, (u8)0, (u8)0);
		free(packet);
	}
	else{
		ip_forward_packet(ip_dst, packet, len);
	}
}

void ip_send_packet(char *packet, int len)
{
	struct iphdr *ip = packet_to_ip_hdr(packet);
	u32 dst = ntohl(ip->daddr);
	rt_entry_t *entry = longest_prefix_match(dst);
	if (!entry) {
		log(ERROR, "Could not find forwarding rule for IP (dst:"IP_FMT") packet.", 
				HOST_IP_FMT_STR(dst));
		free(packet);
		return ;
	}

	u32 next_hop = entry->gw;
	if (!next_hop)
		next_hop = dst;

	struct ether_header *eh = (struct ether_header *)packet;
	eh->ether_type = ntohs(ETH_P_IP);
	memcpy(eh->ether_shost, entry->iface->mac, ETH_ALEN);

	iface_send_packet_by_arp(entry->iface, next_hop, packet, len);
}
