#! /bin/bash

inicio = 100
fin = 30000
incremento = 500

i= $inicio

while($i <= $fin)
	echo `./ordenacion.cpp $i 10000` >> t_ordenacion.dat
end