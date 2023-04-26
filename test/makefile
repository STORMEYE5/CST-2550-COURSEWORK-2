NAME = test
CXX = g++ 
CXXFLAGS = -g -Wall -Wextra
SRC=test.cpp

.PHONY: all
all: program

program: test.cpp
	$(CXX)$(CXXFLAGS) $(SRC) -o $(NAME)
	./$(NAME)