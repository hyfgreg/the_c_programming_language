#include <stdio.h>

int main(int argc, char const *argv[])
{
    printf("\thello, world\n");
    for (int i = 0; i < argc; i++)
    {
        printf("%s\t", argv[i]);
    }
    printf("\n");
    return 0;
}
