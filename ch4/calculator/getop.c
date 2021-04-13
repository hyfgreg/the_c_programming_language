#include <stdio.h>
#include <ctype.h>
#define BUFSIZE 100
#define NUMBER '0'

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
    return (bufp > 0) ? buf[bufp--] : getchar();
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
    while (isspace((s[0] = c = getch())))
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; // not a number, shoule be operator

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
        ungetch(c);
    }
    return NUMBER;
}