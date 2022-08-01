#include <stdio.h>
int main()
{
    int math, phy;
    printf("\nif you pass on math or phy then you won an Iphone,if you pass on both then you won a Macbook.");
    printf("\nEnter your math number: ");
    scanf("%d", &math);
    printf("\nEnter your phy number: ");
    scanf("%d", &phy);
    if (math >= 50 && phy >= 50)
    {
        printf("\nYou won a Macbook.");
    }
    else if (math >= 50 || phy >= 50)
    {
        printf("\nyou won an Iphone.");
    }
    else
    {
        printf("\ntumse kuch na hoga.");
    }
    return 0;
}