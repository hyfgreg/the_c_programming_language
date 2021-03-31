#include <stdio.h>

int main(int argc, char const *argv[])
{
    int c = getchar() != EOF;
    printf("getchar() != EOF == %d\n",c);
    return 0;
}
