NAME		= a.out

SRCS		= main.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -I.
OBJS		= $(SRCS:.cpp=.o)
HEADER		= Makefile whatever.hpp

all:		$(NAME)

$(OBJS): $(HEADER)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
