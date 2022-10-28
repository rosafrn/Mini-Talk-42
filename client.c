#include "mini_talk.h"

int main (int argc, char **argv)
{
    if (argc != 2)
        return (1);
    client(argv[1], argv[2]);
}

void client(char *server_pid, unsigned char *str)
{
    int i;
    pid_t pid;

    i = 0;
    pid = atoi(server_pid);
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
            kill(SIGUSR2, pid);
        else
            kill(SIGUSR1, pid);
        x--;
    }
}

