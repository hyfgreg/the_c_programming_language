#include <stdio.h>
#define MAXLINE 1024

char pattern[] = "ould";

int getLine(char[], int);
int strIndex(char[], char[]);

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
        s[i++] = c;
    s[i] = '\0';
    return i;
}

int strIndex(char s[], char t[])
{
    int i, j, k;

    for (i = 0; s[i] != '\0'; i++)
    {
        for (j = i, k = 0; t[k] != '\0' && s[j] == t[k]; j++, k++)
            ;
        if (k > 0 && t[k] != '\0')
            return i;
    }
    return -1;
}