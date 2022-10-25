#ifndef MINI_TALK_H
#define MINI_TALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>

void client(unsigned char *str, pid_t pid);
void    binary(int i, pid_t pid);

#endif