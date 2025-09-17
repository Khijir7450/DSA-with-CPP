#include<stdio.h>
int main()
{
float a,p,r,t,i;
printf("\nenter the initial amount = ");
scanf("%f",&p);
printf("\nenter annual interest rate = ");
scanf("%f",&r);
printf("\nenter the time duration in years = ");
scanf("%f",&t);
i=p*r*t/100;
printf("\nyour interest is = %.1f",i);
a=p+p*r*t/100;
printf("\nyour final amount is = %.2f",a);
return 0;



}