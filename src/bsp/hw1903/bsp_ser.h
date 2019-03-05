/**
  * @file    bsp_mcu.h
  * @brief   BSP - MCU services
  * @author  Igor T. <research.tahoe@gmail.com>
  */


#ifndef  BSP_MCU_H
#define  BSP_MCU_H


#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
//#include "bsp.h"


bool bsp_ser1_init(                     const   size_t                  baud );

void bsp_ser1_isr(                              void );

uint32_t bsp_ser1_dma_recv_ndtr_get(            void );

void bsp_ser1_dma_tx_isr(                       void );

void bsp_ser1_dma_rx_isr(                       void );

bool bsp_ser1_xmit_start(                       uint8_t *               data,
                                                size_t                  size );

uint32_t bsp_ser1_recv_dma_head_get(            void );

bool    bsp_ser1_recv_dma_full_get(             void );

bool    bsp_ser1_sts_idle(                      void );


#endif	//BSP_MCU_H
