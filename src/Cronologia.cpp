#include "../include/Cronologia.h"

using namespace std;

Cronologia::Cronologia(vector<EventoHistorico>& v){
  vector<EventoHistorico>::iterator it = v.begin();
  pair<int, EventoHistorico> aux;

  for(it; it != v.end(); ++it){
    aux.first = (*it).getYear();
    aux.seccond = (*it);

    this->cronologia.insert(aux);
  }
}

Cronologia::Cronologia(const Cronologia& c){
  this->cronologia = c.cronologia;
}

Cronologia& Cronologia::operator=(const Cronologia& c){
  if(*this != c){
    this->cronlogia = c.cronologia;
  }

  return this;
}



bool Cronologia::opeartor==(const Cronologia& c){
  map<int, EventoHistorico>::iterator it = this->cronologia.begin();
  map<int, EventoHistorico>::iterator it2 = c.cronologia.begin();
  bool equal = false;

  if(this->cronologia.size() == c.cronologia.size()){
    equal = true;
    for(it, it2; it != this->cronologia.end() && it2 != c.cronologia.end() && equal; ++it, ++it2){
      if((*it) != *(it2))
	equal = false;
    }

  }

  return equal;
}

bool Cronologia::operator!=(const Cronologia& c){
  return !(this == c);
}

ostream& operator<<(ostream& o, Cronologia& c){
  map<int, EventoHistorico>::iterator it = c.begin();

  for(it; it != c.cronlogia.end(); ++it){
    o << (*it);
  }

  return o;
}

