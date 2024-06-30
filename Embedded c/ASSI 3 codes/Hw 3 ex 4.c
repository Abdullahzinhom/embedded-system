#include <stdio.h>

int main() {
    int n, element, location;


    printf("Enter no of elements: ");
    scanf("%d", &n);

    int arr[100];
    printf("Enter the elements: ");
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }


    printf("Enter the element to be inserted: ");
    scanf("%d", &element);


    printf("Enter the location: ");
    scanf("%d", &location);


    for(int i = n; i >= location; i--) {
        arr[i] = arr[i - 1];
    }


    arr[location - 1] = element;
    n++;


    printf("Updated array: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
