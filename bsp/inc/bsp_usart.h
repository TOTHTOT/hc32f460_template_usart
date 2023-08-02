/*
 * @Description: 串口驱动, hc32f460
 * @Author: TOTHTOT
 * @Date: 2023-08-01 16:22:46
 * @LastEditTime: 2023-08-01 16:28:21
 * @LastEditors: TOTHTOT
 * @FilePath: \MDKd:\Project\Work\hc32f460_test\template_usart\bsp\bsp_usart.h
 */

#ifndef __BSP_USART_H__
#define __BSP_USART_H__

#include "hc32_ddl.h"
#include <stdint.h>

typedef struct
{
#define USART_RX_BUF_SIZE 128
    uint8_t rx_buf[USART_RX_BUF_SIZE];

    // 回调函数
    uint8_t (*recv_cb)(uint8_t *data, uint32_t len);
    uint8_t (*analyse_recv_data_cb)(uint8_t *data);

} bsp_usart_t;

#endif /* __BSP_USART_H__ */
