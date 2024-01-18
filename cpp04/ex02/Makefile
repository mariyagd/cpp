# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 12:44:29 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/17 14:24:00 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.cpp Animal.cpp Dog.cpp Cat.cpp \
	   Brain.cpp test1.cpp test2.cpp

CPPF = c++ -Wall -Werror -Wextra -std=c++98 -g

RM = rm -f

BLUE = \033[0;34m
END	 = \033[0m
BOLD = \033[1m

all: ${NAME}

${NAME}:
	${CPPF} ${SRCS} -o ${NAME}
	@echo "${BLUE}To start the program, type ${BOLD}./${NAME}${END}"
	@echo "${BLUE}$$(date)${END}"

fclean:
	${RM} ${NAME}

re: fclean all

.PHONY: re all fclean
