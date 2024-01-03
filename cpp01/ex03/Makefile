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

NAME = Unnecessary_violence

SRCS = main.cpp Weapon.cpp HumanA.cpp HumanB.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re clean all
