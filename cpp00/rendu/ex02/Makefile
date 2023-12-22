NAME = account

SRCS = tests.cpp Account.cpp

RM = rm -f

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean re all