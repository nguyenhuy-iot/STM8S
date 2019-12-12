
/* Includes ------------------------------------------------------------------*/
#include "stm8s_config.h"
static uint32_t test = 0;
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
  GPIO_DeInit(GPIOA);
  GPIO_Init(LED_BUILTIN, GPIO_MODE_OUT_PP_HIGH_FAST);
  GPIO_Init(GPIOA, GPIO_PIN_1, GPIO_MODE_IN_PU_NO_IT);
  ////Setup EXTI/////
  GPIO_Init(GPIOA, GPIO_PIN_2, GPIO_MODE_IN_PU_IT);
  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOA, EXTI_SENSITIVITY_RISE_ONLY);
  ////Setup TIM4/////
  TIM4_TimeBaseInit(TIM4_PRESCALER_128, 124); //1ms if fMaster=16Mhz (16 MHz / 128 = 125 kHz / 125 = 1 kHz = 1 ms)
  TIM4_ClearFlag(TIM4_FLAG_UPDATE);
  TIM4_ITConfig(TIM4_IT_UPDATE, ENABLE); // cho phep ngat tran TIM4
  TIM4_Cmd(ENABLE);
  ///////Setup TIM1///////
  TIM1_TimeBaseInit(15, TIM1_COUNTERMODE_UP, 255, 0); //(16 MHz / 16 = 1 MHz / 256 ~ 3906 Hz)
  TIM1_ClearFlag(TIM1_FLAG_UPDATE);
  TIM1_ITConfig(TIM1_IT_UPDATE, ENABLE); // cho phep ngat tran TIM1
  TIM1_Cmd(ENABLE);

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
void delay_us(volatile uint32_t us)
{
  if (us > 2)
  {
    if (us < 256)
    {
      volatile uint8_t cntr = TIM1->CNTRL;
      cntr += (uint8_t)us;
      while ((int8_t)TIM1->CNTRL < (int8_t)cntr)
        ;
    }
    else
    {
      us += micros();
      while ((int32_t)micros() < (int32_t)us)
        ; // Wait us microseconds
    }
  }
}

uint32_t pulseIn(GPIO_TypeDef *GPIOx, GPIO_Pin_TypeDef GPIO_Pin, bool state, uint32_t timeout)
{

  uint32_t start = micros(), pulsestart;

  while (GPIO_ReadInputPin(GPIOx, GPIO_Pin) == state)
  { // Wait for pulse gap or timeout
    if ((int32_t)(micros() - start) >= (int32_t)timeout)
      return 0;
  }
  while (GPIO_ReadInputPin(GPIOx, GPIO_Pin) != state)
  { // Wait for pulse starts or timeout
    if ((int32_t)(micros() - start) >= (int32_t)timeout)
      return 0;
  }
  pulsestart = micros();
  while (GPIO_ReadInputPin(GPIOx, GPIO_Pin) == state)
  { // Wait for pulse ends or timeout
    if ((int32_t)(micros() - start) >= (int32_t)timeout)
      return 0;
  }

  return (micros() - pulsestart);
}
/////////xu ly trong ngat///////////
void TIM4_IT()
{
  ++__ms;
  TIM4_ClearITPendingBit(TIM4_IT_UPDATE);
}
void TIM1_IT()
{
  __us += 256;
  TIM1_ClearITPendingBit(TIM1_IT_UPDATE);
}
/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/