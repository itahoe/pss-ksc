/**
  * @file    ui_led_sts.c
  * @brief   UI - Status LED
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include	"bsp_led.h"
#include	"ui_led.h"


#define UI_LED_TS100            0x08
#define UI_LED_TS101            0x40
#define UI_LED_TS102            0x20
#define UI_LED_TS103            0x02
#define UI_LED_TS104            0x04
#define UI_LED_TS105            0x01
#define UI_LED_TS106            0x10
#define UI_LED_TS107            0x80

//const   uint8_t         ui_led_sts_remap[ 256 ]   = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };


/**
 * @brief LED Init.
 */
void ui_led_sts_init( void )
{
        bsp_led_sts_init();
}


/**
 * @brief LED Control.
 */
void ui_led_sts_set(            const   uint8_t                 val )
{
        uint8_t         map     = 0;


        map     = val & UI_LED_TS100 ? map | 0x08 : map;
        map     = val & UI_LED_TS101 ? map | 0x40 : map;
        map     = val & UI_LED_TS102 ? map | 0x80 : map;
        map     = val & UI_LED_TS103 ? map | 0x04 : map;
        map     = val & UI_LED_TS104 ? map | 0x20 : map;
        map     = val & UI_LED_TS105 ? map | 0x01 : map;
        map     = val & UI_LED_TS106 ? map | 0x02 : map;
        map     = val & UI_LED_TS107 ? map | 0x10 : map;

        bsp_led_sts_set( map );
}


void    ui_led_sts_startup(     const   uint32_t        delay_msec )
{
        ui_led_sts_set( UI_LED_TS101 | UI_LED_TS106 );
        HAL_Delay( delay_msec );

        ui_led_sts_set( UI_LED_TS103 | UI_LED_TS104 );
        HAL_Delay( delay_msec );

        ui_led_sts_set( UI_LED_TS100 | UI_LED_TS102 );
        HAL_Delay( delay_msec );

        ui_led_sts_set( UI_LED_TS105 | UI_LED_TS107 );
        HAL_Delay( delay_msec );

        ui_led_sts_set( 0x00 );
        HAL_Delay( delay_msec );

        ui_led_sts_set( 0xFF );
}
