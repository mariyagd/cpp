# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/30 13:47:11 by mdanchev          #+#    #+#              #
#    Updated: 2023/12/30 13:52:29 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = hi

SRCS = main.cpp

CPP = c++

FLAGS = -Wall -Werror -Wextra -std=c++98

RM = rm -f

all: $(NAME)

$(NAME):
	$(CPP) $(FLAGS) $(SRCS) -o $(NAME)

fclean:
	$(RM) $(NAME)

re: fclean all

.PHONY: re all fclean
