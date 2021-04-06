/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __Matrix4_HPP__
#define __Matrix4_HPP__

#include "matriz3.hpp"
#include "vetor4.hpp"
#include "vetor3.hpp"

class Matriz4 {
public:
  Matriz4() {}
  Matriz4(const Real matriz[4][4] ) ;
  Matriz4(const Matriz4& matriz);
  Matriz4(Real m00, Real m01, Real m02, Real m03,
          Real m10, Real m11, Real m12, Real m13,
          Real m20, Real m21, Real m22, Real m23,
          Real m30, Real m31, Real m32, Real m33);
  
  Matriz4(const Matriz3& m3x3);
  Real* operator[] (size_t linha) const;
  Matriz4& operator= (const Matriz4& matriz);
  bool operator== (const Matriz4& matriz) const;
  inline bool operator!= (const Matriz4& matriz) const {return !operator==(matriz);}
  
  Vetor4 getColuna(size_t coluna) const;
  Vetor4 getLinha(size_t linha) const;
  
  Matriz4& operator+= (const Matriz4& matriz);
  Matriz4& operator-= (const Matriz4& matriz);
  Matriz4& operator*= (const Matriz4& matriz);
  Matriz4 operator- () const;
  
  inline Matriz4 operator+ (const Matriz4& matriz) const { Matriz4 r = *this;  return r+=matriz;  }
  inline Matriz4 operator- (const Matriz4& matriz) const { Matriz4 r = *this;  return r-=matriz;  }
  inline Matriz4 operator* (const Matriz4& matriz) const { Matriz4 r = *this;  return r*=matriz;  }
  
  Matriz4& operator*= (Real escalar);
  inline Matriz4 operator* (Real escalar) const { Matriz4 r = *this; return r*=escalar; }
  friend Matriz4 operator* (Real escalar, const Matriz4& matriz);
  
  //[4x4 * 4x1 = 4x1]
  Vetor4 operator* (const Vetor4& vetor) const;
  //[1x4 * 4x4 = 1x4]
  friend Vetor4 operator* (const Vetor4& vetor, const Matriz4& matriz);
  
  Vetor3 operator * ( const Vetor3 &v ) const;
  
  Matriz4 Transposta () const;
  Real Determinante () const;
  bool Inversa (Matriz4& inversa, Real tolerancia = 1e-07) const;
  Matriz4 Inversa(Real tolerancia = 1e-07) const;
  
  bool ehAfim(void) const;
  
  //Transformacoes de translacao
  void setTrans( const Vetor3& v );
  Vetor3 getTrans() const;
  
  void makeTrans( const Vetor3& v );
  void makeTrans( Real tx, Real ty, Real tz );
  
  static Matriz4 getTrans( const Vetor3& v );
  static Matriz4 getTrans( Real tx, Real ty, Real tz );
  
  //Menor Complementar
  //lx = linha x, cx = coluna x
  Real menorComp(const size_t l0, const size_t l1, const size_t l2, 
                 const size_t c0, const size_t c1, const size_t c2) const;
  //outra forma de chamar o menor complementar
  Real menorComp(size_t linha, size_t coluna) const;
  
  static const Matriz4 ZERO;
  static const Matriz4 IDENTIDADE;
private:
  Real m[4][4];
};

inline Matriz4 operator* (Real escalar, const Matriz4& matriz) {return matriz*escalar;}
Vetor4  operator* (const Vetor4& vetor, const Matriz4& matriz);

#endif

