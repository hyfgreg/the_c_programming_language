#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c, nt, ns, nn;
    nt = 0;
    ns = 0;
    nn = 0;
    while ((c = getchar()) != EOF)
    {
        if (c == '\t')
        {
            nt++;
        }
        else if (c == ' ')
        {
            ns++;
        }
        else if (c == '\n')
        {
            nn++;
        }
    }
    printf("tab: %3d, space: %3d, enter: %3d\n", nt, ns, nn);
    return 0;
}
