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

    
    /**
     * @brief Operador que comprueba si son diferentes
     * @param i Objeto de Iterator 
     */
    bool operator!=(const Iterator& i);

    /**
     * @brief Devuelve el inicio de la Cronologia 
     */
    Iterator begin();

    
    /**
     * @brief Devuelve el fin de la Cronologia 
     */
    Iterator end();

    /**
     * @brief Inserta los datos de los dos iteradores en la cronologia
     * @param it Objeto de Iterator
     * @param it2 Objeto de Iterator
     */
    void insert(const Iterator& it, const Iterator& it2);
    
    /**
     * @brief Inserta el e a partir del iterador it
     * @param it Objeto de Iterator
     * @param e Objeto de EventoHistorico
     */
    void insert(const Iterator& it, const EventoHistorico& e);

    //Clase const_Iterator

    class const_Iterator{
    public:
      vector<EventoHistorico>::const_iterator it;

      
    /**
     * @brief Operador de incremento
     */
    const_Iterator& operator++();
    
    /**
     * @brief Operador de descremento
     */
    const_Iterator& operator--();

    /**
     * @brief Operador de acceso
     */
    const_Iterator& operator*();

    /**
     * @brief Operador que comprueba si son iguales
     * @param i Objeto de const_Iterator 
     */
    bool operator==(const cosnt_Iterator& i);

    /**
     * @brief Operador que comprueba si son distintos
     * @param i Objeto de Iterator 
     */
    bool operator!=(const const_Iterator& i);
    
    /**
     * @brief Devuelve el comienzo de const_Iterator
     */
    const_Iterator begin_const() const;
    
    /**
     * @brief Devuelve el final de const_Iterator
     */
    const_Iterator end_const() const;
    
    // Funciones para operar en cronologias
    
    /**
     * @brief Union con un objeto que le pasas por parametro
     * @param c Objeto constante de Cronologia
     */
    void join(const Cronologia& c);
    
    /**
     * @brief Intercambia por el objeto que le pasas por parametro
     * @param c Objeto de Cronologia
     */
    void swap(Cronologia& c);
    
    /**
     * @brief Busca en un intervalo
     * @param begin Entero que marca comienzo
     * @param end Entero que marca final
     */
    Cronologia& findByInterval(int begin, int end) const;
    
    /**
     * @brief Saca estadisticas
     */
    void findStadistics() const;
    
    };//Fin clase const_Iterator
  };//Fin clase Iterator
}; //Fin clase Cronologia

#endif
