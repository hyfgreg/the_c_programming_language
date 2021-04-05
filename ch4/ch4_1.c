#include <stdio.h>
#define MAXLINE 1024;

int getLine(char[], int);
int strIndex2(char[], char[]);

int main(int argc, char const *argv[])
{
    /* code */
    return 0;
}

int getLine(char s[], int lim)
{
    int c, i;
    i = 0;
    while (--lim > 0 && (c = getchar()) != EOF && c != '\n')
    {
        s[i++] = c;
    }
    if (c == '\n')
    {
        s[i++] = c;
    }
    s[i] = '\0';
    return i;
}