/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "triangulo.hpp"

Triangulo::Triangulo(const Vetor3& v0, const Vetor3& v1, const Vetor3& v2,const Material& mat ):Objeto(mat) {
  vertice[0] = v0;
  vertice[1] = v1;
  vertice[2] = v2;
}

Triangulo::Triangulo(const Vetor3& v0, const Vetor3& v1, const Vetor3& v2) {
  vertice[0] = v0;
  vertice[1] = v1;
  vertice[2] = v2;
}

Vetor3 Triangulo::operator[] ( size_t i ) const {
  assert(i >= 0 && i < 3);
  return vertice[i];
}

Vetor3& Triangulo::operator[] ( size_t i ) {
  assert(i >= 0 && i < 3);
  return vertice[i];
}

void Triangulo::mudancaBase(const Matriz4& matriz) {
  vertice[0] = matriz*vertice[0];
  vertice[1] = matriz*vertice[1];
  vertice[2] = matriz*vertice[2];
}

Objeto* Triangulo::mudancaBaseCP(const Matriz4& matriz) {
  Triangulo *t;
  t = new Triangulo(matriz*vertice[0],matriz*vertice[1],matriz*vertice[2],material);
  return t;
}

bool Triangulo::intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal) {
  Plano plano;
  plano.redefina(vertice[0],vertice[1],vertice[2]);
  
  if(!plano.intersecao(ray,t,normal,sentidoNormal)  ){
    return false;
  }
  
  int sentido = 0;
  Vetor3 ponto = ray*t;
  
  Vetor3 v1 = vertice[1] - vertice[0];
  Vetor3 v2 = vertice[2] - vertice[1];
  Vetor3 v3 = vertice[0] - vertice[2];
  Vetor3 p1 = ponto - vertice[0];
  Vetor3 p2 = ponto - vertice[1];
  Vetor3 p3 = ponto - vertice[2];
  Vetor3 e1 = p1.vetorial(v1);
  Vetor3 e2 = p2.vetorial(v2);
  Vetor3 e3 = p3.vetorial(v3);
  
  if(e1.escalar(e2) < 0   )
    sentido--;
  else
    sentido++;
  if(e2.escalar(e3) < 0   )
    sentido--;
  else
    sentido++;
  if(e3.escalar(e1) < 0   )
    sentido--;
  else
    sentido++;
    

  if(sentido == 3 || sentido == -3){
    return true;
  }
  else
    return false;

}


