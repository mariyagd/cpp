# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/16 12:44:29 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/24 09:45:40 by mdanchev         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = prog

SRCS = main.cpp AMateria.cpp Cure.cpp Ice.cpp Character.cpp MateriaSource.cpp \
		utils.cpp test1.cpp test2.cpp test3.cpp

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
