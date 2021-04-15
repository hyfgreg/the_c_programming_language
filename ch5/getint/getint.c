#include <stdio.h>
#include <ctype.h>
#include "./getch.h"

#define SIZE 100

int getint(int *pn)
{
    int c, sign;
    while (isspace(c = getch()))
        ; // ignore space
    if (!isdigit(c) && c != EOF && c != '+' && c != '-')
    {
        ungetch(c);
        return 0;
    }
    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-')
    {
        int tmp = getch();
        if (!isdigit(tmp))
        {
            ungetch(tmp);
            ungetch(c);
            return 0;
        }
        c = tmp;
    }
    for (*pn = 0; isdigit(c); c = getch())
    {
        *pn = 10 * *pn + (c - '0');
    }
    *pn *= sign;
    if (c != EOF)
        ungetch(c);
    return c;
}

int main(int argc, char const *argv[])
{
    int n, array[SIZE];
    for (n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
        printf("array[%d]: %d\n", n, array[n]);
    return 0;
}
