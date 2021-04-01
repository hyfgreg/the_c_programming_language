#include <stdio.h>
#define IN 1
#define OUT 0
#define WORDCOUNT 20

int main(int argc, char const *argv[])
{
    int wordLength[WORDCOUNT + 1];
    int c, state, current, max;
    state = OUT;
    current = 0;
    max = 0;
    for (int i = 0; i < WORDCOUNT + 1; i++)
    {
        wordLength[i] = 0;
    }
    while ((c = getchar()) != EOF)
    {
        if (c == ' ' || c == '\t' || c == '\n')
        {
            if (state == IN)
            {
                wordLength[current]++;
                if (wordLength[current] > max)
                    max = wordLength[current];
                current = 0;
                state = OUT;
            }
        }
        else
        {
            if (state == OUT)
            {
                state = IN;
                current++;
            }
            else
            {
                current++;
            }
        }
    }
    if (current > 0)
        wordLength[current]++;

    if (wordLength[current] > max)
        max = wordLength[current];

    printf("\n");
    for (int i = 0; i < WORDCOUNT + 1; i++)
    {
        printf("%d ", wordLength[i]);
    }
    printf("\n");
    for (int i = max; i > 0; i--)
    {
        for (int j = 0; j < WORDCOUNT + 1; j++)
        {
            if (wordLength[j] >= i)
                printf("  |");
            else
                printf("   ");
        }
        printf("\n");
    }
    for (int i = 0; i < WORDCOUNT + 1; i++)
    {
        printf("%3d", i);
    }
    printf("\n");
    return 0;
}
