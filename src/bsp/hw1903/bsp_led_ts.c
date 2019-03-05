/**
  * @file    bsp_led_ts.c
  * @brief   Board Support Package - LED TouchSense services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include	<string.h>
#include	"bsp_led.h"
#include	"bsp.h"


/**
 * @brief LED GPIO initialization
 */
void bsp_led_ts_init( void )
{
	GPIO_InitTypeDef        pin_mosi    = { .Pin       =    GPIO_PIN_8,
	                                        .Mode      =    GPIO_MODE_OUTPUT_PP,
	                                        .Pull      =    GPIO_NOPULL,
	                                        .Speed     =    GPIO_SPEED_FREQ_LOW };

	GPIO_InitTypeDef        pin_sck     = { .Pin       =    GPIO_PIN_15,
	                                        .Mode      =    GPIO_MODE_OUTPUT_PP,
	                                        .Pull      =    GPIO_NOPULL,
	                                        .Speed     =    GPIO_SPEED_FREQ_LOW };

	GPIO_InitTypeDef        pin_nss     = { .Pin       =    GPIO_PIN_5,
	                                        .Mode      =    GPIO_MODE_OUTPUT_PP,
	                                        .Pull      =    GPIO_NOPULL,
	                                        .Speed     =    GPIO_SPEED_FREQ_LOW };

	GPIO_InitTypeDef        pin_pwm     = { .Pin       =    GPIO_PIN_0,
	                                        .Mode      =    GPIO_MODE_OUTPUT_PP,
	                                        .Pull      =    GPIO_NOPULL,
	                                        .Speed     =    GPIO_SPEED_FREQ_LOW };


	__HAL_RCC_GPIOA_CLK_ENABLE();
	__HAL_RCC_GPIOB_CLK_ENABLE();

	HAL_GPIO_Init( GPIOA, &pin_mosi );
	HAL_GPIO_Init( GPIOA, &pin_sck  );
	HAL_GPIO_Init( GPIOB, &pin_nss  );
	HAL_GPIO_Init( GPIOB, &pin_pwm  );


        HAL_GPIO_WritePin( GPIOB, GPIO_PIN_0, GPIO_PIN_RESET );
}


/**
 * @brief LED state get.
 */
uint8_t bsp_led_ts_get( void )
{
        uint8_t         val     = 0;


	return( val );
}


#define BSP_LED_TS_NSS_FORCE()          HAL_GPIO_WritePin( GPIOB, GPIO_PIN_5, GPIO_PIN_RESET )
#define BSP_LED_TS_NSS_RELEASE()        HAL_GPIO_WritePin( GPIOB, GPIO_PIN_5, GPIO_PIN_SET )

#define BSP_LED_TS_SCK_HIGH()           HAL_GPIO_WritePin( GPIOA, GPIO_PIN_15, GPIO_PIN_SET )
#define BSP_LED_TS_SCK_LOW()            HAL_GPIO_WritePin( GPIOA, GPIO_PIN_15, GPIO_PIN_RESET )

#define BSP_LED_TS_MOSI_SET( data )     HAL_GPIO_WritePin( GPIOA, GPIO_PIN_8, data ? GPIO_PIN_SET : GPIO_PIN_RESET )


/**
 * @brief LED pin set
 */
void	bsp_led_ts_set(                uint8_t                 val )
{

        //BSP_LED_TS_NSS_FORCE();

        for( int i = 0; i < 8; i++ )
        {
                BSP_LED_TS_MOSI_SET( val & 1 );
                //HAL_Delay( 1 );
                BSP_LED_TS_SCK_HIGH();
                //HAL_Delay( 1 );
                BSP_LED_TS_SCK_LOW();
                //HAL_Delay( 1 );
                val     >>=  1;
        }

        BSP_LED_TS_NSS_FORCE();
        //HAL_Delay( 1 );
        BSP_LED_TS_NSS_RELEASE();
}
