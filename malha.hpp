/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __MALHA_TRIANGULO_HPP__
#define __MALHA_TRIANGULO_HPP__

#include "retangulo.hpp"

class Malha : public Objeto {
public:
  typedef vector<Objeto*> ListaFace;
  
  Malha() {}
  Malha( const Malha& cpy );
 
  void addFace(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Material& mat);
  void addFace(const Triangulo& triangulo);
  void addFace(const Vetor3& v1, const Vetor3& v2, const Vetor3& v3, const Vetor3& v4 ,const Material& mat);
  void addFace(const Retangulo& retangulo);
  
  void deleteFace(size_t indice);
  Objeto* getFace(size_t indice);
  size_t qtdFace(void) const;
  void reset(void);
  
  bool intersecao(const Raio& raio, Real& t, Vetor3& normal, int& sentidoNormal);
  void mudancaBase(const Matriz4& matriz);
  Objeto* mudancaBaseCP(const Matriz4& matriz);

private:
  ListaFace listFace;
};

#endif

