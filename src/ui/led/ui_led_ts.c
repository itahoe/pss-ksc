/**
  * @file    ui_led_ts.c
  * @brief   UI - Touch Sense LED Services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include "bsp_led.h"
#include "ui_led.h"

/**
 * @brief LED Init.
 */
void ui_led_ts_init( void )
{
        bsp_led_ts_init();
}


/**
 * @brief LED Control.
 */
void ui_led_ts_set(            const   uint8_t                 word )
{
        bsp_led_ts_set( word );
}


void    ui_led_ts_startup(     const   uint32_t        delay_msec )
{

        ui_led_ts_set( UI_LED_TS101 | UI_LED_TS106 );
        HAL_Delay( delay_msec );

        ui_led_ts_set( UI_LED_TS103 | UI_LED_TS104 );
        HAL_Delay( delay_msec );

        ui_led_ts_set( UI_LED_TS100 | UI_LED_TS102 );
        HAL_Delay( delay_msec );

        ui_led_ts_set( UI_LED_TS105 | UI_LED_TS107 );
        HAL_Delay( delay_msec );

        ui_led_ts_set( 0x00 );
        HAL_Delay( delay_msec );

        ui_led_ts_set( 0xFF );
}
