#include <stdio.h>

int main(int argc, char const *argv[])
{
    float celsius;

    for(float fahr = 300.0;fahr>=0;fahr-=20){
        celsius = (5.0 / 9.0) * (fahr - 32.0);
        printf("%10.0f %7.1f\n", fahr, celsius);
    }
    return 0;
}
