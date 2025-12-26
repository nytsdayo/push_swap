CC = cc
CFLAGS = -Wall -Wextra -Werror

NAME = push_swap

LIBFT_DIR = Libft/
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

test:
	git submodule add https://github.com/nafuka11/push_swap_tester.git
	python3 push_swap_tester/push_swap_tester.py -l 100
	python3 push_swap_tester/push_swap_tester.py -l 500
	git submodule deinit -f push_swap_tester
	git rm -f push_swap_tester
	rm -rf .git/modules/push_swap_testers 

.PHONY: all clean fclean re