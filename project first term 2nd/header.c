#include "headers.h"
#include "stdio.h"
#include "stdlib.h"
struct sinfo {
    char first_name[25];
    char last_name[25];
    int roll;
    float GPA;
    int cid[5];  // Array for multiple course IDs
}student[50]; // Array of student structures
int number_of_student=1;
struct sinfo *ptr= student;         // Pointer to a student structure

//----------------------------------------------------------
//----------------------------------------------------------

void initialization()
{
    for (int k=1;k<50;k++)
    {
        student[k].roll=0;
    }


}

int add_student_info_from_file()
{
    FILE *file_pointer;
    file_pointer = fopen("data.txt", "r");

    // Check if the file is opened successfully
    if (file_pointer == NULL) {
        printf("Error: Could not open file.\n");
        return ;  // Return an error code
    }


    char line[256];  // Buffer to read each line from the file
    int j;

    // Read each line and process the student data
    while (fgets(line, sizeof(line), file_pointer) != NULL)
        {
            int g=1;
        // Parse the line using sscanf
        sscanf(line, "%s %s %d %f %d %d %d %d %d",
               (ptr + number_of_student)->first_name,
               (ptr + number_of_student)->last_name,
               &(ptr + number_of_student)->roll,
               &(ptr + number_of_student)->GPA,
               &(ptr + number_of_student)->cid[0],
               &(ptr + number_of_student)->cid[1],
               &(ptr + number_of_student)->cid[2],
               &(ptr + number_of_student)->cid[3],
               &(ptr + number_of_student)->cid[4]);

               //check if roll number is repeted
              for(int g =1 ;g<number_of_student;g++)
               {
                   if ((ptr + g)->roll==(ptr + number_of_student)->roll)
                   {
                       strcpy((ptr + g)->first_name,"");
                       strcpy((ptr + g)->last_name,"");
                       (ptr + g)->roll=0;
                       (ptr + g)->GPA=0;
                            for (int j = 0; j < 5; j++)
                             {

                                (ptr + g)->cid[j]=0;
                            }

                    number_of_student--;
                       printf("ERROR !! \nThe roll number is repeted \n");
                       return 1;
                   }
               }

        // Output the data from the student array using the pointer
        printf("Name: %s %s, Roll: %d, GPA: %.2f, CIDs: ",
               (ptr + number_of_student)->first_name,
               (ptr + number_of_student)->last_name,
               (ptr + number_of_student)->roll,
               (ptr + number_of_student)->GPA);

        // Loop to print each course ID
        for (j = 0; j < 5; j++) {
            printf("%d ", (ptr + number_of_student)->cid[j]);
        }
        printf("\n");  // Move to the next line after printing all CIDs

        number_of_student++;// Increment student index
    }
    printf("\n");
        number_of_student--;
    // Close the file after reading
    fclose(file_pointer);

}

 void add_student_info_manually()
 {
     //gets how number of student
    printf("------------------- \n");
    printf("Add Student details \n");
    printf("------------------- \n");

    printf("Enter the Roll number\n ");
    scanf("%d",&(ptr + number_of_student)->roll);

    //check if repeted roll number
    for(int g =1 ;g<number_of_student;g++)
               {
                   if ((ptr + g)->roll==(ptr + number_of_student)->roll)
                   {
                       strcpy((ptr + g)->first_name,"");
                       strcpy((ptr + g)->last_name,"");
                       (ptr + g)->roll=0;
                       (ptr + g)->GPA=0;
                            for (int j = 0; j < 5; j++)
                             {

                                (ptr + g)->cid[j]=0;
                            }

                    number_of_student--;
                       printf("ERROR !! \nThe roll number is repeted \n");
                       return 1;
                   }
               }

    printf("Enter the first name of student \n");
    scanf("%s",(ptr + number_of_student)->first_name);

    printf("Enter  the second name of student\n ");
    scanf("%s",(ptr + number_of_student)->last_name);

    printf("Enter GPA you obtained\n");
    scanf("%s",&(ptr + number_of_student)->GPA);

    printf("Enter course id for each course \n");
    for (int j=0; j<5 ;j++)
    {
        printf("course id %d: ",j+1);
        scanf("%s",&(ptr + number_of_student)->cid[j]);
    }
    printf("[INFO] student details is added successfully \n");
    printf("------------------- \n");

        printf("[INFO] The total number of student is %d \n",number_of_student);
        printf("[INFO] You can add up to 50 student  \n");
        printf("[INFO] YOU can add %d more students \n",50-number_of_student);
 }





