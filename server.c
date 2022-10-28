#include "mini_talk.h"

int main()
{
    pid_t pid;
    struct sigaction sa;

    sa.sa_handler = &handle_SIGUSR;
    sa.sa_flags = SA_SIGINFO;
    sigaction(SIGUSR1, &sa, NULL);
    sigaction(SIGUSR2, &sa, NULL);
    pid = getpid();
    if (pid == -1)
        return (1);
    printf("PID: %d\n", pid);
    while (1)
		pause();
    return(0);
}

void handle_SIGUSR(int sig)
{
    static int i;
    static char letter;

    if (sig == SIGUSR2 || sig == SIGUSR1)
    {
        if (sig == SIGUSR2)
		    letter |= (1 << i);
        i++;
        if (i == 8)
        {
            write(1, &letter, 1);
            letter = 0;
            i = 0;
        }
    }
}

/*void print_decode()
{
 
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
}*/