/*
check if a char[] is number format
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isnumfmt(char number[])
{
    int len = strlen(number);
    int pointExist = 0;
    for (int i = 0; i < len; i++)
        if (!isdigit(number[i]) && number[i] != '.')
            return 0;
        else if (number[i] == '.')
        {
            if (pointExist)
                return 0;
            else
                pointExist = 1;
        }
    if (pointExist && len == 1)
        return 0;
    return 1;
}