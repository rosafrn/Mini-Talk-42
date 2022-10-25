#ifndef MINI_TALK_H
#define MINI_TALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void client(pid_t pid, unsigned char *str);
void    encode(int i, pid_t pid);

#endif