set term pngcairo
set out "spring3.png"

set xlabel "Time"
set ylabel "Position"
unset key
p [0:10] "spring2.dat" pt 6,"spring3.dat" pt 7

