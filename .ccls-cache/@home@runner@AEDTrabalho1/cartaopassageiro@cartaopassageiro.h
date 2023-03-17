#include "../passageiro/passageiro.h"
#include "../estacao/estacao.h"
#ifndef H_CARTAOPASSAGEIRO
#define H_CARTAOPASSAGEIRO

//Struct Localidade
typedef struct _cartaopassageiro{
  struct passageiro;
  struct estacao;
  int pontos;
  int brindes;
} cartaopassageiroInfo, *cartaopassageiro;

//Inicializar Objeto
cartaopassageiro create(cartaopassageiro e);

//Destroir Objeto
void destroy(cartaopassageiro e);

#endif