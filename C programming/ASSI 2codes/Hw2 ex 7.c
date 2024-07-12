#include<stdio.h>
int main ()
{
signed long sum =1,x;
printf("Enter an integer \n");
scanf("%d",&x);
if (x<=0)
    printf("Error!!! Factorial of negative number doesn't exist. ");
for(int i=1 ;i<=x;i++)
{
    sum=sum*i;
}
printf("sum = %d",sum);
}
