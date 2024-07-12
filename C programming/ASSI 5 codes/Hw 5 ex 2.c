#include<stdio.h>
#include<string.h>
#include<math.h>
struct Sunits {
    int feet;
    float inch;

}distance1,distance2,sum ;

int main ()
{
   printf("Enter information of 1st distance : \n");
    printf("Enter feet : ");
    scanf("%d",&distance1.feet);

    printf("Enter inch : ");
    scanf("%f",&distance1.inch);

    printf("Enter information of 2nd distance : \n");
    printf("Enter feet : ");
    scanf("%d",&distance2.feet);

    printf("Enter inch : ");
    scanf("%f",&distance2.inch);

    sum.feet=distance1.feet+distance2.feet;
    sum.inch=distance1.inch+distance2.inch;

    sum.inch=sum.inch*0.08333;
    float summ,final1;
    int summ1;
    summ=sum.feet+sum.inch;
    summ1=sum.feet+sum.inch;


    final1=summ-summ1;
    final1=ceil(final1*100)/10;
    printf("sum of distances = %.f'-%.1f\"",summ,final1);


}
