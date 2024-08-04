/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:Aug 2, 2024          ****************/
/***********************************************************/
/***********************************************************/

#ifndef SYSCFG_INTERFACE_H_
#define SYSCFG_INTERFACE_H_


typedef enum
{
	EXTI_LINE_0   ,
	EXTI_LINE_1   ,
	EXTI_LINE_2   ,
	EXTI_LINE_3   ,
	EXTI_LINE_4   ,
	EXTI_LINE_5   ,
	EXTI_LINE_6   ,
	EXTI_LINE_7   ,
	EXTI_LINE_8   ,
	EXTI_LINE_9   ,
	EXTI_LINE_10  ,
	EXTI_LINE_11  ,
	EXTI_LINE_12  ,
	EXTI_LINE_13  ,
	EXTI_LINE_14  ,
	EXTI_LINE_15  ,

}SYSCFG_EXTI_LINE_t;


typedef enum
{
	EXTI_PORT_A ,
	EXTI_PORT_B ,
	EXTI_PORT_C ,
	EXTI_PORT_D ,
	EXTI_PORT_E ,
	EXTI_PORT_F ,
	EXTI_PORT_G ,
	EXTI_PORT_H
}SYSCFG_EXTI_PORT_t;


ES_t  SYSCFG_enuSet_EXTI_PIN(SYSCFG_EXTI_LINE_t Copy_enuEXTI_LINE , SYSCFG_EXTI_PORT_t Copy_enuPort_ID);


#endif
