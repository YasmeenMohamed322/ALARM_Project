/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:Aug 1, 2024          ****************/
/***********************************************************/
/***********************************************************/

#ifndef NVICf44_INTERFACE_H_
#define NVICf44_INTERFACE_H_


typedef enum
{
	/*Window watchdog interrupt*/
	 WWDG_INT = 0                                                        ,
	 /*PVD through EXTI Line detection interrupt*/
	 PVD_INT                                                             ,
	 /*Tamper and TimeStamp interrupts through the EXTI Line*/
	 TAMP_STAMP_INT                                                          ,
	 /* RTC Wakeup interrupt through the EXTI line*/
	 RTC_WKUP_INT                                                             ,
	 /*Flash global interru*/
	 FLASH_INT                                                           ,
	 /*RCC global interrupt*/
	 RCC_INT                                                             ,
	 /*EXTI Line0 interrupt*/
	 EXTI0_INT                                                           ,
	 /*EXTI Line1 interrupt*/
	 EXTI1_INT                                                           ,
	 /*EXTI Line2 interrupt*/
	 EXTI2_INT                                                           ,
	 /*EXTI Line3 interrupt*/
	 EXTI3_INT                                                           ,
	 /*EXTI Line4 interrupt*/
	 EXTI4_INT                                                           ,
	 /*DMA1 Stream0 global interrupt*/
	 DMA1_Stream0_INT                                                   ,
	 /*DMA1 Stream1 global interrupt*/
	 DMA1_Stream1_INT                                                   ,
	 /*DMA1 Stream2 global interrupt*/
	 DMA1_Stream2_INT                                                   ,
	 /*DMA1 Stream3 global interrupt*/
	 DMA1_Stream3_INT                                                   ,
	 /*DMA1 Stream4 global interrupt*/
	 DMA1_Stream4_INT                                                   ,
	 /*DMA1 Stream5 global interrupt*/
	 DMA1_Stream5_INT                                                   ,
	 /*DMA1 Stream6 global interrupt*/
	 DMA1_Stream6_INT                                                   ,
	 /*ADC1, ADC2 and ADC3 global interrupts*/
	 ADC1_2_3_INT                                                          ,
	 /*CAN1 TX interrupts*/
	 CAN1_TX_INT                                                ,
	 /*CAN1 RX0 interrupts*/
	 CAN1_RX0_INT                                                  ,
	 /*CAN1 RX1 interrupt*/
	 CAN1_RX1_INT                                                         ,
	 /*CAN1 SCE interrupt*/
	 CAN1_SCE_INT                                                         ,
	 /*EXTI Line[5] interrupts*/
	 EXTI5_INT = 23                                                      ,
	 /*EXTI Line[6] interrupts*/
	 EXTI6_INT = 23                                                      ,
	 /*EXTI Line[7] interrupts*/
	 EXTI7_INT = 23                                                      ,
	 /*EXTI Line[8] interrupts*/
	 EXTI8_INT = 23                                                      ,
	 /*EXTI Line[9] interrupts*/
	 EXTI9_INT = 23                                                      ,
	 /*TIM1 Break interrupt and TIM9 global interrupt*/
	 TIM1_BRK_TIM9_INT                                                        ,
	 /*TIM1 Update interrupt and TIM10 global interrupt*/
	 TIM1_UP_TIM10_INT                                                         ,
	 /*TIM1 Trigger and Commutation interrupts And TIM11 global interrupt*/
	 TIM1_TRG_COM_TIM11_INT                                                    ,
	 /*TIM1 Capture Compare interrupt*/
	 TIM1_CC_INT                                                         ,
	 /*TIM2 global interrupt*/
	 TIM2_INT                                                            ,
	 /*TIM3 global interrupt*/
	 TIM3_INT                                                            ,
	 /* TIM4 global interrupt*/
	 TIM4_INT                                                            ,
	 /*I2C1 event interrupt*/
	 I2C1_EV_INT                                                         ,
	 /*I2C1 error interrupt*/
	 I2C1_ER_INT                                                         ,
	 /*I2C2 event interrupt*/
	 I2C2_EV_INT                                                         ,
	 /*I2C2 error interrupt*/
	 I2C2_ER_INT                                                         ,
	 /*SPI1 global interrup*/
	 SPI1_INT                                                            ,
	 /*SPI2 global interrupt*/
	 SPI2_INT                                                            ,
	 /*USART1 global interrupt*/
	 USART1_INT                                                          ,
	 /*USART2 global interrupt*/
	 USART2_INT                                                          ,
	 /*USART3 global interrupt*/
	 USART3_INT                                                          ,
	 /*EXTI Line[10] interrupts*/
	 EXTI10_INT  = 40                                                    ,
	 /*EXTI Line[11] interrupts*/
	 EXTI11_INT  = 40                                                    ,
	 /*EXTI Line[12] interrupts*/
	 EXTI12_INT  = 40                                                    ,
	 /*EXTI Line[13] interrupts*/
	 EXTI13_INT  = 40                                                    ,
	 /*EXTI Line[14] interrupts*/
	 EXTI14_INT  = 40                                                    ,
	 /*EXTI Line[15] interrupts*/
	 EXTI15_INT  = 40                                                    ,
     /*RTC alarm through EXTI line interrupt*/
	 RTCAlarm_INT                                                        ,
	 /*USB On-The-Go FS Wakeup through EXTI line interrupt*/
	 OTG_FS_WKUP_INT                                                     ,
	 /*TIM8 break interrupt and TIM12 global interrupt*/
	 TIM8_BRK_TIM12_INT                                                  ,
	 /*TIM8 Update interrupt and TIM13 global interrup*/
	 TIM8_UP_TIM13_INT                                                   ,
	 /*TIM8 Trigger and Commutation interrupts and TIM14 global interrup*/
	 TIM8_TRG_COM_TIM14_INT                                              ,
	 /*TIM8 Capture compare interrupt*/
	 TIM8_CC_INT                                                         ,
	 /* DMA1 Stream7 global interrupt*/
	 DMA1_Stream7_INT                                                    ,
	 /*FMC global interrupt*/
	 FMC_INT                                                             ,
	 /*SDIO global interrupt*/
	 SDIO_INT                                                            ,
	 /*TIM5 global interrupt*/
	 TIM5_INT                                                            ,
	 /*SPI3 global interrupt*/
	 SPI3_INT                                                            ,
	 /*UART4 global interrupt*/
	 UART4_INT                                                           ,
	 /*UART5 global interrupt*/
	 UART5_INT                                                           ,
	 /*TIM6 global interrupt, DAC1 and DAC2 underrun error interrupts*/
	 TIM6_DAC_INT                                                        ,
	 /*TIM7 global interrupt*/
	 TIM7_INT                                                            ,
	 /*DMA2 Stream0 global interrupt*/
	 DMA2_Stream0_INT                                                    ,
	 /* DMA2 Stream1 global interrupt*/
	 DMA2_Stream1_INT                                                    ,
	 /*DMA2 Stream2 global interrup*/
	 DMA2_Stream2_INT                                                    ,
	 /*DMA2 Stream2 global interrup*/
	 DMA2_Stream3_INT                                                    ,
	 /*DMA2 Stream4 global interrup*/
	 DMA2_Stream4_INT                                                    ,
	 /*CAN2 TX interruptS*/
	 CAN2_TX_INT  = 63                                                     ,
	 /* CAN2 RX0 interrupts*/
	 CAN2_RX0_INT                                                        ,
	 /*CAN2 RX1 interrup*/
	 CAN2_RX1_INT                                                        ,
	 /*CAN2 SCE interrupT*/
	 CAN2_SCE_INT                                                        ,
	 /* USB On The Go FS global interrupT*/
	 OTG_FS_INT                                                          ,
	 /*DMA2 Stream5 global interrupt*/
	 DMA2_Stream5_INT                                                    ,
	 /*DMA2 Stream6 global interrupt*/
	 DMA2_Stream6_INT                                                    ,
	 /*DMA2 Stream7 global interrupt*/
	 DMA2_Stream7_INT                                                    ,
	 /*USART6 global interrupt*/
	 USART6_INT                                                          ,
	 /*I2C3 event interrupt*/
	 I2C3_EV_INT                                                         ,
	 /*I2C3 error interrupt*/
	 I2C3_ER_INT                                                         ,
	 /*USB On The Go HS End Point 1 Out global interrup*/
	 OTG_HS_EP1_OUT_INT                                                  ,
	 /*USB On The Go HS End Point 1 In global interrup*/
	 OTG_HS_EP1_IN_INT                                                   ,
	 /*USB On The Go HS Wakeup through EXTI interrup*/
	 OTG_HS_WKUP_INT                                                     ,
	 /*USB On The Go HS global interrupt */
	 OTG_HS_INT                                                          ,
	 /* DCMI global interrupt*/
	 DCIM_INT                                                            ,
	 /*FPU global interrupt*/
	 FPU_INT = 81                                                        ,
	 /*SPI 4 global interrupt*/
	 SPI4_INT = 84                                                       ,
	 /*SAI1 global interrupt*/
	 SAI1_INT = 87                                                       ,
	 /*SAI2 global interrupt*/
	 SAI2_INT = 91                                                       ,
	 /*QuadSPI global interrupt*/
	 QuadSPI_INT                                                         ,
	 /*HDMI-CEC global interrupt*/
	 HDMI_CEC_INT                                                        ,
	 /*SPDIF-Rx global interrupt*/
	 SPDIF_Rx_INT                                                        ,
	 /*FMPI2C1 event interrupt*/
	 FMPI2C1_INT                                                         ,
	 /*FMPI2C1 error interrupt*/
	 FMPI2C1_error_INT

}IRQ_NUM_t;


