#include<stdio.h>
int main ()
{
int sum =0,x;
printf("Enter an integer \n");
scanf("%d",&x);

for(int i=1 ;i<=x;i++)
{
    sum=sum+i;
}
printf("sum = %d",sum);
}
