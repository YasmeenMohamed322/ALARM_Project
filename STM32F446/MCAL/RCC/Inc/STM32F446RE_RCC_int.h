/*
 * STM32F446RE_RCC_int.h
 *
 *  Created on: Jul 30, 2024
 *      Author: Mostafa Edrees
 */

#ifndef RCC_STM32F446RE_RCC_INT_H_
#define RCC_STM32F446RE_RCC_INT_H_

#include "../../LIB/errorStates.h"

typedef enum
{
	HSI,
	HSE,
	PLLCLK,
	PLLR
}SYSCLK_Mux_t;

typedef enum
{
	CLK_OFF,
	CLK_ON
}CLK_Status_t;

typedef enum
{
	HSE_BYPASS,
	HSE_CRYSTAL
}HSE_Config_t;

typedef enum
{
	PLL_SRC_HSI,
	PLL_SRC_HSE
}PLL_Sourc_Mux_t;

typedef enum
{
	PLL_OFF,
	PLL_ON
}PLL_State_t;

typedef struct
{
	PLL_State_t PLL_State;	/* This value set according to @ref PLL_State_t */

	/* Configuration Parameters of main PLL */
	u8 PLLM_Div_Factor;		/* This value must be between (2 --> 63) */
	u8 PLLN_Mul_Factor;		/* This value must be between (50 --> 432) */
	u8 PLLP_Div_Factor;		/* This value must be 2 or 4 or 6 or 8 */
	u8 PLLQ_Div_Factor;		/* This value must be between (2 --> 15) */
	u8 PLLR_Div_Factor;		/* This value must be between (2 --> 7) */
}PLL_main_t;

typedef struct
{
	PLL_State_t PLL_State;	/* This value set according to @ref PLL_State_t */

	/* Configuration Parameters of PLLSAI */

}PLLSAI_t;

typedef struct
{
	PLL_State_t PLL_State;	/* This value set according to @ref PLL_State_t */

	/* Configuration Parameters of PLLI2S */

}PLLI2S_t;

typedef struct
{
	PLL_main_t Main_PLL_CFG;	/* This value set according to @ref PLL_main_t */
	PLLSAI_t PLLSAI_CFG;		/* This value set according to @ref PLLSAI_t */
	PLLI2S_t PLLI2S_CFG;		/* This value set according to @ref PLLI2S_t */
}PLL_Type_t;

typedef enum
{
	CLK_HSI,
	CLK_HSE,
	CLK_PLL,
	CLK_PLLI2S,
	CLK_PLLSAI
}Clock_Src_t;

typedef struct
{
	PLL_Sourc_Mux_t PLL_SRC;	/* This value set according to @ref PLL_Sourc_Mux_t */
	PLL_Type_t PLL_TYP;			/* This value set according to @ref PLL_Type_t */
}PLL_Config_t;

typedef enum
{
	CLK_NOT_DIVIDED,
	CLK_DIVIDED_by_2,
	CLK_DIVIDED_by_4,
	CLK_DIVIDED_by_8,
	CLK_DIVIDED_by_16,
	CLK_DIVIDED_by_64,
	CLK_DIVIDED_by_128,
	CLK_DIVIDED_by_256,
	CLK_DIVIDED_by_512
}PreScaler_t;

typedef struct
{
	PreScaler_t AHB_PreScaler;
	PreScaler_t APB1_PreScaler;
	PreScaler_t APB2_PreScaler;
}SYSCLK_Config_t;

ES_t RCC_enuSetClockState(Clock_Src_t Copy_enuClkSrc, CLK_Status_t Copy_enuClkState);

ES_t RCC_enuSetSYSCLK(SYSCLK_Mux_t Copy_enuClkTyp);

ES_t RCC_enuConfigHSE(HSE_Config_t Copy_strHSEcfg);

ES_t RCC_enuConfigPLL(PLL_Config_t *Copy_PstrPLLcfg);

ES_t RCC_enuConfigSYSCLK(SYSCLK_Config_t *Copy_PstrSYSCLKcfg);

ES_t RCC_enuAHB1EnableClock(AHB1_Peripheral_t Copy_enuAHB1Peri);
ES_t RCC_enuAHB1DisableClock(AHB1_Peripheral_t Copy_enuAHB1Peri);

ES_t RCC_enuAHB2EnableClock(AHB2_Peripheral_t Copy_enuAHB2Peri);
ES_t RCC_enuAHB2DisableClock(AHB2_Peripheral_t Copy_enuAHB2Peri);

ES_t RCC_enuAHB3EnableClock(AHB3_Peripheral_t Copy_enuAHB3Peri);
ES_t RCC_enuAHB3DisableClock(AHB3_Peripheral_t Copy_enuAHB3Peri);

ES_t RCC_enuAPB1EnableClock(APB1_Peripheral_t Copy_enuAPB1Peri);
ES_t RCC_enuAPB1DisableClock(APB1_Peripheral_t Copy_enuAPB1Peri);

ES_t RCC_enuAPB2EnableClock(APB2_Peripheral_t Copy_enuAPB2Peri);
ES_t RCC_enuAPB2DisableClock(APB2_Peripheral_t Copy_enuAPB2Peri);

#endif /* RCC_STM32F446RE_RCC_INT_H_ */
