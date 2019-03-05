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
 * @brief       UI Key hook, Non-Typematic version
 */
bool	ui_key_hook(                    ui_key_t *              p,
                                const   bool                    forced )
{
	bool    resp    = false;


        if( forced )
	{
                p->tick++;

                if( p->tick == UI_KEY_LONG_TCKS )
                {
                        p->sts  =    UI_KEY_STS_HOLD;
                        resp    =    true;
                }
	}
	else if( p->tick > 0 )
	{
                p->sts  =   p->tick < UI_KEY_DEBOUNCE_TCKS ? UI_KEY_STS_IDLE:
                                p->tick < UI_KEY_LONG_TCKS     ? UI_KEY_STS_PUSH : UI_KEY_STS_RELEASE;
                p->tick =   0;

		if( p->sts > UI_KEY_STS_IDLE )
                {
                        resp            =    true;
                }
	}

	return( resp );
}


/**
 * @brief       UI Key hook, Typematic version
 */
bool	ui_key_hook_typematic(                  ui_key_t *      p,
                                        const   bool            forced )
{
	bool    resp    = false;


        if( forced )
	{
                p->tick++;

                if(             p->tick == UI_KEY_DEBOUNCE_TCKS )
                {
                        p->sts  =    UI_KEY_STS_PUSH;
                        resp    =    true;
                }
                else if(        p->tick > (UI_KEY_TYPEMATIC_DELAY_TCKS + UI_KEY_TYPEMATIC_RATE_TCKS) )
                {
                        p->tick =    UI_KEY_TYPEMATIC_DELAY_TCKS;
                        p->sts  =    UI_KEY_STS_HOLD;
                        resp    =    true;
                }
	}
	else if( p->tick > 0 )
        {
                p->sts  =   p->tick < UI_KEY_DEBOUNCE_TCKS ? UI_KEY_STS_IDLE : UI_KEY_STS_RELEASE;
                p->tick =   0;

                if( p->sts > UI_KEY_STS_IDLE )
		{
                        resp            =    true;
		}
	}

	return( resp );
}
