#ifndef __CMD_H
#define __CMD_H

#include <stddef.h>
#include "stm8s.h"

//kich thuoc bo dem tuong tu Serial.h ...static const uint8_t RXBUFSIZE = 16, TXBUFSIZE = 16;
#define SIZE_BUF 64

//dinh dang bien goi bo dem
struct Cmd_cushion
{
    char _Buf[SIZE_BUF];
    uint8_t _len;
};

class Command
{
public:
    bool find(char *target, uint32_t timeout = 1000); // find returns true if the target string is found
    void run(const char *str);
    void Event();
    void wait();
    uint32_t parseInt(char *str);
    uint32_t parseHex(char *str);
};

extern Command cmd;
////////////
int JAS_IndexOf(const char *text, const char *key); // tim chuoi trong chuoi tong
#endif
