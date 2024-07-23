#include<stdio.h>
int main ()
{
    char x[25],k=0;
    for(int i =65;i<=90;i++)
    {
        x[k]=i;
        k++;
    }
    char *p=x;

    for(int i=0;i<=25;i++)
    {
        printf("%c \t",*(p+i));

    }
}
