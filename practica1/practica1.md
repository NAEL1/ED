# Practica1

# enlace: https://github.com/NAEL1/ED/blob/master/practica1/

```
Procesador: Intel(R) Core(TM) i5-4200U CPU @ 1.60GHz
Memoria:
       tamaño: 3836Mi
Disco: ATA Disk
       HGST HTS545050A7
       versión: AF10
       serie: TEA55C5G0V2GMN
       tamaño: 465GiB (500GB)

compilador: g++ version 4.9.2

SO: 3.19.0-30-generic #34-Ubuntu  x86_64 GNU/Linux
```


## Ejercicio1:

###El siguiente código realiza la ordenación mediante el algoritmo de la burbuja:

```c++ 
1 void ordenar(int *v, int n) {
2	for (int i=0; i<n-1; i++)
3		for (int j=0; j<n-i-1; j++)
4			if (v[j]>v[j+1]) {
5				int aux = v[j];
6				v[j] = v[j+1];
7				v[j+1] = aux;
8			}
9  }
``` 
###Calcule la eficiencia teórica de este algoritmo:


```
linea 2: 4 OE de las cuales 1 se ejecuta 1 vez( int i=0)

linea 3: 4 OE de las cuales 1 se ejecuta 1 vez( int j=0)

linea 4: 3 OE

linea 5: 3 OE

linea 6: 3 OE

linea 7: 2 OE
```


			

