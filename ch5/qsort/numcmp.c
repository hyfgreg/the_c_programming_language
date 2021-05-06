#include <stdlib.h>

int numcmp(char *a, char *b)
{
    double i = atof(a);
    double j = atof(b);
    // printf("i %f, j %f\n", i, j);
    if (i < j)
        return -1;
    else if (i > j)
        return 1;
    else
        return 0;
}