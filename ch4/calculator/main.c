#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#include "getop.h"
#include "stack.h"
#include "isnumfmt.h"

#define MAXOP 100
#define NUMBER '0'

int main(int argc, char const *argv[])
{
    int type;
    double op2;
    char s[MAXOP];

    while (1)
    {
        getop(s);
        if (s[0] == EOF)
        {
            break;
        }
        if (isnumfmt(s))
        {
            push(atof(s));
        }
        else if (!strcmp(s, "+"))
        {
            push(pop() + pop());
        }
        else if (!strcmp(s, "-"))
        {
            op2 = pop();
            push(pop() - op2);
        }
        else if (!strcmp(s, "*"))
        {
            push(pop() * pop());
        }
        else if (!strcmp(s, "/"))
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
        else if (!strcmp(s, "%"))
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
        else if (!strcmp(s, "pow"))
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
        else if (!strcmp(s, "sin"))
        {
            push(sin(pop()));
        }
        else if (!strcmp(s, "exp"))
        {
            push(exp(pop()));
        }
        else if (!strcmp(s, "\n"))
        {
            printf("%8g\n", pop());
        }
        else
        {
            printf("error: unknown command %s\n", s);
        }
        // switch (type)
        // {
        // case NUMBER:
        //     /* code */
        //     push(atof(s));
        //     break;
        // case '+':
        //     // printf("meet + , plus\n");
        //     push(pop() + pop());
        //     break;
        // case '*':
        //     push(pop() * pop());
        //     break;
        // case '-':
        //     op2 = pop();
        //     push(pop() - op2);
        //     break;
        // case '/':
        //     op2 = pop();
        //     if (op2 != 0.0)
        //     {
        //         push(pop() / op2);
        //     }
        //     else
        //     {
        //         printf("error: zero divisor\n");
        //     }
        //     break;
        // case '%':
        //     op2 = pop();
        //     if (op2 != 0.0)
        //     {
        //         push(fmod(pop(), op2));
        //     }
        //     else
        //     {
        //         // 非法取模，但是要把这几个数和操作符号干掉，否则整个表达式就卡在这里了
        //         pop();
        //         push(0.0);
        //         printf("error: zero modulo\n");
        //     }
        //     break;
        // case '\n':
        //     // printf("meet \\n, print res\n");
        //     printf("\t%.8g\n", pop());
        //     break; // break is neccessary!!!
        // default:
        //     printf("error: unknown command %s\n", s);
        //     break;
        // }
    }
    clearStack();
    return 0;
}
