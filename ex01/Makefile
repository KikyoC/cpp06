NAME=convert

CXXFLAGS= -Wall -Werror -Wextra -std=c++98 -g

SRCS=main.cpp Serializer.cpp Data.cpp 
OBJS=$(SRCS:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJS)
	c++ $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp
	c++ $(CXXFLAGS) -c $^ -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
