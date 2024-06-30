#include <stdio.h>

int main() {
    char str[100];
    int length = 0,i=1;

    printf("Enter a string: ");
    gets(str);
    for (i;i<20;i++)
{

    if  (str[i]==0)
    {
        break;
    }

}

    printf("Length of string: %d\n", i);

    return 0;
}
