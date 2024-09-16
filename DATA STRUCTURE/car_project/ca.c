#include "ca.h"
#include "status.h"
#include "stdio.h"
static unsigned int speed;
static unsigned int distance;
void send_distance(unsigned int d)
{
    distance=d;
    ca_function= (distance<=50)?ca_waiting_state : ca_driving_state ;
    printf("US-----------distance = %d-------------->CA\n", distance);
}

void ca_waiting_state()
{
    //state id
    ca_state_id=ca_waiting;
    printf("CA Waiting state : distance = %d speed = %d\n", distance, speed);
    //set speed
    speed=0;
    set_speed(speed);
    //send distance
    //comparing



}
void ca_driving_state()
{
    //state id
    ca_state_id=ca_driving;
    printf("CA Driving state : distance = %d speed = %d\n", distance, speed);
    //set speed
    speed=30;

    set_speed(speed);
}


