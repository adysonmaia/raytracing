/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "matriz4.hpp"

const Matriz4 Matriz4::ZERO(0,0,0,0,
                            0,0,0,0,
                            0,0,0,0,
                            0,0,0,0);
const Matriz4 Matriz4::IDENTIDADE(1,0,0,0,
                                  0,1,0,0,
                                  0,0,1,0,
                                  0,0,0,1); 

Matriz4::Matriz4(const Real matriz[4][4]) {
  memcpy(m,matriz,16*sizeof(Real));
}

Matriz4::Matriz4(const Matriz4& matriz) {
  memcpy(m,matriz.m, 16*sizeof(Real) );
}

Matriz4::Matriz4(Real m00, Real m01, Real m02, Real m03,
                 Real m10, Real m11, Real m12, Real m13,
                 Real m20, Real m21, Real m22, Real m23,
                 Real m30, Real m31, Real m32, Real m33) 
{
  m[0][0] = m00;    m[0][1] = m01;    m[0][2] = m02;    m[0][3] = m03;
  m[1][0] = m10;    m[1][1] = m11;    m[1][2] = m12;    m[1][3] = m13;
  m[2][0] = m20;    m[2][1] = m21;    m[2][2] = m22;    m[2][3] = m23;
  m[3][0] = m30;    m[3][1] = m31;    m[3][2] = m32;    m[3][3] = m33;
}

Matriz4::Matriz4(const Matriz3& m3x3) {
  operator=(IDENTIDADE);
  operator=(m3x3);
}

Real* Matriz4::operator[] (size_t linha) const  {
  assert( linha < 4 && linha >= 0);
  return (Real*)m[linha]; 
}

Matriz4& Matriz4::operator= (const Matriz4& matriz)
{
  memcpy(m,matriz.m,16*sizeof(Real));
  return *this;
}

bool Matriz4::operator== (const Matriz4& matriz) const {
  for(size_t i =0; i < 4; i++)
    for(size_t j =0; j < 4; j++)
      if(m[i][j] != matriz.m[i][j])
        return false;
  return true;
}

Vetor4 Matriz4::getColuna(size_t coluna) const {
  assert( 0 <= coluna && coluna < 4 );
  return Vetor4(m[0][coluna],m[1][coluna], m[2][coluna], m[3][coluna]);
}

Vetor4 Matriz4::getLinha(size_t linha) const {
  assert( 0 <= linha && linha < 4 );
  return Vetor4(m[linha][0],m[linha][1], m[linha][2], m[linha][3]);
}

Matriz4& Matriz4::operator+= (const Matriz4& matriz) {
  for(size_t i=0; i < 4; i++)
    for(size_t j=0; j < 4; j++)
      m[i][j] += matriz.m[i][j];
  return *this;
}

Matriz4& Matriz4::operator-= (const Matriz4& matriz) {
  for(size_t i=0; i < 4; i++)
    for(size_t j=0; j < 4; j++)
      m[i][j] -= matriz.m[i][j];
  return *this;
}

Matriz4& Matriz4::operator*= (const Matriz4& matriz) {
  for(size_t i=0; i < 4; i++)
    for(size_t j=0; j < 4; j++) {
      m[i][j] =  m[i][0]*matriz.m[0][j] +
                 m[i][1]*matriz.m[1][j] +
                 m[i][2]*matriz.m[2][j] +
                 m[i][3]*matriz.m[3][j];
    }
  return *this;
}

Matriz4 Matriz4::operator- () const {
  Matriz4 r;
  for(size_t i=0; i < 4; i++)
    for(size_t j=0; j < 4; j++)
      r.m[i][j] = -m[i][j];
  return r;
}

Matriz4& Matriz4::operator*= (Real escalar) {
  for(size_t i=0; i < 4; i++)
    for(size_t j=0; j < 4; j++)
      m[i][j] *= escalar;
  return *this;
}

Vetor4 Matriz4::operator* (const Vetor4& vetor) const {
  Vetor4 r;
  for(size_t i=0; i < 4; i ++){
    r[i] = m[i][0]*vetor[0] +
           m[i][1]*vetor[1] +
           m[i][2]*vetor[2] +
           m[i][3]*vetor[3];
  }
  return r;
}

Vetor4 operator* (const Vetor4& vetor, const Matriz4& matriz) {
  Vetor4 r;
  for(size_t j=0; j < 4; j++) {
    r[j] = vetor[0]*matriz.m[0][j] +
           vetor[1]*matriz.m[1][j] + 
           vetor[2]*matriz.m[2][j] +
           vetor[3]*matriz.m[3][j];
  }
  return r;
}

Vetor3 Matriz4::operator * ( const Vetor3 &v ) const {
  Vetor3 r;

  Real invW = 1.0 / ( m[3][0] * v[0] + m[3][1] * v[1] + m[3][2] * v[2] + m[3][3] );
  
  r[0] = ( m[0][0] * v[0] + m[0][1] * v[1] + m[0][2] * v[2] + m[0][3] ) * invW;
  r[1] = ( m[1][0] * v[0] + m[1][1] * v[1] + m[1][2] * v[2] + m[1][3] ) * invW;
  r[2] = ( m[2][0] * v[0] + m[2][1] * v[1] + m[2][2] * v[2] + m[2][3] ) * invW;

  return r;
}

bool Matriz4::ehAfim(void) const {
  return m[3][0] == 0 && m[3][1] == 0 && m[3][2] == 0 && m[3][3] == 1;
}


