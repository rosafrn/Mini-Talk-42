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
    print_decode();
    free (str);
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
        str = ft_strdup(" ");
    if (sig == SIGUSR1)
        tmp = ft_strjoin(str, "0");
    else if (sig == SIGUSR2)
        tmp = ft_strjoin(str, "1");
    free(str);
    str = tmp;
}

void print_decode()
{
    int letter;
    int i;
    int x;

    i = 0;
    while (str[i] != '\0')
    {
        letter = 0;
        x = 0;
        while (x < 8 && str[i] != '\0')
        {
            letter <<= 1;// Shift the values in result left once.  Same ase
                // result *= 2;
            // if intMe[i] == '0', we don't do anything.
            if (str[i] == '1')
                letter += 1;
            i++;
            x++;
        }
        write(1, &letter, 1);
        i++; 
    }
}