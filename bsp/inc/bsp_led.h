/*
 * @Description: led 驱动
 * @Author: TOTHTOT
 * @Date: 2023-08-01 17:18:22
 * @LastEditTime: 2023-08-01 17:20:03
 * @LastEditors: TOTHTOT
 * @FilePath: \MDKd:\Project\Work\hc32f460_test\template_usart\bsp\inc\bsp_led.h
 */
#ifndef __BSP_LED_H__
#define __BSP_LED_H__

#include <stdint.h>
#include "hc32_ddl.h"

typedef struct bsp_led_t bsp_led_t;
typedef uint8_t (*led_ctrl_t)(uint8_t led_state);
typedef uint8_t (*led_config_t)(void);
typedef enum
{
		LED_STATE_NONE,
		LED_STATE_ON,
		LED_STATE_OFF,
		LED_STATE_TOGGLE,
		LED_TOTAL_STATE
}led_state_t;
struct bsp_led_t
{
		
//    led_ctrl_t led_ctrl_cb; // 用户提供的led控制函数
//		led_config_t led_config_cb;
	
    uint8_t (*ctrl_cb)(led_state_t led_state_em);       // 翻转LED状态

};
extern bsp_led_t g_led_dev_st;
/* 全局函数 */
uint8_t led_init(bsp_led_t *dev);

#endif /* __BSP_LED_H__ */
