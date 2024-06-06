CXX = c++
CXXFLAGS =-Wall -Wextra -Werror -std=c++98
NAME = ex02
SRC = main.cpp

all: $(NAME)

$(NAME): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(NAME)
fclean:
	rm -f $(NAME)

re: fclean $(NAME)
