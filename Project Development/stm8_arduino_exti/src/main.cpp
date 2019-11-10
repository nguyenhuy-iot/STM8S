#include "Arduino.h"
#include "exti_conf.h"

extern void __preinit();
extern void setup();
extern void loop();

void main()
{
  __preinit();
  
  /*Config PE0,PD0 as input pull up for external interrupt*/
  GPIO_Init(GPIOD, GPIO_PIN_3, GPIO_MODE_IN_PU_IT);

  EXTI_SetExtIntSensitivity(EXTI_PORT_GPIOD, EXTI_SENSITIVITY_FALL_ONLY);


  enableInterrupts();

  setup();
  /* Infinite loop */
  while (1)
  {
    loop();
  }
}
