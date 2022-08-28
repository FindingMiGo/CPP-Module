NAME		= violence

SRCS		= main.cpp HumanA.cpp HumanB.cpp Weapon.cpp
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

re:			fclean all

.PHONY: all clean fclean re
