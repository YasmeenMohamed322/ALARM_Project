#include "../../../LIB/stdTypes.h"
#include "../../../LIB/errorStates.h"
#include "../../../LIB/stm32f103.h"

#include "../../../MCAL/GPIO/Inc/GPIO_int.h"

ES_t Led_enuInit(Port_t port,Pin_t pin)
{
	ES_t Local_enuErrorState = ES_NOK;

	PinConfig_t Led_Pin = {
			.Port = port,
			.PinNum = pin,
			.PinDirection = OUTPUT,
			.INConfig = IN_PULLUP_PULLDOWN,
			.OUTConfig = PUSH_PULL,
	};

	GPIO_enuInit(&Led_Pin);

	return Local_enuErrorState;
}
ES_t Led_enuON(Port_t port,Pin_t pin)
{
	ES_t Local_enuErrorState = ES_NOK;

	GPIO_enuSetPinValue(port,pin,PIN_HIGH);

	return Local_enuErrorState;
}
ES_t Led_enuOFF(Port_t port,Pin_t pin)
{
	ES_t Local_enuErrorState = ES_NOK;

	GPIO_enuSetPinValue(port,pin,PIN_LOW);

	return Local_enuErrorState;
}
