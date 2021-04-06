/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "camera.hpp"

const Camera Camera::CAM_ORIGEM;

Camera::Camera(const Vetor3& eye, const Vetor3& at, const Vetor3& up) {
  local = eye;
  k = (eye - at).normalizarCP();
  i = k.vetorial(up - eye).normalizarCP();
  j = i.vetorial(k);

}

void Camera::setOrientacao(const Vetor3& at, const Vetor3& up) {
  k = (local - at).normalizar();
  i = (up - local).vetorial(k).normalizar();
  j = k.vetorial(i);
}

void Camera::LookAt(const Vetor3& eye, const Vetor3& at, const Vetor3& up) {
  local = eye;
  k = (eye - at).normalizar();
  i = (up - eye).vetorial(k).normalizar();
  j = k.vetorial(i);
}

Matriz4 Camera::matrizMundoCamera() const {
  Matriz4 r = Matriz4::IDENTIDADE;
  Matriz4 t;
  t = Matriz4::getTrans(-local);
  
  r[0][0] = i[0]; r[0][1] = i[1]; r[0][2] = i[2];
  r[1][0] = j[0]; r[1][1] = j[1]; r[1][2] = j[2];
  r[2][0] = k[0]; r[2][1] = k[1]; r[2][2] = k[2];
  
  return r*t;
}

Matriz4 Camera::matrizCameraMundo() const {
  Matriz4 r = Matriz4::IDENTIDADE;
  Matriz4 t;
  t = Matriz4::getTrans(local);
  
  r[0][0] = i[0]; r[0][1] = j[0]; r[0][2] = k[0];
  r[1][0] = i[1]; r[1][1] = j[1]; r[1][2] = k[1];
  r[2][0] = i[2]; r[2][1] = j[2]; r[2][2] = k[2];
  
  return t*r;
}
