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
#include <iostream>

#include "polynomial.h"

int main() {
  Polynomial p1, p2, p3;
  
  std::cin >> p1 >> p2 >> p3;
  std::cout << "p1= " << p1;
  std::cout << "p2= " << p2;
  std::cout << "p3= " << p3;
  std::cout << std::endl;

   // Fase II
  SparsePolynomial sp1(p1), sp2(p2), sp3(p3);
  std::cout << "sp1= " << sp1;
  std::cout << "sp2= " << sp2;
  std::cout << "sp3= " << sp3;
  std::cout << std::endl;

  // Fase III
  double x1, x2, x3;
  std::cin >> x1 >> x2 >> x3;
  std::cout << "p1(" << x1 << ")= " << p1.Eval(x1) << std::endl;
  std::cout << "p1(" << x2 << ")= " << p1.Eval(x2) << std::endl;
  std::cout << "p1(" << x3 << ")= " << p1.Eval(x3) << std::endl;
  std::cout << "p2(" << x1 << ")= " << p2.Eval(x1) << std::endl;
  std::cout << "p2(" << x2 << ")= " << p2.Eval(x2) << std::endl;
  std::cout << "p2(" << x3 << ")= " << p2.Eval(x3) << std::endl;
  std::cout << "p3(" << x1 << ")= " << p3.Eval(x1) << std::endl;
  std::cout << "p3(" << x2 << ")= " << p3.Eval(x2) << std::endl;
  std::cout << "p3(" << x3 << ")= " << p3.Eval(x3) << std::endl;
  std::cout << std::endl;

  std::cout << "sp1(" << x1 << ")= " << sp1.Eval(x1) << std::endl;
  std::cout << "sp1(" << x2 << ")= " << sp1.Eval(x2) << std::endl;
  std::cout << "sp1(" << x3 << ")= " << sp1.Eval(x3) << std::endl;
  std::cout << "sp2(" << x1 << ")= " << sp2.Eval(x1) << std::endl;
  std::cout << "sp2(" << x2 << ")= " << sp2.Eval(x2) << std::endl;
  std::cout << "sp2(" << x3 << ")= " << sp2.Eval(x3) << std::endl;
  std::cout << "sp3(" << x1 << ")= " << sp3.Eval(x1) << std::endl;
  std::cout << "sp3(" << x2 << ")= " << sp3.Eval(x2) << std::endl;
  std::cout << "sp3(" << x3 << ")= " << sp3.Eval(x3) << std::endl;
  std::cout << std::endl;

  // Fase IV
  std::cout << "p1 == p1? " << (p1.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "p2 == p2? " << (p2.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "p3 == p3? " << (p3.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "p1 == p2? " << (p1.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "p2 == p1? " << (p2.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "p1 == p3? " << (p1.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "p3 == p1? " << (p3.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "p2 == p3? " << (p2.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "p3 == p2? " << (p3.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << std::endl;

  std::cout << "sp1 == sp1? " << (sp1.IsEqual(sp1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == sp2? " << (sp2.IsEqual(sp2) ? "true" : "false") << std::endl;
  std::cout << "sp3 == sp3? " << (sp3.IsEqual(sp3) ? "true" : "false") << std::endl;
  std::cout << "sp1 == sp2? " << (sp1.IsEqual(sp2) ? "true" : "false") << std::endl;
  std::cout << "sp2 == sp1? " << (sp2.IsEqual(sp1) ? "true" : "false") << std::endl;
  std::cout << "sp1 == sp3? " << (sp1.IsEqual(sp3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == sp1? " << (sp3.IsEqual(sp1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == sp3? " << (sp2.IsEqual(sp3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == sp2? " << (sp3.IsEqual(sp2) ? "true" : "false") << std::endl;
  std::cout << std::endl;

  std::cout << "sp1 == p1? " << (sp1.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == p2? " << (sp2.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "sp3 == p3? " << (sp3.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "sp1 == p2? " << (sp1.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << "sp2 == p1? " << (sp2.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "sp1 == p3? " << (sp1.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == p1? " << (sp3.IsEqual(p1) ? "true" : "false") << std::endl;
  std::cout << "sp2 == p3? " << (sp2.IsEqual(p3) ? "true" : "false") << std::endl;
  std::cout << "sp3 == p2? " << (sp3.IsEqual(p2) ? "true" : "false") << std::endl;
  std::cout << std::endl;


  std::cout << "Modificación" << std::endl << std::endl;
  /*
  std::cout << sp1;
  std::cout << sp1.Converter();
  sp1.Converter().Write0s();

  std::cout << p3;
  p3.WriteChain();
  std::cout << "\n"; 
*/
  return 0;
}
