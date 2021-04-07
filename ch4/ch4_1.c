#include <stdio.h>
#include <string.h>
#define MAXLINE 1024

int getLinex(char[], int);
int strIndex2(char[], char[]);

int main(int argc, char *argv[])
{
    /* code */
    if (argc == 1)
    {
        printf("you must input a target word!!!");
        return -1;
    }
    char *word = argv[1];
    char line[MAXLINE];
    int i;
    while (getLinex(line, MAXLINE) > 0)
    {
        if ((i = strIndex2(line, word)) >= 0)
        {
            printf("word %s index is %d\n", word, i);
        }
        else
        {
            printf("not exists!\n");
        }
    }
    return 0;
}

int getLinex(char s[], int lim)
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

int strIndex2(char s[], char t[])
{
    int ssize = strlen(s);
    int tsize = strlen(t);
    if (ssize < tsize)
        return -1;
    int i = ssize - tsize;
    int j, k;
    while (i >= 0)
    {
        k = 0;
        for (j = i; s[j] == t[k] && k < tsize; j++, k++)
            ;
        if (k == tsize)
            return i;
        i--;
    }
    return -1;
}