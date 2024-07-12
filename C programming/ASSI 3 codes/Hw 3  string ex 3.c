#include <stdio.h>

int main() {
    int x,k;
    char str[100],reserved[100];
    printf("Enter the string  : ");
    gets(str);
    x=strlen(str);
    k=x-1;
    for (int i =0 ; i<x ; i++)
    {
      reserved[k]=str[i]  ;
      k--;
    }
    printf("reserve string is  : %s ",reserved);
}
