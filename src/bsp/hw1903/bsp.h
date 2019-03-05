/**
  * @file    bsp.h
  * @brief   Board Support Package
  * @author  Igor T. <research.tahoe@gmail.com>
  */

#ifndef  BSP_H
#define  BSP_H


#include <stdint.h>
#include <stdbool.h>
//#include "config.h"
//#include "stm32f3xx_hal.h"
#include "stm32f0xx_hal.h"
//#include "stm32f0xx.h"

//#include "stm32f3xx_ll_bus.h"
//#include "stm32f3xx_ll_rcc.h"
//#include "stm32f3xx_ll_gpio.h"
//#include "stm32f3xx_ll_dma.h"
//#include "stm32f3xx_ll_usart.h"


#define BSP_SYSTICK_HZ                  1000ul

#define BSP_NVIC_PRIO_SER1_DMA_RX       9
#define BSP_NVIC_PRIO_SER1_DMA_TX       9
#define BSP_NVIC_PRIO_SER1_UART         11
#define BSP_NVIC_PRIO_SENS_ADC          7


typedef enum    bsp_ser_isr_sts_e
{
        BSP_SER_ISR_STS_NONE,
        BSP_SER_ISR_STS_IDLE,
} bsp_ser_isr_sts_t;


void    bsp_system_reset( void );

void    bsp_sens_init( void );

void    bsp_sens_run( void );

void    bsp_sens_isr( void );



#endif	//BSP_H
