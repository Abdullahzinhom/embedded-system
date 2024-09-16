#include"us.h"
#include"motor.h"
#include"ca.h"
#include"stdio.h"
#include"status.h"
int main()
{
    //init
        us_init_state();
        motor_init_state();
    //set states pointers for each block
        ca_function= ca_waiting_state;
        us_function= us_busy_state;
        motor_function=motor_idle_state;


for (int k=0;k<100;k++)
{

    if(k)
    {
        us_function();
        ca_function();
        motor_function();
        for(int i=0;i<10000;i++);
    }

}



}
