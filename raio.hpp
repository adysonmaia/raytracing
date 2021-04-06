/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __RAIO_HPP__
#define __RAIO_HPP__

#include "vetor3.hpp"

class Raio {
public:
  Raio() : pOrigem(Vetor3::ZERO), pDirecao(Vetor3::UNIT_Z) {}
  inline Raio(const Vetor3& origem, const Vetor3& direcao) : pOrigem(origem) 
  {
    pDirecao = direcao.normalizarCP();
  }
  
  Raio& operator= (const Raio& raio);
  
  void setOrigem(const Vetor3& origem) {pOrigem = origem;}
  const Vetor3& getOrigem(void) const {return pOrigem;} 
  
  void setDirecao(const Vetor3& direcao) {pDirecao = direcao.normalizarCP();}
  const Vetor3& getDirecao(void) const {return pDirecao;} 
  
  Vetor3 getPonto(Real t) const;
  Vetor3 operator*(Real t) const;
private:
  Vetor3 pOrigem;
  Vetor3 pDirecao;
};

#endif
