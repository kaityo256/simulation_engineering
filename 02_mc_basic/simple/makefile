all: a.out
CC=g++
CPPFLAGS=-O3

a.out: simple.cpp
	$(CC) $(CPPFLAGS) $< -o $@

simple.dat: a.out
	./a.out > simple.dat

graph: simple.png

simple.png: simple.plt simple.dat
	gnuplot simple.plt

clean:
	rm -f a.out
