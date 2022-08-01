#include<stdio.h>

int fib_recursive(int n)
{
    if (n==1||n==2)
    {
        return 1;
    }
    else
    {
        return fib_recursive(n-1)+fib_recursive(n-2);
    }
    
    return 0;
}


/*int fib_iterative(int n)
{
    return 0;
}*/

int main()
{
    int number;
    printf("enter the index to get fibonacci series\n");
    scanf("%d",&number);
   // printf("the value of fibonacci number at position no %d using iterative approch is %d\n",number,fib_iterative);
    printf("the value of fibonacci number at position no %d using recursive approch is %d\n",number,fib_recursive(number));
    return 0;
}