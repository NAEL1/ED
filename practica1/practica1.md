# Practica1

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

