/**
  * @file    ui_led.h
  * @brief   User Interface - LED Services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  UI_LED_H
#define  UI_LED_H


#include	<stdint.h>
#include	<stdbool.h>
#include	<string.h>
#include	"config.h"
#include	"bsp_led.h"


//#define	UI_LED_FLSH_SHRT_TCKS   ( ((uint32_t) CFG_UI_LED_FLSH_SHRT_mSEC * UI_SYSTICK_HZ) / 1000 )
//#define	UI_LED_FLSH_LONG_TCKS   ( ((uint32_t) CFG_UI_LED_FLSH_LONG_mSEC * UI_SYSTICK_HZ) / 1000 )

#define	UI_LED_FLSH_SHRT_TCKS   ( ((size_t) CFG_UI_LED_FLSH_SHRT_mSEC * BSP_SYSTICK_HZ) / 1000 )
#define	UI_LED_FLSH_LONG_TCKS   ( ((size_t) CFG_UI_LED_FLSH_LONG_mSEC * BSP_SYSTICK_HZ) / 1000 )

/*
#define UI_LED_TS100            0x08
#define UI_LED_TS101            0x40
#define UI_LED_TS102            0x80
#define UI_LED_TS103            0x04
#define UI_LED_TS104            0x20
#define UI_LED_TS105            0x01
#define UI_LED_TS106            0x02
#define UI_LED_TS107            0x10
*/
#define UI_LED_TS100            0x08
#define UI_LED_TS101            0x04
#define UI_LED_TS102            0x01
#define UI_LED_TS103            0x80
#define UI_LED_TS104            0x10
#define UI_LED_TS105            0x20
#define UI_LED_TS106            0x40
#define UI_LED_TS107            0x02


typedef    void ( * ui_led_init_t )( void );
typedef    bool ( * ui_led_get_t )( void );
typedef    void ( * ui_led_set_t )(     const   bool    b );


typedef	struct	ui_led_s
{
	ui_led_init_t           init;
	ui_led_set_t            set;
	ui_led_get_t            get;
	size_t                  tick;
} ui_led_t;


void	ui_led_init(                    ui_led_t *              p );

bool ui_led_hook(                       ui_led_t *              p );

void ui_led_toggle(                     ui_led_t *              p );

void ui_led_set(                        ui_led_t *              p,
                                const   bool                    mode );

void ui_led_flash(                      ui_led_t *              p,
                                        size_t                  len );



void ui_led_pwr_init( void );

bool ui_led_pwr_hook( void );

void ui_led_pwr_set(                    const   bool                    val );

void ui_led_pwr_flash(                  const   size_t                  len );

void ui_led_ts_init( void );

void ui_led_ts_set(                     const   uint8_t                 val );

void ui_led_ts_startup(                 const   uint32_t                delay );


#endif	//UI_LED_H
