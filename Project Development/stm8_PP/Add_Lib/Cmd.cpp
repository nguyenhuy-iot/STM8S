#include <math.h>
#include "string.h"
#include "stm8s_config.h"
#include "Cmd.h"

// find returns true if the target string is found
bool Command::find(char *target, uint32_t timeout)
{
    uint32_t _startMillis = millis();
    uint8_t l = strlen(target);
    uint8_t i = 0;
    do
    {
        if (millis() - _startMillis > timeout)
        {
            return false;
        }
        if (Serial.read() == target[i])
        {
            i++;
            l--;
        }
        else
        {
            if (i > 0)
            {
                return false;
            }
        }

    } while (l > 0);
    return true;
}
void Command::run()
{
    char buffer[16] = "", l = 0;
    if (Serial.available() > 0) //cho nhan lenh
    {
        while (1)
        {
            buffer[l] = Serial.read();
            Serial.print(buffer[l]);
            if (buffer[l] == '\n')
            {
                break;
            }

            l++;
        }
        Serial.print("cmd:  ");
        Serial.print(buffer);
        //xu ly
        if (strstr(buffer, "ON"))
        {
            Serial.println("bat den");
        }
        else if (strstr(buffer, "OFF"))
        {
            Serial.println("tat den");
        }
        else
        {
            Serial.println("what?");
        }
    }
}
Command cmd;

/////////tim chuoi trong chuoi/////
int JAS_IndexOf(const char *text, const char *key)
{
    int index = -1;
    const char *found = strstr(text, key);
    if (found != NULL)
        index = found - text;
    return index;
}