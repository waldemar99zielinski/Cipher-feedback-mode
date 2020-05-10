CC = gcc
CFLAGS =  -m64

all: main.o encrypt.o decrypt.o encryptv2.o decryptv2.o
	$(CC) $(CFLAGS) -g -o cfb -fPIC main.o encrypt.o decrypt.o encryptv2.o decryptv2.o

encrypt.o: encrypt.s
	nasm -f elf64 -o encrypt.o encrypt.s

encryptv2.o: encryptv2.s
	nasm -f elf64 -o encryptv2.o encryptv2.s

decrypt.o: decrypt.s
	nasm -f elf64 -o decrypt.o decrypt.s

decryptv2.o: decryptv2.s
	nasm -f elf64 -o decryptv2.o decryptv2.s
main.o: main.c
	$(CC) $(CFLAGS) -c  -o main.o main.c

clean:
	rm -f *.o
