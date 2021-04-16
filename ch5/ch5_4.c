#include <stdio.h>
#include <string.h>

int strends(char *, char *);

int main(int argc, char const *argv[])
{
    char s[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    char t[] = {'a', 'b', 'c', 'd', 'e', '\0'};
    int atEnd = strends(s, t);
    printf("t is at the end of s: %d\n", atEnd);
}

int strends(char *s, char *t)
{
    int slen = strlen(s);
    int tlen = strlen(t);
    if (slen < tlen)
        return 0;
    if (tlen == 0)
        return 1;
    int tmp = slen - tlen;
    while (tmp--)
        s++;
    while (*s && *t && *s++ == *t++)
        ;
    return (*s) ? 0 : 1;
}
