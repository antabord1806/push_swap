CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

NAME = push_swap

SRC = adding_to_lst.c ft_err.c push_swap.c add_index.c check_stack.c \
      rotate.c push.c reverse_rotate.c swap.c 1st_push_cycle.c 2nd_push_cycle.c \
      ft_split.c ft_strjoin.c \

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
