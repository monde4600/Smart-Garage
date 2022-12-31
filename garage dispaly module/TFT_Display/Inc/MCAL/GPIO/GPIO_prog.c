/*
 * GPIO_prog.c
 *
 *  Created on: Dec 11, 2022
 *      Author: abano
 */
#include "BIT_MATH.h"
#include "STD_TYPES.h"
#include "GPIO_config.h"
#include "GPIO_private.h"

void MGPIO_vSetPinMode(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_MODE_t Copy_enuMode  )
{
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->MODER &=~((_MODE_ANALOG)<<(Copy_enuPinNum*2));
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->MODER |=(Copy_enuMode)<<(Copy_enuPinNum*2);
}

void MGPIO_vSetPinOutPutType(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_OUT_t Copy_enuOutPutType  )
{
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->OTYPER &=~(OPEN_DRAIN<<Copy_enuPinNum);
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->OTYPER |= Copy_enuOutPutType<<Copy_enuPinNum;
}

void MGPIO_vSetPinOutSpeed(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_SPEED_t Copy_enuOutSpeed )
{
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->OSPEEDR &=~((_OUTPUT_SPEED_VERY_HIGH)<<(Copy_enuPinNum*2));
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->OSPEEDR |=(Copy_enuOutSpeed)<<(Copy_enuPinNum*2);
}
void MGPIO_vSetPullType(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_PULL_t Copy_enuPullType )
{
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->PUPDR &=~((_PULL_reserved)<<(Copy_enuPinNum*2));
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->PUPDR |=(Copy_enuPullType)<<(Copy_enuPinNum*2);
}

GPIO_PIN_STATE_t MGPIO_enuReadData(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum)
{
	return GET_BIT((GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->IDR,Copy_enuPinNum);
}

void MGPIO_vWriteData(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum,GPIO_PIN_STATE_t Copy_enuState)
{
	if(Copy_enuState==_HIGH)
		SET_BIT((GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->ODR,Copy_enuPinNum);
	else
		CLR_BIT((GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->ODR,Copy_enuPinNum);
}
void MGPIO_vWriteDataDIR(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_PIN_STATE_t Copy_enuState)
{
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->BSRR = 1<<(Copy_enuPinNum+16*(!Copy_enuState));
}

void MGPIO_vPinLock(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum )
{
	u32 Local_u16Handeller = (1 << LCKK) |(1 << Copy_enuPinNum);
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->LCKR = Local_u16Handeller;
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->LCKR = (1 << Copy_enuPinNum);
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->LCKR = Local_u16Handeller;
	while(!GET_BIT((GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->LCKR ,LCKK));
}

void MGPIO_vSetPinAltFn(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum, GPIO_ALTFN_MOOD_t Copy_enuALF )
{
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->AFR[Copy_enuPinNum/8] &= ~(_ALTFN_15<<(Copy_enuPinNum*4)%31);
	(GPIO_BASE_ADDRES_TOT + Copy_enuPortName)->AFR[Copy_enuPinNum/8] |= (Copy_enuALF<<(Copy_enuPinNum*4)%31);
}
