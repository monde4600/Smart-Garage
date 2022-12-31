/*
 * SSG_prog.c
 *
 *  Created on: Nov 21, 2022
 *      Author: abano
 */
#include "STD_TYPES.h"
#include "Delay_interface.h"

#include "GPIO_interface.h"


#include "SSG_config.h"
#include "SSG_priv.h"
#include "SSG_int.h"
const u8 SSD_Au8_ControlePins[7]=SSG_PINS;
const u8 SSD_Au8_ControlePorts[7]=SSG_PORTS;
void H_SSD_Init(void)
{
	u8 Local_u8_Iterator;
	for(Local_u8_Iterator=0 ;Local_u8_Iterator<7 ;Local_u8_Iterator++)
	{
		//M_DIO_Void_SetPinDirection(Local_Au8_RowPins[Local_u8_Iterator],OUTPUT);
		MGPIO_vSetPinMode	   (SSD_Au8_ControlePorts[Local_u8_Iterator], SSD_Au8_ControlePins[Local_u8_Iterator], _MODE_OUTPUT);
		MGPIO_vSetPullType	   (SSD_Au8_ControlePorts[Local_u8_Iterator], SSD_Au8_ControlePins[Local_u8_Iterator], _PULL_OFF);
		MGPIO_vSetPinOutPutType(SSD_Au8_ControlePorts[Local_u8_Iterator], SSD_Au8_ControlePins[Local_u8_Iterator], PUSH_PULL);
		MGPIO_vSetPinOutSpeed  (SSD_Au8_ControlePorts[Local_u8_Iterator], SSD_Au8_ControlePins[Local_u8_Iterator], _OUTPUT_SPEED_MEDUIM);
		MGPIO_vWriteDataDIR(SSD_Au8_ControlePorts[Local_u8_Iterator], SSD_Au8_ControlePins[Local_u8_Iterator],LOW);
	}
}

void H_SSD_DisplayInteger(u16 Copy_u16_Nomber)
{
	u8 cat_seg[]={0x3f,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0X07,0x7F,0x6F,0x77,0x7C
					,0x39,0x5E,0x79,0x71};

	u8 Local_u8_Iterator;
	for(Local_u8_Iterator=0 ;Local_u8_Iterator<7 ;Local_u8_Iterator++)
	{
		MGPIO_vWriteDataDIR(SSD_Au8_ControlePorts[Local_u8_Iterator], SSD_Au8_ControlePins[Local_u8_Iterator],(cat_seg[Copy_u16_Nomber]>>Local_u8_Iterator)&1);
	}
}
