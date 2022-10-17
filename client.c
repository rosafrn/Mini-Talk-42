#include "mini_talk.h"

int main (int argc, char **argv)
{
    pid_t pid;

    pid = getpid();
    client(argv[1], pid);

}


void client(char *signals, pid_t pid)
{
    printf("%d\n", pid);
    printf("%s\n", signals);
    // while(signals != NULL)
    // {
        
    // }
}

