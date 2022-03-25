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
#ifndef POLYNOMIAL_H_
#define POLYNOMIAL_H_

#include <iostream>
#include <math.h>  

#include "vector_t.h"
#include "sparse_vector_t.h"

// Clase para polinomios basados en vectores densos de doubles
class Polynomial : public vector_t<double> {
 public:
  /// Constructors
  Polynomial(const int n = 0) : vector_t<double>(n) {};
  Polynomial(const Polynomial& pol): vector_t<double>(pol) {}; // constructor de copia
  /// Destructors
  ~Polynomial() {};
  /// Input / Output 
  void Write(std::ostream& = std::cout, const double eps = kEps) const;
  /// Operations
  double Eval(const double) const;
  bool IsEqual(const Polynomial&, const double = kEps) const;
 };


// Clase para polinomios basados en vectores dispersos
class SparsePolynomial : public sparse_vector_t {
 public:
  /// Constructors
  SparsePolynomial(const int n = 0) : sparse_vector_t(n) {};
  SparsePolynomial(const Polynomial& pol) : sparse_vector_t(pol) {};
  SparsePolynomial(const SparsePolynomial&);  // constructor de copia
  /// Destructors
  ~SparsePolynomial() {};
  /// Input / Output
  void Write(std::ostream& = std::cout) const;
  /// Operations
  double Eval(const double) const;
  bool IsEqual(const SparsePolynomial&, const double = kEps) const;
  bool IsEqual(const Polynomial&, const double = kEps) const;
};

/**
 * @brief This method allow user to print a polynomial on the screen.
 * @param os : Output stream.
 * @param eps : The presition.
 */
void Polynomial::Write(std::ostream& os, const double eps) const {
  os << get_size() << ": [ ";
  bool first{true};
  for (int i{0}; i < get_size(); i++)
    if (IsNotZero(at(i), eps)) {
      os << (!first ? " + " : "") << at(i)
	 << (i > 1 ? " x^" : (i == 1) ? " x" : "");
      if (i > 1)
	os << i;
      first = false;
    }
  os << " ]" << std::endl;
}




/**
 * @brief Operator overcharge <<
 * @param os : Output stream.
 * @param p : The polynomial that will be printed.
 */
std::ostream& operator<<(std::ostream& os, const Polynomial& p) {
  p.Write(os);
  return os;
}

// Operations

/**
 * @brief Evaluation of a polynomial represented for an original vector.
 * @param x :
 * @return result
 */
double Polynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  return result;
}

// Comparación si son iguales dos polinomios representados por vectores densos
/**
 * @brief This method allow user to know if two vectors are equals
 * @param pol : It is one of the polynomials.
 * @param eps : It is the presition.
 * @return true 
 * @return false 
 */
bool Polynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  return !differents;
}

/**
 * @brief It is the copy constructor.
 * @param spol It is the polynomial that will be passed.
 */
SparsePolynomial::SparsePolynomial(const SparsePolynomial& spol) {
  *this = spol;   // se invoca directamente al operator=
}

/// Input / Output Sparce vector

/**
 * @brief This method allow user to print a sparse vector.
 * @param os : Output stream. 
 */
void SparsePolynomial::Write(std::ostream& os) const {
  os << get_n() << "(" << get_nz() << "): [ ";
  bool first{true};
  for (int i{0}; i < get_nz(); i++) {
    int inx{at(i).get_inx()};
    os << (!first ? " + " : "") << at(i).get_val()
       << (inx > 1 ? " x^" : (inx == 1) ? " x" : "");
    if (inx > 1)
      os << inx;
    first = false;
  }
  os << " ]" << std::endl;
}



/**
 * @brief Operator << overcharge
 * @param os : Output stream. 
 * @param p: It is the polynomial that will be printed.
 */
std::ostream& operator<<(std::ostream& os, const SparsePolynomial& p) {
  p.Write(os);
  return os;
}

// Operaciones con polinomios

// Evaluación de un polinomio representado por vector disperso
/**
 * @brief Evaluation of a polynomial represented for a sparce vector.
 * @param x :
 * @return result
 */
double SparsePolynomial::Eval(const double x) const {
  double result{0.0};
  // poner el código aquí
  return result;
}

/**
 * @brief This method allow user to know if two sparse vectors are equals
 * @param pol : It is one of the polynomials.
 * @param eps : It is the presition.
 * @return true 
 * @return false 
 */
bool SparsePolynomial::IsEqual(const SparsePolynomial& spol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  return !differents;
}

// Comparación si son iguales dos polinomios representados por
// vector disperso y vector denso
/**
 * @brief This method allow user to know if two sparse vectors are equals
 * @param pol : It is one of the polynomials.
 * @param eps : It is the presition.
 * @return true 
 * @return false 
 */
bool SparsePolynomial::IsEqual(const Polynomial& pol, const double eps) const {
  bool differents = false;
  // poner el código aquí
  return !differents;
}


#endif  // POLYNOMIAL_H_
