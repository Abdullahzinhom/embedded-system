#include<stdio.h>
int main ()

{
    int start,end;

    printf("Enter two number (intervals) : ");
    scanf("%d%d" ,&start,&end);
    printf("prime number between %d and %d are :",start,end);
    for (int i =start+1;i<end;i++)
    {
        if (prime (i))
            printf("%d ",i);
    }


}


int  prime (int start)
{
    if (start <=1)
        return 0;
 for (int i = 2  ; i*i<=start ;i++)
 {
     if (start % i ==0)
     return 0;
 }
 return 1;

}
