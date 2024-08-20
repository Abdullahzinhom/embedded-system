typedef  volatile unsigned int vuint32_t;
 
#define SYSCTL_RCGC2_R    *(vuint32_t*)(0x400FE108) 
#define GPIO_PORTF_DATA_R *(vuint32_t*)(0x400253FC) 
#define GPIO_PORTF_DIR_R  *(vuint32_t*)(0x40025400) 
#define GPIO_PORTF_DEN_R  *(vuint32_t*)(0x4002551c) 


int main()
{
	 volatile unsigned int  delay_counter ;
	SYSCTL_RCGC2_R = 0x00000020;
	
	for (delay_counter=0;delay_counter<200;delay_counter++); // wait until clock is on
	
	GPIO_PORTF_DIR_R |= (1<<3); // set the direction to output
	
	GPIO_PORTF_DEN_R |= (1<<3); //set digital enable 

	
	while(1)
	{
		GPIO_PORTF_DATA_R |= (1<<3);
		for (delay_counter=0;delay_counter<2000000;delay_counter++); //wait
		
		GPIO_PORTF_DATA_R &= ~(1<<3); 
		
	    for (delay_counter=0;delay_counter<2000000;delay_counter++); //wait
		
	}
	return 0;
}