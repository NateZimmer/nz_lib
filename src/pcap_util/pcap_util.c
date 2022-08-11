
#include "pcap_util.h"
#include <string.h>
#include <sys/time.h>

#define PRINT_FNC printf

static void pcap_get_packet_header(uint8_t * buf, uint32_t link_type)
{
  pcap_header_t header = {0};
  uint8_t * data = NULL;
  header.magic_number = 0xa1b2c3d4;
  header.version_major = 2;
  header.version_minor = 4;
  header.this_zone = 0;
  header.sig_figs = 0;
  header.snapshot_length = 0;
  header.link_type = link_type;
  data = (uint8_t *)(&header);
  memcpy(buf, data, sizeof(pcap_header_t));
}

FILE * pcap_initialize(char * pcap_file_name, uint16_t link_type)
{
  uint8_t header_buf[PCAP_HEADER_SIZE] = {0};
  char file_name[50];
  struct timeval te;
  FILE * fp = NULL;

  if(pcap_file_name == NULL)
  {
    gettimeofday(&te, NULL);
    sprintf(file_name, "%d.pcap",(int)te.tv_sec);
    fp = fopen(file_name, "ab+");
  }
  else
  {
    fp = fopen(pcap_file_name, "w+");
  }

  if(fp == NULL)
  {
    PRINT_FNC("error in opening file %s\r\n", pcap_file_name);
    return NULL;
  }

  pcap_get_packet_header(header_buf, link_type);

  fwrite(header_buf, 1, sizeof(header_buf), fp);
  fflush(fp);
  return fp;
}

void pcap_write_packet(uint8_t * buf, uint32_t buf_len, FILE ** fp)
{
  struct timeval te;
  uint8_t pcap_header[PCAP_OFFSET] = { 0 };
  uint8_t * index = NULL;

  gettimeofday(&te, NULL);

  // create frame header 
  index = pcap_header;
  uint32_t num = te.tv_sec;
  memcpy(index, &num, sizeof(num));
  index += sizeof(num);
  num = te.tv_usec;
  memcpy(index, &num, sizeof(num));
  index += sizeof(num);
  memcpy(index, &buf_len, sizeof(buf_len));
  index += sizeof(buf_len);
  memcpy(index, &buf_len, sizeof(buf_len));
  index += sizeof(buf_len);

  // write frame header + payload to file
  fwrite(pcap_header, 1, sizeof(pcap_header), *fp);
  fwrite(buf, 1, buf_len, *fp);
  fflush(*fp);
}
