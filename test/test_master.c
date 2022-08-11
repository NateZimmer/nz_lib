
#include "acutest.h"

#include "pcap_test.h"
#include "ring_test.h"

TEST_LIST = {
    { "PCAP Utils", test_pcap },
    { "Ring Buf", ring_test },
    { NULL, NULL }     /* zeroed record marking the end of the list */
};
