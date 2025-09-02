NAME = technology
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRC = main.cpp phonebook.cpp contact.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@


clean:
	rm -f $(OBJ)
	
fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re

run:
	./$(NAME) | tee run.log

check:
	diff -U 3 run.log out.log