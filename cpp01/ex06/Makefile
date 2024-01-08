# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/07 14:07:47 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/07 14:07:49 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = harlFilter

SRCS = main.cpp Harl.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}
	@echo "The name of this program is: ${NAME}"
	@echo "Use this program: ./${NAME} [level]"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean
