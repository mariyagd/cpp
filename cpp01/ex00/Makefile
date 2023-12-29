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

NAME = BraiiiiiiinnnzzzZ...

SRCS =  main.cpp randomChump.cpp newZombie.cpp Zombie.cpp

CPP = c++

FLAGS = -Werror -Wextra -Wall -std=c++98

RM = rm -f

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: all re clean 


