#include "Arduino.h"
#include "IRremote.h"

uint32_t IR_receiver()
{
    static uint32_t IR_byte = 0;
    static uint16_t T = 0;
    if (digitalRead(IR_pin) == 0)
    {
        T = pulseIn(IR_pin, HIGH, 15000); //bit start  9ms(low) + 4ms(high)
        if (T > 4000)
        {
            for (uint8_t i = 0; i < 32; i++)
            {
                T = pulseIn(IR_pin, HIGH, 2500); // 600us+1700us
                if (T == 0)
                {
                    IR_byte = 0;
                    return IR_byte; // error
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
        }
    }
    return IR_byte;
}