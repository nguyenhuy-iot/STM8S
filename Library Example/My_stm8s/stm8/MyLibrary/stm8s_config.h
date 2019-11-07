

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __STM8S_CONFIG_H
#define __STM8S_CONFIG_H

/* Includes ------------------------------------------------------------------*/
#include "stm8s.h"
#include "Serial.h"
#include "Print.h"

#define LED_BUILTIN GPIOB, GPIO_PIN_5

void clk_config_16MHz_hse(void); // Initialize clock module, run in mode external crystal HSE
void clk_config_16MHz_hsi(void); // Initialize clock module, run in mode internal crystal HSI
void delay(volatile uint16_t ms);
void GPIO_Config(void); //  setup GPIO
void UART_Config(void); // setup UART

#endif /* __STM8S_CONFIG_H */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
