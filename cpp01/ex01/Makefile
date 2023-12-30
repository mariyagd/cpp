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

NAME = Moar_brainz!

SRCS = main.cpp Zombie.cpp zombieHorde.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all re fclean
