typedef volatile unsigned int vuint32_t;
#include "stdio.h"

extern unsigned int stack_top;  // Correct stack top address

extern int main(void);

void reset_handler(void);

void Default_Handler(void)
{
    reset_handler();
}

void NMI_Handler(void) __attribute__((weak, alias("Default_Handler")));
void HardFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void MemManage_Handler(void) __attribute__((weak, alias("Default_Handler")));
void BusFault_Handler(void) __attribute__((weak, alias("Default_Handler")));
void UsageFault_Handler(void) __attribute__((weak, alias("Default_Handler")));

// Vector Table
vuint32_t vector[] __attribute__((section(".vectors"))) = {
    (vuint32_t) &stack_top,             // Initial stack pointer
    (vuint32_t) reset_handler,          // Reset Handler
    (vuint32_t) NMI_Handler,            // NMI Handler
    (vuint32_t) HardFault_Handler,      // Hard Fault Handler
    (vuint32_t) MemManage_Handler,      // Memory Management Fault Handler
    (vuint32_t) BusFault_Handler,       // Bus Fault Handler
    (vuint32_t) UsageFault_Handler,     // Usage Fault Handler
};

extern unsigned int _E_text;
extern unsigned int _S_data;
extern unsigned int _E_data;
extern unsigned int _S_bss;
extern unsigned int _E_bss;

void reset_handler(void)
{
	unsigned int i=0;
    // Copy data from ROM to RAM
    unsigned int data_size = (unsigned char *)&_E_data - (unsigned char *)&_S_data;
    unsigned char *p_Ram_data = (unsigned char *)&_S_data;
    unsigned char *p_Rom_data = (unsigned char *)&_E_text;
    for ( ; i < data_size; i++)
    {
        *(p_Ram_data++) = *(p_Rom_data++);
    }
    
    // Zero out the BSS section
    unsigned int bss_size = (unsigned char *)&_E_bss - (unsigned char *)&_S_bss;
    unsigned char *p_ram_bss = (unsigned char *)&_S_bss;
    for (; i < bss_size; i++)
    {
        *(p_ram_bss++) = 0;
    }
    
    main();
}
