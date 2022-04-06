set term png
set out "langevin2.png"

set xla "t"
set yla "v"

unset key

p "langevin2.dat" w e pt 6 lc "blue", 0 lt 1 lc "black"
