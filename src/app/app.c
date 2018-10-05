/**
  * @file    app.c
  * @brief   Application
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include "app.h"
#include "bsp.h"
#include "app_trace.h"
#include "ui_led.h"
#include "ui_key.h"


#define UI_KEY_IDX_TS100                3
#define UI_KEY_IDX_TS101                6
#define UI_KEY_IDX_TS102                5
#define UI_KEY_IDX_TS103                1
#define UI_KEY_IDX_TS104                2
#define UI_KEY_IDX_TS105                0
#define UI_KEY_IDX_TS106                4
#define UI_KEY_IDX_TS107                7


                app_t                   app;
                UART_HandleTypeDef      huart1;
extern  CONST   TSL_TouchKeyB_T         MyTKeysB[];

void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_USART1_UART_Init(void);


/**
  * @brief  Display sensors information on LEDs and LCD
  * @param  status TSL user status
  * @retval None
  */
static
void    Process_Sensors(                tsl_user_status_t       status )
{
        uint8_t         mask    = 0;


        /* ECS information */
        switch( status )
        {
                case TSL_USER_STATUS_OK_ECS_OFF:
                        //BSP_LED_Off(LED4);
                        //APP_TRACE( "BSP_LED_Off( LED4 )\n" );
                        break;

                case TSL_USER_STATUS_OK_ECS_ON:
                        //ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        //BSP_LED_Toggle(LED4);
                        //APP_TRACE( "BSP_LED_Toggle( LED4 )\n" );
                        break;

                default:
                        break;
        }


        mask    |=   MyTKeysB[ UI_KEY_IDX_TS100 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS100 : 0;
        mask    |=   MyTKeysB[ UI_KEY_IDX_TS101 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS101 : 0;
        mask    |=   MyTKeysB[ UI_KEY_IDX_TS102 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS102 : 0;
        mask    |=   MyTKeysB[ UI_KEY_IDX_TS103 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS103 : 0;
        mask    |=   MyTKeysB[ UI_KEY_IDX_TS104 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS104 : 0;
        mask    |=   MyTKeysB[ UI_KEY_IDX_TS105 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS105 : 0;
        mask    |=   MyTKeysB[ UI_KEY_IDX_TS106 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS106 : 0;
        mask    |=   MyTKeysB[ UI_KEY_IDX_TS107 ].p_Data->StateId == TSL_STATEID_DETECT ? UI_LED_TS107 : 0;

        ui_led_ts_set( ~mask );
}


/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main( void )
{
        tsl_user_status_t       tsl_status;
        uint8_t                 mask;


        HAL_Init();
        SystemClock_Config();

        ui_led_pwr_init();
        ui_led_pwr_set( true );
        ui_led_ts_init();
        ui_led_ts_startup( 250 );


        MX_GPIO_Init();

        //MX_TSC_Init();
        ui_key_ts_init();
        //MX_TOUCHSENSING_Init();

        MX_USART1_UART_Init();

        while( 1 )
        {
                tsl_status = tsl_user_Exec();   // Execute STMTouch Driver state machine

                if( tsl_status != TSL_USER_STATUS_BUSY )
                {
                        Process_Sensors(tsl_status);
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS100 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS100 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x01;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS101 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS101 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x02;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS102 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS102 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x04;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS103 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS103 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x08;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS104 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS104 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x10;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS105 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS105 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x20;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS106 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS106 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x40;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                if(     MyTKeysB[ UI_KEY_IDX_TS107 ].p_Data->Change &&
                        MyTKeysB[ UI_KEY_IDX_TS107 ].p_Data->StateId == TSL_STATEID_DETECT )
                {
                        ui_led_pwr_flash( UI_LED_FLSH_SHRT_TCKS );
                        mask    =   0x80;
                        HAL_UART_Transmit( &huart1, &mask, 1, 100 );
                }

                //HAL_Delay( 1 );
        }
}


/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{

  RCC_OscInitTypeDef RCC_OscInitStruct;
  RCC_ClkInitTypeDef RCC_ClkInitStruct;
  RCC_PeriphCLKInitTypeDef PeriphClkInit;

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = 16;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_NONE;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Initializes the CPU, AHB and APB busses clocks
    */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_HSI;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_0) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

  PeriphClkInit.PeriphClockSelection = RCC_PERIPHCLK_USART1;
  PeriphClkInit.Usart1ClockSelection = RCC_USART1CLKSOURCE_PCLK1;
  if (HAL_RCCEx_PeriphCLKConfig(&PeriphClkInit) != HAL_OK)
  {
    _Error_Handler(__FILE__, __LINE__);
  }

    /**Configure the Systick interrupt time
    */
  HAL_SYSTICK_Config(HAL_RCC_GetHCLKFreq()/1000);

    /**Configure the Systick
    */
  HAL_SYSTICK_CLKSourceConfig(SYSTICK_CLKSOURCE_HCLK);

  /* SysTick_IRQn interrupt configuration */
  HAL_NVIC_SetPriority(SysTick_IRQn, 0, 0);
}

/*
static
void MX_TSC_Init(void)
{
        htsc.Instance = TSC;
        htsc.Init.CTPulseHighLength = TSC_CTPH_2CYCLES;
        htsc.Init.CTPulseLowLength = TSC_CTPL_2CYCLES;
        htsc.Init.SpreadSpectrum = DISABLE;
        htsc.Init.SpreadSpectrumDeviation = 1;
        htsc.Init.SpreadSpectrumPrescaler = TSC_SS_PRESC_DIV1;
        htsc.Init.PulseGeneratorPrescaler = TSC_PG_PRESC_DIV4;
        htsc.Init.MaxCountValue = TSC_MCV_8191;
        htsc.Init.IODefaultMode = TSC_IODEF_OUT_PP_LOW;
        htsc.Init.SynchroPinPolarity = TSC_SYNC_POLARITY_FALLING;
        htsc.Init.AcquisitionMode = TSC_ACQ_MODE_NORMAL;
        htsc.Init.MaxCountInterrupt = DISABLE;
        htsc.Init.ChannelIOs = TSC_GROUP1_IO3|TSC_GROUP1_IO4|TSC_GROUP2_IO2|TSC_GROUP2_IO3|TSC_GROUP2_IO4|TSC_GROUP4_IO2|TSC_GROUP4_IO3|TSC_GROUP4_IO4;
        htsc.Init.ShieldIOs = TSC_GROUP5_IO1;
        htsc.Init.SamplingIOs = TSC_GROUP1_IO1|TSC_GROUP2_IO1|TSC_GROUP4_IO1|TSC_GROUP5_IO2;
        if( HAL_TSC_Init( &htsc ) != HAL_OK )
        {
                _Error_Handler( __FILE__, __LINE__ );
        }
}
*/

static
void MX_USART1_UART_Init(void)
{
        huart1.Instance                         = USART1;
        //huart1.Init.BaudRate                    = 9600;
        huart1.Init.BaudRate                    = 115200;
        huart1.Init.WordLength                  = UART_WORDLENGTH_8B;
        huart1.Init.StopBits                    = UART_STOPBITS_1;
        huart1.Init.Parity                      = UART_PARITY_NONE;
        huart1.Init.Mode                        = UART_MODE_TX_RX;
        huart1.Init.HwFlowCtl                   = UART_HWCONTROL_NONE;
        huart1.Init.OverSampling                = UART_OVERSAMPLING_16;
        huart1.Init.OneBitSampling              = UART_ONE_BIT_SAMPLE_DISABLE;
        huart1.AdvancedInit.AdvFeatureInit      = UART_ADVFEATURE_NO_INIT;

        if( HAL_UART_Init( &huart1 ) != HAL_OK )
        {
                _Error_Handler(__FILE__, __LINE__);
        }
}

/** Configure pins as
        * Analog
        * Input
        * Output
        * EVENT_OUT
        * EXTI
*/
static void MX_GPIO_Init(void)
{
        __HAL_RCC_GPIOF_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
void _Error_Handler(char *file, int line)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  while(1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     tex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */

/**
  * @}
  */

/**
  * @}
  */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
