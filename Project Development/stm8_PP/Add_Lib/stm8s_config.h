

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_CONFIG_H
#define __STM8S_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include <stddef.h>
#include "stm8s.h"

#define LED_BUILTIN GPIOB, GPIO_PIN_5

extern volatile uint32_t __us;
extern volatile uint32_t __ms;
///////////////////
void clk_config_16MHz_hse(); // Initialize clock module, run in mode external crystal HSE
void clk_config_16MHz_hsi(); // Initialize clock module, run in mode internal crystal HSI
void SETUP();
void TIM4_IT(); // xu ly ngat TIM4
void TIM1_IT(); // xu ly ngat TIM1
void delay_ms(volatile uint32_t ms);
void delay_us(volatile uint32_t us);
uint32_t pulseIn(GPIO_TypeDef *GPIOx, GPIO_Pin_TypeDef GPIO_Pin, bool state, uint32_t timeout = 1000000L);
///////////
inline uint32_t micros()
{
    return (__us | TIM1->CNTRL);
}

inline uint32_t millis()
{
    return __ms;
}

#endif /* __STM8S_CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
