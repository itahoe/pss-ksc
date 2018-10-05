/**
  * @file    app_clock.c
  * @brief   Configure MCU clock tree
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include "stm32f0xx.h"
#include "app_trace.h"
#include "app.h"


void    app_clock_config( void )
{
        RCC_OscInitTypeDef              osc;
        RCC_ClkInitTypeDef              clk;
        RCC_PeriphCLKInitTypeDef        pck;

        //Initializes the CPU, AHB and APB busses clocks
        osc.OscillatorType = RCC_OSCILLATORTYPE_HSI;
        osc.HSIState = RCC_HSI_ON;
        osc.HSICalibrationValue = 16;
        osc.PLL.PLLState = RCC_PLL_NONE;

        if( HAL_RCC_OscConfig( &osc ) != HAL_OK )
        {
                _Error_Handler(__FILE__, __LINE__);
        }

        //Initializes the CPU, AHB and APB busses clocks
        clk.ClockType     = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK | RCC_CLOCKTYPE_PCLK1;
        clk.SYSCLKSource  = RCC_SYSCLKSOURCE_HSI;
        clk.AHBCLKDivider = RCC_SYSCLK_DIV1;
        clk.APB1CLKDivider = RCC_HCLK_DIV1;

        if( HAL_RCC_ClockConfig( &clk, FLASH_LATENCY_0 ) != HAL_OK )
        {
                _Error_Handler(__FILE__, __LINE__);
        }

        pck.PeriphClockSelection = RCC_PERIPHCLK_USART1;
        pck.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
        if( HAL_RCCEx_PeriphCLKConfig( &pck ) != HAL_OK )
        {
                _Error_Handler(__FILE__, __LINE__);
        }

        //Configure the Systick interrupt time
        HAL_SYSTICK_Config( HAL_RCC_GetHCLKFreq()/1000 );

        //Configure the Systick
        HAL_SYSTICK_CLKSourceConfig( SYSTICK_CLKSOURCE_HCLK );

        //SysTick_IRQn interrupt configuration
        HAL_NVIC_SetPriority( SysTick_IRQn, 0, 0 );
}
