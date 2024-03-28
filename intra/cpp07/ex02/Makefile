NAME = prog

SRCS = main.cpp

CPPF = c++ -Wall -Werror -Wextra -std=c++98

RM = rm -f

BLUE = \033[1;34m
END = \033[0m

all: ${NAME}

${NAME} :
	${CPPF} ${SRCS} -o ${NAME}
	@echo "${BLUE}Start this program with ./prog${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re fclen all
