#include <stdio.h>

void readArray(int *p, int n);
void printArray(int *beg, int *end);

#define N 5
#define M 3

int main()
{
    int a[N];
    int b[M];

    readArray(a, N);
    readArray (b, M);

    printArray(a, a + N);
    printArray(b, b + M);
}

void printArray(int *beg, int *end)
{
    while(beg != end)
    {
        printf("%d ", *beg++);
    }
    printf("\n");
}
void readArray(int *p, int n)
{
    while(n--)
    {
        scanf("%d", p++);
    }

}