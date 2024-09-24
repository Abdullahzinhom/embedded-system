#include <stdint.h>
#include <stdio.h>
#include "driver.h"
#include "alarm.h"

int main (){
	GPIO_INITIALIZATION();
	int Pvalue ;
	int threshold = 20;
	while (1)
	{
		Pvalue = getPressureVal();
		if (Pvalue > threshold){
			alarm_on();
		}

	}
}
