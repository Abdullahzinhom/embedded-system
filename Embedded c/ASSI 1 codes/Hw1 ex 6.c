#include<stdio.h>
int main ()
{
    float a,b,c;
    printf("#########Console_output######\n");
    printf("Enter value of a: \n");
    scanf("%f",&a);
    printf("Enter value of b: \n");
    scanf("%f",&b);
    c=a;
    a=b;
    b=c;
    printf("After swapping, value of a = %.2f \n",a);
    printf("After swapping, value of b = %.2f\n",b);
    printf("#############################");
    printf("########################################################################");


}

