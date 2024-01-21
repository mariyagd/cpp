# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 23:27:32 by mdanchev          #+#    #+#              #
#    Updated: 2023/12/30 23:31:24 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

BLUE = \033[0;34m

COLOUR_END = \033[0m

BOLD = \033[1m

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}
	@echo "${BLUE}Exercise 03: Unnecessary violence${END}"
	@echo "${BLUE}The name of the program is ${BOLD}${NAME} ${END}"
	@echo "${BLUE}To start the program: ${BOLD}./${NAME} ${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re clean all
