/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "cena.hpp"

void Cena::LookAt(const Vetor3& eye, const Vetor3& at, const Vetor3& up) {
  cameraMudou = true;
  visualizador.LookAt(eye,at,up);
}

void Cena::addObjeto(Objeto* obj){
  listObj.push_back(obj);
  listObjCam.push_back(obj->mudancaBaseCP(mMC) );
}

void Cena::mudarMundoCamera() {
  if(cameraMudou) {
    cameraMudou = false;
    listObjCam.clear();
    mMC = visualizador.matrizMundoCamera();
    for(size_t i=0; i < listObj.size(); i++ ){
      listObjCam.push_back( listObj[i]->mudancaBaseCP(mMC)  );
    }
    luzCam = iluminacao.mudancaBaseCP(mMC);
    
  }

}

Vetor3 Cena::direcaoReflexao(const Vetor3& visual, const Vetor3& normal) {
  return (2*visual.escalar(normal)*normal) - visual;
}

Vetor3 Cena::direcaoRefracao(const Vetor3& visual, const Vetor3& normal, Real n1, Real n2) {
  Real b = n1 / n2;
  Real e = visual.escalar(normal);
  Real r = 1 - b*b*(1 - e*e);
  Real a =  sqrt(r) - b*e;
  Vetor3 t = -a*normal - b*visual;
  return t;
}

void Cena::RayTracing(Real planoLargura, Real planoAltura, Real planoDistancia,
                       uint telaLargura, uint telaAltura)
{
  mudarMundoCamera();
  Vetor3 cor = Vetor3::ZERO;
  Real dx, dy, x, y,z;
  dx = planoLargura/telaLargura;
  dy = planoAltura/telaAltura;
  
  Vetor3 c;
  float vcor[3];
  c[0] = -planoLargura*0.5;
  c[1] = -planoAltura*0.5;
  c[2] = -planoDistancia;
  z = (c[2] > 0.0) ? -c[2] : c[2];
  
  for(size_t i=0; i < telaAltura; i++){
    for(size_t j=0; j < telaLargura; j++){
      x = (j + 0.5)*dx + c[0];
      y = (i + 0.5)*dy + c[1];
      Raio ray(Vetor3::ZERO, Vetor3(x,y,z) );
      cor = rt_trace(ray,1);
      vcor[0] = (cor[0] > 1.0) ? 1.0 : cor[0];
      vcor[1] = (cor[1] > 1.0) ? 1.0 : cor[1];
      vcor[2] = (cor[2] > 1.0) ? 1.0 : cor[2];
      
      glRasterPos2i(j,i);  
      glDrawPixels(1,1,GL_RGB, GL_FLOAT, vcor);
      //cout << vcor[0] << " ; " << vcor[1] << " ; " << vcor[2] << endl;
    }
    
  }
  

}

Vetor3 Cena::rt_trace(const Raio& ray, uint nivel) {
  uint nivelMAX = 6;
  Objeto* pObj;
  Real t, tmenor;
  Vetor3 n;
  Vetor3 normal;
  Vetor3 cor;
  int sn, sentidoNormal, ii;

  tmenor = -1.0;
  for(int i=0; i < listObjCam.size(); i++){
    if(  listObjCam[i]->intersecao(ray, t,n, sn) ){
      if( t < tmenor || tmenor == -1.0){
        tmenor = t;
        pObj = listObjCam[i];
        normal = n;
        sentidoNormal = sn;
        ii = i;
      }
    }
  }
  
   //nao teve intersecao
   if(tmenor == -1.0){
    if(nivel == 1)
      return corAmb;
    else
      return Vetor3::ZERO;
   }
   
   Vetor3 pntIntersecao = ray.getPonto(tmenor);
   
   Vetor3 l = (luzCam.getLocalizacao() - pntIntersecao ).normalizarCP();
   Vetor3 r = (2*( l.escalar(normal) )*normal - l ).normalizarCP();
   Vetor3 v = -ray.getDirecao();
   
   
   Vetor3 ambiente      = pObj->getAmbiente();
   Vetor3 difusa        = pObj->getDifusa();
   Vetor3 especular     = pObj->getEspecular();
   Vetor3 transmissiva  = pObj->getTransmissiva();
   Real shininess       = pObj->getShininess();
   Real indiceRefracao  = pObj->getIndiceRefracao();
    
   Vetor3 corAmb =  ambiente*luzCam.getAmbiente() ;
   Vetor3 corDif =  difusa*max(l.escalar(normal), (Real) 0.0)*luzCam.getDifusa() ;
   Vetor3 corEsp =  especular*luzCam.getEspecular() *
                      max( (float) 0.0, pow(r.escalar(v), shininess )); 
   
   /*
   for(int i=0; i < listObjCam.size(); i++){
    if(i != ii){
      if(  listObjCam[i]->intersecao(Raio(pntIntersecao,l), t,n, sn) ){
        cor = corAmb;
        return cor;
      }
    }
    
   }*/
   
   
   cor = corAmb;
   if(!isnan(corDif[0]) && !isnan(corDif[1]) && !isnan(corDif[2]) )
    cor += corDif;

   if(!isnan(corEsp[0]) && !isnan(corEsp[1]) && !isnan(corEsp[2]) )
    cor += corEsp;
   
   if(nivel >= nivelMAX){
    return cor;
   }
   
   Vetor3 dirRe = direcaoReflexao(v,normal);
   Vetor3 corRe = rt_trace(Raio(pntIntersecao, dirRe) ,nivel+1);
   
   Vetor3 dirRa;
   if(sentidoNormal == 0){
    dirRa = direcaoRefracao(v,normal,nAmb,indiceRefracao );
   } else {
    dirRa = direcaoRefracao(v,normal,indiceRefracao,nAmb );
   }
   Vetor3 corRa = rt_trace(Raio(pntIntersecao, dirRa) ,nivel+1);

   cor += corRa*transmissiva +
          corRe*especular;
   
   return cor;
}

