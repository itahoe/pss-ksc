/**
  * @file    ui_key_ts.c
  * @brief   User Interface - Key TouchSense services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include <string.h>
#include "ui_key.h"
#include "bsp_key.h"


/**
 * @brief User Interface Keys initialization.
 */
void	ui_key_init( void )
{
	//memset( p, 0, sizeof(ui_key_t) );
	//bsp_key_init();

        //MX_TSC_Init();
        bsp_key_ts_init();
        tsl_user_Init();
}


/**
 * @brief User Interface Key hook.
 */
bool	ui_key_hook(                    ui_key_t *      p,
                                const   bool            forced )
{
	bool    resp    =    false;
	//bool    forced  =    bsp_key_get();
	//bool    forced  =    false;

	if( forced == true )
	{
		p->tick++;

		if( p->tick == UI_KEY_REPEAT_TCKS )
		{
			p->tick         =    UI_KEY_LONG_TCKS;
			p->status       =    UI_KEY_STS_REPEAT;
			resp            =    true;
		}
	}
	else
	{
		if( p->tick > 0 )
		{
			p->status       =    p->tick < UI_KEY_DEBOUNCE_TCKS ? UI_KEY_STS_NONE :
			                         p->tick < UI_KEY_SHRT_TCKS     ? UI_KEY_STS_SHORT :
			                             p->tick < UI_KEY_LONG_TCKS     ? UI_KEY_STS_LONG : UI_KEY_STS_RELEASE;
			p->tick		=	0;

			if( p->status > UI_KEY_STS_NONE )
			{
				resp            =    true;
			}
		}
	}

	return( resp );
}
