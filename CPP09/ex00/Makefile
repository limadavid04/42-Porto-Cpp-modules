CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98 -g
SRCS =  main.cpp BitcoinExchange.cpp
NAME = btc
HEADERS = BitcoinExchange.hpp

all: $(NAME)

OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CXX) $(CXXFLAGS) $(OBJS) -o $(NAME)

%.o: %.cpp $(HEADERS)
	$(CXX) $(CXXFLAGS) -c $< -o $@
clean:
	rm -f $(OBJS)
fclean: clean
	rm -f $(NAME)
re: fclean $(NAME)

