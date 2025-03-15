# Makefile

CXX = g++
CXXFLAGS = -Wall -std=c++11

SRC = main.cpp Board.cpp Queen.cpp
OBJ = $(SRC:.cpp=.o)

EXEC = eight_queens

all: $(EXEC)

$(EXEC): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $(EXEC) $(OBJ)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(EXEC)
