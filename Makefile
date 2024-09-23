CC = gcc -g
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT_DIR = libft/
LIBFT = $(LIBFT_DIR)libft.a

SRCS_DIR = srcs/
SRCS = $(wildcard $(SRCS_DIR)*.c)
OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT)

$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c
	$(CC) $(CFLAGS) -I./includes -c $< -o $@

$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)
	make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re