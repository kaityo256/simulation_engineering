set term pngcairo
set out "exp1.png"

unset key
set xlabel "t"
set ylabel "Data"
p "exp1.dat" u 1:2:3 w e pt 6 lc "blue"

set out "exp1_line.png"

unset key
p "exp1.dat" w errorbars pt 6 lc "blue", exp(-x/3) lt 1 lc "black"
