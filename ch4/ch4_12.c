#include <stdio.h>
#include <string.h>
#define MAXLEN 100

void itoax(int n, char number[])
{
    if (n / 10)
    {
        itoax(n / 10, number);
    }
    int len = strlen(number);
    char tmp = (n % 10) + '0';
    number[len] = tmp;
    number[++len] = '\0';
    return;
}

int main(int argc, char const *argv[])
{
    int n = 123;
    char number[MAXLEN];
    itoax(n, number);
    printf("n: %d to char[]: %s\n", n, number);
    return 0;
}
