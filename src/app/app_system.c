/**
  * @file    bsp_system.c
  * @brief   System Routins
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#include "app.h"
#include "bsp.h"


void app_system_reset( void )
{
        NVIC_SystemReset();
}
