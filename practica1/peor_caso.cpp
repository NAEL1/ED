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
for (int i=0; i<tam; i++) // Recorrer vector
	v[i] = tam-i-1; 

//clock_t tini;
//tini=clock();// Anotamos el tiempo de inicio
//int x = vmax+1; // Buscamos un valor que no está en el vector
high_resolution_clock::time_point start = high_resolution_clock::now();
for(int i=0; i<10;i++)
	ordenar(v,tam);
//clock_t tfin;
//tfin=clock();
high_resolution_clock::time_point end = high_resolution_clock::now();
duration<double> tiempo = duration_cast<duration<double>>(end-start)/10.0;
// Anotamos el tiempo de finalización
// Mostramos resultados (Tamaño del vector y tiempo de ejecución en seg.)
cout << tam << "\t" << tiempo.count() << endl;
delete [] v;// Liberamos memoria dinámica

}