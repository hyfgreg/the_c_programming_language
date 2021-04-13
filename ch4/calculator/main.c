#include <stdio.h>
#include <stdlib.h>

#include "getop.h"
#include "stack.h"

#define MAXOP 100
#define NUMBER '0'

int main(int argc, char const *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            /* code */
            push(atof(s));
            break;
        case '+':
            push(pop() + pop());
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            op2 = pop();
            push(pop() - op2);
            break;
        case '\n':
            printf("\t%.8g\n", pop());

        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}
