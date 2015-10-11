# Gnuplot script para calcular las eficiencias de la practica1
# este archivo se carga en gnuplt usando el comando load'plot.p'
# @autor Nasrdine el houfi
# @version V 1.1

set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically

#Generamos graficos de burbuja
unset label
set xlabel "Tamanio"
set ylabel "Tiempo (seg)"
set title "Eficiencia Busqueda binaria"

plot 't_b_binaria.dat' title "Eficienca emperica" with lines linecolor rgb "blue"

set terminal png
set output "Busquedabin_aria.png"
replot