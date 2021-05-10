#include <limits.h>
#include <stdio.h>

void bit_print(int a)
{
    int i;
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n - 1);
    for (i = 1; i <= n; i++)
    {
        putchar(((a & mask) == 0) ? '0' : '1');
        a <<= 1;
        if (i % CHAR_BIT == 0 && i < n)
            putchar(' ');
    }
    putchar('\n');
}

int main(int argc, char const *argv[])
{
    int n = sizeof(int) * CHAR_BIT;
    int mask = 1 << (n - 1);
    printf("mask:\n");
    bit_print(mask);
    for (int i = 0; i < 32; i++)
        bit_print(i);
    return 0;
}
