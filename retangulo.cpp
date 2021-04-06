/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "retangulo.hpp"

Retangulo::Retangulo(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Vetor3& v4, const Material& mat) 
          : Objeto(mat)
{
  vertice[0] = v1;
  vertice[1] = v2;
  vertice[2] = v3;
  vertice[3] = v4;
}

Retangulo::Retangulo(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Vetor3& v4) {
  vertice[0] = v1;
  vertice[1] = v2;
  vertice[2] = v3;
  vertice[3] = v4;
}

Vetor3 Retangulo::operator[] ( size_t i ) const {
  assert(i >= 0 && i < 4);
  return vertice[i];
}

Vetor3& Retangulo::operator[] ( size_t i ) {
  assert(i >= 0 && i < 4);
  return vertice[i];
}

void Retangulo::mudancaBase(const Matriz4& matriz) {
  vertice[0] = matriz*vertice[0];
  vertice[1] = matriz*vertice[1];
  vertice[2] = matriz*vertice[2];
  vertice[3] = matriz*vertice[3];
}

Objeto* Retangulo::mudancaBaseCP(const Matriz4& matriz) {
  Retangulo *r;
  r = new Retangulo(matriz*vertice[0],matriz*vertice[1],matriz*vertice[2],matriz*vertice[3] ,material);
  return r;
}

bool Retangulo::intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal) {
  Triangulo t1(vertice[0],vertice[1],vertice[2]);
  Triangulo t2(vertice[2],vertice[3],vertice[0]);

  if(t1.intersecao(ray,t,normal,sentidoNormal)  ){
   return true;
  }else if(t2.intersecao(ray,t,normal,sentidoNormal) ){
    return true;
  }else{
    return false;
  }
}



