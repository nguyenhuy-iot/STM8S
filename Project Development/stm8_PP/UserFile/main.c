#include "stm8s.h"
#include "stm8s_config.h"
#include "string.h"
#include "Cmd.h"
uint32_t test;
void main(void)
{
  SETUP();
  delay_ms(1000);
  Serial.println("READY...");
  while (1)
  {
    GPIO_WriteHigh(LED_BUILTIN);
    delay_ms(100);
    GPIO_WriteLow(LED_BUILTIN);
    delay_ms(100);
    cmd.Event();
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
