#include "VecInt.h"
#include <stdio.h>

void printArray(int *beg, int *end);
void reverse(int *beg, int *end);
void p01();
void p02();

int main()
{
    p01();
    p02();
}

void p01()
{
    printf("Enter size of Array: \n");
    int x;
    scanf("%d", &x);
    struct VecInt v;
    VecInt_createOfSize(&v, x, 0);

    for (int i = 0; i < x; i++)
    {
        scanf("%d", &v.data[i]);
    }
    reverse(v.data, v.data + x);
    printArray(v.data, v.data + x);

    VecInt_destroy(&v);
}

void p02()
{
    struct VecInt v;
    VecInt_createEmpty(&v);
    puts("Enter arbitrary numbers: ");
    int x;
    while (scanf("%d", &x) == 1)
    {
        VecInt_pushBack(&v, x);
    }
    printArray(v.data, v.data + v.sz);
    reverse(v.data, v.data + v.sz);
    printArray(v.data, v.data + v.sz);

    VecInt_destroy(&v);
}

void printArray(int *beg, int *end)
{
    while (beg != end)
    {
        printf("%d", *beg++);
    }
    printf("\n");
}

void reverse(int *beg, int *end)
{
    while (beg != end)
    {
        end--;
        if (beg == end)
        {
            break;
        }

        int t = *beg;
        *beg = *end;
        *end = t;

        beg++;
    }
}