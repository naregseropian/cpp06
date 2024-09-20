NAME = convert
CXX = c++
CXXFLAGS = -Wall -Werror -Wextra -g -std=c++98
SRCS = main.cpp ScalarConverter.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(NAME) $(OBJS)

all: $(NAME)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re:fclean all

.PHONY: all, clean, fclean, re