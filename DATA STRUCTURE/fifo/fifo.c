#include "fifo.h"
#include "stdio.h"

FIFO_BUFF_STATUS check_FIFO_EMPTY(FIFO_BUF_t* fifo);
FIFO_BUFF_STATUS check_FIFO_NULL(FIFO_BUF_t* fifo);
FIFO_BUFF_STATUS check_FIFO_FULL(FIFO_BUF_t* fifo);

FIFO_BUFF_STATUS FIFO_INIT(FIFO_BUF_t* fifo,element_type* buff,element_type length)
{
    //check if fifo is null
    if (buff==NULL)
        return FIFO_NULL;

        fifo->base= buff;
        fifo->tail= buff;
        fifo->head= buff;
        fifo->length = length;
        fifo->counter=0;
        return FIFO_NO_ERROR;

}
//push mechanism
FIFO_BUFF_STATUS FIFO_PUSH(FIFO_BUF_t* fifo,element_type item)
{
     //check if fifo is null
        if(check_FIFO_NULL(fifo)!=FIFO_NO_ERROR)
         return FIFO_NULL;
    //check if fifo full
    if(check_FIFO_FULL(fifo)!=FIFO_NO_ERROR)
         return FIFO_FULL;

          //sequence
    *(fifo->head)=item;
    //fifo circular
    if(fifo->head == (fifo->base + fifo->length))
       fifo->head=fifo->base;
       else
        fifo->head++;

    fifo->counter++;
    return FIFO_NO_ERROR;

}
//pop mechnism
FIFO_BUFF_STATUS FIFO_POP(FIFO_BUF_t* fifo,element_type* item)
{
      //check if fifo is null
      if(check_FIFO_NULL(fifo)!=FIFO_NO_ERROR)
         return FIFO_NULL;

    //check if fifo empty
    if (check_FIFO_EMPTY(fifo) != FIFO_NO_ERROR)
        return FIFO_EMPTY;

    //sequence
    *item = *(fifo->tail);
  if(fifo->tail == (fifo->base + fifo->length))
       fifo->tail = fifo->base ;
       else
        fifo->tail++;

    fifo->counter--;
    return FIFO_NO_ERROR;

}
FIFO_BUFF_STATUS check_FIFO_EMPTY(FIFO_BUF_t* fifo)
{
    //check is fifo is empty
    if (fifo->counter ==0 )
        return FIFO_EMPTY;

         return FIFO_NO_ERROR;

}

FIFO_BUFF_STATUS check_FIFO_NULL(FIFO_BUF_t* fifo)
{
      //check if fifo is null
    if (!(fifo->base && fifo->head && fifo->tail))
        return FIFO_NULL;

         return FIFO_NO_ERROR;
}

FIFO_BUFF_STATUS check_FIFO_FULL(FIFO_BUF_t* fifo)
{
    //check is fifo is full
    if (fifo->length == fifo->counter )
        return FIFO_FULL;

        return FIFO_NO_ERROR;

}

