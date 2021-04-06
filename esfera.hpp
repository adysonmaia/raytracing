/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __ESFERA_HPP__
#define __ESFERA_HPP__

#include "objeto.hpp"

class Esfera : public Objeto {
public:
  Esfera(const Vetor3& vcentro, Real vraio, const Material& mat ) : Objeto(mat), centro(vcentro), raio(vraio) {}
   
  inline Vetor3 getCentro() const {return centro;}
  inline void setCentro(const Vetor3& vcentro) {centro = vcentro;}
  inline Real getRaio() const {return raio;}
  inline void setRaio(Real vraio) {raio=vraio;}
   
  bool intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal);
  void mudancaBase(const Matriz4& matriz);
  Objeto* mudancaBaseCP(const Matriz4& matriz);
  
private:
  Vetor3 centro;
  Real raio;
};

#endif
