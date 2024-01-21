# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 13:47:11 by mdanchev          #+#    #+#              #
#    Updated: 2023/12/30 13:52:29 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

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
	@echo "${BLUE}Exercise 02: HI THIS IS BRAIN${END}"
	@echo "${BLUE}The name of the program is ${BOLD}${NAME} ${END}"
	@echo "${BLUE}To start the program: ${BOLD}./${NAME}${END}"

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: re all fclean
