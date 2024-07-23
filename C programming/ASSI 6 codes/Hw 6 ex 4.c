#include<stdio.h>
int main ()
{
    int  x[15],size;
    int *p=&x;

    printf("Input the number of elements to store in the array (max 15) : \n ");
    scanf("%d",&size);
    printf("Input 5 number of elements in the array :\n");
    for (int i=0;i<size ;i++)
    {
        printf("element - %d : ",i+1);
        scanf("%d",p);
        p++;
    }
    p--;
    printf("\n");
    for (int i=size ;i>0 ;i--)
    {
        printf("element - %d : %d \n",i,*p);

       p--;
    }



}
