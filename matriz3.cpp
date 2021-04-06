/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "matriz3.hpp"

const Matriz3 Matriz3::ZERO(0,0,0,0,0,0,0,0,0);
const Matriz3 Matriz3::IDENTIDADE(1,0,0,0,1,0,0,0,1);

Matriz3::Matriz3(const Real matriz[3][3]) {
  memcpy(m,matriz,9*sizeof(Real));
}

Matriz3::Matriz3(const Matriz3& matriz) {
  memcpy(m,matriz.m, 9*sizeof(Real) );
}

Matriz3::Matriz3(Real ent00, Real ent01, Real ent02,
          Real ent10, Real ent11, Real ent12,
          Real ent20, Real ent21, Real ent22) 
{
  m[0][0] = ent00;    m[0][1] = ent01;    m[0][2] = ent02;
  m[1][0] = ent10;    m[1][1] = ent11;    m[1][2] = ent12;
  m[2][0] = ent20;    m[2][1] = ent21;    m[2][2] = ent22;
}

Real* Matriz3::operator[] (size_t linha) const  {
  return (Real*)m[linha]; 
}

Matriz3& Matriz3::operator= (const Matriz3& matriz)
{
  memcpy(m,matriz.m,9*sizeof(Real));
  return *this;
}

bool Matriz3::operator== (const Matriz3& matriz) const {
  for(size_t i =0; i < 3; i++)
    for(size_t j =0; j < 3; j++)
      if(m[i][j] != matriz.m[i][j])
        return false;
  return true;
}

Vetor3 Matriz3::getColuna(size_t coluna) const {
  assert( 0 <= coluna && coluna < 3 );
  return Vetor3(m[0][coluna],m[1][coluna], m[2][coluna]);
}

Vetor3 Matriz3::getLinha(size_t linha) const {
  assert( 0 <= linha && linha < 3 );
  return Vetor3(m[linha][0],m[linha][1], m[linha][2]);
}

Matriz3& Matriz3::operator+= (const Matriz3& matriz) {
  for(size_t i=0; i < 3; i++)
    for(size_t j=0; j < 3; j++)
      m[i][j] += matriz.m[i][j];
  return *this;
}

Matriz3& Matriz3::operator-= (const Matriz3& matriz) {
  for(size_t i=0; i < 3; i++)
    for(size_t j=0; j < 3; j++)
      m[i][j] -= matriz.m[i][j];
  return *this;
}

Matriz3& Matriz3::operator*= (const Matriz3& matriz) {
  for(size_t i=0; i < 3; i++)
    for(size_t j=0; j < 3; j++) {
      m[i][j] =  m[i][0]*matriz.m[0][j] +
                 m[i][1]*matriz.m[1][j] +
                 m[i][2]*matriz.m[2][j];
    }
  return *this;
}

Matriz3 Matriz3::operator- () const {
  Matriz3 r;
  for(size_t i=0; i < 3; i++)
    for(size_t j=0; j < 3; j++)
      r.m[i][j] = -m[i][j];
  return r;
}

Matriz3& Matriz3::operator*= (Real escalar) {
  for(size_t i=0; i < 3; i++)
    for(size_t j=0; j < 3; j++)
      m[i][j] *= escalar;
  return *this;
}

Vetor3 Matriz3::operator* (const Vetor3& vetor) const {
  Vetor3 r;
  for(size_t i=0; i < 3; i ++){
    r[i] = m[i][0]*vetor[0] +
           m[i][1]*vetor[1] +
           m[i][2]*vetor[2];
  }
  return r;
}

Vetor3 operator* (const Vetor3& vetor, const Matriz3& matriz) {
  Vetor3 r;
  for(size_t j=0; j < 3; j++) {
    r[j] = vetor[0]*matriz.m[0][j] +
           vetor[1]*matriz.m[1][j] + 
           vetor[2]*matriz.m[2][j];
  }
  return r;
}

Matriz3 Matriz3::Transposta () const {
  Matriz3 t;
  for(size_t i=0; i < 3; i++)
    for(size_t j=0; j < 3; j++)
      t.m[j][i] = m[i][j];
  return t;
}

Real Matriz3::Determinante () const {
  Real det;
  det =  m[0][0]*m[1][1]*m[2][2] + m[1][0]*m[2][1]*m[0][2] + m[2][0]*m[0][1]*m[1][2];
  det -= m[0][2]*m[1][1]*m[2][0] + m[1][2]*m[2][1]*m[0][0] + m[2][2]*m[0][1]*m[1][0];
  return det;
}

bool Matriz3::Inversa (Matriz3& inversa, Real tolerancia) const
{
  // Inverte a matriz 3x3 usando cofatores

  inversa[0][0] = m[1][1]*m[2][2] -
                  m[1][2]*m[2][1];
  
  inversa[0][1] = m[0][2]*m[2][1] -
                  m[0][1]*m[2][2];
  
  inversa[0][2] = m[0][1]*m[1][2] -
                  m[0][2]*m[1][1];
  
  inversa[1][0] = m[1][2]*m[2][0] -
                  m[1][0]*m[2][2];
  
  inversa[1][1] = m[0][0]*m[2][2] -
                  m[0][2]*m[2][0];
  
  inversa[1][2] = m[0][2]*m[1][0] -
                  m[0][0]*m[1][2];
  
  inversa[2][0] = m[1][0]*m[2][1] -
                  m[1][1]*m[2][0];
  
  inversa[2][1] = m[0][1]*m[2][0] -
                  m[0][0]*m[2][1];
  
  inversa[2][2] = m[0][0]*m[1][1] -
                  m[0][1]*m[1][0];

  Real det =  m[0][0]*inversa[0][0] +
              m[0][1]*inversa[1][0]+
              m[0][2]*inversa[2][0];

  if ( abs(det) <= tolerancia )
    return false;

  Real invDet = 1.0/det;
  for (size_t i = 0; i < 3; i++)
    for (size_t j = 0; j < 3; j++)
      inversa[i][j] *= invDet;


  return true;
 }

Matriz3 Matriz3::Inversa (Real tolerancia) const
{
  Matriz3 inversa;
  if(!Inversa(inversa,tolerancia) )
    inversa = Matriz3::ZERO;
  return inversa;
}
