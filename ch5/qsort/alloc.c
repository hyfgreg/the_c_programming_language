#include <stddef.h>
#define BUFFERSIZE 1000
static char buffer[BUFFERSIZE];
static char *bufp = buffer;

char *alloc(int n)
{
    if (buffer + BUFFERSIZE - bufp >= n)
    {
        bufp += n;
        return bufp - n;
    }
    return NULL;
}

void afree(char *p)
{
    bufp = p;
}