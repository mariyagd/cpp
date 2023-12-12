NAME = megaphone

SRCS = megaphone.cpp

CC = c++

FLAGS =	-Wall -Werror -Wextra -std=c++98

RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re