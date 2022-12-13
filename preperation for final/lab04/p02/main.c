#include <stdio.h>

#define N 10

int main()
{
    int a[N];

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &a[i]);
    }

    for (int i = 0; i < N; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");

    int sum = 0;
    for (int i = 0; i < N; i++)
    {
        sum += a[i];
    }
    printf("Sum is %d\n", sum);

    int sum2 = 0;
    for (int *p = a; p != N + a; p++)
    {
        sum2 += *p;
    }
    printf("Sum of elements: %d\n", sum2);
}