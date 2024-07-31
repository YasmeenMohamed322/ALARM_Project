/*
 * stm32f446.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Mostafa Edrees
 */

#ifndef LIB_STM32F446_H_
#define LIB_STM32F446_H_

#include "stdTypes.h"



typedef enum
{
	GPIOA,
	GPIOB,
	GPIOC,
	GPIOD,
	GPIOE,
	GPIOF,
	GPIOG,
	GPIOH,
	CRC = 12,
	BKPSRAM = 18,
	DMA1 = 21,
	DMA2,
	OTGHS = 29,
	OTGHSULPI
}AHB1_Peripheral_t;

typedef enum
{
	DCMI,
	OTGFS = 7
}AHB2_Peripheral_t;

typedef enum
{
	FMC,
	QSPI
}AHB3_Peripheral_t;

typedef enum
{
	TIM2,
	TIM3,
	TIM4,
	TIM5,
	TIM6,
	TIM7,
	TIM12,
	TIM13,
	TIM14,
	WWDG = 11,
	SPI2 = 14,
	SPI3,
	SPDIFRX,
	USART2,
	USART3,
	UART4,
	UART5,
	I2C1,
	I2C2,
	I2C3,
	FMPI2C1,
	CAN1,
	CAN2,
	CEC,
	PWR,
	DAC
}APB1_Peripheral_t;

typedef enum
{
	TIM1,
	TIM8,
	USART1 = 4,
	USART6,
	ADC1 = 8,
	ADC2,
	ADC3,
	SDIO,
	SPI1,
	SPI4,
	SYSCFG,
	TIM9 = 16,
	TIM10,
	TIM11,
	SAI1 = 22,
	SAI2
}APB2_Peripheral_t;


//Peripherals base address
#define RCC_BASE_ADDRESS				0x40023800

#define GPIOA_BASE_ADDRESS              0x40020000
#define GPIOB_BASE_ADDRESS              0x40020400
#define GPIOC_BASE_ADDRESS              0x40020800
#define GPIOD_BASE_ADDRESS              0x40020C00
#define GPIOE_BASE_ADDRESS              0x40021000
#define GPIOF_BASE_ADDRESS              0x40021400
#define GPIOG_BASE_ADDRESS              0x40021800
#define GPIOH_BASE_ADDRESS              0x40021C00

//RCC register definition
typedef struct
{
	u32 RCC_CR;
	u32 RCC_PLLCFGR;
	u32 RCC_CFGR;
	u32 RCC_CIR;
	u32 RCC_AHB1RSTR;
	u32 RCC_AHB2RSTR;
	u32 RCC_AHB3RSTR;
	u32 RCC_RESERVED1;
	u32 RCC_APB1RSTR;
	u32 RCC_APB2RSTR;
	u32 RCC_RESERVED2;
	u32 RCC_RESERVED3;
	u32 RCC_AHB1ENR;
	u32 RCC_AHB2ENR;
	u32 RCC_AHB3ENR;
	u32 RCC_RESERVED4;
	u32 RCC_APB1ENR;
	u32 RCC_APB2ENR;
	u32 RCC_RESERVED5;
	u32 RCC_RESERVED6;
	u32 RCC_AHB1LPENR;
	u32 RCC_AHB2LPENR;
	u32 RCC_AHB3LPENR;
	u32 RCC_RESERVED7;
	u32 RCC_APB1LPENR;
	u32 RCC_APB2LPENR;
	u32 RCC_RESERVED8;
	u32 RCC_RESERVED9;
	u32 RCC_BDCR;
	u32 RCC_CSR;
	u32 RCC_RESERVED10;
	u32 RCC_RESERVED11;
	u32 RCC_SSCGR;
	u32 RCC_PLLI2SCFGR;
	u32 RCC_PLLSAICFGR;
	u32 RCC_DCKCFGR;
	u32 RCC_CKGATENR;
	u32 RCC_DCKCFGR2;
}RCC_TypeDef_t;

#define RCC								((RCC_TypeDef_t *)RCC_BASE_ADDRESS)

//GPIO register Definition
typedef struct {
	volatile u32 GPIO_MODER;
	volatile u32 GPIO_OTYPER;
	volatile u32 GPIO_OSPEEDER;
	volatile u32 GPIO_PUPDR;
	volatile u32 GPIO_IDR;
	volatile u32 GPIO_ODR;
	volatile u32 GPIO_BSRR;
	volatile u32 GPIO_LCKR;
	volatile u32 GPIO_AFRL;
	volatile u32 GPIO_AFRH;
}GPIOx_REG_t;

#define GPIOA                             ((GPIOx_REG_t*)GPIOA_BASE_ADDRESS)
#define GPIOB                             ((GPIOx_REG_t*)GPIOB_BASE_ADDRESS)
#define GPIOC                             ((GPIOx_REG_t*)GPIOC_BASE_ADDRESS)
#define GPIOD                             ((GPIOx_REG_t*)GPIOD_BASE_ADDRESS)
#define GPIOE                             ((GPIOx_REG_t*)GPIOE_BASE_ADDRESS)
#define GPIOF                             ((GPIOx_REG_t*)GPIOF_BASE_ADDRESS)
#define GPIOG                             ((GPIOx_REG_t*)GPIOG_BASE_ADDRESS)
#define GPIOH                             ((GPIOx_REG_t*)GPIOH_BASE_ADDRESS)

#define MASK_BIT						1

#endif /* LIB_STM32F446_H_ */
