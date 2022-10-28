#ifndef MINI_TALK_H
#define MINI_TALK_H

#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void client(char *server_pid, unsigned char *str);
void    encode(int i, pid_t pid);
void handle_signals();
void handle_SIGUSR1(int sig);
void handle_SIGUSR2(int sig);


 #endif