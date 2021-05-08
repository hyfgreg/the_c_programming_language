#include <stdio.h>
#include <string.h>
#include "readlines.h"
#include "qsort.h"
#include "numcmp.h"

#define MAXLINES 5000

int main(int argc, char const *argv[])
{
    int nlines;
    char *lineptr[MAXLINES];
    int numeric = 0;
    int reverse = 0;
    int ignoreCase = 0;
    int dirOnly = 0;
    int c;
    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'r':
                reverse = 1;
                break;
            case 'n':
                numeric = 1;
                break;
            case 'f':
                ignoreCase = 1;
                break;
            case 'd':
                dirOnly = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                numeric = 0;
                reverse = 0;
                ignoreCase = 0;
                dirOnly = 0;
                break;
            }
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp));
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort!!!\n");
        return 1;
    }
}
