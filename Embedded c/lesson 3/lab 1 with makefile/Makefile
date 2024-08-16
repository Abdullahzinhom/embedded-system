#@copyright: abdallah
CC    =arm-none-eabi-
CFLAGS=-g -mcpu=arm926ej-s
INCS  =-I .
LIBS  =
SRC   = $(wildcard *.c)
OBJ   = $(SRC:.c=.o)
AS	  =$(wildcard *.s)
ASOBJ =$(AS:.s=.o)
project_name= UART_lab



all: $(project_name).bin

		@echo "========done======="
	 

	
%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@	
	 
startup.o: startup.s

	$(CC)gcc.exe  -c $(CFLAGS) $< -o $@
	
	
$(project_name).elf: $(ASOBJ) $(OBJ)

	$(CC)ld.exe -T linker-script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $(project_name).elf -Map=Map_file.map
	
	
$(project_name).bin:$(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	 
clean-all:
	rm *.o *.bin *.elf *.map

clean: 
	rm *.bin *.elf *.map