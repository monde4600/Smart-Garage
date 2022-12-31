/******************************************************************
   -	.h
   - Created: /5/2022
   - Author:  Magdy
   - Version : V01
 *****************************************************************/
#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

#include "SPI_private.h"



void SPI_vInit(void);
u8 SPI_u8SendRecive(SPI_t* SPI_ptrIndex,u8 Copy_u8Data);


#define SPI1   ((SPI_t*)(SPI1_BASE_ADDRESS))
#define SPI2   ((SPI_t*)(SPI2_BASE_ADDRESS))
#define SPI3   ((SPI_t*)(SPI3_BASE_ADDRESS))
#define SPI4   ((SPI_t*)(SPI4_BASE_ADDRESS))


#endif
