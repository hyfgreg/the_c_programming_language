#include <stdio.h>

void _reverse(char s[], int *left, int *right)
{
    // 双指针, right先到最后，然后left从前往后，right从后往前, 一边交换元素一边移动
    char c = s[(*right)++];
    if (c != '\0')
    {
        _reverse(s, left, right);
        s[(*left)++] = c;
    }
}

void reversex(char s[])
{
    int left = 0;
    int right = 0;
    _reverse(s, &left, &right);
    return;
}

int main(int argc, char const *argv[])
{
    char s[] = "0123456789";
    printf("s: %s\n", s);
    reversex(s);
    printf("reverse s: %s\n", s);
    return 0;
}
