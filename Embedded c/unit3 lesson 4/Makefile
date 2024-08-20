#@copyright: abdallah
CC    =arm-none-eabi-
CFLAGS= -mcpu=cortex-m4 -gdwarf-2 -g 
INCS  =-I .
LIBS  =
SRC   = $(wildcard *.c)
OBJ   = $(SRC:.c=.o)
AS	  =$(wildcard *.s)
ASOBJ =$(AS:.s=.o)
project_name= lesson3_cortex_m4



all: $(project_name).bin

		@echo "========done======="
	 

	
%.o:%.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) -std=c99 -mthumb  $< -o $@	
	 
%.o: %.s

	$(CC)gcc.exe  -c $(CFLAGS) -std=c99 -mthumb $< -o $@
	
	
$(project_name).elf: $(ASOBJ) $(OBJ)

	$(CC)ld.exe -T linker-script.ld $(LIBS) $(ASOBJ) $(OBJ) -o $(project_name).elf -Map=Map_file.map
	cp $(project_name).elf $(project_name).axf
	
$(project_name).bin:$(project_name).elf
	$(CC)objcopy.exe -O binary $< $@
	 
clean-all:
	rm *.o *.bin *.elf *.map

clean: 
	rm *.bin *.elf *.map