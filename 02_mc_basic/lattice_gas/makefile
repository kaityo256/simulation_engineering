all: a.out
CC=g++
CPPFLAGS=-O3

a.out: lattice_gas.cpp
	$(CC) $(CPPFLAGS) $< -o $@

lattice_gas.dat: a.out
	./a.out > lattice_gas.dat

graph: lattice_gas.png

lattice_gas.png: lattice_gas.plt lattice_gas.dat
	gnuplot lattice_gas.plt

clean:
	rm -f a.out
