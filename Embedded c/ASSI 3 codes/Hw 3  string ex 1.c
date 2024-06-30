#include <stdio.h>

int main()
{
    int x,y,k;
    printf("Enter a string :");
    char array1[100],c;
    gets(array1);
    printf("Enter a character to find frequency : ");
    scanf("%c",&c);
    x=strlen(array1);

    for (int i =0 ;i<x ;i++)
    {

        if (array1[i]==c)
            k++;
    }
    printf("frequency of %C = %d",c,k);
}
