#include <string.h>

void swap(void *v[], int i, int j)
{
    void *tmp = v[i];
    v[i] = v[j];
    v[j] = tmp;
}
void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *))
{
    if (left >= right)
        return;
    int i, last;
    swap(lineptr, left, (left + right) / 2);
    last = left;
    for (i = left + 1; i <= right; i++)
    {
        if ((*comp)(lineptr[i], lineptr[left]) < 0)
            swap(lineptr, ++last, i);
    }
    swap(lineptr, left, last);
    qsort(lineptr, left, last - 1, comp);
    qsort(lineptr, last + 1, right, comp);
}