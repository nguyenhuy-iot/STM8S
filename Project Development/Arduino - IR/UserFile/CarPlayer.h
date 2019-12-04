#ifndef CarPlay_h
#define CarPlay_h
#include "Arduino.h"
#include "IRremote.h"

#define M1_A_pin PC7
#define M1_B_pin PC6
#define M2_A_pin PC5
#define M2_B_pin PC4

void Car_setup();

void PWM_TIM4();
void Car_Stop();
void Car_Up();
void Car_Down();
void Car_Player();

#endif