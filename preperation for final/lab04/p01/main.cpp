#include <stdio.h>
int main()
{
    int x;
    int y;
    int *p;

    x = 1;
    p = &x;

    printf("x = %d\n", x);
    printf("address of x: %p\n", (void *)p);
    printf("value of x: %d\n", *p);

    *p = 2;

    printf("new value of x: %d\n", x);
    printf("new value of x: %d\n", *p);

    y = *p * *p;
    printf("value of y: %d\n", y);
}