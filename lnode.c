#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define HASHSIZE 101

struct nlist
{
    struct nlist *next;
    char *name;
    char *defn;
};

static struct nlist *hashtab[HASHSIZE];

char *strdup(char *s)
{
    char *p;
    p = (char *)malloc(strlen(s) + 1); /* +1 for '\0' */
    if (p != NULL)                     /* 没有可用空间时, malloc返回NULL */
    {
        strcpy(p, s);
    }
    return p;
}

unsigned hash(char *s)
{
    unsigned hashval;
    for (hashval = 0; *s != '\0'; s++)
    {
        hashval = *s + 31 * hashval;
    }
    return hashval % HASHSIZE;
}

/* 这个智障的查找函数就是个线性查找 */
struct nlist *lookup(char *s)
{
    struct nlist *np;
    for (np = hashtab[0]; np != NULL; np = np->next)
    {
        if (strcmp(s, np->name) == 0)
            return np;
    }
    return NULL;
}

struct nlist *install(char *name, char *defn)
{
    struct nlist *np;
    unsigned hashval;

    if ((np = lookup(name)) == NULL)
    {
        np = (struct nlist *)malloc(sizeof(*np));
        if (np == NULL || (np->name = strdup(name)) == NULL)
            return NULL;
        hashval = hash(name);
        np->next = hashtab[hashval];
        hashtab[hashval] = np; // 这里的next指向了自己啊，为何又要用hashval又要用链表
    }
    else
    {
        free((void *)np->defn); // 这里用心的定义替换了旧的定义
    }
    if ((np->defn = strdup(defn)) == NULL)
        return NULL;
    return np;
}