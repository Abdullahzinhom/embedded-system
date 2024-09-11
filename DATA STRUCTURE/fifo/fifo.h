#ifndef FIFO
#define FIFO.h
//MACFROS
#define element_type unsigned int //(1 bit - 2 bits - 4 bits - 8 bits)


//DEFINITION
typedef struct {
    element_type* base;
    element_type* tail;
    element_type* head;
    unsigned int  length;
    unsigned int  counter;
}FIFO_BUF_t;

typedef enum {
 FIFO_NO_ERROR,
 FIFO_EMPTY,
 FIFO_FULL,
 FIFO_NULL
}FIFO_BUFF_STATUS;

//APIS
FIFO_BUFF_STATUS FIFO_INIT(FIFO_BUF_t* fifo,element_type* buff,element_type lenght);
FIFO_BUFF_STATUS FIFO_PUSH(FIFO_BUF_t* fifo,element_type item);
FIFO_BUFF_STATUS FIFO_POP(FIFO_BUF_t* fifo,element_type* item);
FIFO_BUFF_STATUS check_FIFO_EMPTY(FIFO_BUF_t* fifo);
FIFO_BUFF_STATUS check_FIFO_NULL(FIFO_BUF_t* fifo);
FIFO_BUFF_STATUS check_FIFO_FULL(FIFO_BUF_t* fifo);



#endif // FIFO
