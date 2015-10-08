!# /bin/bash

inicio=100
fin=30000
incremento=500

let i=inicio

while($i <= $fin)
	echo `./ordenacion.cpp $i 10000` >> t_ordenacion.datet
	let i+=incremento
end