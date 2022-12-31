/*
 * GPIO_interface.h
 *
 *  Created on: Dec 11, 2022
 *      Author: abano
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_



typedef enum
{
	_MODE_INPUT =0,
	_MODE_OUTPUT,
	_MODE_ALTF,
	_MODE_ANALOG
}GPIO_MODE_t;

typedef enum
{
	PUSH_PULL = 0U,
	OPEN_DRAIN
}GPIO_OUT_t;

typedef enum
{
	_OUTPUT_SPEED_LOW =0,
	_OUTPUT_SPEED_MEDUIM,
	_OUTPUT_SPEED_HIGH,
	_OUTPUT_SPEED_VERY_HIGH
}GPIO_SPEED_t;



typedef enum
{
	_PULL_OFF  =0,
	_PULL_UP   ,
	_PULL_DOWN,
	_PULL_reserved
}GPIO_PULL_t;

typedef enum
{
	_LOW   =0,
	_HIGH
}GPIO_PIN_STATE_t;




typedef enum
{
	_ALTFN_0 =0,
	_ALTFN_1   ,
	_ALTFN_2   ,
	_ALTFN_3   ,
	_ALTFN_4   ,
	_ALTFN_5   ,
	_ALTFN_6   ,
	_ALTFN_7   ,
	_ALTFN_8   ,
	_ALTFN_9   ,
	_ALTFN_10  ,
	_ALTFN_11  ,
	_ALTFN_12  ,
	_ALTFN_13  ,
	_ALTFN_14  ,
	_ALTFN_15

}GPIO_ALTFN_MOOD_t;


typedef enum
{
	GPIO_PIN_0  =0,
	GPIO_PIN_1    ,
	GPIO_PIN_2    ,
	GPIO_PIN_3    ,
	GPIO_PIN_4    ,
	GPIO_PIN_5    ,
	GPIO_PIN_6    ,
	GPIO_PIN_7    ,
	GPIO_PIN_8    ,
	GPIO_PIN_9    ,
	GPIO_PIN_10   ,
	GPIO_PIN_11   ,
	GPIO_PIN_12   ,
	GPIO_PIN_13   ,
	GPIO_PIN_14   ,
	GPIO_PIN_15
}GPIO_PIN_t;


#define _GPIOA_PORT				0
#define _GPIOB_PORT				1
#define _GPIOC_PORT             2
#define _GPIOD_PORT             3
#define _GPIOE_PORT             4
#define _GPIOH_PORT             7


void MGPIO_vSetPinMode(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_MODE_t Copy_enuMode  );

void MGPIO_vSetPinOutPutType(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_OUT_t Copy_enuOutPutType  );

void MGPIO_vSetPinOutSpeed(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_SPEED_t Copy_enuOutSpeed );

void MGPIO_vSetPullType(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_PULL_t Copy_enuPullType );

GPIO_PIN_STATE_t MGPIO_enuReadData(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum);

void MGPIO_vWriteData(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum,GPIO_PIN_STATE_t Copy_enuState);
void MGPIO_vWriteDataDIR(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum ,GPIO_PIN_STATE_t Copy_enuState);

void MGPIO_vPinLock(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum );

void MGPIO_vSetPinAltFn(u8 Copy_enuPortName ,GPIO_PIN_t Copy_enuPinNum, GPIO_ALTFN_MOOD_t Copy_enuALF );



#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
