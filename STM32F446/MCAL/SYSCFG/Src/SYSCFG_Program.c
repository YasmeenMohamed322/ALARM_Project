/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:Aug 3, 2024          ****************/
/***********************************************************/
/***********************************************************/


#include "../../../LIB/stdTypes.h"
#include "../../../LIB/errorStates.h"
#include "../../../LIB/BIT_MATH.h"

#include "../../../LIB/stm32f446.h"


#include "../Inc/SYSCFG_Interface.h"
#include "../Inc/SYSCFG_Private.h"


ES_t  SYSCFG_enuSet_EXTI_PIN(SYSCFG_EXTI_LINE_t Copy_enuEXTI_LINE , SYSCFG_EXTI_PORT_t Copy_enuPort_ID)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if((Copy_enuEXTI_LINE <= EXTI_LINE_15) && (Copy_enuPort_ID <= EXTI_PORT_H))
	{
		u8 Local_u8Register_Num = Copy_enuEXTI_LINE/FOUR;
		u8 Local_u8Shift_Bit = ((Copy_enuEXTI_LINE%FOUR)*FOUR);

		/*Masking Four Bits For EXTI Line*/
		SYS_CFG->SYSCFG_EXTICR[Local_u8Register_Num] &= (~(MASK_EXTI_LINE << Local_u8Shift_Bit));

		/*Choosing Port for EXTI Line*/
		SYS_CFG->SYSCFG_EXTICR[Local_u8Register_Num] |= (Copy_enuPort_ID << Local_u8Shift_Bit);

        Local_enuErrorState = ES_OK;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorState;
}
