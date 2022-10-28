#include "mini_talk.h"

char *str;

int main()
{
    pid_t pid;

    str = NULL;
    pid = getpid();
    if (pid == -1)
        return (1);
    printf("PID: %d\n", pid);
    handle_signals();
    // char *str = "01110010";
    // char *tmp = NULL;
    // int z = 0;

    // int i = 0;
    // while (i < 8)
    // {
    //     if (str[i] == '1')
    //     {
    //         z = (z * 2) + 1;
    //     }
    //     else 
    //         z = (z * 2) + 0;
    //     i++;   
    // }
    // char x = z;
    // printf("%c", x);
}

void handle_signals()
{
    struct sigaction sa;

    sa.sa_handler = &handle_SIGUSR;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
}

void handle_SIGUSR(int sig)
{
    char *tmp;
    
    if (str == NULL)
        str = strdup(" ");
    if (sig == SIGUSR1)
        strjoin(str, "0");
    else if (sig == SIGUSR2)
        strjoin(str, "1");
}