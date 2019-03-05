/**
  * @file    app_isr.c
  * @brief   Interrupt Service Routines
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include "stm32f0xx_hal.h"
#include "stm32f0xx.h"
#include "tsl_time.h"
#include "ui_key.h"
#include "ui_led.h"
#include "app.h"


extern          app_t                   app;
extern  CONST   TSL_TouchKeyB_T         MyTKeysB[];


void    NMI_Handler( void );
void    HardFault_Handler( void );
void    SVC_Handler( void );
void    PendSV_Handler( void );
void    SysTick_Handler( void );


/******************************************************************************/
/*            Cortex-M0 Processor Interruption and Exception Handlers         */
/******************************************************************************/

/**
* @brief This function handles Non maskable interrupt.
*/
void NMI_Handler( void )
{
}


/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler( void )
{
        while( 1 );
}


/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler( void )
{
}


/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler( void )
{
}


/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler( void )
{
        HAL_IncTick();
        HAL_SYSTICK_IRQHandler();
        TSL_tim_ProcessIT();    //TSL timing for ECS, DTO
        ui_led_pwr_hook();
        app.evt.tick_1msec      = true;

	app.evt.key_ts100       = ui_key_ts100_hook();
	app.evt.key_ts101       = ui_key_ts101_hook();
	app.evt.key_ts102       = ui_key_ts102_hook();
	app.evt.key_ts103       = ui_key_ts103_hook();
	app.evt.key_ts104       = ui_key_ts104_hook();
	app.evt.key_ts105       = ui_key_ts105_hook();
}


/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

