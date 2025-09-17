#include<stdio.h>
int main()
{
    int n;
    printf("Enter weekday number (0-6):");
    scanf("%d",&n);
    switch (n)
    {
    case 0:printf("sunday");
    break;
    case 1:printf("monday");
    break;
    case 2:printf("Tuesday");
    break;
    case 3:printf("Wednesday");
    break;
    case 4:printf("Thursday");
    break;
    case 5:printf("Friday");
    break;
    case 6:printf("Saterday");
        break;
    default:
    printf("Motherfucker!!!! week main 7 din hota hain. \n");

}
return 0;
}