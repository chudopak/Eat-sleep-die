NAME		= philosophers

FLAGS		= -Wall -Wextra -Werror -g

FILES		= philosophers set_all set_input utils time

SRCS		= $(patsubst %, srcs/%.c, $(FILES))

OBJ			= $(SRCS:.c=.o)

HEADER		= philosophers.h

TEST_INPUT	= check_parsed_input.c

%.o: %.c $(HEADER)
	gcc $(FLAGS) $< -c -o $(<:.c=.o)

$(NAME):  $(OBJ)
	gcc -o $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all