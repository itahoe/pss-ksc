/**
  * @file    bsp_led.h
  * @brief   Board Support Package - LED services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  BSP_LED_H
#define  BSP_LED_H


#include	<stdint.h>
#include	<stdbool.h>
#include        "stm32f0xx_hal.h"


void    bsp_led_pwr_init( void );
bool    bsp_led_pwr_get( void );
void	bsp_led_pwr_set(        const   bool                    val );


void    bsp_led_ts_init( void );
uint8_t bsp_led_ts_get( void );
void	bsp_led_ts_set(         const   uint8_t                 val );


#endif	//BSP_LED_H
