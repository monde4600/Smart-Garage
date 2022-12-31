/*
 * RCC_interface.h
 *
 *  Created on: Dec 10, 2022
 *      Author: abano
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_

typedef enum{
	AHB1=0,
	AHB2,
	APB1,
	APB2
}BusName_t;

//AHB1 peripheral
#define _PERIPHERAL_EN_GPIOA					0
#define _PERIPHERAL_EN_GPIOB					1
#define _PERIPHERAL_EN_GPIOC					2
#define _PERIPHERAL_EN_GPIOD					3
#define _PERIPHERAL_EN_GPIOE					4
#define _PERIPHERAL_EN_GPIOH					7
#define _PERIPHERAL_EN_CRCR						12
#define _PERIPHERAL_EN_DMA1						21
#define _PERIPHERAL_EN_DMA2						22

//AHB2 peripheral
#define _PERIPHERAL_EN_OTGFS					7


//APB1 peripheral
#define _PERIPHERAL_EN_TIM2					0
#define _PERIPHERAL_EN_TIM3					1
#define _PERIPHERAL_EN_TIM4					2
#define _PERIPHERAL_EN_TIM5					3
#define _PERIPHERAL_EN_WWDG					11
#define _PERIPHERAL_EN_SPI2					14
#define _PERIPHERAL_EN_SPI3					15
#define _PERIPHERAL_EN_USART2				17
#define _PERIPHERAL_EN_I2c1					21
#define _PERIPHERAL_EN_I2c2					22
#define _PERIPHERAL_EN_I2c3					23
#define _PERIPHERAL_EN_PWR					28

//APB2 peripheral
#define _PERIPHERAL_EN_TIM1					0
#define _PERIPHERAL_EN_USART1				4
#define _PERIPHERAL_EN_USART6				5
#define _PERIPHERAL_EN_ADC1					8
#define _PERIPHERAL_EN_SDIO					11
#define _PERIPHERAL_EN_SPI1					12
#define _PERIPHERAL_EN_SPI4					13
#define _PERIPHERAL_EN_SYSCFG				14
#define _PERIPHERAL_EN_TIM9					16
#define _PERIPHERAL_EN_TIM10				17
#define _PERIPHERAL_EN_TIM11				18




void MRCC_vInitSystemCLK(void);

void MRCC_vEnableClock(BusName_t BusName , u8 Copy_u8PerNum );

void MRCC_vDisableClock(BusName_t BusName , u8 Copy_u8PerNum );

#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
