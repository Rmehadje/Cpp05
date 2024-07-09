NAME = ex03

SRC = main.cpp Bureaucrat.cpp AForm.cpp PresidentialPardonForm.cpp Intern.cpp RobotomyRequestForm.cpp ShrubberyCreationForm.cpp

FLAGS = -Wall -Wextra -Werror -std=c++98

OBJ = $(SRC:.cpp=.o)

CC = c++

all: $(NAME)

$(NAME):	$(OBJ)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f treeshrubbery


re:	fclean all

.PHONY: all clean fclean re
