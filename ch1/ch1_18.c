#include <stdio.h>
#define MAXLINE 1024

int getLine(char[], int);
int rstrip(char[], int len);

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    for (int i = 0; i < MAXLINE; i++)
        line[i] = 0;
    int len = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        if ((len = rstrip(line, len)) > 0)
            printf("len: %d, line: %s", len, line);
    }
    return 0;
}

int getLine(char line[], int lim)
{
    int i, c;
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

int rstrip(char line[], int len)
{
    /*return the length after rstrip*/
    int i = len - 2;
    char c;
    while (i >= 0)
    {
        c = line[i];
        if (c != ' ' && c != '\t')
        {
            break;
        }
        i--;
    }
    line[++i] = '\n';
    line[++i] = '\0';
    return i - 1;
}