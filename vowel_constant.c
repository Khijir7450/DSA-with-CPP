#include<stdio.h>
int main()
{
char ch;
printf("enter a alphabet: ");
scanf("%c",&ch);
if((ch>='A' && ch<='Z') || (ch>='a' && ch<='z'))
{
    switch (ch)
    {
    case 'A':
    case 'E':
    case 'I':
    case 'O':
    case 'U':
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    printf("%c is VOWEL.\n",ch);
        break;
    default:
        printf("%c is CONSONANT.\n",ch);
    }
}
else
{
    printf("Betichod!!!!! alphabet enter karne bola tha.\n");
}
return 0;

}