#include<stdio.h>
int main ()
{
    int x,k=0;
   printf("Enter the number of data : ");
   scanf("%d",&x);
   float matrix [100],avarage=0;
   for (int i =0; i<x ;i++)
   {
       printf("%d.Enter the number: ",i+1);
       scanf("%f",&matrix[i]);
       avarage = avarage + matrix[i];
       k++;
   }
   avarage=(avarage/k);
   //printf("average = %d \n",k);
   printf("average = %.2f",avarage);
}
