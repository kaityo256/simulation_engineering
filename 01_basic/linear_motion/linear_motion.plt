set term pngcairo
set out "linear_motion.png"

set xlabel "Time"
set ylabel "Position"
unset key
p "linear_motion.dat" pt 6

