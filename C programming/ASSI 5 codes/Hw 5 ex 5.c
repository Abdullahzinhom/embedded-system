#include<stdio.h>
#define pi 3.14159265359
#define square(x) ((x)*(x))
int main ()
{
    int raduis ;
    printf("Enter raduis  : ");
    scanf("%d",&raduis);
    printf(" Area = %.2f",pi*square(raduis));
}
