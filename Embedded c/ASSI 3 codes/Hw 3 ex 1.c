#include<stdio.h>
int main ()
{
    float array1[2][2];
    float array2 [2][2];
    float array3[2][2];
    printf("Enter the element of 1st matrix\n");
    for (int i=0;i<2;i++)
    {
        for (int k=0;k<2;k++)
        {
            printf("Enter a%d%d:",i+1,k+1);
            scanf("%f",&array1[i][k]);

        }

    }
    printf("Enter the element of 2nd matrix\n");
     for (int i=0;i<2;i++)
    {
        for (int k=0;k<2;k++)
        {
            printf("Enter b%d%d:",i+1,k+1);
            scanf("%f",&array2[i][k]);

        }

    }

    printf("sum of matrix:\n");

     for (int i=0;i<2;i++)
    {
        for (int k=0;k<2;k++)
        {
            printf("%0.1f    ",array3[i][k]=array1[i][k]+array2[i][k]);

        }
        printf("\n");
    }
}
