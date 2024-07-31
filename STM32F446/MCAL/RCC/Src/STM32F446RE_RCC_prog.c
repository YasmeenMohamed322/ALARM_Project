/*
 * STM32F446RE_RCC_prog.c
 *
 *  Created on: Jul 30, 2024
 *      Author: Mostafa Edrees
 */

#include "../../LIB/errorStates.h"
#include "../../LIB/stdTypes.h"

#include "../../LIB/stm32f446.h"

#include "../Inc/STM32F446RE_RCC_priv.h"
#include "../Inc/STM32F446RE_RCC_int.h"


ES_t RCC_enuSetClockState(Clock_Src_t Copy_enuClkSrc, CLK_Status_t Copy_enuClkState)
{
	ES_t Local_enuErrorState = ES_NOK;

	switch(Copy_enuClkSrc)
	{
	case CLK_HSI:
		if(Copy_enuClkState == CLK_ON)
		{
			/*
			 * Bit 0 HSION: Internal high-speed clock enable
			 * 0: HSI oscillator OFF
			 * 1: HSI oscillator ON
			 * Set by hardware to force the HSI oscillator ON when leaving the Stop or Standby mode
			 * or in case of a failure of the HSE oscillator used directly or indirectly as the system clock */
			RCC->RCC_CR |= (MASK_BIT << 0);

			/*
			 * Bit 1 HSIRDY: Internal high-speed clock ready flag
			 * 0: HSI oscillator not ready
			 * 1: HSI oscillator ready
			 * Set by hardware to indicate that the HSI oscillator is stable.
			 */
			//while(!((RCC->RCC_CR >> 1) & 1));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuClkState == CLK_OFF)
		{
			RCC->RCC_CR &= ~(MASK_BIT << 0);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		break;

	case  CLK_HSE:
		if(Copy_enuClkState == CLK_ON)
		{
			/*
			 * Bit 16 HSEON: HSE clock enable
			 * 0: HSE oscillator OFF
			 * 1: HSE oscillator ON
			 * Cleared by hardware to stop the HSE oscillator when entering Stop or Standby mode.
			 */
			RCC->RCC_CR |= (MASK_BIT << 16);

			/*
			 * Bit 17 HSERDY: HSE clock ready flag
			 * 0: HSE oscillator not ready
			 * 1: HSE oscillator ready
			 * Set by hardware to indicate that the HSE oscillator is stable.
			 */
			while(!((RCC->RCC_CR >> 17) & 1));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuClkState == CLK_OFF)
		{
			RCC->RCC_CR &= ~(MASK_BIT << 16);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		break;

	case CLK_PLL:
		if(Copy_enuClkState == CLK_ON)
		{
			/*
			 * Bit 24 PLLON: Main PLL (PLL) enable
			 * 0: PLL OFF
			 * 1: PLL ON
			 * Cleared by hardware when entering Stop or Standby mode.
			 */
			RCC->RCC_CR |= (MASK_BIT << 24);

			/*
			 * Bit 25 PLLRDY: Main PLL (PLL) clock ready flag
			 * 0: PLL unlocked
			 * 1: PLL locked
			 * Set by hardware to indicate that PLL is locked.
			 */
			while(!((RCC->RCC_CR >> 25) & 1));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuClkState == CLK_OFF)
		{
			RCC->RCC_CR &= ~(MASK_BIT << 24);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		break;

	case CLK_PLLI2S:
		if(Copy_enuClkState == CLK_ON)
		{
			/*
			 * Bit 26 PLLI2SON: PLLI2S enable
			 * Cleared by hardware when entering Stop or Standby mode.
			 * 0: PLLI2S OFF
			 * 1: PLLI2S ON
			 */
			RCC->RCC_CR |= (MASK_BIT << 26);

			/*
			 * Bit 27 PLLI2SRDY: PLLI2S clock ready flag
			 * 0: PLLI2S unlocked
			 * 1: PLLI2S locked
			 * Set by hardware to indicate that the PLLI2S is locked.
			 */
			while(!((RCC->RCC_CR >> 27) & 1));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuClkState == CLK_OFF)
		{
			RCC->RCC_CR &= ~(MASK_BIT << 26);
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		break;

	case CLK_PLLSAI:
		if(Copy_enuClkState == CLK_ON)
		{
			/*
			 * Bit 28 PLLSAION: PLLSAI enable
			 * Cleared by hardware when entering Stop or Standby mode.
			 * 0: PLLSAI OFF
			 * 1: PLLSAI ON
			 */
			RCC->RCC_CR |= (MASK_BIT << 28);

			/*
			 * Bit 29 PLLSAIRDY: PLLSAI clock ready flag
			 * 0: PLLSAI unlocked
			 * 1: PLLSAI locked
			 * Set by hardware to indicate that the PLLSAI is locked.
			 */
			while(!((RCC->RCC_CR >> 29) & 1));

			Local_enuErrorState = ES_OK;
		}
		else if(Copy_enuClkState == CLK_OFF)
		{
			RCC->RCC_CR &= ~(MASK_BIT << 29);

			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}
		break;

	default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
		break;
	}

	return Local_enuErrorState;
}

ES_t RCC_enuSetSYSCLK(SYSCLK_Mux_t Copy_enuClkTyp)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*
	 * Bits 1:0 SW[1:0]: System clock switch
	 * Used to select the system clock source.
	 * Set by hardware to force the HSI selection when leaving the Stop or Standby mode
	 * or in case of failure of the HSE oscillator used directly or indirectly as the system clock.
	 * 00: HSI oscillator selected as system clock
	 * 01: HSE oscillator selected as system clock
	 * 10: PLL_P selected as system clock
	 * 11: PLL_R selected as system clock
	 */
	switch(Copy_enuClkTyp)
	{
	case HSI:
		RCC->RCC_CFGR &= ~(MASK_BIT << 0);
		RCC->RCC_CFGR &= ~(MASK_BIT << 1);
		Local_enuErrorState = ES_OK;
		break;

	case HSE:
		RCC->RCC_CFGR |=  (MASK_BIT << 0);
		RCC->RCC_CFGR &= ~(MASK_BIT << 1);
		Local_enuErrorState = ES_OK;
		break;

	case PLLCLK:
		RCC->RCC_CFGR &= ~(MASK_BIT << 0);
		RCC->RCC_CFGR |=  (MASK_BIT << 1);
		Local_enuErrorState = ES_OK;
		break;

	case PLLR:
		RCC->RCC_CFGR |=  (MASK_BIT << 0);
		RCC->RCC_CFGR |=  (MASK_BIT << 1);
		Local_enuErrorState = ES_OK;
		break;

	default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
		break;
	}

	return Local_enuErrorState;
}

ES_t RCC_enuConfigHSE(HSE_Config_t Copy_strHSEcfg)
{
	ES_t Local_enuErrorState = ES_NOK;

	/*
	 * Bit 18 HSEBYP: HSE clock bypass
	 * Used to to bypass the oscillator with an external clock.
	 * The external clock must be enabled with the HSEON bit, to be used by the device.
	 * The HSEBYP bit can be written only if the HSE oscillator is disabled.
	 */
	switch(Copy_strHSEcfg)
	{
	case HSE_BYPASS:
		RCC->RCC_CR |= (MASK_BIT << 18);
		Local_enuErrorState = ES_OK;
		break;

	case HSE_CRYSTAL:
		RCC->RCC_CR &= ~(MASK_BIT << 18);
		Local_enuErrorState = ES_OK;
		break;

	default:
		Local_enuErrorState = ES_OUT_OF_RANGE;
		break;

	}
	return Local_enuErrorState;
}

ES_t RCC_enuConfigPLL(PLL_Config_t *Copy_PstrPLLcfg)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PstrPLLcfg != NULL)
	{
		/*
		 * Bit 22 PLLSRC: Main PLL(PLL) and audio PLL (PLLI2S) entry clock source
		 * 0: HSI clock selected as PLL and PLLI2S clock entry
		 * 1: HSE oscillator clock selected as PLL and PLLI2S clock entry
		 */
		if(Copy_PstrPLLcfg->PLL_SRC == PLL_SRC_HSI)
		{
			RCC->RCC_PLLCFGR &= ~(MASK_BIT << 22);
			Local_enuErrorState = ES_OK;
		}
		else if(Copy_PstrPLLcfg->PLL_SRC == PLL_SRC_HSE)
		{
			RCC->RCC_PLLCFGR |= (MASK_BIT << 22);
			Local_enuErrorState = ES_OK;
		}
		else
		{
			Local_enuErrorState = ES_OUT_OF_RANGE;
		}

		/* Configure main PLL */
		if(Copy_PstrPLLcfg->PLL_TYP.Main_PLL_CFG.PLL_State != PLL_OFF)
		{
			/*
			 * Bits 5:0 PLLM[5:0]: Division factor for the main PLL (PLL) input clock
			 */
			RCC->RCC_PLLCFGR |= (Copy_PstrPLLcfg->PLL_TYP.Main_PLL_CFG.PLLM_Div_Factor << 0);

			/*
			 * Bits 14:6 PLLN[8:0]: Main PLL (PLL) multiplication factor for VCO
			 */
			RCC->RCC_PLLCFGR |= (Copy_PstrPLLcfg->PLL_TYP.Main_PLL_CFG.PLLN_Mul_Factor << 6);

			/*
			 * Bits 17:16 PLLP[1:0]: Main PLL (PLL) division factor for main system clock
			 */
			RCC->RCC_PLLCFGR |= (Copy_PstrPLLcfg->PLL_TYP.Main_PLL_CFG.PLLP_Div_Factor << 16);

			/*
			 * Bits 27:24 PLLQ[3:0]: Main PLL (PLL) division factor for USB OTG FS, SDIOclocks
			 */
			RCC->RCC_PLLCFGR |= (Copy_PstrPLLcfg->PLL_TYP.Main_PLL_CFG.PLLQ_Div_Factor << 24);

			/*
			 * Bits 30:28 PLLR[2:0]: Main PLL division factor for I2Ss, SAIs, SYSTEM and SPDIF-Rx clocks
			 */
			RCC->RCC_PLLCFGR |= (Copy_PstrPLLcfg->PLL_TYP.Main_PLL_CFG.PLLR_Div_Factor << 28);

			Local_enuErrorState = ES_OK;
		}

		/* Configure PLLSAI */
		if(Copy_PstrPLLcfg->PLL_TYP.PLLSAI_CFG.PLL_State != PLL_OFF)
		{
			Local_enuErrorState = ES_OK;
		}

		/* Configure PLLI2S */
		if(Copy_PstrPLLcfg->PLL_TYP.PLLI2S_CFG.PLL_State != PLL_OFF)
		{
			Local_enuErrorState = ES_OK;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t RCC_enuConfigSYSCLK(SYSCLK_Config_t *Copy_PstrSYSCLKcfg)
{
	ES_t Local_enuErrorState = ES_NOK;

	if(Copy_PstrSYSCLKcfg != NULL)
	{
		/*
		 * Bits 7:4 HPRE: AHB prescaler
		 */
		RCC->RCC_CFGR &= ~(0xF << 4);
		switch(Copy_PstrSYSCLKcfg->AHB_PreScaler)
		{
		case CLK_NOT_DIVIDED:
			RCC->RCC_CFGR &= ~(0xF << 4);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_2:
			RCC->RCC_CFGR |= (0b1000 << 4);
			break;

		case CLK_DIVIDED_by_4:
			RCC->RCC_CFGR |= (0b1001 << 4);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_8:
			RCC->RCC_CFGR |= (0b1010 << 4);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_16:
			RCC->RCC_CFGR |= (0b1011 << 4);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_64:
			RCC->RCC_CFGR |= (0b1100 << 4);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_128:
			RCC->RCC_CFGR |= (0b1101 << 4);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_256:
			RCC->RCC_CFGR |= (0b1110 << 4);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_512:
			RCC->RCC_CFGR |= (0b1111 << 4);
			Local_enuErrorState = ES_OK;
			break;

		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
			break;
		}

		/*
		 * Bits 12:10 PPRE1: APB Low speed prescaler (APB1)
		 */
		RCC->RCC_CFGR &= ~(0x7 << 10);
		switch (Copy_PstrSYSCLKcfg->APB1_PreScaler)
		{
		case CLK_NOT_DIVIDED:
			RCC->RCC_CFGR &= ~(0x7 << 10);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_2:
			RCC->RCC_CFGR |= (0b100 << 10);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_4:
			RCC->RCC_CFGR |= (0b101 << 10);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_8:
			RCC->RCC_CFGR |= (0b110 << 10);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_16:
			RCC->RCC_CFGR |= (0b111 << 10);
			Local_enuErrorState = ES_OK;
			break;

		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
			break;
		}

		/*
		 * Bits 15:13 PPRE2: APB high-speed prescaler (APB2)
		 */
		RCC->RCC_CFGR &= ~(0x7 << 13);
		switch (Copy_PstrSYSCLKcfg->APB2_PreScaler)
		{
		case CLK_NOT_DIVIDED:
			RCC->RCC_CFGR &= ~(0x7 << 13);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_2:
			RCC->RCC_CFGR |= (0b100 << 13);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_4:
			RCC->RCC_CFGR |= (0b101 << 13);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_8:
			RCC->RCC_CFGR |= (0b110 << 13);
			Local_enuErrorState = ES_OK;
			break;

		case CLK_DIVIDED_by_16:
			RCC->RCC_CFGR |= (0b111 << 13);
			Local_enuErrorState = ES_OK;
			break;

		default:
			Local_enuErrorState = ES_OUT_OF_RANGE;
			break;
		}
	}
	else
	{
		Local_enuErrorState = ES_NULL_POINTER;
	}

	return Local_enuErrorState;
}

ES_t RCC_enuAHB1EnableClock(AHB1_Peripheral_t Copy_enuAHB1Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHB1ENR |= (MASK_BIT << Copy_enuAHB1Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_t RCC_enuAHB1DisableClock(AHB1_Peripheral_t Copy_enuAHB1Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHB1ENR &= ~(MASK_BIT << Copy_enuAHB1Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t RCC_enuAHB2EnableClock(AHB2_Peripheral_t Copy_enuAHB2Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHB2ENR |= (MASK_BIT << Copy_enuAHB2Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_t RCC_enuAHB2DisableClock(AHB2_Peripheral_t Copy_enuAHB2Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHB2ENR &= ~(MASK_BIT << Copy_enuAHB2Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t RCC_enuAHB3EnableClock(AHB3_Peripheral_t Copy_enuAHB3Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHB3ENR |= (MASK_BIT << Copy_enuAHB3Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_t RCC_enuAHB3DisableClock(AHB3_Peripheral_t Copy_enuAHB3Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_AHB3ENR &= ~(MASK_BIT << Copy_enuAHB3Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t RCC_enuAPB1EnableClock(APB1_Peripheral_t Copy_enuAPB1Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_APB1ENR |= (MASK_BIT << Copy_enuAPB1Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_t RCC_enuAPB1DisableClock(APB1_Peripheral_t Copy_enuAPB1Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_APB1ENR &= ~(MASK_BIT << Copy_enuAPB1Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}

ES_t RCC_enuAPB2EnableClock(APB2_Peripheral_t Copy_enuAPB2Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_APB2ENR |= (MASK_BIT << Copy_enuAPB2Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
ES_t RCC_enuAPB2DisableClock(APB2_Peripheral_t Copy_enuAPB2Peri)
{
	ES_t Local_enuErrorState = ES_NOK;

	RCC->RCC_APB2ENR &= ~(MASK_BIT << Copy_enuAPB2Peri);
	Local_enuErrorState = ES_OK;

	return Local_enuErrorState;
}
