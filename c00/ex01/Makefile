NAME = PhoneBook

SRCS =	main.cpp \
		PhoneBook.cpp \
		PhoneBook_Add.cpp \
		PhoneBook_IsNumber.cpp \
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