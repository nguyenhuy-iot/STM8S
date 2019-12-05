

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_CONFIG_H
#define __STM8S_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"

#define LED_BUILTIN GPIOB, GPIO_PIN_5

///////////////////
void clk_config_16MHz_hse(); // Initialize clock module, run in mode external crystal HSE
void clk_config_16MHz_hsi(); // Initialize clock module, run in mode internal crystal HSI
void SETUP();
void delay_ms(volatile uint32_t ms);
void TIM4_IT(); // xu ly ngat TIM4

#endif /* __STM8S_CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
