/**
 * @file ui_key.h
 *
 *
 * @author Igor T. (aka Tahoe) <office.tahoe@gmail.com>
 */


#ifndef  UI_KEY_H
#define  UI_KEY_H


#include <stdbool.h>
#include <stdint.h>
#include <string.h>
#include "tsl_conf.h"
#include "tsl_user.h"
#include "config.h"
#include "bsp.h"


#define	UI_SYSTICK_HZ                           BSP_SYSTICK_HZ

#define	UI_KEY_DEBOUNCE_TCKS                    ( ((uint32_t) CFG_UI_KEY_DEBOUNCE_mSEC * UI_SYSTICK_HZ) / 1000 )
#define	UI_KEY_SHRT_TCKS                        ( ((uint32_t) CFG_UI_KEY_SHRT_MAX_mSEC * UI_SYSTICK_HZ) / 1000 )
#define	UI_KEY_LONG_TCKS                        ( ((uint32_t) CFG_UI_KEY_LONG_MAX_mSEC * UI_SYSTICK_HZ) / 1000 )
#define	UI_KEY_REPEAT_TCKS                      ( ((uint32_t) CFG_UI_KEY_REPEAT_MAX_mSEC * UI_SYSTICK_HZ) / 1000 )


typedef    bool ( * ui_key_get_t )( void );


typedef	enum	ui_key_status_e
{
	UI_KEY_STS_NONE,
	UI_KEY_STS_SHORT,
	UI_KEY_STS_LONG,
	UI_KEY_STS_REPEAT,
	UI_KEY_STS_RELEASE,
}	ui_key_status_t;

typedef	struct	ui_key_s
{
	ui_key_status_t         status;
	size_t                  tick;
	ui_key_get_t            get;
}	ui_key_t;

void    ui_key_init( void );

bool    ui_key_hook(                            ui_key_t *      p,
                                        const   bool            forced );

void    ui_key_ts_init( void );

bool	ui_key_ts100_hook(              const   bool            forced );
bool	ui_key_ts101_hook(              const   bool            forced );
bool	ui_key_ts102_hook(              const   bool            forced );
bool	ui_key_ts103_hook(              const   bool            forced );
bool	ui_key_ts104_hook(              const   bool            forced );
bool	ui_key_ts105_hook(              const   bool            forced );
bool	ui_key_ts106_hook(              const   bool            forced );
bool	ui_key_ts107_hook(              const   bool            forced );

ui_key_status_t ui_key_ts100_status( void );
ui_key_status_t ui_key_ts101_status( void );
ui_key_status_t ui_key_ts102_status( void );
ui_key_status_t ui_key_ts103_status( void );
ui_key_status_t ui_key_ts104_status( void );
ui_key_status_t ui_key_ts105_status( void );
ui_key_status_t ui_key_ts106_status( void );
ui_key_status_t ui_key_ts107_status( void );

#endif	//UI_KEY_H
