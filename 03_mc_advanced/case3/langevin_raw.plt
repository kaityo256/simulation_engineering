set term pngcairo
set out "langevin_raw.png"

unset key
set xla "t"
set yla "v"

p [0:100] "langevin_raw.dat" w linespoints pt 6 lc "blue", 0 lt 1 lc "black"

set out "langevin_long.png"

p [0:1000] "langevin_raw.dat" w l lc "blue", 0 lt 1 lc "black"
