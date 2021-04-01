#include <stdio.h>
#define IN 1  // inside a word
#define OUT 0 // outside a word

int main(int argc, char const *argv[])
{
    int c, nl, nw, nc, state;
    nl = nw = nc = 0;
    while ((c = getchar()) != EOF)
    {
        ++nc;
        if (c == '\n')
        {
            nl++;
        }
        if (c == ' ' || c == '\n' || c == '\t')
        {
            state = OUT; // 当前到了单词外
        }
        else if (state == OUT)
        {
            // 当前进入了一个单词
            nw++;
            state = IN;
        }
    }
    printf("\nlines: %d, words: %d\n", nl, nw);
    return 0;
}
