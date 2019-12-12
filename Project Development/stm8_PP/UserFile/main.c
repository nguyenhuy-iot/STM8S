#include "stm8s.h"
#include "stm8s_config.h"
extern void __preinit();
bool T;
void main(void)
{
  SETUP();
  //delay_ms(100);
  T = pulseIn(GPIOA, GPIO_PIN_1,0,3000000);
  while (1)
  {
    GPIO_WriteHigh(LED_BUILTIN);
    delay_us(100000);
    GPIO_WriteLow(LED_BUILTIN);
    delay_ms(100);
  }
}

/* User Function */

#ifdef USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param file: pointer to the source file name
  * @param line: assert_param error line source number
  * @retval : None
  */
void assert_failed(u8 *file, u32 line)
{
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
