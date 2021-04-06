/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __CENA_HPP__
#define __CENA_HPP__

#include "prerequisitos.hpp"
#include "esfera.hpp"
#include "malha.hpp"
#include "cone.hpp"
#include "camera.hpp"

class Cena {
public:
  Cena(const Luz& luz, const Camera& camera , const vector<Objeto*>& objetos,
       const Vetor3& corAmbiente = Vetor3::ZERO, Real indiceRefracaoAmb = 1.0) 
       :
        iluminacao(luz), visualizador(camera), listObj(objetos), corAmb(corAmbiente),
        nAmb(indiceRefracaoAmb), cameraMudou(true) 
  {
    //mMC = visualizador.matrizMundoCamera();
  }
  
  Cena(const Luz& luz, const Camera& camera, const Vetor3& corAmbiente = Vetor3::ZERO, Real indiceRefracaoAmb = 1.0) :
       iluminacao(luz), visualizador(camera), corAmb(corAmbiente), nAmb(indiceRefracaoAmb), cameraMudou(true)
  {
    //mMC = visualizador.matrizMundoCamera();
  }
        
  //Muda a camera
  void LookAt(const Vetor3& eye, const Vetor3& at, const Vetor3& up);
  //adiciona objeto a cena
  void addObjeto(Objeto* obj);
  
  inline Luz& getLuz() {return iluminacao;}
  inline void setLuz(const Luz& l) {iluminacao = l;}
  inline Vetor3& getCorAmbiente() {return corAmb;}
  inline void setCorAmbiente(const Vetor3& cor) {corAmb = cor;} 
  
  void RayTracing(Real planoLargura, Real planoAltura, Real planoDistancia,
                  uint telaLargura, uint telaAltura);
  
private:
  vector<Objeto*> listObj;
  vector<Objeto*> listObjCam; //posicao dos objetos em relacao a camera
  Luz iluminacao;
  Luz luzCam; //luz com posicao em relacao a camera;
  Camera visualizador;
  Vetor3 corAmb;
  Real nAmb; // indice de refracao do ambiente;

  bool cameraMudou;
  void mudarMundoCamera();
  Matriz4 mMC; //matriz mudanca de base mundo->camera
  
  Vetor3 direcaoReflexao(const Vetor3& visualizacao, const Vetor3& normal);
  Vetor3 direcaoRefracao(const Vetor3& visualizacao, const Vetor3& normal, Real n1, Real n2);

  Vetor3 rt_trace(const Raio& ray, uint nivel);
};

#endif
