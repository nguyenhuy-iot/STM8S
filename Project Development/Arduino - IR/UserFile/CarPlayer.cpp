#include "CarPlayer.h"

static uint8_t PWM_M1_A, PWM_M1_B, PWM_M2_A, PWM_M2_B;

void Car_setup()
{
    pinMode(M1_A_pin, OUTPUT);
    pinMode(M1_B_pin, OUTPUT);

    digitalWrite(M1_A_pin, HIGH);
    digitalWrite(M1_B_pin, HIGH);
}

void PWM_TIM4()
{
    static uint8_t Count_PWM = 0;

    if (Count_PWM < PWM_M1_A)
    {
        digitalWrite(M1_A_pin, LOW);
    }
    else
    {
        digitalWrite(M1_A_pin, HIGH);
    }
    if (Count_PWM < PWM_M1_B)
    {
        digitalWrite(M1_B_pin, LOW);
    }
    else
    {
        digitalWrite(M1_B_pin, HIGH);
    }

    if (Count_PWM < 4)
    {
        Count_PWM++;
    }
    else
    {
        Count_PWM = 0;
    }
}
void Car_Stop()
{
    PWM_M1_A = 0;
    PWM_M1_B = 0;
}
void Car_Up()
{
    PWM_M1_A = 3;
    PWM_M1_B = 0;
}
void Car_Down()
{
    PWM_M1_A = 0;
    PWM_M1_B = 3;
}
void Car_Player()
{
    uint32_t control = IR_receiver();
    if (control != 0)
    {
        if (control == Key[0])
        {
            Serial.print("0: ");
        }
        else if (control == Key[1])
        {
            Serial.print("1: ");
        }
        else if (control == Key[2])
        {
            Car_Up();
            Serial.print("2: ");
        }
        else if (control == Key[3])
        {
            Serial.print("3: ");
        }
        else if (control == Key[4])
        {
            Serial.print("4: ");
        }
        else if (control == Key[5])
        {
            Car_Stop();
            Serial.print("5: ");
        }
        else if (control == Key[6])
        {
            Serial.print("6: ");
        }
        else if (control == Key[7])
        {
            Serial.print("7: ");
        }
        else if (control == Key[8])
        {
            Car_Down();
            Serial.print("8: ");
        }
        else if (control == Key[9])
        {
            Serial.print("9: ");
        }
        else
        {
            /* code */
        }
        Serial.println(control);
    }
}