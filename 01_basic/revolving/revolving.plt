set term pngcairo
set out "revolving.png"

unset key
p "revolving.dat" u 1:3 w linespoints pt 6
