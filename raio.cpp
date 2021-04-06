/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "raio.hpp"

Vetor3 Raio::getPonto(Real t) const {
  return Vetor3(pOrigem + (pDirecao * t));
}

Vetor3 Raio::operator*(Real t) const {
  return getPonto(t);
}

Raio& Raio::operator= (const Raio& raio) {
  pOrigem = raio.pOrigem;
  pDirecao = raio.pDirecao.normalizarCP();
  return *this;
}

