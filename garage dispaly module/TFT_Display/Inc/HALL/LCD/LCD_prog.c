/*
 * LCD_prog.c
 *
 *  Created on: Jun 4, 2022
 *      Author: Ahmed El-Gaafrawy
 */
#include "STD_TYPES.h"
#include "Delay_interface.h"

#include "GPIO_interface.h"


#include "LCD_config.h"
#include "LCD_priv.h"


//#include <util/delay.h>


ES_t LCD_enuInit(void)
{

	ES_t Local_enuErrorState = ES_NOK;
	Delay_vMsIn16MHz(35);

	//DIO_enuSetPinDirection(RS_GRP , RS_PIN , DIO_u8OUTPUT);
	MGPIO_vSetPinMode(RS_GRP , RS_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(RS_GRP , RS_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed(RS_GRP , RS_PIN , _OUTPUT_SPEED_MEDUIM);
	//DIO_enuSetPinDirection(RW_GRP , RW_PIN , DIO_u8OUTPUT);
	MGPIO_vSetPinMode(RW_GRP , RW_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(RW_GRP , RW_PIN, PUSH_PULL);
	MGPIO_vSetPinOutSpeed(RW_GRP , RW_PIN, _OUTPUT_SPEED_MEDUIM);


	//DIO_enuSetPinDirection(EN_GRP , EN_PIN , DIO_u8OUTPUT);
	MGPIO_vSetPinMode      (EN_GRP , EN_PIN, _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(EN_GRP , EN_PIN, PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (EN_GRP , EN_PIN, _OUTPUT_SPEED_MEDUIM);



	//DIO_enuSetPinDirection(D7_GRP , D7_PIN , DIO_u8OUTPUT);
	MGPIO_vSetPinMode      (D7_GRP , D7_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D7_GRP , D7_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D7_GRP , D7_PIN , _OUTPUT_SPEED_MEDUIM);

	MGPIO_vSetPinMode      (D6_GRP , D6_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D6_GRP , D6_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D6_GRP , D6_PIN , _OUTPUT_SPEED_MEDUIM);

	MGPIO_vSetPinMode      (D5_GRP , D5_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D5_GRP , D5_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D5_GRP , D5_PIN , _OUTPUT_SPEED_MEDUIM);

	MGPIO_vSetPinMode      (D4_GRP , D4_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D4_GRP , D4_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D4_GRP , D4_PIN , _OUTPUT_SPEED_MEDUIM);





	//DIO_enuSetPinDirection(D6_GRP , D6_PIN , DIO_u8OUTPUT);
	                                                                  //DIO_enuSetPinDirection(D5_GRP , D5_PIN , DIO_u8OUTPUT);

	//DIO_enuSetPinDirection(D4_GRP , D4_PIN , DIO_u8OUTPUT);

#if LCD_MODE == EIGHT_BIT
/*
	DIO_enuSetPinDirection(D3_GRP , D3_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D2_GRP , D2_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D1_GRP , D1_PIN , DIO_u8OUTPUT);
	DIO_enuSetPinDirection(D0_GRP , D0_PIN , DIO_u8OUTPUT);*/

	MGPIO_vSetPinMode      (D3_GRP , D3_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D3_GRP , D3_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D3_GRP , D3_PIN , _OUTPUT_SPEED_MEDUIM);

	MGPIO_vSetPinMode      (D2_GRP , D2_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D2_GRP , D2_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D2_GRP , D2_PIN , _OUTPUT_SPEED_MEDUIM);

	MGPIO_vSetPinMode      (D1_GRP , D1_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D1_GRP , D1_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D1_GRP , D1_PIN , _OUTPUT_SPEED_MEDUIM);

	MGPIO_vSetPinMode      (D0_GRP , D0_PIN , _MODE_OUTPUT);
	MGPIO_vSetPinOutPutType(D0_GRP , D0_PIN , PUSH_PULL);
	MGPIO_vSetPinOutSpeed  (D0_GRP , D0_PIN , _OUTPUT_SPEED_MEDUIM);

	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN ,LOW);
	LCD_enuWriteNLatch(0x38);

#elif LCD_MODE == FOUR_BIT
	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN ,LOW);

	MGPIO_vWriteDataDIR(D7_GRP , D7_PIN ,  0 );
	MGPIO_vWriteDataDIR(D6_GRP , D6_PIN ,  0 );
	MGPIO_vWriteDataDIR(D5_GRP , D5_PIN ,  1 );
	MGPIO_vWriteDataDIR(D4_GRP , D4_PIN ,  0 );

	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,HIGH );
	//_delay_ms (5);
	Delay_vMsIn16MHz(2);
	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,LOW );
	//_delay_ms (5);
	Delay_vMsIn16MHz(2);
	LCD_enuWriteNLatch(0x2C);

#else
#error "LCD mode is wrong ya 7ayawan"
#endif

	//display control
	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , LOW);
	LCD_enuWriteNLatch(0x0D);

	//clear display control
	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , LOW);
	LCD_enuWriteNLatch(0x1);

	//entry set
	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , LOW);
	LCD_enuWriteNLatch(0x6);

	return Local_enuErrorState;
}

