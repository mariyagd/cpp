NAME = prog

SRCS = main.cpp

CPPF = c++ -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: ${NAME}

${NAME} :
	${CPPF} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re fclen all
