#include<stdio.h>

int  factorial (int a);
int main ()
{
    int start;

    printf("Enter an postivie integer: ");
    scanf("%d" ,&start);
    factorial(start);


}


int factorial (int a)
{
 static int fac=1 ;
fac = a*fac;
a--;
if (a>0)
factorial(a);
else
printf("%d",fac);
}
