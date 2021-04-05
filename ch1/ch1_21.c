/*
 * Exercise 1-21
 * Write a program entab that replaces strings of blanks
 * by the minimum number of tabs and blanks to achieve the same spacing.
 * Use the same tab stops as for detab.
 * When either a tab or a single blank would suffice to reach a tab stop,
 * which should be given preference?
 */
#include <stdio.h>
#define TABN 8
#define MAXLINE 1024

int getLine(char[], int);
void entab(char[]);

// for readable, switch the space with '-'
int main(int argc, char const *argv[])
{
    char line[MAXLINE];
    for (int i = 0; i < MAXLINE; i++)
    {
        line[i] = 0;
    }
    while (getLine(line, MAXLINE))
    {
        entab(line);
        printf("%s", line);
    }
    return 0;
}

int getLine(char line[], int lim)
{
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
    {
        line[i] = c;
    }
    if (c == '\n')
    {
        line[i] = c;
        i++;
    }
    line[i] = '\0';
    return i;
}

void entab(char line[])
{
    /* tab to space */
    // 思路: 找到tab的固定的终止位置，把挨着这个位置并且在位置之前的连续空格换成tab

    int i, c;
    int spaceStartIndex = -1;
    int j;
    for (i = 0; (c = line[i]) != '\0'; i++)
    {
        if (i != 0 && (i % TABN) == 0)
        {
            if (spaceStartIndex != -1)
            {
                for (j = spaceStartIndex; j < i; j++)
                {
                    line[j] = '-';
                }
                spaceStartIndex = -1;
            }
        }
        if (c != ' ')
        {
            spaceStartIndex = -1;
        }
        else if (spaceStartIndex == -1)
        {
            spaceStartIndex = i;
        }
    }
}