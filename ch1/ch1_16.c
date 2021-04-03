#include <stdio.h>
#define MAXLINE 1024

int getLine(char[], int);
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    for (int i = 0; i < MAXLINE; i++)
    {
        line[i] = 0;
    }
    int len;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        // for ch1_17,
        // if(len > 80) then printf
        printf("%s", line);
    }
    return 0;
}
int getLine(char line[], int lim)
{
    int c;
    int i;
    for (i = 0; i < lim && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        ++i;
    }
    line[i] = '\0';
    return i;
}
