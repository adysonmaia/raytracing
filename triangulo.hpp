/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __TRIANGULO_HPP__
#define __TRIANGULO_HPP__

#include "plano.hpp"

class Triangulo : public Objeto {
public:
  Triangulo(const Vetor3& v0, const Vetor3& v1, const Vetor3& v2, const Material& mat);
  Triangulo(const Vetor3& v0, const Vetor3& v1, const Vetor3& v2);
  Vetor3 operator[] ( size_t i ) const;
  Vetor3& operator[] ( size_t i );

  bool intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal);
  void mudancaBase(const Matriz4& matriz);
  Objeto* mudancaBaseCP(const Matriz4& matriz);
private:
  Vetor3 vertice[3];
};

#endif

