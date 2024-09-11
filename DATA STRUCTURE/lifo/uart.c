
#include "uart.h"
#include "stdio.h"
extern element_type buff;
//APIS
LIFO_UART_STATUS init_lifo(LIFO_UART* lifo,element_type* buff ,element_type length)
{
	 //check if null
    if (!(lifo->base && lifo->head))
		return LIFO_NULL ;

    //initializations
    lifo->base = buff;
    lifo->head = buff ;
    lifo->counter =  0 ;
    lifo->length =  length;
    return LIFO_NO_ERROR ;

}
LIFO_UART_STATUS push_lifo	(LIFO_UART* lifo,element_type item)
{
    //check if null
    if (!(lifo->base && lifo->head))
		return LIFO_NULL ;

    //check if lifo is full
    if(lifo->counter == lifo->length)
    return LIFO_FULL;

    //lifo sequence
    *(lifo->head)=item;
    lifo->head++;
    lifo->counter++;
    return LIFO_NO_ERROR;

}
LIFO_UART_STATUS pop_lifo	(LIFO_UART* lifo,element_type* item)
{
     //check if null
    if (!(lifo->base && lifo->head))
		return LIFO_NULL ;

    //check lifo is empty
    if (lifo->counter==0)
            return LIFO_EMPTY;

    //lifo pop sequence
        lifo->head--;
        *item=*(lifo->head);
        lifo->counter--;
        return LIFO_NO_ERROR;
}
