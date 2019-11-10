#ifndef __exti_conf_h
#define __exti_conf_h

#include "Arduino.h"
#include "stm8s_gpio.h"
#include "stm8s_exti.h"

INTERRUPT void EXTI_PORTA_IRQHandler(void); /* EXTI PORTA */
INTERRUPT void EXTI_PORTB_IRQHandler(void); /* EXTI PORTB */
INTERRUPT void EXTI_PORTC_IRQHandler(void); /* EXTI PORTC */
INTERRUPT void EXTI_PORTD_IRQHandler(void); /* EXTI PORTD */
INTERRUPT void EXTI_PORTE_IRQHandler(void); /* EXTI PORTE */
#endif