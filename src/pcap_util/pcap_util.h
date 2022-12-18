
#ifndef PCAP_UTIL_H
#define PCAP_UTIL_H

#include <stdint.h>
#include <stdio.h>

#define PCAP_OFFSET 16
#define PCAP_HEADER_SIZE 24

#pragma pack(push)
#pragma pack(1)

typedef struct
{
  uint32_t magic_number;
  uint16_t version_major;
  uint16_t version_minor;
  uint32_t this_zone;
  uint32_t sig_figs;
  uint32_t snapshot_length;
  uint32_t link_type;
} pcap_header_t;

/**
    @brief Creates a .pcap file and returns an open file handle
    @param[in] pcap_file_name - file name pointer. Set to NULL for a timestamp auto-gen filename
    @param[in] link_type - Wireshark link types. This defines what dissector is used when opening a .pcap
*/
FILE *pcap_initialize(char *pcap_file_name, uint16_t link_type);

/**
    @brief Appends a packet to a pcap file
    @param[in] buf - Pointer to a byte array
    @param[in] buf_len - Length of byte array
    @param[in] fp - Pointer to pcap file pointer, use the output of &pcap_initialize
*/
void pcap_write_packet(uint8_t *buf, uint32_t buf_len, FILE **fp);

#pragma pack(push)

#endif // end PCAP_UTIL_H
