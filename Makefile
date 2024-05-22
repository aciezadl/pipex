CC = cc
CFLAGS = -Wall -Werror -Wextra -g
SRC = main.c pipex.c pipex_init.c pipex_utils.c child_process.c
LIBFT = libft/libft.a 
PRINTF = libft/printf/libftprintf.a
NAME = pipex

all: $(NAME)

$(LIBFT):
	make -C libft

$(NAME): $(LIBFT) $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(PRINTF) -o $(NAME)

clean:
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
