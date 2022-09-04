NAME		= Bureaucrat02

SRCS		= main.cpp Bureaucrat.cpp Form.cpp ShrubberyCreationForm.cpp RobotomyRequestForm.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I.
OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)
			$(RM) *_shrubery

re:			fclean all

.PHONY: all clean fclean re
