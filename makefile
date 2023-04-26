NAME = TrackSongs
CXX = g++ 
CXXFLAGS = -g -Wall -Wextra
SRC=main.cpp

.PHONY: all
all: program

program: main.cpp
	$(CXX)$(CXXFLAGS) $(SRC) -o $(NAME)


# .PHONY: run
run:
	./$(NAME)


.PHONY: clean
clean:
	rm $(NAME)


