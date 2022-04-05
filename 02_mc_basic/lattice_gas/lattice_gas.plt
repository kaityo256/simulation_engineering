set term pngcairo

set xlabel "K"
set ylabel "U"

V=10*10
f(x) = -2*V*exp(x)/(2*V*exp(x) + V*(V-5)/2)
unset key

set out "n2.png"
p [0:10] f(x) lc "black"

set out "lattice_gas.png"
p [0:10] f(x) lc "black", "lattice_gas.dat" u 1:2:4 w e pt 6 lc "blue"
