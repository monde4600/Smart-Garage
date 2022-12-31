/*
 * Keypad_Prog.c
 *
 *  Created on: ???/???/????
 *      Author: dell
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "GPIO_interface.h"
#include "Keypad_Private.h"
#include "Keypad_Config.h"
#include <Delay_interface.h>
void H_KEYPAD_void_Init(void)
{
	u8 Local_u8_Iterator;
	u8 Local_Au8_ColomsPins [COL_N]=COL_PINS;
	u8 Local_Au8_ColomsPorts [COL_N]=COL_PORTS;

	u8 Local_Au8_RowPins [ROWS_N]=ROW_PINS;
	u8 Local_Au8_RowPorts [ROWS_N]=ROW_PORTS;


	for(Local_u8_Iterator=0 ;Local_u8_Iterator<COL_N ;Local_u8_Iterator++)
	{
		//(Local_Au8_ColomsPins[Local_u8_Iterator],INPUT);
		MGPIO_vSetPinMode(Local_Au8_ColomsPorts[Local_u8_Iterator], Local_Au8_ColomsPins[Local_u8_Iterator], _MODE_INPUT);
		MGPIO_vSetPullType(Local_Au8_ColomsPorts[Local_u8_Iterator], Local_Au8_ColomsPins[Local_u8_Iterator], _PULL_UP);

	}
	for(Local_u8_Iterator=0 ;Local_u8_Iterator<ROWS_N ;Local_u8_Iterator++)
	{
		//M_DIO_Void_SetPinDirection(Local_Au8_RowPins[Local_u8_Iterator],OUTPUT);
		MGPIO_vSetPinMode	   (Local_Au8_RowPorts[Local_u8_Iterator], Local_Au8_RowPins[Local_u8_Iterator], _MODE_OUTPUT);
		MGPIO_vSetPullType	   (Local_Au8_RowPorts[Local_u8_Iterator], Local_Au8_RowPins[Local_u8_Iterator], _PULL_OFF);
		MGPIO_vSetPinOutPutType(Local_Au8_RowPorts[Local_u8_Iterator], Local_Au8_RowPins[Local_u8_Iterator], PUSH_PULL);
		MGPIO_vSetPinOutSpeed  (Local_Au8_RowPorts[Local_u8_Iterator], Local_Au8_RowPins[Local_u8_Iterator], _OUTPUT_SPEED_MEDUIM);

		MGPIO_vWriteDataDIR(Local_Au8_RowPorts[Local_u8_Iterator], Local_Au8_RowPins[Local_u8_Iterator],HIGH);
	}
}
u8 H_KEYPAD_u8_GetPressedKey(u8* Copy_pu8_pressedKey)
{
	u8 Local_u8_COLIterator;
	u8 Local_u8_ROWIterator;

	u8 Local_Au8_ColomsPins [COL_N]=COL_PINS;
	u8 Local_Au8_ColomsPorts [COL_N]=COL_PORTS;
	u8 Local_Au8_RowPins [ROWS_N]=ROW_PINS;
	u8 Local_Au8_RowPorts [ROWS_N]=ROW_PORTS;

	u8 Local_Au8_ButtonsValue[ROWS_N][COL_N] = KEYS_VAL;
	u8 Local_u8_Result = KEPAD_NOTPRESSED;
	for(Local_u8_ROWIterator=0;Local_u8_ROWIterator<ROWS_N; Local_u8_ROWIterator++)
	{
		MGPIO_vWriteDataDIR(Local_Au8_RowPorts[Local_u8_ROWIterator], Local_Au8_RowPins[Local_u8_ROWIterator],LOW);
		for(Local_u8_COLIterator=0;Local_u8_COLIterator<COL_N;Local_u8_COLIterator++)
		{
			if(MGPIO_u8ReadData(Local_Au8_ColomsPorts[Local_u8_COLIterator], Local_Au8_ColomsPins[Local_u8_COLIterator])==LOW)
				do{
					Delay_vMsIn16MHz(KEYPAD_DEBOUNCING_TIME);
					Local_u8_Result =
						Local_Au8_ButtonsValue[Local_u8_ROWIterator][Local_u8_COLIterator];
				}while(MGPIO_u8ReadData(Local_Au8_ColomsPorts[Local_u8_COLIterator], Local_Au8_ColomsPins[Local_u8_COLIterator])==LOW);

		}
		MGPIO_vWriteDataDIR(Local_Au8_RowPorts[Local_u8_ROWIterator], Local_Au8_RowPins[Local_u8_ROWIterator],HIGH);
	}
	*Copy_pu8_pressedKey = Local_u8_Result;
	return Local_u8_Result;
}
