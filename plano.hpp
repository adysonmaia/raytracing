/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __PLANO_HPP__
#define __PLANO_HPP__

#include "objeto.hpp"

class Plano : public Objeto {
public:
  Plano() : normal(Vetor3::ZERO), d(0.0) {}
  Plano(const Material& m) : Objeto(m), normal(Vetor3::ZERO), d(0.0){}
  Plano(const Plano& pl);
  Plano(const Vetor3& vNormal, Real constante, const Material& m);
  Plano (const Vetor3& vNormal, const Vetor3& ponto, const Material& m);
  Plano (const Vetor3& ponto0, const Vetor3& ponto1, const Vetor3& ponto2, const Material& m);
  
  void redefina(const Vetor3& ponto0, const Vetor3& ponto1, const Vetor3& ponto2);
  void redefina(const Vetor3& vNormal, const Vetor3& ponto);
  
  bool intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal);
  void mudancaBase(const Matriz4& matriz);
  Objeto* mudancaBaseCP(const Matriz4& matriz);
  
  Real getDistancia(const Vetor3& ponto) const;
private:
  Vetor3 normal;
  Real d;

};

#endif

