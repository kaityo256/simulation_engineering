set term pngcairo
set out "exp2.png"

unset key
set xlabel "t"
set ylabel "Data"
p "exp2.dat" u 1:2:3 w e pt 6 lc "blue"

set out "exp2_line.png"

unset key
p "exp2.dat" w errorbars pt 6 lc "blue", exp(-x/3) lt 1 lc "black"
