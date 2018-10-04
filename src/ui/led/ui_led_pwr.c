/**
  * @file    ui_led_sts.c
  * @brief   UI - Status LED
  * @author  Igor T. <research.tahoe@gmail.com>
  */

#include	"ui_led.h"


/**
 * @brief LED Init.
 */
void ui_led_pwr_init( void )
{
        bsp_led_pwr_init();
}


/**
 * @brief POWER LED Control.
 */
void ui_led_pwr_set(            const   bool                    val )
{
        bsp_led_pwr_set( val );
}
