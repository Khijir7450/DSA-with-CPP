#include<stdio.h>
int main()
{
    int beng,eng,meth,phy,chem,bio,total;
    float per;
    printf("\nenter your beng num: ");
    scanf("%d",&beng);
    printf("\nenter your eng num: ");
    scanf("%d",&eng);
    printf("\nenter your math num: ");
    scanf("%d",&meth);
    printf("\nenter your phy num: ");
    scanf("%d",&phy);
    printf("\nenter your chem num: ");
    scanf("%d",&chem);
    printf("\nenter your bio num: ");
    scanf("%d",&bio);
    total=beng+eng+meth+phy+chem+bio;
    printf("\nyour total number is %d out of 600",total);
    per=total*100/600;
    printf("\nyour percentej is %.2f",per);
    if(per>=90&&per<=100)
       printf("\nBah Bete Bah!!!!! tumne too mojjjj kardi");
    else if (per>=80&&per<=89)
       printf("\nBOHOT khub Beta");
    else if (per>=65&&per<=79)
       printf("\nisse jada milega,agar a66a se padega too");
    else if (per<=44&&per>=0)
       printf("\nbeta tum kuch nehi kar paoge!!!");
    
    
return 0;

    
}