#include<stdio.h>
#include<string.h>
#include<math.h>
struct Scomplex {
    float real;
    float imaginary;

}complex1,complex2,sum;
struct Scomplex add(struct Scomplex v1,struct Scomplex v2 )
{
    struct Scomplex result;
    result.real = v1.real+v2.real;
    result.imaginary =v1.imaginary+v2.imaginary;
 sum.imaginary=result.imaginary;
 sum.real=result.real;
}

int main ()
{
   printf("For 1st complex number \n");

   printf("Enter real and imaginary respectively :\n");
   scanf("%f%f",&complex1.real,&complex1.imaginary);

   printf("For 2nd complex number \n");

   printf("Enter real and imaginary respectively :\n");
   scanf("%f%f",&complex2.real,&complex2.imaginary);
   add (complex1,complex2);
   printf("sum = %.1f + %.1fi",sum.real,sum.imaginary);



}
