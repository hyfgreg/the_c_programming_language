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
    if (argc > 1 && strcmp(argv[1], "-n") == 0)
        numeric = 1;
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
