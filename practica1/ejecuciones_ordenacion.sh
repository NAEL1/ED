#! /bin/bash

declare -i inicio=100
declare -i fin=30000
declare -i incremento=500
declare -i i=$inicio
while(($i < $fin));do
	echo `./ordenacion $i 10000 >> t_ordenacion.dat`
    echo `./mejor_caso $i 10000 >> t_mejorcaso.dat`
    echo `./peor_caso $i 10000 >> t_peorcaso.dat`
	#echo `./nueva_burbuja $i 10000 >> t_nueva_burbuja.dat`
	#echo `./ordenacion_optimizado $i 10000 >> t_ordenacion_optimizado.dat`

	
	let i+=$incremento
done
