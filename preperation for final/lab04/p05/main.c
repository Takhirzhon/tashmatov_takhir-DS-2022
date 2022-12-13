#include <stdlib.h>
#include <stdio.h>

void reverse(int *beg, int *end);
void printArray(int *beg, int *end);

int main(void)
{

    int *data = NULL;
    size_t sz = 0;
    size_t cp = 0;

    printf("Enter arbitariray numbers of int values: ");
    int x;
    while (scanf("%d", &x) == 1)
    {
        if (sz == cp)
        {
            if (cp == 0)
            {
                cp = 1;
            }
            else
            {
                cp * 2;
            }

            int *newData = (int *)malloc(sizeof(int) * cp);

            for (size_t i = 0; i < sz; i++)
            {
                newData[i] = data[i];
            }
            free(data);
            data = newData;
        }
        data[sz++] = x;
    }
    printArray(data, data + sz);
    reverse(data, data + sz);
    printArray(data, data + sz);

    free(data);
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