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

#ifndef SPARSE_VECTORT_H_
#define SPARSE_VECTORT_H_

#include <iostream>
#include <math.h>  // fabs

#include "vector_t.h"
#include "pair_t.h"

/// The definition of the const kEps.
const double kEps = 1.0e-6;

/// Another names
typedef pair_t<double> pair_double_t;
typedef vector_t<pair_double_t> pair_vector_t;

/// Definition of the class sparse_vector_t
class sparse_vector_t {
 public:
  /// Constructors
  sparse_vector_t(const int = 0);
  sparse_vector_t(const vector_t<double>&, const double = kEps);
  sparse_vector_t(const sparse_vector_t&);  
  // destructor
  ~sparse_vector_t();  
  /// Operator overcharge
  sparse_vector_t& operator=(const sparse_vector_t&);
  /// getters
  int get_nz(void) const;
  int get_n(void) const;
  pair_vector_t get_pv(void) const {return pv_;};
  /// Getters-Setters
  pair_double_t& at(const int);
  pair_double_t& operator[](const int);
  /// Getters constantes
  const pair_double_t& at(const int) const;
  const pair_double_t& operator[](const int) const;
  /// Input / Output
  void write(std::ostream& = std::cout) const;
  bool IsNotZero(const double, const double = kEps) const;
 private:
  pair_vector_t pv_;  /// values + index
  int nz_;            /// Size of the sparse vector
  int n_;             /// Size of the original vetor
};

/**
 * @brief This method allow user to know if an elment is different than 0.
 * @param val : It is the value that will be compared
 * @param eps : It is the presition.
 * @return true 
 * @return false 
 */
bool IsNotZero(const double val, const double eps = kEps)  {
  return fabs(val) > eps;
}



/**
 * @brief It is the constructor with params.
 * @param n : It is the value that will be assigned.
 */
sparse_vector_t::sparse_vector_t(const int n) : pv_(n), nz_(0), n_(n) {}

// FASE II

/**
 * @brief It is a constructor
 * @param v : It is the vector that will be passed
 * @param eps : It is the presition.
 */

sparse_vector_t::sparse_vector_t(const vector_t<double>& v, const double eps) : pv_(), nz_(0), n_(0) {
  n_ = v.get_size();
  int size{0};
  for (int counter = 0; counter < v.get_size(); ++counter) {
    if (fabs(v[counter]) > eps) {
      ++size;
    }
  }
  pv_.resize(size);
  int counter2{0};
  for (int counter = 0; counter < v.get_size(); ++counter) {
    if (fabs(v[counter]) > eps) {
      pair_t<double> pair{v[counter], counter};
      pv_[counter2] = pair;
      counter2++;
    }
  }
  nz_ = size;
}

/**
 * @brief It is the copy constructor
 * @param w : It is the sparse vector.
 * @param eps : It is the presition.
 */
sparse_vector_t::sparse_vector_t(const sparse_vector_t& w) {
  *this = w;  // se invoca directamente al operator=   ???????????
}

/**
 * @brief This is the = operator overcharge.
 * @param w : It is the sparse vector.
 * @param val : It is the value that will be compared
 * @return this* : 
 */
sparse_vector_t& sparse_vector_t::operator=(const sparse_vector_t& w) {
  nz_ = w.get_nz();
  n_ = w.get_n();
  pv_ = w.pv_;
  return *this;
}

/**
 * @brief Is the destructor of the class.
 */
sparse_vector_t::~sparse_vector_t() {}


/**
 * @brief It is the getter of the size of the sparse vector.
 * @return nz_ : It is the size of the sparse vector. 
 */
inline int sparse_vector_t::get_nz() const {
  return nz_;
}


/**
 * @brief It is the getter of the size of the original vector.
 * @return n_ : It is the size of the original vector.
 */
inline int sparse_vector_t::get_n() const {
  return n_;
}



/**
 * @brief It is a mehtod that return the element that is in a specific position.
 * @param i : It is the position.
 * @return pv_[i] : It is the element in that position.
 */
pair_double_t& sparse_vector_t::at(const int i) {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}

/**
 * @brief Operator [] overcharge
 * @param i : It is the position.
 * @return pv_[i] : It is the element in that position.
 */
pair_double_t& sparse_vector_t::operator[](const int i) {
  return at(i);
}



/**
 * @brief It is a mehtod that return the element that is in a specific position. Const
 * @param i : It is the position.
 * @return pv_[i] : It is the element in that position.
 */
const pair_double_t& sparse_vector_t::at(const int i) const {
  assert(i >= 0 && i < get_nz());
  return pv_[i];
}



/**
 * @brief Operator [] overcharge const
 * @param i : It is the position.
 * @return pv_[i] : It is the element in that position.
 */
const pair_double_t& sparse_vector_t::operator[](const int i) const {
  return at(i);
}

/// Input / Output 

/**
 * @brief This method allow user to print a sparse_vector on the screen.
 * @param os : It is the output stream.
 */
void sparse_vector_t::write(std::ostream& os) const { 
  os << get_n() << "(" << get_nz() << "): [ ";
  for (int i = 0; i < get_nz(); i++)
    os << pv_[i] << " ";
	os << "]" << std::endl;
}

/**
 * @brief Operator << overcharge 
 * @param os : It is the output stream.
 */
std::ostream& operator<<(std::ostream& os, const sparse_vector_t& sv) {
  sv.write(os);
  return os;
}

#endif  // SPARSE_VECTORT_H_
