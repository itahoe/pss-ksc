/**
  * @file    bsp_key_ts.h
  * @brief   Board Support Package - Keys Touch Sense services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


//#include	<string.h>
#include	"bsp_key.h"
//#include	"bsp.h"


        TSC_HandleTypeDef       htsc;


/**
 * @brief KEY initialization
 */
void    bsp_key_ts_init( void )
{
        htsc.Instance                           = TSC;
        htsc.Init.CTPulseHighLength             = TSC_CTPH_2CYCLES;
        htsc.Init.CTPulseLowLength              = TSC_CTPL_2CYCLES;
        htsc.Init.SpreadSpectrum                = DISABLE;
        htsc.Init.SpreadSpectrumDeviation       = 1;
        htsc.Init.SpreadSpectrumPrescaler       = TSC_SS_PRESC_DIV1;
        htsc.Init.PulseGeneratorPrescaler       = TSC_PG_PRESC_DIV4;
        htsc.Init.MaxCountValue                 = TSC_MCV_8191;
        htsc.Init.IODefaultMode                 = TSC_IODEF_OUT_PP_LOW;
        htsc.Init.SynchroPinPolarity            = TSC_SYNC_POLARITY_FALLING;
        htsc.Init.AcquisitionMode               = TSC_ACQ_MODE_NORMAL;
        htsc.Init.MaxCountInterrupt             = DISABLE;
        htsc.Init.ChannelIOs                    = TSC_GROUP1_IO3|TSC_GROUP1_IO4|TSC_GROUP2_IO2|TSC_GROUP2_IO3|TSC_GROUP2_IO4|TSC_GROUP4_IO2|TSC_GROUP4_IO3|TSC_GROUP4_IO4;
        htsc.Init.ShieldIOs                     = TSC_GROUP5_IO1;
        htsc.Init.SamplingIOs                   = TSC_GROUP1_IO1|TSC_GROUP2_IO1|TSC_GROUP4_IO1|TSC_GROUP5_IO2;
        if( HAL_TSC_Init( &htsc ) != HAL_OK )
        {
                //_Error_Handler( __FILE__, __LINE__ );
                app_error( __FILE__, __LINE__ );
        }
}


/**
 * @brief KEY get.
 */
bool    bsp_key_ts_get( void )
{
        return( false );
}

/**
 * @brief KEY set
 */
void	bsp_key_ts_set(        const   bool                    val )
{
}

