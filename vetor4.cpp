/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "vetor4.hpp"

const Vetor4 Vetor4::ZERO( 0, 0, 0, 0 );
const Vetor4 Vetor4::UNIT_SCALE(1, 1, 1, 1);


Real Vetor4::operator [] ( size_t i ) const {
  //assert( i < 4 && i >= 0);
  switch (i) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    case 3:
      return w;
    default:
      assert(0);
  }
}

Real& Vetor4::operator[] ( size_t i ) {
  switch (i) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    case 3:
      return w;
    default:
      assert(0);
  }
}

Vetor4& Vetor4::operator= (const Vetor4& vetor) {
  x = vetor.x;  y = vetor.y;  z = vetor.z; w = vetor.w;
  return *this;
}

Vetor4& Vetor4::operator= (const Real escalar) {
  x = y = z = w = escalar;
  return *this;
}

bool Vetor4::operator== ( const Vetor4& vetor ) const {
  return (x == vetor.x && y == vetor.y && z == vetor.z && w == vetor.w);
}

Vetor4 Vetor4::operator- () const {
  return Vetor4(-x,-y,-z, -w);
}

 Vetor4& Vetor4::operator+= (const Vetor4 vetor) {
  x += vetor.x;  y += vetor.y;  z += vetor.z; w += vetor.w;
  return *this;
 }

 Vetor4& Vetor4::operator-= (const Vetor4 vetor) {
  x -= vetor.x;  y -= vetor.y;  z -= vetor.z; w -= vetor.w;
  return *this;
 }

 Vetor4& Vetor4::operator*= (const Vetor4 vetor) {
  x *= vetor.x;  y *= vetor.y;  z *= vetor.z; w *= vetor.w;
  return *this;
 }

 Vetor4& Vetor4::operator/= (const Vetor4 vetor) {
  x /= vetor.x;  y /= vetor.y;  z /= vetor.z; w /= vetor.w;
  return *this;
 }

Vetor4& Vetor4::operator+= (const Real escalar) {
  x += escalar;  y += escalar;  z += escalar; w += escalar;
  return *this;
}

Vetor4& Vetor4::operator-= (const Real escalar) {
  x -= escalar;  y -= escalar;  z -= escalar; w -= escalar;
  return *this;
}

Vetor4& Vetor4::operator*= (const Real escalar) {
  x *= escalar;  y *= escalar;  z *= escalar; w *= escalar;
  return *this;
}

Vetor4& Vetor4::operator/= (const Real escalar) {
  assert( escalar != 0.0 );
  Real invEsc = 1.0/escalar;
  x *= invEsc;  y *= invEsc;  z *= invEsc; w *= invEsc;
  return *this;
}

Real Vetor4::dimensao() const {
  return sqrt(x*x + y*y + z*z + w*w);
}

Real Vetor4::dimensao2() const {
  return x*x + y*y + z*z + w*w;
}

Real Vetor4::distancia(const Vetor4& vetor) const {
  return (*this - vetor).dimensao();
}

Real Vetor4::distancia2(const Vetor4& vetor) const {
  return (*this - vetor).dimensao2();
}

Real Vetor4::escalar(const Vetor4& vetor) const {
  return x*vetor.x + y*vetor.y + z*vetor.z + w*vetor.w;
}

Real Vetor4::normalizar(Real tolerancia ) {
  Real dim = sqrt( x * x + y * y + z * z + w * w);
  if ( dim > tolerancia) {
    Real invDim = 1.0 / dim;
    x *= invDim;    y *= invDim;    z *= invDim;    w *= invDim;
  }
  return dim;
}

Vetor4 Vetor4::normalizarCP(Real tolerancia) const {
  Vetor4 n=*this;
  n.normalizar(tolerancia);
  return n;
}





















