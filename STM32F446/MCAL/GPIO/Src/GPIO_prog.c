/*
 * GPIO_prog.c
 *
 *  Created on: Jul 31, 2024
 *      Author: user
 */

#include "../LIB/stdTypes.h"
#include "../LIB/errorStates.h"
#include "../LIB/stm32f446.h"

#include "../Inc/GPIO_priv.h"
#include "../Inc/GPIO_int.h"

GPIOx_REG_t* GPIO_PORT[GPIO_NUMBER] = {GPIO_PORT_A , GPIO_PORT_B , GPIO_PORT_C , GPIO_PORT_D ,
		                               GPIO_PORT_E , GPIO_PORT_F , GPIO_PORT_G , GPIO_PORT_H};

ES_t GPIO_enuInit(const PinConfig_t* PinConfig)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(PinConfig != NULL)
	{
		if(PinConfig->Port >= GPIO_PORTA && PinConfig->Port <= GPIO_PORTH )
		{
			if(PinConfig->PinNum >= GPIO_PIN0 && PinConfig->PinNum <= GPIO_PIN15 )
			{
				//Configuring I/O direction
				GPIO_PORT[PinConfig->Port]->GPIO_MODER &= ~(MODER_BIT_MASK << ( (PinConfig->PinNum) * 2 ));
				GPIO_PORT[PinConfig->Port]->GPIO_MODER |= ( (PinConfig->IODirection) << ( (PinConfig->PinNum) * 2 ));

				//Configuring Output Type
				GPIO_PORT[PinConfig->Port]->GPIO_OTYPER &= ~(OTYPER_BIT_MASK << (PinConfig->PinNum ));
				GPIO_PORT[PinConfig->Port]->GPIO_OTYPER |= ((PinConfig->OUTConfig) << (PinConfig->PinNum ));

				//Pull up or pull down configuration
				GPIO_PORT[PinConfig->Port]->GPIO_PUPDR &= ~(PUPDR_BIT_MASK << ( (PinConfig->PinNum) * 2 ));
				GPIO_PORT[PinConfig->Port]->GPIO_PUPDR |= ((PinConfig->Pullup_downConfig) << ( (PinConfig->PinNum) * 2 ));
			}
			else
			{
				Local_enuErrorStates = ES_OUT_OF_RANGE;
			}

		}
		else
		{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}

	}
	else
	{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}
ES_t GPIO_enuSetPinValue(Port_t Port,Pin_t Pin,PinValue_t PinValue)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(Port >= GPIO_PORTA && Port <= GPIO_PORTH )
	{
		if(Pin >= GPIO_PIN0 && Pin <= GPIO_PIN15 )
		{
			GPIO_PORT[Port]-> GPIO_ODR &= ~(ODR_BIT_MASK << Pin );
			GPIO_PORT[Port]-> GPIO_ODR |= ( PinValue <<  Pin );
		}
		else
		{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}
ES_t GPIO_enuTogglePinValue(Port_t Port,Pin_t Pin)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(Port >= GPIO_PORTA && Port <= GPIO_PORTH )
	{
		if(Pin >= GPIO_PIN0 && Pin <= GPIO_PIN15 )
		{
			GPIO_PORT[Port]-> GPIO_ODR ^= ( ODR_BIT_MASK <<  Pin );
		}
		else
		{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}

	return Local_enuErrorStates;
}
ES_t GPIO_enuReadPinValue(Port_t Port,Pin_t Pin,PinValue_t* PinValue)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(PinValue != NULL)
	{
		if(Port >= GPIO_PORTA && Port <= GPIO_PORTH )
		{
			if(Pin >= GPIO_PIN0 && Pin <= GPIO_PIN15 )
			{
				*PinValue = ( (GPIO_PORT[Port]->GPIO_IDR) >> Pin ) & IDR_BIT_MASK;
			}
			else
			{
				Local_enuErrorStates = ES_OUT_OF_RANGE;
			}
		}
		else
		{
			Local_enuErrorStates = ES_OUT_OF_RANGE;
		}
	}
	else
	{
		Local_enuErrorStates = ES_NULL_POINTER;
	}

	return Local_enuErrorStates;
}
