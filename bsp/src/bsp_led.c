/*
 * @Description: led 驱动
 * @Author: TOTHTOT
 * @Date: 2023-08-01 17:18:37
 * @LastEditTime: 2023-08-01 17:28:24
 * @LastEditors: TOTHTOT
 * @FilePath: \MDKd:\Project\Work\hc32f460_test\template_usart\bsp\src\bsp_led.c
 */

#include "bsp_led.h"


bsp_led_t g_led_dev_st = {0};

uint8_t led_config(void)
{
	stc_port_init_t stcPortInit;

    MEM_ZERO_STRUCT(stcPortInit);

    stcPortInit.enPinMode = Pin_Mode_Out;
    stcPortInit.enExInt = Enable;
    stcPortInit.enPullUp = Enable;

    PORT_Init(PortB, Pin04, &stcPortInit);
}

uint8_t led_ctrl(led_state_t led_state)
{
	switch(led_state)
	{
		case LED_STATE_ON:
			PORT_SetBits(PortB, Pin04);
			break;
		case LED_STATE_OFF:
			PORT_ResetBits(PortB, Pin04);
			break;
		case LED_STATE_TOGGLE:
			PORT_Toggle(PortB, Pin04);
			break;
	}
	return led_state;
}


uint8_t led_init(bsp_led_t *dev)
{
		led_config();
    dev->ctrl_cb = led_ctrl;
    return 0;
}

