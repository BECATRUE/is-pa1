TARGET = rsa
SRCS   = rsa.c keygen.c keyread.c textread.c encrypt.c decrypt.c
CC     = gcc
CFLAGS = -g -Wall
OBJS   = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^ -lgmp

clean:
	$(RM) $(TARGET) $(OBJS)