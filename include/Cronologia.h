#ifndef __CRONOLOGIA__
#define __CRONOLOGIA__

#include "./EventoHistorico.hpp"
#include <map>
#include <vector>
#include <string>
#include <set>
#include <fstream>
#include <iostream>

using namespace std;

class Cronologia{
private:
  vector<EventoHistorico> cronologia;

public:
  /**
   * @brief Constructor por defecto
   */
  Cronologia();

  /**
   * @brief Constructor con parametro
   * @param v Vector de EventoHistorico
   */
  Cronologia(const vector<EventoHistorico>& v);

  /**
   * @brief Constuctor de copia
   * @param c Objeto de Cronologia
   */
  Cronologia(const Cronologia &c);

  //operadores

  /**
   * @brief operador asignacion
   * @param c Objeto de Cronologia
   */
  Cronologia& operator=(const Cronologia &c);

  /**
   * @brief operador de igualacion
   * @param Objeto de Cronologia que comparar
   */
  Cronologia& operator==(const Cronologia &c);

  /**
   * @brief Operador de desigualdad
   * @param c Objeto de Cronologia
   */
  Cronologia& operator!=(const Cronologia &c);

  //Operadores entrada y salida
  
  /**
   * @brief Operador salida 
   * @param o Mensaje a mostrar
   * @param c Objeto de Cronologia
   */
  friend ostream& operator<<(ostream& o, Cronologia &c);

  /**
   * @brief Operator entrada
   * @param i Mensaje entrada
   * @param c Objeto de Cronologia
   */
  friend ifstream& operator>>(ifstream& i; Cronologia &c);

  //Clase anidada Iterator
  class Iterator{
  public:
    vector<EventoHistorico>::iterator it; //Deberia de ser private

    /**
     * @brief operador incremento
     */
    Iterator& operator++();

    /**
     * @brief Operador descremento
     */
    Iterator& operator--();

    /**
     * @brief operador de acceso
     */
    Iterator& operator*();

    /**
     * @brief Operador de igualacion
     * @param i Objeto de Iterator 
     */
    Iterator& operator==(const Iterator& i);

    
  };//Fin clase Iterator
}; //Fin clase Cronologia
