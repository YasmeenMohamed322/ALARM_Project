/*
 * GPIO_Prog.c
 *
 *  Created on: Mar 6, 2024
 *      Author: user
 */
#include "../../../LIB/stdTypes.h"
#include "../../../LIB/errorStates.h"
#include "../../../LIB/stm32f103.h"

#include "../Inc/GPIO_Int.h"
#include "../Inc/GPIO_Priv.h"

GPIO_REG* GPIO_PORT[GPIO_PERIPHERAL_NUM]={GPIOA,GPIOB,GPIOC,GPIOD,GPIOE,GPIOF,GPIOG};

ES_t GPIO_enuInit(const PinConfig_t* PinConfig)
{
	ES_t Local_enuErrorStates = ES_NOK;

	if(PinConfig != NULL)
	{
		if((PinConfig->Port) <= PORTG)
		{
			if((PinConfig->PinNum) >= PIN0 && (PinConfig->PinNum) <= PIN15 )
			{
					if((PinConfig->PinDirection) == INPUT)
					{
						u8 Local_u8RegNum = (PinConfig -> PinNum) / 8;
						GPIO_PORT[PinConfig->Port]->GPIO_CR[Local_u8RegNum] &= ~ (0b1111<<((PinConfig->PinNum) * 4));
						GPIO_PORT[PinConfig->Port]->GPIO_CR[Local_u8RegNum] = (PinConfig->INConfig | PinConfig->Mode) << (((PinConfig->PinNum) %8) * 4);
					}
				   else if(PinConfig -> PinDirection == OUTPUT)
					{
					   u8 Local_u8RegNum = (PinConfig -> PinNum) / 8;
						GPIO_PORT[PinConfig->Port]->GPIO_CR[Local_u8RegNum] &= ~ (0b1111<<(PinConfig -> PinNum * 4));
						GPIO_PORT[PinConfig->Port]->GPIO_CR[Local_u8RegNum] = (PinConfig->OUTConfig | ( (PinConfig->Mode) << 2)) << (((PinConfig->PinNum) %8) * 4);
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

	if(Port <= PORTG)
	{
		if((Pin >= PIN0) && (Pin <= PIN15))
		{
			GPIO_PORT[Port]->GPIO_ODR &= ~(1<<Pin);

			GPIO_PORT[Port]->GPIO_ODR |= (PinValue << Pin);
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

	if(Port <= PORTG)
	{
		if(Pin >= PIN0 && Pin <= PIN15)
		{
			GPIO_PORT[Port]->GPIO_ODR ^= (1 << Pin);
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

	if(Port <= PORTG)
	{

    	*PinValue = ((GPIO_PORT[Port]->GPIO_IDR)>>Pin) & 1 ;
	}
	else
	{
		Local_enuErrorStates = ES_OUT_OF_RANGE;
	}
	return Local_enuErrorStates;
}
