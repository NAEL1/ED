# Gnuplot script para calcular las eficiencias de la practica1
# este archivo se carga en gnuplt usando el comando load'plot.p'
# @autor Nasrdine el houfi
# @version V 1.1

set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set xrange [100:30000]

#Generamos graficos de burbuja
unset label
set xlabel "Tamanio"
set ylabel "Tiempo (seg)"
#set title "Eficiencia Burbuja"

#plot 't_ordenacion.dat' with lines linecolor rgb "blue"

#set terminal png
#set output "burbuja.png"
#replot

#f(x)= a*x*x+b*x+c

#fit f(x) 't_ordenacion.dat' via  a,b,c

#plot 't_ordenacion.dat'with points ,f(x) with lines linecolor rgb "green" title 'curva ajustada burbuja'

#set terminal png
#set output "curva ajustada burbuja.png"
#replot

#f(x)=14*x*x+3*x+2
#set title "Eficiencia teorica Vs Eficiencia emperica"
#plot 't_ordenacion.dat' with points  title "Eficiencia emperica" ,f(x) with lines linecolor rgbg title "Eficiencia teorica"
#set output "teorica vs emperica.png"
#replot
#Generanos graficos eficiencia de insercion

#unset label
#set xlabel "Tamanio"
#set ylabel "Tiempo (seg)"
#set title "Eficiencia Insercion"

#plot 'Datos_insercion.dat' with lines linecolor rgb "blue"


#set title "burbuja_mejor_caso"
#plot 't_mejorcaso.dat' with lines linecolor rgb "green" title "mejor_caso"
#set terminal png
#set output "mejorcaso.png"
#replot



#set title "burbuja_peor_caso"
#plot 't_peorcaso.dat' with lines linecolor rgb "red" title "peor_caso"
#set terminal png
#set output "peorcaso.png"
#replot

#plot 't_ordenacion.dat'with lines linecolor rgb "blue" title "caso_normal" ,'t_peorcaso.dat' with lines linecolor rgb "red" title "peor_caso", 't_mejorcaso.dat' with lines linecolor rgb "green" title "mejor_caso"
#set terminal png
#set output "comparativa_burbuja.png"
#replot

set title "Eficiencia nueva Burbuja"
plot 't_nueva_burbuja.dat' with lines linecolor rgb "blue"
set terminal png
set output "nueva_burbuja.png"
replot