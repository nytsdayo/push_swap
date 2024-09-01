CC = gcc -g
CFLAGS = -Wall -Wextra -Werror
TARGET = push_swap

SRCSDIR = srcs
SRCS = $(wildcard $(SRCSDIR)/*.c) $(wildcard $(SRCSDIR)/*/*.c)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(TARGET)

re: fclean all

.PHONY: all clean fclean re


