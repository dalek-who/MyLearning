#include "icmp.h"
#include "ip.h"
#include "rtable.h"
#include "arp.h"
#include "base.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void icmp_send_packet(const char *in_pkt, int len, u8 type, u8 code)
{
	// fprintf(stderr, "TODO: malloc and send icmp packet.\n");
	struct iphdr *in_ip = packet_to_ip_hdr(in_pkt);
	u32 dst = ntohl(in_ip->saddr);
	rt_entry_t *entry = longest_prefix_match(dst);

	int out_len, source, destination, new_len;
	switch(type){
		case 0:
			out_len = len - IP_HDR_SIZE(in_ip) + IP_BASE_HDR_SIZE;
			source = 0; destination = IP_HDR_SIZE(in_ip);
			break;
		case 3:
		case 11:
			out_len = ETHER_HDR_SIZE + IP_BASE_HDR_SIZE + ICMP_HDR_SIZE + IP_HDR_SIZE(in_ip) + 8;
			source = ICMP_HDR_SIZE; destination = 0;
			break;
	}
	char *out_pkt;
	out_pkt = malloc(out_len);

	struct icmphdr* icmp_hdr = (struct icmphdr *)(out_pkt + ETHER_HDR_SIZE + IP_BASE_HDR_SIZE);
	memset(icmp_hdr, 0, ICMP_HDR_SIZE);
	new_len = out_len - IP_BASE_HDR_SIZE - ETHER_HDR_SIZE;
	memcpy((char *)icmp_hdr + source, (char *)in_ip + destination, new_len - source);

	icmp_hdr->type = type;
	icmp_hdr->code = code;
	icmp_hdr->checksum = icmp_checksum(icmp_hdr, new_len);

	struct ether_header *out_eh = (struct ether_header *)out_pkt;
	out_eh->ether_type = ntohs(ETH_P_IP);

	struct iphdr *out_ip = packet_to_ip_hdr(out_pkt);
	ip_init_hdr(out_ip, entry->iface->ip, dst, out_len - ETHER_HDR_SIZE, 1);
	ip_send_packet(out_pkt, out_len);
}
