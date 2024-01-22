# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/10 11:19:01 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/10 11:31:10 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.cpp Fixed.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

BLUE = \033[0;34m

END = \033[0m

BOLD = \033[1m

all: ${NAME}

${NAME}:
	${CPP} ${FLAGS} ${SRCS} -o ${NAME}
	
	@echo "${BLUE}The name of this program is: ${BOLD}${NAME}${END}"
	@echo "${BLUE}To start the program, type: ${BOLD}./${NAME}${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean
