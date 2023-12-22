# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdanchev <mdanchev@student.42lausanne.ch>  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/21 05:21:03 by mdanchev          #+#    #+#              #
#    Updated: 2023/12/21 05:21:05 by mdanchev         ###   lausanne.ch        #
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

$(NAME):
	$(CC) $(FLAGS) $(SRCS) -o $(NAME)

fclean:
		$(RM) $(NAME)

re: fclean all

.PHONY: all fclean re
