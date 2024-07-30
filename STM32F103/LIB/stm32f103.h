/*
 * stm32f103.h
 *
 *  Created on: Mar 6, 2024
 *      Author: user
 */

#ifndef STM32F103_H_
#define STM32F103_H_

//Various memory base addresses
#define FLASH_BASE_ADDRESS                    0x08000000UL
#define SRAM_BASE_ADDRESS                     0x20000000UL

//AHB peripherals base address
#define FSMC_BASE_ADDRESS                      0xA0000000UL
#define USB_OTG_FS_BASE_ADDRESS                0x50000000UL
#define ETHERNET_BASE_ADDRESS                  0x40028000UL
#define CRC_BASE_ADDRESS                       0x40023000UL
#define FLASH_INTERFACE_BASE_ADDRESS           0x40022000UL
#define RCC_BASE_ADDRESS                       0x40021000UL
#define DMA2_BASE_ADDRESS                      0x40020400UL
#define DMA1_BASE_ADDRESS                      0x40020000UL
#define SDIO_BASE_ADDRESS                      0x40018000UL

//APB2 peripherals base address
#define TIM11_BASE_ADDRESS                     0x40015400UL
#define TIM10_BASE_ADDRESS                     0x40015000UL
#define TIM9_BASE_ADDRESS                      0x40014C00UL
#define ADC3_BASE_ADDRESS                      0x40013C00UL
#define USART1_BASE_ADDRESS                    0x40013800UL
#define TIM8_BASE_ADDRESS                      0x40013400UL
#define SPI1_BASE_ADDRESS                      0x40013000UL
#define TIM1_BASE_ADDRESS                      0x40012C00UL
#define ADC2_BASE_ADDRESS                      0x40012800UL
#define ADC1_BASE_ADDRESS                      0x40012400UL
#define GPIO_G_BASE_ADDRESS                    0x40012000UL
#define GPIO_F_BASE_ADDRESS                    0x40011C00UL
#define GPIO_E_BASE_ADDRESS                    0x40011800UL
#define GPIO_D_BASE_ADDRESS                    0x40011400UL
#define GPIO_C_BASE_ADDRESS                    0x40011000UL
#define GPIO_B_BASE_ADDRESS                    0x40010C00UL
#define GPIO_A_BASE_ADDRESS                    0x40010800UL
#define EXTI_BASE_ADDRESS                      0x40010400UL
#define AFIO_BASE_ADDRESS                      0x40010000UL

//APB1 peripherals base address

//RCC Register Definition Structure
typedef struct{
volatile u32  RCC_CR;
volatile u32 RCC_CFGR;
volatile u32 RCC_CIR;
volatile u32 RCC_APB2RSTR;
volatile u32 RCC_APB1RSTR;
volatile u32 RCC_AHBENR;
volatile u32 RCC_APB2ENR;
volatile u32 RCC_APB1ENR;
volatile u32 RCC_BDCR;
volatile u32 RCC_CSR;
}RCC_REG;

RCC_REG * RCC = (RCC_REG*)(RCC_BASE_ADDRESS);

//GPIO Register Definition Structure
typedef struct{
volatile u32 GPIO_CR[2];
volatile u32 GPIO_IDR;
volatile u32 GPIO_ODR;
volatile u32 GPIO_BSRR;
volatile u32 GPIO_BRR;
volatile u32 GPIO_LCKR;
}GPIO_REG;

#define GPIOA  ((GPIO_REG*)GPIO_A_BASE_ADDRESS)
#define GPIOB  ((GPIO_REG*)GPIO_B_BASE_ADDRESS)
#define GPIOC  ((GPIO_REG*)GPIO_C_BASE_ADDRESS)
#define GPIOD  ((GPIO_REG*)GPIO_D_BASE_ADDRESS)
#define GPIOE  ((GPIO_REG*)GPIO_E_BASE_ADDRESS)
#define GPIOF  ((GPIO_REG*)GPIO_F_BASE_ADDRESS)
#define GPIOG  ((GPIO_REG*)GPIO_G_BASE_ADDRESS)



//AFIO Register Definition Structure
typedef struct{
volatile u32 AFIO_EVCR;
volatile u32 AFIO_MAPR;
volatile u32 AFIO_EXTICR[4];
volatile u32 AFIO_MAPR2;
}AFIO_REG;


#define AFIO             ((AFIO_REG*)AFIO_BASE_ADDRESS)
//RCC_CR Register

#define RCC_PLL_RDY        25
#define RCC_PLL_ON         24
#define RCC_HSE_RDY        17
#define RCC_HSE_ON         16
#define RCC_HSI_RDY         1
#define RCC_HSI_ON          0

//RCC_CFGR register
#define RCC_PLLMUL_21    21
#define RCC_PLLMUL_20    20
#define RCC_PLLMUL_19    19
#define RCC_PLLMUL_18    18
#define RCC_PLLXTPRE     17
#define RCC_PLLSRC       16
#define RCC_SW_1          1
#define RCC_SW_0          0

//RCC_AHBENR register
#define RCC_SDIOEN         10
#define RCC_FSMCEN         8
#define RCC_CRCEN          6
#define RCC_FLITFEN        4
#define RCC_SRAMEN         2
#define RCC_DMA2EN         1
#define RCC_DMA1EN         0

//RCC_APB2ENR
#define RCC_TIM11EN        21
#define RCC_TIM10EN        20
#define RCC_TIM9EN         19
#define RCC_ADC3EN         15
#define RCC_USART1EN       14
#define RCC_TIM8EN         13
#define RCC_SPI1EN         12
#define RCC_TIM1EN         11
#define RCC_ADC2EN         10
#define RCC_ADC1EN         9
#define RCC_IOPGEN         8
#define RCC_IOPFEN         7
#define RCC_IOPEEN         6
#define RCC_IOPDEN         5
#define RCC_IOPCEN         4
#define RCC_IOPBEN         3
#define RCC_IOPAEN         2
#define RCC_AFIOEN         0

