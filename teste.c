#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

int binary(int x);

int main (int argc, char **argv)
{  
    int i;

    i = 0; 
    while(argv[1][i] != '\0')
    {
        binary(argv[1][i]);
        printf("\n");
        i++;
    }
}

int binary(int x)
{
    if (x <= 0)
        return (1);
    binary(x / 2);
    printf ("%d", (x % 2));
}
