/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "plano.hpp"


Plano::Plano(const Plano& pl) {
  normal = pl.normal;
  d      = pl.d;
  material = pl.material; 
  
}

Plano::Plano(const Vetor3& vNormal, Real constante, const Material& m) {
  normal = vNormal.normalizarCP();
  d      = -constante;
  material = m;
}

 Plano::Plano (const Vetor3& vNormal, const Vetor3& ponto, const Material& m) {
  redefina(vNormal,ponto);
  material = m;
 }
 
 Plano::Plano (const Vetor3& ponto0, const Vetor3& ponto1, const Vetor3& ponto2, const Material& m) {
  redefina(ponto0,ponto1,ponto2);
  material = m;
 }
 
 void Plano::redefina(const Vetor3& ponto0, const Vetor3& ponto1, const Vetor3& ponto2) {
  Vetor3 vetor1 = ponto1 - ponto0;
  Vetor3 vetor2 = ponto2 - ponto0;
  normal = vetor1.vetorial(vetor2);
  normal.normalizar();
  d = - normal.escalar(ponto0);
 }
 
 void Plano::redefina(const Vetor3& vNormal, const Vetor3& ponto) {
  normal = vNormal.normalizarCP();
  d      = -normal.escalar(ponto);
 }
 
 Real Plano::getDistancia(const Vetor3& ponto) const {
  return normal.escalar(ponto) + d;
 }
 
 void Plano::mudancaBase(const Matriz4& matriz) {
  normal = matriz*normal;
  normal.normalizar();
 }
 
 Objeto* Plano::mudancaBaseCP(const Matriz4& matriz){
  Plano *pl;
  pl = new Plano(*this);
  pl->mudancaBase(matriz);
  return pl;
 }
 
 bool Plano::intersecao(const Raio& ray, Real& t, Vetor3& vNormal, int& sentidoNormal) {
  Real denom = normal.escalar(ray.getDirecao() );
  if(abs(denom) <= 0.00001 ){
    return false;
  }else{
    Real nom = normal.escalar(ray.getOrigem()) + d;
    t = -(float) (nom/denom);
    
    if( denom >= 0 ){
      vNormal = -normal;
      sentidoNormal = 1;
    }else{
      vNormal = normal;
      sentidoNormal = 0;
    }
  
  }
  
  return t >= 0.00008;
  
 }

