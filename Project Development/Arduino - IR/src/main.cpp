#include "Arduino.h"
extern void __preinit();
#include "IRremote.h"
uint32_t test;
void main()
{
  __preinit();

  pinMode(PA2, INPUT); //pin IR
  pinMode(BUILTIN_LED, OUTPUT);

  Serial.begin(115200);

  Serial.println("ready");
  test = 0;
  while (1)
  {
    test = IR_receiver();
  }
}
