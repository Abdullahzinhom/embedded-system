#include<stdio.h>
#include<string.h>
#include<math.h>
struct Sstudent  {
    int  roll ;
    char  name[50];
    float marks;

}student[10];
int main ()
{
    printf("Enter information of student :\n ");

for (int i=0;i<10;i++)
{
    printf("For roll number: ");
    scanf("%d",&student[i].roll);
    printf("Enter name : ");
    scanf("%s",&student[i].name);
    printf("Enter marks : ");
        scanf("%f",&student[i].marks);
}
printf("Displaying information of  students \n");
for (int i=0;i<10;i++)
{
    printf("infromation for roll number %d :\n",student[i].roll);
    printf("Name: %s \n",student[i].name);
    printf("Marks: %.1f \n",student[i].marks);
printf("\n");
}
}
