set term pngcairo
set out "corr2.png"

set log x
set xlabel "n"
set ylabel "Data"

unset key
p [8:4096] "corr2.dat" w errorbars pt 6 lc "blue"

set out "corr2_line.png"

p [8:4096] "corr2.dat" w errorbars pt 6 lc "blue", 0.5 lt 1 lc "black"
