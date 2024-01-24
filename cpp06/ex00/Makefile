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

all: ${NAME}

${NAME}:
	${CPPF} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean
