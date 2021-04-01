#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAXWORD 1000

int getword(char *, int);
struct key
{
    char *word;
    int count;
};
struct key *binsearch(char *, struct key *, int);

struct key keytab[] = {
    "auto", 0,
    "break", 0,
    "case", 0,
    "char", 0,
    "const", 0,
    "continue", 0,
    "default", 0,
    /* ... */
    "unsigned", 0,
    "void", 0,
    "volatile", 0,
    "while", 0};

#define NKEYS (sizeof keytab / sizeof(struct key))

main()
{
    struct key *p;
    char word[MAXWORD];

    while (getword(word, MAXWORD) != EOF)
        if (isalpha(word[0]))
            if ((p = binsearch(word, keytab, NKEYS)) >= 0)
                p->count++;
    for (p = keytab; p < keytab + NKEYS; p++)
    {
        if (p->count > 0)
        {
            printf("%4d %s\n", p->count, p->word);
        }
    }
    return 0;
}

struct key *binsearch(char *word, struct key *tab, int n)
{
    int cond;
    struct key *low = tab;
    struct key *high = tab + n;
    struct key *mid;

    low = 0;
    high = n - 1;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if ((cond = strcmp(word, mid->word)) < 0)
            high = mid - 1;
        else if (cond > 0)
            low = mid + 1;
        else
            return mid;
    }
    return -1;
}

int getword(char *word, int lim)
{
    int c, getch(void);
    void ungetch(int);
}