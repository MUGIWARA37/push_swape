NAME	= push_swap
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
SRCS	= min_number_hundler.c min_number_hundler_2.c chunk_sort.c ft_atol.c ft_lstsize.c ft_split.c ft_strlcpy.c ft_strlen.c is_sorted.c parcing_helper.c parcing.c ps_command_2.c ps_command.c push_swap_ulits.c push_swap.c
OBJS	= $(SRCS:.c=.o)

# ------------------- RULES -------------------

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re