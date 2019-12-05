
/* Includes ------------------------------------------------------------------*/
#include "stm8s_config.h"

//////////////
volatile uint32_t __us = 0;
volatile uint32_t __ms = 0;
////////////
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
void SETUP()
{
  clk_config_16MHz_hsi();
  ////GPIO////
  GPIO_DeInit(GPIOB);
  GPIO_Init(LED_BUILTIN, GPIO_MODE_OUT_PP_HIGH_FAST);
  /////////
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124); //1ms if fMaster=16Mhz
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE); // cho phep ngat tran TIM4
  TIM4_Cmd(ENABLE);

  enableInterrupts();
}
void delay_ms(volatile uint32_t ms)
{
  if (ms)
  {
    //volatile uint8_t cntr = (uint8_t)TIM4->CNTR;
    volatile uint8_t cntr = TIM4_GetCounter();
    ms += __ms;
    while ((int32_t)__ms < (int32_t)ms)
      ; // Wait ms whole milliseconds
    if (cntr > 1)
      while (TIM4_GetCounter() < cntr)
        ; // Wait fraction millisecond
  }
}
/////////xu ly trong ngat///////////
void TIM4_IT()
{
  ++__ms;
  TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
}

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/