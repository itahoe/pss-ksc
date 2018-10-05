/**
  * @file    bsp_key.h
  * @brief   Board Support Package - Keys Touch Senese services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  BSP_KEY_H
#define  BSP_KEY_H


#include <stdint.h>
#include <stdbool.h>
#include "stm32f0xx_hal.h"


void    bsp_key_ts_init( void );
bool    bsp_key_ts_get( void );
void	bsp_key_ts_set(        const   bool                    val );


#endif	//BSP_KEY_H
