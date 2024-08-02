/***********************************************************/
/***********************************************************/
/**************   Author: Doaa_Tawfik       ****************/
/**************   Layer:  MCAL              ****************/
/**************   Version: 1.00             ****************/
/**************   Date:Aug 2, 2024          ****************/
/***********************************************************/
/***********************************************************/


#include "../../../LIB/stdTypes.h"
#include "../../../LIB/errorStates.h"
#include "../../../LIB/BIT_MATH.h"

#include "../../../LIB/stm32f103.h"

#include "../Inc/Systick_Interface.h"
#include "../Inc/Systick_Private.h"



/********************************************************/
/*********** Global Variables         ******************/
/*******************************************************/

u32 Global_u32BaseCounter;
f32 Global_f32OVF_Time;

/********************************************************/
/*********** Call_Back Functions          ***************/
/*******************************************************/
static volatile void (*Global_PF_ISRFun)(volatile void*) = NULL;
static volatile void (*Global_PV_ISRParameter) = NULL;



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuInitialize_CLK.                                         ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_enuCLKSOURCE                                                  ****/
/** Functionality   : Initialize Clock Source [External, Processor]                      ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuInitialize_CLK(SYSTICK_CLKSOURCE_t Copy_enuCLKSOURCE)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_enuCLKSOURCE == EXTERNAL_CLK)
	{
		/*Calculate Over Flow Time in Milli Seconds*/
		Global_f32OVF_Time = ((1/(f32)SYSTICK_EXT_FREQ)*((SYSTICK_CON_SEC)*((f32)SYSTICK_RES_VALUE)));

		/*CLEAR CLKSOURCE Bit @SYST_CSR*/
		SYSTICK->SYST_CSR &= (~(ONE_VALUE<< Bit_2));
		Local_enuErrorState = ES_OK;
	}
	else if(Copy_enuCLKSOURCE == PROCESSOR_CLK)
	{
		/*Calculate Over Flow Time in Milli Seconds*/
		Global_f32OVF_Time = ((1/(f32)SYSTICK_PRO_FREQ)*((SYSTICK_CON_SEC)*((f32)SYSTICK_RES_VALUE)));

		/*SETTING CLKSOURCE @SYST_CSR*/
		SYSTICK->SYST_CSR |= (ONE_VALUE<< Bit_2);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICk_enuSetPreloadValue.                                        ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_u32ReloadValue                                                ****/
/** Functionality   : Set Reload Value Register with Value                               ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuSetPreloadValue(u32 Copy_u32ReloadValue)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*Reading Value of SYST_RVR after doing masking to last 8 bits*/
	SYSTICK->SYST_RVR = (Copy_u32ReloadValue &SYSTICK_MASKING_RVR);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuEnable_SysTick_INT.                                     ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Enable Interrupt for System Timer                                  ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuEnable_SYSTICK_INT(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	/*Setting TICKINT bit @SYST_CSR*/
	SYSTICK->SYST_CSR |= (ONE_VALUE<< Bit_1);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuDisable_SysTick_INT.                                    ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Disable Interrupt for System Timer                                 ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuDisable_SYSTICK_INT(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	/*Clearing TICKINT bit @SYST_CSR*/
	SYSTICK->SYST_CSR &= (~(ONE_VALUE<< Bit_1));
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;

}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuEnable_SysTick.                                         ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Enable System Timer                                                ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t SYSTICKf103_enuEnable_SYSTICK(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	/*Setting ENABLE bit @SYST_CSR*/
	SYSTICK->SYST_CSR |= (ONE_VALUE<< Bit_0);
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuDisable_SysTick.                                        ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : void                                                               ****/
/** Functionality   : Disable System Timer                                               ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuDisable_SYSTICK(void)
{
	ES_t  Local_enuErrorState = ES_NOK;

	/*Clearing ENABLE bit @SYST_CSR*/
	SYSTICK->SYST_CSR &= (~(ONE_VALUE<< Bit_0));
	Local_enuErrorState = ES_OK;

	return  Local_enuErrorState;
}


/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuGet_COUNTFLAG.                                          ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_Pu8Flag_Value                                                 ****/
/** Functionality   : Getting Value of Counter Flag[Underflow Flag]                      ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuGet_COUNTFLAG(u8* Copy_Pu8Flag_Value)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_Pu8Flag_Value != NULL)
	{
		*Copy_Pu8Flag_Value = (((SYSTICK->SYST_CSR)>>Bit_16)&ONE_VALUE);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuGet_CurrentValue.                                       ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_Pu32CurrentValue                                              ****/
/** Functionality   : Getting Current Value of Counter                                   ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuGet_CurrentValue(u32* Copy_Pu32CurrentValue)
{
	ES_t  Local_enuErrorState = ES_NOK;

	if(Copy_Pu32CurrentValue != NULL)
	{
		/*Reading Value of SYST_CVR after doing masking to last 8 bits*/
		*Copy_Pu32CurrentValue = ((SYSTICK->SYST_CVR)&SYSTICK_MASKING_CVR);
		Local_enuErrorState = ES_OK;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}



/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuAsync_Delay_ms.                                         ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_u32Delay_ms,Copy_Pfun_AppFun,Copy_PV_AppParameter             ****/
/** Functionality   : Function to implement delay in ms using INT                        ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuAsync_Delay_ms(u32 Copy_u32Delay_ms ,volatile void (*Copy_Pfun_AppFun)(volatile void*) , void* Copy_PV_AppParameter)
{
	ES_t  Local_enuErrorState = ES_NOK;

	f32  Local_f32OVF_NUM , Local_f32Ticks_Ratio;
	u32  Local_u32Preload_Value ;

	if(Copy_Pfun_AppFun != NULL)
	{
		if(Copy_u32Delay_ms <= SYSTICK_RES_VALUE)
		{
			SYSTICKf103_enuDisable_SYSTICK_INT();

			Local_f32OVF_NUM = Copy_u32Delay_ms/Global_f32OVF_Time;
			Global_u32BaseCounter = Local_f32OVF_NUM+1;
			Local_f32Ticks_Ratio = Local_f32OVF_NUM - (u32)Local_f32OVF_NUM;
			Local_u32Preload_Value = (u32)(SYSTICK_RES_VALUE*Local_f32Ticks_Ratio);


			Global_PF_ISRFun = Copy_Pfun_AppFun;
			Global_PV_ISRParameter = Copy_PV_AppParameter;

			SYSTICKf103_enuSetPreloadValue(Local_u32Preload_Value);

			SYSTICKf103_enuEnable_SYSTICK_INT();

			Local_enuErrorState = ES_OK;

		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}


/********************************************************************************************/
/********************************************************************************************/
/** Function Name   : SYSTICK_enuSync_Delay_ms.                                          ****/
/** Return Type     : Error_State enum.                                                  ****/
/** Arguments       : Copy_u32Delay_ms                                                   ****/
/** Functionality   : Function to implement delay in ms using Polling                    ****/
/********************************************************************************************/
/********************************************************************************************/
ES_t  SYSTICKf103_enuSync_Delay_ms(u32 Copy_u32Delay_ms)
{
	ES_t  Local_enuErrorState = ES_NOK;

	f32  Local_f32OVF_NUM , Local_f32Ticks_Ratio;
	u32  Local_u32Preload_Value ;

	if(Copy_u32Delay_ms <= SYSTICK_RES_VALUE)
	{
		Local_f32OVF_NUM = Copy_u32Delay_ms/Global_f32OVF_Time;
		Global_u32BaseCounter = Local_f32OVF_NUM+1;
		Local_f32Ticks_Ratio = Local_f32OVF_NUM - (u32)Local_f32OVF_NUM;
		Local_u32Preload_Value = (u32)(SYSTICK_RES_VALUE*Local_f32Ticks_Ratio);


		SYSTICKf103_enuDisable_SYSTICK_INT();

		SYSTICKf103_enuSetPreloadValue(Local_u32Preload_Value);

		SYSTICKf103_enuEnable_SYSTICK();

		while(Global_u32BaseCounter--)
		{
			/*Implement Polling*/
			while(!GET_BIT(SYSTICK->SYST_CSR , Bit_16));

			/*Clear Flag*/
			// SET_BIT(SYSTICK->SYST_CSR , Bit_16);
			/*A write of any value clears the field to 0, and also clears the SYST_CSR COUNTFLAG bit to 0*/
			SYSTICK->SYST_CVR = 0;
		}

		SYSTICKf103_enuDisable_SYSTICK();

		Local_enuErrorState = ES_OK;

	}
	else
	{
		Local_enuErrorState = ES_OUT_OF_RANGE;
	}


	return Local_enuErrorState;
}



/********************************************************************************************/
/************************************* SYSTICK Handler **************************************/
/********************************************************************************************/
void SysTick_Handler()
{
	static u32 Local_su32Counter = 0;
	Local_su32Counter++;

	if(Local_su32Counter == Global_u32BaseCounter)
	{
		Local_su32Counter = 0;
		/*Calling Call back Function*/
		Global_PF_ISRFun(Global_PV_ISRParameter);

		SYSTICKf103_enuDisable_SYSTICK_INT();
	}

}


