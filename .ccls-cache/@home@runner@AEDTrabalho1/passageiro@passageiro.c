#include "passageiro.h"
#include <stdlib.h>
#include <stdio.h>

//Inicializar Objeto
passageiro create(passageiro p) {
  p = (passageiro)malloc(sizeof(passageiroInfo));
  p->nome = "";
  p->email = "";
  return p;
}

//Destroir Objeto
void destroy(passageiro p) { free(p); }