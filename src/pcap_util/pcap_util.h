
#ifndef PCAP_UTIL_H
#define PCAP_UTIL_H

#include <stdint.h>
#include <stdio.h>

#define PCAP_OFFSET 16
#define PCAP_HEADER_SIZE 24

#pragma pack(push)
#pragma pack(1)

typedef struct{
    uint32_t magic_number;
    uint16_t version_major;
    uint16_t version_minor;
    uint32_t this_zone;
    uint32_t sig_figs;
    uint32_t snapshot_length;
    uint32_t link_type;
}pcap_header_t;

FILE * pcap_initialize(char * pcap_file_name, uint16_t link_type);
void pcap_write_packet(uint8_t * buf, uint32_t buf_len, FILE ** fp);

#pragma pack(push)

#endif // end PCAP_UTIL_H
