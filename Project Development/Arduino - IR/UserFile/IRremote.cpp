#include "Arduino.h"
#include "IRremote.h"

uint16_t IR_receiver()
{
    static uint16_t IR_byte = 0, T;
    if (digitalRead(IR_pin) == 0)
    {
        for (uint8_t i = 0; i < 16; i++)
        {
            T = pulseIn(IR_pin, HIGH, 25000);
            if (T == 0)
            {
                return -1; //FFFF
            }
            if (T < 1000) //1ms
            {
                IR_byte = IR_byte * 2; //bit 0 ~600us
            }
            else
            {
                IR_byte = IR_byte * 2 + 1; //bit 1 ~1700us
            }
        }
        return IR_byte;
    }
    return 0;
}