CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
INCLUDES = -I../include

SRCS = $(wildcard *.c)
LIB_SRCS = $(wildcard ../src/*.c)

TARGETS = $(SRCS:.c=)

all: $(TARGETS)

%: %.c $(LIB_SRCS)
	$(CC) $(CFLAGS) $(INCLUDES) $< $(LIB_SRCS) -o $@

clean:
	rm -f $(TARGETS) *.o 