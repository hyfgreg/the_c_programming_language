#include <stdio.h>
#include <string.h>
#include "readlines.h"
#include "qsort.h"

#define MAXLINES 5000

int main(int argc, char const *argv[])
{
    int nlines;
    char *lineptr[MAXLINES];
    if ((nlines = readlines(lineptr, MAXLINES)) >= 0)
    {
        qsort(lineptr, 0, nlines - 1);
        writelines(lineptr, nlines);
        return 0;
    }
    else
    {
        printf("error: input too big to sort!!!\n");
        return 1;
    }
}
