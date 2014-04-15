reset
cd  'D:\uni\mathe2\mathe2_praktikum\aufgb1'
set xrange[0:60]
set yrange[0:1]
plot 'V_2.txt' u 1:2 w lines
pause -1
set yrange[0.0001:1]
set logscale y
plot 'V_2.txt' u 1:2 w lines