#ifndef _UART_H
#define _UART_H

#define element_type unsigned int //(1 byte - 2 byte - 4 byte )

//definitions
typedef struct {
element_type length;
element_type counter ;
element_type* base ;
element_type* head ;

}LIFO_UART;

typedef enum {
     LIFO_NO_ERROR,
      LIFO_EMPTY,
      LIFO_NULL,
      LIFO_FULL,

}LIFO_UART_STATUS;

//APIS
LIFO_UART_STATUS init_lifo(LIFO_UART* lifo,element_type* buff,element_type length);
LIFO_UART_STATUS push_lifo(LIFO_UART* lifo,element_type item);
LIFO_UART_STATUS pop_lifo(LIFO_UART* lifo,element_type* item);


#endif // uart
