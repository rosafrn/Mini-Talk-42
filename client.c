#include "mini_talk.h"

int main (int argc, char **argv)
{
    pid_t pid;

    pid = getpid();
    printf("PID: %d\n", pid);
    if (argc == 2)
        client(argv[1], pid);
    else 
        return (1);

}


void client(char *str, pid_t pid)
{
    printf("%s\n", str);
    // while(signals != NULL)
    // {
        
    // }
}

char *binary(char *str)
{
    char *tmp;

    tmp = str;
    while (tmp != NULL)
    {
        
    }
}

