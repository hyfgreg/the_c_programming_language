#include <stdio.h>
#include <string.h>
#include <stddef.h>

#include "getlinex.h"
#include "alloc.h"

#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines)
{
    int len, nlines;
    char *p, line[MAXLEN];
    nlines = 0;
    while ((len = getlinex(line, MAXLEN)) > 0)
    {
        if (nlines >= maxlines || (p = alloc(len)) == NULL)
            return -1;
        else
        {
            // printf("address of p: %d\n", p);
            line[len - 1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
            // printf("get line: %s, fuck\n", p);
        }
    }
    // printf("get %d lines\n", nlines);
    return nlines;
}

void writelines(char *lineptr[], int nlines)
{
    int i;
    for (i = 0; i < nlines; i++)
    {
        printf("%s\n", lineptr[i]);
    }
}
