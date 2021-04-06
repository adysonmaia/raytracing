/*
  Ray Tracing
  Adyson Magalhaes Maia, 277954
  UFC
*/

#include "objeto.hpp"

Luz Luz::mudancaBaseCP(const Matriz4& matriz) {
  return Luz(matriz*posicao,Ia,Id,Is);
}
