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
void NMI_Handler(void)
{
  /* USER CODE BEGIN NonMaskableInt_IRQn 0 */

  /* USER CODE END NonMaskableInt_IRQn 0 */
  /* USER CODE BEGIN NonMaskableInt_IRQn 1 */

  /* USER CODE END NonMaskableInt_IRQn 1 */
}

/**
* @brief This function handles Hard fault interrupt.
*/
void HardFault_Handler(void)
{
  /* USER CODE BEGIN HardFault_IRQn 0 */

  /* USER CODE END HardFault_IRQn 0 */
  while (1)
  {
    /* USER CODE BEGIN W1_HardFault_IRQn 0 */
    /* USER CODE END W1_HardFault_IRQn 0 */
  }
  /* USER CODE BEGIN HardFault_IRQn 1 */

  /* USER CODE END HardFault_IRQn 1 */
}

/**
* @brief This function handles System service call via SWI instruction.
*/
void SVC_Handler(void)
{
  /* USER CODE BEGIN SVC_IRQn 0 */

  /* USER CODE END SVC_IRQn 0 */
  /* USER CODE BEGIN SVC_IRQn 1 */

  /* USER CODE END SVC_IRQn 1 */
}

/**
* @brief This function handles Pendable request for system service.
*/
void PendSV_Handler(void)
{
  /* USER CODE BEGIN PendSV_IRQn 0 */

  /* USER CODE END PendSV_IRQn 0 */
  /* USER CODE BEGIN PendSV_IRQn 1 */

  /* USER CODE END PendSV_IRQn 1 */
}

/**
* @brief This function handles System tick timer.
*/
void SysTick_Handler(void)
{
        HAL_IncTick();
        HAL_SYSTICK_IRQHandler();
        TSL_tim_ProcessIT();    //TSL timing for ECS, DTO
        ui_led_pwr_hook();
/*
	app.evt.ui_key_ts100    = ui_key_ts100_hook( MyTKeysB[6].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
	//app.evt.ui_key_ts100    = ui_key_ts100_hook( MyTKeysB[1].p_Data->StateId == TSL_STATEID_DEB_DETECT ? true : false );
	//app.evt.ui_key_ts100    = ui_key_ts100_hook( MyTKeysB[1].p_Data->StateId == TSL_STATEID_TOUCH ? true : false );

	app.evt.ui_key_ts101    = ui_key_ts101_hook( MyTKeysB[0].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
	app.evt.ui_key_ts102    = ui_key_ts102_hook( MyTKeysB[2].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
	app.evt.ui_key_ts103    = ui_key_ts103_hook( MyTKeysB[3].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
	app.evt.ui_key_ts104    = ui_key_ts104_hook( MyTKeysB[1].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
	app.evt.ui_key_ts105    = ui_key_ts105_hook( MyTKeysB[5].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
	app.evt.ui_key_ts106    = ui_key_ts106_hook( MyTKeysB[4].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
	app.evt.ui_key_ts107    = ui_key_ts107_hook( MyTKeysB[7].p_Data->StateId == TSL_STATEID_DETECT ? true : false );
*/
}

/******************************************************************************/
/* STM32F0xx Peripheral Interrupt Handlers                                    */
/* Add here the Interrupt Handlers for the used peripherals.                  */
/* For the available peripheral interrupt handler names,                      */
/* please refer to the startup file (startup_stm32f0xx.s).                    */
/******************************************************************************/

/* USER CODE BEGIN 1 */

/* USER CODE END 1 */
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
