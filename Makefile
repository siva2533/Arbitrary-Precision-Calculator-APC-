CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = apc

SRCS = main.c \
       val.c \
       operations.c \
       add.c \
       sub.c \
       mul.c \
       div.c \
       mod.c \
       pow.c

OBJS = $(SRCS:.c=.o)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

%.o: %.c apc.h
	$(CC) $(CFLAGS) -c $<

clean:
	rm -f $(OBJS) $(TARGET)
