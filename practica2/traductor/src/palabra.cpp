#include "palabra.h"
#include <cassert>


//Constructor por defecto
palabra::palabra(){
}

//Constructor
palabra::palabra(const string &origen,const vector<string > &trad){
	assert(!origen.empty() && !trad.empty());
	this->p=origen;
	this->traduccion=trad;
}

//Constructor de copia
palabra::palabra(const palabra &pal){
	this->p=pal.p;
	this->traduccion=pal.traduccion;
}

//destructor
palabra::~palabra(){
}

//devuelve palabra origen
string palabra::getOrigen()const{
	return this->p;
}

// devuelve palabra(s) destino
vector<string > palabra::getTraduccion()const{
	return this->traduccion;
}



//Operador =
palabra& palabra::operator=(const palabra &pal){
	if(this!=&pal){
		this->p=pal.p;
		this->traduccion=pal.traduccion;
	}
	return *this;
}


void palabra::addTraducciones(const string &trad){
	bool existe=false;
	for(unsigned int i=0; i<this->traduccion.size() && !existe;i++){
		if(this->traduccion[i]==trad)
			existe=true;
	}
	if(!existe)
		this->traduccion.push_back(trad);
}

