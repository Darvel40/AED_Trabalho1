#include "../localidade/localidade.h"
#ifndef H_ESTACAO
#define H_ESTACAO

//Struct Localidade
typedef struct _estacao{
  int codigo;
  char* nome;
  struct localidade;
} estacaoInfo, *estacao;

//Inicializar Objeto
estacao create(estacao e);

//Destroir Objeto
void destroy(estacao e);

#endif