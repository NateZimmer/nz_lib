
#include "acutest.h"
#include "../src/add.h"

void test_add()
{
    TEST_CHECK( add(1,2)==3);
}

TEST_LIST = {
    { "Testing add", test_add },
    { NULL, NULL }     /* zeroed record marking the end of the list */
};