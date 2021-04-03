#include <stdio.h>
#define MAXLINE 1024

void reverse(char[], int);
int getLine(char line[], int lim);

int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    for (int i = 0; i < MAXLINE; i++)
    {
        line[i] = 0;
    }
    int len = 0;
    while ((len = getLine(line, MAXLINE)) > 0)
    {
        printf("before %s", line);
        reverse(line, len - 1);
        printf("after %s", line);
    }
    return 0;
}

void reverse(char line[], int len)
{
    /*assert '\n' not in line*/
    int first, last;
    char tmp;
    first = 0;
    last = len - 1;
    while (first < last)
    {
        tmp = line[first];
        line[first] = line[last];
        line[last] = tmp;
        first++;
        last--;
    }
    return;
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