![pr1-1](https://github.com/NAEL1/ED/blob/master/practica1/pr1-1.png)


###Crear un fichero ordenacion.cpp

Compilado con : 
```bash
g++ -o ordenacion  ordenacion.cpp -std=c++11
```
```c++
#include <iostream>
#include <ctime>
#include <ratio>
#include <chrono>
// Recursos para medir tiempos
#include <cstdlib> // Para generación de números pseudoaleatorios
using namespace std;
using namespace std::chrono;

void ordenar(int *v, int n) {
	for (int i=0; i<n-1; i++)
		for (int j=0; j<n-i-1; j++)
			if (v[j]>v[j+1]) {
				int aux = v[j];
				v[j] = v[j+1];
				v[j+1] = aux;
			}
}

void sintaxis() {
	cerr << "Sintaxis:" << endl;
	cerr << " TAM: Tamaño del vector (>0)" << endl;
	cerr << " VMAX: Valor máximo (>0)" << endl;
	cerr << "Genera un vector de TAM números aleatorios en [0,VMAX[" << endl;
	exit(EXIT_FAILURE);
}

int main(int argc, char * argv[]) {
	if (argc!=3) // Lectura de parámetros
		sintaxis();
	int tam=atoi(argv[1]);// Tamaño del vector
	int vmax=atoi(argv[2]);// Valor máximo
	if (tam<=0 || vmax<=0)
		sintaxis();

// Generación del vector aleatorio

int *v=new int[tam];// Reserva de memoria
srand(time(0));// Inicialización generador números pseudoaleatorios
for (int i=0; i<tam; i++) // Recorrer vector
	v[i] = rand() % vmax; // Generar aleatorio [0,vmax[

//clock_t tini;
//tini=clock();// Anotamos el tiempo de inicio
//int x = vmax+1; // Buscamos un valor que no está en el vector
high_resolution_clock::time_point start = high_resolution_clock::now();
ordenar(v,tam);
//clock_t tfin;
//tfin=clock();
high_resolution_clock::time_point end = high_resolution_clock::now();
duration<double> tiempo = duration_cast<duration<double>>(end-start);
// Anotamos el tiempo de finalización
// Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
cout << tam << "\t" << tiempo.count() << endl;
delete [] v;// Liberamos memoria dinámica

}
```


### Crear un script ejecuciones_ordenacion.sh en bash que permite ejecutar varias veces el programa anterior y generar un fichero con los datos obtenidos.

```bash
	declare -i inicio=100
	declare -i fin=30000
	declare -i incremento=500
	declare -i i=$inicio

	while(($i < $fin));do
		echo `./ordenacion $i 10000` >> t_ordenacion.dat
	done
```

### Usar gnuplot para dibujar los datos obtenidos en el apartado previo.
Script para Gnuplot:
```plot
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
set title "Eficiencia Burbuja"

plot 't_ordenacion.dat' with lines linecolor rgb "blue"

set terminal png
set output "burbuja.png"
replot

f(x)= a*x*x+b*x+c

fit f(x) 't_ordenacion.dat' via  a,b,c

plot 't_ordenacion.dat'with points ,f(x) with lines linecolor rgb "green" title 'curva ajustada burbuja'

set terminal png
set output "curva ajustada burbuja.png"
replot

f(x)=14*x*x+3*x+2
set title "Eficiencia teorica Vs Eficiencia emperica"
plot 't_ordenacion.dat' with points  title "Eficiencia emperica" ,f(x) with lines linecolor rgbg title "Eficiencia teorica"
set output "teorica vs emperica.png"
replot

```
Graficas:

![burbuja.png](https://github.com/NAEL1/ED/blob/master/practica1/burbuja.png)


### Pruebe a dibujar superpuestas la función con la eficiencia teórica y la empírica. ¿Qué
sucede?

![emperiva vs teorica](https://github.com/NAEL1/ED/blob/master/practica1/teorica%20vs%20emperica.png)


tal como se ve en la grafica la funcion  teorica  esta mal ajustada ya que acota muy por encima a la curva teorica .

## Ejercicio 2: Ajuste en la ordenación de la burbuja

###Replique el experimento de ajuste por regresión a los resultados obtenidos en el ejercicio1 que calculaba la eficiencia del algoritmo de ordenación de la burbuja. Para ello
considere que f(x) es de la forma ax2+bx+c

![curva ajustada burbuja.png](https://github.com/NAEL1/ED/blob/master/practica1/curva%20ajustada%20burbuja.png)

Funcion de ajuste:
```
f(x)= a*x*x+b*x+c

a               = 3.76715e-09      +/- 4.677e-11    (1.241%)
b               = -5.06617e-06     +/- 1.435e-06    (28.33%)
c               = -0.00100904      +/- 0.009223     (914%)
```

##Ejercicio 3: Problemas de precisión:

###Junto con este guión se le ha suministrado un fichero ejercicio_desc.cpp. En él se ha implementado un algoritmo. Se pide que:

####Explique qué hace este algoritmo.

Es un algoritmo de busqueda binario: mira si el valor buscado se encuentra en la mitad del vector sino compara el valor buscado con el valor que se encuentra en la mitad del vector si en menor, actliza el extremo superior del vector al valor medio mas 1, en cambio si es mallor que el valor medio actualiza el extremo inferior al valor medio menor uno.

#### Calcule su eficiencia teórica:

```c++
1 int operacion(int *v, int n, int x, int inf, int sup) {
2  int med;
3  bool enc=false;
4  while ((inf<sup) && (!enc)) {
5    med = (inf+sup)/2; 
6    if (v[med]==x) 
7      enc = true;
8    else if (v[med] < x) 
9      inf = med+1;
10   else
11      sup = med-1;
12  }
13  if (enc) 
14    return med;
15  else 
16    return -1;
17 }

``` 

```
linea  2: 1 OE (declaracion)

linea  3: 1 OE (asignacion)

linea  4: 3 OE (comparacion inf<sup, comparacion (!enc) , operacion &&)

linea  5: 3 OE (suma , division y asignacion)

linea  6: 2 OE (acceso y comparacion)

linea  7: 1 OE (asignacion)

linea  8: 2 OE (acceso y comparacion)

linea  9: 2 OE (incremento y asignacion)

linea 11: 2 OE (decremento y asignacion)

linea 13: 1 OE (comparacion)

linea 14: 1 OE (devolucion)

linea 13: 1 OE (devolucion)

```

![pr1-2](https://github.com/NAEL1/ED/blob/master/practica1/pr1-2.png)

####Calcule su eficiencia empírica.
primero modificamos el cpp proporcionado para tener unas medidas mas precisas

```c++
#include <iostream>
#include <ctime>    // Recursos para medir tiempos
#include <cstdlib>  // Para generación de números pseudoaleatorios
#include <ratio>
#include <chrono>

using namespace std;
using namespace std::chrono;

int operacion(int *v, int n, int x, int inf, int sup) {
  int med;
  bool enc=false;
  while ((inf<sup) && (!enc)) {
    med = (inf+sup)/2; 
    if (v[med]==x) 
      enc = true;
    else if (v[med] < x) 
      inf = med+1;
    else
      sup = med-1;
  }
  if (enc) 
    return med;
  else 
    return -1;
}

void sintaxis()
{
  cerr << "Sintaxis:" << endl;
  cerr << "  TAM: Tamaño del vector (>0)" << endl;
  cerr << "Se genera un vector de tamaño TAM con elementos aleatorios" << endl;
  exit(EXIT_FAILURE);
}

int main(int argc, char * argv[])
{
  // Lectura de parámetros
  if (argc!=2)
    sintaxis();
  int tam=atoi(argv[1]);     // Tamaño del vector
  if (tam<=0)
    sintaxis();
  
  // Generación del vector aleatorio
  int *v=new int[tam];       // Reserva de memoria
  srand(time(0));            // Inicialización del generador de números pseudoaleatorios
  for (int i=0; i<tam; i++)  // Recorrer vector
    v[i] = rand() % tam;
  
  //clock_t tini;    // Anotamos el tiempo de inicio
  //tini=clock();
  high_resolution_clock::time_point start = high_resolution_clock::now();
  // Algoritmo a evaluar
  operacion(v,tam,tam+1,0,tam-1);
  
  //clock_t tfin;    // Anotamos el tiempo de finalización
  //tfin=clock();
  high_resolution_clock::time_point end = high_resolution_clock::now();
  duration<double> tiempo = duration_cast<duration<double>>(end-start);

  // Mostramos resultados
  cout << tam << "\t" << tiempo.count() << endl;
  
  delete [] v;     // Liberamos memoria dinámica
}
```

Compilado con : 
```bash
g++ -o ejercicio_desc  ejercicio_desc.cpp -std=c++11
```
![Busquedabin_aria](https://github.com/NAEL1/ED/blob/master/practica1/Busquedabin_aria.png)

####Si visualiza la eficiencia empírica debería notar algo anormal. Explíquelo y proponga una solución. Compruebe que su solución es correcta. Una vez resuelto el problema realice la regresión para ajustar la curva teórica a la empírica.

se observan picos irregulares, la grafica tiene mucho ruido.
eso esta debido a que el vector no esta ordenado. para solucionar este problema deberiamos ordenar el vector antes de aplicar la busqueda binaria.


![busqueda_binaria](https://github.com/NAEL1/ED/blob/master/practica1/busqueda_binaria.png)

 Dado que el tiempo de ejecucion es muy pequeño aun se aprecian picos  aunque la grafica ha mejorado ya  excepcion de unos datos anomalos e puede apreciar una curva logaritmica,(los picos en este caso se deben a las condiciones incontrolables del test ya que los procesos secundarios de S.O. han podido intervenir)


##Ejercicio 4: Mejor y peor caso

###Retome el ejercicio de ordenación mediante el algoritmo de la burbuja. Debe modificar el código que genera los datos de entrada para situarnos en dos escenarios diferentes:

####El mejor caso posible. Para este algoritmo, si la entrada es un vector que ya está ordenado el tiempo de cómputo es menor ya que no tiene que intercambiar ningún elemento.

Para este caso basta con modificar el bucle que genera el vector como sigue:

``` c++ 
	for (int i=0; i<tam; i++) // Recorrer vector
		v[i] = i;
```

Compilamos el cpp:

```bash
	g++ -o mejor_caso  mejor_caso.cpp -std=c++11
```

La grafica seria:

![mejor_caso](https://github.com/NAEL1/ED/blob/master/practica1/mejorcaso.png)

####El peor caso posible. Si la entrada es un vector ordenado en orden inverso estaremos en la peor situación posible ya que en cada iteración del bucle interno hay que hacer un intercambio.

Para este caso basta con modificar el bucle que genera el vector como sigue:

``` c++ 
	for (int i=0; i<tam; i++) // Recorrer vector
		v[i] = tam-i-1;
```

Compilamos el cpp:

```bash
	g++ -o peor_caso  peor_caso.cpp -std=c++11
```
La grafica seria:

![peor_caso](https://github.com/NAEL1/ED/blob/master/practica1/peorcaso.png)



Finalmente comparando los datos obtenidos con los del ejercicio uno obtenemos la siguiente grafica

![comparativa](https://github.com/NAEL1/ED/blob/master/practica1/comparativa_burbuja.png)

tal como se ve en la grafica el caso promedio parece mas lento que el peor caso ,sospecho que es debido a la optimizacon que hace el g++ detecta que se trata de un vector ordenado inversamente y le da la vuelta  esto es debedo a que la opcion(implicta) por defecto es -O1,por lo que g++ somete el codigo a una optimoacion de nivel 1.
asi que voy a repetir las mediciones poniendo explicitamente la opcion -O0 para que el g++ no optimice el codigo.

```bash
	g++ -O0 -o ordenacion ordenacion.cpp -std=c++11
	g++ -O0 -o mejor_caso  mejor_caso.cpp -std=c++11
	g++ -O0 -o peor_caso  peor_caso.cpp -std=c++11
```
![comparativa_burbuja_2](https://github.com/NAEL1/ED/blob/master/practica1/comparativa_burbuja_2.png)

##Ejercicio 5: Dependencia de la implementación

###Considere esta otra implementación del algoritmo de la burbuja:

```c++
1	void ordenar(int *v, int n) {
2		bool cambio=true;
3		for (int i=0; i<n-1 && cambio; i++) {
4			cambio=false;
5			for (int j=0; j<n-i-1; j++)
6				if (v[j]>v[j+1]) {
7					cambio=true;
8					int aux = v[j];
9					v[j] = v[j+1];
10					v[j+1] = aux;
11				}
12		}
13	}

```
En ella se ha introducido una variable que permite saber si, en una de las iteraciones del bucle externo no se ha modificado el vector. Si esto ocurre significa que ya está ordenado y no hay que continuar.

#### Considere ahora la situación del mejor caso posible en la que el vector de entrada ya está ordenado. ¿Cuál sería la eficiencia teórica en ese mejor caso? Muestre la gráfica con la eficiencia empírica y compruebe si se ajusta a la previsión.

```
linea  2: 1 OE (asignacion)

linea  3: 5 OE (asignacion, comparacion,operacion &&, comparacion, incremento )

linea  4: 1 OE (asignacion)

linea  5: 3 OE (asignacion, comparacion, incremento )

linea  6: 1 OE (comparacion)

```

![pr1-3](https://github.com/NAEL1/ED/blob/master/practica1/pr1-3.png)


Compilamos el cpp:

```bash
	g++ -o nueva_burbuja  nueva_burbuja.cpp -std=c++11
```

La grafica de la eficiencia empírica es:


![nueva_burbuja](https://github.com/NAEL1/ED/blob/master/practica1/nueva_burbuja.png)

##Ejercicio 6: Influencia del proceso de compilación

###Retome el ejercicio de ordenación mediante el algoritmo de la burbuja. Ahora replique dicho ejercicio pero previamente deberá compilar el programa indicándole al compilador que optimice el código. Esto se consigue así:

```bash
g++ -O3 ordenacion.cpp -o ordenacion_optimizado -std=c++11
```
####Compare las curvas de eficiencia empírica para ver cómo mejora esto la eficiencia del programa.

![ordenacion_optimizado vs ordenacion](https://github.com/NAEL1/ED/blob/master/practica1/ordenacion_optimizado vs ordenacion.png)