typedef enum
{
	PENDED_INT,
	NOT_PENDED_INT
}Interrupt_PendingState_t;

typedef enum
{
	ACTIVATED_INT,
	DISACTIVATED_INT
}Interrupt_ActiveState_t;

typedef enum
{
	PRIORITY_ZERO          ,
	PRIORITY_ONE           ,
	PRIORITY_TWO           ,
	PRIORITY_THREE         ,
	PRIORITY_FOUR          ,
	PRIORITY_FIVE          ,
	PRIORITY_SIX           ,
	PRIORITY_SEVEN         ,
	PRIORITY_EIGHT         ,
	PRIORITY_NINE          ,
	PRIORITY_TEN           ,
	PRIORITY_ELEVEN        ,
	PRIORITY_TWELVE        ,
	PRIORITY_THIRTEEN      ,
	PRIORITY_FOURTEEN      ,
	PRIORITY_FIFTEEN
}Interrupt_Priority_t;






ES_t  NVICf44_enuEnable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVICf44_enuDisable_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVICf44_enuGetEnabledINT_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u8* Copy_pu8Enabled_INT);
ES_t  NVICf44_enuSetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVICf44_enuClearPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM);
ES_t  NVICf44_enuGetPendingFlag_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u8* Copy_pu8Pending_Flag);
ES_t  NVICf44_enuSetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32 Copy_u32Priority);
ES_t  NVICf44_enuGetPriority_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Prority);
ES_t  NVICf44_enuGetActive_IRQ(IRQ_NUM_t  Copy_enuIRQ_NUM , u32* Copy_pu32Active_IRQ);


#endif
