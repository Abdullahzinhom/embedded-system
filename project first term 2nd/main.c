#include <stdio.h>
#include <stdlib.h>

// Define the structure for the student database

int a;
extern number_of_student;

int main() {
        initialization();
        while(1)
        {
        printf("Choose the option you need:\n");
        printf("1-Add student details from file \n");
        printf("2-Add student details manually \n");
        printf("3-Find the student by the given roll number  \n");
        printf("4-Find the student by the given first name  \n");
        printf("5-Find the students registered in a course \n");
        printf("6-Count of student\n");
        printf("7-Delete a student\n");
        printf("8-Update student \n");
        printf("9-view student \n");
        printf("10-EXITE \n");
        scanf("%d",&a);
              switch(a)
            {

        case 1:
            add_student_info_from_file();
            break;

        case 2:
            add_student_info_manually();
            break;

        case 3:
            find_student_by_roll_number();
            break;

        case 4:
            find_student_by_first_name();
            break;

        case 5:
            find_student_by_regestration_in_course();
            break;

        case 6 :
            count_of_student();
            break;
        case 7:
            delet_student();
        break;

        case 8:
            update_student();
            break;
        case 9:
            view_student();
            break;
        case 10:
            return 1;



            }
        }

}
