#include "us.h"
#include "stdio.h"
#include "status.h"
unsigned int distance;

int generateRandomNumber(int x, int y)
{
    return (rand() % (y - x + 1)) + x;
}
void us_init_state()
{
    printf("us_init\n");
}
void us_busy_state()
{
    //id state
    us_state_id=us_busy;
    //get distance
    distance = generateRandomNumber(45,55);
    printf("us busy : distance = %d \n",distance);
    //send distance to ca
    send_distance(distance);
    //return to the function again
    us_function=us_busy_state;

}
