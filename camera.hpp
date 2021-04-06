/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#ifndef __CAMERA_HPP__
#define __CAMERA_HPP__

#include "matriz4.hpp"

class Camera {
public:
  Camera() : local(Vetor3::ZERO), i(Vetor3::UNIT_X), j(Vetor3::UNIT_Y), k(Vetor3::NEGATIVO_UNIT_Z) {};
  Camera(const Vetor3& eye, const Vetor3& at, const Vetor3& up);
  
  inline Vetor3 getLocalizacao() const {return local;}
  inline void setLocalizacao(const Vetor3& eye) {local=eye;}
  
  void setOrientacao(const Vetor3& at, const Vetor3& up);
  void LookAt(const Vetor3& eye, const Vetor3& at, const Vetor3& up);
  
  inline Vetor3 getOrientX() const {return i;}
  inline Vetor3 getOrientY() const {return j;}
  inline Vetor3 getOrientZ() const {return k;}
  
  Matriz4 matrizMundoCamera() const;
  Matriz4 matrizCameraMundo() const;
private:
  Vetor3 i,j,k;
  Vetor3 local;

  static const Camera CAM_ORIGEM;

};

#endif
