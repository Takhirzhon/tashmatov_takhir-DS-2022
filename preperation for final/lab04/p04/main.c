#include <stdio.h>
#include <stdlib.h>

void printArray(int *beg, int *end);
void reverse(int *beg, int *end);

int main()
{
    puts("Enter size of array: ");
    int x;
    scanf("%d", &x);

    int *dinArray = (int *)malloc(sizeof(int) * x);
    if (dinArray == NULL)
    {
        printf("Memory error\n");
        exit(1);
    }

    for (size_t i = 0; i < x; i++)
    {
        scanf("%d", &dinArray[i]);
    }

    reverse(dinArray, dinArray + x);
    printArray(dinArray, dinArray + x);
}

void printArray(int *beg, int *end)
{
    while (beg != end)
    {
        printf("%d ", *beg++);
    }
    printf("\n");
}
void reverse(int *beg, int *end)
{
    while (beg != end)
    {
        --end;
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