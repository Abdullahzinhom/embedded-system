#include<stdio.h>
#include<string.h>
struct Sstudent {
    char name[50];
    int roll;
    float mark;

}student ;

int main ()
{
    printf("Enter information of student : \n");
    printf("Enter name : ");
    scanf("%s",&student.name);

    printf("Enter roll number : ");
    scanf("%d",&student.roll);

    printf("Enter marks : ");
    scanf("%f",&student.mark);
    printf("\n");
    printf("Displaying  information : \n");
    printf("Name : %s \n",student.name);
    printf("Roll number: %d\n",student.roll);
    printf("Marks:%.2f \n",student.mark);

}
