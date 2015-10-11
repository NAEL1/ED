#! /bin/bash

declare -i inicio=100
declare -i fin=30000
declare -i incremento=500
declare -i i=$inicio
sudo touch t_b_binaria.dat
while(($i < $fin));do
	echo `./ejercicio_desc $i  >> t_b_binaria.dat` 
	let i+=$incremento
done