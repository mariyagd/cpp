# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 05:19:27 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/08 19:21:33 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = megaphone

SRCS = megaphone.cpp

CC = c++

FLAGS =	-Wall -Werror -Wextra -std=c++98

RM = rm -f

BLUE = \033[0;34m

END = \033[0m

BOLD = \033[1m

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(BLUE)The name of this program is $(BOLD)$(NAME)$(END)"
	@echo "$(BLUE)This program capitalizes a string passed as argument.$(END)"
	@echo "$(BLUE)To start this program, type $(BOLD)./$(NAME) $(BLUE)[string 1] [string 2] [string n]$(END)"

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
