NAME		= harl

SRCS		= main.cpp Harl.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -I. -std=c++98
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
