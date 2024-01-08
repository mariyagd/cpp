NAME = prog

SRCS = tests.cpp Account.cpp

RM = rm -f

CC = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

all: $(NAME)

BLUE = \033[0;34m

END = \033[0m

BOLD = \033[1m

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(BLUE)The name of this program is $(BOLD)$(NAME)$(END)"
	@echo "$(BLUE)To start the program, type $(BOLD)./$(NAME)$(END)"

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: fclean re all
