#include <string.h>

void swap(char *v[], int i, int j)
{
    char *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
void qsort(char *lineptr[], int left, int right)
{
    if (left >= right)
        return;
    int i, last;
    swap(lineptr, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if (strcmp(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    }
    swap(lineptr, left, last);
    qsort(lineptr, left, last - 1);
    qsort(lineptr, last + 1, right);
}