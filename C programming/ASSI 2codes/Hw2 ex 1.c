#include<stdio.h>
int main ()
{
    int x,y=1;

    while (y==1)
    {
        printf("Enter an integer you want to check : ");
    scanf(" %d" ,&x);
    if (x%2==0)
    printf("%d is even \n",x);
    else
    printf("%d is odd \n", x);

    printf("if you need another output press 1 \n");
    scanf("%d",&y);

    }



}
