#include<stdio.h>
int main ()
{
char c;
float x,y;
printf("Enter operator either + or - or * or divided:\n  ");
scanf(" %c" ,&c);
printf("Enter two operands : \n");
scanf("%f%f",&x,&y);


switch(c)
{
    case '+':
    {
       printf("%.2f %c %.2f = %.2f",x,c,y,x+y);

    }
    break;
    case '-':
    {
       printf("%.2f %c %.2f = %.2f",x,c,y,x-y);

    }
    break;
    case '*':
    {
       printf("%.2f %c %.2f = %.2f",x,c,y,x*y);

    }
    break;
    case '/':
    {
       printf("%.2f %c %.2f = %.2f",x,c,y,x/y);

    }
    break;


}
}
