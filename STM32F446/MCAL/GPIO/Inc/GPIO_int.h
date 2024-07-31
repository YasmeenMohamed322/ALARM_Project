/*
 * GPIO_int.h
 *
 *  Created on: Jul 31, 2024
 *      Author: user
 */

#ifndef GPIO_INT_H_
#define GPIO_INT_H_

//GPIO ports
typedef enum{
	GPIO_PORTA,
	GPIO_PORTB ,
	GPIO_PORTC ,
	GPIO_PORTD ,
	GPIO_PORTE ,
	GPIO_PORTF ,
	GPIO_PORTG ,
	GPIO_PORTH
}Port_t;

//GPIO Pins
typedef enum{
	GPIO_PIN0,
	GPIO_PIN1 ,
	GPIO_PIN2 ,
	GPIO_PIN3 ,
	GPIO_PIN4 ,
	GPIO_PIN5 ,
	GPIO_PIN6 ,
	GPIO_PIN7 ,
	GPIO_PIN8 ,
	GPIO_PIN9 ,
	GPIO_PIN10 ,
	GPIO_PIN11 ,
	GPIO_PIN12 ,
	GPIO_PIN13 ,
	GPIO_PIN14 ,
    GPIO_PIN15
}Pin_t;

typedef enum{
	INPUT_Mode,
	GENERAL_PURPOSE_OUTPUT_MODE,
	ALTERNATE_FUNCTION_MODE,
	ANALOG_MODE
}IO_DirectionMode_t;

typedef enum{
	NO_PULLUP_DOWN,
	PULLUP,
	PULLDOWN
}Pullup_down_Config_t;

typedef enum{
	PUSH_PULL,
	OPEN_DRAIN
}PinOUTConfig_t;

typedef enum{
	PIN_LOW,
	PIN_HIGH
}PinValue_t;

typedef struct{
	Port_t Port;
	Pin_t PinNum;
	IO_DirectionMode_t IODirection;
	Pullup_down_Config_t Pullup_downConfig;
	PinOUTConfig_t OUTConfig;
}PinConfig_t;

ES_t GPIO_enuInit(const PinConfig_t* PinConfig);
ES_t GPIO_enuSetPinValue(Port_t Port,Pin_t Pin,PinValue_t PinValue);
ES_t GPIO_enuTogglePinValue(Port_t Port,Pin_t Pin);
ES_t GPIO_enuReadPinValue(Port_t Port,Pin_t Pin,PinValue_t* PinValue);

#endif /* GPIO_INT_H_ */
