#include "mini_talk.h"

int main()
{
    char *str = NULL;
    char *tmp = NULL;

    char *test = "01110 010 01101111 01110011 01100001";
    int i = 0;

    while(test[i] != '\0')
    {
    if (str == NULL)
        str = ft_strdup(" ");
    if (test[i] == '0')
        tmp = ft_strjoin(str, "0");
    else if (test[i] == '1')
        tmp = ft_strjoin(str, "1");
    free(str);
    str = tmp;
    i++;
    }

}