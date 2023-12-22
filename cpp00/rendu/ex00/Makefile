# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 05:19:27 by mdanchev          #+#    #+#              #
#    Updated: 2023/12/21 05:19:29 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

CC = c++

FLAGS =	-Wall -Werror -Wextra -std=c++98

RM = rm -f

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
