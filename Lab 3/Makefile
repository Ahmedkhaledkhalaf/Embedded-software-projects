#@copyright : Ahmed Khaled Khalaf
#@Generic MakeFile
#@18/5/2024
#@v.2

CC=arm-none-eabi-
CFLAGS=-g -mcpu=cortex-m3	-gdwarf-2
INCS=-I .
LIBS=
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)
AS= $(wildcard *.s)
ASOBJ= $(AS:.s=.o)
Project_name=TM4C123GH6PM_project


all: $(Project_name).bin
	@echo "==========Build is done========="



%.o: %.c
	$(CC)gcc.exe -c $(INCS) $(CFLAGS) $< -o $@
	

$(Project_name).elf: $(OBJ) $(ASOBJ)
	$(CC)ld.exe -T linkerscript.ld $(LIBS) $(OBJ) $(ASOBJ) -o $@	-Map=$(Project_name)_map.map
	cp $(Project_name).elf $(Project_name).axf
$(Project_name).bin: $(Project_name).elf
	$(CC)objcopy.exe -O binary $<  $@
  
clean_All:
	rm *.o *.elf *.bin *.axf
	@echo "==========every thing is clean========="
  
clean:
	rm *.elf *.bin
