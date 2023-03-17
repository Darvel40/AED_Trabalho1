#include "../localidade/localidade.h"
#ifndef H_LISTA
#define H_LISTA

//Struct Localidade
typedef struct _estacao{
  int cod;
  char* nome;
  struct localidade;
  int stockDeBrindes;
} estacaoInfo, *estacao;

//Inicializar Objeto
estacao create(estacao e);

//Destroir Objeto
void destroy(estacao e);

#endif