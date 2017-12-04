#include "arp.h"
#include "base.h"
#include "types.h"
#include "packet.h"
#include "ether.h"
#include "arpcache.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "log.h"
void arp_send_option(iface_info_t *iface, u32 dst_ip, struct ether_arp *req_hdr, u16 option){
	
	char *packet;
	int len = ETHER_HDR_SIZE + sizeof(struct ether_arp);
	packet = (char *)malloc(len);

	struct ether_header* eh = (struct ether_header*)packet;
	struct ether_arp* eh_arp = (struct ether_arp*)(packet + ETHER_HDR_SIZE);

	eh->ether_type = htons(ETH_P_ARP);
	memcpy((char *)eh->ether_shost, (char *)iface->mac, ETH_ALEN);

	eh_arp->arp_hrd = htons(0x01);
	eh_arp->arp_pro = htons(ETH_P_IP);
	eh_arp->arp_hln = ETH_ALEN;
	eh_arp->arp_pln = 4;
	eh_arp->arp_op = htons(option);
	eh_arp->arp_spa = htonl(iface->ip);
	
	memset(eh_arp->arp_tha, 0, ETH_ALEN);
	memcpy((char *)eh_arp->arp_sha, (char *)iface->mac, ETH_ALEN);

	switch(option){
		case ARPOP_REQUEST:
			memset(eh->ether_dhost, 0xff, ETH_ALEN);
			eh_arp->arp_tpa = htonl(dst_ip);
			break;
		case ARPOP_REPLY:
			memcpy(eh->ether_dhost, req_hdr->arp_sha, ETH_ALEN);
			eh_arp->arp_tpa = req_hdr->arp_spa;
			break;
	}

	iface_send_packet(iface, packet, len);
}
void arp_send_request(iface_info_t *iface, u32 dst_ip)
{
	// fprintf(stderr, "TODO: send arp request when lookup failed in arpcache.\n");
	arp_send_option(iface, dst_ip, NULL, ARPOP_REQUEST);
}

void arp_send_reply(iface_info_t *iface, struct ether_arp *req_hdr)
{
	// fprintf(stderr, "TODO: send arp reply when receiving arp request.\n");
	arp_send_option(iface, 0, req_hdr, ARPOP_REPLY);
}

void handle_arp_packet(iface_info_t *iface, char *packet, int len)
{
	// fprintf(stderr, "TODO: process arp packet: arp request & arp reply.\n");
	struct ether_arp* eh_arp = (struct ether_arp*)(packet + ETHER_HDR_SIZE);
	u16 op = ntohs(eh_arp->arp_op);
	u32 ip = ntohl(eh_arp->arp_tpa);
	
	if(op == ARPOP_REQUEST && ip == iface->ip){
		arp_send_reply(iface, eh_arp);
	}
	else if(op == ARPOP_REPLY && ip == iface->ip){
		arpcache_insert(ntohl(eh_arp->arp_spa), eh_arp->arp_sha);
	}
}

// This function should free the memory of the packet if needed.
void iface_send_packet_by_arp(iface_info_t *iface, u32 dst_ip, char *packet, int len)
{
	struct ether_header *eh = (struct ether_header *)packet;
	memcpy(eh->ether_shost, iface->mac, ETH_ALEN);
	eh->ether_type = htons(ETH_P_IP);

	u8 dst_mac[ETH_ALEN];
	int found = arpcache_lookup(dst_ip, dst_mac);
	if (found) {
		// log(DEBUG, "found the mac of %x, send this packet", dst_ip);
		memcpy(eh->ether_dhost, dst_mac, ETH_ALEN);
		iface_send_packet(iface, packet, len);
		free(packet);
	}
	else {
		// log(DEBUG, "lookup %x failed, pend this packet", dst_ip);
		arpcache_append_packet(iface, dst_ip, packet, len);
	}
}
