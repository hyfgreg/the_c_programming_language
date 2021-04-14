#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define BUFSIZE 100
#define NUMBER '0'
#define print(x) printf(x);printf("\n")

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    int tmp;
    // printf("before getch, bufp: %d\n", bufp);
    if (bufp > 0)
    {
        tmp = buf[--bufp];
        // printf("get buf[%d]: %d\n", bufp + 1, tmp);
    }
    else
    {
        // printf("use getchar\n");
        tmp = getchar();
        // printf("getchar %d\n", tmp);
    }
    // return (bufp > 0) ? buf[--bufp] : getchar();
    return tmp;
}

void ungetch(int c)
{
    if (bufp >= BUFSIZE)
    {
        printf("ungetch: too many characters!\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
    {
        // print("is space!!!");
    }
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
    {
        // printf("is not a number, return: %d\n", c);
        return c; // not a number, shoule be operator
    }

    i = 0;
    if (isdigit(c))
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.')
        while (isdigit(s[++i] = c = getch()))
            ;

    s[i] = '\0';
    if (c != EOF)
    {
        // printf("c %d is not EOF, ungetch\n", c);
        ungetch(c);
    }
    return NUMBER;
}