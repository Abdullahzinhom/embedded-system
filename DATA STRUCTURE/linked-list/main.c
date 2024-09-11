#include "stdio.h"
#include "stdlib.h"
int counter;

struct sdata
{
    unsigned int ID;
    char name [40];
    float height;
};

struct Sstudent
{
    struct sdata student;
    struct sstudent * next_address ;
};

 struct Sstudent* gphead = NULL ;

void addstudent ()
{
    char temp[40];
    struct Sstudent* newrecord;
    struct Sstudent* lastrecord;

    if (gphead == NULL)
    {
        //new record
        newrecord = (struct Sstudent*) malloc( sizeof (struct Sstudent));
        //assign to it
        gphead = newrecord;
    }
    else
    {
        lastrecord = gphead;

        while (lastrecord->next_address != NULL)
        {
            lastrecord = lastrecord->next_address;
        }
        newrecord = (struct Sstudent*) malloc( sizeof (struct Sstudent));
        lastrecord->next_address = newrecord;
    }

    // Clean input buffer (to avoid leftover newlines)
    fflush(stdin);

    // Fill data
    printf("Enter student ID:\n");
    fgets(temp, sizeof(temp), stdin);
    newrecord->student.ID = atoi(temp);

    printf("Enter student name:\n");
    fgets(newrecord->student.name, sizeof(newrecord->student.name), stdin);
    newrecord->student.name[strcspn(newrecord->student.name, "\n")] = '\0'; // Remove newline character

    printf("Enter student height:\n");
    fgets(temp, sizeof(temp), stdin);
    newrecord->student.height = atof(temp);

    // Set the last record next address by null
    newrecord->next_address = NULL;
}


 void deletrecord()
 {
    struct Sstudent* current_student;
    struct Sstudent* previous_student;
     unsigned int selected_id;
     printf("Enter the selected id record");
     scanf("%d",&selected_id);
    if(gphead)
    {
        current_student=gphead;
        previous_student=NULL;
        //loop for all records
        while (current_student)
        {
            if(current_student->student.ID==selected_id)
            {
                    if (previous_student)//if the selected student is not the first one
                    {
                        previous_student->next_address=current_student->next_address;
                    }
                    else //if the selected student is the first one
                    {
                        gphead=current_student->next_address;
                        previous_student=NULL;
                    }
                    free(current_student);
                    return 1;
            }
            previous_student=current_student;
            current_student=current_student->next_address;
        }

    }
    printf("NO MATCHED ID!");
        return 0;

 }
 void view_content()
 {
     int count =0;
     struct Sstudent* current_student;
     current_student=gphead;
     if(gphead)
     {
         while (current_student)
         {


            printf("\n");
            printf("Record number %d\n", ++count);
            printf("ID is: %d\n", current_student->student.ID);
            printf("NAME is: %s\n", current_student->student.name);
            printf("Height is: %f\n", current_student->student.height);
            current_student = current_student->next_address;
            printf("\n");
         }
     }
     else
     printf("The record is empty\n");
 }

 void deleteall()
 {
        struct Sstudent* current_student =gphead;
        struct Sstudent* delete_student ;
        if (gphead)
        {
            while (current_student)
            {
                delete_student=current_student;
                current_student=current_student->next_address;
                free(delete_student);
            }
            gphead=NULL;
        }
        else
        {
            printf("ALREADY DELETED!!\n");
        }
 }
 void Nth_node()
{
    int count = 0, temp;
    struct Sstudent* current_student = gphead;

    printf("Enter the number of index: ");
    scanf("%d", &temp);

    // Clear the input buffer after using scanf

    if (gphead)
    {
        while (current_student)
        {
            if (count == temp)
            {
                printf("The output of the index %d is: \n", temp);
                printf("ID is : %d\n", current_student->student.ID);
                printf("NAME is : %s\n", current_student->student.name);
                printf("Height is : %f\n", current_student->student.height);
                return;
            }
            else
            {
                current_student = current_student->next_address;
                count++;
            }
        }
        printf("The index is out of range\n");
    }
    else
    {
        printf("The list is empty\n");
    }
}


 //recursive case
 int recursive_length_of_list (struct Sstudent* current_student)
 {
	 if(current_student==NULL)
		 return 0;
	 else
		 return 1 + recursive_length_of_list(current_student->next_address);
 }

 void Length_of_list()
 {
	  struct Sstudent* current_student = gphead;
	  int count=0;
		  while (current_student)
		  {
			  ++count;
			  current_student=current_student->next_address;

		  }
		 counter=count;
		if(count>0)
			printf("LENGTH IS %d \n",count);
		else
		{printf("LENGTH IS ZERO\n");}
 }

 void nth_from_back_method1()
 {
	 printf("Enter the number of index");
	 int n;
	 scanf("%d",&n);
	 counter =recursive_length_of_list(gphead);
	 struct Sstudent* current_student = gphead;
	 for (int i=1;i<(counter-n+1);i++)
	 {
		 current_student=current_student->next_address;
	 }
             printf("\n");
			 printf("the output of the index %d is : ",n);
			 printf("ID is : %d\n",current_student->student.ID);
             printf("NAME is : %s\n",current_student->student.name);
             printf("height is : %f\n",current_student->student.height);
             printf("\n");
 }
  void nth_from_back_method2()
  {
      struct Sstudent* main_pointer = gphead;
      struct Sstudent* ref_pointer = gphead;
      printf("Enter the number of index");
	 int n;
	 scanf("%d",&n);
	  if (gphead == NULL) {
        printf("The list is empty\n");
        return 0 ;
    }
	 for(int i=0;i<n;i++)
     {
         if (ref_pointer == NULL) {
            printf("The index is out of range.\n");
            return;
        }
         ref_pointer=ref_pointer->next_address;
     }
     while (ref_pointer)
     {
         ref_pointer=ref_pointer->next_address;
         main_pointer=main_pointer->next_address;
     }
        printf("\n");
        printf("the output of the index %d is :\n ",n);
        printf("ID is : %d\n",main_pointer->student.ID);
        printf("NAME is : %s\n",main_pointer->student.name);
        printf("height is : %f\n",main_pointer->student.height);
        printf("\n");

}
void middle_of_linked_list()
{
      struct Sstudent* slow_pointer = gphead;
      struct Sstudent* fast_pointer = gphead;
      if(gphead)
      {
           while(fast_pointer != NULL && fast_pointer->next_address !=NULL)
          {
              slow_pointer=slow_pointer->next_address;
              fast_pointer=fast_pointer->next_address;
              fast_pointer=fast_pointer->next_address;

          }
                    printf("\n");
                    printf("ID is : %d\n",slow_pointer->student.ID);
                    printf("NAME is : %s\n",slow_pointer->student.name);
                    printf("height is : %f\n",slow_pointer->student.height);
                    printf("\n");
                    return ;


          }
          else
          { printf("it's empty");}
}
void reverse_linked_list()
{
    struct Sstudent* current = gphead;
    struct Sstudent* next = NULL;
    struct Sstudent* prev = NULL;
    while (current != NULL)
    {
        // Store the next node
        next = current->next_address;

        // Reverse the current node's pointer
        current->next_address = prev;

        // Move pointers one step forward
        prev = current;
        current = next;
    }

    // Update the head to the last non-null node (prev)
    gphead = prev;

    printf("The linked list has been reversed.\n");
}

int main()
{
    int  temp=0;
    while (1)
{
    printf("========================\n");
    printf("\n");

    printf("            Choose one of the following options :\n");
    printf("1:Add student \n");
    printf("2:Delete student\n");
    printf("3:view student \n");
    printf("4:delete all  \n");
    printf("5:Nth node in a Linked List  \n");
    printf("6:Length of a Linked List  \n");
    printf("7:Nth node from the end  \n");
    printf("8:Middle of linked list  \n");
    printf("9:Reverse the linked list  \n");
    printf("10:EXIT  \n");
    printf("Enter your choice   \n");
    scanf("%d",&temp);
    //gets(temp);

        switch (temp)
    {
    case 1 :
        addstudent();
        break;
    case 2 :
        deletrecord();
        break;
    case 3 :
        view_content();
        break;
    case 4 :
        deleteall();
        break;
	case 5:
		Nth_node();
		break;
	case 6:
		Length_of_list();
		break;
	case 7:
		nth_from_back_method1();
		break;
	case 8:
         middle_of_linked_list();
		break;
	case 9:
        reverse_linked_list();
		break;
	case 10:
		return 0;

    default:
        printf("wrong choice \n");
        break;

    }
        printf("\n");


}

}
