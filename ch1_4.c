#include <stdio.h>

int main(int argc, char const *argv[])
{
    float fahr, celsius;
    float lower, upper, step;

    lower = -50;
    upper = 100;
    step = 10;

    celsius = lower;
    printf("Celsius Fahrenheit\n");
    while (celsius <= upper)
    {
        // celsius = (5.0 / 9.0) * (fahr - 32.0);
        fahr = celsius * (9.0 / 5.0) + 32.0;
        printf("%7.0f %10.1f\n", celsius, fahr);
        celsius += step;
    }
    return 0;
}