ES_t LCD_enuSendData(u8 Copy_u8Data)
{
	ES_t Local_enuErrorState = ES_NOK;

	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
	LCD_enuWriteNLatch(Copy_u8Data);

	return Local_enuErrorState;
}

ES_t LCD_enuSendCommand(u8 Copy_u8Cmnd)
{
	ES_t Local_enuErrorState = ES_NOK;

	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , LOW);
	//SEND DATA & LATCH
	LCD_enuWriteNLatch(Copy_u8Cmnd);

	return Local_enuErrorState;
}

ES_t LCD_enuSendString(const char * Copy_pcString)
{
	if (Copy_pcString != 0)
	{
		while (*Copy_pcString)
		{
			MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
			LCD_enuWriteNLatch(*Copy_pcString++);
		}
		return ES_OK ;
	}
	else return ES_NULL_POINTER ;
}

ES_t LCD_enuGoToPosition(u8 Copy_u8Row , u8 Copy_u8Column)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_u8Column>15)	return Local_enuErrorState = ES_OUT_OF_RANGE;

	if((Copy_u8Row!=LCD_ROW_0) && (Copy_u8Row!=LCD_ROW_1))		return Local_enuErrorState = ES_OUT_OF_RANGE;

	u8 Copy_u8Position = Copy_u8Row + Copy_u8Column;

	MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , LOW);
		//SEND DATA & LATCH
	LCD_enuWriteNLatch(Copy_u8Position);
	Local_enuErrorState= ES_OK;
	return Local_enuErrorState;

}


ES_t LCD_enuSendIntegerNum (s32 Copy_s32Num)
{
	u8 copy_u8digits[10];
	if(Copy_s32Num<0)
	{
		MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
		LCD_enuWriteNLatch('-');
		Copy_s32Num*=-1;
	}
	else if(0==Copy_s32Num)
	{
		MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
		LCD_enuWriteNLatch('0');
		return ES_OK ;
	}
	u8 Copy_u8DigCount=0;
	while(Copy_s32Num)
	{
		copy_u8digits[Copy_u8DigCount++] = Copy_s32Num % 10;
		Copy_s32Num /= 10;
	}
	//Copy_s8DigCount--;
	for(;Copy_u8DigCount>0;Copy_u8DigCount--)
	{
		MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
		LCD_enuWriteNLatch('0'+copy_u8digits[Copy_u8DigCount-1]);
		/*switch(copy_u8digits[Copy_s8DigCount])
		{
			case 0:
				LCD_enuWriteNLatch('0');
				break;
			case 1:
				LCD_enuWriteNLatch('1');
				break;
			case 2:
				LCD_enuWriteNLatch('2');
				break;
			case 3:
				LCD_enuWriteNLatch('3');
				break;
			case 4:
				LCD_enuWriteNLatch('4');
				break;
			case 5:
				LCD_enuWriteNLatch('5');
				break;
			case 6:
				LCD_enuWriteNLatch('6');
				break;
			case 7:
				LCD_enuWriteNLatch('7');
				break;
			case 8:
				LCD_enuWriteNLatch('8');
				break;
			case 9:
				LCD_enuWriteNLatch('9');
				break;

		}*/
	}
	return ES_OK;
}

