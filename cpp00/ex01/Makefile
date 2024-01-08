# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 05:21:03 by mdanchev          #+#    #+#              #
#    Updated: 2024/01/08 19:27:55 by mdanchev         ###   lausanne.ch        #
#                                                                              #
# **************************************************************************** #

NAME = PhoneBook

SRCS =	main.cpp \
		PhoneBook.cpp \
		PhoneBook_Add.cpp \
		PhoneBook_IsNumber.cpp \
		PhoneBook_eraseWhitespaces.cpp \
		Contact.cpp \
		Contact_Setters.cpp \
		Contact_Getters.cpp \
		Contact_IsValid.cpp \
		Contact_Trunc.cpp

CC = c++

FLAGS =	-Wall -Werror -Wextra -std=c++98

RM = rm -f

all: $(NAME)

BLUE = \033[0;34m

END = \033[0m

BOLD = \033[1m

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)
	@echo "$(BLUE)The name of this program is $(BOLD)$(NAME)$(END)"
	@echo "$(BLUE)To start the program, type $(BOLD)./$(NAME)$(END)"

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
