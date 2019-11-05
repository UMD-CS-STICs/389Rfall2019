CC=gcc
CFLAGS=-Wall -m32 -z execstack -fno-stack-protector -O0 -g

all: format overflow server byteorder

clean:
	-rm -rf *.o 
	-rm -rf format overflow server byteorder

.PHONY = all clean