/**
  * @file    bsp_led_pwr.h
  * @brief   Board Support Package - LED services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include	<string.h>
#include	"bsp_led.h"
#include	"bsp.h"


/**
 * @brief LED initialization
 */
void    bsp_led_pwr_init( void )
{
	GPIO_InitTypeDef        gpio_led        =   {    .Pin       =    GPIO_PIN_1,
	                                                 .Mode      =    GPIO_MODE_OUTPUT_PP,
	                                                 .Pull      =    GPIO_NOPULL,
	                                                 .Speed     =    GPIO_SPEED_FREQ_LOW };

	__HAL_RCC_GPIOB_CLK_ENABLE();

	HAL_GPIO_Init( GPIOB, &gpio_led );
}


/**
 * @brief LED get.
 */
bool    bsp_led_pwr_get( void )
{
	return( HAL_GPIO_ReadPin( GPIOB, GPIO_PIN_1 ) ? true : false );
}

/**
 * @brief LED set
 */
void	bsp_led_pwr_set(        const   bool                    val )
{
        HAL_GPIO_WritePin( GPIOB, GPIO_PIN_1, val ? GPIO_PIN_SET : GPIO_PIN_RESET );
}

