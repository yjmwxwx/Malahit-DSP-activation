all:
	arm-none-eabi-as -ahls -mcpu=cortex-m7 -mthumb  -o 1.o 1.s > 1.lst
	arm-none-eabi-ld -v -T stm32.ld  -o 1.elf 1.o
	arm-none-eabi-objcopy -O binary 1.elf  1.bin
