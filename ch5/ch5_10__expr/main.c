#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "getop.h"
#include "stack.h"
#include "isnumfmt.h"

#define MAXOP 100
#define NUMBER '0'

int main(int argc, char *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while (--argc > 0 && (*++argv)[0] != '\0')
    {
        if (isnumfmt(*argv))
        {
            push(atof(*argv));
        }
        else if (!strcmp(*argv, "+"))
        {
            push(pop() + pop());
        }
        else if (!strcmp(*argv, "-"))
        {
            op2 = pop();
            push(pop() - op2);
        }
        else if (!strcmp(*argv, "*"))
        {
            push(pop() * pop());
        }
        else if (!strcmp(*argv, "/"))
        {
            op2 = pop();
            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                pop();
                push(0.0);
                printf("error, zero divisor\n");
            }
        }
        else if (!strcmp(*argv, "%"))
        {
            op2 = pop();
            if (op2 != 0.0)
            {
                push(fmod(pop(), op2));
            }
            else
            {
                pop();
                push(0.0);
                printf("error, zero modulo\n");
            }
        }
        else if (!strcmp(*argv, "pow"))
        {
            op2 = pop();
            int op1 = pop();
            if (op1 == 0.0 && op2 <= 0)
            {
                printf("error, pow zero divisor\n");
                push(0.0);
            }
            else
            {
                push(pow(op1, (int)op2));
            }
        }
        else if (!strcmp(*argv, "sin"))
        {
            push(sin(pop()));
        }
        else if (!strcmp(*argv, "exp"))
        {
            push(exp(pop()));
        }
        else if (!strcmp(*argv, "\n"))
        {
            printf("%8g\n", pop());
        }
        else
        {
            printf("error: unknown command %s\n", *argv);
        }
    }
    printf("%8g\n", pop());
    clearStack();
    return 0;
}
