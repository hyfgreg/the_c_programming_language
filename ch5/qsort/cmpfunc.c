#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <ctype.h>

int numcmp(char *a, char *b, int reverse)
{
    double i = atof(a);
    double j = atof(b);
    int ret;
    // printf("i %f, j %f\n", i, j);
    if (i < j)
        ret = -1;
    else if (i > j)
        ret = 1;
    else
        ret = 0;

    if (reverse)
        ret *= -1;
}

int strcmpx(char *v1, char *v2, int reverse, int ignoreCase, int dirOnly)
{
    int ret = 0;
    char c1, c2;
    while (1)
    {
        c1 = *v1;
        c2 = *v2;
        if (!c1 || !c2)
            break;
        if (dirOnly)
        {
            if (!isalnum(c1) && !isspace(c1))
            {
                v1++;
                continue;
            }
            if (!isalnum(c2) && !isspace(c2))
            {
                v2++;
                continue;
            }
        }
        if (ignoreCase)
        {
            c1 = tolower(c1);
            c2 = tolower(c2);
        }
        if (c1 != c2)
        {
            ret = (c1) < (c2) ? -1 : 1;
            break;
        }
        v1++;
        v2++;
    }
    if (!(*v1) && (*v2))
        ret = -1;
    if (*v1 && !(*v2))
        ret = 1;
    if (reverse)
        ret *= -1;
    return ret;
}

void test_ingoreCase()
{
    char str1[] = {'A', 'b', 'C', 'D', '1', '2', '-', '_', '\0'};
    char str2[] = {'a', 'B', 'c', 'd', '1', '2', '-', '_', '\0'};
    int ret = strcmpx(str1, str2, 0, 1, 0);
    assert(ret == 0);
}

int main(int argc, char const *argv[])
{
    // char *v1 = "look";
    // char *v2 = "lookly";
    // int ret = strcmpx(v1, v2, 0, 0);
    // assert(ret == -1);

    // ret = strcmpx(v1, v2, 1, 0);
    // assert(ret == 1);

    // v1 = "aaa";
    // v2 = "baaa";
    // ret = strcmpx(v1, v2, 0, 0);
    // assert(ret == -1);

    // ret = strcmpx(v1, v2, 1, 0);
    // assert(ret == 1);
    test_ingoreCase();
    return 0;
}
