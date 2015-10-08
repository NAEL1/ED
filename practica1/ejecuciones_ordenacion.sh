#! /bin/bash

declare -i inicio=100
declare -i fin=30000
declare -i incremento=500

declare -i i=$inicio

while(($i < $fin));do
	echo `./ordenacion $i 10000` >> t_ordenacion.dat
done