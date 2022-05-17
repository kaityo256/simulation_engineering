set term pngcairo
set out "lj.png"
unset key

p [0.9:3.0] x**-12 - x**-6 lc "blue",0 lt 0 lc "black"
