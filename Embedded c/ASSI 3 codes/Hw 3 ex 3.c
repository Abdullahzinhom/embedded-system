#include<stdio.h>
int main ()
{
    int row,column;
    printf("Enter the rows and coulmn of matrix : ");
    scanf("%d%d",&row,&column);
    printf("Enter the element of matrix : \n");
    int matrix[2][3];
    int transpoze[3][2];

    for(int i=0;i<row;i++)
    {
        for (int k=0 ; k<column ; k++)
        {
            printf("Enter elements  a%d%d  ",i+1,k+1);
            scanf("%d",&matrix[i][k]);
        }
    }
    printf("Entered matrix : \n");

     for(int i=0;i<row;i++)
    {
        for (int k=0 ; k<column ; k++)
        {
            printf("%d   ",matrix[i][k]);

        }
        printf("\n");
    }

    for(int i=0;i<row;i++)
    {
        for (int k=0 ; k<column ; k++)
        {
            transpoze[k][i]=matrix[i][k];

        }

    }

     printf("transposed of matrix  : \n");

     for(int i=0;i<column;i++)
    {
        for (int k=0 ; k<row ; k++)
        {
            printf("%d   ",transpoze[i][k]);

        }
        printf("\n");
    }


}
