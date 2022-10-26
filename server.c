#include "mini_talk.h"

int main()
{
    char *str = "01110010";
    char *tmp = NULL;
    int z = 0;

    int i = 0;
    while (i < 8)
    {
        if (str[i] == '1')
        {
            z = (z * 2) + 1;
        }
        else 
            z = (z * 2) + 0;
        i++;   
    }
    char x = z;
    printf("%c", x);
}