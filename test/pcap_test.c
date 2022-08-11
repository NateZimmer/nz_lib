
#define TEST_NO_MAIN
#include "acutest.h"

#include "pcap_test.h"
#include "../src/pcap_util/pcap_util.h"

void test_pcap()
{
    FILE * fp;
    uint8_t data[4] = {1, 2, 3, 4}; 
    fp = pcap_initialize(NULL, 147);
    pcap_write_packet(data, sizeof(data), &fp);
    pcap_write_packet(data, sizeof(data), &fp);
}