Matriz4 Matriz4::Transposta () const {
  Matriz4 t;
  for(size_t i=0; i < 4; i++)
    for(size_t j=0; j < 4; j++)
      t.m[j][i] = m[i][j];
  return t;
}

//Transformacoes de translacao
void Matriz4::setTrans( const Vetor3& v ) {
  m[0][3] = v[0];   m[1][3] = v[1];  m[2][3] = v[2];
}

Vetor3 Matriz4::getTrans() const {
  return Vetor3(m[0][3], m[1][3], m[2][3]);
}

void Matriz4::makeTrans( const Vetor3& v ) {
  m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = v[0];
  m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = v[1];
  m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = v[2];
  m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
}

void Matriz4::makeTrans( Real tx, Real ty, Real tz ) {
  m[0][0] = 1.0; m[0][1] = 0.0; m[0][2] = 0.0; m[0][3] = tx;
  m[1][0] = 0.0; m[1][1] = 1.0; m[1][2] = 0.0; m[1][3] = ty;
  m[2][0] = 0.0; m[2][1] = 0.0; m[2][2] = 1.0; m[2][3] = tz;
  m[3][0] = 0.0; m[3][1] = 0.0; m[3][2] = 0.0; m[3][3] = 1.0;
}

Matriz4 Matriz4:: getTrans( const Vetor3& v ) {
  Matriz4 t;
  t[0][0] = 1.0; t[0][1] = 0.0; t[0][2] = 0.0; t[0][3] = v[0];
  t[1][0] = 0.0; t[1][1] = 1.0; t[1][2] = 0.0; t[1][3] = v[1];
  t[2][0] = 0.0; t[2][1] = 0.0; t[2][2] = 1.0; t[2][3] = v[2];
  t[3][0] = 0.0; t[3][1] = 0.0; t[3][2] = 0.0; t[3][3] = 1.0;
  return t;
}

Matriz4 Matriz4:: getTrans( Real tx, Real ty, Real tz ) {
  Matriz4 t;
  t[0][0] = 1.0; t[0][1] = 0.0; t[0][2] = 0.0; t[0][3] = tx;
  t[1][0] = 0.0; t[1][1] = 1.0; t[1][2] = 0.0; t[1][3] = ty;
  t[2][0] = 0.0; t[2][1] = 0.0; t[2][2] = 1.0; t[2][3] = tz;
  t[3][0] = 0.0; t[3][1] = 0.0; t[3][2] = 0.0; t[3][3] = 1.0;
  return t;
}

Real Matriz4::menorComp(size_t linha, size_t coluna) const {
  size_t l0,l1,l2;
  size_t c0,c1,c2;
  switch (linha) {
    case 0:
      l0 = 1; l1 = 2; l2 = 3;
      break;
    case 1:
      l0 = 0; l1 = 2; l2 = 3;
      break;
    case 2:
      l0 = 0; l1 = 1; l2 = 3;
      break;
    case 3:
      l0 = 0; l1 = 1; l2 = 3;
      break;
    default:
     assert(0);
  }

  switch (coluna) {
    case 0:
      c0 = 1; c1 = 2; c2 = 3;
      break;
    case 1:
      c0 = 0; c1 = 2; c2 = 3;
      break;
    case 2:
      c0 = 0; c1 = 1; c2 = 3;
      break;
    case 3:
      c0 = 0; c1 = 1; c2 = 3;
      break;
    default:
     assert(0);
  }
  
  return m[l0][c0] * (m[l1][c1] * m[l2][c2] - m[l2][c1] * m[l1][c2]) -
         m[l0][c1] * (m[l1][c0] * m[l2][c2] - m[l2][c0] * m[l1][c2]) +
         m[l0][c2] * (m[l1][c0] * m[l2][c1] - m[l2][c0] * m[l1][c1]); 

}
  
Real Matriz4::menorComp(const size_t l0, const size_t l1, const size_t l2,
                    const size_t c0, const size_t c1, const size_t c2) const
{
  return m[l0][c0] * (m[l1][c1] * m[l2][c2] - m[l2][c1] * m[l1][c2]) -
         m[l0][c1] * (m[l1][c0] * m[l2][c2] - m[l2][c0] * m[l1][c2]) +
         m[l0][c2] * (m[l1][c0] * m[l2][c1] - m[l2][c0] * m[l1][c1]); 

}

Real Matriz4::Determinante () const {
  return m[0][0] * menorComp(1, 2, 3, 1, 2, 3) -
         m[0][1] * menorComp(1, 2, 3, 0, 2, 3) +
         m[0][2] * menorComp(1, 2, 3, 0, 1, 3) -
         m[0][3] * menorComp(1, 2, 3, 0, 1, 2);

}

bool Matriz4::Inversa (Matriz4& inversa, Real tolerancia) const {
  for(size_t i=0; i < 4; i++)
    for(size_t j=0; j < 4; j++){
      inversa[i][j] = (i+j % 2 == 0) ? menorComp(j,i) : -1*menorComp(j,i);
    }
  Real det = m[0][0]*inversa.m[0][0] -
             m[0][1]*inversa.m[1][0] +
             m[0][2]*inversa.m[2][0] -
             m[0][3]*inversa.m[3][0];
  if ( abs(det) <= tolerancia )
    return false;

  Real invDet = 1.0/det;
  for (size_t i = 0; i < 4; i++)
    for (size_t j = 0; j < 4; j++)
      inversa[i][j] *= invDet;

  return true;

}

Matriz4 Matriz4::Inversa(Real tolerancia) const {
  Matriz4 inversa;
  if(!Inversa(inversa,tolerancia) )
    inversa = Matriz4::ZERO;
  return inversa;
}


