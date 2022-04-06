set term png
set out "langevin.png"

set xla "t"
set yla "v"

unset key
p "langevin.dat" w e pt 6 lc "blue"

set out "langevin_line.png"

p "langevin.dat" w e pt 6 lc "blue", 0 lt 1 lc "black"
