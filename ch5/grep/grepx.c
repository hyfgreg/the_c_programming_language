#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "getlinex.h"

#define MAXLINE 1000

// version 1
// int main(int argc, char const *argv[])
// {
//     char *line = (char *)malloc(MAXLINE);
//     int found = 0;
//     if (argc != 2)
//         printf("Usage： find pattern\n");
//     else
//         while (getlinex(line, MAXLINE) > 0)
//             if (strstr(line, argv[1]) != NULL)
//             {
//                 printf("%s", line);
//                 found++;
//             }
//     return found;
// }

// version 2
int main(int argc, char const *argv[])
{
    char *line = (char *)malloc(MAXLINE);
    long lineno = 0;
    int c, except = 0, number = 0, found = 0;
    while (--argc > 0 && (*++argv)[0] == '-')
        while (c = *++argv[0])
            switch (c)
            {
            case 'x':
                except = 1;
                break;
            case 'n':
                number = 1;
                break;
            default:
                printf("find: illegal option %c\n", c);
                argc = 0;
                found = -1;
                break;
            }
    if (argc != 1)
        printf("Usage: find -x -n pattern\n");
    else
    {
        if (except)
        {
            printf("ignore: %s\n", *argv);
        }
        else
        {
            printf("grep: %s\n", *argv);
        }
        while (getlinex(line, MAXLINE) > 0)
        {
            lineno++;
            if ((strstr(line, *argv) != NULL) != except)
            {
                if (number)
                {
                    printf("%ld: ", lineno);
                }
                printf("%s", line);
                found++;
            }
        }
    }

    return found;
}
