#ifndef __EVENT__
#define __EVENT__

#include <vector>
#include <set>
#include <string>

using namesapce std;

class EventoHistorico{
private:
  pair<int, set<string> > event;

public:

  /**
   * @brief Constructor
   */
  EventoHistorico(){};

  /**
   * @brief Constructor con parametros
   * @param y entero fecha
   * @param a vector de sucesos en esa fecha
   */
  EventoHistorico(const int y, const set<string> a);

  /**
   * @brief Constructor
   * @param y entero fecha
   * @param a string evento
   */
  EventoHistorico(const int y, const string a);

  /**
   * @brief Constructor
   * @param y entero año
   */
  EventoHistorico(const int y);

  /**
   * @brief Constructor de copia
   * @param c Objeto de EventoHistorico
   */
  EventoHistorico(const EventoHistorico& c);

  /**
   * @brief Destructor
   */
  ~EventoHistorico(){}

  //Operadores

  /**
   * @brief Operador de asignacion
   * @param c Objeto de EventoHistorico
   */
  EventoHistorico& operator=(const EventoHistorico& c);

  /**
   * @brief Operador de concatenacion
   * @param c Objeto de EventoHistorico
   */
  void operator+(const EventoHistorico& c);

  
  /**
   * @brief Operador de concatenacion
   * @param c set de strings sucesos
   */
  void operator+(const set <string>& c);

  
  /**
   * @brief Operador de igualdad
   * @param c Objeto de EventoHistorico
   */
  bool operator==(const EventoHistorico& c);

  
  /**
   * @brief Operador de diferencia
   * @param c Objeto de EventoHistorico
   */
  bool operator!=(const EventoHistorico& c);

  
  //Metodos TDA EventoHistorico
  
  /**
   * @brief Añade una ocurrencia
   * @param o String que define la ocurencia
   */
  void addOcurrence(string o);

  
  /**
   * @brief Añadir varias ocurrencias
   * @param o Set de strings que definen las ocurrencias
   */
  void addMultipleOcurrences(const set<string>& o);

  
  /**
   * @brief Añade varias ocurrencias
   * @param o Vector de ocurrencias 
   */
  void AddMultipleOcurrences(const vector<string>& o);

  
  /**
   * @brief Devuelve el año
   */
  int getYear() const;

  
  /**
   * @brief Devuelve un set de strings eventos
   */
  set<string>& getEvents();

  
  /**
   * @brief Busca por un valor clave que le pasas
   * @param key String que es la clave paa buscar
   */
  set<string>& findKeyWord(string key);

  //friend methods
  //ostream& operator<<(ostream& o, EventoHistorico& e);
};

#endif
