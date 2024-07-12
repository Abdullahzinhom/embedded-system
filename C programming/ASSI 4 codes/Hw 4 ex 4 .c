#include<stdio.h>
int power(int base, int exp);
int main ()
{
    int x,y;
    printf("Enter base number ");
    scanf("%d",&x);

    printf("Enter power number (positive integer ");
    scanf("%d",&y);
    power(x,y);

}
int power(int base, int exp) {
    int result = 1;
int k=exp;
    while (exp > 0) {
        result *= base;
        exp--;
    }

    printf("%d^%d = %d",base,k,result);
}

