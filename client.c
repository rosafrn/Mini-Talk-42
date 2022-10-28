#include "mini_talk.h"

int main (int argc, char **argv)
{
    if (argc != 3)
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
        send_encode(str[i], pid);
            i++;
    }
}

void    send_encode(int i, pid_t pid)
{
    int x;

    x = 0;
    while(x < 8)
    {
        if ((i >> x) & 1)
            kill(pid, SIGUSR2);
        else
            kill(pid, SIGUSR1);
        usleep(30);
        x++;
    }
}

