#include <stdio.h>
#include "uart.h"
//GLOBAL VAR
element_type buff_1[5];

int main ()
{
int i=0,temp=0;
LIFO_UART uart_lifo,I2c_lifo;
init_lifo(&uart_lifo,buff_1,5);
for (i=0;i<5;i++)
    {
      if (push_lifo(&uart_lifo,i)== LIFO_NO_ERROR)
      {

        printf("uart_lifo push: %d \n",i);
      }
      else printf("error \n");
    }
    printf("================ \n");
    for (i=0;i<5;i++)
    {
      if ( pop_lifo(&uart_lifo,&temp) == LIFO_NO_ERROR)
      {
        printf("uart_lifo pop: %d \n",temp);

      }
            else printf("error \n");

    }
    return 0;
}
