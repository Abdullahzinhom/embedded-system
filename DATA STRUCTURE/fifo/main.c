#include "stdio.h"
#include "fifo.h"
int main ()
{
    int i=0,temp=0;
    element_type buff[5];
    FIFO_BUF_t fifo_buff;
    FIFO_INIT(&fifo_buff,buff,5);
    for (i=0;i<5;i++)
    {
        FIFO_PUSH(&fifo_buff , i);
        printf("added item is : %d \n",i);
    }
    printf("=====================\n");
    for(i=0 ; i<5 ;i++)
    {
        FIFO_POP(&fifo_buff,&temp);
        printf("poped item is : %d\n",temp);
    }

}

