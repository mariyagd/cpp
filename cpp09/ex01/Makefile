NAME = RPN

SRCS = main.cpp RPN.cpp

CPPF = c++ -Wall -Werror -Wextra -std=c++98 -g

RM = rm -f

BLUE = \033[1;34m
END	 = \033[0m

all: ${NAME}

${NAME} :
	${CPPF} ${SRCS} -o ${NAME}
	@echo "${BLUE}To start this program, type ./${NAME} \"your input\"${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re fclen all
