#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#define MAXLINE 1024

double xatof(char[]);

int main(int argc, char const *argv[])
{
    int len = MAXLINE;
    char *line = NULL;
    if ((line = malloc(len + 1)) == NULL)
    {
        printf("fuck! cannot allocate %d mem", len);
        exit(-1);
    }
    while (getline(&line, &len, stdin) > 0)
        // printf("%s", line);
        printf("%g\n", xatof(line));
    free(line);
    return 0;
}

double xatof(char s[])
{
    double val = 0.0;
    int power = 1;
    int i;
    int sign = 1;

    int esign = 1;
    int epower = 0;
    long eval = 1;

    for (i = 0; isspace(s[i]); i++)
        ;
    if (s[i] == '+' || s[i] == '-')
    {
        sign = s[i] == '+' ? 1 : -1;
        i++;
    }
    for (; isdigit(s[i]); i++)
    {
        val = 10 * val + (s[i] - '0');
    }
    if (s[i] == '.')
    {
        i++;
    }
    for (; isdigit(s[i]); i++)
    {
        val = 10 * val + (s[i] - '0');
        power *= 10;
    }
    if (s[i] == 'e' || s[i] == 'E')
    {
        i++;
    }
    if (s[i] == '-' || s[i] == '+')
    {
        esign = s[i] == '+' ? 1 : -1;
        i++;
    }
    for (; isdigit(s[i]); i++)
    {
        epower = 10 * epower + (s[i] - '0');
    }
    while (epower-- > 0)
    {
        eval *= 10;
    }
    return esign > 0 ? (sign * val / power) * eval : (sign * val / power) / eval;
}