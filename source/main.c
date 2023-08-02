
#include "hc32_ddl.h"
#include <stdint.h>
#include "bsp_sys.h"
#include "bsp_usart.h"
#include "bsp_led.h"


int32_t main(void)
{
		PORT_DebugPortSetting(ALL_DBG_PIN, Disable);
		bsp_sys_clk_init();
		SysTick_Init(1000u);
		led_init(&g_led_dev_st);
		g_led_dev_st.ctrl_cb(LED_STATE_OFF);
		while(1)
		{
			g_led_dev_st.ctrl_cb(LED_STATE_TOGGLE);
			Ddl_Delay1ms(500);
		}
}
