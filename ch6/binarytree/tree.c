#include <stddef.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct tnode
{
    char *word;
    int count;
    struct tnode *left;
    struct tnode *right;
};

struct tnode *talloc(void)
{
    return (struct tnode *)malloc(sizeof(struct tnode));
}

char *wordcpy(char *src)
{
    char *dst;
    dst = (char *)malloc(strlen(src) + 1);
    if (dst != NULL)
        strcpy(dst, src);
    return dst;
}

struct tnode *addtree(struct tnode *node, char *word)
{
    int cmp;
    if (node == NULL)
    {
        node = talloc();
        node->word = wordcpy(word);
        node->count = 1;
    }
    else if ((cmp = strcmp(node->word, word)) == 0)
    {
        node->count++;
        return node;
    }
    else if (cmp < 0)
    {
        node->left = addtree(node->left, word);
    }
    else
    {
        node->right = addtree(node->right, word);
    }
    return node;
}

void treeprint(struct tnode *node)
{
    if (node == NULL)
    {
        return;
    }
    treeprint(node->left);
    printf("%s, %d\n", node->word, node->count);
    treeprint(node->right);
}

// struct tnode *binsearch(char *word, struct tnode *node, int n)
// {
// }

int main(int argc, char const *argv[])
{
    struct tnode *root = NULL;
    char *words[] = {
        "hahaha",
        "lalala",
        "lululu",
        "yoyoyo",
        "xixixi",
        "bibibi"};
    char *word;
    for (int i = 0; i < 6; i++)
    {
        word = words[i];
        root = addtree(root, word);
    }
    treeprint(root);
    return 0;
}
