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

/*
#define UI_KEY_IDX_TS100                3
#define UI_KEY_IDX_TS101                6
#define UI_KEY_IDX_TS102                5
#define UI_KEY_IDX_TS103                1
#define UI_KEY_IDX_TS104                2
#define UI_KEY_IDX_TS105                0
#define UI_KEY_IDX_TS106                4
#define UI_KEY_IDX_TS107                7
*/

#define UI_KEY_IDX_TS100                6
#define UI_KEY_IDX_TS101                2
#define UI_KEY_IDX_TS102                1
#define UI_KEY_IDX_TS103                4
#define UI_KEY_IDX_TS104                3
#define UI_KEY_IDX_TS105                0
#define UI_KEY_IDX_TS106                5
#define UI_KEY_IDX_TS107                7

#define SER_BIT_BTN_V                   0x01
#define SER_BIT_BTN_X                   0x02
#define SER_BIT_BTN_UP                  0x10
#define SER_BIT_BTN_DOWN                0x20
#define SER_BIT_BTN_LEFT                0x40
#define SER_BIT_BTN_RGHT                0x80


                app_t                   app;
                UART_HandleTypeDef      huart1;
extern  CONST   TSL_TouchKeyB_T         MyTKeysB[];


static void MX_GPIO_Init(void)
{
        __HAL_RCC_GPIOF_CLK_ENABLE();
        __HAL_RCC_GPIOA_CLK_ENABLE();
        __HAL_RCC_GPIOB_CLK_ENABLE();
}


static
void MX_USART1_UART_Init(void)
{
        huart1.Instance                         = USART1;
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
                app_error( __FILE__, __LINE__ );
        }
}


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


static
void    app_test_loop(                  const   uint32_t        delay_msec )
{
        uint8_t                 mask;
        int                     count_msec      = 0;


        while( 1 )
        {
                if( app.evt.tick_1msec )
                {
                        app.evt.tick_1msec      = false;

                        count_msec++;

                        if( count_msec >= delay_msec )
                        {
                                count_msec      = 0;

                                mask    <<= 1;

                                if( (mask & 0xFF) == 0 )
                                {
                                        mask    = 1;
                                }

                                HAL_UART_Transmit( &huart1, &mask, 1, 1 );

                                //printf( "%02X\n", mask );
                        }
                } //if( app.evt.tick_1msec )
        } //while( 1 )
}


static
void    app_test1_loop( void )
{
        uint8_t                 mask            = 0;
        bool                    xmit_rqst       = false;


        while( 1 )
        {
                if( app.evt.tick_1msec )
                {
                        app.evt.tick_1msec      = false;

                        ui_key_ts_hook();

                        if( app.evt.key_ts100 )
                        {
                                app.evt.key_ts100       =   false;

                                switch( ui_key_ts100_status() )
                                {
                                        case UI_KEY_STS_PUSH:
                                                mask            |=  SER_BIT_BTN_UP;
                                                xmit_rqst       =   true;
                                                break;

                                        case UI_KEY_STS_HOLD:
                                                mask            |=  SER_BIT_BTN_UP;
                                                xmit_rqst       =   true;
                                                break;

                                        case UI_KEY_STS_RELEASE:
                                                mask            &=  ~SER_BIT_BTN_UP;
                                                xmit_rqst       =   true;
                                                break;

                                        default:
                                                xmit_rqst       =   false;
                                                break;
                                }
                        }

                        if( xmit_rqst )
                        {
                                xmit_rqst       =   false;
                                printf( "%02X\n", mask );
                                HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                                mask    =   0;
                        }
                } //if( app.evt.tick_1msec )
        }
}


/**
  * @brief  The application entry point.
  *
  * @retval None
  */
