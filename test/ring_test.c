
#define TEST_NO_MAIN
#include "acutest.h"

#include "../src/ring_buf/ring_buf.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

ring_buf_t buf;

void ring_test()
{
  uint8_t data[30] = {0};
  uint16_t bytes_read = 0;
  bool overflow = false;
  ring_buf_init(&buf, 6);

  // Test Length, 0
  TEST_CHECK(ring_buf_len(&buf) == 0);

  printf("\r\ninitially buf len should be 0, buf len is %d, buf size is %d\r\n", ring_buf_len(&buf), buf.total_size);
  overflow = ring_buf_add(&buf, (uint8_t[]){1, 2, 3, 4}, 4);
  printf("adding {1,2,3,4}, buf len is %d, overflow: %d\r\n", ring_buf_len(&buf), overflow);

  // Test Length, 4
  TEST_CHECK(ring_buf_len(&buf) == 4);

  overflow = ring_buf_add(&buf, (uint8_t[]){5, 6, 7}, 3);
  printf("adding {5,6,7}, buf len is %d, overflow: %d\r\n", ring_buf_len(&buf), overflow);
  printf("Buf is: ");
  for(int i = 0; i < buf.total_size; i++)
  {
    printf("%02x ", buf.data[i]);
  }
  printf("\r\n");
  bytes_read = ring_buf_get(&buf, data, 3);
  printf("attempting to read 3 bytes, read %d\r\nBuffer: ", bytes_read);
  for(int i = 0; i < bytes_read; i++)
  {
    printf("%02x ", data[i]);
  }
  printf("\r\n");
  overflow = ring_buf_add(&buf, (uint8_t[]){1, 2, 3, 4}, 4);
  printf("adding {1,2,3,4}, buf len is %d, overflow: %d\r\n", ring_buf_len(&buf), overflow);
  bytes_read = ring_buf_get(&buf, data, 2);
  printf("reading 2 bytes, read %d\r\nBuf: ", bytes_read);
  for(int i = 0; i < bytes_read; i++)
  {
    printf("%02x ", data[i]);
  }
  printf("\r\n");
  bytes_read = ring_buf_get(&buf, data, 3);
  printf("reading 3 bytes, read %d\r\nBuf: ", bytes_read);
  for(int i = 0; i < bytes_read; i++)
  {
    printf("%02x ", data[i]);
  }
  printf("\r\n");
}
