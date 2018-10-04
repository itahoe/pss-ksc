/**
  * @file    ui_led.h
  * @brief   User Interface - LED Services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  UI_LED_H
#define  UI_LED_H


#include	<stdint.h>
#include	<stdbool.h>
#include	<string.h>
#include	"config.h"
#include	"bsp_led.h"


//#define	UI_LED_FLSH_SHRT_TCKS   ( ((uint32_t) CFG_UI_LED_FLSH_SHRT_mSEC * UI_SYSTICK_HZ) / 1000 )
//#define	UI_LED_FLSH_LONG_TCKS   ( ((uint32_t) CFG_UI_LED_FLSH_LONG_mSEC * UI_SYSTICK_HZ) / 1000 )



void ui_led_pwr_init( void );

void ui_led_pwr_set(            const   bool                    val );

void ui_led_sts_init( void );

void ui_led_sts_set(            const   uint8_t                 val );

void    ui_led_sts_startup(     const   uint32_t        delay );


#endif	//UI_LED_H
