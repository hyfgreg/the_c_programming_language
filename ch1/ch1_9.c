#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, lastIsSpace;
    lastIsSpace = 0;
    while ((c = getchar()) != EOF)
    {
        if (c != ' ')
        {
            putchar(c);
            lastIsSpace = 0;
        }
        else if (!lastIsSpace)
        {
            putchar(c);
            lastIsSpace = 1;
        }
    }
    return 0;
}
