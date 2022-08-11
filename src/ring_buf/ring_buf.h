
#ifndef RING_BUF_H
#define RING_BUF_H

#include <stdint.h>
#include <stdbool.h>

typedef struct
{
  uint8_t * data;
  uint8_t * head;
  uint8_t * tail;
  uint16_t total_size;
}ring_buf_t;

/**
 * @brief initialize ring buffer
 * @param[in] buf - Pointer to ring buf struct, see ring_buf_t
 * @param[in] len - Length of buffer in bytes 
 */
void ring_buf_init(ring_buf_t * buf, uint16_t len);

/**
 * @brief gets the length of bytes in buffer 
 * @param[in] buf - Pointer to ring buf struct, see ring_buf_t
 */
uint16_t ring_buf_len(ring_buf_t * buf);

/**
 * @brief add bytes into ring buffer 
 * @param[in] buf - Pointer to ring buf struct, see ring_buf_t
 * @param[in] data - Pointer to buffer to be filled into ring buffer
 * @param[in] len - length of data in bytes
 * @return overflow, true if an overflow occurred 
 */
bool ring_buf_add(ring_buf_t * buf, uint8_t * data, uint16_t len);

/**
 * @brief get bytes from ring buffer 
 * @param[in] buf - Pointer to ring buf struct, see ring_buf_t
 * @param[out] data - Pointer to buffer to be filled into ring buffer
 * @param[in] len - length of data in bytes
 * @return bytes read, will be less than len if amount in buffer is less than len
 */
uint16_t ring_buf_get(ring_buf_t * buf, uint8_t * data, uint16_t len);

/**
 * @brief clears out data in buffer
 * @param[in] buf - Pointer to ring buf struct, see ring_buf_t
 */
void ring_buf_reset(ring_buf_t * buf); 

#endif // RING_BUF_H
