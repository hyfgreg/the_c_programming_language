#include <stdio.h>

int main(int argc, char const *argv[])
{
    // version 1
    // int i;
    // for (i = 1; i < argc; i++)
    // {
    //     printf("%s%s", argv[i], (i < argc - 1) ? " " : "");
    // }
    // printf("\n");
    // return 0;

    // version 2
    while (--argc > 0)
    {
        // printf("%s%s", *++argv, (argc > 1) ? " " : "");
        printf(argc > 0 ? "%s ": "%s", *++argv);
    }
    printf("\n");
    return 0;
}
