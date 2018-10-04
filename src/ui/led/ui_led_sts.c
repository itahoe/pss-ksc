/**
  * @file    ui_led_sts.c
  * @brief   UI - Status LED
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include	"bsp_led.h"
#include	"ui_led.h"


const   uint8_t         ui_led_sts_remap[ 256 ]   = { 0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };


/**
 * @brief LED Init.
 */
void ui_led_sts_init( void )
{
        bsp_led_sts_init();
}


/**
 * @brief POWER LED Control.
 */
void ui_led_sts_set(            const   uint8_t                 val )
{
        //0x08 > 0x08
        //0x40 > 0x40
        //0x20 > 0x80
        //0x02 >
        //0x04 >
        //0x01 > 0x01
        //0x10 >
        //0x80 >
        uint8_t         map     = 0;


        map     = val & 0x08 ? map | 0x08 : map;
        map     = val & 0x40 ? map | 0x40 : map;
        map     = val & 0x20 ? map | 0x80 : map;
        map     = val & 0x02 ? map | 0x04 : map;
        map     = val & 0x04 ? map | 0x20 : map;
        map     = val & 0x01 ? map | 0x01 : map;
        map     = val & 0x10 ? map | 0x02 : map;
        map     = val & 0x80 ? map | 0x10 : map;

        bsp_led_sts_set( map );
        //bsp_led_sts_set( ui_led_sts_remap[ val ] );
}


void    ui_led_sts_startup(     const   uint32_t        delay_msec )
{
        //ui_led_sts_set( 0x08 | 0x01 );
        //ui_led_sts_set( 0x01 | 0x20 );
        ui_led_sts_set( 0x01 | 0x08 );
        HAL_Delay( delay_msec );

        //ui_led_sts_set( 0x80 | 0x10 );
        //ui_led_sts_set( 0x02 | 0x40 );
        ui_led_sts_set( 0x10 | 0x40 );
        HAL_Delay( delay_msec );

        //ui_led_sts_set( 0x40 | 0x02 );
        //ui_led_sts_set( 0x04 | 0x80 );
        ui_led_sts_set( 0x20 | 0x80 );
        HAL_Delay( delay_msec );

        //ui_led_sts_set( 0x20 | 0x04  );
        //ui_led_sts_set( 0x08 | 0x10  );
        ui_led_sts_set( 0x02 | 0x04  );
        HAL_Delay( delay_msec );

        ui_led_sts_set( 0x00 );
        HAL_Delay( delay_msec );

        ui_led_sts_set( 0xFF );
}
