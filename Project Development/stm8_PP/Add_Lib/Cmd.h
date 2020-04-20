#ifndef __CMD_H
#define __CMD_H

#include <stddef.h>
#include "stm8s.h"

class Command
{
public:
    bool find(char *target, uint32_t timeout = 1000); // find returns true if the target string is found
    void run();
};

extern Command cmd;
////////////
int JAS_IndexOf(const char *text, const char *key); // tim chuoi trong chuoi tong
#endif
