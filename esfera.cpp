/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "esfera.hpp"

bool Esfera::intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal) {
  Real tolerancia = 0.001;
  //normaliza direcao do raio
  Vetor3 direcao = ray.getDirecao();
  //quadrado da distancia entre o centro da esfera e a origem do raio
  Vetor3 origem = centro - ray.getOrigem();
  Real d2OC = origem.dimensao2();
  Real b = direcao.escalar(origem);

 
  // se d2OC >= r*r, testar se b eh negativo, em caso afirmativo, abandonar os calculos da intersecao 
  // ( o raio aponta no sentido contrario ao da localizacao da esfera relativamente a origem do raio)
  Real dif = abs(d2OC - raio*raio);
  

  
  //if( (d2OC >= raio*raio )  && b <= 0 ){
  if( (d2OC - raio*raio >= -0.003)  && b <= 0 ){
    return false;
  }
  
  
  //calculo delta
  Real r = b*b -d2OC + raio*raio;
  
  if(r < 0) {
    return false;
  }

  sentidoNormal = 0;
  Real fator;
  if( d2OC - raio*raio > 0.0022){
    t = b - sqrt(r);
    fator = 1.0;

  //origem do raio dentro da esfera, d2OC <= raio*raio
  }else{
    t = b + sqrt(r);
    fator = -1.0; //normal invertida
    sentidoNormal = 1;
  }

  Vetor3 ponto = ray.getPonto(t);
  normal = fator*(ponto - centro).normalizarCP();

  return true;
}


void Esfera::mudancaBase(const Matriz4& matriz) {
  centro =  matriz*centro;
}

Objeto* Esfera::mudancaBaseCP(const Matriz4& matriz) {
  Objeto *obj;
  obj = new Esfera(matriz*centro,raio,material);
  return obj;
}

