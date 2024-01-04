NAME = prog

SRCS = main.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}

delete:
	find . -type f -name '*.replace' -delete

re: fclean delete all

.PHONY: all fclean re