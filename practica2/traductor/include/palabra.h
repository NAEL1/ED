/**
  * @file palabra.h
  * @brief Fichero cabezera del TDA palabra
  *
*/

#ifndef __palabra
#define __palabra
#include <string>
#include <vector>
  
using namespace std;

/*
 *@brief T.D.A palabra
 *
 * Una instancia @e c del tipo de datos abstracto @c palabra es objeto del conjunto de las palabras compuesto por 
 * una palabra en el idioma origen  y una lista de sus traducciones en el idioma destino.
 * Lo representamos por:
 * (Palabara_en_idioma_de_origen,{conjunto_de_palabras_equivalentes_en_idioma_distino})
 *
 *Un ejemplo de su uso:
 *@include pruebatraducor.cpp
 *
 *@author Nasrdine El houfi
 *@date octubre 2015
 */
class palabra{
private:
/**
	* @page repConjunto Rep del TDA palabra
	*
	* @section invConjunto_palabra Invariante de la representación
	*
	* El invariante es \e rep.p->caracteres ;  rep.traduccion-> equivalente de rep->p en idioma destino
	*
	* @section faConjunto_palabra Función de abstracción
	*
	* Un objeto válido @e rep del TDA palabra representa al valor
	*
	* (Palabara_en_idioma_de_origen,{conjunto_de_palabras_equivalentes_en_idioma_distino})
	*
*/
string p; /**< palabra idioma origen   */
vector<string > traduccion; /**< traduccion(es) de la origen en el idioma destino    */
public:

/**
	* @brief Constructor por defecto de la clase. Crea una palabra vacia y un vector de traduciones vacio
*/
palabra();



/**
  	* @brief Constructor de la clase
  	* @param origen palabra del idioma origen 
  	* @param trad vector de palabra(s) equivalente en el idioma destino
  	* @return Crea crea una palabra (Palabara_en_idioma_de_origen,{conjunto_de_palabras_equivalentes_en_idioma_distino})
  	* @pre origen y trad no pueden ser nulos
  	* @post palabra valida des diccionario
*/
palabra(const string &origen,const vector<string > &trad);


/**
  	* @brief Constructor de copias de la clase
  	* @param pal.origen palabra del idioma origen de la palabra a construir
	* @param pal.traduccion palabra(s) del idioma destino euivalent a pal.origen 	
*/
palabra(const palabra &pal);



/**
	* @brief Destructor  de la clase
*/
 ~palabra();


/**
  	* @brief Operador de asignacion
  	* @param pal palabra del diccionario que se va a asignar 
	* @return devuelve una referencia a la palabra asignada para permitir asignacion multiple
	* @pre la palabra que asigna no puede ser igual al asignado
	* @post palabra valida del diccionario
*/	 
palabra& operator=(const palabra &pal);



/**
	* @brief getOrigen
	* @return Devuelve la palabra origen
*/
string getOrigen()const;


/**
	* @brief getTraduccion
	* @return Devuelve la palabra(s) del idioma destino
*/	 
 vector<string > getTraduccion()const;

/*
	*@breif addTraducciones añade traduciones al TDA palabra
	*@param trad  palabra del idioma destino que queremos añadir al TDA palabra
	*@post las traducciones del TDA palabra seran ampliadas
 */
void addTraducciones(const string &trad);

};




#endif