void find_student_by_roll_number()
{
    int x,y=0;
     printf("Enter the roll number : ");
     scanf("%d",&x);
     printf("\n");
     for(int g=1;g<=number_of_student;g++)
     {
         if ((ptr + g)->roll==x)
         {
                y=1;
                printf("---------------------------\n");
                printf("First Name: %s \n",(ptr + g)->first_name);
                printf("Last name: %s \n",(ptr + g)->last_name);
                printf("Roll number: %d \n",(ptr + g)->roll);
                printf("GPA: %.2f\n",(ptr + g)->GPA);

               for (int j = 0; j < 5; j++) {
            printf("coure id %d:%d \n", j+1,(ptr + g)->cid[j]);
        }
                printf("---------------------------\n");  // Move to the next line after printing all CIDs
            break;
         }
     }
     if(y==0)
     {
        printf("[ERROR] Roll number %d not found \n",x);
        printf("\n");
     }

}



 void find_student_by_first_name()
 {
     char x[25],y=0;
    printf("Enter the first name: ");
    scanf("%s", &x);
    printf("\n"); // Read the first name directly

     for(int g=1;g<=number_of_student;g++)
     {
         if (strcmp((ptr + g)->first_name,x)==0)
         {
            y=1;
                printf("---------------------------\n");
                printf("First Name: %s \n",(ptr + g)->first_name);
                printf("Last name: %s \n",(ptr + g)->last_name);
                printf("Roll number: %d \n",(ptr + g)->roll);
                printf("GPA: %.2f\n",(ptr + g)->GPA);

                for (int j = 0; j < 5; j++)
                    {
                        printf("coure id %d:%d \n", j+1,(ptr + g)->cid[j]);
                    }
                        printf("---------------------------\n"); // Move to the next line after printing all CIDs
         }
     }
     if(y==0)
     {
        printf("[ERROR] first name %s not found \n",x);
        printf("\n");

     }
 }

 void count_of_student()
{
     int count =0;
for (int g=1;g<=number_of_student;g++)
{
    if (student[g].roll != 0)
        count++;
}

      printf("[INFO] The total number of student is %d \n",count);
      printf("[INFO] The total number of student is %d \n",number_of_student);
        printf("[INFO] You can add up to 50 student  \n");
        printf("[INFO] YOU can add %d more students \n",50-count);
}



void find_student_by_regestration_in_course()
{
    int x,y=0;
    printf("Enter regestration course number you need:\n");
    scanf("%d",&x);
    printf("\n");

    for(int g=1;g<=number_of_student;g++)
    {

        for (int k=0 ;k<5;k++)
        {
            if((ptr+ g)->cid[k]==x)
            {
                y++;
                printf("---------------------------\n");
                printf("First Name: %s \n",(ptr + g)->first_name);
                printf("Last name: %s \n",(ptr + g)->last_name);
                printf("Roll number: %d \n",(ptr + g)->roll);
                printf("GPA: %.2f\n",(ptr + g)->GPA);
                printf("---------------------------\n");
        }
    }

}
if(y==0)
{
printf("[ERROR] the course id:%d not found\n",x);
printf("\n");

}
else
    {
        printf("Total number of student are %d\n",y);
        printf("\n");
    }

}
void delet_student()
{
    printf("Enter Roll number which you want to delete: ");
    int x;
    scanf("%d",&x);
    for(int g=1;g<=number_of_student;g++)
  {
        if((ptr+g)->roll==x)
        {
            strcpy((ptr + g)->first_name,"");
            strcpy((ptr + g)->last_name,"");
             (ptr + g)->roll=0;
             (ptr + g)->GPA=0;


              for (int j = 0; j < 5; j++)
                    {
                    (ptr + g)->cid[j]=0;
                    }

        }
        break;

  }

  for (int k = 1 ; k < number_of_student; k++) {
                ptr[k] = ptr[k + 1];
            }
            //make the last one is zero
            number_of_student--;

}




 void update_student()
{
    printf("Enter the roll number to update the entry:");
    int previous_roll_number,y,x,new_roll;
    scanf("%d",&previous_roll_number);
    for(int g=1;g<=number_of_student;g++)
    {
        if((ptr +g)->roll==previous_roll_number)
        {
            printf("choose what data you need to modify:\n");
            printf("1-First name.\n");
            printf("2-last name.\n");
            printf("3-roll number.\n");
            printf("4-gpa.\n");
            printf("5-course id.\n");
            printf("6-EXITE.\n");
            scanf("%d",&y);
            switch(y)
            {
            case 1:
                printf("The new first name is :\n");
                scanf("%s",&(ptr +g)->first_name);
                break;
            case 2:
                 printf("The new laset name is :\n");
                scanf("%s",&(ptr +g)->last_name);
                break;
            case 3:
                printf("The new roll number is :\n");
                scanf("%d",&new_roll);
                 for(int g =1 ;g<number_of_student;g++)
               {
                   if ((ptr + g)->roll==new_roll)
                   {
                       (ptr +g)->roll=previous_roll_number;
                       printf("[ERROR] REPEATED ROLL NUMBER\n");
                    }
                    else
                    {
                        (ptr + g)->roll==new_roll;
                    }
                }
                break;
            case 4:
                 printf("The new GPA is :\n");
                scanf("%s",&(ptr +g)->GPA);
                break;

            case 5:
                printf("Enter course id: \n");
                scanf("%d",&x);
                printf("Enter new course number :\n");
                scanf("%d",&(ptr + g)->cid[x]);

                break;
            case 6:

                break;
}
        }
        }
        }




void view_student()
{
     for(int g=1;g<=number_of_student;g++)
     {
            printf("---------------------------\n");
                printf("First Name: %s \n",(ptr + g)->first_name);
                printf("Last name: %s \n",(ptr + g)->last_name);
                printf("Roll number: %d \n",(ptr + g)->roll);
                printf("GPA: %.2f\n",(ptr + g)->GPA);

                for (int j = 0; j < 5; j++)
                    {
                        printf("coure id %d:%d \n", j+1,(ptr + g)->cid[j]);
                    }
     }
     printf("---------------------------\n");
}
