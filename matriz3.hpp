/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __Matrix3_HPP__
#define __Matrix3_HPP__

#include "vetor3.hpp"

class Matriz3 {
public:
  Matriz3() {}
  Matriz3(const Real matriz[3][3] ) ;
  Matriz3(const Matriz3& matriz);
  Matriz3(Real ent00, Real ent01, Real ent02,
          Real ent10, Real ent11, Real ent12,
          Real ent20, Real ent21, Real ent22);
  
  Real* operator[] (size_t linha) const;
  Matriz3& operator= (const Matriz3& matriz);
  bool operator== (const Matriz3& matriz) const;
  inline bool operator!= (const Matriz3& matriz) const {return !operator==(matriz);}
  
  Vetor3 getColuna(size_t coluna) const;
  Vetor3 getLinha(size_t linha) const;
  
  Matriz3& operator+= (const Matriz3& matriz);
  Matriz3& operator-= (const Matriz3& matriz);
  Matriz3& operator*= (const Matriz3& matriz);
  Matriz3 operator- () const;
  
  inline Matriz3 operator+ (const Matriz3& matriz) const { Matriz3 r = *this;  return r+=matriz;  }
  inline Matriz3 operator- (const Matriz3& matriz) const { Matriz3 r = *this;  return r-=matriz;  }
  inline Matriz3 operator* (const Matriz3& matriz) const { Matriz3 r = *this;  return r*=matriz;  }
  
  Matriz3& operator*= (Real escalar);
  inline Matriz3 operator* (Real escalar) const { Matriz3 r = *this; return r*=escalar; }
  friend Matriz3 operator* (Real escalar, const Matriz3& matriz);
  
  //[3x3 * 3x1 = 3x1]
  Vetor3 operator* (const Vetor3& vetor) const;
  //[1x3 * 3x3 = 1x3]
  friend Vetor3 operator* (const Vetor3& vetor, const Matriz3& matriz);
  
  Matriz3 Transposta () const;
  Real Determinante () const;
  bool Inversa (Matriz3& inversa, Real tolerancia = 1e-07) const;
  Matriz3 Inversa(Real tolerancia = 1e-07) const;
  
  static const Matriz3 ZERO;
  static const Matriz3 IDENTIDADE;
private:
  Real m[3][3];
};

inline Matriz3 operator* (Real escalar, const Matriz3& matriz) {return matriz*escalar;}
Vetor3  operator* (const Vetor3& vetor, const Matriz3& matriz);

#endif

