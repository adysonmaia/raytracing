/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __CONE_HPP__
#define __CONE_HPP__

#include "objeto.hpp"

class Cone: public Objeto{
public:
  Cone(const Vetor3& c1, const Vetor3& c2, Real vraio, const Material& mat);
  Cone(const Cone& cpy);
  
  inline Real getRaio() const {return raio;}
  inline void setRaio(Real vraio) {raio = vraio;}
  
  inline Real getAltura() const {return altura;}
  inline void setAltura(Real h) {altura = h;}
  
  bool intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal);
  void mudancaBase(const Matriz4& matriz);
  Objeto* mudancaBaseCP(const Matriz4& matriz);
private:
  Real raio, altura;
  Vetor3 origem, direcao, apice;
  Vetor3 i,j,k;
};

#endif

