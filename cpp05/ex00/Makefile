NAME = prog

SRCS = main.cpp Bureaucrat.cpp

CPPF = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: ${NAME}

${NAME}:
	${CPPF} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean