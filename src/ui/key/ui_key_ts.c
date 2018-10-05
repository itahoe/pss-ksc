/**
  * @file    ui_key_ts.c
  * @brief   User Interface - Key TouchSense services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include <string.h>
#include "ui_led.h"
#include "ui_key.h"
#include "bsp_key.h"


static  ui_key_t        ui_key_ts_100   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_101   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_102   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_103   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_104   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_105   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_106   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_107   =   {   .status         = UI_KEY_STS_NONE,
                                                .tick           = 0 };




/*
ui_key_s
{
	ui_key_status_t         status;
	size_t                  tick;
}	;
*/

/**
 * @brief KEY initialization.
 */
void	ui_key_ts_init( void )
{
        bsp_key_ts_init();
        tsl_user_Init();
        //ui_key_init();
}


/**
 * @brief Key hook.
 */
bool	ui_key_ts100_hook(              bool            forced )
{
	return( ui_key_hook( &ui_key_ts_100, forced ) );
}


/**
 * @brief Key hook.
 */
bool	ui_key_ts101_hook(              const   bool            forced )
{
	return( ui_key_hook( &ui_key_ts_101, forced ) );
}

/**
 * @brief Key hook.
 */
bool	ui_key_ts102_hook(              const   bool            forced )
{
	return( ui_key_hook( &ui_key_ts_102, forced ) );
}

/**
 * @brief Key hook.
 */
bool	ui_key_ts103_hook(              const   bool            forced )
{
	return( ui_key_hook( &ui_key_ts_103, forced ) );
}

/**
 * @brief Key hook.
 */
bool	ui_key_ts104_hook(              const   bool            forced )
{
	return( ui_key_hook( &ui_key_ts_104, forced ) );
}

/**
 * @brief Key hook.
 */
bool	ui_key_ts105_hook(              const   bool            forced )
{
	return( ui_key_hook( &ui_key_ts_105, forced ) );
}

/**
 * @brief Key hook.
 */
bool	ui_key_ts106_hook(              const   bool            forced )
{
	return( ui_key_hook( &ui_key_ts_106, forced ) );
}

/**
 * @brief Key hook.
 */
bool	ui_key_ts107_hook(              const   bool            forced )
{
	return( ui_key_hook( &ui_key_ts_107, forced ) );
}


ui_key_status_t ui_key_ts100_status( void )
{
	return( ui_key_ts_107.status );
}
