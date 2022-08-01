#include<stdio.h>
int main()
{
    int beng,eng,math,phy,chem;
    int total;
    float per;
    printf("enter the beng number: ");
    scanf("%d",&beng);
    printf("enter the eng number: ");
    scanf("%d",&eng);
    printf("enter the math number: ");
    scanf("%d",&math);
    printf("enter the phy number: ");
    scanf("%d",&phy);
    printf("enter the chem number: ");
    scanf("%d",&chem);
    total= beng+eng+math+phy+chem;
    per=total*100/500;
    printf("\nTotal marks:%d",total);
    printf("\nyour percentage:%f",per);
    if (per>=60/* condition */)
    {
        printf("\nFirst Division");
    }   
   else if (per>=50)
     {
      printf("Second Division");
     }
  else if (per>=40)
     {
     printf("Third Division");
     }
  else
   printf("KUCH PADLO BETICHOD");
        
}
