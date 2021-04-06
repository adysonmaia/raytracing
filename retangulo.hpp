/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __RETANGULO_HPP__
#define __RETANGULO_HPP__

#include "triangulo.hpp"

class Retangulo : public Objeto {
public:
  Retangulo(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Vetor3& v4, const Material& mat);
  Retangulo(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Vetor3& v4);
  
  Vetor3 operator[] ( size_t i ) const;
  Vetor3& operator[] ( size_t i );
  
  bool intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal);
  void mudancaBase(const Matriz4& matriz);
  Objeto* mudancaBaseCP(const Matriz4& matriz);
private:
  Vetor3 vertice[4];
};

#endif

