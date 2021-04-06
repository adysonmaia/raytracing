/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __Vetor4_HPP__
#define __Vetor4_HPP__

#include "prerequisitos.hpp"

class Vetor4 {
public:
  Vetor4() {}
  inline Vetor4(const Vetor4& vetor) : x(vetor.x), y(vetor.y), z(vetor.z), w(vetor.w) {}
  inline Vetor4(Real ent0, Real ent1, Real ent2, Real ent3) : x(ent0), y(ent1), z(ent2), w(ent3) {}
  inline Vetor4(const Real vetor[4] ) : x(vetor[0]), y(vetor[1]), z(vetor[2]), w(vetor[3]) {}
  inline Vetor4(const Real escalar) : x(escalar), y(escalar), z(escalar), w(escalar) {}
  
  Real operator[] ( size_t i ) const;
  Real& operator[] ( size_t i );
  
  Vetor4& operator= (const Vetor4& vetor);
  Vetor4& operator= (const Real escalar);
  
  bool operator== ( const Vetor4& vetor ) const;
  inline bool operator!= ( const Vetor4& vetor ) const {return !operator==(vetor);}
  
  Vetor4  operator- () const;
  Vetor4& operator+= (const Vetor4 vetor);
  Vetor4& operator-= (const Vetor4 vetor);
  Vetor4& operator*= (const Vetor4 vetor);
  Vetor4& operator/= (const Vetor4 vetor);
  
  inline Vetor4 operator+ (const Vetor4 vetor) const {Vetor4 r=*this; return r+=vetor;}
  inline Vetor4 operator- (const Vetor4 vetor) const {Vetor4 r=*this; return r-=vetor;}
  inline Vetor4 operator* (const Vetor4 vetor) const {Vetor4 r=*this; return r*=vetor;}
  inline Vetor4 operator/ (const Vetor4 vetor) const {Vetor4 r=*this; return r/=vetor;}
  
  Vetor4& operator+= (const Real escalar);
  Vetor4& operator-= (const Real escalar);
  Vetor4& operator*= (const Real escalar);
  Vetor4& operator/= (const Real escalar);
  
  inline Vetor4 operator+ (const Real escalar) const {Vetor4 r=*this; return r+=escalar;}
  inline Vetor4 operator- (const Real escalar) const {Vetor4 r=*this; return r-=escalar;}
  inline Vetor4 operator* (const Real escalar) const {Vetor4 r=*this; return r*=escalar;}
  inline Vetor4 operator/ (const Real escalar) const {Vetor4 r=*this; return r/=escalar;}
  
  friend Vetor4 operator+ (const Real escalar, const Vetor4& vetor);
  friend Vetor4 operator- (const Real escalar, const Vetor4& vetor);
  friend Vetor4 operator* (const Real escalar, const Vetor4& vetor);
  friend Vetor4 operator/ (const Real escalar, const Vetor4& vetor);
  
  Real dimensao() const;
  //dimensao ao quadrado
  Real dimensao2() const;
  Real distancia(const Vetor4& vetor) const;
  //distancia ao quadrado
  Real distancia2(const Vetor4& vetor) const;
  //produto escalar
  Real escalar(const Vetor4& vetor) const;
  //retorna a dimensao e normaliza o vetor
  Real normalizar(Real tolerancia = 1e-08);
  //retorna a copia do vetor normalizado
  Vetor4 normalizarCP(Real tolerancia = 1e-08) const;
  
  static const Vetor4 ZERO;
  static const Vetor4 UNIT_SCALE;
  
private:
  Real x, y, z, w;
};


inline Vetor4 operator+ (const Real escalar, const Vetor4& vetor)  {return vetor+escalar;}
inline Vetor4 operator- (const Real escalar, const Vetor4& vetor)  {return vetor-escalar;}
inline Vetor4 operator* (const Real escalar, const Vetor4& vetor)  {return vetor*escalar;}
inline Vetor4 operator/ (const Real escalar, const Vetor4& vetor)  {return vetor/escalar;}

  
#endif

