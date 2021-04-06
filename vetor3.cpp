/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "vetor3.hpp"

const Vetor3 Vetor3::ZERO( 0, 0, 0 );
const Vetor3 Vetor3::UNIT_X( 1, 0, 0 );
const Vetor3 Vetor3::UNIT_Y( 0, 1, 0 );
const Vetor3 Vetor3::UNIT_Z( 0, 0, 1 );
const Vetor3 Vetor3::NEGATIVO_UNIT_X( -1,  0,  0 );
const Vetor3 Vetor3::NEGATIVO_UNIT_Y(  0, -1,  0 );
const Vetor3 Vetor3::NEGATIVO_UNIT_Z(  0,  0, -1 );
const Vetor3 Vetor3::UNIT_SCALE(1, 1, 1);


Real Vetor3::operator [] ( size_t i ) const {
  //assert( i < 3 && i >= 0);
  switch (i) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    default:
      assert(0);
  }
}

Real& Vetor3::operator[] ( size_t i ) {
  switch (i) {
    case 0:
      return x;
    case 1:
      return y;
    case 2:
      return z;
    default:
      assert(0);
  }
}

Vetor3& Vetor3::operator= (const Vetor3& vetor) {
  x = vetor.x;  y = vetor.y;  z = vetor.z;
  return *this;
}

Vetor3& Vetor3::operator= (const Real escalar) {
  x = y = z = escalar;
  return *this;
}

bool Vetor3::operator== ( const Vetor3& vetor ) const {
  return (x == vetor.x && y == vetor.y && z == vetor.z);
}

Vetor3 Vetor3::operator- () const {
  return Vetor3(-x,-y,-z);
}

 Vetor3& Vetor3::operator+= (const Vetor3 vetor) {
  x += vetor.x;  y += vetor.y;  z += vetor.z;
  return *this;
 }

 Vetor3& Vetor3::operator-= (const Vetor3 vetor) {
  x -= vetor.x;  y -= vetor.y;  z -= vetor.z;
  return *this;
 }

 Vetor3& Vetor3::operator*= (const Vetor3 vetor) {
  x *= vetor.x;  y *= vetor.y;  z *= vetor.z;
  return *this;
 }

 Vetor3& Vetor3::operator/= (const Vetor3 vetor) {
  x /= vetor.x;  y /= vetor.y;  z /= vetor.z;
  return *this;
 }

Vetor3& Vetor3::operator+= (const Real escalar) {
  x += escalar;  y += escalar;  z += escalar;
  return *this;
}

Vetor3& Vetor3::operator-= (const Real escalar) {
  x -= escalar;  y -= escalar;  z -= escalar;
  return *this;
}

Vetor3& Vetor3::operator*= (const Real escalar) {
  x *= escalar;  y *= escalar;  z *= escalar;
  return *this;
}

Vetor3& Vetor3::operator/= (const Real escalar) {
  assert( escalar != 0.0 );
  Real invEsc = 1.0/escalar;
  x *= invEsc;  y *= invEsc;  z *= invEsc;
  return *this;
}

Real Vetor3::dimensao() const {
  return sqrt(x*x + y*y + z*z);
}

Real Vetor3::dimensao2() const {
  return x*x + y*y + z*z;
}

Real Vetor3::distancia(const Vetor3& vetor) const {
  return (*this - vetor).dimensao();
}

Real Vetor3::distancia2(const Vetor3& vetor) const {
  return (*this - vetor).dimensao2();
}

Real Vetor3::escalar(const Vetor3& vetor) const {
  return x*vetor.x + y*vetor.y + z*vetor.z;
}

Real Vetor3::normalizar(Real tolerancia ) {
  Real dim = sqrt( x * x + y * y + z * z );
  if ( abs(dim) > tolerancia) {
    Real invDim = 1.0 / dim;
    x *= invDim;    y *= invDim;    z *= invDim;
  }else{
    x = y = z = 0.0;
  }

  return dim;
}

Vetor3 Vetor3::normalizarCP(Real tolerancia) const {
  Vetor3 n;
  n = *this;
  n.normalizar(tolerancia);
  return n;
}

Vetor3 Vetor3::vetorial(const Vetor3& vetor) const {
  return Vetor3( y * vetor.z - z * vetor.y,
                 z * vetor.x - x * vetor.z,
                 x * vetor.y - y * vetor.x);
}




















