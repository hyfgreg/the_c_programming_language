#include <stdio.h>

static int daytab[2][13] = {
    {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
    {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
};

int isleap(int year)
{
    return year % 4 == 0 && year % 100 != 0 || year % 400 == 0;
}

void monthday(int year, int day, int *pm, int *pd)
{
    if (day <= 0)
    {
        *pm = 0;
        *pd = 0;
        return;
    }
    int leap = isleap(year);
    int i;
    for (i = 1; day > *(*(daytab + leap) + i); i++)
    {
        if (i == 12)
        {
            *pd = 0;
            *pm = 0;
            return;
        }
        day -= *(*(daytab + leap) + i);
    }
    *pm = i;
    *pd = day;
}

int day_of_year(int year, int month, int day)
{
    if (month < 1 || month > 12)
        return -1;
    int leap = isleap(year);
    if (day > *(*(daytab + leap) + month))
        return -1;
    int i;
    for (i = 1; i < month; i++)
    {
        day += *(*(daytab + leap) + i);
    }
    return day;
}