int main( void )
{
        uint8_t                 mask            = 0;
        bool                    xmit_rqst       = false;


        HAL_Init();
        app_clock_config();

        ui_led_pwr_init();
        ui_led_pwr_set( true );
        ui_led_ts_init();

        ui_led_ts_startup( 250 );

        MX_GPIO_Init();
        MX_USART1_UART_Init();

        ui_key_ts_init();

        //app_test_loop( 50 );
        //app_test1_loop();


        while( 1 )
        {
                if( app.evt.tick_1msec )
                {
                        app.evt.tick_1msec      = false;
                        ui_key_ts_hook();
                } //if( app.evt.tick_1msec )


                if( app.evt.key_ts100 )
                {
                        app.evt.key_ts100       =   false;

                        switch( ui_key_ts100_status() )
                        {
                                case UI_KEY_STS_PUSH:           mask    =  SER_BIT_BTN_UP;      break;
                                case UI_KEY_STS_HOLD:           mask    =  SER_BIT_BTN_UP;      break;
                                case UI_KEY_STS_RELEASE:        mask    =  0;                   break;
                                default:
                                        break;
                        }

                        HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                } //if( app.evt.key_ts100 )


                if( app.evt.key_ts101 )
                {
                        app.evt.key_ts101       =   false;

                        switch( ui_key_ts101_status() )
                        {
                                case UI_KEY_STS_PUSH:           mask    =  SER_BIT_BTN_X;       break;
                                case UI_KEY_STS_HOLD:           mask    =  SER_BIT_BTN_X;       break;
                                case UI_KEY_STS_RELEASE:        mask    =  0;                   break;
                                default:
                                        break;
                        }

                        HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                } //if( app.evt.key_ts101 )


                if( app.evt.key_ts102 )
                {
                        app.evt.key_ts102       =   false;

                        switch( ui_key_ts102_status() )
                        {
                                case UI_KEY_STS_PUSH:           mask    = SER_BIT_BTN_LEFT;     break;
                                case UI_KEY_STS_HOLD:           mask    = SER_BIT_BTN_LEFT;     break;
                                case UI_KEY_STS_RELEASE:        mask    = 0;                    break;
                                default:
                                        break;
                        }

                        HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                } //if( app.evt.key_ts102 )


                if( app.evt.key_ts103 )
                {
                        app.evt.key_ts103       =   false;

                        switch( ui_key_ts103_status() )
                        {
                                case UI_KEY_STS_PUSH:           mask    = SER_BIT_BTN_RGHT;     break;
                                case UI_KEY_STS_HOLD:           mask    = SER_BIT_BTN_RGHT;     break;
                                case UI_KEY_STS_RELEASE:        mask    = 0;                    break;
                                default:
                                        break;
                        }

                        HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                } //if( app.evt.key_ts103 )


                if( app.evt.key_ts104 )
                {
                        app.evt.key_ts104       =   false;

                        switch( ui_key_ts104_status() )
                        {
                                case UI_KEY_STS_PUSH:           mask    =  SER_BIT_BTN_DOWN;    break;
                                case UI_KEY_STS_HOLD:           mask    =  SER_BIT_BTN_DOWN;    break;
                                case UI_KEY_STS_RELEASE:        mask    =  0;                   break;
                                default:
                                        break;
                        }

                        HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                } //if( app.evt.key_ts104 )


                if( app.evt.key_ts105 )
                {
                        app.evt.key_ts105       =   false;

                        switch( ui_key_ts105_status() )
                        {
                                case UI_KEY_STS_PUSH:           mask    =  SER_BIT_BTN_V;       break;
                                case UI_KEY_STS_HOLD:           mask    =  SER_BIT_BTN_V;       break;
                                case UI_KEY_STS_RELEASE:        mask    =  0;                   break;
                                default:
                                        break;
                        }

                        HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                } //if( app.evt.key_ts105 )

/*
                if( xmit_rqst )
                {
                        xmit_rqst       =   false;

                        //HAL_UART_Transmit( &huart1, &mask, 1, 1 );
                        mask    =   0;
                }
*/

        }
}


/**
  * @brief  This function is executed in case of error occurrence.
  * @param  file: The file name as string.
  * @param  line: The line in file as a number.
  * @retval None
  */
/*
void _Error_Handler(char *file, int line)
{
  while(1)
  {
  }
}
*/
