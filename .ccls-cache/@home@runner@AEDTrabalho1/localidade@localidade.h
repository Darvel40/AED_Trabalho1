#ifndef H_LOCALIDADE
#define H_LOCALIDADE

//Struct Localidade
typedef struct _localidade{
  char* nome;
} localidadeInfo, *localidade;

//Inicializar Objeto
localidade create(localidade l);

//Destroir Objeto
void destroy(localidade l);

#endif