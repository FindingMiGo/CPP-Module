NAME		= megaphone

SRCS		= megaphone.cpp
CXX			= c++
CXXFLAGS	= -Wall -Wextra -Werror -std=c++98 -MMP -MD
OBJS		= $(SRCS:.cpp=.o)

rm			= rm -f

all:		$(NAME)

$(NAME):	$(OBJS)
			$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)

fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all fclean re
