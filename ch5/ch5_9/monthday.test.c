#include <stdio.h>
#include <assert.h>
#include "monthday.h"

int main(int argc, char const *argv[])
{
    int m;
    int d;

    monthday(0, 0, &m, &d);
    assert(m == 0 && d == 0);

    monthday(0, 367, &m, &d);
    assert(m == 0 && d == 0);

    monthday(2020, 60, &m, &d);
    assert(m == 2 && d == 29);

    assert(day_of_year(2021, 1, 31) == 31);

    assert(day_of_year(2021, 0, 0) == -1);

    assert(day_of_year(2020, 3, 1) == 61);

    return 0;
}
