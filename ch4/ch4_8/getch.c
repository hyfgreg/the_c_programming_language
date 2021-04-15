#include <stdio.h>

static char c;

int getch()
{
    char rt = c ? c : getchar();
    c = '\0';
    return rt;
}

int ungetch(char ch)
{
    if (c)
    {
        printf("error: ch buffer is full!\n");
        return -1;
    }
    else
    {
        c = ch;
        return 0;
    }
}