/*
 * GPIO_private.h
 *
 *  Created on: Dec 11, 2022
 *      Author: abano
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIOA_BASE_ADDRESS					0x40020000
#define GPIOB_BASE_ADDRESS					0x40020400
#define GPIOC_BASE_ADDRESS                  0x40020800
#define GPIOD_BASE_ADDRESS                  0x40020C00
#define GPIOE_BASE_ADDRESS                  0x40021000
#define GPIOH_BASE_ADDRESS                  0x40021C00

#define LCKK					16

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


typedef struct
{
	volatile u32 MODER;
	volatile u32 OTYPER;
	volatile u32 OSPEEDR;
	volatile u32 PUPDR;
	volatile u32 IDR;
	volatile u32 ODR;
	volatile u32 BSRR;
	volatile u32 LCKR;
	volatile u32 AFR[2];
	volatile u32 rserved[246];
}GPIO_t;


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

#define GPIO_BASE_ADDRES_TOT				(GPIO_t*)GPIOA_BASE_ADDRESS
#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
