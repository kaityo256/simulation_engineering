set term pngcairo
set out "spring2.png"

set xlabel "Time"
set ylabel "Position"
unset key
p "spring.dat" t "m=1" pt 6 ps 1.5,"spring2.dat" t "m=4" pt 7 ps 1.5

