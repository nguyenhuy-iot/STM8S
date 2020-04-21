#include <math.h>
#include "string.h"
#include "stm8s_config.h"
#include "Cmd.h"

Cmd_cushion text;
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
//xu ly cac truong hop
void Command::run(const char *str)
{
    Serial.print("cmd:  ");
    Serial.print(text._Buf);
    if (strstr(text._Buf, "ON"))
    {
        Serial.println("bat den");
    }
    else if (strstr(text._Buf, "OFF"))
    {
        Serial.println("tat den");
    }
    else
    {
        Serial.println("what?");
        Serial.println(cmd.parseInt(text._Buf));
        Serial.println(text._Buf);
        Serial.println(cmd.parseInt(text._Buf));
        Serial.println(text._Buf);
    }
}
//chiet xuat du lieu khi co tin hieu
void Command::Event()
{
    if (Serial.available() > 0)
    {
        do
        {
            text._Buf[text._len] = Serial.read();
            if (text._Buf[text._len] == '\n') //ket thuc '\n'
            {
                cmd.run(text._Buf); //chay xu ly
                //xoa bo dem
                memset(text._Buf, '\0', sizeof(text._Buf));
                text._len = 0;
            }
            else
            {
                text._len >= (SIZE_BUF - 1) ? text._len = 0 : text._len++; //trang bo dem
            }
        } while (Serial.available() > 0);
    }
}
//cho nhap lenh bang tay
void Command::wait()
{
    char buffer[SIZE_BUF] = "", l = 0;
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
        cmd.run(buffer); //chay xu ly
    }
}
//chiet xuat so nguyen
uint32_t Command::parseInt(char *str)
{
    uint8_t i = 0;
    uint32_t value = 0;
    // chay den vi tri so
    while (str[i] < '0' || str[i] > '9')
    {
        i++;
    }
    //chi nhan so
    while (str[i] >= '0' && str[i] <= '9')
    {
        value = value * 10 + (str[i] - '0');
        str[i] = ' '; //xoa
        i++;
    }
    return value;
}
//chiet xuat so hex
uint32_t Command::parseHex(char *str)
{
    uint8_t i = 0;
    uint32_t value = 0;
    //(str[i] >= '0' && str[i] <= '9')||(str[i] >= 'a' && str[i] <= 'f')||(str[i] >= 'A' && str[i] <= 'F')
    while (!((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')))
    { //tim den so hex
        i++;
    }
    while (((str[i] >= '0' && str[i] <= '9') || (str[i] >= 'a' && str[i] <= 'f')))
    { //chi nhan so hex
        if (str[i] >= '0' && str[i] <= '9')
        {
            value = value * 0x10 + (str[i] - '0');
        }
        else if (str[i] >= 'a' && str[i] <= 'f')
        {
            value = value * 0x10 + (str[i] - 'a' + 10);
        }
        else
        {
            /* code */
        }
        str[i] = ' '; //xoa
        i++;
    }
    return value;
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