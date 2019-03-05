/**
  * @file    ui_key_ts.c
  * @brief   User Interface - Key TouchSense services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include <string.h>
#include "ui_led.h"
#include "ui_key.h"
#include "bsp_key.h"


#define UI_KEY_TS_FORCED_THLD           20


extern  TSL_ChannelData_T       MyChannels_Data[ TSLPRM_TOTAL_CHANNELS ];



static  ui_key_t        ui_key_ts_100   =   {   .sts    = UI_KEY_STS_IDLE,
                                                .tick   = 0 };

static  ui_key_t        ui_key_ts_101   =   {   .sts    = UI_KEY_STS_IDLE,
                                                .tick   = 0 };

static  ui_key_t        ui_key_ts_102   =   {   .sts    = UI_KEY_STS_IDLE,
                                                .tick   = 0 };

static  ui_key_t        ui_key_ts_103   =   {   .sts    = UI_KEY_STS_IDLE,
                                                .tick   = 0 };

static  ui_key_t        ui_key_ts_104   =   {   .sts    = UI_KEY_STS_IDLE,
                                                .tick   = 0 };

static  ui_key_t        ui_key_ts_105   =   {   .sts    = UI_KEY_STS_IDLE,
                                                .tick   = 0 };


/**
 * @brief KEY initialization.
 */
void	ui_key_ts_init( void )
{
        bsp_key_ts_init();
        tsl_user_Init();
}


void    ui_key_ts_hook( void )
{
        tsl_user_Exec();   // Execute STMTouch Driver state machine
}



static
bool ui_key_ts_100_get( void )
{
        //bool    resp    = (MyLinRots[0].p_Data->StateId == TSL_STATEID_DETECT) ? true : false;
        bool    resp    = (MyChannels_Data[6].Delta > UI_KEY_TS_FORCED_THLD ) ? true : false;

        return( resp );
}


static
bool ui_key_ts_101_get( void )
{
        bool    resp    = (MyChannels_Data[2].Delta > UI_KEY_TS_FORCED_THLD ) ? true : false;

        return( resp );
}


static
bool ui_key_ts_102_get( void )
{
        bool    resp    = (MyChannels_Data[1].Delta > UI_KEY_TS_FORCED_THLD ) ? true : false;

        return( resp );
}


static
bool ui_key_ts_103_get( void )
{
        bool    resp    = (MyChannels_Data[4].Delta > UI_KEY_TS_FORCED_THLD ) ? true : false;

        return( resp );
}


static
bool ui_key_ts_104_get( void )
{
        bool    resp    = (MyChannels_Data[3].Delta > UI_KEY_TS_FORCED_THLD ) ? true : false;

        return( resp );
}


static
bool ui_key_ts_105_get( void )
{
        bool    resp    = (MyChannels_Data[0].Delta > UI_KEY_TS_FORCED_THLD ) ? true : false;

        return( resp );
}


/**
 * @brief Key hook.
 */
bool    ui_key_ts100_hook( void )
{
        bool    forced  = ui_key_ts_100_get();
        bool    rslt    = ui_key_hook( &ui_key_ts_100, forced );

	return( rslt );
}


/**
 * @brief Key hook.
 */
bool    ui_key_ts101_hook( void )
{
        bool    forced  = ui_key_ts_101_get();
        bool    rslt    = ui_key_hook( &ui_key_ts_101, forced );

	return( rslt );
}

/**
 * @brief Key hook.
 */
bool    ui_key_ts102_hook( void )
{
        bool    forced  = ui_key_ts_102_get();
        bool    rslt    = ui_key_hook( &ui_key_ts_102, forced );

	return( rslt );
}

/**
 * @brief Key hook.
 */
bool    ui_key_ts103_hook( void )
{
        bool    forced  = ui_key_ts_103_get();
        bool    rslt    = ui_key_hook( &ui_key_ts_103, forced );

	return( rslt );
}

/**
 * @brief Key hook.
 */
bool    ui_key_ts104_hook( void )
{
        bool    forced  = ui_key_ts_104_get();
        bool    rslt    = ui_key_hook( &ui_key_ts_104, forced );

	return( rslt );
}

/**
 * @brief Key hook.
 */
bool    ui_key_ts105_hook( void )
{
        bool    forced  = ui_key_ts_105_get();
        bool    rslt    = ui_key_hook( &ui_key_ts_105, forced );

	return( rslt );
}

/******************************************************************************/
/* STATUS *********************************************************************/
/******************************************************************************/

ui_key_sts_t
ui_key_ts100_status( void )
{
	return( ui_key_ts_100.sts );
}


ui_key_sts_t
ui_key_ts101_status( void )
{
	return( ui_key_ts_101.sts );
}


ui_key_sts_t
ui_key_ts102_status( void )
{
	return( ui_key_ts_102.sts );
}


ui_key_sts_t
ui_key_ts103_status( void )
{
	return( ui_key_ts_103.sts );
}


ui_key_sts_t
ui_key_ts104_status( void )
{
	return( ui_key_ts_104.sts );
}


ui_key_sts_t
ui_key_ts105_status( void )
{
	return( ui_key_ts_105.sts );
}


/*
static
bool ui_key_ts_left_get( void )
{
        bool    resp;


        //resp    = (MyLinRots[0].p_Data->StateId == TSL_STATEID_DETECT) ? true : false;
        resp    = (MyChannels_Data[2].Delta > 30 ) ? true : false;
        return( resp );
}


static
bool ui_key_ts_rght_get( void )
{
        bool    resp;


        //resp    = (MyLinRots[0].p_Data->StateId == TSL_STATEID_DETECT) ? true : false;
        resp    = (MyChannels_Data[0].Delta > 30 ) ? true : false;
        return( resp );
}


static  ui_key_t        ui_key_ts_left  =   {   //.init           = ui_key_ts_init,
                                                .forced         = ui_key_ts_left_get,
                                                .sts            = UI_KEY_STS_IDLE,
                                                .tick           = 0 };

static  ui_key_t        ui_key_ts_rght  =   {   //.init           = ui_key_ts_init,
                                                .forced         = ui_key_ts_rght_get,
                                                .sts            = UI_KEY_STS_IDLE,
                                                .tick           = 0 };


void	ui_key_ts_init( void )
{
        bsp_tsc_init();
        tsl_user_Init();
}


void    ui_key_ts_hook( void )
{
        tsl_user_Exec();   // Execute STMTouch Driver state machine
}

bool	ui_key_ts_left_hook( void )
{
	return( ui_key_hook_typematic( &ui_key_ts_left ) );
}


bool	ui_key_ts_rght_hook( void )
{
	return( ui_key_hook_typematic( &ui_key_ts_rght ) );
}


ui_key_status_t ui_key_ts_left_status( void )
{
	return( ui_key_ts_left.sts );
}


ui_key_status_t ui_key_ts_rght_status( void )
{
	return( ui_key_ts_rght.sts );
}

*/
