/**
  * @file traductor.h
  * @brief Fichero cabezera del TDA traductor
  *
*/

#ifndef __traductor
#define __traductor

#include <iostream>
#include "palabra.h"
#include <utility>
using namespace std;

/*
 *@brief T.D.A traductor
 *
 * Una instancia @e c del tipo de datos abstracto @c traductor es objeto compuesto por un conjunto de TDA palabra
 * Lo representamos por:
 * {conjunto TDA palabra}
 *
 *Un ejemplo de su uso:
 *@include pruebatraducor.cpp
 *
 *@author Nasrdine El houfi
 *@date octubre 2015
 */
class traductor{
/**
  * @page repConjunto Rep del TDA traductor
  *
  * @section invConjunto_traductor Invariante de la representación
  *
  * El invariante es \e true;
  *
  * @section faConjunto_traductor Función de abstracción
  *
  * Un objeto válido @e rep del TDA traductor representa al valor
  *
  * {conjunto TDA palabra}
  *
  */
private:

	vector<palabra >  t;

public:

/**
	* @brief Constructor por defecto de la clase. Crea un vector de TDA palabra vacio
*/
traductor();


/**
	* @brief Constructor de copias de la clase
 	* @param tr.t conjunto de TDA palabra
*/
traductor(const traductor &tr);


/** 	
	* @brief Destructor  de la clase
*/
~traductor();


/**
	* @brief Compueba si existe una palabra origen en el traductor
	* @param s palabra origen que se va a buscar
	* @return devuelve true y posicion si existe palabra origen en el traducor y false y -1 si no esta 
*/
pair<bool,int> existe(const string s);


/**
	* @brief Inserta una TDA palabra en el traductor
	* @param P TDA palabra a insertar
  	* @post si p.origen existe en el traductor  si añadiran al traductor aquellas traducciones que no estas en p.traduccion
*/
void insert(palabra p);

/**
  	* @brief getTraducor 
	* @return Devuelve el conjunto de TDA palabra del traductor
*/
vector<palabra > getTraducor();

/**
  	* @brief getTraducor 
	* @return Devuelve el conjunto de TDA palabra del traductor
*/
vector<palabra > getTraducor()const;

/**
  	* @brief GetTraducciones 
	* @param origen palabra origen de la cual queremos las traduciones en el idioma destino
  	* @pre origen debe existir en el traductor
	* @return Devuelve el conjunto de palabras del idioma destino equivalentes a palabra 
*/
vector<string> GetTraducciones(const string &origen);

/*
	*@brief salida de un traductor a ostream
	*@param out es el stream de salida
	*@param tr es el traducror a escribir
	*@post se obtiene en \a out las cadena Palabra: \e palabra_origen Traduccion: \e palabra(s)_destino para cada elemento TDA palabra del diccionario
	*
*/
friend ostream& operator<<(ostream &out, const traductor &tr);


/*
	*@brief Entrada de un traductor desde istream
	*@param in es el stream de entrada
	*@param tr es el traducror leido
	*@post la entrada tiene un formato TDA palabra (palabra_origen.{conjunto_palabras_destino})
	* donde palabra.p es palabra_origen y palabra.traduccion es {conjunto_palabras_destino}
*/
friend istream& operator>>(istream &in,traductor &tr);


};


#endif
