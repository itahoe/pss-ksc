/**
  * @file    app.h
  * @brief   Application
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  APP_H
#define  APP_H


#include <stdint.h>
#include <stdbool.h>


typedef	union	app_event_u
{
	uint16_t				whole;
	struct
	{
		bool            ui_key_ts100    :    1;
		bool            ui_key_ts101    :    1;
		bool            ui_key_ts102    :    1;
		bool            ui_key_ts103    :    1;
		bool            ui_key_ts104    :    1;
		bool            ui_key_ts105    :    1;
		bool            ui_key_ts106    :    1;
		bool            ui_key_ts107    :    1;
		bool                            :    0;
	};
}	app_event_t;

typedef	struct	app_s
{
	app_event_t     evt;
}	app_t;


void _Error_Handler(char *, int);

#define Error_Handler() _Error_Handler(__FILE__, __LINE__)

#endif //APP_H
