#include <stdio.h>
#define MAX 100

static char s[MAX];
static int size = 0;

int getch()
{
    return size ? s[--size] : getchar();
}

int ungetch(char ch)
{
    if (size < MAX)
    {
        s[size++] = ch;
    }
    else
    {
        printf("error, buf is full!\n");
    }
}