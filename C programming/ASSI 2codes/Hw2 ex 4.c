#include<stdio.h>
int main ()
{
float x,y,z;
printf("Enter three numbers: ");
scanf("%f %f %f",&x,&y,&z);
if (x>y && x>z)
    printf("the largest number is %.2f ",x);

    else if (z>y && x<z)
    printf("the largest number is %.2f ",z);
    else
     printf("the largest number is %.2f ",y);
}
