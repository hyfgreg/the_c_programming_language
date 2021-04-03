#include <stdio.h>
#define TAB2SPACE 8
#define MAXLINE 1024

int getLine(char[], int);
void detab(char[], char[]);

int main(int argc, char const *argv[])
{

    char src[MAXLINE], dst[MAXLINE];
    for (int i = 0; i < MAXLINE; i++)
    {
        src[i] = 0;
        dst[i] = 0;
    }
    int len;
    while ((len = getLine(src, MAXLINE)) > 0)
    {
        // printf("tab: %s", src);
        detab(src, dst);
        printf("%s", dst);
    }
    return 0;
}

int getLine(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
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

void detab(char src[], char dst[])
{
    int i, c, spaceCount;
    int j = 0;
    for (i = 0; (c = src[i]) != '\0'; ++i)
    {
        if (c != '\t')
            dst[j++] = c;
        else
        {
            spaceCount = ((j / TAB2SPACE) + 1) * TAB2SPACE - j;
            while (spaceCount-- > 0)
            {
                dst[j++] = ' ';
                
            }
        }
    }
}
