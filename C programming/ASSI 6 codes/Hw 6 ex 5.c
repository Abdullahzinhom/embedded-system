#include<stdio.h>
struct Semployees
{
    char name[50];
    int ID;
};
int main ()
{
 struct Semployees emp1={"ahmed",1001};
 struct Semployees emp2={"amal",1002};
 struct Semployees emp3={"mahmoud",1003};
 struct Semployees emp4={"abdallah",1004};
struct Semployees *p[3];

p[0]=&emp1;
p[1]=&emp2;
p[2]=&emp3;
p[3]=&emp4;

printf("%s    %d",p[3]->name,p[3]->ID);
}
