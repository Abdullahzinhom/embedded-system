#include "driver.h"
#include "stdio.h"
#include "alarm.h"




void alarm_on()
{

        Set_Alarm_actuator(1);
        Delay(200000);  //let 1000 is 60 second
        Set_Alarm_actuator(0);
        Delay(200000);

}

