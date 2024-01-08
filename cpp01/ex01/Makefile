# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 16:32:19 by mdanchev          #+#    #+#              #
#    Updated: 2023/12/29 16:40:18 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

BLUE = \033[0;34m

END = \033[0m

BOLD = \033[1m

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}
	@echo "${BLUE}Exercise 01: Moar brainz!"
	@echo "The name of the program is ${BOLD}${NAME}"
	@echo "${BLUE}To start the program: ${BOLD} ./${NAME} ${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all re fclean
