set term pngcairo
unset key
set out "vv.png"
set size square
set xla "p"
set yla "q"
set xrange [-1.1:1.1]
set yrange [-1.1:1.1]
p "vv.dat" u 2:3 w linespoints pt 6