ES_t LCD_enuSendFloatNum (f32 Copy_f32Num)
{
	u64 Copy_u64Num;
	u8 copy_u8digits[10];
	if(Copy_f32Num<0)
	{
		MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
		LCD_enuWriteNLatch('-');
		Copy_f32Num*=-1000;
	}
	else if(0==Copy_f32Num)
	{
		MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
		LCD_enuWriteNLatch('0');
		return ES_OK ;
	}
	else	Copy_f32Num*=1000;

	Copy_u64Num = Copy_f32Num;

	u8 Copy_u8DigCount=0;
	while(Copy_u64Num)
	{
		copy_u8digits[Copy_u8DigCount++] = Copy_u64Num % 10;
		Copy_u64Num /= 10;
	}
	//Copy_s8DigCount--;
	for(;Copy_u8DigCount>0;Copy_u8DigCount--)
	{

		MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
		LCD_enuWriteNLatch('0'+copy_u8digits[Copy_u8DigCount-1]);
		/*switch(copy_u8digits[Copy_s8DigCount])
		{
			case 0:
				LCD_enuWriteNLatch('0');
				break;
			case 1:
				LCD_enuWriteNLatch('1');
				break;
			case 2:
				LCD_enuWriteNLatch('2');
				break;
			case 3:
				LCD_enuWriteNLatch('3');
				break;
			case 4:
				LCD_enuWriteNLatch('4');
				break;
			case 5:
				LCD_enuWriteNLatch('5');
				break;
			case 6:
				LCD_enuWriteNLatch('6');
				break;
			case 7:
				LCD_enuWriteNLatch('7');
				break;
			case 8:
				LCD_enuWriteNLatch('8');
				break;
			case 9:
				LCD_enuWriteNLatch('9');
				break;

		}*/
		if(4==Copy_u8DigCount)
		{
			MGPIO_vWriteDataDIR(RS_GRP , RS_PIN , HIGH);
			LCD_enuWriteNLatch('.');
		}
	}
	return ES_OK;
}

static ES_t LCD_enuWriteNLatch(u8 Copy_u8Byte)
{
	MGPIO_vWriteDataDIR( RW_GRP , RW_PIN , LOW); //RW
	MGPIO_vWriteDataDIR( EN_GRP , EN_PIN , LOW); //EN

#if LCD_MODE == EIGHT_BIT

	MGPIO_vWriteDataDIR(D7_GRP , D7_PIN ,  ((Copy_u8Byte >> 7) & 1) );
	MGPIO_vWriteDataDIR(D6_GRP , D6_PIN ,  ((Copy_u8Byte >> 6) & 1) );
	MGPIO_vWriteDataDIR(D5_GRP , D5_PIN ,  ((Copy_u8Byte >> 5) & 1) );
	MGPIO_vWriteDataDIR(D4_GRP , D4_PIN ,  ((Copy_u8Byte >> 4) & 1) );
	MGPIO_vWriteDataDIR(D3_GRP , D3_PIN ,  ((Copy_u8Byte >> 3) & 1) );
	MGPIO_vWriteDataDIR(D2_GRP , D2_PIN ,  ((Copy_u8Byte >> 2) & 1) );
	MGPIO_vWriteDataDIR(D1_GRP , D1_PIN ,  ((Copy_u8Byte >> 1) & 1) );
	MGPIO_vWriteDataDIR(D0_GRP , D0_PIN ,  ((Copy_u8Byte >> 0) & 1) );


	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,  HIGH );
	Delay_vMsIn16MHz(2);
	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,  LOW );
	Delay_vMsIn16MHz(2);


#elif LCD_MODE == FOUR_BIT

	MGPIO_vWriteDataDIR(D7_GRP , D7_PIN ,  ((Copy_u8Byte >> 7) & 1) );
	MGPIO_vWriteDataDIR(D6_GRP , D6_PIN ,  ((Copy_u8Byte >> 6) & 1) );
	MGPIO_vWriteDataDIR(D5_GRP , D5_PIN ,  ((Copy_u8Byte >> 5) & 1) );
	MGPIO_vWriteDataDIR(D4_GRP , D4_PIN ,  ((Copy_u8Byte >> 4) & 1) );

	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,  DIO_u8HIGH );
	//_delay_ms (2);
	Delay_vMsIn16MHz(2);
	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,  DIO_u8LOW );
	//_delay_ms (2);
	Delay_vMsIn16MHz(2);

	MGPIO_vWriteDataDIR(D7_GRP , D7_PIN ,  ((Copy_u8Byte >> 3) & 1) );
	MGPIO_vWriteDataDIR(D6_GRP , D6_PIN ,  ((Copy_u8Byte >> 2) & 1) );
	MGPIO_vWriteDataDIR(D5_GRP , D5_PIN ,  ((Copy_u8Byte >> 1) & 1) );
	MGPIO_vWriteDataDIR(D4_GRP , D4_PIN ,  ((Copy_u8Byte >> 0) & 1) );


	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,  DIO_u8HIGH );
	//_delay_ms (2);
	Delay_vMsIn16MHz(2);
	MGPIO_vWriteDataDIR(EN_GRP , EN_PIN ,  DIO_u8LOW );
	//_delay_ms (2);
	Delay_vMsIn16MHz(2);
#else
#error "LCD mode is wrong ya 7ayawan"
#endif
	return ES_OK;
}


