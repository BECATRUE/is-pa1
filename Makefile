TARGET = rsa
SRCS   = rsa.c keygen.c encrypt.c decrypt.c
CC     = gcc
CFLAGS = -g -Wall
OBJS   = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

clean:
	$(RM) $(TARGET) $(OBJS)