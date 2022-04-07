set term pngcairo
set out "bias.png"

set xlabel "N"
set ylabel "<1/{/Symbol m}>"
unset key

p "bias.dat" u 1:2:3 w e pt 6 lc "blue"\
,2.0/7.0 lt 1 lc "black"\
, "bias.dat" u 1:2 w l lc "blue"

