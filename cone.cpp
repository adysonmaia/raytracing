/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "cone.hpp"

Cone::Cone(const Vetor3& c1, const Vetor3& c2, Real vraio, const Material& mat): Objeto(mat) {
  origem = c1;
  apice = c2;
  direcao = c2 - c1;
  altura = direcao.normalizar();
  raio = vraio;
  
  Vetor3 x = Vetor3::UNIT_X;
  j = direcao;
  k = x.vetorial(j);
  //normalizar() retorna a dimensao do vetor anteriormente
  if( abs(k.normalizar() ) < 1e-06 ){
    x = Vetor3::UNIT_Y;
    k = x.vetorial(j).normalizarCP();
  }
  i = j.vetorial(k);

}

Cone::Cone(const Cone& cpy) {
  origem  = cpy.origem;
  apice   = cpy.apice;
  direcao = cpy.direcao;
  altura  = cpy.altura;
  raio    = cpy.raio;
  material = cpy.material;
  i = cpy.i;
  j = cpy.j;
  k = cpy.k;
}


void Cone::mudancaBase(const Matriz4& matriz) {
  origem  = matriz*origem;
  apice   = matriz*apice;
  
  direcao = apice - origem;
  direcao.normalizar();
  
  Vetor3 x = Vetor3::UNIT_X;
  j = direcao;
  k = x.vetorial(j);
  //normalizar() retorna a dimensao do vetor anteriormente
  if( abs(k.normalizar() ) < 1e-06 ){
    x = Vetor3::UNIT_Y;
    k = x.vetorial(j).normalizarCP();
  }
  i = j.vetorial(k);

}

Objeto* Cone::mudancaBaseCP(const Matriz4& matriz) {
  Cone *cone;
  cone = new Cone(*this);
  cone->mudancaBase(matriz);
  return cone;
}

// /*
bool Cone::intersecao(const Raio& ray, Real& t, Vetor3& normal, int& sentidoNormal) {  
  Vetor3 o = origem;
  Real h,hh,r,rr;
  Real r2h2,_2r2h;
  h      = altura;
  hh     = h*h;
  r      = raio;
  rr     = r*r;
  r2h2   = rr/hh;
  _2r2h  = 2*rr/h;

  Real a = i.escalar(ray.getOrigem() - o);
  Real b = i.escalar(ray.getDirecao());
  Real c = k.escalar(ray.getOrigem() - o);
  Real d = k.escalar(ray.getDirecao());
  Real e = j.escalar(ray.getOrigem() - o);
  Real f = j.escalar(ray.getDirecao());


  Real A = -(f*f*r2h2) +(d*d) +(b*b);
  Real B = -(2*e*f*r2h2)  +(2*c*d) +(2*a*b)+ (f*_2r2h);
  Real C = -(e*e*r2h2)-(rr)+(c*c)+(a*a)+(e*_2r2h);
  Real delta = (B*B) - (4*A*C);

  if(delta < 0) 
    return false;

  Real raiz = sqrt(delta);

  t = (-B -raiz)/(2*A);
  if (t <= 0.0001 ) {
    t = (-B +raiz)/(2*A);
    if( t <= 0.0001 ) 
      return false;
  }
  if((e +(f*t)  < 0.001 || e +(f*t) > h - 0.001) )
    return false;


  Vetor3 ponto = ray*t;
  
  Real yH = ponto.escalar(direcao);
        
  Vetor3 radical_vector = (direcao*yH - ponto).normalizarCP();
                        
  Vetor3 out_vector = radical_vector.vetorial(direcao);
  Vetor3 generatrix = (apice - radical_vector*raio);

  normal = generatrix.vetorial(out_vector).normalizarCP();

  
  
//   normal[0] = 2*(i.escalar(ponto -o));
//   normal[1] = 2*(k.escalar(ponto -o));
//   normal[2] = -2*(rr/hh)*(j.escalar(ponto -o)) + (2*rr/h);
//   normal.normalizar();
  
  if(normal.escalar(ray.getDirecao()) >= 0.0){
    normal *= -1;
    sentidoNormal = 1;
  }else{
    sentidoNormal = 0;
  }
  
  return true;


}
// */

  
  
  

