#include <iostream>
#include <cassert>
#include <cstdlib>
#include "traductor.h"

traductor::traductor(){

}


traductor::traductor(const traductor &tr){
	this->t=tr.t;
}


traductor::~traductor(){

}



pair<bool,int> traductor::existe(const string s){
	bool encontrado=false;
	unsigned int i=0;
	for(; i< this->t.size() && !encontrado ;i++){
		if(this->t[i].getOrigen()==s)
			encontrado=true;
	}
	if(encontrado)
		return pair<bool,int>(encontrado,i);
	else
		return pair<bool,int>(encontrado,-1);
}


//void setTraducciones(const string &origen, const vector<string > &trad){}


void traductor::insert(palabra p){
	pair<bool,int> aux=existe(p.getOrigen());
	if(!aux.first){
		this->t.push_back(p);
	}
	else{
		vector<string > v=p.getTraduccion();
		for(unsigned int i=0; i<v.size();i++){
			//cout << v[i] <<endl;
			this->t[aux.second-1].addTraducciones(v[i]);
		}
	}
}


vector<palabra > traductor::getTraducor(){
	return this->t;
}


vector<palabra > traductor::getTraducor()const{
	vector<palabra > v=this->t;
	return v;
}


vector<string> traductor::GetTraducciones(const string &origen){
	vector <string > s;
	if(!existe(origen).first){
		s.push_back("la palabra que ha introducido no existe en el diccionario, prueba con otra :-)\0");
		return s;
	}
	vector <palabra > v=getTraducor();
	for(unsigned int i=0 ; i < v.size();i++){
		if(v[i].getOrigen()==origen)
				s=v[i].getTraduccion();
	}
	return s;
}


ostream& operator<<(ostream &out, const traductor &tr){
	vector<palabra > v=tr.getTraducor();
	for(unsigned int i=0;i<v.size();i++){
		out << "Palabra:\t " << v[i].getOrigen();
		vector<string > vt=v[i].getTraduccion();
		out << "Traduccion:\t " << v[i].getOrigen();
		for(unsigned int i=0;i<vt.size();i++){
			out << vt[i] << ";\t ";
		}
		out << endl;
	}
	return out;
}


istream& operator>>(istream &in, traductor  &tr){
	string s,aux;
	vector<string > v;
	while(getline(in,s)){
		for(unsigned int i=0; i<s.size();i++){
			if(s[i]!=';'){
				aux.push_back(s[i]);
			}else{
				v.push_back(aux);
				aux.clear();
			}
		}
		s.clear();
		s=v[0];
		//cout<< "palabra original: " << s << "\n traduccion: ";
		v.erase(v.begin());
		//for(unsigned int i=0;i<v.size();i++)
		//		cout<< v[i] << " ; ";
		//cout<< endl;
		palabra p(s,v);
		//cout<< "palabra original: " << p.getOrigen() <<endl;
		tr.insert(p);
		s.clear();
		v.clear();

	}
	return in;
}
