/**
  * @file    ui_led_sts.c
  * @brief   UI - Status LED
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include	"ui_led.h"


static  ui_led_t        ui_led_pwr      =   {   .init           =   bsp_led_pwr_init,
	                                        .get            =   bsp_led_pwr_get,
	                                        .set            =   bsp_led_pwr_set,
	                                        .tick           =   0 };


/**
 * @brief LED Init
 */
void ui_led_pwr_init( void )
{
        ui_led_init( &ui_led_pwr );
}


/**
 * @brief LED SysTick Hook.
 */
bool ui_led_pwr_hook( void )
{
	bool            resp    =   ui_led_hook( &ui_led_pwr );

	return( resp );
}


/**
 * @brief LED Control
 */
void ui_led_pwr_set(                    const   bool                    val )
{
        ui_led_set( &ui_led_pwr, val );
}


void ui_led_pwr_flash(                  const   size_t                  len )
{
        ui_led_flash( &ui_led_pwr, len );
}

