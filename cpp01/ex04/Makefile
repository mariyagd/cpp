NAME = prog

SRCS = main.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f
BLUE = \033[0;34m

COLOUR_END = \033[0m

BOLD = \033[1m

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}
	@echo "${BLUE}Exercise 04: Sed is for losers ${END}"
	@echo "${BLUE}The name of the program is ${BOLD}${NAME}${END}"
	@echo "${BLUE}To start the program: ${BOLD}./${NAME} [existing_file] [word1] [word2]${END}"
	@echo "${BLUE}This program copies [existing_file] in [existing_file].replace and replaces [word1] by [word2] in it${END}"
	@echo "${BLUE}To delete all .replace files: ${BOLD} make delete ${BLUE}or ${BOLD}make re ${END}"

fclean:
	${RM} ${NAME}

delete:
	find . -type f -name '*.replace' -delete

re: fclean delete all

.PHONY: all fclean re