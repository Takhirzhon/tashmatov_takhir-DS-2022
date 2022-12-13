#include <stdio.h>
#include <stdlib.h>

void reverse(int *beg, int *end);
void printArray(int *beg, int *end);

int main()
{
    printf("Enter size of Array: ");
    int n;
    scanf("%d", &n);

    int *dinArray = (int *)malloc(sizeof(int) * n);
    if (dinArray == NULL)
    {
        printf("Error, not enough memory\n");
        exit(1);
    }

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &dinArray[i]);
    }

    reverse(dinArray, dinArray + n);
    printArray(dinArray, dinArray + n);
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
    while (beg != end)
    {
        --end;
        if (*beg == *end)
        {
            break;
        }

        int t = *beg;
        *beg = *end;
        *end = t;

        beg++;
    }
}