//RCC_APB1ENR
#define RCC_DACEN          29
#define RCC_PWREN          28
#define RCC_BKPEN          27
#define RCC_CANEN          25
#define RCC_USBEN          23
#define RCC_I2C2EN         22
#define RCC_I2C1EN         21
#define RCC_UART5EN        20
#define RCC_UART4EN        19
#define RCC_USART3EN       18
#define RCC_USART2EN       17
#define RCC_SPI3EN         15
#define RCC_SPI2EN         14
#define RCC_WWDGEN         11
#define RCC_TIM14EN        8
#define RCC_TIM13EN        7
#define RCC_TIM12EN        6
#define RCC_TIM7EN         5
#define RCC_TIM6EN         4
#define RCC_TIM5EN         3
#define RCC_TIM4EN         2
#define RCC_TIM3EN         1
#define RCC_TIM2EN         0


// EXTI Register Definition Structure

typedef struct {
	volatile u32 EXTI_IMR;
	volatile u32 EXTI_EMR;
	volatile u32 EXTI_RTSR;
	volatile u32 EXTI_FTSR;
	volatile u32 EXTI_SWIER;
	volatile u32 EXTI_PR;
}EXTI_t;

#define EXTI                             ((EXTI_t*)EXTI_BASE_ADDRESS)


// DMA Register Definition Structure
typedef struct{
	volatile u32 DMA_ISR  ;
	volatile u32 DMA_IFCR ;
	volatile u32 DMA_CCR1 ;
	volatile u32 DMA_CNDTR1 ;
	volatile u32 DMA_CPAR1 ;
	volatile u32 DMA_CMAR1 ;
	volatile u32 RESERVED1 ;
	volatile u32 DMA_CCR2 ;
	volatile u32 DMA_CNDTR2 ;
	volatile u32 DMA_CPAR2 ;
	volatile u32 DMA_CMAR2 ;
	volatile u32 RESERVED2 ;
	volatile u32 DMA_CCR3 ;
	volatile u32 DMA_CNDTR3 ;
	volatile u32 DMA_CPAR3 ;
	volatile u32 DMA_CMAR3 ;
	volatile u32 RESERVED3 ;
	volatile u32 DMA_CCR4 ;
	volatile u32 DMA_CNDTR4 ;
	volatile u32 DMA_CPAR4 ;
	volatile u32 DMA_CMAR4 ;
	volatile u32 RESERVED4 ;
	volatile u32 DMA_CCR5 ;
	volatile u32 DMA_CNDTR5 ;
	volatile u32 DMA_CPAR5 ;
	volatile u32 DMA_CMAR5 ;
	volatile u32 RESERVED5 ;
	volatile u32 DMA_CCR6 ;
	volatile u32 DMA_CNDTR6 ;
	volatile u32 DMA_CPAR6 ;
	volatile u32 DMA_CMAR6 ;
	volatile u32 RESERVED6 ;
	volatile u32 DMA_CCR7 ;
	volatile u32 DMA_CNDTR7 ;
	volatile u32 DMA_CPAR7 ;
	volatile u32 DMA_CMAR7 ;

}DMA_t;

#define  DMA1                     ((DMA_t*)DMA1_BASE_ADDRESS)
#define  DMA2                     ((DMA_t*)DMA2_BASE_ADDRESS)

//Core peripherals

//SysTick Register Definition Structure
typedef struct{
	volatile u32 SYST_CSR;
	volatile u32 SYST_RVR;
	volatile u32 SYST_CVR;
	volatile u32 SYST_CALIB;
}SYST;

#define SYSTICK_BASE_ADDRESS                   0xE000E010UL
#define SYSTICK                             ((SYST*)SYSTICK_BASE_ADDRESS)


//SysTick Control and Status Register
#define COUNTFLAG          16
#define CLKSOURCE          2
#define TICKINT            1
#define ENABLE             0


//NVIC Registers Definition Structure
typedef struct{
	volatile u32 NVIC_ISER[7];
	volatile u32 RES1[25];
	volatile u32 NVIC_ICER[7];
	volatile u32 RES2[25];
	volatile u32 NVIC_ISPR[7];
	volatile u32 RES3[25];
	volatile u32 NVIC_ICPR[7];
	volatile u32 RES4[25];
	volatile u32 NVIC_IABR[7];
	volatile u32 RES5[57];
	volatile u32 NVIC_IPR[17];

}NVIC_REG;

#define NVIC_BASE_ADDRESS                      0xE000E100UL
#define NVIC                                 ((NVIC_REG*)NVIC_BASE_ADDRESS)

// SCB Registers Definition
typedef struct{
	volatile u32 SCB_ACTLR;
	volatile u32 SCB_CPUID;
	volatile u32 SCB_ICSR ;
	volatile u32 SCB_VTOR ;
	volatile u32 SCB_AIRCR ;
	volatile u32 SCB_SCR ;
	volatile u32 SCB_CCR ;
	volatile u32 SCB_SHPR[3];
	volatile u32 SCB_SHCRS ;
	volatile u32 SCB_CFSR ;
	volatile u32 SHB_HFSR ;
	volatile u32 SCB_MMAR ;
	volatile u32 SCB_BFAR ;
}SCB_REG;

#define SCB_BASE_ADDRESS                       0xE000E008UL
#define SCB                                   ((SCB_REG*)SCB_BASE_ADDRESS)




#endif /* STM32F103_H_ */
