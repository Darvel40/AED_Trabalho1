#ifndef H_CARTAOPASSAGEIRO
#define H_CARTAOPASSAGEIRO

//Struct Localidade
typedef struct _cartaopassageiro{
  int pontos;
  int codigoViagemRecente;
} cartaopassageiro;

//Inicializar Objeto
cartaopassageiro create(cartaopassageiro e);

//Destroir Objeto
void destroy(cartaopassageiro e);

#endif