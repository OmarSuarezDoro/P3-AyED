/**
 * AUTOR: Omar Suárez Doro
 * FECHA: 25/03/2022
 * EMAIL: alu0101483474@ull.edu.es
 * VERSION: 1.0
 * ASIGNATURA: Algoritmos y Estructuras de Datos
 * PRÁCTICA Nº: 3
 * COMENTARIOS: se indican entre [] las pautas de estilo aplicadas de
 *              "C++ Programming Style Guidelines"
 *              https://geosoft.no/development/cppstyle.html
 * COMPILACIÓN: g++ -g rational_t.cpp main_p2.cpp -o main_p2
 */

#ifndef PAIRT_H_
#define PAIRT_H_

#include <iostream>


template<class T> 
class pair_t {
 public:
  /// Constructors
  pair_t(void); 
  pair_t(T, int);

  /// Destructores
  ~pair_t(void);

  /// Getters
  T get_val(void) const;
  int get_inx(void) const;
  /// Setters
  void set(T, int);
  /// Input / Output methods
  std::istream& read(std::istream& is = std::cin);
  std::ostream& write(std::ostream& os = std::cout) const;

 private:
  T value_;
  int inx_;
};

/**
 * @brief Is the constructor of the class without parameters.
 */
template<class T> 
pair_t<T>::pair_t() : value_(), inx_(-1) {}

/**
 * @brief Constructor with params.
 * @param val : Is the value that will be assigned.
 * @param inx : It is the index of the NO NULL element.
 */
template<class T> 
pair_t<T>::pair_t(T val, int inx) : value_(val), inx_(inx) {}



/**
 * @brief Is the destructor of the class.
 */
template<class T> 
pair_t<T>::~pair_t() {}



/**
 * @brief This method allow user to set the value of the attributes.
 * @param val : Is the value that will be re-assigned.
 * @param inx : It is the new value of the index.
 */
template<class T> 
void pair_t<T>::set(T val, int inx) {
  value_ = val;
  inx_ = inx;
}



/**
 * @brief Is the getter of inx_ attribute.
 * @return inx_ : The index
 */
template<class T> int pair_t<T>::get_inx() const {
  return inx_;
}

/**
 * @brief Is the getter of value_ attribute.
 * @return value_ : The value.
 */
template<class T> T pair_t<T>::get_val() const {
  return value_;
}



/**
 * @brief This method allow user to introduce pairs.
 * @param is: Is the input stream. 
 */
template<class T> std::istream& pair_t<T>::read(std::istream& is) {
  return is >> inx_ >> value_;
}



/**
 * @brief This method allow user to printe pairs on the screen.
 * @param os : Is the output stream.
 */
template<class T> std::ostream& pair_t<T>::write(std::ostream& os) const {
  return os << "(" << inx_ << ":" << value_ << ")";
}



/**
 * @brief This is the overcharge of << operator.
 * @param os : Is the output stream.
 * @param p : It is the pair that will be printed on the screen.
 */
template<class T> std::ostream& operator<<(std::ostream& os,
					   const pair_t<T>& p) {
  p.write(os);
  return os;
}

#endif  // PAIRT_H_
