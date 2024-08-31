/*
 * I2C_int.h
 *
 *  Created on: Aug 27, 2024
 *      Author: user
 */

#ifndef I2C_INT_H_
#define I2C_INT_H_

typedef enum{
	I2Cx_1,
	I2Cx_2,
	I2Cx_3
}I2C_Number;

typedef enum{
	SM_MODE,
	FM_MODE
}I2C_MODE;
typedef enum {
	I2C_SPEED_SM = 100000,
	I2C_SPEED_FM = 400000
}I2C_SCL_Speed;

typedef enum{
	ACK_DISABLE,
	ACK_ENABLE
}I2C_ACK_State;

typedef enum{
	I2C_FM_DUTY_2,
	I2C_FM_DUTY_16_9,
	I2C_NO_FM_MODE
}I2C_FM_DUTY;

typedef enum{
	I2C_7bit_Mode,
	I2C_10bit_Mode
}I2C_AddressingMode;

typedef struct{
	I2C_Number number;
	I2C_SCL_Speed SCL_speed;
	I2C_MODE mode;
	I2C_ACK_State ACK_state;
	I2C_FM_DUTY FM_duty;
	I2C_AddressingMode addressing_mode;
	u8 Address;
}IIC_Config_t;

typedef enum
{
	Write,
	Read
}RW_Bit;


ES_t I2C_enuInit(IIC_Config_t* IIC_config);
ES_t I2C_enuStartCondition(IIC_Config_t* IIC_config);
ES_t I2C_enuRepeatedStartCondition(IIC_Config_t* IIC_config);
ES_t I2C_enuStopCondition(IIC_Config_t* IIC_config);
ES_t I2C_enuWriteData(u8 Copy_u8Data,IIC_Config_t* IIC_config);
ES_t I2C_enuReadData(u8* Copy_pu8Data,IIC_Config_t* IIC_config);
ES_t I2C_enuWriteSlaveAddress(u8 Copy_u8Address,RW_Bit rwBit,IIC_Config_t* IIC_config);

#endif /* I2C_INT_H_ */
