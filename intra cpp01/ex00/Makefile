# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/29 15:13:13 by mdanchev          #+#    #+#              #
#    Updated: 2023/12/29 15:40:20 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS =  main.cpp randomChump.cpp newZombie.cpp Zombie.cpp

CPP = c++

FLAGS = -Werror -Wextra -Wall -std=c++98

RM = rm -f

BLUE = \033[0;34m

END = \033[0m

BOLD = \033[1m

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}
	@echo "${BLUE}Exercise 00: BraiiiiiiinnnzzzZ "
	@echo "The name of the program is ${BOLD} ${NAME}"
	@echo "${BLUE}To start the program: ${BOLD} ./${NAME} ${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean 


