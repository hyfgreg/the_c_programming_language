/*
 * Exercise 1-12
 * Write a program that prints its input one word per line.
 */

#include <stdio.h>
#define IN 1
#define OUT 0

int main(int argc, char const *argv[])
{
    int c = 0;
    int state = OUT;
    while ((c = getchar()) != EOF)
    {
        if (state == OUT)
        {
            if (c == '\t' || c == ' ' || c == '\n')
            {
                continue;
            }
            else
            {
                putchar(c);
                state = IN;
            }
        }
        else if (state == IN)
        {
            if (c == '\t' || c == ' ' || c == '\n')
            {
                putchar('\n');
                state = OUT;
            }
            else
            {
                putchar(c);
            }
        }
    }
    return 0;
}
