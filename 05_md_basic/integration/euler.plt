set term pngcairo
unset key
set out "euler.png"
set size square
set xla "p"
set yla "q"
p "euler.dat" u 2:3 w linespoints pt 6
