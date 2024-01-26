# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 09:46:55 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/24 09:46:56 by mdanchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.cpp ScalarConverter.cpp

CPPF = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

BLUE = 	\033[1;34m
END	= 	\033[0m


all: ${NAME}

${NAME}:
	${CPPF} ${SRCS} -o ${NAME}
	@echo "${BLUE}./prog [value : char, int, float or double]${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean
