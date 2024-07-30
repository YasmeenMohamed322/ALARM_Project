/*
 * GPIO_Int.h
 *
 *  Created on: Mar 6, 2024
 *      Author: user
 */

#ifndef GPIO_INT_H_
#define GPIO_INT_H_

//GPIO Ports
typedef enum{
	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,
	PORTF,
	PORTG
}Port_t;

//GPIO Pins
typedef enum{
	PIN0,
	PIN1 ,
	PIN2 ,
	PIN3 ,
	PIN4 ,
	PIN5 ,
	PIN6 ,
	PIN7 ,
	PIN8 ,
	PIN9 ,
	PIN10 ,
	PIN11 ,
	PIN12 ,
	PIN13 ,
	PIN14 ,
    PIN15
}Pin_t;

typedef enum{
	INPUT,
	OUTPUT
}PinDirection_t;
typedef enum{
	INPUTMode,
	OUTPUT_SPEED10,
	OUTPUT_SPEED2,
	OUTPUT_SPEED50
}PinMode_t;

typedef enum{
	ANALOG,
	FLOATING,
	IN_PULLUP_PULLDOWN
}PinINConfig_t;

typedef enum{
	PUSH_PULL,
	OPEN_DRAIN,
	AF_PUSH_PULL,
	AF_OPEN_DRAIN
}PinOUTConfig_t;

typedef enum{
	PIN_LOW,
	PIN_HIGH
}PinValue_t;

typedef struct{
	Port_t Port;
	Pin_t PinNum;
	PinDirection_t PinDirection;
	PinMode_t Mode;
	PinINConfig_t INConfig;
	PinOUTConfig_t OUTConfig;
}PinConfig_t;


ES_t GPIO_enuInit(const PinConfig_t* PinConfig);
ES_t GPIO_enuSetPinValue(Port_t Port,Pin_t Pin,PinValue_t PinValue);
ES_t GPIO_enuTogglePinValue(Port_t Port,Pin_t Pin);
ES_t GPIO_enuReadPinValue(Port_t Port,Pin_t Pin,PinValue_t* PinValue);
#endif /* GPIO_INT_H_ */
