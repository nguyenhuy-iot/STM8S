
/* Includes ------------------------------------------------------------------*/
#include "stm8s_config.h"

void clk_config_16MHz_hse(void)
{
  CLK_DeInit();
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSE, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}

void clk_config_16MHz_hsi(void)
{
  CLK_DeInit();
  CLK_SYSCLKConfig(CLK_PRESCALER_CPUDIV1);
  CLK_SYSCLKConfig(CLK_PRESCALER_HSIDIV1);
  CLK_ClockSwitchConfig(CLK_SWITCHMODE_AUTO, CLK_SOURCE_HSI, DISABLE, CLK_CURRENTCLOCKSTATE_DISABLE);
}

void delay(volatile uint16_t ms)
{
  while (ms--)
  {
    int16_t us = 1000;
    while (us--)
    {
      //nop();
      //nop();
      nop();
      nop();
      nop();
      nop();
      nop();
      nop();
      nop();
      nop();
      nop();
    }
  }
}

void GPIO_Config(void)
{
  //    OUT
  GPIO_Init(LED_BUILTIN, GPIO_MODE_OUT_PP_LOW_FAST);
}
void UART_Config(void)
{
  UART1_DeInit();
  /* UART1 configuration ------------------------------------------------------*/
  /* UART1 configured as follow:
        - BaudRate = 115200 baud  
        - Word Length = 8 Bits
        - One Stop Bit
        - No parity
        - Receive and transmit enabled
        - UART1 Clock disabled
  */
  UART1_Init((uint32_t)115200, UART1_WORDLENGTH_8D, UART1_STOPBITS_1, UART1_PARITY_NO,
             UART1_SYNCMODE_CLOCK_DISABLE, UART1_MODE_TXRX_ENABLE);
  //UART1_ITConfig(UART1_IT_RXNE_OR, ENABLE);
  //UART1_Cmd(ENABLE); //enableInterrupts();
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/