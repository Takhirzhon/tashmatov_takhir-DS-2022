#include <stdio.h>
#include <stdlib.h>

void printArray(int *beg, int *end);
void reverse(int *beg, int *end);

int main()
{
    printf("Size of Array: ");
    int n;
    scanf("%d", &n);

    int *dinArray = (int *)malloc(n * sizeof(int));
    if (dinArray == NULL)
    {
        printf("Not enough memory");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dinArray[i]);
    }

    reverse(dinArray, n + dinArray);

    printArray(dinArray, n + dinArray);

    free(dinArray);
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
    for (;;)
    {
        if (beg == end)
        {
            break;
        }

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