/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "malha.hpp"

Malha::Malha( const Malha& cpy ) {
  listFace = cpy.listFace;
  material = cpy.material;
}

void Malha::addFace(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Material& mat) {
  Triangulo *tri;
  tri = new Triangulo (v1,v2,v3,mat);
  material = mat;
  listFace.push_back(tri);
}

void Malha::addFace(const Triangulo& tri) {
  Triangulo *triangulo = new Triangulo(tri);
  material = tri.getMaterial();
  listFace.push_back(triangulo);
}

void Malha::addFace(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Vetor3& v4, const Material& mat) {
  Retangulo *ret;
  ret = new Retangulo (v1,v2,v3,v4,mat);
  material = mat;
  listFace.push_back(ret);
}

void Malha::addFace(const Retangulo& ret) {
  Retangulo *retangulo = new Retangulo(ret);
  material = ret.getMaterial();
  listFace.push_back(retangulo);
}

void Malha::deleteFace(size_t indice) {
  assert(indice < qtdFace() && indice >= 0);
  ListaFace::iterator it = listFace.begin();
  
  std::advance(it, indice);
  listFace.erase(it);
}

Objeto* Malha::getFace(size_t indice){
  assert(indice < qtdFace() && indice >= 0);
  return listFace[indice];
}


size_t Malha::qtdFace(void) const {
  return listFace.size();
}

void Malha::reset(void) {
  listFace.clear();
}

void Malha::mudancaBase(const Matriz4& matriz) {
  for(size_t it=0; it < qtdFace() ; it++ ){
    listFace[it] = listFace[it]->mudancaBaseCP(matriz);
  }
}

Objeto* Malha::mudancaBaseCP(const Matriz4& matriz) {
    Malha *malha;
    malha = new Malha(*this);
    malha->mudancaBase(matriz);
    return malha;
}

bool Malha::intersecao(const Raio& raio, Real& t, Vetor3& normal, int& sentidoNormal) {
  Real tt, tmenor;
  int sn;
  Vetor3 n;
  size_t ii;
  
  tmenor = -1;
  tt = -1;
  Triangulo *tri;
  tri = (Triangulo*) listFace[0];
  Vetor3 v1 = tri->operator[](0);
  Vetor3 v2 = tri->operator[](1);
  Vetor3 v3 = tri->operator[](2);
  
  for(size_t i=0; i < qtdFace(); i++){
    if( listFace[i]->intersecao(raio,tt,n,sn)  ){
      if(tt < tmenor || tmenor == -1){
        t = tt;
        tmenor = tt;
        normal = n;
        sentidoNormal = sn;
        ii = i;
      }
    }
  }
  
  if(tmenor == -1){
    return false;
  }
  
  material = listFace[ii]->getMaterial();
  return true;

}



