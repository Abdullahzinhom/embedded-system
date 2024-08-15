#include "stdio.h"

typedef volatile unsigned int vuint32_t;

// Base addresses
#define RCC_BASE    0x40021000
#define GPIOA_BASE  0x40010800

// Register addresses
#define RCC_APB2ENR  *(vuint32_t *)(RCC_BASE + 0x18)
#define GPIOA_CRH    *(vuint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR    *(vuint32_t *)(GPIOA_BASE + 0x0C)

typedef union {
    vuint32_t all_ports;
    struct {
        vuint32_t reserved : 13;
        vuint32_t pin_13   : 1;
    } port;
} R_ODR_t;

typedef union
{
	vuint32_t all_ports;
	struct
	{
		 vuint32_t port_A:4;
		 vuint32_t port_B:4;
		 vuint32_t port_C:4;
		 vuint32_t port_D:4;
		 vuint32_t port_E:4;
		 vuint32_t port_F:4;
		 vuint32_t port_G:4;
		 vuint32_t port_H:4;
	} port;
} R_GPIO_CRH;

volatile R_GPIO_CRH* p_GPIO_CRH = (volatile R_GPIO_CRH *)(GPIOA_BASE + 0x04);
volatile R_ODR_t* p_GPIO_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);

void wait() {
    for (int i = 0; i < 5000; i++);
}

int main() {
    // Enable clock for GPIOA
    RCC_APB2ENR |= 1 << 2;

    // Configure PA13 as output push-pull
    p_GPIO_CRH->all_ports &= ~0xF; // Correct syntax to clear the bits
    p_GPIO_CRH->port.port_F |=  0x2;  // Set MODE13 to 0b01 (output mode, max speed 10 MHz)

    while (1) {
        p_GPIO_ODR->port.pin_13 = 1; // Set PA13 high
        wait();
        p_GPIO_ODR->port.pin_13 = 0; // Set PA13 low
        wait();
    }

    return 0;
}
