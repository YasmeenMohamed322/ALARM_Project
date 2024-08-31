/*
 * I2C_prog.c
 *
 *  Created on: Aug 27, 2024
 *      Author: user
 */

#include "../../../LIB/stdTypes.h"
#include "../../../LIB/errorStates.h"
#include "../../../LIB/stm32f446.h"

#include "../Inc/I2C_priv.h"
#include "../Inc/I2C_int.h"

u32 systemClock, pclk1;
u32 ahbPrescaler, apb1Prescaler;

ES_t RCC_GetPCLK1Freq(void)
{

	ES_t Local_enuErrorState = ES_NOK;
    systemClock = CLOCK_FREQ;

    // Get AHB prescaler
    u32 hpre = (RCC->RCC_CFGR >> 4) & 0xF;
    if (hpre < 8) {
        ahbPrescaler = 1;
    } else {
        ahbPrescaler = 2 << (hpre - 8);
    }


    u32 ppre1 = (RCC->RCC_CFGR >> 10) & 0x7;
    if (ppre1 < 4) {
        apb1Prescaler = 1;
    } else {
        apb1Prescaler = 2 << (ppre1 - 3);
    }

    pclk1 = (systemClock / ahbPrescaler) / apb1Prescaler;

    return Local_enuErrorState;
}

I2C_REG_t* IIC_NUM[IIC_NUMBER] = {I2C_1,I2C_2,I2C_3};

ES_t I2C_enuInit(IIC_Config_t* IIC_config)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(IIC_config != NULL)
	{
		//Disable I2Cbefore configuration
		IIC_NUM[IIC_config->number]->I2C_CR1 &= ~(MASKING_BIT<<PE);

		//clock calculations
		IIC_NUM[IIC_config->number]->I2C_CR2 &= ~(FREQ_MASKING);
		IIC_NUM[IIC_config->number]->I2C_CR2 = pclk1 / 1000000;
		//enable the peripheral
		IIC_NUM[IIC_config->number]->I2C_CR1 |= (MASKING_BIT<<PE);

		//set ack state
		IIC_NUM[IIC_config->number]->I2C_CR1 &= ~(MASKING_BIT << ACK);
		IIC_NUM[IIC_config->number]->I2C_CR1 |= ((IIC_config->ACK_state) << ACK);

		//set the address
		IIC_NUM[IIC_config->number]->I2C_OAR1 &= ~(MASKING_BIT << ADDMODE);
		//IIC_NUM[IIC_config->number]->I2C_OAR1 |= ((IIC_config->addressing_mode) << ADDMODE);

		IIC_NUM[IIC_config->number]->I2C_OAR1 &= ~(ADD_MASKING << MASKING_BIT);
		IIC_NUM[IIC_config->number]->I2C_OAR1 |= ((IIC_config->Address) << MASKING_BIT);

		IIC_NUM[IIC_config->number]->I2C_OAR1 |= (MASKING_BIT << 14);

		//CCR
		IIC_NUM[IIC_config->number]->I2C_CCR &= ~(CCR_MASKING);
		IIC_NUM[IIC_config->number]->I2C_CCR &= ~(MASKING_BIT << F_S);
		IIC_NUM[IIC_config->number]->I2C_CCR |= (IIC_config->mode <<F_S);

		//standard mode
		IIC_NUM[IIC_config->number]->I2C_CCR |= pclk1 / (2 * IIC_config->SCL_speed);
		IIC_NUM[IIC_config->number]->I2C_TRISE &= ~(TRISE_MASKING);
		IIC_NUM[IIC_config->number]->I2C_TRISE |= (pclk1 / 1000000)+1;
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}
	return Local_enuErrorState;
}
ES_t I2C_enuStartCondition(IIC_Config_t* IIC_config)
{
	ES_t Local_enuErrorState = ES_NOK;

	IIC_NUM[IIC_config->number]->I2C_CR1 |= (MASKING_BIT << START);

	while( ! ((( IIC_NUM[IIC_config->number]->I2C_SR1 ) >> SB ) & MASKING_BIT ));

	return Local_enuErrorState;
}

ES_t I2C_enuStopCondition(IIC_Config_t* IIC_config)
{
	ES_t Local_enuErrorState = ES_NOK;

	IIC_NUM[IIC_config->number]->I2C_CR1 |= (MASKING_BIT << STOP);

	while( ! ((( IIC_NUM[IIC_config->number]->I2C_SR1 ) >> STOPF ) & MASKING_BIT ));

	return Local_enuErrorState;
}
ES_t I2C_enuWriteData(u8 Copy_u8Data,IIC_Config_t* IIC_config)
{
	ES_t Local_enuErrorState = ES_NOK;

	//wait till data register is empty
	while( ! ((( IIC_NUM[IIC_config->number]->I2C_SR1 ) >> TXE ) & MASKING_BIT ));

	//write the data
	IIC_NUM[IIC_config->number]->I2C_DR &= ~(DATA_MASK);
	IIC_NUM[IIC_config->number]->I2C_DR |= Copy_u8Data;

	//Wait till the data is transmitted
	while( ! ((( IIC_NUM[IIC_config->number]->I2C_SR1 ) >> BTF ) & MASKING_BIT ));

	return Local_enuErrorState;
}
ES_t I2C_enuReadData(u8* Copy_pu8Data,IIC_Config_t* IIC_config)
{
	ES_t Local_enuErrorState = ES_NOK;

	//Wait till the data is received
	while( ! ((( IIC_NUM[IIC_config->number]->I2C_SR1 ) >> RXNE ) & MASKING_BIT ));

	//read the data
	*Copy_pu8Data = IIC_NUM[IIC_config->number]->I2C_DR;

	return Local_enuErrorState;
}
ES_t I2C_enuWriteSlaveAddress(u8 Copy_u8Address,RW_Bit rwBit,IIC_Config_t* IIC_config)
{
	ES_t Local_enuErrorState = ES_NOK;

	IIC_NUM[IIC_config->number]->I2C_DR = (Copy_u8Address <<1)|rwBit;

	while( ! ((( IIC_NUM[IIC_config->number]->I2C_SR1 ) >> ADDR ) & MASKING_BIT ));

	IIC_NUM[IIC_config->number]->I2C_SR1;
	IIC_NUM[IIC_config->number]->I2C_SR2;

	return Local_enuErrorState;
}
