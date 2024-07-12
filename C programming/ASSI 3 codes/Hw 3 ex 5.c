#include <stdio.h>

int main()
{
    int array[100],x,y;
    printf("Enter number of elements : \n");
    scanf("%d",&x);

    for (int i=0;i<x;i++)
    {
        scanf("%d",&array[i]);

    }
    printf("Enter the element to be searched :\n");
    scanf("%d",&y);

        for (int i=0;i<x;i++)
        {
            if (y==array[i])

                printf("Number found at location = %d ",i+1);
        }
}
