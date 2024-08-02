/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:Aug 2, 2024          ****************/
/***********************************************************/
/***********************************************************/



#ifndef SYSTICKf103_INTERFACE_H_
#define SYSTICKf103_INTERFACE_H_


typedef enum
{
	EXTERNAL_CLK  = 0,
	PROCESSOR_CLK
}SYSTICK_CLKSOURCE_t;




ES_t  SYSTICKf103_enuInitialize_CLK(SYSTICK_CLKSOURCE_t Copy_enuCLKSOURCE);
ES_t  SYSTICKf103_enuSetPreloadValue(u32 Copy_u32ReloadValue);
ES_t  SYSTICKf103_enuEnable_SYSTICK_INT(void);
ES_t  SYSTICKf103_enuDisable_SYSTICK_INT(void);
ES_t  SYSTICKf103_enuEnable_SYSTICK(void);
ES_t  SYSTICKf103_enuDisable_SYSTICK(void);
ES_t  SYSTICKf103_enuGet_COUNTFLAG(u8* Copy_Pu8Flag_Value);
ES_t  SYSTICKf103_enuGet_CurrentValue(u32* Copy_Pu32CurrentValue);
ES_t  SYSTICKf103_enuAsync_Delay_ms(u32 Copy_u32Delay_ms ,volatile void (*Copy_Pfun_AppFun)(volatile void*) , void* Copy_PV_AppParameter);
ES_t  SYSTICKf103_enuSync_Delay_ms(u32 Copy_u32Delay_ms);


#endif
