set term pngcairo
set out "revolving_small.png"

unset key
p [0:410000] [0:]"revolving.dat" u 1:3 with linespoints pt 6,x lc "black"
