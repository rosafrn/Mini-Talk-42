#include "mini_talk.h"

int main (int argc, char **argv)
{
    pid_t pid;

    pid = getpid();
    //printf("PID: %d\n", pid);
    if (argc == 2)
        client(pid, argv[1]);
    else 
        return (1);

}

void client(pid_t pid, unsigned char *str)
{
    int i;

    i = 0;
    while(str[i] != '\0')
    {
        encode(str[i], pid);
        i++;
        printf(" ");
    }
}

void    encode(int i, pid_t pid)
{
    int x;

    x = 7;
    while(x >= 0)
    {
        if ((i >> x) & 1)
            printf("1");
        else
            printf("0");
        x--;
    }
    /*if ((i % 2) == 0)
        kill(SIGUSR1, pid);
    else
        kill(SIGUSR2, pid);*/
}
