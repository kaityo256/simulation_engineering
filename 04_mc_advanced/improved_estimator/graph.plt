set term pngcairo
set out "m2.png"
set xlabel "Temperature"
set ylabel "m^2"

p "L064.dat" u 1:2:4 w e pt 6 lc "blue" t "Normal"\
, "L064.dat" u 1:5:7 w e pt 7 lc "red "t "Improved Estimator"\
, "L064.dat" u 1:2 w l lc "blue" t ""\
, "L064.dat" u 1:5 w l lc "red" t ""


set out "m4.png"
set ylabel "m^4"

p "L064.dat" u 1:8:10 w e pt 6 lc "blue" t "Normal"\
, "L064.dat" u 1:11:13 w e pt 7 lc "red" t "Improved Estimator"\
, "L064.dat" u 1:8 w l lc "blue" t ""\
, "L064.dat" u 1:11 w l lc "red" t ""

set out "binder.png"
set ylabel "U"

p "L064.dat" u 1:14:16 w e pt 6 lc "blue" t "Normal"\
, "L064.dat" u 1:17:19 w e pt 7 lc "red " t "Improved Estimator"\
, "L064.dat" u 1:14 w l lc "blue" t ""\
, "L064.dat" u 1:17 w l lc "red" t ""
