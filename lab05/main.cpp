#include <stdio.h>
#include <stdlib.h>

void printArray(int *beg, int *end);
void reverse(int *beg, int *end);

int main()
{
    // vector<int> v;
    int *data = NULL;
    size_t sz = 0;
    size_t cp = 0;

    puts("enter arbitrary number of intger values:");
    int x;
    while (scanf("%d", &x) == 1)
    {
        // v.push_back(x);
        if (sz == cp)
        {
            cp = (cp == 0) ? 1 : 2 * cp;
            int *newData = (int *)malloc((sizeof(int) * cp));
            for (size_t i = 0; i < sz; ++i)
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