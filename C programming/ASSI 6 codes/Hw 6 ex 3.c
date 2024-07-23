#include<stdio.h>
int main ()
{
    char x[25];

    printf("pointer : print a string in reverse order :\n ");
    printf("----------------------------------------\n");
    printf("input a string : ");
    scanf("%s",&x);
    char *p;
    int z;
    z = strlen(x);
    p=(char*)x;
    p=(p)+z-1;

    for(int i=z-1;i>=0;i--)
    {
        printf("%c",*p);
        p--;
    }


}
