NAME = prog

SRCS = main.cpp Bureaucrat.cpp AForm.cpp ShrubberyCreationForm.cpp \
		RobotomyRequestForm.cpp PresidentialPardonForm.cpp

CPPF = c++ -Wall -Wextra -Werror -std=c++98

RM = rm -f

all: ${NAME}

${NAME}:
	${CPPF} ${SRCS} -o ${NAME}

fclean:
	${RM} ${NAME}
	${RM} *_shrubbery

re: fclean all

.PHONY: re all fclean