set term pngcairo
set out "spring.png"

set xlabel "Time"
set ylabel "Position"
unset key
p "spring.dat" pt 6

