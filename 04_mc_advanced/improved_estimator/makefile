all: a.out
SRC=$(shell ls *.cpp)
OBJ=$(SRC:.cpp=.o)

CC=g++
CPPFLAGS=-O3 -march=native -Wall -Wextra -std=c++11  -I./sdouble

-include makefile.opt

a.out: $(OBJ)
	$(CC) $(CPPFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CPPFLAGS) -c $< -o $@

clean:
	rm -f a.out $(OBJ)
