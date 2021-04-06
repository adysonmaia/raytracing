/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __Vetor3_HPP__
#define __Vetor3_HPP__

#include "prerequisitos.hpp"

class Vetor3 {
public:
  Vetor3() {}
  inline Vetor3(const Vetor3& vetor) : x(vetor.x), y(vetor.y), z(vetor.z) {}
  inline Vetor3(Real ent0, Real ent1, Real ent2) : x(ent0), y(ent1), z(ent2) {}
  inline Vetor3(const Real vetor[3] ) : x(vetor[0]), y(vetor[1]), z(vetor[2]) {}
  inline Vetor3(const Real escalar) : x(escalar), y(escalar), z(escalar) {}
  
  Real operator[] ( size_t i ) const;
  Real& operator[] ( size_t i );
  
  Vetor3& operator= (const Vetor3& vetor);
  Vetor3& operator= (const Real escalar);
  
  bool operator== ( const Vetor3& vetor ) const;
  inline bool operator!= ( const Vetor3& vetor ) const {return !operator==(vetor);}
  
  Vetor3 operator- () const;
  Vetor3& operator+= (const Vetor3 vetor);
  Vetor3& operator-= (const Vetor3 vetor);
  Vetor3& operator*= (const Vetor3 vetor);
  Vetor3& operator/= (const Vetor3 vetor);
  
  inline Vetor3 operator+ (const Vetor3 vetor) const {Vetor3 r=*this; return r+=vetor;}
  inline Vetor3 operator- (const Vetor3 vetor) const {Vetor3 r=*this; return r-=vetor;}
  inline Vetor3 operator* (const Vetor3 vetor) const {Vetor3 r=*this; return r*=vetor;}
  inline Vetor3 operator/ (const Vetor3 vetor) const {Vetor3 r=*this; return r/=vetor;}
  
  Vetor3& operator+= (const Real escalar);
  Vetor3& operator-= (const Real escalar);
  Vetor3& operator*= (const Real escalar);
  Vetor3& operator/= (const Real escalar);
  
  inline Vetor3 operator+ (const Real escalar) const {Vetor3 r=*this; return r+=escalar;}
  inline Vetor3 operator- (const Real escalar) const {Vetor3 r=*this; return r-=escalar;}
  inline Vetor3 operator* (const Real escalar) const {Vetor3 r=*this; return r*=escalar;}
  inline Vetor3 operator/ (const Real escalar) const {Vetor3 r=*this; return r/=escalar;}
  
  friend Vetor3 operator+ (const Real escalar, const Vetor3& vetor);
  friend Vetor3 operator- (const Real escalar, const Vetor3& vetor);
  friend Vetor3 operator* (const Real escalar, const Vetor3& vetor);
  friend Vetor3 operator/ (const Real escalar, const Vetor3& vetor);
  
  Real dimensao() const;
  //dimensao ao quadrado
  Real dimensao2() const;
  Real distancia(const Vetor3& vetor) const;
  //distancia ao quadrado
  Real distancia2(const Vetor3& vetor) const;
  //produto escalar
  Real escalar(const Vetor3& vetor) const;
  //retorna a dimensao e normaliza o vetor
  Real normalizar(Real tolerancia = 1e-06);
  //retorna a copia do vetor normalizado
  Vetor3 normalizarCP(Real tolerancia = 1e-06) const;
  //produto vetorial
  Vetor3 vetorial(const Vetor3& vetor) const;

  
  static const Vetor3 ZERO;
  static const Vetor3 UNIT_X;
  static const Vetor3 UNIT_Y;
  static const Vetor3 UNIT_Z;
  static const Vetor3 NEGATIVO_UNIT_X;
  static const Vetor3 NEGATIVO_UNIT_Y;
  static const Vetor3 NEGATIVO_UNIT_Z;
  static const Vetor3 UNIT_SCALE;
  
private:
  Real x, y, z;
};


inline Vetor3 operator+ (const Real escalar, const Vetor3& vetor)  {return vetor+escalar;}
inline Vetor3 operator- (const Real escalar, const Vetor3& vetor)  {return vetor-escalar;}
inline Vetor3 operator* (const Real escalar, const Vetor3& vetor)  {return vetor*escalar;}
inline Vetor3 operator/ (const Real escalar, const Vetor3& vetor)  {return vetor/escalar;}

  
#endif

