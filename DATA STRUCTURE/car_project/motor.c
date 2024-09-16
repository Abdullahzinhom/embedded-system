#include"motor.h"
#include"status.h"
#include"stdio.h"
unsigned int speed;

void set_speed(unsigned int s)
{
    speed=s;
    motor_function=motor_busy_state;
    printf("CA-----------speed = %d-------------->DC\n", speed);

}
void motor_init_state()
{
    printf("motor init\n");
}
void motor_idle_state()
{
    motor_state_id=motor_idle;
    printf("DC_idle state : speed = %d \n", speed);
}

void motor_busy_state()
{
    motor_state_id=motor_busy;
    motor_function=motor_idle_state;
    printf("DC_busy state : speed = %d \n",speed);
}



