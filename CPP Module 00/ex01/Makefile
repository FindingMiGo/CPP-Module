NAME		= phonebook

SRCS		= phonebook.cpp contact.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -pedantic -I.
OBJS		= $(SRCS:.cpp=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)
			$(RM) *.d


fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
