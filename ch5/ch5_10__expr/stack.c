#include <stdio.h>
#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        // printf("push %g\n", f);
        val[sp++] = f;
    }
    else
        printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
    if (sp > 0)
        return val[--sp];
    printf("error: stack empty!\n");
    return 0.0;
}

double getPeak(void)
{
    if (sp > 0)
    {
        return val[sp - 1];
    }
    printf("error: stack empty!\n");
    return 0.0;
}

void printPeak(void)
{
    printf("the peak of stack is: %g\n", getPeak());
    return;
}

void swap(void)
{
    if (sp > 1)
    {
        double tmp = val[sp - 1];
        val[sp - 1] = val[sp - 2];
        val[sp - 2] = tmp;
    }
    else
    {
        printf("error: stack size is less than 2\n");
    }
    return;
}

void clearStack(void)
{
    sp = 0;
    return;
}