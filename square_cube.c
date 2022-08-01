#include<stdio.h>

int main()
{
	int count,n;
    printf("Enter the number: ");
    scanf("%d",&n);
    count=1;
    start:
    printf("num:%d square:%d cube:%d \n",count,(count*count),(count*count*count));
    count++;
    if(count<=n)
    goto start;
    return 0;
}