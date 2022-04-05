set term pngcairo
set out "errorbar.png"

set xra [0.9:2.0]
unset key

p "errorbar.dat" u 1:2:3 w e pt 6 lc "blue"
