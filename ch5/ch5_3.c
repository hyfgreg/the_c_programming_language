#include <stdio.h>

void strcatx(char *, char *);

int main(int argc, char const *argv[])
{
    /* code */
    char s[100] = {'a', 'b', '\0'};
    char t[100] = {'c', 'd', '\0'};
    strcatx(s, t);
    printf("%s\n", s);
    return 0;
}

void strcatx(char *s, char *t)
{
    /*copy t to the taif of s*/
    while (*s)
        s++;
    while (*s = *t)
    {
        s++;
        t++;
    }
}