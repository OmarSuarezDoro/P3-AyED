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

#ifndef VECTORT_H_
#define VECTORT_H_

#include <iostream>
#include <cassert>

template<class T> class vector_t {
 public:
  /// Constructors
  vector_t(const int = 0);
  vector_t(const vector_t&); // constructor de copia
  /// Assignation operator
  vector_t<T>& operator=(const vector_t<T>&);
  /// Destructor
  ~vector_t();
  /// Getters
  T get_val(const int) const;
  int get_size(void) const;
  /// Setters
  void set_val(const int, const T);
  void set_size(const int s) {size_ = s;};
  /// Getters-Setters
  T& at(const int);
  T& operator[](const int);
  /// Getters constantes
  const T& at(const int) const;
  const T& operator[](const int) const;
  /// Resize
  void resize(const int);
  /// Input / Output
  void read(std::istream& = std::cin);
  void write(std::ostream& = std::cout) const;

 private:
  T* v_;
  int size_;
  
  void build(void);
  void destroy(void);
};

/**
 * @brief It is the constructor of the class with params.
 * @param n: the size of the vector. 
 */
template<class T> vector_t<T>::vector_t(const int n) : v_(NULL), size_(n) {
  build();
}

/**
 * @brief Copy constructor
 * @param w: the vector. 
 */
template<class T> vector_t<T>::vector_t(const vector_t<T>& w)
    : v_(NULL), size_(0) {
  *this = w; // se invoca directamente al operator=
}

/**
 * @brief Assignation operator 
 * @param n: It is the vector that will be assigned to another one. 
 */
template<class T> vector_t<T>& vector_t<T>::operator=(const vector_t<T>& w) {
  resize(w.get_size());
  for (int i = 0; i < get_size(); i++)
    at(i) = w.at(i);
  
  return *this;
}


/**
 * @brief It is the destructor of the class
 */
template<class T> 
vector_t<T>::~vector_t() {
  destroy();
}


/**
 * @brief This method is used by the constructors. 
 */
template<class T> 
void vector_t<T>::build() {
  v_ = NULL;
  if (size_ != 0) {
    v_ = new T[size_];
    assert(v_ != NULL);
  }
}



/**
 * @brief This method is used by the destructor. 
 */
template<class T> 
void vector_t<T>::destroy() {
  if (v_ != NULL) {
    delete[] v_;
    v_ = NULL;
  }
  size_ = 0;
}


/**
 * @brief This mehod set the size of the vector. 
 * @param n : The size that will be assigned.
 */
template<class T> 
void vector_t<T>::resize(const int n) {
  destroy();
  size_ = n;
  build();
}




/**
 * @brief Getter of the value.
 * @param i : It is the position.
 */
template<class T> 
inline T vector_t<T>::get_val(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



/**
 * @brief Getter of the size of the vector.
 */
template<class T> 
inline int vector_t<T>::get_size() const {
  return size_;
}



/**
 * @brief Setter of the value.
 * @param i : It is the position.
 * @param d : value that will be assigned.
 */
template<class T> 
void vector_t<T>::set_val(const int i, const T d) {
  assert(i >= 0 && i < get_size());
  v_[i] = d;
}



/**
 * @brief This method allow user to know the element of a vector in a specific position.
 * @param i : It is the position.
 */
template<class T> 
T& vector_t<T>::at(const int i) {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



/**
 * @brief Operator [] overload
 * @param i : It is the position.
 */
template<class T> 
T& vector_t<T>::operator[](const int i) {
  return at(i);
}



/**
 * @brief This method allow user to know the element of a vector in a specific position. Const
 * @param i : It is the position.
 */
template<class T> 
const T& vector_t<T>::at(const int i) const {
  assert(i >= 0 && i < get_size());
  return v_[i];
}



/**
 * @brief This method allow user to know the element of a vector in a specific position. Const
 * @param i : It is the position.
 */
template<class T> 
const T& vector_t<T>::operator[](const int i) const {
  return at(i);
}



/**
 * @brief This method allow user to introduce a Vector
 * @param is : Input stream.
 */
template<class T> 
void vector_t<T>::read(std::istream& is) {
  is >> size_;
  resize(size_);
  for (int i = 0; i < size_; i++)
    is >> at(i);
}



/**
 * @brief This method allow user to print a vector on the screen.
 * @param os : Output stream.
 */
template<class T> 
void vector_t<T>::write(std::ostream& os) const {
  os << get_size() << ": [ ";
  for (int i = 0; i < get_size(); i++)
    os << at(i) << (i != get_size() - 1 ? "\t" : "");
  os << " ]" << std::endl;
}



/**
 * @brief Operator >> overcharge
 * @param is : Input stream.
 * @param v : The vector that will be inserted.
 */
template<class T> std::istream& operator>>(std::istream& is, vector_t<T>& v) {
  v.read(is);
  return is;
}



/**
 * @brief Operator << overcharge
 * @param is : Output stream.
 * @param v : The vector that will be printed.
 */
template<class T> std::ostream& operator<<(std::ostream& os,
					   const vector_t<T>& v) {
  v.write(os);
  return os;
}

#endif  // VECTORT_H_
