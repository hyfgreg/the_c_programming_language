/*
check if a char[] is number format
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isnumfmt(char *number)
{
    int pointExist = 0;
    int i;
    printf("%s\n", number);
    for (i = 0; *(number + i) != '\0'; i++)
        if (!isdigit(*(number + i)) && *(number + i) != '.')
            return 0;
        else if (*(number + i) == '.')
        {
            if (pointExist)
                return 0;
            else
                pointExist = 1;
        }
    if (pointExist && i == 1)
        return 0;
    return 1;
}