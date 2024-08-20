typedef volatile unsigned int vuint32_t;
#include "stdio.h"

 // Correct stack top address

extern int main(void);

void reset_handler(void);

void Default_Handler(void)
{
    reset_handler();
}

static vuint32_t stack_top[256];
//===============================


void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

// Vector Table

void (*vector[])() __attribute__((section(".vectors"))) = {
	
(void (*)()) (((vuint32_t)stack_top +  sizeof(stack_top))),             // Initial stack pointer
     reset_handler,          // Reset Handler
     NMI_Handler,            // NMI Handler
    HardFault_Handler,      // Hard Fault Handler
};



extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_handler(void)
{
    // Copy data from ROM to RAM
    unsigned int data_size = (unsigned char *)&_E_data - (unsigned char *)&_S_data;
    unsigned char *p_Ram_data = (unsigned char *)&_S_data;
    unsigned char *p_Rom_data = (unsigned char *)&_E_text;
    for (unsigned int i = 0; i < data_size; i++)
    {
        *(p_Ram_data++) = *(p_Rom_data++);
    }
    
    // Zero out the BSS section
    unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
    unsigned char *p_ram_bss = (unsigned char *)&_S_bss;
    for (unsigned int i = 0; i < bss_size; i++)
    {
        *(p_ram_bss++) = 0;
    }
    
    main();
}
