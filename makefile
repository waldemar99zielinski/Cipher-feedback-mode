CC = gcc
CFLAGS =  -m64

all: main.o encrypt.o decrypt.o
	$(CC) $(CFLAGS) -g -o cfb -fPIC main.o encrypt.o decrypt.o

encrypt.o: encrypt.s
	nasm -f elf64 -o encrypt.o encrypt.s

decrypt.o: decrypt.s
	nasm -f elf64 -o decrypt.o decrypt.s
main.o: main.c
	$(CC) $(CFLAGS) -c  -o main.o main.c

clean:
	rm -f *.o
