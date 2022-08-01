#include <stdio.h>
int main()
{
    int i, t;
    printf("\nEnter the number which table you want:");
    scanf("%d", &t);
    i = 1;
    printf("multiplecation table of %d is:", t);
start:
    if (i <= 10)
    {
        printf("\n%d*%d=%d", t, i, t * i);
        i++;
        goto start;
    }

    return 0;
}