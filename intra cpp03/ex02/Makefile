# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/13 20:31:27 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/14 17:21:04 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRC = main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra

BLUE = \033[0;34m

END = \033[0m

BOLD = \033[1m

RM = rm -f

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRC} -o ${NAME}
	@echo "${BLUE} To start this program type: ${BOLD}./${NAME}${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean


