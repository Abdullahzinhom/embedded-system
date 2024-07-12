#include <stdio.h>
#include <string.h>

void reverse(char start[], int n);

char reversed[100];
int k = 0;

int main() {
    char str[100];

    printf("Enter a string: ");
    gets(str);

    int length = strlen(str)-1;
    reverse(str, length );

    printf("%s\n", reversed);

    return 0;
}

void reverse(char start[], int n) {
    if (n >= 0) {
        reversed[k++] = start[n];
        reverse(start, n - 1);
    } else {
        reversed[k] = '\0';
    }
}
