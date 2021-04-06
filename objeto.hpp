/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __OBJETO_HPP__
#define __OBJETO_HPP__

#include "matriz4.hpp"
#include "raio.hpp"

class Material {
public:
  Material() {}
  Material(const Vetor3& ambiente, const Vetor3& difusa, const Vetor3& especular, const Vetor3& transmissiva, 
           Real shininess, Real iRefracao = 1.0) :
           ka(ambiente), kd(difusa), ks(especular), kt(transmissiva), a(shininess), n(iRefracao) {}
  
  inline Vetor3 getAmbiente() const {return ka;}
  inline void setAmbiente(const Vetor3& valor) {ka = valor;}
  inline Vetor3 getDifusa() const {return kd;}
  inline void setDifusa(const Vetor3& valor) {kd = valor;}
  inline Vetor3 getEspecular() const {return ks;}
  inline void setEspecular(const Vetor3& valor) {ks = valor;}
  inline Vetor3 getTransmissiva() const {return kt;}
  inline void setTransmissiva(const Vetor3& valor) {kt = valor;}
  inline Real getShininess() const {return a;}
  inline void setShininess(Real s) {a = s;}
  inline Real getIndiceRefracao() const {return n;}
  inline void setIndiceRefracao(Real ir) {n=ir;}
  
private:
  Vetor3 ka; //Ambiente
  Vetor3 kd; //Difusa
  Vetor3 ks; //Especular
  Vetor3 kt; //Transmissiva
  Real a;    //shininess
  Real n;    // Indice de refracao
  
  //Vetor3 vEmissiva;
};

class Objeto {
public:
  Objeto() {};
  Objeto(const Material& m) : material(m) {}
  
  //sentidoNormal = 0 (saindo do obejto) 1(entrando no obejto)
  virtual bool intersecao(const Raio& raio, Real& t, Vetor3& normal, int& sentidoNormal) =0;
  //altera a base do objeto
  virtual void mudancaBase(const Matriz4& matriz) =0;
  //copia do objeto com a mudanca de base
  virtual Objeto* mudancaBaseCP(const Matriz4& matriz) = 0;
  
  inline Material getMaterial() const {return material;}
  inline void setMaterial(const Material& mat) {material = mat;}
  
  inline Vetor3 getAmbiente() const {return material.getAmbiente();}
  inline Vetor3 getDifusa() const {return material.getAmbiente();}
  inline Vetor3 getEspecular() const {return material.getEspecular();}
  inline Vetor3 getTransmissiva() const {return material.getTransmissiva();}
  inline Real getShininess() const {return material.getShininess();}
  inline Real getIndiceRefracao() const {return material.getIndiceRefracao();}


protected:
  Material material;
};

//Luz pontual
class Luz {
public:
  Luz(): posicao(Vetor3::ZERO), Ia(Vetor3::ZERO), Id(Vetor3::ZERO), Is(Vetor3::ZERO)  {}
  Luz(const Vetor3& local, const Vetor3& ambiente, const Vetor3& difusa, const Vetor3& especular) :
      posicao(local), Ia(ambiente), Id(difusa), Is(especular) {}
  
  inline Vetor3 getAmbiente() const {return Ia;}
  inline void setAmbiente(const Vetor3& v) {Ia = v;}
  inline Vetor3 getDifusa() const {return Id;}
  inline void setDifusa(const Vetor3& v) {Id = v;}
  inline Vetor3 getEspecular() const {return Is;}
  inline void setEspecular(const Vetor3& v) {Is = v;}
  inline Vetor3 getLocalizacao() const {return posicao;}
  inline void setLocalizacao(const Vetor3& local) {posicao = local;}
  
  Luz mudancaBaseCP(const Matriz4& matriz);
  
protected:
  Vetor3 Ia;
  Vetor3 Id;
  Vetor3 Is;
  Vetor3 posicao;
};

#endif
