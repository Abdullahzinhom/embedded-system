#include<stdio.h>
int main ()
{
   int m=29;
   printf("Address of m : %p\n",&m);
   printf("value of m : %d\n",m);
   printf("\n");
   int *ab=&m;
   printf("now ab is assigned with the address of m \n");
   printf("Address of pointer ab : %p\n",ab);
   printf("content of pointer ab : %d\n",*ab);
   printf("\n");
   *ab=34;
   printf("the value of m assigned to 34 now.\n");
   printf("Address of pointer ab : %p\n",ab);
   printf("content of pointer ab : %d\n",*ab);
      printf("\n");
      *ab=7;
       printf("the pointer variable ab is assgined with the value 7 now.\n");
   printf("Address of m : %p\n",ab);
   printf("value of m: %d\n",*ab);
      printf("\n");


}
